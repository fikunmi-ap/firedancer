#include "fd_snapshot_create.h"
#include "../runtime/fd_acc_mgr.h"
#include "../runtime/fd_hashes.h"
#include "../runtime/context/fd_exec_epoch_ctx.h"

#include <asm-generic/errno.h>
#include <assert.h>
#include <fcntl.h>
#include <zstd.h>

static uchar padding      [ FD_SNAPSHOT_ACC_ALIGN ] = {0};

int
fd_snapshot_create_populate_acc_vecs( fd_snapshot_ctx_t                 * snapshot_ctx,
                                      fd_exec_slot_ctx_t                * slot_ctx,
                                      fd_solana_manifest_serializable_t * manifest,
                                      fd_tar_writer_t                   * writer ) {

  /* The append vecs need to be described in an index in the manifest so a
     reader knows what account files to look for. These files are technically
     slot indexed, but the Firedancer implementation of the Solana snapshot,
     only produces two append vecs. These two storages are for the accounts 
     that were modified and deleted in the most recent slot because that 
     information is used by the Agave client to calculate and verify the 
     bank hash for the given slot. This is done as an optimization to avoid
     having to slot index the Firedancer accounts db which would incur a large
     performance hit.. 
     
     To avoid iterating through the root twice to determine what accounts were
     touched in the snapshot slot and what accounts were touched in the
     other slots, we will create an array of pubkey pointers for all accounts
     that were touched in the pubkey slot. We can safely size this buffer to 
     have a reasonable upper bound for the number of accounts that can be 
     modified during a slot (not including epoch boundaries). This number
     is roughly ~160k because a write lock on an account consumes 300 compute 
     units and there is a block-level limit of 48 million compute units. */

  fd_pubkey_t * * snapshot_slot_keys    = fd_valloc_malloc( slot_ctx->valloc, alignof(fd_pubkey_t*), sizeof(fd_pubkey_t*) * 160000UL );
  ulong           snapshot_slot_key_cnt = 0UL;

  /* Setup the storages for the accounts db index. */

  fd_solana_accounts_db_fields_t * accounts_db = &manifest->accounts_db;

  accounts_db->storages_len                   = 2UL;
  accounts_db->storages                       = fd_valloc_malloc( snapshot_ctx->valloc,
                                                                  FD_SNAPSHOT_SLOT_ACC_VECS_ALIGN,
                                                                  sizeof(fd_snapshot_slot_acc_vecs_t) * accounts_db->storages_len );
  accounts_db->version                        = 1UL;
  accounts_db->slot                           = snapshot_ctx->snapshot_slot;
  accounts_db->historical_roots_len           = 0UL;
  accounts_db->historical_roots               = NULL;
  accounts_db->historical_roots_with_hash_len = 0UL;
  accounts_db->historical_roots_with_hash     = NULL;

  /* Prepopulate storages metadata for the two append vecs. */

  accounts_db->storages[0].account_vecs_len        = 1UL;
  accounts_db->storages[0].account_vecs            = fd_valloc_malloc( snapshot_ctx->valloc,
                                                                       FD_SNAPSHOT_ACC_VEC_ALIGN,
                                                                       sizeof(fd_snapshot_acc_vec_t) * accounts_db->storages[0].account_vecs_len );
  accounts_db->storages[0].account_vecs[0].file_sz = 0UL;
  accounts_db->storages[0].account_vecs[0].id      = 10000UL;
  accounts_db->storages[0].slot                    = snapshot_ctx->snapshot_slot - 1UL;

  accounts_db->storages[1].account_vecs_len        = 1UL;
  accounts_db->storages[1].account_vecs            = fd_valloc_malloc( snapshot_ctx->valloc,
                                                                       FD_SNAPSHOT_ACC_VEC_ALIGN,
                                                                       sizeof(fd_snapshot_acc_vec_t) * accounts_db->storages[1].account_vecs_len );
  accounts_db->storages[1].account_vecs[0].file_sz = 0UL;
  accounts_db->storages[1].account_vecs[0].id      = 10001UL;
  accounts_db->storages[1].slot                    = snapshot_ctx->snapshot_slot; /* All accounts in the snapshot slot */

  /* Populate the snapshot hash into the accounts db. */

  int err = fd_snapshot_hash( slot_ctx, NULL, &accounts_db->bank_hash_info.snapshot_hash, 0 );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Unable to calculate snapshot hash" ));
    return -1;
  }
  fd_memset( &accounts_db->bank_hash_info.stats, 0, sizeof(fd_bank_hash_stats_t) );

  /* Propogate snapshot hash to the snapshot_ctx */

  snapshot_ctx->hash = accounts_db->bank_hash_info.snapshot_hash;

  /* Because the files are serially written out for tar, we must reserve space
     in the archive for the solana manifest. */

  ulong manifest_sz = fd_solana_manifest_serializable_size( manifest ); 

  char buffer[ FD_SNAPSHOT_DIR_MAX ];
  snprintf( buffer, FD_SNAPSHOT_DIR_MAX, "snapshots/%lu/%lu", snapshot_ctx->snapshot_slot, snapshot_ctx->snapshot_slot );
  err = fd_tar_writer_new_file( writer, buffer );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Unable to create snapshot manifest file" ));
    return -1;
  }
  err = fd_tar_writer_make_space( writer, manifest_sz );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Unable to make space for snapshot manifest file" ));
    return -1;
  }
  err = fd_tar_writer_fini_file( writer );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Unable to finalize snapshot manifest file" ));
    return -1;
  }

  /* Iterate through all of the records in the funk root and create/populate an
     append vec for previous slots. Just record the pubkeys for the latest
     slot to populate the append vec after. */

  fd_funk_t *             funk      = slot_ctx->acc_mgr->funk;
  fd_snapshot_acc_vec_t * prev_accs = &accounts_db->storages[0].account_vecs[0];

  snprintf( buffer, 128, "accounts/%lu.%lu", snapshot_ctx->snapshot_slot - 1UL, prev_accs->id );
  fd_tar_writer_new_file( writer, buffer );

  for( fd_funk_rec_t const * rec = fd_funk_txn_first_rec( funk, NULL ); NULL != rec; rec = fd_funk_txn_next_rec( funk, rec ) ) {

    /* Get the account data */

    if( !fd_funk_key_is_acc( rec->pair.key ) ) {
      continue;
    }

    fd_pubkey_t       const * pubkey   = fd_type_pun_const( rec->pair.key[0].uc );
    uchar             const * raw      = fd_funk_val( rec, fd_funk_wksp( funk ) );
    fd_account_meta_t const * metadata = fd_type_pun_const( raw );

    if( !metadata ) {
      continue;
    }

    if( metadata->magic!=FD_ACCOUNT_META_MAGIC ) {
      continue;
    }

    uchar const * acc_data = raw + metadata->hlen;

    /* All accounts that were touched in the snapshot slot should be in 
       a different append vec so that Agave can calculate the snapshot slot's
       bank hash. */

    if( metadata->slot==snapshot_ctx->snapshot_slot ) {
      snapshot_slot_keys[ snapshot_slot_key_cnt++ ] = (fd_pubkey_t *)pubkey;
      continue;
    }

    prev_accs->file_sz += sizeof(fd_solana_account_hdr_t) + fd_ulong_align_up( metadata->dlen, FD_SNAPSHOT_ACC_ALIGN );


    /* Write out the header. */
    fd_solana_account_hdr_t header = {0};
    /* Stored meta */
    header.meta.write_version_obsolete = 0UL;
    header.meta.data_len               = metadata->dlen;
    fd_memcpy( header.meta.pubkey, pubkey, sizeof(fd_pubkey_t) );
    /* Account Meta */
    header.info.lamports               = metadata->info.lamports;
    header.info.rent_epoch             = header.info.lamports ? metadata->info.rent_epoch : 0UL;
    fd_memcpy( header.info.owner, metadata->info.owner, sizeof(fd_pubkey_t) );
    header.info.executable             = metadata->info.executable;
    /* Hash */
    fd_memcpy( &header.hash, metadata->hash, sizeof(fd_hash_t) );


    if( FD_UNLIKELY( fd_tar_writer_stream_file_data( writer, &header, sizeof(fd_solana_account_hdr_t) ) ) ) {
      FD_LOG_ERR(("Unable to stream out account header to tar archive"));
    }
    if( FD_UNLIKELY( fd_tar_writer_stream_file_data( writer, acc_data, metadata->dlen ) ) ) {
      FD_LOG_ERR(("Unable to stream out account data to tar archive"));
    }
    ulong align_sz = fd_ulong_align_up( metadata->dlen, FD_SNAPSHOT_ACC_ALIGN ) - metadata->dlen;
    if( FD_UNLIKELY( fd_tar_writer_stream_file_data( writer, padding, align_sz ) ) ) {
      FD_LOG_ERR(("Unable to stream out account padding to tar archive"));
    }
  }

  fd_tar_writer_fini_file( writer );

  /* Snapshot slot */
  fd_snapshot_acc_vec_t * curr_accs = &accounts_db->storages[1].account_vecs[0];
  snprintf( buffer, 128, "accounts/%lu.%lu", snapshot_ctx->snapshot_slot, curr_accs->id );
  fd_tar_writer_new_file( writer, buffer );

  curr_accs->id = 10001UL;

  for( ulong i=0UL; i<snapshot_slot_key_cnt; i++ ) {
    
    fd_pubkey_t const * pubkey = snapshot_slot_keys[i];

    fd_funk_rec_t const * rec = fd_funk_rec_query( funk, NULL, (fd_funk_rec_key_t*)pubkey );
    if( FD_UNLIKELY( !rec ) ) {
      FD_LOG_ERR(( "Previously found record can no longer be found" ));
    }
    uchar             const * raw      = fd_funk_val( rec, fd_funk_wksp( funk ) );
    fd_account_meta_t const * metadata = fd_type_pun_const( raw );

    if( FD_UNLIKELY( !metadata ) ) {
      FD_LOG_ERR(("Record should have non-NULL metadata"));
    }

    if( FD_UNLIKELY( metadata->magic!=FD_ACCOUNT_META_MAGIC ) ) {
      FD_LOG_ERR(("Record should have valid magic"));
    }

    uchar const * acc_data = raw + metadata->hlen;

    curr_accs->file_sz += sizeof(fd_solana_account_hdr_t) + fd_ulong_align_up( metadata->dlen, FD_SNAPSHOT_ACC_ALIGN );

    /* Write out the header. */
    fd_solana_account_hdr_t header = {0};
    /* Stored meta */
    header.meta.write_version_obsolete = 0UL;
    header.meta.data_len               = metadata->dlen;
    fd_memcpy( header.meta.pubkey, pubkey, sizeof(fd_pubkey_t) );
    /* Account Meta */
    header.info.lamports               = metadata->info.lamports;
    header.info.rent_epoch             = header.info.lamports ? metadata->info.rent_epoch : 0UL;
    fd_memcpy( header.info.owner, metadata->info.owner, sizeof(fd_pubkey_t) );
    header.info.executable             = metadata->info.executable;
    /* Hash */
    fd_memcpy( &header.hash, metadata->hash, sizeof(fd_hash_t) );


    err = fd_tar_writer_stream_file_data( writer, &header, sizeof(fd_solana_account_hdr_t) );
    if( FD_UNLIKELY( err ) ) {
      FD_LOG_WARNING(( "Unable to stream out account header to tar archive" ));
      return -1;
    }
    err = fd_tar_writer_stream_file_data( writer, acc_data, metadata->dlen );
    if( FD_UNLIKELY( err ) ) {
      FD_LOG_WARNING(( "Unable to stream out account data to tar archive" ));
      return -1;
    }
    ulong align_sz = fd_ulong_align_up( metadata->dlen, FD_SNAPSHOT_ACC_ALIGN ) - metadata->dlen;
    err = fd_tar_writer_stream_file_data( writer, padding, align_sz );
    if( FD_UNLIKELY( err ) ) {
      FD_LOG_WARNING(( "Unable to stream out account padding to tar archive" ));
      return -1;
    }
  }

  err = fd_tar_writer_fini_file( writer );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Unable to finish writing out file" ));
  }

  return 0;
}

int
fd_snapshot_create_serialiable_stakes( fd_exec_slot_ctx_t       * slot_ctx,
                                       fd_stakes_t              * old_stakes,
                                       fd_stakes_serializable_t * new_stakes ) {

/* The deserialized stakes cache that is used by the runtime can't be
     reserialized into the format that Agave uses. For every vote accounts
     in the stakes struct, the Firedancer client holds a decoded copy of the 
     vote state. However, this vote state can't be reserialized back into the 
     full vote account data. 
     
     This poses a problem in the Agave client client because upon boot, Agave
     verifies that for all of the vote accounts in the stakes struct, the data
     in the cache is the same as the data in the accounts db.
     
     The other problem is that the Firedancer stakes cache does not evict old
     entries and doesn't update delegations within the cache. The cache will
     just insert new pubkeys as stake accounts are created/delegated to. To
     make the cache conformant for the snapshot, old accounts should be removed
     from the snapshot and all of the delegations should be updated. */

  /* First populate the vote accounts using the vote accounts/stakes cache. 
     We can populate over all of the fields except we can't reserialize the
     vote account data. Instead we will copy over the raw contents of all of
     the vote accounts. */

  ulong vote_accounts_len                      = fd_vote_accounts_pair_t_map_size( old_stakes->vote_accounts.vote_accounts_pool, old_stakes->vote_accounts.vote_accounts_root );
  new_stakes->vote_accounts.vote_accounts_pool = fd_vote_accounts_pair_serializable_t_map_alloc( fd_scratch_virtual(), fd_ulong_max(vote_accounts_len, 15000 ) );
  new_stakes->vote_accounts.vote_accounts_root = NULL;

  for( fd_vote_accounts_pair_t_mapnode_t * n = fd_vote_accounts_pair_t_map_minimum(
       old_stakes->vote_accounts.vote_accounts_pool,
       old_stakes->vote_accounts.vote_accounts_root );
       n;
       n = fd_vote_accounts_pair_t_map_successor( old_stakes->vote_accounts.vote_accounts_pool, n ) ) {
    
    fd_vote_accounts_pair_serializable_t_mapnode_t * new_node = fd_vote_accounts_pair_serializable_t_map_acquire( new_stakes->vote_accounts.vote_accounts_pool );
    new_node->elem.key   = n->elem.key;
    fd_memcpy( &new_node->elem.key, &n->elem.key, sizeof(fd_pubkey_t) );
    new_node->elem.stake = n->elem.stake;
    /* Now to populate the value, lookup the account using the acc mgr */
    FD_BORROWED_ACCOUNT_DECL( vote_acc );
    int err = fd_acc_mgr_view( slot_ctx->acc_mgr, slot_ctx->funk_txn, &n->elem.key, vote_acc );
    if( FD_UNLIKELY( err ) ) {
      FD_LOG_WARNING(( "Failed to view vote account from stakes cache %s", FD_BASE58_ENC_32_ALLOCA(&n->elem.key) ));
      return -1;
    }

    new_node->elem.value.lamports   = vote_acc->const_meta->info.lamports;
    new_node->elem.value.data_len   = vote_acc->const_meta->dlen;
    new_node->elem.value.data       = fd_scratch_alloc( 8UL, vote_acc->const_meta->dlen );
    fd_memcpy( new_node->elem.value.data, vote_acc->const_data, vote_acc->const_meta->dlen );
    fd_memcpy( &new_node->elem.value.owner, &vote_acc->const_meta->info.owner, sizeof(fd_pubkey_t) );
    new_node->elem.value.executable = vote_acc->const_meta->info.executable;
    new_node->elem.value.rent_epoch = vote_acc->const_meta->info.rent_epoch;
    fd_vote_accounts_pair_serializable_t_map_insert( new_stakes->vote_accounts.vote_accounts_pool, &new_stakes->vote_accounts.vote_accounts_root, new_node );

  }

  /* Stale stake delegations should also be removed or updated in the cache. */

  FD_BORROWED_ACCOUNT_DECL( stake_acc );
  fd_delegation_pair_t_mapnode_t * nn = NULL;
  for( fd_delegation_pair_t_mapnode_t * n = fd_delegation_pair_t_map_minimum(
      old_stakes->stake_delegations_pool,
      old_stakes->stake_delegations_root );
      n; n=nn ) {

    nn = fd_delegation_pair_t_map_successor( old_stakes->stake_delegations_pool, n );
    
    int err = fd_acc_mgr_view( slot_ctx->acc_mgr, slot_ctx->funk_txn, &n->elem.account, stake_acc );
    if( FD_UNLIKELY( err ) ) {
      /* If the stake account doesn't exist, the cache is stale and the entry
         just needs to be evicted. */
      fd_delegation_pair_t_map_remove( old_stakes->stake_delegations_pool, &old_stakes->stake_delegations_root, n );
      fd_delegation_pair_t_map_release( old_stakes->stake_delegations_pool, n );
    } else {
      /* Otherwise, just update the delegation in case it is stale. */
      fd_bincode_decode_ctx_t ctx = {
        .data    = stake_acc->const_data,
        .dataend = stake_acc->const_data + stake_acc->const_meta->dlen,
        .valloc  = fd_scratch_virtual()
      };
      fd_stake_state_v2_t stake_state = {0};
      err = fd_stake_state_v2_decode( &stake_state, &ctx );
      if( FD_UNLIKELY( err ) ) {
        FD_LOG_WARNING(( "Failed to decode stake state" ));
        return -1;
      }
      n->elem.delegation = stake_state.inner.stake.stake.delegation;
    }
  }

  /* Copy over the rest of the fields as they are the same. */

  new_stakes->stake_delegations_pool = old_stakes->stake_delegations_pool;
  new_stakes->stake_delegations_root = old_stakes->stake_delegations_root;
  new_stakes->unused                 = old_stakes->unused;
  new_stakes->epoch                  = old_stakes->epoch;
  new_stakes->stake_history          = old_stakes->stake_history;

  return 0;
}

int
fd_snapshot_create_populate_bank( fd_snapshot_ctx_t *                snapshot_ctx, 
                                  fd_exec_slot_ctx_t *               slot_ctx,
                                  fd_serializable_versioned_bank_t * bank ) {

  fd_epoch_bank_t * epoch_bank = fd_exec_epoch_ctx_epoch_bank( slot_ctx->epoch_ctx );

  /* The blockhash queue has to be copied over along with all of its entries. */

  bank->blockhash_queue.last_hash_index = slot_ctx->slot_bank.block_hash_queue.last_hash_index;
  bank->blockhash_queue.last_hash       = fd_scratch_alloc( FD_HASH_ALIGN, FD_HASH_FOOTPRINT );
  fd_memcpy( bank->blockhash_queue.last_hash, slot_ctx->slot_bank.block_hash_queue.last_hash, sizeof(fd_hash_t) );

  bank->blockhash_queue.ages_len = fd_hash_hash_age_pair_t_map_size( slot_ctx->slot_bank.block_hash_queue.ages_pool, slot_ctx->slot_bank.block_hash_queue.ages_root);
  bank->blockhash_queue.ages     = fd_scratch_alloc( FD_HASH_HASH_AGE_PAIR_ALIGN, bank->blockhash_queue.ages_len * sizeof(fd_hash_hash_age_pair_t) );
  bank->blockhash_queue.max_age  = FD_BLOCKHASH_QUEUE_SIZE;

  fd_block_hash_queue_t             * queue               = &slot_ctx->slot_bank.block_hash_queue;
  fd_hash_hash_age_pair_t_mapnode_t * nn                  = NULL;
  ulong                               blockhash_queue_idx = 0UL;
  for( fd_hash_hash_age_pair_t_mapnode_t * n = fd_hash_hash_age_pair_t_map_minimum( queue->ages_pool, queue->ages_root ); n; n = nn ) {
    nn = fd_hash_hash_age_pair_t_map_successor( queue->ages_pool, n );
    fd_memcpy( &bank->blockhash_queue.ages[ blockhash_queue_idx++ ], &n->elem, sizeof(fd_hash_hash_age_pair_t) );
  }

  /* Ancestor can be omitted to boot off of for both clients */

  bank->ancestors_len                        = 0UL;
  bank->ancestors                            = NULL;

  bank->hash                                  = slot_ctx->slot_bank.banks_hash;
  bank->parent_hash                           = slot_ctx->prev_banks_hash;

  /* The slot needs to be decremented because the snapshot is created after
     a slot finishes executing and the slot value is incremented. 
     TODO: This will not always be correct and should be fixed. */

  bank->parent_slot                           = snapshot_ctx->snapshot_slot - 1UL;

  /* Hard forks can be omitted as it is not needed to boot off of both clients */

  bank->hard_forks.hard_forks                 = NULL;
  bank->hard_forks.hard_forks_len             = 0UL;

  bank->transaction_count                     = slot_ctx->slot_bank.transaction_count;
  bank->tick_height                           = slot_ctx->tick_height;
  bank->signature_count                       = slot_ctx->parent_signature_cnt;
  bank->capitalization                        = slot_ctx->slot_bank.capitalization;
  bank->tick_height                           = slot_ctx->tick_height;
  bank->max_tick_height                       = slot_ctx->tick_height;
  bank->hashes_per_tick                       = &epoch_bank->hashes_per_tick;
  bank->ticks_per_slot                        = FD_TICKS_PER_SLOT;
  bank->ns_per_slot                           = epoch_bank->ns_per_slot;
  bank->genesis_creation_time                 = epoch_bank->genesis_creation_time;
  bank->slots_per_year                        = epoch_bank->slots_per_year;

  /* This value can be set to 0 because the Agave client recomputes this value
     and the firedancer client doesn't use it. */

  bank->accounts_data_len                     = 0UL;

  bank->slot                                  = snapshot_ctx->snapshot_slot;
  bank->epoch                                 = fd_slot_to_epoch( &epoch_bank->epoch_schedule, bank->slot, NULL );
  bank->block_height                          = slot_ctx->slot_bank.block_height;

  /* Collector id can be left as null for both clients */

  fd_memset( &bank->collector_id, 0, sizeof(fd_pubkey_t) );

  bank->collector_fees                        = slot_ctx->slot_bank.collected_execution_fees + slot_ctx->slot_bank.collected_priority_fees;
  bank->fee_calculator.lamports_per_signature = slot_ctx->slot_bank.lamports_per_signature;
  bank->fee_rate_governor                     = slot_ctx->slot_bank.fee_rate_governor;
  bank->collected_rent                        = slot_ctx->slot_bank.collected_rent;

  bank->rent_collector.epoch                  = bank->epoch;
  bank->rent_collector.epoch_schedule         = epoch_bank->rent_epoch_schedule;
  bank->rent_collector.slots_per_year         = epoch_bank->slots_per_year;
  bank->rent_collector.rent                   = epoch_bank->rent;

  bank->epoch_schedule                        = epoch_bank->epoch_schedule;
  bank->inflation                             = epoch_bank->inflation;
  
  /* Unused accounts can be left as NULL for both clients */

  fd_memset( &bank->unused_accounts, 0, sizeof(fd_unused_accounts_t) );

  /* We need to copy over the stakes for two epochs despite the Agave client
     providing the stakes for 6 epochs. These stakes need to be copied over
     because of the fact that the leader schedule computation uses the two
     previous epoch stakes. */

  fd_epoch_epoch_stakes_pair_t * relevant_epoch_stakes = fd_scratch_alloc( FD_EPOCH_EPOCH_STAKES_PAIR_ALIGN, 2UL * sizeof(fd_epoch_epoch_stakes_pair_t) );
  fd_memset( &relevant_epoch_stakes[0], 0UL, sizeof(fd_epoch_epoch_stakes_pair_t) );
  fd_memset( &relevant_epoch_stakes[1], 0UL, sizeof(fd_epoch_epoch_stakes_pair_t) );
  relevant_epoch_stakes[0].key                        = bank->epoch;
  relevant_epoch_stakes[0].value.stakes.vote_accounts = slot_ctx->slot_bank.epoch_stakes;
  relevant_epoch_stakes[1].key                        = bank->epoch+1UL;
  relevant_epoch_stakes[1].value.stakes.vote_accounts = epoch_bank->next_epoch_stakes;

  bank->epoch_stakes_len                      = 2UL;
  bank->epoch_stakes                          = relevant_epoch_stakes;
  bank->is_delta                              = 0;

  /* The firedancer runtime currently maintains a version of the stakes which
     can't be reserialized into a format that is compatible with the Solana
     snapshot format. Therefore, we must recompute the data structure. */

  int err = fd_snapshot_create_serialiable_stakes( slot_ctx, &epoch_bank->stakes, &bank->stakes );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to serialize stakes" ));
    return -1;
  }

  return 0;
}

static inline int
fd_snapshot_create_validate_ctx( fd_snapshot_ctx_t *  snapshot_ctx,
                                 fd_exec_slot_ctx_t * slot_ctx ) {
  
    /* Validate that the snapshot context is setup correctly */
  
    if( FD_UNLIKELY( !snapshot_ctx->snapshot_dir ) ) {
      FD_LOG_WARNING(( "Snapshot directory is not set" ));
      return -1;
    }

    if( FD_UNLIKELY( snapshot_ctx->snapshot_slot > slot_ctx->slot_bank.slot ) ) {
      FD_LOG_WARNING(( "Snapshot slot is greater than the current slot" ));
      return -1;
    }

    /* TODO: Fill out other things to validate here. */
  
    return 0;
}

static inline int
fd_snapshot_create_setup_writer( fd_snapshot_ctx_t * snapshot_ctx ) {
  
  /* Write out the snapshot tar archive to a temporary location that will be 
     written to when the snapshot account hash is recalculated. */
  char directory_buf[ FD_SNAPSHOT_DIR_MAX ];
  snprintf( directory_buf, FD_SNAPSHOT_DIR_MAX, "%s/tmp.tar", snapshot_ctx->snapshot_dir );

  uchar * writer_mem   = fd_valloc_malloc( snapshot_ctx->valloc, fd_tar_writer_align(), fd_tar_writer_footprint() );
  snapshot_ctx->writer = fd_tar_writer_new( writer_mem, directory_buf );
  if( FD_UNLIKELY( !snapshot_ctx->writer ) ) {
    return -1;
  }
  return 0;
}

static inline int
fd_snapshot_create_write_version( fd_snapshot_ctx_t * snapshot_ctx ) {

  /* The first file in the tar archive should be the version. */

  int err = fd_tar_writer_new_file( snapshot_ctx->writer, FD_SNAPSHOT_VERSION_FILE );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to create the version file" ));
    return -1;
  }

  err = fd_tar_writer_stream_file_data( snapshot_ctx->writer, FD_SNAPSHOT_VERSION, FD_SNAPSHOT_VERSION_LEN);
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to create the version file" ));
    return -1;
  }

  err = fd_tar_writer_fini_file( snapshot_ctx->writer );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to create the version file" ));
    return -1;
  }

  return 0; 
}

static inline int
fd_snapshot_create_write_status_cache( fd_snapshot_ctx_t *  snapshot_ctx,
                                       fd_exec_slot_ctx_t * slot_ctx ) {

  FD_SCRATCH_SCOPE_BEGIN {

  /* First convert the existing status cache into a snapshot-friendly format */

  fd_bank_slot_deltas_t slot_deltas_new = {0};
  fd_txncache_get_entries( slot_ctx->status_cache,
                           &slot_deltas_new );
  ulong   bank_slot_deltas_sz = fd_bank_slot_deltas_size( &slot_deltas_new );
  uchar * out_status_cache    = fd_valloc_malloc( snapshot_ctx->valloc, FD_BANK_SLOT_DELTAS_ALIGN, bank_slot_deltas_sz );
  fd_bincode_encode_ctx_t encode_status_cache = {
    .data    = out_status_cache,
    .dataend = out_status_cache + bank_slot_deltas_sz,
  };
  if( FD_UNLIKELY( fd_bank_slot_deltas_encode( &slot_deltas_new, &encode_status_cache ) ) ) {
    FD_LOG_WARNING(( "Failed to encode the status cache" ));
    return -1;
  }

  /* Now write out the buffer to the tar archive */

  int err = fd_tar_writer_new_file( snapshot_ctx->writer, FD_SNAPSHOT_STATUS_CACHE_FILE );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to create the status cache file" ));
    return -1;
  }
  err = fd_tar_writer_stream_file_data( snapshot_ctx->writer, out_status_cache, bank_slot_deltas_sz );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to create the status cache file" ));
    return -1;
  }
  err = fd_tar_writer_fini_file( snapshot_ctx->writer );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to create the status cache file" ));
    return -1;
  }

  return 0;

  } FD_SCRATCH_SCOPE_END;

}

static inline int
fd_snapshot_create_write_manifest_and_acc_vecs( fd_snapshot_ctx_t  * snapshot_ctx,
                                                fd_exec_slot_ctx_t * slot_ctx ) {


  fd_solana_manifest_serializable_t manifest = {0};
  
  /* Copy in all the fields of the bank */

  int err = fd_snapshot_create_populate_bank( snapshot_ctx, slot_ctx, &manifest.bank );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to populate the bank" ));
    return -1;
  }

  /* Populate the rest of the manifest, except for the append vec index. */

  manifest.lamports_per_signature                = slot_ctx->slot_bank.lamports_per_signature;
  manifest.bank_incremental_snapshot_persistence = NULL;
  manifest.epoch_account_hash                    = &slot_ctx->slot_bank.epoch_account_hash;
  /* TODO: The versioned epoch stakes needs to be implemented */
  manifest.versioned_epoch_stakes_len            = 0UL;
  manifest.versioned_epoch_stakes                = NULL;

  /* Create the append vecs and populate the index in the manifest. */

  fd_snapshot_create_populate_acc_vecs( snapshot_ctx, slot_ctx, &manifest, snapshot_ctx->writer );

  /* TODO: Need to write out the snapshot hash to the name of the file as well. */

  /* Encode and output the manifest to a file */
  ulong   manifest_sz  = fd_solana_manifest_serializable_size( &manifest ); 
  uchar * out_manifest = fd_valloc_malloc( snapshot_ctx->valloc, FD_SOLANA_MANIFEST_SERIALIZABLE_ALIGN, manifest_sz );

  fd_bincode_encode_ctx_t encode = { 
    .data    = out_manifest,
    .dataend = out_manifest + manifest_sz
  };

  err = fd_solana_manifest_serializable_encode( &manifest, &encode );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to encode the manifest" ));
    return -1;
  }

  err = fd_tar_writer_fill_space( snapshot_ctx->writer, out_manifest, manifest_sz );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to write out the manifest" ));
    return -1;
  }

  void * mem = fd_tar_writer_delete( snapshot_ctx->writer );
  if( FD_UNLIKELY( !mem ) ) {
    return -1;
  }
  fd_valloc_free( snapshot_ctx->valloc, mem );

  return 0;
}

static int
fd_snapshot_create_compress( fd_snapshot_ctx_t * snapshot_ctx ) {


  char directory_buf_og  [ FD_SNAPSHOT_DIR_MAX ];
  char directory_buf_zstd[ FD_SNAPSHOT_DIR_MAX ];
  snprintf( directory_buf_og,  FD_SNAPSHOT_DIR_MAX, "%s/tmp.tar",
            snapshot_ctx->snapshot_dir);
  snprintf( directory_buf_zstd, FD_SNAPSHOT_DIR_MAX, "%s/snapshot-%lu-%s.tar.zst", 
            snapshot_ctx->snapshot_dir, snapshot_ctx->snapshot_slot, FD_BASE58_ENC_32_ALLOCA(&snapshot_ctx->hash) );

  /* Compress the file using zstd. First open the non-compressed file and
     create a file for the compressed file. */

  ulong in_buf_sz  = ZSTD_CStreamInSize();
  ulong out_buf_sz = ZSTD_CStreamOutSize();

  char * in_buf   = fd_valloc_malloc( snapshot_ctx->valloc, 64UL, in_buf_sz );
  char * zstd_buf = fd_valloc_malloc( snapshot_ctx->valloc, 64UL, out_buf_sz );
  char * out_buf  = fd_valloc_malloc( snapshot_ctx->valloc, 64UL, out_buf_sz );

  /* Reopen the tarball and open/overwrite the filename for the compressed,
     finalized full snapshot. Setup the zstd compression stream. */

  int err = 0;

  ZSTD_CStream * cstream = ZSTD_createCStream();
  if( FD_UNLIKELY( !cstream ) ) {
    FD_LOG_WARNING(( "Failed to create the zstd compression stream" ));
    return -1;
  }
  ZSTD_initCStream(cstream, ZSTD_CLEVEL_DEFAULT ); 

  int fd      = 0;
  int fd_zstd = 0;
  fd_io_buffered_ostream_t ostream[1];

  fd = open( directory_buf_og, O_RDONLY );
  if( FD_UNLIKELY( fd==-1 ) ) {
    FD_LOG_WARNING(( "Failed to open the tar archive (%i-%s)", errno, fd_io_strerror( errno ) ));
    err = -1;
    goto cleanup;
  }

  fd_zstd = open( directory_buf_zstd, O_WRONLY | O_CREAT | O_TRUNC, 0644 );
  if( FD_UNLIKELY( fd_zstd==-1 ) ) {
    FD_LOG_WARNING(( "Failed to open the snapshot file (%i-%s)", errno, fd_io_strerror( errno ) ));
    err = -1;
    goto cleanup;
  }
  err = ftruncate( fd_zstd, 0UL );
  if( FD_UNLIKELY( err=-1 && errno!=0 ) ) {
    FD_LOG_WARNING(( "Failed to truncate the snapshot file (%i-%s)", errno, fd_io_strerror( errno ) ));
     goto cleanup;
  }

  if( FD_UNLIKELY( !fd_io_buffered_ostream_init( ostream, fd_zstd, out_buf, out_buf_sz ) ) ) {
    FD_LOG_WARNING(( "Failed to initialize the ostream" ));
    err = -1;
    goto cleanup;
  }

  /* Read in bytes until we hit an eof */
  ulong in_sz = in_buf_sz;
  while( in_sz==in_buf_sz ) {

    /* Read chunks from the file. There isn't really a need to use a streamed
       reader here because we will read in the max size buffer for every single
       file read except for the very last one. */

    err = fd_io_read( fd, in_buf, 0UL, in_buf_sz, &in_sz );
    if( FD_UNLIKELY( err ) ) {
      FD_LOG_WARNING(( "Failed to read in the file" ));
      goto cleanup;
    }

    /* Compress the in memory buffer and add it to the output stream */
  
    ZSTD_inBuffer input = { in_buf, in_sz, 0 };
    while( input.pos < input.size ) {
      ZSTD_outBuffer output = { zstd_buf, out_buf_sz, 0 };
      ulong ret = ZSTD_compressStream(cstream, &output, &input );
      if( ZSTD_isError( ret )) {
        FD_LOG_WARNING(( "Compression error: %s\n", ZSTD_getErrorName(ret) ));
        err = -1;
        goto cleanup;
      }
      err = fd_io_buffered_ostream_write( ostream, zstd_buf, output.pos );
      if( FD_UNLIKELY( err ) ) {
        FD_LOG_WARNING(( "Failed to write out the compressed file" ));
        goto cleanup;
      }
    }
  }

  ZSTD_outBuffer output    = { zstd_buf, out_buf_sz, 0 };
  ulong          remaining = ZSTD_endStream(cstream, &output);
  if( ZSTD_isError( remaining ) ) {
    FD_LOG_WARNING(("ERROR WITH ENDING"));
    err = -1;
    goto cleanup;
  }   
  if( output.pos>0 ) {
    fd_io_buffered_ostream_write( ostream, zstd_buf, output.pos );
  }

  cleanup:

  ZSTD_freeCStream( cstream ); /* Works even if cstream is null */
  err = fd_io_buffered_ostream_flush( ostream );
  if( FD_UNLIKELY( err ) ) {
    FD_LOG_WARNING(( "Failed to flush the ostream" ));
  }
  err = close( fd );
  if( FD_UNLIKELY( err==-1 ) ) {
    FD_LOG_WARNING(( "Failed to close the tar archive (%i-%s)", errno, fd_io_strerror( errno ) ));
  }
  err = close( fd_zstd );
  if( FD_UNLIKELY( err==-1 ) ) {
    FD_LOG_WARNING(( "Failed to close the snapshot file (%i-%s)", errno, fd_io_strerror( errno ) ));
  }
  err = remove( directory_buf_og );
  if( FD_UNLIKELY( err==-1 ) ) {
    FD_LOG_WARNING(( "Failed to remove the tar archive (%i-%s)", errno, fd_io_strerror( errno ) ));
  }

  return err;
}

int
fd_snapshot_create_new_snapshot( fd_snapshot_ctx_t *  snapshot_ctx,
                                 fd_exec_slot_ctx_t * slot_ctx ) {

  FD_SCRATCH_SCOPE_BEGIN {

  FD_LOG_NOTICE(( "Starting to produce a snapshot for slot=%lu in directory=%s", snapshot_ctx->snapshot_slot, snapshot_ctx->snapshot_dir ));

  /* TODO:FIXME: START HACK Do a funk publish and whatnot */
  fd_funk_t *     funk = slot_ctx->acc_mgr->funk;
  fd_funk_txn_t * txn  = slot_ctx->funk_txn;
  fd_funk_start_write( funk );
  ulong publish_err = fd_funk_txn_publish( funk, txn, 1 );
  if( !publish_err ) {
    FD_LOG_ERR(( "publish err" ));
    return -1;
  }
  fd_funk_end_write( funk );
  /* TODO:FIXME: END HACK */

  /* Validate that the snapshot_ctx is setup correctly */

  int err = fd_snapshot_create_validate_ctx( snapshot_ctx, slot_ctx );
  if( FD_UNLIKELY( err ) ) {
      return -1;
  }

  /* Setup the writer that is used. */

  err = fd_snapshot_create_setup_writer( snapshot_ctx );
  if( FD_UNLIKELY( err ) ) {
    return -1;
  }

  /* Write out the version file. */

  err = fd_snapshot_create_write_version( snapshot_ctx );
  if( FD_UNLIKELY( err ) ) {
    return -1; /* TODO: replace with a jump to cleanup */
  }

  /* Dump the status cache and append it to the tar archive. */

  err = fd_snapshot_create_write_status_cache( snapshot_ctx, slot_ctx );
  if( FD_UNLIKELY( err ) ) {
    return -1;
  }

  /* Populate and write out the manifest and append vecs. */

  err = fd_snapshot_create_write_manifest_and_acc_vecs( snapshot_ctx, slot_ctx );
  if( FD_UNLIKELY( err ) ) {
    return -1;
  }

  /* Compress the tar file and write it out to the specified directory. */

  err = fd_snapshot_create_compress( snapshot_ctx );
  if( FD_UNLIKELY( err ) ) {
    return -1;
  }

  /* TODO:FIXME: Do the cleanup here */

  } FD_SCRATCH_SCOPE_END;

  return 0;
}