// This is an auto-generated file. To add entries, edit fd_types.json
#ifndef HEADER_FD_RUNTIME_TYPES
#define HEADER_FD_RUNTIME_TYPES

#include "fd_bincode.h"
#include "../../ballet/utf8/fd_utf8.h"
#include "fd_types_custom.h"
#define FD_ACCOUNT_META_MAGIC 9823

/* sdk/program/src/feature.rs#L22 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_feature {
  ulong activated_at;
  uchar has_activated_at;
};
typedef struct fd_feature fd_feature_t;
#define FD_FEATURE_FOOTPRINT sizeof(fd_feature_t)
#define FD_FEATURE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_feature_off {
  uint activated_at_off;
};
typedef struct fd_feature_off fd_feature_off_t;
#define FD_FEATURE_OFF_FOOTPRINT sizeof(fd_feature_off_t)
#define FD_FEATURE_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/fee_calculator.rs#L9 */
/* Encoded Size: Fixed (8 bytes) */
struct __attribute__((aligned(8UL))) fd_fee_calculator {
  ulong lamports_per_signature;
};
typedef struct fd_fee_calculator fd_fee_calculator_t;
#define FD_FEE_CALCULATOR_FOOTPRINT sizeof(fd_fee_calculator_t)
#define FD_FEE_CALCULATOR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_fee_calculator_off {
  uint lamports_per_signature_off;
};
typedef struct fd_fee_calculator_off fd_fee_calculator_off_t;
#define FD_FEE_CALCULATOR_OFF_FOOTPRINT sizeof(fd_fee_calculator_off_t)
#define FD_FEE_CALCULATOR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_hash_age {
  fd_fee_calculator_t fee_calculator;
  ulong hash_index;
  ulong timestamp;
};
typedef struct fd_hash_age fd_hash_age_t;
#define FD_HASH_AGE_FOOTPRINT sizeof(fd_hash_age_t)
#define FD_HASH_AGE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_hash_age_off {
  uint fee_calculator_off;
  uint hash_index_off;
  uint timestamp_off;
};
typedef struct fd_hash_age_off fd_hash_age_off_t;
#define FD_HASH_AGE_OFF_FOOTPRINT sizeof(fd_hash_age_off_t)
#define FD_HASH_AGE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_hash_hash_age_pair {
  fd_hash_t key;
  fd_hash_age_t val;
};
typedef struct fd_hash_hash_age_pair fd_hash_hash_age_pair_t;
#define FD_HASH_HASH_AGE_PAIR_FOOTPRINT sizeof(fd_hash_hash_age_pair_t)
#define FD_HASH_HASH_AGE_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_hash_hash_age_pair_off {
  uint key_off;
  uint val_off;
};
typedef struct fd_hash_hash_age_pair_off fd_hash_hash_age_pair_off_t;
#define FD_HASH_HASH_AGE_PAIR_OFF_FOOTPRINT sizeof(fd_hash_hash_age_pair_off_t)
#define FD_HASH_HASH_AGE_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_block_hash_vec {
  ulong last_hash_index;
  fd_hash_t * last_hash;
  ulong ages_len;
  fd_hash_hash_age_pair_t * ages;
  ulong max_age;
};
typedef struct fd_block_hash_vec fd_block_hash_vec_t;
#define FD_BLOCK_HASH_VEC_FOOTPRINT sizeof(fd_block_hash_vec_t)
#define FD_BLOCK_HASH_VEC_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_block_hash_vec_off {
  uint last_hash_index_off;
  uint last_hash_off;
  uint ages_off;
  uint max_age_off;
};
typedef struct fd_block_hash_vec_off fd_block_hash_vec_off_t;
#define FD_BLOCK_HASH_VEC_OFF_FOOTPRINT sizeof(fd_block_hash_vec_off_t)
#define FD_BLOCK_HASH_VEC_OFF_ALIGN (8UL)

typedef struct fd_hash_hash_age_pair_t_mapnode fd_hash_hash_age_pair_t_mapnode_t;
#define REDBLK_T fd_hash_hash_age_pair_t_mapnode_t
#define REDBLK_NAME fd_hash_hash_age_pair_t_map
#define REDBLK_IMPL_STYLE 1
#include "../../util/tmpl/fd_redblack.c"
struct fd_hash_hash_age_pair_t_mapnode {
    fd_hash_hash_age_pair_t elem;
    ulong redblack_parent;
    ulong redblack_left;
    ulong redblack_right;
    int redblack_color;
};
static inline fd_hash_hash_age_pair_t_mapnode_t *
fd_hash_hash_age_pair_t_map_alloc( fd_valloc_t valloc, ulong len ) {
  if( FD_UNLIKELY( 0 == len ) ) len = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, fd_hash_hash_age_pair_t_map_align(), fd_hash_hash_age_pair_t_map_footprint(len));
  return fd_hash_hash_age_pair_t_map_join(fd_hash_hash_age_pair_t_map_new(mem, len));
}
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_block_hash_queue {
  ulong last_hash_index;
  fd_hash_t * last_hash;
  fd_hash_hash_age_pair_t_mapnode_t * ages_pool;
  fd_hash_hash_age_pair_t_mapnode_t * ages_root;
  ulong max_age;
};
typedef struct fd_block_hash_queue fd_block_hash_queue_t;
#define FD_BLOCK_HASH_QUEUE_FOOTPRINT sizeof(fd_block_hash_queue_t)
#define FD_BLOCK_HASH_QUEUE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_block_hash_queue_off {
  uint last_hash_index_off;
  uint last_hash_off;
  uint ages_off;
  uint max_age_off;
};
typedef struct fd_block_hash_queue_off fd_block_hash_queue_off_t;
#define FD_BLOCK_HASH_QUEUE_OFF_FOOTPRINT sizeof(fd_block_hash_queue_off_t)
#define FD_BLOCK_HASH_QUEUE_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (33 bytes) */
struct __attribute__((aligned(8UL))) fd_fee_rate_governor {
  ulong target_lamports_per_signature;
  ulong target_signatures_per_slot;
  ulong min_lamports_per_signature;
  ulong max_lamports_per_signature;
  uchar burn_percent;
};
typedef struct fd_fee_rate_governor fd_fee_rate_governor_t;
#define FD_FEE_RATE_GOVERNOR_FOOTPRINT sizeof(fd_fee_rate_governor_t)
#define FD_FEE_RATE_GOVERNOR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_fee_rate_governor_off {
  uint target_lamports_per_signature_off;
  uint target_signatures_per_slot_off;
  uint min_lamports_per_signature_off;
  uint max_lamports_per_signature_off;
  uint burn_percent_off;
};
typedef struct fd_fee_rate_governor_off fd_fee_rate_governor_off_t;
#define FD_FEE_RATE_GOVERNOR_OFF_FOOTPRINT sizeof(fd_fee_rate_governor_off_t)
#define FD_FEE_RATE_GOVERNOR_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (16 bytes) */
struct __attribute__((aligned(8UL))) fd_slot_pair {
  ulong slot;
  ulong val;
};
typedef struct fd_slot_pair fd_slot_pair_t;
#define FD_SLOT_PAIR_FOOTPRINT sizeof(fd_slot_pair_t)
#define FD_SLOT_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_pair_off {
  uint slot_off;
  uint val_off;
};
typedef struct fd_slot_pair_off fd_slot_pair_off_t;
#define FD_SLOT_PAIR_OFF_FOOTPRINT sizeof(fd_slot_pair_off_t)
#define FD_SLOT_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_hard_forks {
  ulong hard_forks_len;
  fd_slot_pair_t * hard_forks;
};
typedef struct fd_hard_forks fd_hard_forks_t;
#define FD_HARD_FORKS_FOOTPRINT sizeof(fd_hard_forks_t)
#define FD_HARD_FORKS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_hard_forks_off {
  uint hard_forks_off;
};
typedef struct fd_hard_forks_off fd_hard_forks_off_t;
#define FD_HARD_FORKS_OFF_FOOTPRINT sizeof(fd_hard_forks_off_t)
#define FD_HARD_FORKS_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (48 bytes) */
struct __attribute__((aligned(8UL))) fd_inflation {
  double initial;
  double terminal;
  double taper;
  double foundation;
  double foundation_term;
  double unused;
};
typedef struct fd_inflation fd_inflation_t;
#define FD_INFLATION_FOOTPRINT sizeof(fd_inflation_t)
#define FD_INFLATION_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_inflation_off {
  uint initial_off;
  uint terminal_off;
  uint taper_off;
  uint foundation_off;
  uint foundation_term_off;
  uint unused_off;
};
typedef struct fd_inflation_off fd_inflation_off_t;
#define FD_INFLATION_OFF_FOOTPRINT sizeof(fd_inflation_off_t)
#define FD_INFLATION_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/rent.rs#L11 */
/* Encoded Size: Fixed (17 bytes) */
struct __attribute__((aligned(8UL))) fd_rent {
  ulong lamports_per_uint8_year;
  double exemption_threshold;
  uchar burn_percent;
};
typedef struct fd_rent fd_rent_t;
#define FD_RENT_FOOTPRINT sizeof(fd_rent_t)
#define FD_RENT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_rent_off {
  uint lamports_per_uint8_year_off;
  uint exemption_threshold_off;
  uint burn_percent_off;
};
typedef struct fd_rent_off fd_rent_off_t;
#define FD_RENT_OFF_FOOTPRINT sizeof(fd_rent_off_t)
#define FD_RENT_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/epoch_schedule.rs#L26 */
/* Encoded Size: Fixed (33 bytes) */
struct __attribute__((aligned(1UL))) fd_epoch_schedule {
  ulong slots_per_epoch;
  ulong leader_schedule_slot_offset;
  uchar warmup;
  ulong first_normal_epoch;
  ulong first_normal_slot;
};
typedef struct fd_epoch_schedule fd_epoch_schedule_t;
#define FD_EPOCH_SCHEDULE_FOOTPRINT sizeof(fd_epoch_schedule_t)
#define FD_EPOCH_SCHEDULE_ALIGN (1UL)

struct __attribute__((aligned(1UL))) fd_epoch_schedule_off {
  uint slots_per_epoch_off;
  uint leader_schedule_slot_offset_off;
  uint warmup_off;
  uint first_normal_epoch_off;
  uint first_normal_slot_off;
};
typedef struct fd_epoch_schedule_off fd_epoch_schedule_off_t;
#define FD_EPOCH_SCHEDULE_OFF_FOOTPRINT sizeof(fd_epoch_schedule_off_t)
#define FD_EPOCH_SCHEDULE_OFF_ALIGN (1UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_rent_collector {
  ulong epoch;
  fd_epoch_schedule_t epoch_schedule;
  double slots_per_year;
  fd_rent_t rent;
};
typedef struct fd_rent_collector fd_rent_collector_t;
#define FD_RENT_COLLECTOR_FOOTPRINT sizeof(fd_rent_collector_t)
#define FD_RENT_COLLECTOR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_rent_collector_off {
  uint epoch_off;
  uint epoch_schedule_off;
  uint slots_per_year_off;
  uint rent_off;
};
typedef struct fd_rent_collector_off fd_rent_collector_off_t;
#define FD_RENT_COLLECTOR_OFF_FOOTPRINT sizeof(fd_rent_collector_off_t)
#define FD_RENT_COLLECTOR_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (32 bytes) */
struct __attribute__((aligned(8UL))) fd_stake_history_entry {
  ulong epoch;
  ulong effective;
  ulong activating;
  ulong deactivating;
};
typedef struct fd_stake_history_entry fd_stake_history_entry_t;
#define FD_STAKE_HISTORY_ENTRY_FOOTPRINT sizeof(fd_stake_history_entry_t)
#define FD_STAKE_HISTORY_ENTRY_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_history_entry_off {
  uint epoch_off;
  uint effective_off;
  uint activating_off;
  uint deactivating_off;
};
typedef struct fd_stake_history_entry_off fd_stake_history_entry_off_t;
#define FD_STAKE_HISTORY_ENTRY_OFF_FOOTPRINT sizeof(fd_stake_history_entry_off_t)
#define FD_STAKE_HISTORY_ENTRY_OFF_ALIGN (8UL)

/* https://github.com/firedancer-io/solana/blob/v1.17/sdk/program/src/stake_history.rs#L12-L75 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_history {
  ulong fd_stake_history_len;
  ulong fd_stake_history_size;
  ulong fd_stake_history_offset;
  fd_stake_history_entry_t fd_stake_history[512];
};
typedef struct fd_stake_history fd_stake_history_t;
#define FD_STAKE_HISTORY_FOOTPRINT sizeof(fd_stake_history_t)
#define FD_STAKE_HISTORY_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_history_off {
  uint fd_stake_history_off;
};
typedef struct fd_stake_history_off fd_stake_history_off_t;
#define FD_STAKE_HISTORY_OFF_FOOTPRINT sizeof(fd_stake_history_off_t)
#define FD_STAKE_HISTORY_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/6ac4fe32e28d8ceb4085072b61fa0c6cb09baac1/sdk/src/account.rs#L37 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_solana_account {
  ulong lamports;
  ulong data_len;
  uchar* data;
  fd_pubkey_t owner;
  uchar executable;
  ulong rent_epoch;
};
typedef struct fd_solana_account fd_solana_account_t;
#define FD_SOLANA_ACCOUNT_FOOTPRINT sizeof(fd_solana_account_t)
#define FD_SOLANA_ACCOUNT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_solana_account_off {
  uint lamports_off;
  uint data_off;
  uint owner_off;
  uint executable_off;
  uint rent_epoch_off;
};
typedef struct fd_solana_account_off fd_solana_account_off_t;
#define FD_SOLANA_ACCOUNT_OFF_FOOTPRINT sizeof(fd_solana_account_off_t)
#define FD_SOLANA_ACCOUNT_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (48 bytes) */
struct __attribute__((packed)) fd_solana_account_stored_meta {
  ulong write_version_obsolete;
  ulong data_len;
  uchar pubkey[32];
};
typedef struct fd_solana_account_stored_meta fd_solana_account_stored_meta_t;
#define FD_SOLANA_ACCOUNT_STORED_META_FOOTPRINT sizeof(fd_solana_account_stored_meta_t)
#define FD_SOLANA_ACCOUNT_STORED_META_ALIGN (8UL)

struct __attribute__((packed)) fd_solana_account_stored_meta_off {
  uint write_version_obsolete_off;
  uint data_len_off;
  uint pubkey_off;
};
typedef struct fd_solana_account_stored_meta_off fd_solana_account_stored_meta_off_t;
#define FD_SOLANA_ACCOUNT_STORED_META_OFF_FOOTPRINT sizeof(fd_solana_account_stored_meta_off_t)
#define FD_SOLANA_ACCOUNT_STORED_META_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (52 bytes) */
struct __attribute__((packed)) fd_solana_account_meta {
  ulong lamports;
  ulong rent_epoch;
  uchar owner[32];
  uchar executable;
  uchar padding[3];
};
typedef struct fd_solana_account_meta fd_solana_account_meta_t;
#define FD_SOLANA_ACCOUNT_META_FOOTPRINT sizeof(fd_solana_account_meta_t)
#define FD_SOLANA_ACCOUNT_META_ALIGN (8UL)

struct __attribute__((packed)) fd_solana_account_meta_off {
  uint lamports_off;
  uint rent_epoch_off;
  uint owner_off;
  uint executable_off;
  uint padding_off;
};
typedef struct fd_solana_account_meta_off fd_solana_account_meta_off_t;
#define FD_SOLANA_ACCOUNT_META_OFF_FOOTPRINT sizeof(fd_solana_account_meta_off_t)
#define FD_SOLANA_ACCOUNT_META_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((packed)) fd_solana_account_hdr {
  fd_solana_account_stored_meta_t meta;
  fd_solana_account_meta_t info;
  uchar padding[4];
  fd_hash_t hash;
};
typedef struct fd_solana_account_hdr fd_solana_account_hdr_t;
#define FD_SOLANA_ACCOUNT_HDR_FOOTPRINT sizeof(fd_solana_account_hdr_t)
#define FD_SOLANA_ACCOUNT_HDR_ALIGN (8UL)

struct __attribute__((packed)) fd_solana_account_hdr_off {
  uint meta_off;
  uint info_off;
  uint padding_off;
  uint hash_off;
};
typedef struct fd_solana_account_hdr_off fd_solana_account_hdr_off_t;
#define FD_SOLANA_ACCOUNT_HDR_OFF_FOOTPRINT sizeof(fd_solana_account_hdr_off_t)
#define FD_SOLANA_ACCOUNT_HDR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((packed)) fd_account_meta {
  ushort magic;
  ushort hlen;
  ulong dlen;
  uchar hash[32];
  ulong slot;
  fd_solana_account_meta_t info;
};
typedef struct fd_account_meta fd_account_meta_t;
#define FD_ACCOUNT_META_FOOTPRINT sizeof(fd_account_meta_t)
#define FD_ACCOUNT_META_ALIGN (8UL)

struct __attribute__((packed)) fd_account_meta_off {
  uint magic_off;
  uint hlen_off;
  uint dlen_off;
  uint hash_off;
  uint slot_off;
  uint info_off;
};
typedef struct fd_account_meta_off fd_account_meta_off_t;
#define FD_ACCOUNT_META_OFF_FOOTPRINT sizeof(fd_account_meta_off_t)
#define FD_ACCOUNT_META_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_accounts_pair {
  fd_pubkey_t key;
  ulong stake;
  fd_solana_vote_account_t value;
};
typedef struct fd_vote_accounts_pair fd_vote_accounts_pair_t;
#define FD_VOTE_ACCOUNTS_PAIR_FOOTPRINT sizeof(fd_vote_accounts_pair_t)
#define FD_VOTE_ACCOUNTS_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_accounts_pair_off {
  uint key_off;
  uint stake_off;
  uint value_off;
};
typedef struct fd_vote_accounts_pair_off fd_vote_accounts_pair_off_t;
#define FD_VOTE_ACCOUNTS_PAIR_OFF_FOOTPRINT sizeof(fd_vote_accounts_pair_off_t)
#define FD_VOTE_ACCOUNTS_PAIR_OFF_ALIGN (8UL)

typedef struct fd_vote_accounts_pair_t_mapnode fd_vote_accounts_pair_t_mapnode_t;
#define REDBLK_T fd_vote_accounts_pair_t_mapnode_t
#define REDBLK_NAME fd_vote_accounts_pair_t_map
#define REDBLK_IMPL_STYLE 1
#include "../../util/tmpl/fd_redblack.c"
struct fd_vote_accounts_pair_t_mapnode {
    fd_vote_accounts_pair_t elem;
    ulong redblack_parent;
    ulong redblack_left;
    ulong redblack_right;
    int redblack_color;
};
static inline fd_vote_accounts_pair_t_mapnode_t *
fd_vote_accounts_pair_t_map_alloc( fd_valloc_t valloc, ulong len ) {
  if( FD_UNLIKELY( 0 == len ) ) len = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, fd_vote_accounts_pair_t_map_align(), fd_vote_accounts_pair_t_map_footprint(len));
  return fd_vote_accounts_pair_t_map_join(fd_vote_accounts_pair_t_map_new(mem, len));
}
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_accounts {
  fd_vote_accounts_pair_t_mapnode_t * vote_accounts_pool;
  fd_vote_accounts_pair_t_mapnode_t * vote_accounts_root;
};
typedef struct fd_vote_accounts fd_vote_accounts_t;
#define FD_VOTE_ACCOUNTS_FOOTPRINT sizeof(fd_vote_accounts_t)
#define FD_VOTE_ACCOUNTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_accounts_off {
  uint vote_accounts_off;
};
typedef struct fd_vote_accounts_off fd_vote_accounts_off_t;
#define FD_VOTE_ACCOUNTS_OFF_FOOTPRINT sizeof(fd_vote_accounts_off_t)
#define FD_VOTE_ACCOUNTS_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (36 bytes) */
struct __attribute__((aligned(8UL))) fd_stake_accounts_pair {
  fd_pubkey_t key;
  uint exists;
};
typedef struct fd_stake_accounts_pair fd_stake_accounts_pair_t;
#define FD_STAKE_ACCOUNTS_PAIR_FOOTPRINT sizeof(fd_stake_accounts_pair_t)
#define FD_STAKE_ACCOUNTS_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_accounts_pair_off {
  uint key_off;
  uint exists_off;
};
typedef struct fd_stake_accounts_pair_off fd_stake_accounts_pair_off_t;
#define FD_STAKE_ACCOUNTS_PAIR_OFF_FOOTPRINT sizeof(fd_stake_accounts_pair_off_t)
#define FD_STAKE_ACCOUNTS_PAIR_OFF_ALIGN (8UL)

typedef struct fd_stake_accounts_pair_t_mapnode fd_stake_accounts_pair_t_mapnode_t;
#define REDBLK_T fd_stake_accounts_pair_t_mapnode_t
#define REDBLK_NAME fd_stake_accounts_pair_t_map
#define REDBLK_IMPL_STYLE 1
#include "../../util/tmpl/fd_redblack.c"
struct fd_stake_accounts_pair_t_mapnode {
    fd_stake_accounts_pair_t elem;
    ulong redblack_parent;
    ulong redblack_left;
    ulong redblack_right;
    int redblack_color;
};
static inline fd_stake_accounts_pair_t_mapnode_t *
fd_stake_accounts_pair_t_map_alloc( fd_valloc_t valloc, ulong len ) {
  if( FD_UNLIKELY( 0 == len ) ) len = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, fd_stake_accounts_pair_t_map_align(), fd_stake_accounts_pair_t_map_footprint(len));
  return fd_stake_accounts_pair_t_map_join(fd_stake_accounts_pair_t_map_new(mem, len));
}
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_accounts {
  fd_stake_accounts_pair_t_mapnode_t * stake_accounts_pool;
  fd_stake_accounts_pair_t_mapnode_t * stake_accounts_root;
};
typedef struct fd_stake_accounts fd_stake_accounts_t;
#define FD_STAKE_ACCOUNTS_FOOTPRINT sizeof(fd_stake_accounts_t)
#define FD_STAKE_ACCOUNTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_accounts_off {
  uint stake_accounts_off;
};
typedef struct fd_stake_accounts_off fd_stake_accounts_off_t;
#define FD_STAKE_ACCOUNTS_OFF_FOOTPRINT sizeof(fd_stake_accounts_off_t)
#define FD_STAKE_ACCOUNTS_OFF_ALIGN (8UL)

/* fd_stake_weight_t assigns an Ed25519 public key (node identity) a stake weight number measured in lamports */
/* Encoded Size: Fixed (40 bytes) */
struct __attribute__((aligned(8UL))) fd_stake_weight {
  fd_pubkey_t key;
  ulong stake;
};
typedef struct fd_stake_weight fd_stake_weight_t;
#define FD_STAKE_WEIGHT_FOOTPRINT sizeof(fd_stake_weight_t)
#define FD_STAKE_WEIGHT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_weight_off {
  uint key_off;
  uint stake_off;
};
typedef struct fd_stake_weight_off fd_stake_weight_off_t;
#define FD_STAKE_WEIGHT_OFF_FOOTPRINT sizeof(fd_stake_weight_off_t)
#define FD_STAKE_WEIGHT_OFF_ALIGN (8UL)

typedef struct fd_stake_weight_t_mapnode fd_stake_weight_t_mapnode_t;
#define REDBLK_T fd_stake_weight_t_mapnode_t
#define REDBLK_NAME fd_stake_weight_t_map
#define REDBLK_IMPL_STYLE 1
#include "../../util/tmpl/fd_redblack.c"
struct fd_stake_weight_t_mapnode {
    fd_stake_weight_t elem;
    ulong redblack_parent;
    ulong redblack_left;
    ulong redblack_right;
    int redblack_color;
};
static inline fd_stake_weight_t_mapnode_t *
fd_stake_weight_t_map_alloc( fd_valloc_t valloc, ulong len ) {
  if( FD_UNLIKELY( 0 == len ) ) len = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, fd_stake_weight_t_map_align(), fd_stake_weight_t_map_footprint(len));
  return fd_stake_weight_t_map_join(fd_stake_weight_t_map_new(mem, len));
}
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_weights {
  fd_stake_weight_t_mapnode_t * stake_weights_pool;
  fd_stake_weight_t_mapnode_t * stake_weights_root;
};
typedef struct fd_stake_weights fd_stake_weights_t;
#define FD_STAKE_WEIGHTS_FOOTPRINT sizeof(fd_stake_weights_t)
#define FD_STAKE_WEIGHTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_weights_off {
  uint stake_weights_off;
};
typedef struct fd_stake_weights_off fd_stake_weights_off_t;
#define FD_STAKE_WEIGHTS_OFF_FOOTPRINT sizeof(fd_stake_weights_off_t)
#define FD_STAKE_WEIGHTS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/state.rs#L303 */
/* Encoded Size: Fixed (64 bytes) */
struct __attribute__((aligned(8UL))) fd_delegation {
  fd_pubkey_t voter_pubkey;
  ulong stake;
  ulong activation_epoch;
  ulong deactivation_epoch;
  double warmup_cooldown_rate;
};
typedef struct fd_delegation fd_delegation_t;
#define FD_DELEGATION_FOOTPRINT sizeof(fd_delegation_t)
#define FD_DELEGATION_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_delegation_off {
  uint voter_pubkey_off;
  uint stake_off;
  uint activation_epoch_off;
  uint deactivation_epoch_off;
  uint warmup_cooldown_rate_off;
};
typedef struct fd_delegation_off fd_delegation_off_t;
#define FD_DELEGATION_OFF_FOOTPRINT sizeof(fd_delegation_off_t)
#define FD_DELEGATION_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_delegation_pair {
  fd_pubkey_t account;
  fd_delegation_t delegation;
};
typedef struct fd_delegation_pair fd_delegation_pair_t;
#define FD_DELEGATION_PAIR_FOOTPRINT sizeof(fd_delegation_pair_t)
#define FD_DELEGATION_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_delegation_pair_off {
  uint account_off;
  uint delegation_off;
};
typedef struct fd_delegation_pair_off fd_delegation_pair_off_t;
#define FD_DELEGATION_PAIR_OFF_FOOTPRINT sizeof(fd_delegation_pair_off_t)
#define FD_DELEGATION_PAIR_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/state.rs#L539 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake {
  fd_delegation_t delegation;
  ulong credits_observed;
};
typedef struct fd_stake fd_stake_t;
#define FD_STAKE_FOOTPRINT sizeof(fd_stake_t)
#define FD_STAKE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_off {
  uint delegation_off;
  uint credits_observed_off;
};
typedef struct fd_stake_off fd_stake_off_t;
#define FD_STAKE_OFF_FOOTPRINT sizeof(fd_stake_off_t)
#define FD_STAKE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_epoch_info_pair {
  fd_pubkey_t account;
  fd_stake_t stake;
};
typedef struct fd_epoch_info_pair fd_epoch_info_pair_t;
#define FD_EPOCH_INFO_PAIR_FOOTPRINT sizeof(fd_epoch_info_pair_t)
#define FD_EPOCH_INFO_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_epoch_info_pair_off {
  uint account_off;
  uint stake_off;
};
typedef struct fd_epoch_info_pair_off fd_epoch_info_pair_off_t;
#define FD_EPOCH_INFO_PAIR_OFF_FOOTPRINT sizeof(fd_epoch_info_pair_off_t)
#define FD_EPOCH_INFO_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_epoch_info {
  ulong infos_len;
  fd_epoch_info_pair_t * infos;
};
typedef struct fd_epoch_info fd_epoch_info_t;
#define FD_EPOCH_INFO_FOOTPRINT sizeof(fd_epoch_info_t)
#define FD_EPOCH_INFO_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_epoch_info_off {
  uint infos_off;
};
typedef struct fd_epoch_info_off fd_epoch_info_off_t;
#define FD_EPOCH_INFO_OFF_FOOTPRINT sizeof(fd_epoch_info_off_t)
#define FD_EPOCH_INFO_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_pair {
  fd_pubkey_t account;
  fd_stake_t stake;
};
typedef struct fd_stake_pair fd_stake_pair_t;
#define FD_STAKE_PAIR_FOOTPRINT sizeof(fd_stake_pair_t)
#define FD_STAKE_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_pair_off {
  uint account_off;
  uint stake_off;
};
typedef struct fd_stake_pair_off fd_stake_pair_off_t;
#define FD_STAKE_PAIR_OFF_FOOTPRINT sizeof(fd_stake_pair_off_t)
#define FD_STAKE_PAIR_OFF_ALIGN (8UL)

typedef struct fd_delegation_pair_t_mapnode fd_delegation_pair_t_mapnode_t;
#define REDBLK_T fd_delegation_pair_t_mapnode_t
#define REDBLK_NAME fd_delegation_pair_t_map
#define REDBLK_IMPL_STYLE 1
#include "../../util/tmpl/fd_redblack.c"
struct fd_delegation_pair_t_mapnode {
    fd_delegation_pair_t elem;
    ulong redblack_parent;
    ulong redblack_left;
    ulong redblack_right;
    int redblack_color;
};
static inline fd_delegation_pair_t_mapnode_t *
fd_delegation_pair_t_map_alloc( fd_valloc_t valloc, ulong len ) {
  if( FD_UNLIKELY( 0 == len ) ) len = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, fd_delegation_pair_t_map_align(), fd_delegation_pair_t_map_footprint(len));
  return fd_delegation_pair_t_map_join(fd_delegation_pair_t_map_new(mem, len));
}
/* https://github.com/anza-xyz/agave/blob/beb3f582f784a96e59e06ef8f34e855258bcd98c/runtime/src/stakes.rs#L202 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stakes {
  fd_vote_accounts_t vote_accounts;
  fd_delegation_pair_t_mapnode_t * stake_delegations_pool;
  fd_delegation_pair_t_mapnode_t * stake_delegations_root;
  ulong unused;
  ulong epoch;
  fd_stake_history_t stake_history;
};
typedef struct fd_stakes fd_stakes_t;
#define FD_STAKES_FOOTPRINT sizeof(fd_stakes_t)
#define FD_STAKES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stakes_off {
  uint vote_accounts_off;
  uint stake_delegations_off;
  uint unused_off;
  uint epoch_off;
  uint stake_history_off;
};
typedef struct fd_stakes_off fd_stakes_off_t;
#define FD_STAKES_OFF_FOOTPRINT sizeof(fd_stakes_off_t)
#define FD_STAKES_OFF_ALIGN (8UL)

typedef struct fd_stake_pair_t_mapnode fd_stake_pair_t_mapnode_t;
#define REDBLK_T fd_stake_pair_t_mapnode_t
#define REDBLK_NAME fd_stake_pair_t_map
#define REDBLK_IMPL_STYLE 1
#include "../../util/tmpl/fd_redblack.c"
struct fd_stake_pair_t_mapnode {
    fd_stake_pair_t elem;
    ulong redblack_parent;
    ulong redblack_left;
    ulong redblack_right;
    int redblack_color;
};
static inline fd_stake_pair_t_mapnode_t *
fd_stake_pair_t_map_alloc( fd_valloc_t valloc, ulong len ) {
  if( FD_UNLIKELY( 0 == len ) ) len = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, fd_stake_pair_t_map_align(), fd_stake_pair_t_map_footprint(len));
  return fd_stake_pair_t_map_join(fd_stake_pair_t_map_new(mem, len));
}
/* https://github.com/anza-xyz/agave/blob/beb3f582f784a96e59e06ef8f34e855258bcd98c/runtime/src/stakes.rs#L202 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stakes_stake {
  fd_vote_accounts_t vote_accounts;
  fd_stake_pair_t_mapnode_t * stake_delegations_pool;
  fd_stake_pair_t_mapnode_t * stake_delegations_root;
  ulong unused;
  ulong epoch;
  fd_stake_history_t stake_history;
};
typedef struct fd_stakes_stake fd_stakes_stake_t;
#define FD_STAKES_STAKE_FOOTPRINT sizeof(fd_stakes_stake_t)
#define FD_STAKES_STAKE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stakes_stake_off {
  uint vote_accounts_off;
  uint stake_delegations_off;
  uint unused_off;
  uint epoch_off;
  uint stake_history_off;
};
typedef struct fd_stakes_stake_off fd_stakes_stake_off_t;
#define FD_STAKES_STAKE_OFF_FOOTPRINT sizeof(fd_stakes_stake_off_t)
#define FD_STAKES_STAKE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_bank_incremental_snapshot_persistence {
  ulong full_slot;
  fd_hash_t full_hash;
  ulong full_capitalization;
  fd_hash_t incremental_hash;
  ulong incremental_capitalization;
};
typedef struct fd_bank_incremental_snapshot_persistence fd_bank_incremental_snapshot_persistence_t;
#define FD_BANK_INCREMENTAL_SNAPSHOT_PERSISTENCE_FOOTPRINT sizeof(fd_bank_incremental_snapshot_persistence_t)
#define FD_BANK_INCREMENTAL_SNAPSHOT_PERSISTENCE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bank_incremental_snapshot_persistence_off {
  uint full_slot_off;
  uint full_hash_off;
  uint full_capitalization_off;
  uint incremental_hash_off;
  uint incremental_capitalization_off;
};
typedef struct fd_bank_incremental_snapshot_persistence_off fd_bank_incremental_snapshot_persistence_off_t;
#define FD_BANK_INCREMENTAL_SNAPSHOT_PERSISTENCE_OFF_FOOTPRINT sizeof(fd_bank_incremental_snapshot_persistence_off_t)
#define FD_BANK_INCREMENTAL_SNAPSHOT_PERSISTENCE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_node_vote_accounts {
  ulong vote_accounts_len;
  fd_pubkey_t * vote_accounts;
  ulong total_stake;
};
typedef struct fd_node_vote_accounts fd_node_vote_accounts_t;
#define FD_NODE_VOTE_ACCOUNTS_FOOTPRINT sizeof(fd_node_vote_accounts_t)
#define FD_NODE_VOTE_ACCOUNTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_node_vote_accounts_off {
  uint vote_accounts_off;
  uint total_stake_off;
};
typedef struct fd_node_vote_accounts_off fd_node_vote_accounts_off_t;
#define FD_NODE_VOTE_ACCOUNTS_OFF_FOOTPRINT sizeof(fd_node_vote_accounts_off_t)
#define FD_NODE_VOTE_ACCOUNTS_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_pubkey_node_vote_accounts_pair {
  fd_pubkey_t key;
  fd_node_vote_accounts_t value;
};
typedef struct fd_pubkey_node_vote_accounts_pair fd_pubkey_node_vote_accounts_pair_t;
#define FD_PUBKEY_NODE_VOTE_ACCOUNTS_PAIR_FOOTPRINT sizeof(fd_pubkey_node_vote_accounts_pair_t)
#define FD_PUBKEY_NODE_VOTE_ACCOUNTS_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_pubkey_node_vote_accounts_pair_off {
  uint key_off;
  uint value_off;
};
typedef struct fd_pubkey_node_vote_accounts_pair_off fd_pubkey_node_vote_accounts_pair_off_t;
#define FD_PUBKEY_NODE_VOTE_ACCOUNTS_PAIR_OFF_FOOTPRINT sizeof(fd_pubkey_node_vote_accounts_pair_off_t)
#define FD_PUBKEY_NODE_VOTE_ACCOUNTS_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (64 bytes) */
struct __attribute__((aligned(8UL))) fd_pubkey_pubkey_pair {
  fd_pubkey_t key;
  fd_pubkey_t value;
};
typedef struct fd_pubkey_pubkey_pair fd_pubkey_pubkey_pair_t;
#define FD_PUBKEY_PUBKEY_PAIR_FOOTPRINT sizeof(fd_pubkey_pubkey_pair_t)
#define FD_PUBKEY_PUBKEY_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_pubkey_pubkey_pair_off {
  uint key_off;
  uint value_off;
};
typedef struct fd_pubkey_pubkey_pair_off fd_pubkey_pubkey_pair_off_t;
#define FD_PUBKEY_PUBKEY_PAIR_OFF_FOOTPRINT sizeof(fd_pubkey_pubkey_pair_off_t)
#define FD_PUBKEY_PUBKEY_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_epoch_stakes {
  fd_stakes_t stakes;
  ulong total_stake;
  ulong node_id_to_vote_accounts_len;
  fd_pubkey_node_vote_accounts_pair_t * node_id_to_vote_accounts;
  ulong epoch_authorized_voters_len;
  fd_pubkey_pubkey_pair_t * epoch_authorized_voters;
};
typedef struct fd_epoch_stakes fd_epoch_stakes_t;
#define FD_EPOCH_STAKES_FOOTPRINT sizeof(fd_epoch_stakes_t)
#define FD_EPOCH_STAKES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_epoch_stakes_off {
  uint stakes_off;
  uint total_stake_off;
  uint node_id_to_vote_accounts_off;
  uint epoch_authorized_voters_off;
};
typedef struct fd_epoch_stakes_off fd_epoch_stakes_off_t;
#define FD_EPOCH_STAKES_OFF_FOOTPRINT sizeof(fd_epoch_stakes_off_t)
#define FD_EPOCH_STAKES_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_epoch_epoch_stakes_pair {
  ulong key;
  fd_epoch_stakes_t value;
};
typedef struct fd_epoch_epoch_stakes_pair fd_epoch_epoch_stakes_pair_t;
#define FD_EPOCH_EPOCH_STAKES_PAIR_FOOTPRINT sizeof(fd_epoch_epoch_stakes_pair_t)
#define FD_EPOCH_EPOCH_STAKES_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_epoch_epoch_stakes_pair_off {
  uint key_off;
  uint value_off;
};
typedef struct fd_epoch_epoch_stakes_pair_off fd_epoch_epoch_stakes_pair_off_t;
#define FD_EPOCH_EPOCH_STAKES_PAIR_OFF_FOOTPRINT sizeof(fd_epoch_epoch_stakes_pair_off_t)
#define FD_EPOCH_EPOCH_STAKES_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (40 bytes) */
struct __attribute__((aligned(8UL))) fd_pubkey_u64_pair {
  fd_pubkey_t _0;
  ulong _1;
};
typedef struct fd_pubkey_u64_pair fd_pubkey_u64_pair_t;
#define FD_PUBKEY_U64_PAIR_FOOTPRINT sizeof(fd_pubkey_u64_pair_t)
#define FD_PUBKEY_U64_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_pubkey_u64_pair_off {
  uint _0_off;
  uint _1_off;
};
typedef struct fd_pubkey_u64_pair_off fd_pubkey_u64_pair_off_t;
#define FD_PUBKEY_U64_PAIR_OFF_FOOTPRINT sizeof(fd_pubkey_u64_pair_off_t)
#define FD_PUBKEY_U64_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_unused_accounts {
  ulong unused1_len;
  fd_pubkey_t * unused1;
  ulong unused2_len;
  fd_pubkey_t * unused2;
  ulong unused3_len;
  fd_pubkey_u64_pair_t * unused3;
};
typedef struct fd_unused_accounts fd_unused_accounts_t;
#define FD_UNUSED_ACCOUNTS_FOOTPRINT sizeof(fd_unused_accounts_t)
#define FD_UNUSED_ACCOUNTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_unused_accounts_off {
  uint unused1_off;
  uint unused2_off;
  uint unused3_off;
};
typedef struct fd_unused_accounts_off fd_unused_accounts_off_t;
#define FD_UNUSED_ACCOUNTS_OFF_FOOTPRINT sizeof(fd_unused_accounts_off_t)
#define FD_UNUSED_ACCOUNTS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/88aeaa82a856fc807234e7da0b31b89f2dc0e091/runtime/src/bank.rs#L967 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(16UL))) fd_deserializable_versioned_bank {
  fd_block_hash_vec_t blockhash_queue;
  ulong ancestors_len;
  fd_slot_pair_t * ancestors;
  fd_hash_t hash;
  fd_hash_t parent_hash;
  ulong parent_slot;
  fd_hard_forks_t hard_forks;
  ulong transaction_count;
  ulong tick_height;
  ulong signature_count;
  ulong capitalization;
  ulong max_tick_height;
  ulong* hashes_per_tick;
  ulong ticks_per_slot;
  uint128 ns_per_slot;
  ulong genesis_creation_time;
  double slots_per_year;
  ulong accounts_data_len;
  ulong slot;
  ulong epoch;
  ulong block_height;
  fd_pubkey_t collector_id;
  ulong collector_fees;
  fd_fee_calculator_t fee_calculator;
  fd_fee_rate_governor_t fee_rate_governor;
  ulong collected_rent;
  fd_rent_collector_t rent_collector;
  fd_epoch_schedule_t epoch_schedule;
  fd_inflation_t inflation;
  fd_stakes_t stakes;
  fd_unused_accounts_t unused_accounts;
  ulong epoch_stakes_len;
  fd_epoch_epoch_stakes_pair_t * epoch_stakes;
  uchar is_delta;
};
typedef struct fd_deserializable_versioned_bank fd_deserializable_versioned_bank_t;
#define FD_DESERIALIZABLE_VERSIONED_BANK_FOOTPRINT sizeof(fd_deserializable_versioned_bank_t)
#define FD_DESERIALIZABLE_VERSIONED_BANK_ALIGN (16UL)

struct __attribute__((aligned(16UL))) fd_deserializable_versioned_bank_off {
  uint blockhash_queue_off;
  uint ancestors_off;
  uint hash_off;
  uint parent_hash_off;
  uint parent_slot_off;
  uint hard_forks_off;
  uint transaction_count_off;
  uint tick_height_off;
  uint signature_count_off;
  uint capitalization_off;
  uint max_tick_height_off;
  uint hashes_per_tick_off;
  uint ticks_per_slot_off;
  uint ns_per_slot_off;
  uint genesis_creation_time_off;
  uint slots_per_year_off;
  uint accounts_data_len_off;
  uint slot_off;
  uint epoch_off;
  uint block_height_off;
  uint collector_id_off;
  uint collector_fees_off;
  uint fee_calculator_off;
  uint fee_rate_governor_off;
  uint collected_rent_off;
  uint rent_collector_off;
  uint epoch_schedule_off;
  uint inflation_off;
  uint stakes_off;
  uint unused_accounts_off;
  uint epoch_stakes_off;
  uint is_delta_off;
};
typedef struct fd_deserializable_versioned_bank_off fd_deserializable_versioned_bank_off_t;
#define FD_DESERIALIZABLE_VERSIONED_BANK_OFF_FOOTPRINT sizeof(fd_deserializable_versioned_bank_off_t)
#define FD_DESERIALIZABLE_VERSIONED_BANK_OFF_ALIGN (16UL)

/* Encoded Size: Fixed (40 bytes) */
struct __attribute__((aligned(8UL))) fd_bank_hash_stats {
  ulong num_updated_accounts;
  ulong num_removed_accounts;
  ulong num_lamports_stored;
  ulong total_data_len;
  ulong num_executable_accounts;
};
typedef struct fd_bank_hash_stats fd_bank_hash_stats_t;
#define FD_BANK_HASH_STATS_FOOTPRINT sizeof(fd_bank_hash_stats_t)
#define FD_BANK_HASH_STATS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bank_hash_stats_off {
  uint num_updated_accounts_off;
  uint num_removed_accounts_off;
  uint num_lamports_stored_off;
  uint total_data_len_off;
  uint num_executable_accounts_off;
};
typedef struct fd_bank_hash_stats_off fd_bank_hash_stats_off_t;
#define FD_BANK_HASH_STATS_OFF_FOOTPRINT sizeof(fd_bank_hash_stats_off_t)
#define FD_BANK_HASH_STATS_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_bank_hash_info {
  fd_hash_t hash;
  fd_hash_t snapshot_hash;
  fd_bank_hash_stats_t stats;
};
typedef struct fd_bank_hash_info fd_bank_hash_info_t;
#define FD_BANK_HASH_INFO_FOOTPRINT sizeof(fd_bank_hash_info_t)
#define FD_BANK_HASH_INFO_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bank_hash_info_off {
  uint hash_off;
  uint snapshot_hash_off;
  uint stats_off;
};
typedef struct fd_bank_hash_info_off fd_bank_hash_info_off_t;
#define FD_BANK_HASH_INFO_OFF_FOOTPRINT sizeof(fd_bank_hash_info_off_t)
#define FD_BANK_HASH_INFO_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_map_pair {
  ulong slot;
  fd_hash_t hash;
};
typedef struct fd_slot_map_pair fd_slot_map_pair_t;
#define FD_SLOT_MAP_PAIR_FOOTPRINT sizeof(fd_slot_map_pair_t)
#define FD_SLOT_MAP_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_map_pair_off {
  uint slot_off;
  uint hash_off;
};
typedef struct fd_slot_map_pair_off fd_slot_map_pair_off_t;
#define FD_SLOT_MAP_PAIR_OFF_FOOTPRINT sizeof(fd_slot_map_pair_off_t)
#define FD_SLOT_MAP_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (16 bytes) */
struct __attribute__((aligned(8UL))) fd_snapshot_acc_vec {
  ulong id;
  ulong file_sz;
};
typedef struct fd_snapshot_acc_vec fd_snapshot_acc_vec_t;
#define FD_SNAPSHOT_ACC_VEC_FOOTPRINT sizeof(fd_snapshot_acc_vec_t)
#define FD_SNAPSHOT_ACC_VEC_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_snapshot_acc_vec_off {
  uint id_off;
  uint file_sz_off;
};
typedef struct fd_snapshot_acc_vec_off fd_snapshot_acc_vec_off_t;
#define FD_SNAPSHOT_ACC_VEC_OFF_FOOTPRINT sizeof(fd_snapshot_acc_vec_off_t)
#define FD_SNAPSHOT_ACC_VEC_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_snapshot_slot_acc_vecs {
  ulong slot;
  ulong account_vecs_len;
  fd_snapshot_acc_vec_t * account_vecs;
};
typedef struct fd_snapshot_slot_acc_vecs fd_snapshot_slot_acc_vecs_t;
#define FD_SNAPSHOT_SLOT_ACC_VECS_FOOTPRINT sizeof(fd_snapshot_slot_acc_vecs_t)
#define FD_SNAPSHOT_SLOT_ACC_VECS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_snapshot_slot_acc_vecs_off {
  uint slot_off;
  uint account_vecs_off;
};
typedef struct fd_snapshot_slot_acc_vecs_off fd_snapshot_slot_acc_vecs_off_t;
#define FD_SNAPSHOT_SLOT_ACC_VECS_OFF_FOOTPRINT sizeof(fd_snapshot_slot_acc_vecs_off_t)
#define FD_SNAPSHOT_SLOT_ACC_VECS_OFF_ALIGN (8UL)

union fd_reward_type_inner {
  uchar nonempty; /* Hack to support enums with no inner structures */ 
};
typedef union fd_reward_type_inner fd_reward_type_inner_t;

/* https://github.com/anza-xyz/agave/blob/7117ed9653ce19e8b2dea108eff1f3eb6a3378a7/sdk/src/reward_type.rs#L7 */
struct fd_reward_type {
  uint discriminant;
  fd_reward_type_inner_t inner;
};
typedef struct fd_reward_type fd_reward_type_t;
#define FD_REWARD_TYPE_FOOTPRINT sizeof(fd_reward_type_t)
#define FD_REWARD_TYPE_ALIGN (8UL)

/* Accounts DB related fields in a snapshot */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_solana_accounts_db_fields {
  ulong storages_len;
  fd_snapshot_slot_acc_vecs_t * storages;
  ulong version;
  ulong slot;
  fd_bank_hash_info_t bank_hash_info;
  ulong historical_roots_len;
  ulong* historical_roots;
  ulong historical_roots_with_hash_len;
  fd_slot_map_pair_t * historical_roots_with_hash;
};
typedef struct fd_solana_accounts_db_fields fd_solana_accounts_db_fields_t;
#define FD_SOLANA_ACCOUNTS_DB_FIELDS_FOOTPRINT sizeof(fd_solana_accounts_db_fields_t)
#define FD_SOLANA_ACCOUNTS_DB_FIELDS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_solana_accounts_db_fields_off {
  uint storages_off;
  uint version_off;
  uint slot_off;
  uint bank_hash_info_off;
  uint historical_roots_off;
  uint historical_roots_with_hash_off;
};
typedef struct fd_solana_accounts_db_fields_off fd_solana_accounts_db_fields_off_t;
#define FD_SOLANA_ACCOUNTS_DB_FIELDS_OFF_FOOTPRINT sizeof(fd_solana_accounts_db_fields_off_t)
#define FD_SOLANA_ACCOUNTS_DB_FIELDS_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_versioned_epoch_stakes_current {
  fd_stakes_stake_t stakes;
  ulong total_stake;
  ulong node_id_to_vote_accounts_len;
  fd_pubkey_node_vote_accounts_pair_t * node_id_to_vote_accounts;
  ulong epoch_authorized_voters_len;
  fd_pubkey_pubkey_pair_t * epoch_authorized_voters;
};
typedef struct fd_versioned_epoch_stakes_current fd_versioned_epoch_stakes_current_t;
#define FD_VERSIONED_EPOCH_STAKES_CURRENT_FOOTPRINT sizeof(fd_versioned_epoch_stakes_current_t)
#define FD_VERSIONED_EPOCH_STAKES_CURRENT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_versioned_epoch_stakes_current_off {
  uint stakes_off;
  uint total_stake_off;
  uint node_id_to_vote_accounts_off;
  uint epoch_authorized_voters_off;
};
typedef struct fd_versioned_epoch_stakes_current_off fd_versioned_epoch_stakes_current_off_t;
#define FD_VERSIONED_EPOCH_STAKES_CURRENT_OFF_FOOTPRINT sizeof(fd_versioned_epoch_stakes_current_off_t)
#define FD_VERSIONED_EPOCH_STAKES_CURRENT_OFF_ALIGN (8UL)

union fd_versioned_epoch_stakes_inner {
  fd_versioned_epoch_stakes_current_t Current;
};
typedef union fd_versioned_epoch_stakes_inner fd_versioned_epoch_stakes_inner_t;

struct fd_versioned_epoch_stakes {
  uint discriminant;
  fd_versioned_epoch_stakes_inner_t inner;
};
typedef struct fd_versioned_epoch_stakes fd_versioned_epoch_stakes_t;
#define FD_VERSIONED_EPOCH_STAKES_FOOTPRINT sizeof(fd_versioned_epoch_stakes_t)
#define FD_VERSIONED_EPOCH_STAKES_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_versioned_epoch_stakes_pair {
  ulong epoch;
  fd_versioned_epoch_stakes_t val;
};
typedef struct fd_versioned_epoch_stakes_pair fd_versioned_epoch_stakes_pair_t;
#define FD_VERSIONED_EPOCH_STAKES_PAIR_FOOTPRINT sizeof(fd_versioned_epoch_stakes_pair_t)
#define FD_VERSIONED_EPOCH_STAKES_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_versioned_epoch_stakes_pair_off {
  uint epoch_off;
  uint val_off;
};
typedef struct fd_versioned_epoch_stakes_pair_off fd_versioned_epoch_stakes_pair_off_t;
#define FD_VERSIONED_EPOCH_STAKES_PAIR_OFF_FOOTPRINT sizeof(fd_versioned_epoch_stakes_pair_off_t)
#define FD_VERSIONED_EPOCH_STAKES_PAIR_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/7117ed9653ce19e8b2dea108eff1f3eb6a3378a7/sdk/src/reward_info.rs#L5 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_reward_info {
  fd_reward_type_t reward_type;
  ulong lamports;
  ulong post_balance;
  ulong commission;
};
typedef struct fd_reward_info fd_reward_info_t;
#define FD_REWARD_INFO_FOOTPRINT sizeof(fd_reward_info_t)
#define FD_REWARD_INFO_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_reward_info_off {
  uint reward_type_off;
  uint lamports_off;
  uint post_balance_off;
  uint commission_off;
};
typedef struct fd_reward_info_off fd_reward_info_off_t;
#define FD_REWARD_INFO_OFF_FOOTPRINT sizeof(fd_reward_info_off_t)
#define FD_REWARD_INFO_OFF_ALIGN (8UL)

/* You can cast this to a (fd_lthash_value_t *) and use it directly since the alignment is preserved */
/* Encoded Size: Fixed (2048 bytes) */
struct __attribute__((aligned(128UL))) fd_slot_lthash {
  uchar lthash[2048];
};
typedef struct fd_slot_lthash fd_slot_lthash_t;
#define FD_SLOT_LTHASH_FOOTPRINT sizeof(fd_slot_lthash_t)
#define FD_SLOT_LTHASH_ALIGN (128UL)

struct __attribute__((aligned(128UL))) fd_slot_lthash_off {
  uint lthash_off;
};
typedef struct fd_slot_lthash_off fd_slot_lthash_off_t;
#define FD_SLOT_LTHASH_OFF_FOOTPRINT sizeof(fd_slot_lthash_off_t)
#define FD_SLOT_LTHASH_OFF_ALIGN (128UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(16UL))) fd_solana_manifest {
  fd_deserializable_versioned_bank_t bank;
  fd_solana_accounts_db_fields_t accounts_db;
  ulong lamports_per_signature;
  fd_bank_incremental_snapshot_persistence_t * bank_incremental_snapshot_persistence;
  fd_hash_t * epoch_account_hash;
  ulong versioned_epoch_stakes_len;
  fd_versioned_epoch_stakes_pair_t * versioned_epoch_stakes;
  fd_slot_lthash_t * lthash;
};
typedef struct fd_solana_manifest fd_solana_manifest_t;
#define FD_SOLANA_MANIFEST_FOOTPRINT sizeof(fd_solana_manifest_t)
#define FD_SOLANA_MANIFEST_ALIGN (16UL)

struct __attribute__((aligned(16UL))) fd_solana_manifest_off {
  uint bank_off;
  uint accounts_db_off;
  uint lamports_per_signature_off;
  uint bank_incremental_snapshot_persistence_off;
  uint epoch_account_hash_off;
  uint versioned_epoch_stakes_off;
  uint lthash_off;
};
typedef struct fd_solana_manifest_off fd_solana_manifest_off_t;
#define FD_SOLANA_MANIFEST_OFF_FOOTPRINT sizeof(fd_solana_manifest_off_t)
#define FD_SOLANA_MANIFEST_OFF_ALIGN (16UL)

/* Encoded Size: Fixed (12 bytes) */
struct __attribute__((aligned(8UL))) fd_rust_duration {
  ulong seconds;
  uint nanoseconds;
};
typedef struct fd_rust_duration fd_rust_duration_t;
#define FD_RUST_DURATION_FOOTPRINT sizeof(fd_rust_duration_t)
#define FD_RUST_DURATION_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_rust_duration_off {
  uint seconds_off;
  uint nanoseconds_off;
};
typedef struct fd_rust_duration_off fd_rust_duration_off_t;
#define FD_RUST_DURATION_OFF_FOOTPRINT sizeof(fd_rust_duration_off_t)
#define FD_RUST_DURATION_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_poh_config {
  fd_rust_duration_t target_tick_duration;
  ulong* target_tick_count;
  ulong hashes_per_tick;
  uchar has_hashes_per_tick;
};
typedef struct fd_poh_config fd_poh_config_t;
#define FD_POH_CONFIG_FOOTPRINT sizeof(fd_poh_config_t)
#define FD_POH_CONFIG_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_poh_config_off {
  uint target_tick_duration_off;
  uint target_tick_count_off;
  uint hashes_per_tick_off;
};
typedef struct fd_poh_config_off fd_poh_config_off_t;
#define FD_POH_CONFIG_OFF_FOOTPRINT sizeof(fd_poh_config_off_t)
#define FD_POH_CONFIG_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_string_pubkey_pair {
  ulong string_len;
  uchar* string;
  fd_pubkey_t pubkey;
};
typedef struct fd_string_pubkey_pair fd_string_pubkey_pair_t;
#define FD_STRING_PUBKEY_PAIR_FOOTPRINT sizeof(fd_string_pubkey_pair_t)
#define FD_STRING_PUBKEY_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_string_pubkey_pair_off {
  uint string_off;
  uint pubkey_off;
};
typedef struct fd_string_pubkey_pair_off fd_string_pubkey_pair_off_t;
#define FD_STRING_PUBKEY_PAIR_OFF_FOOTPRINT sizeof(fd_string_pubkey_pair_off_t)
#define FD_STRING_PUBKEY_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_pubkey_account_pair {
  fd_pubkey_t key;
  fd_solana_account_t account;
};
typedef struct fd_pubkey_account_pair fd_pubkey_account_pair_t;
#define FD_PUBKEY_ACCOUNT_PAIR_FOOTPRINT sizeof(fd_pubkey_account_pair_t)
#define FD_PUBKEY_ACCOUNT_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_pubkey_account_pair_off {
  uint key_off;
  uint account_off;
};
typedef struct fd_pubkey_account_pair_off fd_pubkey_account_pair_off_t;
#define FD_PUBKEY_ACCOUNT_PAIR_OFF_FOOTPRINT sizeof(fd_pubkey_account_pair_off_t)
#define FD_PUBKEY_ACCOUNT_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_genesis_solana {
  ulong creation_time;
  ulong accounts_len;
  fd_pubkey_account_pair_t * accounts;
  ulong native_instruction_processors_len;
  fd_string_pubkey_pair_t * native_instruction_processors;
  ulong rewards_pools_len;
  fd_pubkey_account_pair_t * rewards_pools;
  ulong ticks_per_slot;
  ulong unused;
  fd_poh_config_t poh_config;
  ulong __backwards_compat_with_v0_23;
  fd_fee_rate_governor_t fee_rate_governor;
  fd_rent_t rent;
  fd_inflation_t inflation;
  fd_epoch_schedule_t epoch_schedule;
  uint cluster_type;
};
typedef struct fd_genesis_solana fd_genesis_solana_t;
#define FD_GENESIS_SOLANA_FOOTPRINT sizeof(fd_genesis_solana_t)
#define FD_GENESIS_SOLANA_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_genesis_solana_off {
  uint creation_time_off;
  uint accounts_off;
  uint native_instruction_processors_off;
  uint rewards_pools_off;
  uint ticks_per_slot_off;
  uint unused_off;
  uint poh_config_off;
  uint __backwards_compat_with_v0_23_off;
  uint fee_rate_governor_off;
  uint rent_off;
  uint inflation_off;
  uint epoch_schedule_off;
  uint cluster_type_off;
};
typedef struct fd_genesis_solana_off fd_genesis_solana_off_t;
#define FD_GENESIS_SOLANA_OFF_FOOTPRINT sizeof(fd_genesis_solana_off_t)
#define FD_GENESIS_SOLANA_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/clock.rs#L114 */
/* Encoded Size: Fixed (40 bytes) */
struct __attribute__((aligned(8UL))) fd_sol_sysvar_clock {
  ulong slot;
  long epoch_start_timestamp;
  ulong epoch;
  ulong leader_schedule_epoch;
  long unix_timestamp;
};
typedef struct fd_sol_sysvar_clock fd_sol_sysvar_clock_t;
#define FD_SOL_SYSVAR_CLOCK_FOOTPRINT sizeof(fd_sol_sysvar_clock_t)
#define FD_SOL_SYSVAR_CLOCK_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_sol_sysvar_clock_off {
  uint slot_off;
  uint epoch_start_timestamp_off;
  uint epoch_off;
  uint leader_schedule_epoch_off;
  uint unix_timestamp_off;
};
typedef struct fd_sol_sysvar_clock_off fd_sol_sysvar_clock_off_t;
#define FD_SOL_SYSVAR_CLOCK_OFF_FOOTPRINT sizeof(fd_sol_sysvar_clock_off_t)
#define FD_SOL_SYSVAR_CLOCK_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/30531d7a5b74f914dde53bfbb0bc2144f2ac92bb/sdk/program/src/last_restart_slot.rs#L7 */
/* Encoded Size: Fixed (8 bytes) */
struct __attribute__((aligned(8UL))) fd_sol_sysvar_last_restart_slot {
  ulong slot;
};
typedef struct fd_sol_sysvar_last_restart_slot fd_sol_sysvar_last_restart_slot_t;
#define FD_SOL_SYSVAR_LAST_RESTART_SLOT_FOOTPRINT sizeof(fd_sol_sysvar_last_restart_slot_t)
#define FD_SOL_SYSVAR_LAST_RESTART_SLOT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_sol_sysvar_last_restart_slot_off {
  uint slot_off;
};
typedef struct fd_sol_sysvar_last_restart_slot_off fd_sol_sysvar_last_restart_slot_off_t;
#define FD_SOL_SYSVAR_LAST_RESTART_SLOT_OFF_FOOTPRINT sizeof(fd_sol_sysvar_last_restart_slot_off_t)
#define FD_SOL_SYSVAR_LAST_RESTART_SLOT_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (12 bytes) */
struct __attribute__((aligned(8UL))) fd_vote_lockout {
  ulong slot;
  uint confirmation_count;
};
typedef struct fd_vote_lockout fd_vote_lockout_t;
#define FD_VOTE_LOCKOUT_FOOTPRINT sizeof(fd_vote_lockout_t)
#define FD_VOTE_LOCKOUT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_lockout_off {
  uint slot_off;
  uint confirmation_count_off;
};
typedef struct fd_vote_lockout_off fd_vote_lockout_off_t;
#define FD_VOTE_LOCKOUT_OFF_FOOTPRINT sizeof(fd_vote_lockout_off_t)
#define FD_VOTE_LOCKOUT_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_lockout_offset {
  ulong offset;
  uchar confirmation_count;
};
typedef struct fd_lockout_offset fd_lockout_offset_t;
#define FD_LOCKOUT_OFFSET_FOOTPRINT sizeof(fd_lockout_offset_t)
#define FD_LOCKOUT_OFFSET_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_lockout_offset_off {
  uint offset_off;
  uint confirmation_count_off;
};
typedef struct fd_lockout_offset_off fd_lockout_offset_off_t;
#define FD_LOCKOUT_OFFSET_OFF_FOOTPRINT sizeof(fd_lockout_offset_off_t)
#define FD_LOCKOUT_OFFSET_OFF_ALIGN (8UL)

/* https://github.com/firedancer-io/solana/blob/da470eef4652b3b22598a1f379cacfe82bd5928d/sdk/program/src/vote/authorized_voters.rs#L9 */
/* Encoded Size: Fixed (72 bytes) */
struct __attribute__((aligned(8UL))) fd_vote_authorized_voter {
  ulong epoch;
  fd_pubkey_t pubkey;
  ulong parent;
  ulong left;
  ulong right;
  ulong prio;
};
typedef struct fd_vote_authorized_voter fd_vote_authorized_voter_t;
#define FD_VOTE_AUTHORIZED_VOTER_FOOTPRINT sizeof(fd_vote_authorized_voter_t)
#define FD_VOTE_AUTHORIZED_VOTER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_authorized_voter_off {
  uint epoch_off;
  uint pubkey_off;
  uint parent_off;
  uint left_off;
  uint right_off;
  uint prio_off;
};
typedef struct fd_vote_authorized_voter_off fd_vote_authorized_voter_off_t;
#define FD_VOTE_AUTHORIZED_VOTER_OFF_FOOTPRINT sizeof(fd_vote_authorized_voter_off_t)
#define FD_VOTE_AUTHORIZED_VOTER_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (48 bytes) */
struct __attribute__((aligned(8UL))) fd_vote_prior_voter {
  fd_pubkey_t pubkey;
  ulong epoch_start;
  ulong epoch_end;
};
typedef struct fd_vote_prior_voter fd_vote_prior_voter_t;
#define FD_VOTE_PRIOR_VOTER_FOOTPRINT sizeof(fd_vote_prior_voter_t)
#define FD_VOTE_PRIOR_VOTER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_prior_voter_off {
  uint pubkey_off;
  uint epoch_start_off;
  uint epoch_end_off;
};
typedef struct fd_vote_prior_voter_off fd_vote_prior_voter_off_t;
#define FD_VOTE_PRIOR_VOTER_OFF_FOOTPRINT sizeof(fd_vote_prior_voter_off_t)
#define FD_VOTE_PRIOR_VOTER_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (56 bytes) */
struct __attribute__((aligned(8UL))) fd_vote_prior_voter_0_23_5 {
  fd_pubkey_t pubkey;
  ulong epoch_start;
  ulong epoch_end;
  ulong slot;
};
typedef struct fd_vote_prior_voter_0_23_5 fd_vote_prior_voter_0_23_5_t;
#define FD_VOTE_PRIOR_VOTER_0_23_5_FOOTPRINT sizeof(fd_vote_prior_voter_0_23_5_t)
#define FD_VOTE_PRIOR_VOTER_0_23_5_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_prior_voter_0_23_5_off {
  uint pubkey_off;
  uint epoch_start_off;
  uint epoch_end_off;
  uint slot_off;
};
typedef struct fd_vote_prior_voter_0_23_5_off fd_vote_prior_voter_0_23_5_off_t;
#define FD_VOTE_PRIOR_VOTER_0_23_5_OFF_FOOTPRINT sizeof(fd_vote_prior_voter_0_23_5_off_t)
#define FD_VOTE_PRIOR_VOTER_0_23_5_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (24 bytes) */
struct __attribute__((aligned(8UL))) fd_vote_epoch_credits {
  ulong epoch;
  ulong credits;
  ulong prev_credits;
};
typedef struct fd_vote_epoch_credits fd_vote_epoch_credits_t;
#define FD_VOTE_EPOCH_CREDITS_FOOTPRINT sizeof(fd_vote_epoch_credits_t)
#define FD_VOTE_EPOCH_CREDITS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_epoch_credits_off {
  uint epoch_off;
  uint credits_off;
  uint prev_credits_off;
};
typedef struct fd_vote_epoch_credits_off fd_vote_epoch_credits_off_t;
#define FD_VOTE_EPOCH_CREDITS_OFF_FOOTPRINT sizeof(fd_vote_epoch_credits_off_t)
#define FD_VOTE_EPOCH_CREDITS_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (16 bytes) */
struct __attribute__((aligned(8UL))) fd_vote_block_timestamp {
  ulong slot;
  long timestamp;
};
typedef struct fd_vote_block_timestamp fd_vote_block_timestamp_t;
#define FD_VOTE_BLOCK_TIMESTAMP_FOOTPRINT sizeof(fd_vote_block_timestamp_t)
#define FD_VOTE_BLOCK_TIMESTAMP_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_block_timestamp_off {
  uint slot_off;
  uint timestamp_off;
};
typedef struct fd_vote_block_timestamp_off fd_vote_block_timestamp_off_t;
#define FD_VOTE_BLOCK_TIMESTAMP_OFF_FOOTPRINT sizeof(fd_vote_block_timestamp_off_t)
#define FD_VOTE_BLOCK_TIMESTAMP_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L268 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_prior_voters {
  fd_vote_prior_voter_t buf[32];
  ulong idx;
  uchar is_empty;
};
typedef struct fd_vote_prior_voters fd_vote_prior_voters_t;
#define FD_VOTE_PRIOR_VOTERS_FOOTPRINT sizeof(fd_vote_prior_voters_t)
#define FD_VOTE_PRIOR_VOTERS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_prior_voters_off {
  uint buf_off;
  uint idx_off;
  uint is_empty_off;
};
typedef struct fd_vote_prior_voters_off fd_vote_prior_voters_off_t;
#define FD_VOTE_PRIOR_VOTERS_OFF_FOOTPRINT sizeof(fd_vote_prior_voters_off_t)
#define FD_VOTE_PRIOR_VOTERS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L268 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_prior_voters_0_23_5 {
  fd_vote_prior_voter_0_23_5_t buf[32];
  ulong idx;
};
typedef struct fd_vote_prior_voters_0_23_5 fd_vote_prior_voters_0_23_5_t;
#define FD_VOTE_PRIOR_VOTERS_0_23_5_FOOTPRINT sizeof(fd_vote_prior_voters_0_23_5_t)
#define FD_VOTE_PRIOR_VOTERS_0_23_5_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_prior_voters_0_23_5_off {
  uint buf_off;
  uint idx_off;
};
typedef struct fd_vote_prior_voters_0_23_5_off fd_vote_prior_voters_0_23_5_off_t;
#define FD_VOTE_PRIOR_VOTERS_0_23_5_OFF_FOOTPRINT sizeof(fd_vote_prior_voters_0_23_5_off_t)
#define FD_VOTE_PRIOR_VOTERS_0_23_5_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L268 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_landed_vote {
  uchar latency;
  fd_vote_lockout_t lockout;
};
typedef struct fd_landed_vote fd_landed_vote_t;
#define FD_LANDED_VOTE_FOOTPRINT sizeof(fd_landed_vote_t)
#define FD_LANDED_VOTE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_landed_vote_off {
  uint latency_off;
  uint lockout_off;
};
typedef struct fd_landed_vote_off fd_landed_vote_off_t;
#define FD_LANDED_VOTE_OFF_FOOTPRINT sizeof(fd_landed_vote_off_t)
#define FD_LANDED_VOTE_OFF_ALIGN (8UL)

#define DEQUE_NAME deq_fd_vote_lockout_t
#define DEQUE_T fd_vote_lockout_t
#include "../../util/tmpl/fd_deque_dynamic.c"
#undef DEQUE_NAME
#undef DEQUE_T
#undef DEQUE_MAX
static inline fd_vote_lockout_t *
deq_fd_vote_lockout_t_alloc( fd_valloc_t valloc, ulong max ) {
  if( FD_UNLIKELY( 0 == max ) ) max = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, deq_fd_vote_lockout_t_align(), deq_fd_vote_lockout_t_footprint( max ) );
  return deq_fd_vote_lockout_t_join( deq_fd_vote_lockout_t_new( mem, max ) );
}
#define DEQUE_NAME deq_fd_vote_epoch_credits_t
#define DEQUE_T fd_vote_epoch_credits_t
#include "../../util/tmpl/fd_deque_dynamic.c"
#undef DEQUE_NAME
#undef DEQUE_T
#undef DEQUE_MAX
static inline fd_vote_epoch_credits_t *
deq_fd_vote_epoch_credits_t_alloc( fd_valloc_t valloc, ulong max ) {
  if( FD_UNLIKELY( 0 == max ) ) max = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, deq_fd_vote_epoch_credits_t_align(), deq_fd_vote_epoch_credits_t_footprint( max ) );
  return deq_fd_vote_epoch_credits_t_join( deq_fd_vote_epoch_credits_t_new( mem, max ) );
}
/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/vote_state_0_23_5.rs#L6 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_state_0_23_5 {
  fd_pubkey_t node_pubkey;
  fd_pubkey_t authorized_voter;
  ulong authorized_voter_epoch;
  fd_vote_prior_voters_0_23_5_t prior_voters;
  fd_pubkey_t authorized_withdrawer;
  uchar commission;
  fd_vote_lockout_t * votes; /* fd_deque_dynamic (min cnt 32) */
  ulong root_slot;
  uchar has_root_slot;
  fd_vote_epoch_credits_t * epoch_credits; /* fd_deque_dynamic (min cnt 64) */
  fd_vote_block_timestamp_t last_timestamp;
};
typedef struct fd_vote_state_0_23_5 fd_vote_state_0_23_5_t;
#define FD_VOTE_STATE_0_23_5_FOOTPRINT sizeof(fd_vote_state_0_23_5_t)
#define FD_VOTE_STATE_0_23_5_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_state_0_23_5_off {
  uint node_pubkey_off;
  uint authorized_voter_off;
  uint authorized_voter_epoch_off;
  uint prior_voters_off;
  uint authorized_withdrawer_off;
  uint commission_off;
  uint votes_off;
  uint root_slot_off;
  uint epoch_credits_off;
  uint last_timestamp_off;
};
typedef struct fd_vote_state_0_23_5_off fd_vote_state_0_23_5_off_t;
#define FD_VOTE_STATE_0_23_5_OFF_FOOTPRINT sizeof(fd_vote_state_0_23_5_off_t)
#define FD_VOTE_STATE_0_23_5_OFF_ALIGN (8UL)

#define FD_VOTE_AUTHORIZED_VOTERS_MIN 64
#define POOL_NAME fd_vote_authorized_voters_pool
#define POOL_T fd_vote_authorized_voter_t
#define POOL_NEXT parent
#include "../../util/tmpl/fd_pool.c"
static inline fd_vote_authorized_voter_t *
fd_vote_authorized_voters_pool_alloc( fd_valloc_t valloc, ulong num ) {
  if( FD_UNLIKELY( 0 == num ) ) num = 1; // prevent underflow
  return fd_vote_authorized_voters_pool_join( fd_vote_authorized_voters_pool_new(
      fd_valloc_malloc( valloc,
                        fd_vote_authorized_voters_pool_align(),
                        fd_vote_authorized_voters_pool_footprint( num ) ),
      num ) );
}
#define TREAP_NAME fd_vote_authorized_voters_treap
#define TREAP_T fd_vote_authorized_voter_t
#define TREAP_QUERY_T ulong
#define TREAP_CMP(q,e) ( (q == (e)->epoch) ? 0 : ( (q < (e)->epoch) ? -1 : 1 ) )
#define TREAP_LT(e0,e1) ((e0)->epoch<(e1)->epoch)
#include "../../util/tmpl/fd_treap.c"
static inline fd_vote_authorized_voters_treap_t *
fd_vote_authorized_voters_treap_alloc( fd_valloc_t valloc, ulong num ) {
  if( FD_UNLIKELY( 0 == num ) ) num = 1; // prevent underflow
  return fd_vote_authorized_voters_treap_join( fd_vote_authorized_voters_treap_new(
      fd_valloc_malloc( valloc,
                        fd_vote_authorized_voters_treap_align(),
                        fd_vote_authorized_voters_treap_footprint( num ) ),
      num ) );
}
/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L310 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_authorized_voters {
  fd_vote_authorized_voter_t * pool;
  fd_vote_authorized_voters_treap_t * treap;
};
typedef struct fd_vote_authorized_voters fd_vote_authorized_voters_t;
#define FD_VOTE_AUTHORIZED_VOTERS_FOOTPRINT sizeof(fd_vote_authorized_voters_t)
#define FD_VOTE_AUTHORIZED_VOTERS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_authorized_voters_off {
  uint fd_vote_authorized_voters_off;
};
typedef struct fd_vote_authorized_voters_off fd_vote_authorized_voters_off_t;
#define FD_VOTE_AUTHORIZED_VOTERS_OFF_FOOTPRINT sizeof(fd_vote_authorized_voters_off_t)
#define FD_VOTE_AUTHORIZED_VOTERS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L310 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_state_1_14_11 {
  fd_pubkey_t node_pubkey;
  fd_pubkey_t authorized_withdrawer;
  uchar commission;
  fd_vote_lockout_t * votes; /* fd_deque_dynamic (min cnt 32) */
  ulong root_slot;
  uchar has_root_slot;
  fd_vote_authorized_voters_t authorized_voters;
  fd_vote_prior_voters_t prior_voters;
  fd_vote_epoch_credits_t * epoch_credits; /* fd_deque_dynamic (min cnt 64) */
  fd_vote_block_timestamp_t last_timestamp;
};
typedef struct fd_vote_state_1_14_11 fd_vote_state_1_14_11_t;
#define FD_VOTE_STATE_1_14_11_FOOTPRINT sizeof(fd_vote_state_1_14_11_t)
#define FD_VOTE_STATE_1_14_11_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_state_1_14_11_off {
  uint node_pubkey_off;
  uint authorized_withdrawer_off;
  uint commission_off;
  uint votes_off;
  uint root_slot_off;
  uint authorized_voters_off;
  uint prior_voters_off;
  uint epoch_credits_off;
  uint last_timestamp_off;
};
typedef struct fd_vote_state_1_14_11_off fd_vote_state_1_14_11_off_t;
#define FD_VOTE_STATE_1_14_11_OFF_FOOTPRINT sizeof(fd_vote_state_1_14_11_off_t)
#define FD_VOTE_STATE_1_14_11_OFF_ALIGN (8UL)

#define DEQUE_NAME deq_fd_landed_vote_t
#define DEQUE_T fd_landed_vote_t
#include "../../util/tmpl/fd_deque_dynamic.c"
#undef DEQUE_NAME
#undef DEQUE_T
#undef DEQUE_MAX
static inline fd_landed_vote_t *
deq_fd_landed_vote_t_alloc( fd_valloc_t valloc, ulong max ) {
  if( FD_UNLIKELY( 0 == max ) ) max = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, deq_fd_landed_vote_t_align(), deq_fd_landed_vote_t_footprint( max ) );
  return deq_fd_landed_vote_t_join( deq_fd_landed_vote_t_new( mem, max ) );
}
/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L310 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_state {
  fd_pubkey_t node_pubkey;
  fd_pubkey_t authorized_withdrawer;
  uchar commission;
  fd_landed_vote_t * votes; /* fd_deque_dynamic (min cnt 32) */
  ulong root_slot;
  uchar has_root_slot;
  fd_vote_authorized_voters_t authorized_voters;
  fd_vote_prior_voters_t prior_voters;
  fd_vote_epoch_credits_t * epoch_credits; /* fd_deque_dynamic (min cnt 64) */
  fd_vote_block_timestamp_t last_timestamp;
};
typedef struct fd_vote_state fd_vote_state_t;
#define FD_VOTE_STATE_FOOTPRINT sizeof(fd_vote_state_t)
#define FD_VOTE_STATE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_state_off {
  uint node_pubkey_off;
  uint authorized_withdrawer_off;
  uint commission_off;
  uint votes_off;
  uint root_slot_off;
  uint authorized_voters_off;
  uint prior_voters_off;
  uint epoch_credits_off;
  uint last_timestamp_off;
};
typedef struct fd_vote_state_off fd_vote_state_off_t;
#define FD_VOTE_STATE_OFF_FOOTPRINT sizeof(fd_vote_state_off_t)
#define FD_VOTE_STATE_OFF_ALIGN (8UL)

union fd_vote_state_versioned_inner {
  fd_vote_state_0_23_5_t v0_23_5;
  fd_vote_state_1_14_11_t v1_14_11;
  fd_vote_state_t current;
};
typedef union fd_vote_state_versioned_inner fd_vote_state_versioned_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/vote_state_versions.rs#L4 */
struct fd_vote_state_versioned {
  uint discriminant;
  fd_vote_state_versioned_inner_t inner;
};
typedef struct fd_vote_state_versioned fd_vote_state_versioned_t;
#define FD_VOTE_STATE_VERSIONED_FOOTPRINT sizeof(fd_vote_state_versioned_t)
#define FD_VOTE_STATE_VERSIONED_ALIGN (8UL)

union fd_vote_state_versioned_off_inner {
  fd_vote_state_0_23_5_off_t v0_23_5_off;
  fd_vote_state_1_14_11_off_t v1_14_11_off;
  fd_vote_state_off_t current_off;
};
typedef union fd_vote_state_versioned_off_inner fd_vote_state_versioned_off_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/vote_state_versions.rs#L4 */
struct fd_vote_state_versioned_off {
  uint discriminant;
  fd_vote_state_versioned_off_inner_t inner;
};
typedef struct fd_vote_state_versioned_off fd_vote_state_versioned_off_t;
#define FD_VOTE_STATE_VERSIONED_OFF_FOOTPRINT sizeof(fd_vote_state_versioned_off_t)
#define FD_VOTE_STATE_VERSIONED_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L185 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_state_update {
  fd_vote_lockout_t * lockouts; /* fd_deque_dynamic (min cnt 32) */
  ulong root;
  uchar has_root;
  fd_hash_t hash;
  long timestamp;
  uchar has_timestamp;
};
typedef struct fd_vote_state_update fd_vote_state_update_t;
#define FD_VOTE_STATE_UPDATE_FOOTPRINT sizeof(fd_vote_state_update_t)
#define FD_VOTE_STATE_UPDATE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_state_update_off {
  uint lockouts_off;
  uint root_off;
  uint hash_off;
  uint timestamp_off;
};
typedef struct fd_vote_state_update_off fd_vote_state_update_off_t;
#define FD_VOTE_STATE_UPDATE_OFF_FOOTPRINT sizeof(fd_vote_state_update_off_t)
#define FD_VOTE_STATE_UPDATE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_compact_vote_state_update {
  ulong root;
  ushort lockouts_len;
  fd_lockout_offset_t * lockouts;
  fd_hash_t hash;
  long timestamp;
  uchar has_timestamp;
};
typedef struct fd_compact_vote_state_update fd_compact_vote_state_update_t;
#define FD_COMPACT_VOTE_STATE_UPDATE_FOOTPRINT sizeof(fd_compact_vote_state_update_t)
#define FD_COMPACT_VOTE_STATE_UPDATE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_compact_vote_state_update_off {
  uint root_off;
  uint lockouts_off;
  uint hash_off;
  uint timestamp_off;
};
typedef struct fd_compact_vote_state_update_off fd_compact_vote_state_update_off_t;
#define FD_COMPACT_VOTE_STATE_UPDATE_OFF_FOOTPRINT sizeof(fd_compact_vote_state_update_off_t)
#define FD_COMPACT_VOTE_STATE_UPDATE_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/252438e28fbfb2c695fe1215171b83456e4b761c/programs/vote/src/vote_instruction.rs#L143 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_compact_vote_state_update_switch {
  fd_compact_vote_state_update_t compact_vote_state_update;
  fd_hash_t hash;
};
typedef struct fd_compact_vote_state_update_switch fd_compact_vote_state_update_switch_t;
#define FD_COMPACT_VOTE_STATE_UPDATE_SWITCH_FOOTPRINT sizeof(fd_compact_vote_state_update_switch_t)
#define FD_COMPACT_VOTE_STATE_UPDATE_SWITCH_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_compact_vote_state_update_switch_off {
  uint compact_vote_state_update_off;
  uint hash_off;
};
typedef struct fd_compact_vote_state_update_switch_off fd_compact_vote_state_update_switch_off_t;
#define FD_COMPACT_VOTE_STATE_UPDATE_SWITCH_OFF_FOOTPRINT sizeof(fd_compact_vote_state_update_switch_off_t)
#define FD_COMPACT_VOTE_STATE_UPDATE_SWITCH_OFF_ALIGN (8UL)

#define DEQUE_NAME deq_fd_lockout_offset_t
#define DEQUE_T fd_lockout_offset_t
#include "../../util/tmpl/fd_deque_dynamic.c"
#undef DEQUE_NAME
#undef DEQUE_T
#undef DEQUE_MAX
static inline fd_lockout_offset_t *
deq_fd_lockout_offset_t_alloc( fd_valloc_t valloc, ulong max ) {
  if( FD_UNLIKELY( 0 == max ) ) max = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, deq_fd_lockout_offset_t_align(), deq_fd_lockout_offset_t_footprint( max ) );
  return deq_fd_lockout_offset_t_join( deq_fd_lockout_offset_t_new( mem, max ) );
}
/* https://github.com/anza-xyz/agave/blob/20ee70cd1829cd414d09040460defecf9792a370/sdk/program/src/vote/state/mod.rs#L990 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_compact_tower_sync {
  ulong root;
  fd_lockout_offset_t * lockout_offsets; /* fd_deque_dynamic (min cnt 32) */
  fd_hash_t hash;
  long timestamp;
  uchar has_timestamp;
  fd_hash_t block_id;
};
typedef struct fd_compact_tower_sync fd_compact_tower_sync_t;
#define FD_COMPACT_TOWER_SYNC_FOOTPRINT sizeof(fd_compact_tower_sync_t)
#define FD_COMPACT_TOWER_SYNC_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_compact_tower_sync_off {
  uint root_off;
  uint lockout_offsets_off;
  uint hash_off;
  uint timestamp_off;
  uint block_id_off;
};
typedef struct fd_compact_tower_sync_off fd_compact_tower_sync_off_t;
#define FD_COMPACT_TOWER_SYNC_OFF_FOOTPRINT sizeof(fd_compact_tower_sync_off_t)
#define FD_COMPACT_TOWER_SYNC_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L185 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_tower_sync {
  fd_vote_lockout_t * lockouts; /* fd_deque_dynamic */
  ulong lockouts_cnt;
  ulong root;
  uchar has_root;
  fd_hash_t hash;
  long timestamp;
  uchar has_timestamp;
  fd_hash_t block_id;
};
typedef struct fd_tower_sync fd_tower_sync_t;
#define FD_TOWER_SYNC_FOOTPRINT sizeof(fd_tower_sync_t)
#define FD_TOWER_SYNC_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_tower_sync_off {
  uint lockouts_off;
  uint lockouts_cnt_off;
  uint root_off;
  uint hash_off;
  uint timestamp_off;
  uint block_id_off;
};
typedef struct fd_tower_sync_off fd_tower_sync_off_t;
#define FD_TOWER_SYNC_OFF_FOOTPRINT sizeof(fd_tower_sync_off_t)
#define FD_TOWER_SYNC_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_instruction.rs#L104 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_tower_sync_switch {
  fd_tower_sync_t tower_sync;
  fd_hash_t hash;
};
typedef struct fd_tower_sync_switch fd_tower_sync_switch_t;
#define FD_TOWER_SYNC_SWITCH_FOOTPRINT sizeof(fd_tower_sync_switch_t)
#define FD_TOWER_SYNC_SWITCH_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_tower_sync_switch_off {
  uint tower_sync_off;
  uint hash_off;
};
typedef struct fd_tower_sync_switch_off fd_tower_sync_switch_off_t;
#define FD_TOWER_SYNC_SWITCH_OFF_FOOTPRINT sizeof(fd_tower_sync_switch_off_t)
#define FD_TOWER_SYNC_SWITCH_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_history_inner {
  ulong blocks_len;
  ulong* blocks;
};
typedef struct fd_slot_history_inner fd_slot_history_inner_t;
#define FD_SLOT_HISTORY_INNER_FOOTPRINT sizeof(fd_slot_history_inner_t)
#define FD_SLOT_HISTORY_INNER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_history_inner_off {
  uint blocks_off;
};
typedef struct fd_slot_history_inner_off fd_slot_history_inner_off_t;
#define FD_SLOT_HISTORY_INNER_OFF_FOOTPRINT sizeof(fd_slot_history_inner_off_t)
#define FD_SLOT_HISTORY_INNER_OFF_ALIGN (8UL)

/* https://github.com/tov/bv-rs/blob/107be3e9c45324e55844befa4c4239d4d3d092c6/src/bit_vec/inner.rs#L8 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_history_bitvec {
  fd_slot_history_inner_t * bits;
  ulong len;
};
typedef struct fd_slot_history_bitvec fd_slot_history_bitvec_t;
#define FD_SLOT_HISTORY_BITVEC_FOOTPRINT sizeof(fd_slot_history_bitvec_t)
#define FD_SLOT_HISTORY_BITVEC_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_history_bitvec_off {
  uint bits_off;
  uint len_off;
};
typedef struct fd_slot_history_bitvec_off fd_slot_history_bitvec_off_t;
#define FD_SLOT_HISTORY_BITVEC_OFF_FOOTPRINT sizeof(fd_slot_history_bitvec_off_t)
#define FD_SLOT_HISTORY_BITVEC_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/slot_history.rs#L11 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_history {
  fd_slot_history_bitvec_t bits;
  ulong next_slot;
};
typedef struct fd_slot_history fd_slot_history_t;
#define FD_SLOT_HISTORY_FOOTPRINT sizeof(fd_slot_history_t)
#define FD_SLOT_HISTORY_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_history_off {
  uint bits_off;
  uint next_slot_off;
};
typedef struct fd_slot_history_off fd_slot_history_off_t;
#define FD_SLOT_HISTORY_OFF_FOOTPRINT sizeof(fd_slot_history_off_t)
#define FD_SLOT_HISTORY_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_hash {
  ulong slot;
  fd_hash_t hash;
};
typedef struct fd_slot_hash fd_slot_hash_t;
#define FD_SLOT_HASH_FOOTPRINT sizeof(fd_slot_hash_t)
#define FD_SLOT_HASH_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_hash_off {
  uint slot_off;
  uint hash_off;
};
typedef struct fd_slot_hash_off fd_slot_hash_off_t;
#define FD_SLOT_HASH_OFF_FOOTPRINT sizeof(fd_slot_hash_off_t)
#define FD_SLOT_HASH_OFF_ALIGN (8UL)

#define DEQUE_NAME deq_fd_slot_hash_t
#define DEQUE_T fd_slot_hash_t
#include "../../util/tmpl/fd_deque_dynamic.c"
#undef DEQUE_NAME
#undef DEQUE_T
#undef DEQUE_MAX
static inline fd_slot_hash_t *
deq_fd_slot_hash_t_alloc( fd_valloc_t valloc, ulong max ) {
  if( FD_UNLIKELY( 0 == max ) ) max = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, deq_fd_slot_hash_t_align(), deq_fd_slot_hash_t_footprint( max ) );
  return deq_fd_slot_hash_t_join( deq_fd_slot_hash_t_new( mem, max ) );
}
/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/slot_hashes.rs#L31 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_hashes {
  fd_slot_hash_t * hashes; /* fd_deque_dynamic (min cnt 512) */
};
typedef struct fd_slot_hashes fd_slot_hashes_t;
#define FD_SLOT_HASHES_FOOTPRINT sizeof(fd_slot_hashes_t)
#define FD_SLOT_HASHES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_hashes_off {
  uint hashes_off;
};
typedef struct fd_slot_hashes_off fd_slot_hashes_off_t;
#define FD_SLOT_HASHES_OFF_FOOTPRINT sizeof(fd_slot_hashes_off_t)
#define FD_SLOT_HASHES_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_block_block_hash_entry {
  fd_hash_t blockhash;
  fd_fee_calculator_t fee_calculator;
};
typedef struct fd_block_block_hash_entry fd_block_block_hash_entry_t;
#define FD_BLOCK_BLOCK_HASH_ENTRY_FOOTPRINT sizeof(fd_block_block_hash_entry_t)
#define FD_BLOCK_BLOCK_HASH_ENTRY_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_block_block_hash_entry_off {
  uint blockhash_off;
  uint fee_calculator_off;
};
typedef struct fd_block_block_hash_entry_off fd_block_block_hash_entry_off_t;
#define FD_BLOCK_BLOCK_HASH_ENTRY_OFF_FOOTPRINT sizeof(fd_block_block_hash_entry_off_t)
#define FD_BLOCK_BLOCK_HASH_ENTRY_OFF_ALIGN (8UL)

#define DEQUE_NAME deq_fd_block_block_hash_entry_t
#define DEQUE_T fd_block_block_hash_entry_t
#include "../../util/tmpl/fd_deque_dynamic.c"
#undef DEQUE_NAME
#undef DEQUE_T
#undef DEQUE_MAX
static inline fd_block_block_hash_entry_t *
deq_fd_block_block_hash_entry_t_alloc( fd_valloc_t valloc, ulong max ) {
  if( FD_UNLIKELY( 0 == max ) ) max = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, deq_fd_block_block_hash_entry_t_align(), deq_fd_block_block_hash_entry_t_footprint( max ) );
  return deq_fd_block_block_hash_entry_t_join( deq_fd_block_block_hash_entry_t_new( mem, max ) );
}
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_recent_block_hashes {
  fd_block_block_hash_entry_t * hashes; /* fd_deque_dynamic (min cnt 151) */
};
typedef struct fd_recent_block_hashes fd_recent_block_hashes_t;
#define FD_RECENT_BLOCK_HASHES_FOOTPRINT sizeof(fd_recent_block_hashes_t)
#define FD_RECENT_BLOCK_HASHES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_recent_block_hashes_off {
  uint hashes_off;
};
typedef struct fd_recent_block_hashes_off fd_recent_block_hashes_off_t;
#define FD_RECENT_BLOCK_HASHES_OFF_FOOTPRINT sizeof(fd_recent_block_hashes_off_t)
#define FD_RECENT_BLOCK_HASHES_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_meta {
  ulong slot;
  ulong consumed;
  ulong received;
  long first_shred_timestamp;
  ulong last_index;
  ulong parent_slot;
  ulong next_slot_len;
  ulong* next_slot;
  uchar is_connected;
  ulong entry_end_indexes_len;
  uint* entry_end_indexes;
};
typedef struct fd_slot_meta fd_slot_meta_t;
#define FD_SLOT_META_FOOTPRINT sizeof(fd_slot_meta_t)
#define FD_SLOT_META_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_meta_off {
  uint slot_off;
  uint consumed_off;
  uint received_off;
  uint first_shred_timestamp_off;
  uint last_index_off;
  uint parent_slot_off;
  uint next_slot_off;
  uint is_connected_off;
  uint entry_end_indexes_off;
};
typedef struct fd_slot_meta_off fd_slot_meta_off_t;
#define FD_SLOT_META_OFF_FOOTPRINT sizeof(fd_slot_meta_off_t)
#define FD_SLOT_META_OFF_ALIGN (8UL)

/* A validator timestamp oracle vote received from a voting node */
/* Encoded Size: Fixed (48 bytes) */
struct __attribute__((aligned(8UL))) fd_clock_timestamp_vote {
  fd_pubkey_t pubkey;
  long timestamp;
  ulong slot;
};
typedef struct fd_clock_timestamp_vote fd_clock_timestamp_vote_t;
#define FD_CLOCK_TIMESTAMP_VOTE_FOOTPRINT sizeof(fd_clock_timestamp_vote_t)
#define FD_CLOCK_TIMESTAMP_VOTE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_clock_timestamp_vote_off {
  uint pubkey_off;
  uint timestamp_off;
  uint slot_off;
};
typedef struct fd_clock_timestamp_vote_off fd_clock_timestamp_vote_off_t;
#define FD_CLOCK_TIMESTAMP_VOTE_OFF_FOOTPRINT sizeof(fd_clock_timestamp_vote_off_t)
#define FD_CLOCK_TIMESTAMP_VOTE_OFF_ALIGN (8UL)

typedef struct fd_clock_timestamp_vote_t_mapnode fd_clock_timestamp_vote_t_mapnode_t;
#define REDBLK_T fd_clock_timestamp_vote_t_mapnode_t
#define REDBLK_NAME fd_clock_timestamp_vote_t_map
#define REDBLK_IMPL_STYLE 1
#include "../../util/tmpl/fd_redblack.c"
struct fd_clock_timestamp_vote_t_mapnode {
    fd_clock_timestamp_vote_t elem;
    ulong redblack_parent;
    ulong redblack_left;
    ulong redblack_right;
    int redblack_color;
};
static inline fd_clock_timestamp_vote_t_mapnode_t *
fd_clock_timestamp_vote_t_map_alloc( fd_valloc_t valloc, ulong len ) {
  if( FD_UNLIKELY( 0 == len ) ) len = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, fd_clock_timestamp_vote_t_map_align(), fd_clock_timestamp_vote_t_map_footprint(len));
  return fd_clock_timestamp_vote_t_map_join(fd_clock_timestamp_vote_t_map_new(mem, len));
}
/* Validator timestamp oracle votes received from voting nodes. TODO: make this a map */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_clock_timestamp_votes {
  fd_clock_timestamp_vote_t_mapnode_t * votes_pool;
  fd_clock_timestamp_vote_t_mapnode_t * votes_root;
};
typedef struct fd_clock_timestamp_votes fd_clock_timestamp_votes_t;
#define FD_CLOCK_TIMESTAMP_VOTES_FOOTPRINT sizeof(fd_clock_timestamp_votes_t)
#define FD_CLOCK_TIMESTAMP_VOTES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_clock_timestamp_votes_off {
  uint votes_off;
};
typedef struct fd_clock_timestamp_votes_off fd_clock_timestamp_votes_off_t;
#define FD_CLOCK_TIMESTAMP_VOTES_OFF_FOOTPRINT sizeof(fd_clock_timestamp_votes_off_t)
#define FD_CLOCK_TIMESTAMP_VOTES_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/sysvar/fees.rs#L21 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_sysvar_fees {
  fd_fee_calculator_t fee_calculator;
};
typedef struct fd_sysvar_fees fd_sysvar_fees_t;
#define FD_SYSVAR_FEES_FOOTPRINT sizeof(fd_sysvar_fees_t)
#define FD_SYSVAR_FEES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_sysvar_fees_off {
  uint fee_calculator_off;
};
typedef struct fd_sysvar_fees_off fd_sysvar_fees_off_t;
#define FD_SYSVAR_FEES_OFF_FOOTPRINT sizeof(fd_sysvar_fees_off_t)
#define FD_SYSVAR_FEES_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/cbc8320d35358da14d79ebcada4dfb6756ffac79/sdk/program/src/epoch_rewards.rs#L14 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_sysvar_epoch_rewards {
  ulong distribution_starting_block_height;
  ulong num_partitions;
  fd_hash_t parent_blockhash;
  uint128 total_points;
  ulong total_rewards;
  ulong distributed_rewards;
  uchar active;
};
typedef struct fd_sysvar_epoch_rewards fd_sysvar_epoch_rewards_t;
#define FD_SYSVAR_EPOCH_REWARDS_FOOTPRINT sizeof(fd_sysvar_epoch_rewards_t)
#define FD_SYSVAR_EPOCH_REWARDS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_sysvar_epoch_rewards_off {
  uint distribution_starting_block_height_off;
  uint num_partitions_off;
  uint parent_blockhash_off;
  uint total_points_off;
  uint total_rewards_off;
  uint distributed_rewards_off;
  uint active_off;
};
typedef struct fd_sysvar_epoch_rewards_off fd_sysvar_epoch_rewards_off_t;
#define FD_SYSVAR_EPOCH_REWARDS_OFF_FOOTPRINT sizeof(fd_sysvar_epoch_rewards_off_t)
#define FD_SYSVAR_EPOCH_REWARDS_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (33 bytes) */
struct __attribute__((aligned(8UL))) fd_config_keys_pair {
  fd_pubkey_t key;
  uchar signer;
};
typedef struct fd_config_keys_pair fd_config_keys_pair_t;
#define FD_CONFIG_KEYS_PAIR_FOOTPRINT sizeof(fd_config_keys_pair_t)
#define FD_CONFIG_KEYS_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_config_keys_pair_off {
  uint key_off;
  uint signer_off;
};
typedef struct fd_config_keys_pair_off fd_config_keys_pair_off_t;
#define FD_CONFIG_KEYS_PAIR_OFF_FOOTPRINT sizeof(fd_config_keys_pair_off_t)
#define FD_CONFIG_KEYS_PAIR_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/config.rs#L14 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_config {
  ushort config_keys_len;
  fd_config_keys_pair_t * config_keys;
  double warmup_cooldown_rate;
  uchar slash_penalty;
};
typedef struct fd_stake_config fd_stake_config_t;
#define FD_STAKE_CONFIG_FOOTPRINT sizeof(fd_stake_config_t)
#define FD_STAKE_CONFIG_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_config_off {
  uint config_keys_off;
  uint warmup_cooldown_rate_off;
  uint slash_penalty_off;
};
typedef struct fd_stake_config_off fd_stake_config_off_t;
#define FD_STAKE_CONFIG_OFF_FOOTPRINT sizeof(fd_stake_config_off_t)
#define FD_STAKE_CONFIG_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_feature_entry {
  fd_pubkey_t pubkey;
  ulong description_len;
  uchar* description;
  ulong since_slot;
};
typedef struct fd_feature_entry fd_feature_entry_t;
#define FD_FEATURE_ENTRY_FOOTPRINT sizeof(fd_feature_entry_t)
#define FD_FEATURE_ENTRY_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_feature_entry_off {
  uint pubkey_off;
  uint description_off;
  uint since_slot_off;
};
typedef struct fd_feature_entry_off fd_feature_entry_off_t;
#define FD_FEATURE_ENTRY_OFF_FOOTPRINT sizeof(fd_feature_entry_off_t)
#define FD_FEATURE_ENTRY_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(16UL))) fd_firedancer_bank {
  fd_stakes_t stakes;
  fd_recent_block_hashes_t recent_block_hashes;
  fd_clock_timestamp_votes_t timestamp_votes;
  ulong slot;
  ulong prev_slot;
  fd_hash_t poh;
  fd_hash_t banks_hash;
  fd_fee_rate_governor_t fee_rate_governor;
  ulong capitalization;
  ulong block_height;
  ulong lamports_per_signature;
  ulong hashes_per_tick;
  ulong ticks_per_slot;
  uint128 ns_per_slot;
  ulong genesis_creation_time;
  double slots_per_year;
  ulong max_tick_height;
  fd_inflation_t inflation;
  fd_epoch_schedule_t epoch_schedule;
  fd_rent_t rent;
  ulong collected_fees;
  ulong collected_rent;
  fd_vote_accounts_t epoch_stakes;
  fd_sol_sysvar_last_restart_slot_t last_restart_slot;
};
typedef struct fd_firedancer_bank fd_firedancer_bank_t;
#define FD_FIREDANCER_BANK_FOOTPRINT sizeof(fd_firedancer_bank_t)
#define FD_FIREDANCER_BANK_ALIGN (16UL)

struct __attribute__((aligned(16UL))) fd_firedancer_bank_off {
  uint stakes_off;
  uint recent_block_hashes_off;
  uint timestamp_votes_off;
  uint slot_off;
  uint prev_slot_off;
  uint poh_off;
  uint banks_hash_off;
  uint fee_rate_governor_off;
  uint capitalization_off;
  uint block_height_off;
  uint lamports_per_signature_off;
  uint hashes_per_tick_off;
  uint ticks_per_slot_off;
  uint ns_per_slot_off;
  uint genesis_creation_time_off;
  uint slots_per_year_off;
  uint max_tick_height_off;
  uint inflation_off;
  uint epoch_schedule_off;
  uint rent_off;
  uint collected_fees_off;
  uint collected_rent_off;
  uint epoch_stakes_off;
  uint last_restart_slot_off;
};
typedef struct fd_firedancer_bank_off fd_firedancer_bank_off_t;
#define FD_FIREDANCER_BANK_OFF_FOOTPRINT sizeof(fd_firedancer_bank_off_t)
#define FD_FIREDANCER_BANK_OFF_ALIGN (16UL)

union fd_cluster_type_inner {
  uchar nonempty; /* Hack to support enums with no inner structures */ 
};
typedef union fd_cluster_type_inner fd_cluster_type_inner_t;

struct fd_cluster_type {
  uint discriminant;
  fd_cluster_type_inner_t inner;
};
typedef struct fd_cluster_type fd_cluster_type_t;
#define FD_CLUSTER_TYPE_FOOTPRINT sizeof(fd_cluster_type_t)
#define FD_CLUSTER_TYPE_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(16UL))) fd_epoch_bank {
  fd_stakes_t stakes;
  ulong hashes_per_tick;
  ulong ticks_per_slot;
  uint128 ns_per_slot;
  ulong genesis_creation_time;
  double slots_per_year;
  ulong max_tick_height;
  fd_inflation_t inflation;
  fd_epoch_schedule_t epoch_schedule;
  fd_rent_t rent;
  ulong eah_start_slot;
  ulong eah_stop_slot;
  ulong eah_interval;
  fd_hash_t genesis_hash;
  uint cluster_type;
  uint cluster_version[3];
  fd_vote_accounts_t next_epoch_stakes;
  fd_epoch_schedule_t rent_epoch_schedule;
};
typedef struct fd_epoch_bank fd_epoch_bank_t;
#define FD_EPOCH_BANK_FOOTPRINT sizeof(fd_epoch_bank_t)
#define FD_EPOCH_BANK_ALIGN (16UL)

struct __attribute__((aligned(16UL))) fd_epoch_bank_off {
  uint stakes_off;
  uint hashes_per_tick_off;
  uint ticks_per_slot_off;
  uint ns_per_slot_off;
  uint genesis_creation_time_off;
  uint slots_per_year_off;
  uint max_tick_height_off;
  uint inflation_off;
  uint epoch_schedule_off;
  uint rent_off;
  uint eah_start_slot_off;
  uint eah_stop_slot_off;
  uint eah_interval_off;
  uint genesis_hash_off;
  uint cluster_type_off;
  uint cluster_version_off;
  uint next_epoch_stakes_off;
  uint rent_epoch_schedule_off;
};
typedef struct fd_epoch_bank_off fd_epoch_bank_off_t;
#define FD_EPOCH_BANK_OFF_FOOTPRINT sizeof(fd_epoch_bank_off_t)
#define FD_EPOCH_BANK_OFF_ALIGN (16UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(128UL))) fd_slot_bank {
  fd_recent_block_hashes_t recent_block_hashes;
  fd_clock_timestamp_votes_t timestamp_votes;
  ulong slot;
  ulong prev_slot;
  fd_hash_t poh;
  fd_hash_t banks_hash;
  fd_hash_t epoch_account_hash;
  fd_fee_rate_governor_t fee_rate_governor;
  ulong capitalization;
  ulong block_height;
  ulong max_tick_height;
  ulong collected_execution_fees;
  ulong collected_priority_fees;
  ulong collected_rent;
  fd_vote_accounts_t epoch_stakes;
  fd_sol_sysvar_last_restart_slot_t last_restart_slot;
  fd_stake_accounts_t stake_account_keys;
  fd_vote_accounts_t vote_account_keys;
  ulong lamports_per_signature;
  ulong transaction_count;
  fd_slot_lthash_t lthash;
  fd_block_hash_queue_t block_hash_queue;
  ulong use_preceeding_epoch_stakes;
  uchar has_use_preceeding_epoch_stakes;
};
typedef struct fd_slot_bank fd_slot_bank_t;
#define FD_SLOT_BANK_FOOTPRINT sizeof(fd_slot_bank_t)
#define FD_SLOT_BANK_ALIGN (128UL)

struct __attribute__((aligned(128UL))) fd_slot_bank_off {
  uint recent_block_hashes_off;
  uint timestamp_votes_off;
  uint slot_off;
  uint prev_slot_off;
  uint poh_off;
  uint banks_hash_off;
  uint epoch_account_hash_off;
  uint fee_rate_governor_off;
  uint capitalization_off;
  uint block_height_off;
  uint max_tick_height_off;
  uint collected_execution_fees_off;
  uint collected_priority_fees_off;
  uint collected_rent_off;
  uint epoch_stakes_off;
  uint last_restart_slot_off;
  uint stake_account_keys_off;
  uint vote_account_keys_off;
  uint lamports_per_signature_off;
  uint transaction_count_off;
  uint lthash_off;
  uint block_hash_queue_off;
  uint use_preceeding_epoch_stakes_off;
};
typedef struct fd_slot_bank_off fd_slot_bank_off_t;
#define FD_SLOT_BANK_OFF_FOOTPRINT sizeof(fd_slot_bank_off_t)
#define FD_SLOT_BANK_OFF_ALIGN (128UL)

/* Encoded Size: Fixed (32 bytes) */
struct __attribute__((aligned(8UL))) fd_prev_epoch_inflation_rewards {
  ulong validator_rewards;
  double prev_epoch_duration_in_years;
  double validator_rate;
  double foundation_rate;
};
typedef struct fd_prev_epoch_inflation_rewards fd_prev_epoch_inflation_rewards_t;
#define FD_PREV_EPOCH_INFLATION_REWARDS_FOOTPRINT sizeof(fd_prev_epoch_inflation_rewards_t)
#define FD_PREV_EPOCH_INFLATION_REWARDS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_prev_epoch_inflation_rewards_off {
  uint validator_rewards_off;
  uint prev_epoch_duration_in_years_off;
  uint validator_rate_off;
  uint foundation_rate_off;
};
typedef struct fd_prev_epoch_inflation_rewards_off fd_prev_epoch_inflation_rewards_off_t;
#define FD_PREV_EPOCH_INFLATION_REWARDS_OFF_FOOTPRINT sizeof(fd_prev_epoch_inflation_rewards_off_t)
#define FD_PREV_EPOCH_INFLATION_REWARDS_OFF_ALIGN (8UL)

#define DEQUE_NAME deq_ulong
#define DEQUE_T ulong
#include "../../util/tmpl/fd_deque_dynamic.c"
#undef DEQUE_NAME
#undef DEQUE_T
#undef DEQUE_MAX
static inline ulong *
deq_ulong_alloc( fd_valloc_t valloc, ulong max ) {
  if( FD_UNLIKELY( 0 == max ) ) max = 1; // prevent underflow
  void * mem = fd_valloc_malloc( valloc, deq_ulong_align(), deq_ulong_footprint( max ) );
  return deq_ulong_join( deq_ulong_new( mem, max ) );
}
/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L133 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote {
  ulong * slots; /* fd_deque_dynamic */
  fd_hash_t hash;
  long* timestamp;
};
typedef struct fd_vote fd_vote_t;
#define FD_VOTE_FOOTPRINT sizeof(fd_vote_t)
#define FD_VOTE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_off {
  uint slots_off;
  uint hash_off;
  uint timestamp_off;
};
typedef struct fd_vote_off fd_vote_off_t;
#define FD_VOTE_OFF_FOOTPRINT sizeof(fd_vote_off_t)
#define FD_VOTE_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L230 */
/* Encoded Size: Fixed (97 bytes) */
struct __attribute__((aligned(8UL))) fd_vote_init {
  fd_pubkey_t node_pubkey;
  fd_pubkey_t authorized_voter;
  fd_pubkey_t authorized_withdrawer;
  uchar commission;
};
typedef struct fd_vote_init fd_vote_init_t;
#define FD_VOTE_INIT_FOOTPRINT sizeof(fd_vote_init_t)
#define FD_VOTE_INIT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_init_off {
  uint node_pubkey_off;
  uint authorized_voter_off;
  uint authorized_withdrawer_off;
  uint commission_off;
};
typedef struct fd_vote_init_off fd_vote_init_off_t;
#define FD_VOTE_INIT_OFF_FOOTPRINT sizeof(fd_vote_init_off_t)
#define FD_VOTE_INIT_OFF_ALIGN (8UL)

union fd_vote_authorize_inner {
  uchar nonempty; /* Hack to support enums with no inner structures */ 
};
typedef union fd_vote_authorize_inner fd_vote_authorize_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L238 */
struct fd_vote_authorize {
  uint discriminant;
  fd_vote_authorize_inner_t inner;
};
typedef struct fd_vote_authorize fd_vote_authorize_t;
#define FD_VOTE_AUTHORIZE_FOOTPRINT sizeof(fd_vote_authorize_t)
#define FD_VOTE_AUTHORIZE_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_instruction.rs#L37 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_authorize_pubkey {
  fd_pubkey_t pubkey;
  fd_vote_authorize_t vote_authorize;
};
typedef struct fd_vote_authorize_pubkey fd_vote_authorize_pubkey_t;
#define FD_VOTE_AUTHORIZE_PUBKEY_FOOTPRINT sizeof(fd_vote_authorize_pubkey_t)
#define FD_VOTE_AUTHORIZE_PUBKEY_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_authorize_pubkey_off {
  uint pubkey_off;
  uint vote_authorize_off;
};
typedef struct fd_vote_authorize_pubkey_off fd_vote_authorize_pubkey_off_t;
#define FD_VOTE_AUTHORIZE_PUBKEY_OFF_FOOTPRINT sizeof(fd_vote_authorize_pubkey_off_t)
#define FD_VOTE_AUTHORIZE_PUBKEY_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_instruction.rs#L78 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_switch {
  fd_vote_t vote;
  fd_hash_t hash;
};
typedef struct fd_vote_switch fd_vote_switch_t;
#define FD_VOTE_SWITCH_FOOTPRINT sizeof(fd_vote_switch_t)
#define FD_VOTE_SWITCH_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_switch_off {
  uint vote_off;
  uint hash_off;
};
typedef struct fd_vote_switch_off fd_vote_switch_off_t;
#define FD_VOTE_SWITCH_OFF_FOOTPRINT sizeof(fd_vote_switch_off_t)
#define FD_VOTE_SWITCH_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_instruction.rs#L104 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_update_vote_state_switch {
  fd_vote_state_update_t vote_state_update;
  fd_hash_t hash;
};
typedef struct fd_update_vote_state_switch fd_update_vote_state_switch_t;
#define FD_UPDATE_VOTE_STATE_SWITCH_FOOTPRINT sizeof(fd_update_vote_state_switch_t)
#define FD_UPDATE_VOTE_STATE_SWITCH_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_update_vote_state_switch_off {
  uint vote_state_update_off;
  uint hash_off;
};
typedef struct fd_update_vote_state_switch_off fd_update_vote_state_switch_off_t;
#define FD_UPDATE_VOTE_STATE_SWITCH_OFF_FOOTPRINT sizeof(fd_update_vote_state_switch_off_t)
#define FD_UPDATE_VOTE_STATE_SWITCH_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L244 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_authorize_with_seed_args {
  fd_vote_authorize_t authorization_type;
  fd_pubkey_t current_authority_derived_key_owner;
  ulong current_authority_derived_key_seed_len;
  uchar* current_authority_derived_key_seed;
  fd_pubkey_t new_authority;
};
typedef struct fd_vote_authorize_with_seed_args fd_vote_authorize_with_seed_args_t;
#define FD_VOTE_AUTHORIZE_WITH_SEED_ARGS_FOOTPRINT sizeof(fd_vote_authorize_with_seed_args_t)
#define FD_VOTE_AUTHORIZE_WITH_SEED_ARGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_authorize_with_seed_args_off {
  uint authorization_type_off;
  uint current_authority_derived_key_owner_off;
  uint current_authority_derived_key_seed_off;
  uint new_authority_off;
};
typedef struct fd_vote_authorize_with_seed_args_off fd_vote_authorize_with_seed_args_off_t;
#define FD_VOTE_AUTHORIZE_WITH_SEED_ARGS_OFF_FOOTPRINT sizeof(fd_vote_authorize_with_seed_args_off_t)
#define FD_VOTE_AUTHORIZE_WITH_SEED_ARGS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/programs/vote/src/vote_state/mod.rs#L252 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_vote_authorize_checked_with_seed_args {
  fd_vote_authorize_t authorization_type;
  fd_pubkey_t current_authority_derived_key_owner;
  ulong current_authority_derived_key_seed_len;
  uchar* current_authority_derived_key_seed;
};
typedef struct fd_vote_authorize_checked_with_seed_args fd_vote_authorize_checked_with_seed_args_t;
#define FD_VOTE_AUTHORIZE_CHECKED_WITH_SEED_ARGS_FOOTPRINT sizeof(fd_vote_authorize_checked_with_seed_args_t)
#define FD_VOTE_AUTHORIZE_CHECKED_WITH_SEED_ARGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_vote_authorize_checked_with_seed_args_off {
  uint authorization_type_off;
  uint current_authority_derived_key_owner_off;
  uint current_authority_derived_key_seed_off;
};
typedef struct fd_vote_authorize_checked_with_seed_args_off fd_vote_authorize_checked_with_seed_args_off_t;
#define FD_VOTE_AUTHORIZE_CHECKED_WITH_SEED_ARGS_OFF_FOOTPRINT sizeof(fd_vote_authorize_checked_with_seed_args_off_t)
#define FD_VOTE_AUTHORIZE_CHECKED_WITH_SEED_ARGS_OFF_ALIGN (8UL)

union fd_vote_instruction_inner {
  fd_vote_init_t initialize_account;
  fd_vote_authorize_pubkey_t authorize;
  fd_vote_t vote;
  ulong withdraw;
  uchar update_commission;
  fd_vote_switch_t vote_switch;
  fd_vote_authorize_t authorize_checked;
  fd_vote_state_update_t update_vote_state;
  fd_update_vote_state_switch_t update_vote_state_switch;
  fd_vote_authorize_with_seed_args_t authorize_with_seed;
  fd_vote_authorize_checked_with_seed_args_t authorize_checked_with_seed;
  fd_compact_vote_state_update_t compact_update_vote_state;
  fd_compact_vote_state_update_switch_t compact_update_vote_state_switch;
  fd_tower_sync_t tower_sync;
  fd_tower_sync_switch_t tower_sync_switch;
};
typedef union fd_vote_instruction_inner fd_vote_instruction_inner_t;

/* https://github.com/firedancer-io/solana/blob/53a4e5d6c58b2ffe89b09304e4437f8ca198dadd/programs/vote/src/vote_instruction.rs#L21 */
struct fd_vote_instruction {
  uint discriminant;
  fd_vote_instruction_inner_t inner;
};
typedef struct fd_vote_instruction fd_vote_instruction_t;
#define FD_VOTE_INSTRUCTION_FOOTPRINT sizeof(fd_vote_instruction_t)
#define FD_VOTE_INSTRUCTION_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/system_instruction.rs#L158 */
/* Encoded Size: Fixed (48 bytes) */
struct __attribute__((aligned(8UL))) fd_system_program_instruction_create_account {
  ulong lamports;
  ulong space;
  fd_pubkey_t owner;
};
typedef struct fd_system_program_instruction_create_account fd_system_program_instruction_create_account_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_FOOTPRINT sizeof(fd_system_program_instruction_create_account_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_system_program_instruction_create_account_off {
  uint lamports_off;
  uint space_off;
  uint owner_off;
};
typedef struct fd_system_program_instruction_create_account_off fd_system_program_instruction_create_account_off_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_OFF_FOOTPRINT sizeof(fd_system_program_instruction_create_account_off_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/system_instruction.rs#L193 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_system_program_instruction_create_account_with_seed {
  fd_pubkey_t base;
  ulong seed_len;
  uchar* seed;
  ulong lamports;
  ulong space;
  fd_pubkey_t owner;
};
typedef struct fd_system_program_instruction_create_account_with_seed fd_system_program_instruction_create_account_with_seed_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_WITH_SEED_FOOTPRINT sizeof(fd_system_program_instruction_create_account_with_seed_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_WITH_SEED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_system_program_instruction_create_account_with_seed_off {
  uint base_off;
  uint seed_off;
  uint lamports_off;
  uint space_off;
  uint owner_off;
};
typedef struct fd_system_program_instruction_create_account_with_seed_off fd_system_program_instruction_create_account_with_seed_off_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_WITH_SEED_OFF_FOOTPRINT sizeof(fd_system_program_instruction_create_account_with_seed_off_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_CREATE_ACCOUNT_WITH_SEED_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/system_instruction.rs#L269 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_system_program_instruction_allocate_with_seed {
  fd_pubkey_t base;
  ulong seed_len;
  uchar* seed;
  ulong space;
  fd_pubkey_t owner;
};
typedef struct fd_system_program_instruction_allocate_with_seed fd_system_program_instruction_allocate_with_seed_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ALLOCATE_WITH_SEED_FOOTPRINT sizeof(fd_system_program_instruction_allocate_with_seed_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ALLOCATE_WITH_SEED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_system_program_instruction_allocate_with_seed_off {
  uint base_off;
  uint seed_off;
  uint space_off;
  uint owner_off;
};
typedef struct fd_system_program_instruction_allocate_with_seed_off fd_system_program_instruction_allocate_with_seed_off_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ALLOCATE_WITH_SEED_OFF_FOOTPRINT sizeof(fd_system_program_instruction_allocate_with_seed_off_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ALLOCATE_WITH_SEED_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/system_instruction.rs#L288 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_system_program_instruction_assign_with_seed {
  fd_pubkey_t base;
  ulong seed_len;
  uchar* seed;
  fd_pubkey_t owner;
};
typedef struct fd_system_program_instruction_assign_with_seed fd_system_program_instruction_assign_with_seed_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ASSIGN_WITH_SEED_FOOTPRINT sizeof(fd_system_program_instruction_assign_with_seed_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ASSIGN_WITH_SEED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_system_program_instruction_assign_with_seed_off {
  uint base_off;
  uint seed_off;
  uint owner_off;
};
typedef struct fd_system_program_instruction_assign_with_seed_off fd_system_program_instruction_assign_with_seed_off_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ASSIGN_WITH_SEED_OFF_FOOTPRINT sizeof(fd_system_program_instruction_assign_with_seed_off_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ASSIGN_WITH_SEED_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/system_instruction.rs#L288 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_system_program_instruction_transfer_with_seed {
  ulong lamports;
  ulong from_seed_len;
  uchar* from_seed;
  fd_pubkey_t from_owner;
};
typedef struct fd_system_program_instruction_transfer_with_seed fd_system_program_instruction_transfer_with_seed_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_TRANSFER_WITH_SEED_FOOTPRINT sizeof(fd_system_program_instruction_transfer_with_seed_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_TRANSFER_WITH_SEED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_system_program_instruction_transfer_with_seed_off {
  uint lamports_off;
  uint from_seed_off;
  uint from_owner_off;
};
typedef struct fd_system_program_instruction_transfer_with_seed_off fd_system_program_instruction_transfer_with_seed_off_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_TRANSFER_WITH_SEED_OFF_FOOTPRINT sizeof(fd_system_program_instruction_transfer_with_seed_off_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_TRANSFER_WITH_SEED_OFF_ALIGN (8UL)

union fd_system_program_instruction_inner {
  fd_system_program_instruction_create_account_t create_account;
  fd_pubkey_t assign;
  ulong transfer;
  fd_system_program_instruction_create_account_with_seed_t create_account_with_seed;
  ulong withdraw_nonce_account;
  fd_pubkey_t initialize_nonce_account;
  fd_pubkey_t authorize_nonce_account;
  ulong allocate;
  fd_system_program_instruction_allocate_with_seed_t allocate_with_seed;
  fd_system_program_instruction_assign_with_seed_t assign_with_seed;
  fd_system_program_instruction_transfer_with_seed_t transfer_with_seed;
};
typedef union fd_system_program_instruction_inner fd_system_program_instruction_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/system_instruction.rs#L152 */
struct fd_system_program_instruction {
  uint discriminant;
  fd_system_program_instruction_inner_t inner;
};
typedef struct fd_system_program_instruction fd_system_program_instruction_t;
#define FD_SYSTEM_PROGRAM_INSTRUCTION_FOOTPRINT sizeof(fd_system_program_instruction_t)
#define FD_SYSTEM_PROGRAM_INSTRUCTION_ALIGN (8UL)

union fd_system_error_inner {
  uchar nonempty; /* Hack to support enums with no inner structures */ 
};
typedef union fd_system_error_inner fd_system_error_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/system_instruction.rs#L16 */
struct fd_system_error {
  uint discriminant;
  fd_system_error_inner_t inner;
};
typedef struct fd_system_error fd_system_error_t;
#define FD_SYSTEM_ERROR_FOOTPRINT sizeof(fd_system_error_t)
#define FD_SYSTEM_ERROR_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/state.rs#L169 */
/* Encoded Size: Fixed (64 bytes) */
struct __attribute__((aligned(8UL))) fd_stake_authorized {
  fd_pubkey_t staker;
  fd_pubkey_t withdrawer;
};
typedef struct fd_stake_authorized fd_stake_authorized_t;
#define FD_STAKE_AUTHORIZED_FOOTPRINT sizeof(fd_stake_authorized_t)
#define FD_STAKE_AUTHORIZED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_authorized_off {
  uint staker_off;
  uint withdrawer_off;
};
typedef struct fd_stake_authorized_off fd_stake_authorized_off_t;
#define FD_STAKE_AUTHORIZED_OFF_FOOTPRINT sizeof(fd_stake_authorized_off_t)
#define FD_STAKE_AUTHORIZED_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/state.rs#L135 */
/* Encoded Size: Fixed (48 bytes) */
struct __attribute__((aligned(8UL))) fd_stake_lockup {
  long unix_timestamp;
  ulong epoch;
  fd_pubkey_t custodian;
};
typedef struct fd_stake_lockup fd_stake_lockup_t;
#define FD_STAKE_LOCKUP_FOOTPRINT sizeof(fd_stake_lockup_t)
#define FD_STAKE_LOCKUP_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_lockup_off {
  uint unix_timestamp_off;
  uint epoch_off;
  uint custodian_off;
};
typedef struct fd_stake_lockup_off fd_stake_lockup_off_t;
#define FD_STAKE_LOCKUP_OFF_FOOTPRINT sizeof(fd_stake_lockup_off_t)
#define FD_STAKE_LOCKUP_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/instruction.rs#L68 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_instruction_initialize {
  fd_stake_authorized_t authorized;
  fd_stake_lockup_t lockup;
};
typedef struct fd_stake_instruction_initialize fd_stake_instruction_initialize_t;
#define FD_STAKE_INSTRUCTION_INITIALIZE_FOOTPRINT sizeof(fd_stake_instruction_initialize_t)
#define FD_STAKE_INSTRUCTION_INITIALIZE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_instruction_initialize_off {
  uint authorized_off;
  uint lockup_off;
};
typedef struct fd_stake_instruction_initialize_off fd_stake_instruction_initialize_off_t;
#define FD_STAKE_INSTRUCTION_INITIALIZE_OFF_FOOTPRINT sizeof(fd_stake_instruction_initialize_off_t)
#define FD_STAKE_INSTRUCTION_INITIALIZE_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/instruction.rs#L78 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_lockup_custodian_args {
  fd_stake_lockup_t lockup;
  fd_sol_sysvar_clock_t clock;
  fd_pubkey_t * custodian;
};
typedef struct fd_stake_lockup_custodian_args fd_stake_lockup_custodian_args_t;
#define FD_STAKE_LOCKUP_CUSTODIAN_ARGS_FOOTPRINT sizeof(fd_stake_lockup_custodian_args_t)
#define FD_STAKE_LOCKUP_CUSTODIAN_ARGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_lockup_custodian_args_off {
  uint lockup_off;
  uint clock_off;
  uint custodian_off;
};
typedef struct fd_stake_lockup_custodian_args_off fd_stake_lockup_custodian_args_off_t;
#define FD_STAKE_LOCKUP_CUSTODIAN_ARGS_OFF_FOOTPRINT sizeof(fd_stake_lockup_custodian_args_off_t)
#define FD_STAKE_LOCKUP_CUSTODIAN_ARGS_OFF_ALIGN (8UL)

union fd_stake_authorize_inner {
  uchar nonempty; /* Hack to support enums with no inner structures */ 
};
typedef union fd_stake_authorize_inner fd_stake_authorize_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/state.rs#L117 */
struct fd_stake_authorize {
  uint discriminant;
  fd_stake_authorize_inner_t inner;
};
typedef struct fd_stake_authorize fd_stake_authorize_t;
#define FD_STAKE_AUTHORIZE_FOOTPRINT sizeof(fd_stake_authorize_t)
#define FD_STAKE_AUTHORIZE_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/instruction.rs#L78 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_instruction_authorize {
  fd_pubkey_t pubkey;
  fd_stake_authorize_t stake_authorize;
};
typedef struct fd_stake_instruction_authorize fd_stake_instruction_authorize_t;
#define FD_STAKE_INSTRUCTION_AUTHORIZE_FOOTPRINT sizeof(fd_stake_instruction_authorize_t)
#define FD_STAKE_INSTRUCTION_AUTHORIZE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_instruction_authorize_off {
  uint pubkey_off;
  uint stake_authorize_off;
};
typedef struct fd_stake_instruction_authorize_off fd_stake_instruction_authorize_off_t;
#define FD_STAKE_INSTRUCTION_AUTHORIZE_OFF_FOOTPRINT sizeof(fd_stake_instruction_authorize_off_t)
#define FD_STAKE_INSTRUCTION_AUTHORIZE_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/instruction.rs#L241 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_authorize_with_seed_args {
  fd_pubkey_t new_authorized_pubkey;
  fd_stake_authorize_t stake_authorize;
  ulong authority_seed_len;
  uchar* authority_seed;
  fd_pubkey_t authority_owner;
};
typedef struct fd_authorize_with_seed_args fd_authorize_with_seed_args_t;
#define FD_AUTHORIZE_WITH_SEED_ARGS_FOOTPRINT sizeof(fd_authorize_with_seed_args_t)
#define FD_AUTHORIZE_WITH_SEED_ARGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_authorize_with_seed_args_off {
  uint new_authorized_pubkey_off;
  uint stake_authorize_off;
  uint authority_seed_off;
  uint authority_owner_off;
};
typedef struct fd_authorize_with_seed_args_off fd_authorize_with_seed_args_off_t;
#define FD_AUTHORIZE_WITH_SEED_ARGS_OFF_FOOTPRINT sizeof(fd_authorize_with_seed_args_off_t)
#define FD_AUTHORIZE_WITH_SEED_ARGS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/instruction.rs#L249 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_authorize_checked_with_seed_args {
  fd_stake_authorize_t stake_authorize;
  ulong authority_seed_len;
  uchar* authority_seed;
  fd_pubkey_t authority_owner;
};
typedef struct fd_authorize_checked_with_seed_args fd_authorize_checked_with_seed_args_t;
#define FD_AUTHORIZE_CHECKED_WITH_SEED_ARGS_FOOTPRINT sizeof(fd_authorize_checked_with_seed_args_t)
#define FD_AUTHORIZE_CHECKED_WITH_SEED_ARGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_authorize_checked_with_seed_args_off {
  uint stake_authorize_off;
  uint authority_seed_off;
  uint authority_owner_off;
};
typedef struct fd_authorize_checked_with_seed_args_off fd_authorize_checked_with_seed_args_off_t;
#define FD_AUTHORIZE_CHECKED_WITH_SEED_ARGS_OFF_FOOTPRINT sizeof(fd_authorize_checked_with_seed_args_off_t)
#define FD_AUTHORIZE_CHECKED_WITH_SEED_ARGS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/instruction.rs#L235 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_lockup_checked_args {
  long* unix_timestamp;
  ulong* epoch;
};
typedef struct fd_lockup_checked_args fd_lockup_checked_args_t;
#define FD_LOCKUP_CHECKED_ARGS_FOOTPRINT sizeof(fd_lockup_checked_args_t)
#define FD_LOCKUP_CHECKED_ARGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_lockup_checked_args_off {
  uint unix_timestamp_off;
  uint epoch_off;
};
typedef struct fd_lockup_checked_args_off fd_lockup_checked_args_off_t;
#define FD_LOCKUP_CHECKED_ARGS_OFF_FOOTPRINT sizeof(fd_lockup_checked_args_off_t)
#define FD_LOCKUP_CHECKED_ARGS_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/instruction.rs#L228 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_lockup_args {
  long* unix_timestamp;
  ulong* epoch;
  fd_pubkey_t * custodian;
};
typedef struct fd_lockup_args fd_lockup_args_t;
#define FD_LOCKUP_ARGS_FOOTPRINT sizeof(fd_lockup_args_t)
#define FD_LOCKUP_ARGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_lockup_args_off {
  uint unix_timestamp_off;
  uint epoch_off;
  uint custodian_off;
};
typedef struct fd_lockup_args_off fd_lockup_args_off_t;
#define FD_LOCKUP_ARGS_OFF_FOOTPRINT sizeof(fd_lockup_args_off_t)
#define FD_LOCKUP_ARGS_OFF_ALIGN (8UL)

union fd_stake_instruction_inner {
  fd_stake_instruction_initialize_t initialize;
  fd_stake_instruction_authorize_t authorize;
  ulong split;
  ulong withdraw;
  fd_lockup_args_t set_lockup;
  fd_authorize_with_seed_args_t authorize_with_seed;
  fd_stake_authorize_t authorize_checked;
  fd_authorize_checked_with_seed_args_t authorize_checked_with_seed;
  fd_lockup_checked_args_t set_lockup_checked;
  ulong move_stake;
  ulong move_lamports;
};
typedef union fd_stake_instruction_inner fd_stake_instruction_inner_t;

/* https://github.com/anza-xyz/agave/blob/cdff19c7807b006dd63429114fb1d9573bf74172/sdk/program/src/stake/instruction.rs#L96 */
struct fd_stake_instruction {
  uint discriminant;
  fd_stake_instruction_inner_t inner;
};
typedef struct fd_stake_instruction fd_stake_instruction_t;
#define FD_STAKE_INSTRUCTION_FOOTPRINT sizeof(fd_stake_instruction_t)
#define FD_STAKE_INSTRUCTION_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/stake/state.rs#L248 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_meta {
  ulong rent_exempt_reserve;
  fd_stake_authorized_t authorized;
  fd_stake_lockup_t lockup;
};
typedef struct fd_stake_meta fd_stake_meta_t;
#define FD_STAKE_META_FOOTPRINT sizeof(fd_stake_meta_t)
#define FD_STAKE_META_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_meta_off {
  uint rent_exempt_reserve_off;
  uint authorized_off;
  uint lockup_off;
};
typedef struct fd_stake_meta_off fd_stake_meta_off_t;
#define FD_STAKE_META_OFF_FOOTPRINT sizeof(fd_stake_meta_off_t)
#define FD_STAKE_META_OFF_ALIGN (8UL)

/* https://github.com/firedancer-io/solana/blob/v1.17/sdk/program/src/stake/stake_flags.rs#L21 */
/* Encoded Size: Fixed (1 bytes) */
struct __attribute__((aligned(8UL))) fd_stake_flags {
  uchar bits;
};
typedef struct fd_stake_flags fd_stake_flags_t;
#define FD_STAKE_FLAGS_FOOTPRINT sizeof(fd_stake_flags_t)
#define FD_STAKE_FLAGS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_flags_off {
  uint bits_off;
};
typedef struct fd_stake_flags_off fd_stake_flags_off_t;
#define FD_STAKE_FLAGS_OFF_FOOTPRINT sizeof(fd_stake_flags_off_t)
#define FD_STAKE_FLAGS_OFF_ALIGN (8UL)

/* https://github.com/firedancer-io/solana/blob/v1.17/sdk/program/src/stake/state.rs#L135 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_state_v2_initialized {
  fd_stake_meta_t meta;
};
typedef struct fd_stake_state_v2_initialized fd_stake_state_v2_initialized_t;
#define FD_STAKE_STATE_V2_INITIALIZED_FOOTPRINT sizeof(fd_stake_state_v2_initialized_t)
#define FD_STAKE_STATE_V2_INITIALIZED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_state_v2_initialized_off {
  uint meta_off;
};
typedef struct fd_stake_state_v2_initialized_off fd_stake_state_v2_initialized_off_t;
#define FD_STAKE_STATE_V2_INITIALIZED_OFF_FOOTPRINT sizeof(fd_stake_state_v2_initialized_off_t)
#define FD_STAKE_STATE_V2_INITIALIZED_OFF_ALIGN (8UL)

/* https://github.com/firedancer-io/solana/blob/v1.17/sdk/program/src/stake/state.rs#L136 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_stake_state_v2_stake {
  fd_stake_meta_t meta;
  fd_stake_t stake;
  fd_stake_flags_t stake_flags;
};
typedef struct fd_stake_state_v2_stake fd_stake_state_v2_stake_t;
#define FD_STAKE_STATE_V2_STAKE_FOOTPRINT sizeof(fd_stake_state_v2_stake_t)
#define FD_STAKE_STATE_V2_STAKE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_stake_state_v2_stake_off {
  uint meta_off;
  uint stake_off;
  uint stake_flags_off;
};
typedef struct fd_stake_state_v2_stake_off fd_stake_state_v2_stake_off_t;
#define FD_STAKE_STATE_V2_STAKE_OFF_FOOTPRINT sizeof(fd_stake_state_v2_stake_off_t)
#define FD_STAKE_STATE_V2_STAKE_OFF_ALIGN (8UL)

union fd_stake_state_v2_inner {
  fd_stake_state_v2_initialized_t initialized;
  fd_stake_state_v2_stake_t stake;
};
typedef union fd_stake_state_v2_inner fd_stake_state_v2_inner_t;

/* https://github.com/firedancer-io/solana/blob/v1.17/sdk/program/src/stake/state.rs#L132 */
struct fd_stake_state_v2 {
  uint discriminant;
  fd_stake_state_v2_inner_t inner;
};
typedef struct fd_stake_state_v2 fd_stake_state_v2_t;
#define FD_STAKE_STATE_V2_FOOTPRINT sizeof(fd_stake_state_v2_t)
#define FD_STAKE_STATE_V2_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/nonce/state/current.rs#L17 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_nonce_data {
  fd_pubkey_t authority;
  fd_hash_t durable_nonce;
  fd_fee_calculator_t fee_calculator;
};
typedef struct fd_nonce_data fd_nonce_data_t;
#define FD_NONCE_DATA_FOOTPRINT sizeof(fd_nonce_data_t)
#define FD_NONCE_DATA_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_nonce_data_off {
  uint authority_off;
  uint durable_nonce_off;
  uint fee_calculator_off;
};
typedef struct fd_nonce_data_off fd_nonce_data_off_t;
#define FD_NONCE_DATA_OFF_FOOTPRINT sizeof(fd_nonce_data_off_t)
#define FD_NONCE_DATA_OFF_ALIGN (8UL)

union fd_nonce_state_inner {
  fd_nonce_data_t initialized;
};
typedef union fd_nonce_state_inner fd_nonce_state_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/nonce/state/current.rs#L65 */
struct fd_nonce_state {
  uint discriminant;
  fd_nonce_state_inner_t inner;
};
typedef struct fd_nonce_state fd_nonce_state_t;
#define FD_NONCE_STATE_FOOTPRINT sizeof(fd_nonce_state_t)
#define FD_NONCE_STATE_ALIGN (8UL)

union fd_nonce_state_versions_inner {
  fd_nonce_state_t legacy;
  fd_nonce_state_t current;
};
typedef union fd_nonce_state_versions_inner fd_nonce_state_versions_inner_t;

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/nonce/state/mod.rs#L9 */
struct fd_nonce_state_versions {
  uint discriminant;
  fd_nonce_state_versions_inner_t inner;
};
typedef struct fd_nonce_state_versions fd_nonce_state_versions_t;
#define FD_NONCE_STATE_VERSIONS_FOOTPRINT sizeof(fd_nonce_state_versions_t)
#define FD_NONCE_STATE_VERSIONS_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/6c520396cd76807f6227a7973f7373b37894251c/sdk/src/compute_budget.rs#L28 */
/* Encoded Size: Fixed (8 bytes) */
struct __attribute__((aligned(8UL))) fd_compute_budget_program_instruction_request_units_deprecated {
  uint units;
  uint additional_fee;
};
typedef struct fd_compute_budget_program_instruction_request_units_deprecated fd_compute_budget_program_instruction_request_units_deprecated_t;
#define FD_COMPUTE_BUDGET_PROGRAM_INSTRUCTION_REQUEST_UNITS_DEPRECATED_FOOTPRINT sizeof(fd_compute_budget_program_instruction_request_units_deprecated_t)
#define FD_COMPUTE_BUDGET_PROGRAM_INSTRUCTION_REQUEST_UNITS_DEPRECATED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_compute_budget_program_instruction_request_units_deprecated_off {
  uint units_off;
  uint additional_fee_off;
};
typedef struct fd_compute_budget_program_instruction_request_units_deprecated_off fd_compute_budget_program_instruction_request_units_deprecated_off_t;
#define FD_COMPUTE_BUDGET_PROGRAM_INSTRUCTION_REQUEST_UNITS_DEPRECATED_OFF_FOOTPRINT sizeof(fd_compute_budget_program_instruction_request_units_deprecated_off_t)
#define FD_COMPUTE_BUDGET_PROGRAM_INSTRUCTION_REQUEST_UNITS_DEPRECATED_OFF_ALIGN (8UL)

union fd_compute_budget_program_instruction_inner {
  fd_compute_budget_program_instruction_request_units_deprecated_t request_units_deprecated;
  uint request_heap_frame;
  uint set_compute_unit_limit;
  ulong set_compute_unit_price;
  uint set_loaded_accounts_data_size_limit;
};
typedef union fd_compute_budget_program_instruction_inner fd_compute_budget_program_instruction_inner_t;

/* https://github.com/solana-labs/solana/blob/6c520396cd76807f6227a7973f7373b37894251c/sdk/src/compute_budget.rs#L25 */
struct fd_compute_budget_program_instruction {
  uint discriminant;
  fd_compute_budget_program_instruction_inner_t inner;
};
typedef struct fd_compute_budget_program_instruction fd_compute_budget_program_instruction_t;
#define FD_COMPUTE_BUDGET_PROGRAM_INSTRUCTION_FOOTPRINT sizeof(fd_compute_budget_program_instruction_t)
#define FD_COMPUTE_BUDGET_PROGRAM_INSTRUCTION_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/a03ae63daff987912c48ee286eb8ee7e8a84bf01/programs/config/src/lib.rs#L32 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_config_keys {
  ushort keys_len;
  fd_config_keys_pair_t * keys;
};
typedef struct fd_config_keys fd_config_keys_t;
#define FD_CONFIG_KEYS_FOOTPRINT sizeof(fd_config_keys_t)
#define FD_CONFIG_KEYS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_config_keys_off {
  uint keys_off;
};
typedef struct fd_config_keys_off fd_config_keys_off_t;
#define FD_CONFIG_KEYS_OFF_FOOTPRINT sizeof(fd_config_keys_off_t)
#define FD_CONFIG_KEYS_OFF_ALIGN (8UL)

/*  */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_bpf_loader_program_instruction_write {
  uint offset;
  ulong bytes_len;
  uchar* bytes;
};
typedef struct fd_bpf_loader_program_instruction_write fd_bpf_loader_program_instruction_write_t;
#define FD_BPF_LOADER_PROGRAM_INSTRUCTION_WRITE_FOOTPRINT sizeof(fd_bpf_loader_program_instruction_write_t)
#define FD_BPF_LOADER_PROGRAM_INSTRUCTION_WRITE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bpf_loader_program_instruction_write_off {
  uint offset_off;
  uint bytes_off;
};
typedef struct fd_bpf_loader_program_instruction_write_off fd_bpf_loader_program_instruction_write_off_t;
#define FD_BPF_LOADER_PROGRAM_INSTRUCTION_WRITE_OFF_FOOTPRINT sizeof(fd_bpf_loader_program_instruction_write_off_t)
#define FD_BPF_LOADER_PROGRAM_INSTRUCTION_WRITE_OFF_ALIGN (8UL)

union fd_bpf_loader_program_instruction_inner {
  fd_bpf_loader_program_instruction_write_t write;
};
typedef union fd_bpf_loader_program_instruction_inner fd_bpf_loader_program_instruction_inner_t;

/*  */
struct fd_bpf_loader_program_instruction {
  uint discriminant;
  fd_bpf_loader_program_instruction_inner_t inner;
};
typedef struct fd_bpf_loader_program_instruction fd_bpf_loader_program_instruction_t;
#define FD_BPF_LOADER_PROGRAM_INSTRUCTION_FOOTPRINT sizeof(fd_bpf_loader_program_instruction_t)
#define FD_BPF_LOADER_PROGRAM_INSTRUCTION_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/007194391ca8313b2854d523769d0bedf040ef92/sdk/program/src/loader_v4_instruction.rs#L11-L17 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_loader_v4_program_instruction_write {
  uint offset;
  ulong bytes_len;
  uchar* bytes;
};
typedef struct fd_loader_v4_program_instruction_write fd_loader_v4_program_instruction_write_t;
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_WRITE_FOOTPRINT sizeof(fd_loader_v4_program_instruction_write_t)
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_WRITE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_loader_v4_program_instruction_write_off {
  uint offset_off;
  uint bytes_off;
};
typedef struct fd_loader_v4_program_instruction_write_off fd_loader_v4_program_instruction_write_off_t;
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_WRITE_OFF_FOOTPRINT sizeof(fd_loader_v4_program_instruction_write_off_t)
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_WRITE_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/007194391ca8313b2854d523769d0bedf040ef92/sdk/program/src/loader_v4_instruction.rs#L33-L36 */
/* Encoded Size: Fixed (4 bytes) */
struct __attribute__((aligned(8UL))) fd_loader_v4_program_instruction_truncate {
  uint new_size;
};
typedef struct fd_loader_v4_program_instruction_truncate fd_loader_v4_program_instruction_truncate_t;
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_TRUNCATE_FOOTPRINT sizeof(fd_loader_v4_program_instruction_truncate_t)
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_TRUNCATE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_loader_v4_program_instruction_truncate_off {
  uint new_size_off;
};
typedef struct fd_loader_v4_program_instruction_truncate_off fd_loader_v4_program_instruction_truncate_off_t;
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_TRUNCATE_OFF_FOOTPRINT sizeof(fd_loader_v4_program_instruction_truncate_off_t)
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_TRUNCATE_OFF_ALIGN (8UL)

union fd_loader_v4_program_instruction_inner {
  fd_loader_v4_program_instruction_write_t write;
  fd_loader_v4_program_instruction_truncate_t truncate;
};
typedef union fd_loader_v4_program_instruction_inner fd_loader_v4_program_instruction_inner_t;

/* https://github.com/anza-xyz/agave/blob/007194391ca8313b2854d523769d0bedf040ef92/sdk/program/src/loader_v4_instruction.rs#L5 */
struct fd_loader_v4_program_instruction {
  uint discriminant;
  fd_loader_v4_program_instruction_inner_t inner;
};
typedef struct fd_loader_v4_program_instruction fd_loader_v4_program_instruction_t;
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_FOOTPRINT sizeof(fd_loader_v4_program_instruction_t)
#define FD_LOADER_V4_PROGRAM_INSTRUCTION_ALIGN (8UL)

/*  */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_program_instruction_write {
  uint offset;
  ulong bytes_len;
  uchar* bytes;
};
typedef struct fd_bpf_upgradeable_loader_program_instruction_write fd_bpf_upgradeable_loader_program_instruction_write_t;
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_WRITE_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_program_instruction_write_t)
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_WRITE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_program_instruction_write_off {
  uint offset_off;
  uint bytes_off;
};
typedef struct fd_bpf_upgradeable_loader_program_instruction_write_off fd_bpf_upgradeable_loader_program_instruction_write_off_t;
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_WRITE_OFF_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_program_instruction_write_off_t)
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_WRITE_OFF_ALIGN (8UL)

/*  */
/* Encoded Size: Fixed (8 bytes) */
struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len {
  ulong max_data_len;
};
typedef struct fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t;
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_DEPLOY_WITH_MAX_DATA_LEN_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t)
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_DEPLOY_WITH_MAX_DATA_LEN_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_off {
  uint max_data_len_off;
};
typedef struct fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_off fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_off_t;
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_DEPLOY_WITH_MAX_DATA_LEN_OFF_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_off_t)
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_DEPLOY_WITH_MAX_DATA_LEN_OFF_ALIGN (8UL)

/*  */
/* Encoded Size: Fixed (4 bytes) */
struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_program_instruction_extend_program {
  uint additional_bytes;
};
typedef struct fd_bpf_upgradeable_loader_program_instruction_extend_program fd_bpf_upgradeable_loader_program_instruction_extend_program_t;
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_EXTEND_PROGRAM_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_program_instruction_extend_program_t)
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_EXTEND_PROGRAM_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_program_instruction_extend_program_off {
  uint additional_bytes_off;
};
typedef struct fd_bpf_upgradeable_loader_program_instruction_extend_program_off fd_bpf_upgradeable_loader_program_instruction_extend_program_off_t;
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_EXTEND_PROGRAM_OFF_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_program_instruction_extend_program_off_t)
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_EXTEND_PROGRAM_OFF_ALIGN (8UL)

union fd_bpf_upgradeable_loader_program_instruction_inner {
  fd_bpf_upgradeable_loader_program_instruction_write_t write;
  fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t deploy_with_max_data_len;
  fd_bpf_upgradeable_loader_program_instruction_extend_program_t extend_program;
};
typedef union fd_bpf_upgradeable_loader_program_instruction_inner fd_bpf_upgradeable_loader_program_instruction_inner_t;

/*  */
struct fd_bpf_upgradeable_loader_program_instruction {
  uint discriminant;
  fd_bpf_upgradeable_loader_program_instruction_inner_t inner;
};
typedef struct fd_bpf_upgradeable_loader_program_instruction fd_bpf_upgradeable_loader_program_instruction_t;
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_program_instruction_t)
#define FD_BPF_UPGRADEABLE_LOADER_PROGRAM_INSTRUCTION_ALIGN (8UL)

/*  */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_state_buffer {
  fd_pubkey_t * authority_address;
};
typedef struct fd_bpf_upgradeable_loader_state_buffer fd_bpf_upgradeable_loader_state_buffer_t;
#define FD_BPF_UPGRADEABLE_LOADER_STATE_BUFFER_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_state_buffer_t)
#define FD_BPF_UPGRADEABLE_LOADER_STATE_BUFFER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_state_buffer_off {
  uint authority_address_off;
};
typedef struct fd_bpf_upgradeable_loader_state_buffer_off fd_bpf_upgradeable_loader_state_buffer_off_t;
#define FD_BPF_UPGRADEABLE_LOADER_STATE_BUFFER_OFF_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_state_buffer_off_t)
#define FD_BPF_UPGRADEABLE_LOADER_STATE_BUFFER_OFF_ALIGN (8UL)

/*  */
/* Encoded Size: Fixed (32 bytes) */
struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_state_program {
  fd_pubkey_t programdata_address;
};
typedef struct fd_bpf_upgradeable_loader_state_program fd_bpf_upgradeable_loader_state_program_t;
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_state_program_t)
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_state_program_off {
  uint programdata_address_off;
};
typedef struct fd_bpf_upgradeable_loader_state_program_off fd_bpf_upgradeable_loader_state_program_off_t;
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_OFF_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_state_program_off_t)
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_OFF_ALIGN (8UL)

/*  */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_state_program_data {
  ulong slot;
  fd_pubkey_t * upgrade_authority_address;
};
typedef struct fd_bpf_upgradeable_loader_state_program_data fd_bpf_upgradeable_loader_state_program_data_t;
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_DATA_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_state_program_data_t)
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_DATA_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bpf_upgradeable_loader_state_program_data_off {
  uint slot_off;
  uint upgrade_authority_address_off;
};
typedef struct fd_bpf_upgradeable_loader_state_program_data_off fd_bpf_upgradeable_loader_state_program_data_off_t;
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_DATA_OFF_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_state_program_data_off_t)
#define FD_BPF_UPGRADEABLE_LOADER_STATE_PROGRAM_DATA_OFF_ALIGN (8UL)

union fd_bpf_upgradeable_loader_state_inner {
  fd_bpf_upgradeable_loader_state_buffer_t buffer;
  fd_bpf_upgradeable_loader_state_program_t program;
  fd_bpf_upgradeable_loader_state_program_data_t program_data;
};
typedef union fd_bpf_upgradeable_loader_state_inner fd_bpf_upgradeable_loader_state_inner_t;

/*  */
struct fd_bpf_upgradeable_loader_state {
  uint discriminant;
  fd_bpf_upgradeable_loader_state_inner_t inner;
};
typedef struct fd_bpf_upgradeable_loader_state fd_bpf_upgradeable_loader_state_t;
#define FD_BPF_UPGRADEABLE_LOADER_STATE_FOOTPRINT sizeof(fd_bpf_upgradeable_loader_state_t)
#define FD_BPF_UPGRADEABLE_LOADER_STATE_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/v2.1.4/sdk/program/src/loader_v4.rs#L33-L43 */
/* Encoded Size: Fixed (48 bytes) */
struct __attribute__((aligned(8UL))) fd_loader_v4_state {
  ulong slot;
  fd_pubkey_t authority_address_or_next_version;
  ulong status;
};
typedef struct fd_loader_v4_state fd_loader_v4_state_t;
#define FD_LOADER_V4_STATE_FOOTPRINT sizeof(fd_loader_v4_state_t)
#define FD_LOADER_V4_STATE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_loader_v4_state_off {
  uint slot_off;
  uint authority_address_or_next_version_off;
  uint status_off;
};
typedef struct fd_loader_v4_state_off fd_loader_v4_state_off_t;
#define FD_LOADER_V4_STATE_OFF_FOOTPRINT sizeof(fd_loader_v4_state_off_t)
#define FD_LOADER_V4_STATE_OFF_ALIGN (8UL)

/* https://github.com/firedancer-io/solana/blob/f4b7c54f9e021b40cfc7cbd32dc12b19dedbe791/ledger/src/blockstore_meta.rs#L178 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_frozen_hash_status {
  fd_hash_t frozen_hash;
  uchar is_duplicate_confirmed;
};
typedef struct fd_frozen_hash_status fd_frozen_hash_status_t;
#define FD_FROZEN_HASH_STATUS_FOOTPRINT sizeof(fd_frozen_hash_status_t)
#define FD_FROZEN_HASH_STATUS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_frozen_hash_status_off {
  uint frozen_hash_off;
  uint is_duplicate_confirmed_off;
};
typedef struct fd_frozen_hash_status_off fd_frozen_hash_status_off_t;
#define FD_FROZEN_HASH_STATUS_OFF_FOOTPRINT sizeof(fd_frozen_hash_status_off_t)
#define FD_FROZEN_HASH_STATUS_OFF_ALIGN (8UL)

union fd_frozen_hash_versioned_inner {
  fd_frozen_hash_status_t current;
};
typedef union fd_frozen_hash_versioned_inner fd_frozen_hash_versioned_inner_t;

/* https://github.com/firedancer-io/solana/blob/f4b7c54f9e021b40cfc7cbd32dc12b19dedbe791/ledger/src/blockstore_meta.rs#L157 */
struct fd_frozen_hash_versioned {
  uint discriminant;
  fd_frozen_hash_versioned_inner_t inner;
};
typedef struct fd_frozen_hash_versioned fd_frozen_hash_versioned_t;
#define FD_FROZEN_HASH_VERSIONED_FOOTPRINT sizeof(fd_frozen_hash_versioned_t)
#define FD_FROZEN_HASH_VERSIONED_ALIGN (8UL)

/*  */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_lookup_table_meta {
  ulong deactivation_slot;
  ulong last_extended_slot;
  uchar last_extended_slot_start_index;
  fd_pubkey_t authority;
  uchar has_authority;
  ushort _padding;
};
typedef struct fd_lookup_table_meta fd_lookup_table_meta_t;
#define FD_LOOKUP_TABLE_META_FOOTPRINT sizeof(fd_lookup_table_meta_t)
#define FD_LOOKUP_TABLE_META_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_lookup_table_meta_off {
  uint deactivation_slot_off;
  uint last_extended_slot_off;
  uint last_extended_slot_start_index_off;
  uint authority_off;
  uint _padding_off;
};
typedef struct fd_lookup_table_meta_off fd_lookup_table_meta_off_t;
#define FD_LOOKUP_TABLE_META_OFF_FOOTPRINT sizeof(fd_lookup_table_meta_off_t)
#define FD_LOOKUP_TABLE_META_OFF_ALIGN (8UL)

/*  */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_address_lookup_table {
  fd_lookup_table_meta_t meta;
};
typedef struct fd_address_lookup_table fd_address_lookup_table_t;
#define FD_ADDRESS_LOOKUP_TABLE_FOOTPRINT sizeof(fd_address_lookup_table_t)
#define FD_ADDRESS_LOOKUP_TABLE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_address_lookup_table_off {
  uint meta_off;
};
typedef struct fd_address_lookup_table_off fd_address_lookup_table_off_t;
#define FD_ADDRESS_LOOKUP_TABLE_OFF_FOOTPRINT sizeof(fd_address_lookup_table_off_t)
#define FD_ADDRESS_LOOKUP_TABLE_OFF_ALIGN (8UL)

union fd_address_lookup_table_state_inner {
  fd_address_lookup_table_t lookup_table;
};
typedef union fd_address_lookup_table_state_inner fd_address_lookup_table_state_inner_t;

/*  */
struct fd_address_lookup_table_state {
  uint discriminant;
  fd_address_lookup_table_state_inner_t inner;
};
typedef struct fd_address_lookup_table_state fd_address_lookup_table_state_t;
#define FD_ADDRESS_LOOKUP_TABLE_STATE_FOOTPRINT sizeof(fd_address_lookup_table_state_t)
#define FD_ADDRESS_LOOKUP_TABLE_STATE_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u8_inner {
  ulong vec_len;
  uchar* vec;
};
typedef struct fd_gossip_bitvec_u8_inner fd_gossip_bitvec_u8_inner_t;
#define FD_GOSSIP_BITVEC_U8_INNER_FOOTPRINT sizeof(fd_gossip_bitvec_u8_inner_t)
#define FD_GOSSIP_BITVEC_U8_INNER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u8_inner_off {
  uint vec_off;
};
typedef struct fd_gossip_bitvec_u8_inner_off fd_gossip_bitvec_u8_inner_off_t;
#define FD_GOSSIP_BITVEC_U8_INNER_OFF_FOOTPRINT sizeof(fd_gossip_bitvec_u8_inner_off_t)
#define FD_GOSSIP_BITVEC_U8_INNER_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u8 {
  fd_gossip_bitvec_u8_inner_t bits;
  uchar has_bits;
  ulong len;
};
typedef struct fd_gossip_bitvec_u8 fd_gossip_bitvec_u8_t;
#define FD_GOSSIP_BITVEC_U8_FOOTPRINT sizeof(fd_gossip_bitvec_u8_t)
#define FD_GOSSIP_BITVEC_U8_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u8_off {
  uint bits_off;
  uint len_off;
};
typedef struct fd_gossip_bitvec_u8_off fd_gossip_bitvec_u8_off_t;
#define FD_GOSSIP_BITVEC_U8_OFF_FOOTPRINT sizeof(fd_gossip_bitvec_u8_off_t)
#define FD_GOSSIP_BITVEC_U8_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u64_inner {
  ulong vec_len;
  ulong* vec;
};
typedef struct fd_gossip_bitvec_u64_inner fd_gossip_bitvec_u64_inner_t;
#define FD_GOSSIP_BITVEC_U64_INNER_FOOTPRINT sizeof(fd_gossip_bitvec_u64_inner_t)
#define FD_GOSSIP_BITVEC_U64_INNER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u64_inner_off {
  uint vec_off;
};
typedef struct fd_gossip_bitvec_u64_inner_off fd_gossip_bitvec_u64_inner_off_t;
#define FD_GOSSIP_BITVEC_U64_INNER_OFF_FOOTPRINT sizeof(fd_gossip_bitvec_u64_inner_off_t)
#define FD_GOSSIP_BITVEC_U64_INNER_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u64 {
  fd_gossip_bitvec_u64_inner_t bits;
  uchar has_bits;
  ulong len;
};
typedef struct fd_gossip_bitvec_u64 fd_gossip_bitvec_u64_t;
#define FD_GOSSIP_BITVEC_U64_FOOTPRINT sizeof(fd_gossip_bitvec_u64_t)
#define FD_GOSSIP_BITVEC_U64_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_bitvec_u64_off {
  uint bits_off;
  uint len_off;
};
typedef struct fd_gossip_bitvec_u64_off fd_gossip_bitvec_u64_off_t;
#define FD_GOSSIP_BITVEC_U64_OFF_FOOTPRINT sizeof(fd_gossip_bitvec_u64_off_t)
#define FD_GOSSIP_BITVEC_U64_OFF_ALIGN (8UL)

/* https://github.com/solana-labs/solana/blob/52616cf7aa424a80f770e5ec3f2cd49d1cfeb845/gossip/src/ping_pong.rs#L22 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_ping {
  fd_pubkey_t from;
  fd_hash_t token;
  fd_signature_t signature;
};
typedef struct fd_gossip_ping fd_gossip_ping_t;
#define FD_GOSSIP_PING_FOOTPRINT sizeof(fd_gossip_ping_t)
#define FD_GOSSIP_PING_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_ping_off {
  uint from_off;
  uint token_off;
  uint signature_off;
};
typedef struct fd_gossip_ping_off fd_gossip_ping_off_t;
#define FD_GOSSIP_PING_OFF_FOOTPRINT sizeof(fd_gossip_ping_off_t)
#define FD_GOSSIP_PING_OFF_ALIGN (8UL)

union fd_gossip_ip_addr_inner {
  fd_gossip_ip4_addr_t ip4;
  fd_gossip_ip6_addr_t ip6;
};
typedef union fd_gossip_ip_addr_inner fd_gossip_ip_addr_inner_t;

/* Unnecessary and sad wrapper type. IPv4 addresses could have been mapped to IPv6 */
struct fd_gossip_ip_addr {
  uint discriminant;
  fd_gossip_ip_addr_inner_t inner;
};
typedef struct fd_gossip_ip_addr fd_gossip_ip_addr_t;
#define FD_GOSSIP_IP_ADDR_FOOTPRINT sizeof(fd_gossip_ip_addr_t)
#define FD_GOSSIP_IP_ADDR_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_prune_data {
  fd_pubkey_t pubkey;
  ulong prunes_len;
  fd_pubkey_t * prunes;
  fd_signature_t signature;
  fd_pubkey_t destination;
  ulong wallclock;
};
typedef struct fd_gossip_prune_data fd_gossip_prune_data_t;
#define FD_GOSSIP_PRUNE_DATA_FOOTPRINT sizeof(fd_gossip_prune_data_t)
#define FD_GOSSIP_PRUNE_DATA_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_prune_data_off {
  uint pubkey_off;
  uint prunes_off;
  uint signature_off;
  uint destination_off;
  uint wallclock_off;
};
typedef struct fd_gossip_prune_data_off fd_gossip_prune_data_off_t;
#define FD_GOSSIP_PRUNE_DATA_OFF_FOOTPRINT sizeof(fd_gossip_prune_data_off_t)
#define FD_GOSSIP_PRUNE_DATA_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_prune_sign_data {
  fd_pubkey_t pubkey;
  ulong prunes_len;
  fd_pubkey_t * prunes;
  fd_pubkey_t destination;
  ulong wallclock;
};
typedef struct fd_gossip_prune_sign_data fd_gossip_prune_sign_data_t;
#define FD_GOSSIP_PRUNE_SIGN_DATA_FOOTPRINT sizeof(fd_gossip_prune_sign_data_t)
#define FD_GOSSIP_PRUNE_SIGN_DATA_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_prune_sign_data_off {
  uint pubkey_off;
  uint prunes_off;
  uint destination_off;
  uint wallclock_off;
};
typedef struct fd_gossip_prune_sign_data_off fd_gossip_prune_sign_data_off_t;
#define FD_GOSSIP_PRUNE_SIGN_DATA_OFF_FOOTPRINT sizeof(fd_gossip_prune_sign_data_off_t)
#define FD_GOSSIP_PRUNE_SIGN_DATA_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_prune_sign_data_with_prefix {
  ulong prefix_len;
  uchar* prefix;
  fd_gossip_prune_sign_data_t data;
};
typedef struct fd_gossip_prune_sign_data_with_prefix fd_gossip_prune_sign_data_with_prefix_t;
#define FD_GOSSIP_PRUNE_SIGN_DATA_WITH_PREFIX_FOOTPRINT sizeof(fd_gossip_prune_sign_data_with_prefix_t)
#define FD_GOSSIP_PRUNE_SIGN_DATA_WITH_PREFIX_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_prune_sign_data_with_prefix_off {
  uint prefix_off;
  uint data_off;
};
typedef struct fd_gossip_prune_sign_data_with_prefix_off fd_gossip_prune_sign_data_with_prefix_off_t;
#define FD_GOSSIP_PRUNE_SIGN_DATA_WITH_PREFIX_OFF_FOOTPRINT sizeof(fd_gossip_prune_sign_data_with_prefix_off_t)
#define FD_GOSSIP_PRUNE_SIGN_DATA_WITH_PREFIX_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_socket_addr_old {
  fd_gossip_ip_addr_t addr;
  ushort port;
};
typedef struct fd_gossip_socket_addr_old fd_gossip_socket_addr_old_t;
#define FD_GOSSIP_SOCKET_ADDR_OLD_FOOTPRINT sizeof(fd_gossip_socket_addr_old_t)
#define FD_GOSSIP_SOCKET_ADDR_OLD_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_socket_addr_old_off {
  uint addr_off;
  uint port_off;
};
typedef struct fd_gossip_socket_addr_old_off fd_gossip_socket_addr_old_off_t;
#define FD_GOSSIP_SOCKET_ADDR_OLD_OFF_FOOTPRINT sizeof(fd_gossip_socket_addr_old_off_t)
#define FD_GOSSIP_SOCKET_ADDR_OLD_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_socket_addr_ip4 {
  fd_gossip_ip4_addr_t addr;
  ushort port;
};
typedef struct fd_gossip_socket_addr_ip4 fd_gossip_socket_addr_ip4_t;
#define FD_GOSSIP_SOCKET_ADDR_IP4_FOOTPRINT sizeof(fd_gossip_socket_addr_ip4_t)
#define FD_GOSSIP_SOCKET_ADDR_IP4_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_socket_addr_ip4_off {
  uint addr_off;
  uint port_off;
};
typedef struct fd_gossip_socket_addr_ip4_off fd_gossip_socket_addr_ip4_off_t;
#define FD_GOSSIP_SOCKET_ADDR_IP4_OFF_FOOTPRINT sizeof(fd_gossip_socket_addr_ip4_off_t)
#define FD_GOSSIP_SOCKET_ADDR_IP4_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_socket_addr_ip6 {
  fd_gossip_ip6_addr_t addr;
  ushort port;
  uint flowinfo;
  uint scope_id;
};
typedef struct fd_gossip_socket_addr_ip6 fd_gossip_socket_addr_ip6_t;
#define FD_GOSSIP_SOCKET_ADDR_IP6_FOOTPRINT sizeof(fd_gossip_socket_addr_ip6_t)
#define FD_GOSSIP_SOCKET_ADDR_IP6_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_socket_addr_ip6_off {
  uint addr_off;
  uint port_off;
  uint flowinfo_off;
  uint scope_id_off;
};
typedef struct fd_gossip_socket_addr_ip6_off fd_gossip_socket_addr_ip6_off_t;
#define FD_GOSSIP_SOCKET_ADDR_IP6_OFF_FOOTPRINT sizeof(fd_gossip_socket_addr_ip6_off_t)
#define FD_GOSSIP_SOCKET_ADDR_IP6_OFF_ALIGN (8UL)

union fd_gossip_socket_addr_inner {
  fd_gossip_socket_addr_ip4_t ip4;
  fd_gossip_socket_addr_ip6_t ip6;
};
typedef union fd_gossip_socket_addr_inner fd_gossip_socket_addr_inner_t;

struct fd_gossip_socket_addr {
  uint discriminant;
  fd_gossip_socket_addr_inner_t inner;
};
typedef struct fd_gossip_socket_addr fd_gossip_socket_addr_t;
#define FD_GOSSIP_SOCKET_ADDR_FOOTPRINT sizeof(fd_gossip_socket_addr_t)
#define FD_GOSSIP_SOCKET_ADDR_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_contact_info_v1 {
  fd_pubkey_t id;
  fd_gossip_socket_addr_t gossip;
  fd_gossip_socket_addr_t tvu;
  fd_gossip_socket_addr_t tvu_fwd;
  fd_gossip_socket_addr_t repair;
  fd_gossip_socket_addr_t tpu;
  fd_gossip_socket_addr_t tpu_fwd;
  fd_gossip_socket_addr_t tpu_vote;
  fd_gossip_socket_addr_t rpc;
  fd_gossip_socket_addr_t rpc_pubsub;
  fd_gossip_socket_addr_t serve_repair;
  ulong wallclock;
  ushort shred_version;
};
typedef struct fd_gossip_contact_info_v1 fd_gossip_contact_info_v1_t;
#define FD_GOSSIP_CONTACT_INFO_V1_FOOTPRINT sizeof(fd_gossip_contact_info_v1_t)
#define FD_GOSSIP_CONTACT_INFO_V1_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_contact_info_v1_off {
  uint id_off;
  uint gossip_off;
  uint tvu_off;
  uint tvu_fwd_off;
  uint repair_off;
  uint tpu_off;
  uint tpu_fwd_off;
  uint tpu_vote_off;
  uint rpc_off;
  uint rpc_pubsub_off;
  uint serve_repair_off;
  uint wallclock_off;
  uint shred_version_off;
};
typedef struct fd_gossip_contact_info_v1_off fd_gossip_contact_info_v1_off_t;
#define FD_GOSSIP_CONTACT_INFO_V1_OFF_FOOTPRINT sizeof(fd_gossip_contact_info_v1_off_t)
#define FD_GOSSIP_CONTACT_INFO_V1_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_vote {
  uchar index;
  fd_pubkey_t from;
  fd_flamenco_txn_t txn;
  ulong wallclock;
};
typedef struct fd_gossip_vote fd_gossip_vote_t;
#define FD_GOSSIP_VOTE_FOOTPRINT sizeof(fd_gossip_vote_t)
#define FD_GOSSIP_VOTE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_vote_off {
  uint index_off;
  uint from_off;
  uint txn_off;
  uint wallclock_off;
};
typedef struct fd_gossip_vote_off fd_gossip_vote_off_t;
#define FD_GOSSIP_VOTE_OFF_FOOTPRINT sizeof(fd_gossip_vote_off_t)
#define FD_GOSSIP_VOTE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_lowest_slot {
  uchar u8;
  fd_pubkey_t from;
  ulong root;
  ulong lowest;
  ulong slots_len;
  ulong* slots;
  ulong i_dont_know;
  ulong wallclock;
};
typedef struct fd_gossip_lowest_slot fd_gossip_lowest_slot_t;
#define FD_GOSSIP_LOWEST_SLOT_FOOTPRINT sizeof(fd_gossip_lowest_slot_t)
#define FD_GOSSIP_LOWEST_SLOT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_lowest_slot_off {
  uint u8_off;
  uint from_off;
  uint root_off;
  uint lowest_off;
  uint slots_off;
  uint i_dont_know_off;
  uint wallclock_off;
};
typedef struct fd_gossip_lowest_slot_off fd_gossip_lowest_slot_off_t;
#define FD_GOSSIP_LOWEST_SLOT_OFF_FOOTPRINT sizeof(fd_gossip_lowest_slot_off_t)
#define FD_GOSSIP_LOWEST_SLOT_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_slot_hashes {
  fd_pubkey_t from;
  ulong hashes_len;
  fd_slot_hash_t * hashes;
  ulong wallclock;
};
typedef struct fd_gossip_slot_hashes fd_gossip_slot_hashes_t;
#define FD_GOSSIP_SLOT_HASHES_FOOTPRINT sizeof(fd_gossip_slot_hashes_t)
#define FD_GOSSIP_SLOT_HASHES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_slot_hashes_off {
  uint from_off;
  uint hashes_off;
  uint wallclock_off;
};
typedef struct fd_gossip_slot_hashes_off fd_gossip_slot_hashes_off_t;
#define FD_GOSSIP_SLOT_HASHES_OFF_FOOTPRINT sizeof(fd_gossip_slot_hashes_off_t)
#define FD_GOSSIP_SLOT_HASHES_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_slots {
  ulong first_slot;
  ulong num;
  fd_gossip_bitvec_u8_t slots;
};
typedef struct fd_gossip_slots fd_gossip_slots_t;
#define FD_GOSSIP_SLOTS_FOOTPRINT sizeof(fd_gossip_slots_t)
#define FD_GOSSIP_SLOTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_slots_off {
  uint first_slot_off;
  uint num_off;
  uint slots_off;
};
typedef struct fd_gossip_slots_off fd_gossip_slots_off_t;
#define FD_GOSSIP_SLOTS_OFF_FOOTPRINT sizeof(fd_gossip_slots_off_t)
#define FD_GOSSIP_SLOTS_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_flate2_slots {
  ulong first_slot;
  ulong num;
  ulong compressed_len;
  uchar* compressed;
};
typedef struct fd_gossip_flate2_slots fd_gossip_flate2_slots_t;
#define FD_GOSSIP_FLATE2_SLOTS_FOOTPRINT sizeof(fd_gossip_flate2_slots_t)
#define FD_GOSSIP_FLATE2_SLOTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_flate2_slots_off {
  uint first_slot_off;
  uint num_off;
  uint compressed_off;
};
typedef struct fd_gossip_flate2_slots_off fd_gossip_flate2_slots_off_t;
#define FD_GOSSIP_FLATE2_SLOTS_OFF_FOOTPRINT sizeof(fd_gossip_flate2_slots_off_t)
#define FD_GOSSIP_FLATE2_SLOTS_OFF_ALIGN (8UL)

union fd_gossip_slots_enum_inner {
  fd_gossip_flate2_slots_t flate2;
  fd_gossip_slots_t uncompressed;
};
typedef union fd_gossip_slots_enum_inner fd_gossip_slots_enum_inner_t;

struct fd_gossip_slots_enum {
  uint discriminant;
  fd_gossip_slots_enum_inner_t inner;
};
typedef struct fd_gossip_slots_enum fd_gossip_slots_enum_t;
#define FD_GOSSIP_SLOTS_ENUM_FOOTPRINT sizeof(fd_gossip_slots_enum_t)
#define FD_GOSSIP_SLOTS_ENUM_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_epoch_slots {
  uchar u8;
  fd_pubkey_t from;
  ulong slots_len;
  fd_gossip_slots_enum_t * slots;
  ulong wallclock;
};
typedef struct fd_gossip_epoch_slots fd_gossip_epoch_slots_t;
#define FD_GOSSIP_EPOCH_SLOTS_FOOTPRINT sizeof(fd_gossip_epoch_slots_t)
#define FD_GOSSIP_EPOCH_SLOTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_epoch_slots_off {
  uint u8_off;
  uint from_off;
  uint slots_off;
  uint wallclock_off;
};
typedef struct fd_gossip_epoch_slots_off fd_gossip_epoch_slots_off_t;
#define FD_GOSSIP_EPOCH_SLOTS_OFF_FOOTPRINT sizeof(fd_gossip_epoch_slots_off_t)
#define FD_GOSSIP_EPOCH_SLOTS_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_version_v1 {
  fd_pubkey_t from;
  ulong wallclock;
  ushort major;
  ushort minor;
  ushort patch;
  uint commit;
  uchar has_commit;
};
typedef struct fd_gossip_version_v1 fd_gossip_version_v1_t;
#define FD_GOSSIP_VERSION_V1_FOOTPRINT sizeof(fd_gossip_version_v1_t)
#define FD_GOSSIP_VERSION_V1_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_version_v1_off {
  uint from_off;
  uint wallclock_off;
  uint major_off;
  uint minor_off;
  uint patch_off;
  uint commit_off;
};
typedef struct fd_gossip_version_v1_off fd_gossip_version_v1_off_t;
#define FD_GOSSIP_VERSION_V1_OFF_FOOTPRINT sizeof(fd_gossip_version_v1_off_t)
#define FD_GOSSIP_VERSION_V1_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_version_v2 {
  fd_pubkey_t from;
  ulong wallclock;
  ushort major;
  ushort minor;
  ushort patch;
  uint commit;
  uchar has_commit;
  uint feature_set;
};
typedef struct fd_gossip_version_v2 fd_gossip_version_v2_t;
#define FD_GOSSIP_VERSION_V2_FOOTPRINT sizeof(fd_gossip_version_v2_t)
#define FD_GOSSIP_VERSION_V2_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_version_v2_off {
  uint from_off;
  uint wallclock_off;
  uint major_off;
  uint minor_off;
  uint patch_off;
  uint commit_off;
  uint feature_set_off;
};
typedef struct fd_gossip_version_v2_off fd_gossip_version_v2_off_t;
#define FD_GOSSIP_VERSION_V2_OFF_FOOTPRINT sizeof(fd_gossip_version_v2_off_t)
#define FD_GOSSIP_VERSION_V2_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_version_v3 {
  ushort major;
  ushort minor;
  ushort patch;
  uint commit;
  uint feature_set;
  ushort client;
};
typedef struct fd_gossip_version_v3 fd_gossip_version_v3_t;
#define FD_GOSSIP_VERSION_V3_FOOTPRINT sizeof(fd_gossip_version_v3_t)
#define FD_GOSSIP_VERSION_V3_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_version_v3_off {
  uint major_off;
  uint minor_off;
  uint patch_off;
  uint commit_off;
  uint feature_set_off;
  uint client_off;
};
typedef struct fd_gossip_version_v3_off fd_gossip_version_v3_off_t;
#define FD_GOSSIP_VERSION_V3_OFF_FOOTPRINT sizeof(fd_gossip_version_v3_off_t)
#define FD_GOSSIP_VERSION_V3_OFF_ALIGN (8UL)

/* Encoded Size: Fixed (56 bytes) */
struct __attribute__((aligned(8UL))) fd_gossip_node_instance {
  fd_pubkey_t from;
  ulong wallclock;
  long timestamp;
  ulong token;
};
typedef struct fd_gossip_node_instance fd_gossip_node_instance_t;
#define FD_GOSSIP_NODE_INSTANCE_FOOTPRINT sizeof(fd_gossip_node_instance_t)
#define FD_GOSSIP_NODE_INSTANCE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_node_instance_off {
  uint from_off;
  uint wallclock_off;
  uint timestamp_off;
  uint token_off;
};
typedef struct fd_gossip_node_instance_off fd_gossip_node_instance_off_t;
#define FD_GOSSIP_NODE_INSTANCE_OFF_FOOTPRINT sizeof(fd_gossip_node_instance_off_t)
#define FD_GOSSIP_NODE_INSTANCE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_duplicate_shred {
  ushort duplicate_shred_index;
  fd_pubkey_t from;
  ulong wallclock;
  ulong slot;
  uint _unused;
  uchar _unused_shred_type;
  uchar num_chunks;
  uchar chunk_index;
  ulong chunk_len;
  uchar* chunk;
};
typedef struct fd_gossip_duplicate_shred fd_gossip_duplicate_shred_t;
#define FD_GOSSIP_DUPLICATE_SHRED_FOOTPRINT sizeof(fd_gossip_duplicate_shred_t)
#define FD_GOSSIP_DUPLICATE_SHRED_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_duplicate_shred_off {
  uint duplicate_shred_index_off;
  uint from_off;
  uint wallclock_off;
  uint slot_off;
  uint _unused_off;
  uint _unused_shred_type_off;
  uint num_chunks_off;
  uint chunk_index_off;
  uint chunk_off;
};
typedef struct fd_gossip_duplicate_shred_off fd_gossip_duplicate_shred_off_t;
#define FD_GOSSIP_DUPLICATE_SHRED_OFF_FOOTPRINT sizeof(fd_gossip_duplicate_shred_off_t)
#define FD_GOSSIP_DUPLICATE_SHRED_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_incremental_snapshot_hashes {
  fd_pubkey_t from;
  fd_slot_hash_t base_hash;
  ulong hashes_len;
  fd_slot_hash_t * hashes;
  ulong wallclock;
};
typedef struct fd_gossip_incremental_snapshot_hashes fd_gossip_incremental_snapshot_hashes_t;
#define FD_GOSSIP_INCREMENTAL_SNAPSHOT_HASHES_FOOTPRINT sizeof(fd_gossip_incremental_snapshot_hashes_t)
#define FD_GOSSIP_INCREMENTAL_SNAPSHOT_HASHES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_incremental_snapshot_hashes_off {
  uint from_off;
  uint base_hash_off;
  uint hashes_off;
  uint wallclock_off;
};
typedef struct fd_gossip_incremental_snapshot_hashes_off fd_gossip_incremental_snapshot_hashes_off_t;
#define FD_GOSSIP_INCREMENTAL_SNAPSHOT_HASHES_OFF_FOOTPRINT sizeof(fd_gossip_incremental_snapshot_hashes_off_t)
#define FD_GOSSIP_INCREMENTAL_SNAPSHOT_HASHES_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_socket_entry {
  uchar key;
  uchar index;
  ushort offset;
};
typedef struct fd_gossip_socket_entry fd_gossip_socket_entry_t;
#define FD_GOSSIP_SOCKET_ENTRY_FOOTPRINT sizeof(fd_gossip_socket_entry_t)
#define FD_GOSSIP_SOCKET_ENTRY_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_socket_entry_off {
  uint key_off;
  uint index_off;
  uint offset_off;
};
typedef struct fd_gossip_socket_entry_off fd_gossip_socket_entry_off_t;
#define FD_GOSSIP_SOCKET_ENTRY_OFF_FOOTPRINT sizeof(fd_gossip_socket_entry_off_t)
#define FD_GOSSIP_SOCKET_ENTRY_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_contact_info_v2 {
  fd_pubkey_t from;
  ulong wallclock;
  ulong outset;
  ushort shred_version;
  fd_gossip_version_v3_t version;
  ushort addrs_len;
  fd_gossip_ip_addr_t * addrs;
  ushort sockets_len;
  fd_gossip_socket_entry_t * sockets;
  ushort extensions_len;
  uint* extensions;
};
typedef struct fd_gossip_contact_info_v2 fd_gossip_contact_info_v2_t;
#define FD_GOSSIP_CONTACT_INFO_V2_FOOTPRINT sizeof(fd_gossip_contact_info_v2_t)
#define FD_GOSSIP_CONTACT_INFO_V2_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_contact_info_v2_off {
  uint from_off;
  uint wallclock_off;
  uint outset_off;
  uint shred_version_off;
  uint version_off;
  uint addrs_off;
  uint sockets_off;
  uint extensions_off;
};
typedef struct fd_gossip_contact_info_v2_off fd_gossip_contact_info_v2_off_t;
#define FD_GOSSIP_CONTACT_INFO_V2_OFF_FOOTPRINT sizeof(fd_gossip_contact_info_v2_off_t)
#define FD_GOSSIP_CONTACT_INFO_V2_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_restart_run_length_encoding_inner {
  ushort bits;
};
typedef struct fd_restart_run_length_encoding_inner fd_restart_run_length_encoding_inner_t;
#define FD_RESTART_RUN_LENGTH_ENCODING_INNER_FOOTPRINT sizeof(fd_restart_run_length_encoding_inner_t)
#define FD_RESTART_RUN_LENGTH_ENCODING_INNER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_restart_run_length_encoding_inner_off {
  uint bits_off;
};
typedef struct fd_restart_run_length_encoding_inner_off fd_restart_run_length_encoding_inner_off_t;
#define FD_RESTART_RUN_LENGTH_ENCODING_INNER_OFF_FOOTPRINT sizeof(fd_restart_run_length_encoding_inner_off_t)
#define FD_RESTART_RUN_LENGTH_ENCODING_INNER_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_restart_run_length_encoding {
  ulong offsets_len;
  fd_restart_run_length_encoding_inner_t * offsets;
};
typedef struct fd_restart_run_length_encoding fd_restart_run_length_encoding_t;
#define FD_RESTART_RUN_LENGTH_ENCODING_FOOTPRINT sizeof(fd_restart_run_length_encoding_t)
#define FD_RESTART_RUN_LENGTH_ENCODING_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_restart_run_length_encoding_off {
  uint offsets_off;
};
typedef struct fd_restart_run_length_encoding_off fd_restart_run_length_encoding_off_t;
#define FD_RESTART_RUN_LENGTH_ENCODING_OFF_FOOTPRINT sizeof(fd_restart_run_length_encoding_off_t)
#define FD_RESTART_RUN_LENGTH_ENCODING_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_restart_raw_offsets_bitvec_u8_inner {
  ulong bits_len;
  uchar* bits;
};
typedef struct fd_restart_raw_offsets_bitvec_u8_inner fd_restart_raw_offsets_bitvec_u8_inner_t;
#define FD_RESTART_RAW_OFFSETS_BITVEC_U8_INNER_FOOTPRINT sizeof(fd_restart_raw_offsets_bitvec_u8_inner_t)
#define FD_RESTART_RAW_OFFSETS_BITVEC_U8_INNER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_restart_raw_offsets_bitvec_u8_inner_off {
  uint bits_off;
};
typedef struct fd_restart_raw_offsets_bitvec_u8_inner_off fd_restart_raw_offsets_bitvec_u8_inner_off_t;
#define FD_RESTART_RAW_OFFSETS_BITVEC_U8_INNER_OFF_FOOTPRINT sizeof(fd_restart_raw_offsets_bitvec_u8_inner_off_t)
#define FD_RESTART_RAW_OFFSETS_BITVEC_U8_INNER_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_restart_raw_offsets_bitvec {
  fd_restart_raw_offsets_bitvec_u8_inner_t bits;
  uchar has_bits;
  ulong len;
};
typedef struct fd_restart_raw_offsets_bitvec fd_restart_raw_offsets_bitvec_t;
#define FD_RESTART_RAW_OFFSETS_BITVEC_FOOTPRINT sizeof(fd_restart_raw_offsets_bitvec_t)
#define FD_RESTART_RAW_OFFSETS_BITVEC_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_restart_raw_offsets_bitvec_off {
  uint bits_off;
  uint len_off;
};
typedef struct fd_restart_raw_offsets_bitvec_off fd_restart_raw_offsets_bitvec_off_t;
#define FD_RESTART_RAW_OFFSETS_BITVEC_OFF_FOOTPRINT sizeof(fd_restart_raw_offsets_bitvec_off_t)
#define FD_RESTART_RAW_OFFSETS_BITVEC_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_restart_raw_offsets {
  fd_restart_raw_offsets_bitvec_t offsets;
};
typedef struct fd_restart_raw_offsets fd_restart_raw_offsets_t;
#define FD_RESTART_RAW_OFFSETS_FOOTPRINT sizeof(fd_restart_raw_offsets_t)
#define FD_RESTART_RAW_OFFSETS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_restart_raw_offsets_off {
  uint offsets_off;
};
typedef struct fd_restart_raw_offsets_off fd_restart_raw_offsets_off_t;
#define FD_RESTART_RAW_OFFSETS_OFF_FOOTPRINT sizeof(fd_restart_raw_offsets_off_t)
#define FD_RESTART_RAW_OFFSETS_OFF_ALIGN (8UL)

union fd_restart_slots_offsets_inner {
  fd_restart_run_length_encoding_t run_length_encoding;
  fd_restart_raw_offsets_t raw_offsets;
};
typedef union fd_restart_slots_offsets_inner fd_restart_slots_offsets_inner_t;

struct fd_restart_slots_offsets {
  uint discriminant;
  fd_restart_slots_offsets_inner_t inner;
};
typedef struct fd_restart_slots_offsets fd_restart_slots_offsets_t;
#define FD_RESTART_SLOTS_OFFSETS_FOOTPRINT sizeof(fd_restart_slots_offsets_t)
#define FD_RESTART_SLOTS_OFFSETS_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_restart_last_voted_fork_slots {
  fd_pubkey_t from;
  ulong wallclock;
  fd_restart_slots_offsets_t offsets;
  ulong last_voted_slot;
  fd_hash_t last_voted_hash;
  ushort shred_version;
};
typedef struct fd_gossip_restart_last_voted_fork_slots fd_gossip_restart_last_voted_fork_slots_t;
#define FD_GOSSIP_RESTART_LAST_VOTED_FORK_SLOTS_FOOTPRINT sizeof(fd_gossip_restart_last_voted_fork_slots_t)
#define FD_GOSSIP_RESTART_LAST_VOTED_FORK_SLOTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_restart_last_voted_fork_slots_off {
  uint from_off;
  uint wallclock_off;
  uint offsets_off;
  uint last_voted_slot_off;
  uint last_voted_hash_off;
  uint shred_version_off;
};
typedef struct fd_gossip_restart_last_voted_fork_slots_off fd_gossip_restart_last_voted_fork_slots_off_t;
#define FD_GOSSIP_RESTART_LAST_VOTED_FORK_SLOTS_OFF_FOOTPRINT sizeof(fd_gossip_restart_last_voted_fork_slots_off_t)
#define FD_GOSSIP_RESTART_LAST_VOTED_FORK_SLOTS_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_restart_heaviest_fork {
  fd_pubkey_t from;
  ulong wallclock;
  ulong last_slot;
  fd_hash_t last_slot_hash;
  ulong observed_stake;
  ushort shred_version;
};
typedef struct fd_gossip_restart_heaviest_fork fd_gossip_restart_heaviest_fork_t;
#define FD_GOSSIP_RESTART_HEAVIEST_FORK_FOOTPRINT sizeof(fd_gossip_restart_heaviest_fork_t)
#define FD_GOSSIP_RESTART_HEAVIEST_FORK_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_restart_heaviest_fork_off {
  uint from_off;
  uint wallclock_off;
  uint last_slot_off;
  uint last_slot_hash_off;
  uint observed_stake_off;
  uint shred_version_off;
};
typedef struct fd_gossip_restart_heaviest_fork_off fd_gossip_restart_heaviest_fork_off_t;
#define FD_GOSSIP_RESTART_HEAVIEST_FORK_OFF_FOOTPRINT sizeof(fd_gossip_restart_heaviest_fork_off_t)
#define FD_GOSSIP_RESTART_HEAVIEST_FORK_OFF_ALIGN (8UL)

union fd_crds_data_inner {
  fd_gossip_contact_info_v1_t contact_info_v1;
  fd_gossip_vote_t vote;
  fd_gossip_lowest_slot_t lowest_slot;
  fd_gossip_slot_hashes_t snapshot_hashes;
  fd_gossip_slot_hashes_t accounts_hashes;
  fd_gossip_epoch_slots_t epoch_slots;
  fd_gossip_version_v1_t version_v1;
  fd_gossip_version_v2_t version_v2;
  fd_gossip_node_instance_t node_instance;
  fd_gossip_duplicate_shred_t duplicate_shred;
  fd_gossip_incremental_snapshot_hashes_t incremental_snapshot_hashes;
  fd_gossip_contact_info_v2_t contact_info_v2;
  fd_gossip_restart_last_voted_fork_slots_t restart_last_voted_fork_slots;
  fd_gossip_restart_heaviest_fork_t restart_heaviest_fork;
};
typedef union fd_crds_data_inner fd_crds_data_inner_t;

struct fd_crds_data {
  uint discriminant;
  fd_crds_data_inner_t inner;
};
typedef struct fd_crds_data fd_crds_data_t;
#define FD_CRDS_DATA_FOOTPRINT sizeof(fd_crds_data_t)
#define FD_CRDS_DATA_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_crds_bloom {
  ulong keys_len;
  ulong* keys;
  fd_gossip_bitvec_u64_t bits;
  ulong num_bits_set;
};
typedef struct fd_crds_bloom fd_crds_bloom_t;
#define FD_CRDS_BLOOM_FOOTPRINT sizeof(fd_crds_bloom_t)
#define FD_CRDS_BLOOM_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_crds_bloom_off {
  uint keys_off;
  uint bits_off;
  uint num_bits_set_off;
};
typedef struct fd_crds_bloom_off fd_crds_bloom_off_t;
#define FD_CRDS_BLOOM_OFF_FOOTPRINT sizeof(fd_crds_bloom_off_t)
#define FD_CRDS_BLOOM_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_crds_filter {
  fd_crds_bloom_t filter;
  ulong mask;
  uint mask_bits;
};
typedef struct fd_crds_filter fd_crds_filter_t;
#define FD_CRDS_FILTER_FOOTPRINT sizeof(fd_crds_filter_t)
#define FD_CRDS_FILTER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_crds_filter_off {
  uint filter_off;
  uint mask_off;
  uint mask_bits_off;
};
typedef struct fd_crds_filter_off fd_crds_filter_off_t;
#define FD_CRDS_FILTER_OFF_FOOTPRINT sizeof(fd_crds_filter_off_t)
#define FD_CRDS_FILTER_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_crds_value {
  fd_signature_t signature;
  fd_crds_data_t data;
};
typedef struct fd_crds_value fd_crds_value_t;
#define FD_CRDS_VALUE_FOOTPRINT sizeof(fd_crds_value_t)
#define FD_CRDS_VALUE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_crds_value_off {
  uint signature_off;
  uint data_off;
};
typedef struct fd_crds_value_off fd_crds_value_off_t;
#define FD_CRDS_VALUE_OFF_FOOTPRINT sizeof(fd_crds_value_off_t)
#define FD_CRDS_VALUE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_pull_req {
  fd_crds_filter_t filter;
  fd_crds_value_t value;
};
typedef struct fd_gossip_pull_req fd_gossip_pull_req_t;
#define FD_GOSSIP_PULL_REQ_FOOTPRINT sizeof(fd_gossip_pull_req_t)
#define FD_GOSSIP_PULL_REQ_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_pull_req_off {
  uint filter_off;
  uint value_off;
};
typedef struct fd_gossip_pull_req_off fd_gossip_pull_req_off_t;
#define FD_GOSSIP_PULL_REQ_OFF_FOOTPRINT sizeof(fd_gossip_pull_req_off_t)
#define FD_GOSSIP_PULL_REQ_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_pull_resp {
  fd_pubkey_t pubkey;
  ulong crds_len;
  fd_crds_value_t * crds;
};
typedef struct fd_gossip_pull_resp fd_gossip_pull_resp_t;
#define FD_GOSSIP_PULL_RESP_FOOTPRINT sizeof(fd_gossip_pull_resp_t)
#define FD_GOSSIP_PULL_RESP_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_pull_resp_off {
  uint pubkey_off;
  uint crds_off;
};
typedef struct fd_gossip_pull_resp_off fd_gossip_pull_resp_off_t;
#define FD_GOSSIP_PULL_RESP_OFF_FOOTPRINT sizeof(fd_gossip_pull_resp_off_t)
#define FD_GOSSIP_PULL_RESP_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_push_msg {
  fd_pubkey_t pubkey;
  ulong crds_len;
  fd_crds_value_t * crds;
};
typedef struct fd_gossip_push_msg fd_gossip_push_msg_t;
#define FD_GOSSIP_PUSH_MSG_FOOTPRINT sizeof(fd_gossip_push_msg_t)
#define FD_GOSSIP_PUSH_MSG_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_push_msg_off {
  uint pubkey_off;
  uint crds_off;
};
typedef struct fd_gossip_push_msg_off fd_gossip_push_msg_off_t;
#define FD_GOSSIP_PUSH_MSG_OFF_FOOTPRINT sizeof(fd_gossip_push_msg_off_t)
#define FD_GOSSIP_PUSH_MSG_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_gossip_prune_msg {
  fd_pubkey_t pubkey;
  fd_gossip_prune_data_t data;
};
typedef struct fd_gossip_prune_msg fd_gossip_prune_msg_t;
#define FD_GOSSIP_PRUNE_MSG_FOOTPRINT sizeof(fd_gossip_prune_msg_t)
#define FD_GOSSIP_PRUNE_MSG_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_gossip_prune_msg_off {
  uint pubkey_off;
  uint data_off;
};
typedef struct fd_gossip_prune_msg_off fd_gossip_prune_msg_off_t;
#define FD_GOSSIP_PRUNE_MSG_OFF_FOOTPRINT sizeof(fd_gossip_prune_msg_off_t)
#define FD_GOSSIP_PRUNE_MSG_OFF_ALIGN (8UL)

union fd_gossip_msg_inner {
  fd_gossip_pull_req_t pull_req;
  fd_gossip_pull_resp_t pull_resp;
  fd_gossip_push_msg_t push_msg;
  fd_gossip_prune_msg_t prune_msg;
  fd_gossip_ping_t ping;
  fd_gossip_ping_t pong;
};
typedef union fd_gossip_msg_inner fd_gossip_msg_inner_t;

/* UDP payloads of the Solana gossip protocol */
struct fd_gossip_msg {
  uint discriminant;
  fd_gossip_msg_inner_t inner;
};
typedef struct fd_gossip_msg fd_gossip_msg_t;
#define FD_GOSSIP_MSG_FOOTPRINT sizeof(fd_gossip_msg_t)
#define FD_GOSSIP_MSG_ALIGN (8UL)

/* Encoded Size: Fixed (9 bytes) */
struct __attribute__((aligned(8UL))) fd_addrlut_create {
  ulong recent_slot;
  uchar bump_seed;
};
typedef struct fd_addrlut_create fd_addrlut_create_t;
#define FD_ADDRLUT_CREATE_FOOTPRINT sizeof(fd_addrlut_create_t)
#define FD_ADDRLUT_CREATE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_addrlut_create_off {
  uint recent_slot_off;
  uint bump_seed_off;
};
typedef struct fd_addrlut_create_off fd_addrlut_create_off_t;
#define FD_ADDRLUT_CREATE_OFF_FOOTPRINT sizeof(fd_addrlut_create_off_t)
#define FD_ADDRLUT_CREATE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_addrlut_extend {
  ulong new_addrs_len;
  fd_pubkey_t * new_addrs;
};
typedef struct fd_addrlut_extend fd_addrlut_extend_t;
#define FD_ADDRLUT_EXTEND_FOOTPRINT sizeof(fd_addrlut_extend_t)
#define FD_ADDRLUT_EXTEND_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_addrlut_extend_off {
  uint new_addrs_off;
};
typedef struct fd_addrlut_extend_off fd_addrlut_extend_off_t;
#define FD_ADDRLUT_EXTEND_OFF_FOOTPRINT sizeof(fd_addrlut_extend_off_t)
#define FD_ADDRLUT_EXTEND_OFF_ALIGN (8UL)

union fd_addrlut_instruction_inner {
  fd_addrlut_create_t create_lut;
  fd_addrlut_extend_t extend_lut;
};
typedef union fd_addrlut_instruction_inner fd_addrlut_instruction_inner_t;

/* https://github.com/solana-labs/solana/blob/fb80288f885a62bcd923f4c9579fd0edeafaff9b/sdk/program/src/address_lookup_table/instruction.rs#L13 */
struct fd_addrlut_instruction {
  uint discriminant;
  fd_addrlut_instruction_inner_t inner;
};
typedef struct fd_addrlut_instruction fd_addrlut_instruction_t;
#define FD_ADDRLUT_INSTRUCTION_FOOTPRINT sizeof(fd_addrlut_instruction_t)
#define FD_ADDRLUT_INSTRUCTION_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_repair_request_header {
  fd_signature_t signature;
  fd_pubkey_t sender;
  fd_pubkey_t recipient;
  long timestamp;
  uint nonce;
};
typedef struct fd_repair_request_header fd_repair_request_header_t;
#define FD_REPAIR_REQUEST_HEADER_FOOTPRINT sizeof(fd_repair_request_header_t)
#define FD_REPAIR_REQUEST_HEADER_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_repair_request_header_off {
  uint signature_off;
  uint sender_off;
  uint recipient_off;
  uint timestamp_off;
  uint nonce_off;
};
typedef struct fd_repair_request_header_off fd_repair_request_header_off_t;
#define FD_REPAIR_REQUEST_HEADER_OFF_FOOTPRINT sizeof(fd_repair_request_header_off_t)
#define FD_REPAIR_REQUEST_HEADER_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_repair_window_index {
  fd_repair_request_header_t header;
  ulong slot;
  ulong shred_index;
};
typedef struct fd_repair_window_index fd_repair_window_index_t;
#define FD_REPAIR_WINDOW_INDEX_FOOTPRINT sizeof(fd_repair_window_index_t)
#define FD_REPAIR_WINDOW_INDEX_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_repair_window_index_off {
  uint header_off;
  uint slot_off;
  uint shred_index_off;
};
typedef struct fd_repair_window_index_off fd_repair_window_index_off_t;
#define FD_REPAIR_WINDOW_INDEX_OFF_FOOTPRINT sizeof(fd_repair_window_index_off_t)
#define FD_REPAIR_WINDOW_INDEX_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_repair_highest_window_index {
  fd_repair_request_header_t header;
  ulong slot;
  ulong shred_index;
};
typedef struct fd_repair_highest_window_index fd_repair_highest_window_index_t;
#define FD_REPAIR_HIGHEST_WINDOW_INDEX_FOOTPRINT sizeof(fd_repair_highest_window_index_t)
#define FD_REPAIR_HIGHEST_WINDOW_INDEX_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_repair_highest_window_index_off {
  uint header_off;
  uint slot_off;
  uint shred_index_off;
};
typedef struct fd_repair_highest_window_index_off fd_repair_highest_window_index_off_t;
#define FD_REPAIR_HIGHEST_WINDOW_INDEX_OFF_FOOTPRINT sizeof(fd_repair_highest_window_index_off_t)
#define FD_REPAIR_HIGHEST_WINDOW_INDEX_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_repair_orphan {
  fd_repair_request_header_t header;
  ulong slot;
};
typedef struct fd_repair_orphan fd_repair_orphan_t;
#define FD_REPAIR_ORPHAN_FOOTPRINT sizeof(fd_repair_orphan_t)
#define FD_REPAIR_ORPHAN_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_repair_orphan_off {
  uint header_off;
  uint slot_off;
};
typedef struct fd_repair_orphan_off fd_repair_orphan_off_t;
#define FD_REPAIR_ORPHAN_OFF_FOOTPRINT sizeof(fd_repair_orphan_off_t)
#define FD_REPAIR_ORPHAN_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_repair_ancestor_hashes {
  fd_repair_request_header_t header;
  ulong slot;
};
typedef struct fd_repair_ancestor_hashes fd_repair_ancestor_hashes_t;
#define FD_REPAIR_ANCESTOR_HASHES_FOOTPRINT sizeof(fd_repair_ancestor_hashes_t)
#define FD_REPAIR_ANCESTOR_HASHES_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_repair_ancestor_hashes_off {
  uint header_off;
  uint slot_off;
};
typedef struct fd_repair_ancestor_hashes_off fd_repair_ancestor_hashes_off_t;
#define FD_REPAIR_ANCESTOR_HASHES_OFF_FOOTPRINT sizeof(fd_repair_ancestor_hashes_off_t)
#define FD_REPAIR_ANCESTOR_HASHES_OFF_ALIGN (8UL)

union fd_repair_protocol_inner {
  fd_gossip_ping_t pong;
  fd_repair_window_index_t window_index;
  fd_repair_highest_window_index_t highest_window_index;
  fd_repair_orphan_t orphan;
  fd_repair_ancestor_hashes_t ancestor_hashes;
};
typedef union fd_repair_protocol_inner fd_repair_protocol_inner_t;

struct fd_repair_protocol {
  uint discriminant;
  fd_repair_protocol_inner_t inner;
};
typedef struct fd_repair_protocol fd_repair_protocol_t;
#define FD_REPAIR_PROTOCOL_FOOTPRINT sizeof(fd_repair_protocol_t)
#define FD_REPAIR_PROTOCOL_ALIGN (8UL)

union fd_repair_response_inner {
  fd_gossip_ping_t ping;
};
typedef union fd_repair_response_inner fd_repair_response_inner_t;

struct fd_repair_response {
  uint discriminant;
  fd_repair_response_inner_t inner;
};
typedef struct fd_repair_response fd_repair_response_t;
#define FD_REPAIR_RESPONSE_FOOTPRINT sizeof(fd_repair_response_t)
#define FD_REPAIR_RESPONSE_ALIGN (8UL)

union fd_instr_error_enum_inner {
  uint custom;
  char* borsh_io_error;
};
typedef union fd_instr_error_enum_inner fd_instr_error_enum_inner_t;

struct fd_instr_error_enum {
  uint discriminant;
  fd_instr_error_enum_inner_t inner;
};
typedef struct fd_instr_error_enum fd_instr_error_enum_t;
#define FD_INSTR_ERROR_ENUM_FOOTPRINT sizeof(fd_instr_error_enum_t)
#define FD_INSTR_ERROR_ENUM_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_txn_instr_error {
  uchar instr_idx;
  fd_instr_error_enum_t error;
};
typedef struct fd_txn_instr_error fd_txn_instr_error_t;
#define FD_TXN_INSTR_ERROR_FOOTPRINT sizeof(fd_txn_instr_error_t)
#define FD_TXN_INSTR_ERROR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_txn_instr_error_off {
  uint instr_idx_off;
  uint error_off;
};
typedef struct fd_txn_instr_error_off fd_txn_instr_error_off_t;
#define FD_TXN_INSTR_ERROR_OFF_FOOTPRINT sizeof(fd_txn_instr_error_off_t)
#define FD_TXN_INSTR_ERROR_OFF_ALIGN (8UL)

union fd_txn_error_enum_inner {
  fd_txn_instr_error_t instruction_error;
  uchar duplicate_instruction;
  uchar insufficient_funds_for_rent;
  uchar program_execution_temporarily_restricted;
};
typedef union fd_txn_error_enum_inner fd_txn_error_enum_inner_t;

struct fd_txn_error_enum {
  uint discriminant;
  fd_txn_error_enum_inner_t inner;
};
typedef struct fd_txn_error_enum fd_txn_error_enum_t;
#define FD_TXN_ERROR_ENUM_FOOTPRINT sizeof(fd_txn_error_enum_t)
#define FD_TXN_ERROR_ENUM_ALIGN (8UL)

union fd_txn_result_inner {
  fd_txn_error_enum_t error;
};
typedef union fd_txn_result_inner fd_txn_result_inner_t;

struct fd_txn_result {
  uint discriminant;
  fd_txn_result_inner_t inner;
};
typedef struct fd_txn_result fd_txn_result_t;
#define FD_TXN_RESULT_FOOTPRINT sizeof(fd_txn_result_t)
#define FD_TXN_RESULT_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_cache_status {
  uchar key_slice[20];
  fd_txn_result_t result;
};
typedef struct fd_cache_status fd_cache_status_t;
#define FD_CACHE_STATUS_FOOTPRINT sizeof(fd_cache_status_t)
#define FD_CACHE_STATUS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_cache_status_off {
  uint key_slice_off;
  uint result_off;
};
typedef struct fd_cache_status_off fd_cache_status_off_t;
#define FD_CACHE_STATUS_OFF_FOOTPRINT sizeof(fd_cache_status_off_t)
#define FD_CACHE_STATUS_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_status_value {
  ulong txn_idx;
  ulong statuses_len;
  fd_cache_status_t * statuses;
};
typedef struct fd_status_value fd_status_value_t;
#define FD_STATUS_VALUE_FOOTPRINT sizeof(fd_status_value_t)
#define FD_STATUS_VALUE_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_status_value_off {
  uint txn_idx_off;
  uint statuses_off;
};
typedef struct fd_status_value_off fd_status_value_off_t;
#define FD_STATUS_VALUE_OFF_FOOTPRINT sizeof(fd_status_value_off_t)
#define FD_STATUS_VALUE_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_status_pair {
  fd_hash_t hash;
  fd_status_value_t value;
};
typedef struct fd_status_pair fd_status_pair_t;
#define FD_STATUS_PAIR_FOOTPRINT sizeof(fd_status_pair_t)
#define FD_STATUS_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_status_pair_off {
  uint hash_off;
  uint value_off;
};
typedef struct fd_status_pair_off fd_status_pair_off_t;
#define FD_STATUS_PAIR_OFF_FOOTPRINT sizeof(fd_status_pair_off_t)
#define FD_STATUS_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_slot_delta {
  ulong slot;
  uchar is_root;
  ulong slot_delta_vec_len;
  fd_status_pair_t * slot_delta_vec;
};
typedef struct fd_slot_delta fd_slot_delta_t;
#define FD_SLOT_DELTA_FOOTPRINT sizeof(fd_slot_delta_t)
#define FD_SLOT_DELTA_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_slot_delta_off {
  uint slot_off;
  uint is_root_off;
  uint slot_delta_vec_off;
};
typedef struct fd_slot_delta_off fd_slot_delta_off_t;
#define FD_SLOT_DELTA_OFF_FOOTPRINT sizeof(fd_slot_delta_off_t)
#define FD_SLOT_DELTA_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_bank_slot_deltas {
  ulong slot_deltas_len;
  fd_slot_delta_t * slot_deltas;
};
typedef struct fd_bank_slot_deltas fd_bank_slot_deltas_t;
#define FD_BANK_SLOT_DELTAS_FOOTPRINT sizeof(fd_bank_slot_deltas_t)
#define FD_BANK_SLOT_DELTAS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_bank_slot_deltas_off {
  uint slot_deltas_off;
};
typedef struct fd_bank_slot_deltas_off fd_bank_slot_deltas_off_t;
#define FD_BANK_SLOT_DELTAS_OFF_FOOTPRINT sizeof(fd_bank_slot_deltas_off_t)
#define FD_BANK_SLOT_DELTAS_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/7117ed9653ce19e8b2dea108eff1f3eb6a3378a7/runtime/src/bank/partitioned_epoch_rewards/mod.rs#L85 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_pubkey_rewardinfo_pair {
  fd_pubkey_t pubkey;
  fd_reward_info_t reward_info;
};
typedef struct fd_pubkey_rewardinfo_pair fd_pubkey_rewardinfo_pair_t;
#define FD_PUBKEY_REWARDINFO_PAIR_FOOTPRINT sizeof(fd_pubkey_rewardinfo_pair_t)
#define FD_PUBKEY_REWARDINFO_PAIR_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_pubkey_rewardinfo_pair_off {
  uint pubkey_off;
  uint reward_info_off;
};
typedef struct fd_pubkey_rewardinfo_pair_off fd_pubkey_rewardinfo_pair_off_t;
#define FD_PUBKEY_REWARDINFO_PAIR_OFF_FOOTPRINT sizeof(fd_pubkey_rewardinfo_pair_off_t)
#define FD_PUBKEY_REWARDINFO_PAIR_OFF_ALIGN (8UL)

/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_optional_account {
  fd_solana_account_t * account;
};
typedef struct fd_optional_account fd_optional_account_t;
#define FD_OPTIONAL_ACCOUNT_FOOTPRINT sizeof(fd_optional_account_t)
#define FD_OPTIONAL_ACCOUNT_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_optional_account_off {
  uint account_off;
};
typedef struct fd_optional_account_off fd_optional_account_off_t;
#define FD_OPTIONAL_ACCOUNT_OFF_FOOTPRINT sizeof(fd_optional_account_off_t)
#define FD_OPTIONAL_ACCOUNT_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/cbc8320d35358da14d79ebcada4dfb6756ffac79/programs/stake/src/points.rs#L27 */
/* Encoded Size: Fixed (25 bytes) */
struct __attribute__((aligned(8UL))) fd_calculated_stake_points {
  uint128 points;
  ulong new_credits_observed;
  uchar force_credits_update_with_skipped_reward;
};
typedef struct fd_calculated_stake_points fd_calculated_stake_points_t;
#define FD_CALCULATED_STAKE_POINTS_FOOTPRINT sizeof(fd_calculated_stake_points_t)
#define FD_CALCULATED_STAKE_POINTS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_calculated_stake_points_off {
  uint points_off;
  uint new_credits_observed_off;
  uint force_credits_update_with_skipped_reward_off;
};
typedef struct fd_calculated_stake_points_off fd_calculated_stake_points_off_t;
#define FD_CALCULATED_STAKE_POINTS_OFF_FOOTPRINT sizeof(fd_calculated_stake_points_off_t)
#define FD_CALCULATED_STAKE_POINTS_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/cbc8320d35358da14d79ebcada4dfb6756ffac79/programs/stake/src/rewards.rs#L24 */
/* Encoded Size: Fixed (24 bytes) */
struct __attribute__((aligned(8UL))) fd_calculated_stake_rewards {
  ulong staker_rewards;
  ulong voter_rewards;
  ulong new_credits_observed;
};
typedef struct fd_calculated_stake_rewards fd_calculated_stake_rewards_t;
#define FD_CALCULATED_STAKE_REWARDS_FOOTPRINT sizeof(fd_calculated_stake_rewards_t)
#define FD_CALCULATED_STAKE_REWARDS_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_calculated_stake_rewards_off {
  uint staker_rewards_off;
  uint voter_rewards_off;
  uint new_credits_observed_off;
};
typedef struct fd_calculated_stake_rewards_off fd_calculated_stake_rewards_off_t;
#define FD_CALCULATED_STAKE_REWARDS_OFF_FOOTPRINT sizeof(fd_calculated_stake_rewards_off_t)
#define FD_CALCULATED_STAKE_REWARDS_OFF_ALIGN (8UL)

/* https://github.com/anza-xyz/agave/blob/v2.0.3/ledger/src/blockstore_meta.rs#L150-L156 */
/* Encoded Size: Dynamic */
struct __attribute__((aligned(8UL))) fd_duplicate_slot_proof {
  ulong shred1_len;
  uchar* shred1;
  ulong shred2_len;
  uchar* shred2;
};
typedef struct fd_duplicate_slot_proof fd_duplicate_slot_proof_t;
#define FD_DUPLICATE_SLOT_PROOF_FOOTPRINT sizeof(fd_duplicate_slot_proof_t)
#define FD_DUPLICATE_SLOT_PROOF_ALIGN (8UL)

struct __attribute__((aligned(8UL))) fd_duplicate_slot_proof_off {
  uint shred1_off;
  uint shred2_off;
};
typedef struct fd_duplicate_slot_proof_off fd_duplicate_slot_proof_off_t;
#define FD_DUPLICATE_SLOT_PROOF_OFF_FOOTPRINT sizeof(fd_duplicate_slot_proof_off_t)
#define FD_DUPLICATE_SLOT_PROOF_OFF_ALIGN (8UL)


FD_PROTOTYPES_BEGIN

void fd_hash_new( fd_hash_t * self );
int fd_hash_decode( fd_hash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_hash_decode_unsafe( fd_hash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_encode( fd_hash_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_hash_destroy( fd_hash_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_hash_walk( void * w, fd_hash_t const * self, fd_types_walk_fn_t fun, const char * name, uint level );
ulong fd_hash_size( fd_hash_t const * self );
ulong fd_hash_footprint( void );
ulong fd_hash_align( void );

void fd_signature_new( fd_signature_t * self );
int fd_signature_decode( fd_signature_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_signature_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_signature_decode_unsafe( fd_signature_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_signature_encode( fd_signature_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_signature_destroy( fd_signature_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_signature_walk( void * w, fd_signature_t const * self, fd_types_walk_fn_t fun, const char * name, uint level );
ulong fd_signature_size( fd_signature_t const * self );
ulong fd_signature_footprint( void );
ulong fd_signature_align( void );

void fd_gossip_ip4_addr_new( fd_gossip_ip4_addr_t * self );
int fd_gossip_ip4_addr_decode( fd_gossip_ip4_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ip4_addr_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_ip4_addr_decode_unsafe( fd_gossip_ip4_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ip4_addr_encode( fd_gossip_ip4_addr_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_ip4_addr_destroy( fd_gossip_ip4_addr_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_ip4_addr_walk( void * w, fd_gossip_ip4_addr_t const * self, fd_types_walk_fn_t fun, const char * name, uint level );
ulong fd_gossip_ip4_addr_size( fd_gossip_ip4_addr_t const * self );
ulong fd_gossip_ip4_addr_footprint( void );
ulong fd_gossip_ip4_addr_align( void );

void fd_gossip_ip6_addr_new( fd_gossip_ip6_addr_t * self );
int fd_gossip_ip6_addr_decode( fd_gossip_ip6_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ip6_addr_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_ip6_addr_decode_unsafe( fd_gossip_ip6_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ip6_addr_encode( fd_gossip_ip6_addr_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_ip6_addr_destroy( fd_gossip_ip6_addr_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_ip6_addr_walk( void * w, fd_gossip_ip6_addr_t const * self, fd_types_walk_fn_t fun, const char * name, uint level );
ulong fd_gossip_ip6_addr_size( fd_gossip_ip6_addr_t const * self );
ulong fd_gossip_ip6_addr_footprint( void );
ulong fd_gossip_ip6_addr_align( void );

void fd_feature_new( fd_feature_t * self );
int fd_feature_decode( fd_feature_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_feature_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_feature_decode_unsafe( fd_feature_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_feature_decode_offsets( fd_feature_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_feature_encode( fd_feature_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_feature_destroy( fd_feature_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_feature_walk( void * w, fd_feature_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_feature_size( fd_feature_t const * self );
ulong fd_feature_footprint( void );
ulong fd_feature_align( void );

void fd_fee_calculator_new( fd_fee_calculator_t * self );
int fd_fee_calculator_decode( fd_fee_calculator_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_calculator_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_fee_calculator_decode_unsafe( fd_fee_calculator_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_calculator_decode_offsets( fd_fee_calculator_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_calculator_encode( fd_fee_calculator_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_fee_calculator_destroy( fd_fee_calculator_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_fee_calculator_walk( void * w, fd_fee_calculator_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_fee_calculator_size( fd_fee_calculator_t const * self );
ulong fd_fee_calculator_footprint( void );
ulong fd_fee_calculator_align( void );
int fd_fee_calculator_decode_archival( fd_fee_calculator_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_calculator_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_fee_calculator_decode_archival_unsafe( fd_fee_calculator_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_calculator_encode_archival( fd_fee_calculator_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_hash_age_new( fd_hash_age_t * self );
int fd_hash_age_decode( fd_hash_age_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_age_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_hash_age_decode_unsafe( fd_hash_age_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_age_decode_offsets( fd_hash_age_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_age_encode( fd_hash_age_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_hash_age_destroy( fd_hash_age_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_hash_age_walk( void * w, fd_hash_age_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_hash_age_size( fd_hash_age_t const * self );
ulong fd_hash_age_footprint( void );
ulong fd_hash_age_align( void );
int fd_hash_age_decode_archival( fd_hash_age_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_age_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_hash_age_decode_archival_unsafe( fd_hash_age_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_age_encode_archival( fd_hash_age_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_hash_hash_age_pair_new( fd_hash_hash_age_pair_t * self );
int fd_hash_hash_age_pair_decode( fd_hash_hash_age_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_hash_age_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_hash_hash_age_pair_decode_unsafe( fd_hash_hash_age_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_hash_age_pair_decode_offsets( fd_hash_hash_age_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_hash_age_pair_encode( fd_hash_hash_age_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_hash_hash_age_pair_destroy( fd_hash_hash_age_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_hash_hash_age_pair_walk( void * w, fd_hash_hash_age_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_hash_hash_age_pair_size( fd_hash_hash_age_pair_t const * self );
ulong fd_hash_hash_age_pair_footprint( void );
ulong fd_hash_hash_age_pair_align( void );
int fd_hash_hash_age_pair_decode_archival( fd_hash_hash_age_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_hash_age_pair_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_hash_hash_age_pair_decode_archival_unsafe( fd_hash_hash_age_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hash_hash_age_pair_encode_archival( fd_hash_hash_age_pair_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_block_hash_vec_new( fd_block_hash_vec_t * self );
int fd_block_hash_vec_decode( fd_block_hash_vec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_vec_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_block_hash_vec_decode_unsafe( fd_block_hash_vec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_vec_decode_offsets( fd_block_hash_vec_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_vec_encode( fd_block_hash_vec_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_block_hash_vec_destroy( fd_block_hash_vec_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_block_hash_vec_walk( void * w, fd_block_hash_vec_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_block_hash_vec_size( fd_block_hash_vec_t const * self );
ulong fd_block_hash_vec_footprint( void );
ulong fd_block_hash_vec_align( void );

void fd_block_hash_queue_new( fd_block_hash_queue_t * self );
int fd_block_hash_queue_decode( fd_block_hash_queue_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_queue_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_block_hash_queue_decode_unsafe( fd_block_hash_queue_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_queue_decode_offsets( fd_block_hash_queue_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_queue_encode( fd_block_hash_queue_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_block_hash_queue_destroy( fd_block_hash_queue_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_block_hash_queue_walk( void * w, fd_block_hash_queue_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_block_hash_queue_size( fd_block_hash_queue_t const * self );
ulong fd_block_hash_queue_footprint( void );
ulong fd_block_hash_queue_align( void );
int fd_block_hash_queue_decode_archival( fd_block_hash_queue_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_queue_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_block_hash_queue_decode_archival_unsafe( fd_block_hash_queue_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_hash_queue_encode_archival( fd_block_hash_queue_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_fee_rate_governor_new( fd_fee_rate_governor_t * self );
int fd_fee_rate_governor_decode( fd_fee_rate_governor_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_rate_governor_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_fee_rate_governor_decode_unsafe( fd_fee_rate_governor_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_rate_governor_decode_offsets( fd_fee_rate_governor_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_rate_governor_encode( fd_fee_rate_governor_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_fee_rate_governor_destroy( fd_fee_rate_governor_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_fee_rate_governor_walk( void * w, fd_fee_rate_governor_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_fee_rate_governor_size( fd_fee_rate_governor_t const * self );
ulong fd_fee_rate_governor_footprint( void );
ulong fd_fee_rate_governor_align( void );
int fd_fee_rate_governor_decode_archival( fd_fee_rate_governor_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_rate_governor_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_fee_rate_governor_decode_archival_unsafe( fd_fee_rate_governor_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_fee_rate_governor_encode_archival( fd_fee_rate_governor_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_slot_pair_new( fd_slot_pair_t * self );
int fd_slot_pair_decode( fd_slot_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_pair_decode_unsafe( fd_slot_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_pair_decode_offsets( fd_slot_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_pair_encode( fd_slot_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_pair_destroy( fd_slot_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_pair_walk( void * w, fd_slot_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_pair_size( fd_slot_pair_t const * self );
ulong fd_slot_pair_footprint( void );
ulong fd_slot_pair_align( void );

void fd_hard_forks_new( fd_hard_forks_t * self );
int fd_hard_forks_decode( fd_hard_forks_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hard_forks_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_hard_forks_decode_unsafe( fd_hard_forks_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hard_forks_decode_offsets( fd_hard_forks_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_hard_forks_encode( fd_hard_forks_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_hard_forks_destroy( fd_hard_forks_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_hard_forks_walk( void * w, fd_hard_forks_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_hard_forks_size( fd_hard_forks_t const * self );
ulong fd_hard_forks_footprint( void );
ulong fd_hard_forks_align( void );

void fd_inflation_new( fd_inflation_t * self );
int fd_inflation_decode( fd_inflation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_inflation_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_inflation_decode_unsafe( fd_inflation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_inflation_decode_offsets( fd_inflation_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_inflation_encode( fd_inflation_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_inflation_destroy( fd_inflation_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_inflation_walk( void * w, fd_inflation_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_inflation_size( fd_inflation_t const * self );
ulong fd_inflation_footprint( void );
ulong fd_inflation_align( void );
int fd_inflation_decode_archival( fd_inflation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_inflation_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_inflation_decode_archival_unsafe( fd_inflation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_inflation_encode_archival( fd_inflation_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_rent_new( fd_rent_t * self );
int fd_rent_decode( fd_rent_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_rent_decode_unsafe( fd_rent_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_decode_offsets( fd_rent_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_encode( fd_rent_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_rent_destroy( fd_rent_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_rent_walk( void * w, fd_rent_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_rent_size( fd_rent_t const * self );
ulong fd_rent_footprint( void );
ulong fd_rent_align( void );
int fd_rent_decode_archival( fd_rent_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_rent_decode_archival_unsafe( fd_rent_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_encode_archival( fd_rent_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_epoch_schedule_new( fd_epoch_schedule_t * self );
int fd_epoch_schedule_decode( fd_epoch_schedule_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_schedule_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_schedule_decode_unsafe( fd_epoch_schedule_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_schedule_decode_offsets( fd_epoch_schedule_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_schedule_encode( fd_epoch_schedule_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_epoch_schedule_destroy( fd_epoch_schedule_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_epoch_schedule_walk( void * w, fd_epoch_schedule_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_epoch_schedule_size( fd_epoch_schedule_t const * self );
ulong fd_epoch_schedule_footprint( void );
ulong fd_epoch_schedule_align( void );
int fd_epoch_schedule_decode_archival( fd_epoch_schedule_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_schedule_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_schedule_decode_archival_unsafe( fd_epoch_schedule_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_schedule_encode_archival( fd_epoch_schedule_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_rent_collector_new( fd_rent_collector_t * self );
int fd_rent_collector_decode( fd_rent_collector_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_collector_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_rent_collector_decode_unsafe( fd_rent_collector_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_collector_decode_offsets( fd_rent_collector_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rent_collector_encode( fd_rent_collector_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_rent_collector_destroy( fd_rent_collector_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_rent_collector_walk( void * w, fd_rent_collector_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_rent_collector_size( fd_rent_collector_t const * self );
ulong fd_rent_collector_footprint( void );
ulong fd_rent_collector_align( void );

void fd_stake_history_entry_new( fd_stake_history_entry_t * self );
int fd_stake_history_entry_decode( fd_stake_history_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_entry_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_history_entry_decode_unsafe( fd_stake_history_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_entry_decode_offsets( fd_stake_history_entry_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_entry_encode( fd_stake_history_entry_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_history_entry_destroy( fd_stake_history_entry_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_history_entry_walk( void * w, fd_stake_history_entry_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_history_entry_size( fd_stake_history_entry_t const * self );
ulong fd_stake_history_entry_footprint( void );
ulong fd_stake_history_entry_align( void );
int fd_stake_history_entry_decode_archival( fd_stake_history_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_entry_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_history_entry_decode_archival_unsafe( fd_stake_history_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_entry_encode_archival( fd_stake_history_entry_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_stake_history_new( fd_stake_history_t * self );
int fd_stake_history_decode( fd_stake_history_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_history_decode_unsafe( fd_stake_history_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_decode_offsets( fd_stake_history_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_encode( fd_stake_history_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_history_destroy( fd_stake_history_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_history_walk( void * w, fd_stake_history_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_history_size( fd_stake_history_t const * self );
ulong fd_stake_history_footprint( void );
ulong fd_stake_history_align( void );
int fd_stake_history_decode_archival( fd_stake_history_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_history_decode_archival_unsafe( fd_stake_history_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_history_encode_archival( fd_stake_history_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_solana_account_new( fd_solana_account_t * self );
int fd_solana_account_decode( fd_solana_account_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_account_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_solana_account_decode_unsafe( fd_solana_account_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_account_decode_offsets( fd_solana_account_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_account_encode( fd_solana_account_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_solana_account_destroy( fd_solana_account_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_solana_account_walk( void * w, fd_solana_account_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_solana_account_size( fd_solana_account_t const * self );
ulong fd_solana_account_footprint( void );
ulong fd_solana_account_align( void );

void fd_vote_accounts_pair_new( fd_vote_accounts_pair_t * self );
int fd_vote_accounts_pair_decode( fd_vote_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_accounts_pair_decode_unsafe( fd_vote_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_pair_decode_offsets( fd_vote_accounts_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_pair_encode( fd_vote_accounts_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_accounts_pair_destroy( fd_vote_accounts_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_accounts_pair_walk( void * w, fd_vote_accounts_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_accounts_pair_size( fd_vote_accounts_pair_t const * self );
ulong fd_vote_accounts_pair_footprint( void );
ulong fd_vote_accounts_pair_align( void );
int fd_vote_accounts_pair_decode_archival( fd_vote_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_pair_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_accounts_pair_decode_archival_unsafe( fd_vote_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_pair_encode_archival( fd_vote_accounts_pair_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_vote_accounts_new( fd_vote_accounts_t * self );
int fd_vote_accounts_decode( fd_vote_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_accounts_decode_unsafe( fd_vote_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_decode_offsets( fd_vote_accounts_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_encode( fd_vote_accounts_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_accounts_destroy( fd_vote_accounts_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_accounts_walk( void * w, fd_vote_accounts_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_accounts_size( fd_vote_accounts_t const * self );
ulong fd_vote_accounts_footprint( void );
ulong fd_vote_accounts_align( void );
int fd_vote_accounts_decode_archival( fd_vote_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_accounts_decode_archival_unsafe( fd_vote_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_accounts_encode_archival( fd_vote_accounts_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_stake_accounts_pair_new( fd_stake_accounts_pair_t * self );
int fd_stake_accounts_pair_decode( fd_stake_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_accounts_pair_decode_unsafe( fd_stake_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_pair_decode_offsets( fd_stake_accounts_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_pair_encode( fd_stake_accounts_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_accounts_pair_destroy( fd_stake_accounts_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_accounts_pair_walk( void * w, fd_stake_accounts_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_accounts_pair_size( fd_stake_accounts_pair_t const * self );
ulong fd_stake_accounts_pair_footprint( void );
ulong fd_stake_accounts_pair_align( void );
int fd_stake_accounts_pair_decode_archival( fd_stake_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_pair_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_accounts_pair_decode_archival_unsafe( fd_stake_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_pair_encode_archival( fd_stake_accounts_pair_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_stake_accounts_new( fd_stake_accounts_t * self );
int fd_stake_accounts_decode( fd_stake_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_accounts_decode_unsafe( fd_stake_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_decode_offsets( fd_stake_accounts_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_encode( fd_stake_accounts_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_accounts_destroy( fd_stake_accounts_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_accounts_walk( void * w, fd_stake_accounts_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_accounts_size( fd_stake_accounts_t const * self );
ulong fd_stake_accounts_footprint( void );
ulong fd_stake_accounts_align( void );
int fd_stake_accounts_decode_archival( fd_stake_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_accounts_decode_archival_unsafe( fd_stake_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_accounts_encode_archival( fd_stake_accounts_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_stake_weight_new( fd_stake_weight_t * self );
int fd_stake_weight_decode( fd_stake_weight_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_weight_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_weight_decode_unsafe( fd_stake_weight_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_weight_decode_offsets( fd_stake_weight_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_weight_encode( fd_stake_weight_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_weight_destroy( fd_stake_weight_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_weight_walk( void * w, fd_stake_weight_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_weight_size( fd_stake_weight_t const * self );
ulong fd_stake_weight_footprint( void );
ulong fd_stake_weight_align( void );

void fd_stake_weights_new( fd_stake_weights_t * self );
int fd_stake_weights_decode( fd_stake_weights_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_weights_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_weights_decode_unsafe( fd_stake_weights_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_weights_decode_offsets( fd_stake_weights_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_weights_encode( fd_stake_weights_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_weights_destroy( fd_stake_weights_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_weights_walk( void * w, fd_stake_weights_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_weights_size( fd_stake_weights_t const * self );
ulong fd_stake_weights_footprint( void );
ulong fd_stake_weights_align( void );

void fd_delegation_new( fd_delegation_t * self );
int fd_delegation_decode( fd_delegation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_delegation_decode_unsafe( fd_delegation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_decode_offsets( fd_delegation_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_encode( fd_delegation_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_delegation_destroy( fd_delegation_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_delegation_walk( void * w, fd_delegation_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_delegation_size( fd_delegation_t const * self );
ulong fd_delegation_footprint( void );
ulong fd_delegation_align( void );
int fd_delegation_decode_archival( fd_delegation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_delegation_decode_archival_unsafe( fd_delegation_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_encode_archival( fd_delegation_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_delegation_pair_new( fd_delegation_pair_t * self );
int fd_delegation_pair_decode( fd_delegation_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_delegation_pair_decode_unsafe( fd_delegation_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_pair_decode_offsets( fd_delegation_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_pair_encode( fd_delegation_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_delegation_pair_destroy( fd_delegation_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_delegation_pair_walk( void * w, fd_delegation_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_delegation_pair_size( fd_delegation_pair_t const * self );
ulong fd_delegation_pair_footprint( void );
ulong fd_delegation_pair_align( void );
int fd_delegation_pair_decode_archival( fd_delegation_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_pair_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_delegation_pair_decode_archival_unsafe( fd_delegation_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_delegation_pair_encode_archival( fd_delegation_pair_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_stake_new( fd_stake_t * self );
int fd_stake_decode( fd_stake_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_decode_unsafe( fd_stake_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_decode_offsets( fd_stake_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_encode( fd_stake_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_destroy( fd_stake_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_walk( void * w, fd_stake_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_size( fd_stake_t const * self );
ulong fd_stake_footprint( void );
ulong fd_stake_align( void );

void fd_epoch_info_pair_new( fd_epoch_info_pair_t * self );
int fd_epoch_info_pair_decode( fd_epoch_info_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_info_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_info_pair_decode_unsafe( fd_epoch_info_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_info_pair_decode_offsets( fd_epoch_info_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_info_pair_encode( fd_epoch_info_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_epoch_info_pair_destroy( fd_epoch_info_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_epoch_info_pair_walk( void * w, fd_epoch_info_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_epoch_info_pair_size( fd_epoch_info_pair_t const * self );
ulong fd_epoch_info_pair_footprint( void );
ulong fd_epoch_info_pair_align( void );

void fd_epoch_info_new( fd_epoch_info_t * self );
int fd_epoch_info_decode( fd_epoch_info_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_info_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_info_decode_unsafe( fd_epoch_info_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_info_decode_offsets( fd_epoch_info_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_info_encode( fd_epoch_info_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_epoch_info_destroy( fd_epoch_info_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_epoch_info_walk( void * w, fd_epoch_info_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_epoch_info_size( fd_epoch_info_t const * self );
ulong fd_epoch_info_footprint( void );
ulong fd_epoch_info_align( void );

void fd_stake_pair_new( fd_stake_pair_t * self );
int fd_stake_pair_decode( fd_stake_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_pair_decode_unsafe( fd_stake_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_pair_decode_offsets( fd_stake_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_pair_encode( fd_stake_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_pair_destroy( fd_stake_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_pair_walk( void * w, fd_stake_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_pair_size( fd_stake_pair_t const * self );
ulong fd_stake_pair_footprint( void );
ulong fd_stake_pair_align( void );

void fd_stakes_new( fd_stakes_t * self );
int fd_stakes_decode( fd_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stakes_decode_unsafe( fd_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_decode_offsets( fd_stakes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_encode( fd_stakes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stakes_destroy( fd_stakes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stakes_walk( void * w, fd_stakes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stakes_size( fd_stakes_t const * self );
ulong fd_stakes_footprint( void );
ulong fd_stakes_align( void );
int fd_stakes_decode_archival( fd_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stakes_decode_archival_unsafe( fd_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_encode_archival( fd_stakes_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_stakes_stake_new( fd_stakes_stake_t * self );
int fd_stakes_stake_decode( fd_stakes_stake_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_stake_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stakes_stake_decode_unsafe( fd_stakes_stake_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_stake_decode_offsets( fd_stakes_stake_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stakes_stake_encode( fd_stakes_stake_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stakes_stake_destroy( fd_stakes_stake_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stakes_stake_walk( void * w, fd_stakes_stake_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stakes_stake_size( fd_stakes_stake_t const * self );
ulong fd_stakes_stake_footprint( void );
ulong fd_stakes_stake_align( void );

void fd_bank_incremental_snapshot_persistence_new( fd_bank_incremental_snapshot_persistence_t * self );
int fd_bank_incremental_snapshot_persistence_decode( fd_bank_incremental_snapshot_persistence_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_incremental_snapshot_persistence_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bank_incremental_snapshot_persistence_decode_unsafe( fd_bank_incremental_snapshot_persistence_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_incremental_snapshot_persistence_decode_offsets( fd_bank_incremental_snapshot_persistence_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_incremental_snapshot_persistence_encode( fd_bank_incremental_snapshot_persistence_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bank_incremental_snapshot_persistence_destroy( fd_bank_incremental_snapshot_persistence_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bank_incremental_snapshot_persistence_walk( void * w, fd_bank_incremental_snapshot_persistence_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bank_incremental_snapshot_persistence_size( fd_bank_incremental_snapshot_persistence_t const * self );
ulong fd_bank_incremental_snapshot_persistence_footprint( void );
ulong fd_bank_incremental_snapshot_persistence_align( void );

void fd_node_vote_accounts_new( fd_node_vote_accounts_t * self );
int fd_node_vote_accounts_decode( fd_node_vote_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_node_vote_accounts_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_node_vote_accounts_decode_unsafe( fd_node_vote_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_node_vote_accounts_decode_offsets( fd_node_vote_accounts_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_node_vote_accounts_encode( fd_node_vote_accounts_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_node_vote_accounts_destroy( fd_node_vote_accounts_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_node_vote_accounts_walk( void * w, fd_node_vote_accounts_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_node_vote_accounts_size( fd_node_vote_accounts_t const * self );
ulong fd_node_vote_accounts_footprint( void );
ulong fd_node_vote_accounts_align( void );

void fd_pubkey_node_vote_accounts_pair_new( fd_pubkey_node_vote_accounts_pair_t * self );
int fd_pubkey_node_vote_accounts_pair_decode( fd_pubkey_node_vote_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_node_vote_accounts_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_pubkey_node_vote_accounts_pair_decode_unsafe( fd_pubkey_node_vote_accounts_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_node_vote_accounts_pair_decode_offsets( fd_pubkey_node_vote_accounts_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_node_vote_accounts_pair_encode( fd_pubkey_node_vote_accounts_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_pubkey_node_vote_accounts_pair_destroy( fd_pubkey_node_vote_accounts_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_pubkey_node_vote_accounts_pair_walk( void * w, fd_pubkey_node_vote_accounts_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_pubkey_node_vote_accounts_pair_size( fd_pubkey_node_vote_accounts_pair_t const * self );
ulong fd_pubkey_node_vote_accounts_pair_footprint( void );
ulong fd_pubkey_node_vote_accounts_pair_align( void );

void fd_pubkey_pubkey_pair_new( fd_pubkey_pubkey_pair_t * self );
int fd_pubkey_pubkey_pair_decode( fd_pubkey_pubkey_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_pubkey_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_pubkey_pubkey_pair_decode_unsafe( fd_pubkey_pubkey_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_pubkey_pair_decode_offsets( fd_pubkey_pubkey_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_pubkey_pair_encode( fd_pubkey_pubkey_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_pubkey_pubkey_pair_destroy( fd_pubkey_pubkey_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_pubkey_pubkey_pair_walk( void * w, fd_pubkey_pubkey_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_pubkey_pubkey_pair_size( fd_pubkey_pubkey_pair_t const * self );
ulong fd_pubkey_pubkey_pair_footprint( void );
ulong fd_pubkey_pubkey_pair_align( void );

void fd_epoch_stakes_new( fd_epoch_stakes_t * self );
int fd_epoch_stakes_decode( fd_epoch_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_stakes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_stakes_decode_unsafe( fd_epoch_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_stakes_decode_offsets( fd_epoch_stakes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_stakes_encode( fd_epoch_stakes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_epoch_stakes_destroy( fd_epoch_stakes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_epoch_stakes_walk( void * w, fd_epoch_stakes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_epoch_stakes_size( fd_epoch_stakes_t const * self );
ulong fd_epoch_stakes_footprint( void );
ulong fd_epoch_stakes_align( void );

void fd_epoch_epoch_stakes_pair_new( fd_epoch_epoch_stakes_pair_t * self );
int fd_epoch_epoch_stakes_pair_decode( fd_epoch_epoch_stakes_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_epoch_stakes_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_epoch_stakes_pair_decode_unsafe( fd_epoch_epoch_stakes_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_epoch_stakes_pair_decode_offsets( fd_epoch_epoch_stakes_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_epoch_stakes_pair_encode( fd_epoch_epoch_stakes_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_epoch_epoch_stakes_pair_destroy( fd_epoch_epoch_stakes_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_epoch_epoch_stakes_pair_walk( void * w, fd_epoch_epoch_stakes_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_epoch_epoch_stakes_pair_size( fd_epoch_epoch_stakes_pair_t const * self );
ulong fd_epoch_epoch_stakes_pair_footprint( void );
ulong fd_epoch_epoch_stakes_pair_align( void );

void fd_pubkey_u64_pair_new( fd_pubkey_u64_pair_t * self );
int fd_pubkey_u64_pair_decode( fd_pubkey_u64_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_u64_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_pubkey_u64_pair_decode_unsafe( fd_pubkey_u64_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_u64_pair_decode_offsets( fd_pubkey_u64_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_u64_pair_encode( fd_pubkey_u64_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_pubkey_u64_pair_destroy( fd_pubkey_u64_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_pubkey_u64_pair_walk( void * w, fd_pubkey_u64_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_pubkey_u64_pair_size( fd_pubkey_u64_pair_t const * self );
ulong fd_pubkey_u64_pair_footprint( void );
ulong fd_pubkey_u64_pair_align( void );

void fd_unused_accounts_new( fd_unused_accounts_t * self );
int fd_unused_accounts_decode( fd_unused_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_unused_accounts_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_unused_accounts_decode_unsafe( fd_unused_accounts_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_unused_accounts_decode_offsets( fd_unused_accounts_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_unused_accounts_encode( fd_unused_accounts_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_unused_accounts_destroy( fd_unused_accounts_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_unused_accounts_walk( void * w, fd_unused_accounts_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_unused_accounts_size( fd_unused_accounts_t const * self );
ulong fd_unused_accounts_footprint( void );
ulong fd_unused_accounts_align( void );

void fd_deserializable_versioned_bank_new( fd_deserializable_versioned_bank_t * self );
int fd_deserializable_versioned_bank_decode( fd_deserializable_versioned_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_deserializable_versioned_bank_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_deserializable_versioned_bank_decode_unsafe( fd_deserializable_versioned_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_deserializable_versioned_bank_decode_offsets( fd_deserializable_versioned_bank_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_deserializable_versioned_bank_encode( fd_deserializable_versioned_bank_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_deserializable_versioned_bank_destroy( fd_deserializable_versioned_bank_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_deserializable_versioned_bank_walk( void * w, fd_deserializable_versioned_bank_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_deserializable_versioned_bank_size( fd_deserializable_versioned_bank_t const * self );
ulong fd_deserializable_versioned_bank_footprint( void );
ulong fd_deserializable_versioned_bank_align( void );

void fd_bank_hash_stats_new( fd_bank_hash_stats_t * self );
int fd_bank_hash_stats_decode( fd_bank_hash_stats_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_hash_stats_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bank_hash_stats_decode_unsafe( fd_bank_hash_stats_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_hash_stats_decode_offsets( fd_bank_hash_stats_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_hash_stats_encode( fd_bank_hash_stats_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bank_hash_stats_destroy( fd_bank_hash_stats_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bank_hash_stats_walk( void * w, fd_bank_hash_stats_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bank_hash_stats_size( fd_bank_hash_stats_t const * self );
ulong fd_bank_hash_stats_footprint( void );
ulong fd_bank_hash_stats_align( void );

void fd_bank_hash_info_new( fd_bank_hash_info_t * self );
int fd_bank_hash_info_decode( fd_bank_hash_info_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_hash_info_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bank_hash_info_decode_unsafe( fd_bank_hash_info_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_hash_info_decode_offsets( fd_bank_hash_info_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_hash_info_encode( fd_bank_hash_info_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bank_hash_info_destroy( fd_bank_hash_info_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bank_hash_info_walk( void * w, fd_bank_hash_info_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bank_hash_info_size( fd_bank_hash_info_t const * self );
ulong fd_bank_hash_info_footprint( void );
ulong fd_bank_hash_info_align( void );

void fd_slot_map_pair_new( fd_slot_map_pair_t * self );
int fd_slot_map_pair_decode( fd_slot_map_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_map_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_map_pair_decode_unsafe( fd_slot_map_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_map_pair_decode_offsets( fd_slot_map_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_map_pair_encode( fd_slot_map_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_map_pair_destroy( fd_slot_map_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_map_pair_walk( void * w, fd_slot_map_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_map_pair_size( fd_slot_map_pair_t const * self );
ulong fd_slot_map_pair_footprint( void );
ulong fd_slot_map_pair_align( void );

void fd_snapshot_acc_vec_new( fd_snapshot_acc_vec_t * self );
int fd_snapshot_acc_vec_decode( fd_snapshot_acc_vec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_snapshot_acc_vec_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_snapshot_acc_vec_decode_unsafe( fd_snapshot_acc_vec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_snapshot_acc_vec_decode_offsets( fd_snapshot_acc_vec_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_snapshot_acc_vec_encode( fd_snapshot_acc_vec_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_snapshot_acc_vec_destroy( fd_snapshot_acc_vec_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_snapshot_acc_vec_walk( void * w, fd_snapshot_acc_vec_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_snapshot_acc_vec_size( fd_snapshot_acc_vec_t const * self );
ulong fd_snapshot_acc_vec_footprint( void );
ulong fd_snapshot_acc_vec_align( void );

void fd_snapshot_slot_acc_vecs_new( fd_snapshot_slot_acc_vecs_t * self );
int fd_snapshot_slot_acc_vecs_decode( fd_snapshot_slot_acc_vecs_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_snapshot_slot_acc_vecs_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_snapshot_slot_acc_vecs_decode_unsafe( fd_snapshot_slot_acc_vecs_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_snapshot_slot_acc_vecs_decode_offsets( fd_snapshot_slot_acc_vecs_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_snapshot_slot_acc_vecs_encode( fd_snapshot_slot_acc_vecs_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_snapshot_slot_acc_vecs_destroy( fd_snapshot_slot_acc_vecs_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_snapshot_slot_acc_vecs_walk( void * w, fd_snapshot_slot_acc_vecs_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_snapshot_slot_acc_vecs_size( fd_snapshot_slot_acc_vecs_t const * self );
ulong fd_snapshot_slot_acc_vecs_footprint( void );
ulong fd_snapshot_slot_acc_vecs_align( void );

void fd_reward_type_new_disc( fd_reward_type_t * self, uint discriminant );
void fd_reward_type_new( fd_reward_type_t * self );
int fd_reward_type_decode( fd_reward_type_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_reward_type_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_reward_type_decode_unsafe( fd_reward_type_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_reward_type_encode( fd_reward_type_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_reward_type_destroy( fd_reward_type_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_reward_type_walk( void * w, fd_reward_type_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_reward_type_size( fd_reward_type_t const * self );
ulong fd_reward_type_footprint( void );
ulong fd_reward_type_align( void );

FD_FN_PURE uchar fd_reward_type_is_fee( fd_reward_type_t const * self );
FD_FN_PURE uchar fd_reward_type_is_rent( fd_reward_type_t const * self );
FD_FN_PURE uchar fd_reward_type_is_staking( fd_reward_type_t const * self );
FD_FN_PURE uchar fd_reward_type_is_voting( fd_reward_type_t const * self );
enum {
fd_reward_type_enum_fee = 0,
fd_reward_type_enum_rent = 1,
fd_reward_type_enum_staking = 2,
fd_reward_type_enum_voting = 3,
}; 
void fd_solana_accounts_db_fields_new( fd_solana_accounts_db_fields_t * self );
int fd_solana_accounts_db_fields_decode( fd_solana_accounts_db_fields_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_accounts_db_fields_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_solana_accounts_db_fields_decode_unsafe( fd_solana_accounts_db_fields_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_accounts_db_fields_decode_offsets( fd_solana_accounts_db_fields_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_accounts_db_fields_encode( fd_solana_accounts_db_fields_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_solana_accounts_db_fields_destroy( fd_solana_accounts_db_fields_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_solana_accounts_db_fields_walk( void * w, fd_solana_accounts_db_fields_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_solana_accounts_db_fields_size( fd_solana_accounts_db_fields_t const * self );
ulong fd_solana_accounts_db_fields_footprint( void );
ulong fd_solana_accounts_db_fields_align( void );

void fd_versioned_epoch_stakes_current_new( fd_versioned_epoch_stakes_current_t * self );
int fd_versioned_epoch_stakes_current_decode( fd_versioned_epoch_stakes_current_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_current_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_versioned_epoch_stakes_current_decode_unsafe( fd_versioned_epoch_stakes_current_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_current_decode_offsets( fd_versioned_epoch_stakes_current_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_current_encode( fd_versioned_epoch_stakes_current_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_versioned_epoch_stakes_current_destroy( fd_versioned_epoch_stakes_current_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_versioned_epoch_stakes_current_walk( void * w, fd_versioned_epoch_stakes_current_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_versioned_epoch_stakes_current_size( fd_versioned_epoch_stakes_current_t const * self );
ulong fd_versioned_epoch_stakes_current_footprint( void );
ulong fd_versioned_epoch_stakes_current_align( void );

void fd_versioned_epoch_stakes_new_disc( fd_versioned_epoch_stakes_t * self, uint discriminant );
void fd_versioned_epoch_stakes_new( fd_versioned_epoch_stakes_t * self );
int fd_versioned_epoch_stakes_decode( fd_versioned_epoch_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_versioned_epoch_stakes_decode_unsafe( fd_versioned_epoch_stakes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_encode( fd_versioned_epoch_stakes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_versioned_epoch_stakes_destroy( fd_versioned_epoch_stakes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_versioned_epoch_stakes_walk( void * w, fd_versioned_epoch_stakes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_versioned_epoch_stakes_size( fd_versioned_epoch_stakes_t const * self );
ulong fd_versioned_epoch_stakes_footprint( void );
ulong fd_versioned_epoch_stakes_align( void );

FD_FN_PURE uchar fd_versioned_epoch_stakes_is_Current( fd_versioned_epoch_stakes_t const * self );
enum {
fd_versioned_epoch_stakes_enum_Current = 0,
}; 
void fd_versioned_epoch_stakes_pair_new( fd_versioned_epoch_stakes_pair_t * self );
int fd_versioned_epoch_stakes_pair_decode( fd_versioned_epoch_stakes_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_versioned_epoch_stakes_pair_decode_unsafe( fd_versioned_epoch_stakes_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_pair_decode_offsets( fd_versioned_epoch_stakes_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_versioned_epoch_stakes_pair_encode( fd_versioned_epoch_stakes_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_versioned_epoch_stakes_pair_destroy( fd_versioned_epoch_stakes_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_versioned_epoch_stakes_pair_walk( void * w, fd_versioned_epoch_stakes_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_versioned_epoch_stakes_pair_size( fd_versioned_epoch_stakes_pair_t const * self );
ulong fd_versioned_epoch_stakes_pair_footprint( void );
ulong fd_versioned_epoch_stakes_pair_align( void );

void fd_reward_info_new( fd_reward_info_t * self );
int fd_reward_info_decode( fd_reward_info_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_reward_info_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_reward_info_decode_unsafe( fd_reward_info_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_reward_info_decode_offsets( fd_reward_info_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_reward_info_encode( fd_reward_info_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_reward_info_destroy( fd_reward_info_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_reward_info_walk( void * w, fd_reward_info_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_reward_info_size( fd_reward_info_t const * self );
ulong fd_reward_info_footprint( void );
ulong fd_reward_info_align( void );

void fd_slot_lthash_new( fd_slot_lthash_t * self );
int fd_slot_lthash_decode( fd_slot_lthash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_lthash_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_lthash_decode_unsafe( fd_slot_lthash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_lthash_decode_offsets( fd_slot_lthash_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_lthash_encode( fd_slot_lthash_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_lthash_destroy( fd_slot_lthash_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_lthash_walk( void * w, fd_slot_lthash_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_lthash_size( fd_slot_lthash_t const * self );
ulong fd_slot_lthash_footprint( void );
ulong fd_slot_lthash_align( void );
int fd_slot_lthash_decode_archival( fd_slot_lthash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_lthash_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_lthash_decode_archival_unsafe( fd_slot_lthash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_lthash_encode_archival( fd_slot_lthash_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_solana_manifest_new( fd_solana_manifest_t * self );
int fd_solana_manifest_decode( fd_solana_manifest_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_manifest_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_solana_manifest_decode_unsafe( fd_solana_manifest_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_manifest_decode_offsets( fd_solana_manifest_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_solana_manifest_encode( fd_solana_manifest_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_solana_manifest_destroy( fd_solana_manifest_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_solana_manifest_walk( void * w, fd_solana_manifest_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_solana_manifest_size( fd_solana_manifest_t const * self );
ulong fd_solana_manifest_footprint( void );
ulong fd_solana_manifest_align( void );

void fd_rust_duration_new( fd_rust_duration_t * self );
int fd_rust_duration_decode( fd_rust_duration_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rust_duration_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_rust_duration_decode_unsafe( fd_rust_duration_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rust_duration_decode_offsets( fd_rust_duration_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_rust_duration_encode( fd_rust_duration_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_rust_duration_destroy( fd_rust_duration_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_rust_duration_walk( void * w, fd_rust_duration_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_rust_duration_size( fd_rust_duration_t const * self );
ulong fd_rust_duration_footprint( void );
ulong fd_rust_duration_align( void );

void fd_poh_config_new( fd_poh_config_t * self );
int fd_poh_config_decode( fd_poh_config_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_poh_config_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_poh_config_decode_unsafe( fd_poh_config_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_poh_config_decode_offsets( fd_poh_config_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_poh_config_encode( fd_poh_config_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_poh_config_destroy( fd_poh_config_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_poh_config_walk( void * w, fd_poh_config_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_poh_config_size( fd_poh_config_t const * self );
ulong fd_poh_config_footprint( void );
ulong fd_poh_config_align( void );

void fd_string_pubkey_pair_new( fd_string_pubkey_pair_t * self );
int fd_string_pubkey_pair_decode( fd_string_pubkey_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_string_pubkey_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_string_pubkey_pair_decode_unsafe( fd_string_pubkey_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_string_pubkey_pair_decode_offsets( fd_string_pubkey_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_string_pubkey_pair_encode( fd_string_pubkey_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_string_pubkey_pair_destroy( fd_string_pubkey_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_string_pubkey_pair_walk( void * w, fd_string_pubkey_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_string_pubkey_pair_size( fd_string_pubkey_pair_t const * self );
ulong fd_string_pubkey_pair_footprint( void );
ulong fd_string_pubkey_pair_align( void );

void fd_pubkey_account_pair_new( fd_pubkey_account_pair_t * self );
int fd_pubkey_account_pair_decode( fd_pubkey_account_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_account_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_pubkey_account_pair_decode_unsafe( fd_pubkey_account_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_account_pair_decode_offsets( fd_pubkey_account_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_account_pair_encode( fd_pubkey_account_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_pubkey_account_pair_destroy( fd_pubkey_account_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_pubkey_account_pair_walk( void * w, fd_pubkey_account_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_pubkey_account_pair_size( fd_pubkey_account_pair_t const * self );
ulong fd_pubkey_account_pair_footprint( void );
ulong fd_pubkey_account_pair_align( void );

void fd_genesis_solana_new( fd_genesis_solana_t * self );
int fd_genesis_solana_decode( fd_genesis_solana_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_genesis_solana_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_genesis_solana_decode_unsafe( fd_genesis_solana_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_genesis_solana_decode_offsets( fd_genesis_solana_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_genesis_solana_encode( fd_genesis_solana_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_genesis_solana_destroy( fd_genesis_solana_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_genesis_solana_walk( void * w, fd_genesis_solana_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_genesis_solana_size( fd_genesis_solana_t const * self );
ulong fd_genesis_solana_footprint( void );
ulong fd_genesis_solana_align( void );

void fd_sol_sysvar_clock_new( fd_sol_sysvar_clock_t * self );
int fd_sol_sysvar_clock_decode( fd_sol_sysvar_clock_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_clock_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_sol_sysvar_clock_decode_unsafe( fd_sol_sysvar_clock_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_clock_decode_offsets( fd_sol_sysvar_clock_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_clock_encode( fd_sol_sysvar_clock_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_sol_sysvar_clock_destroy( fd_sol_sysvar_clock_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_sol_sysvar_clock_walk( void * w, fd_sol_sysvar_clock_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_sol_sysvar_clock_size( fd_sol_sysvar_clock_t const * self );
ulong fd_sol_sysvar_clock_footprint( void );
ulong fd_sol_sysvar_clock_align( void );

void fd_sol_sysvar_last_restart_slot_new( fd_sol_sysvar_last_restart_slot_t * self );
int fd_sol_sysvar_last_restart_slot_decode( fd_sol_sysvar_last_restart_slot_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_last_restart_slot_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_sol_sysvar_last_restart_slot_decode_unsafe( fd_sol_sysvar_last_restart_slot_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_last_restart_slot_decode_offsets( fd_sol_sysvar_last_restart_slot_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_last_restart_slot_encode( fd_sol_sysvar_last_restart_slot_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_sol_sysvar_last_restart_slot_destroy( fd_sol_sysvar_last_restart_slot_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_sol_sysvar_last_restart_slot_walk( void * w, fd_sol_sysvar_last_restart_slot_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_sol_sysvar_last_restart_slot_size( fd_sol_sysvar_last_restart_slot_t const * self );
ulong fd_sol_sysvar_last_restart_slot_footprint( void );
ulong fd_sol_sysvar_last_restart_slot_align( void );
int fd_sol_sysvar_last_restart_slot_decode_archival( fd_sol_sysvar_last_restart_slot_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_last_restart_slot_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_sol_sysvar_last_restart_slot_decode_archival_unsafe( fd_sol_sysvar_last_restart_slot_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sol_sysvar_last_restart_slot_encode_archival( fd_sol_sysvar_last_restart_slot_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_vote_lockout_new( fd_vote_lockout_t * self );
int fd_vote_lockout_decode( fd_vote_lockout_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_lockout_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_lockout_decode_unsafe( fd_vote_lockout_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_lockout_decode_offsets( fd_vote_lockout_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_lockout_encode( fd_vote_lockout_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_lockout_destroy( fd_vote_lockout_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_lockout_walk( void * w, fd_vote_lockout_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_lockout_size( fd_vote_lockout_t const * self );
ulong fd_vote_lockout_footprint( void );
ulong fd_vote_lockout_align( void );

void fd_lockout_offset_new( fd_lockout_offset_t * self );
int fd_lockout_offset_decode( fd_lockout_offset_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockout_offset_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_lockout_offset_decode_unsafe( fd_lockout_offset_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockout_offset_decode_offsets( fd_lockout_offset_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockout_offset_encode( fd_lockout_offset_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_lockout_offset_destroy( fd_lockout_offset_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_lockout_offset_walk( void * w, fd_lockout_offset_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_lockout_offset_size( fd_lockout_offset_t const * self );
ulong fd_lockout_offset_footprint( void );
ulong fd_lockout_offset_align( void );

void fd_vote_authorized_voter_new( fd_vote_authorized_voter_t * self );
int fd_vote_authorized_voter_decode( fd_vote_authorized_voter_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorized_voter_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_authorized_voter_decode_unsafe( fd_vote_authorized_voter_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorized_voter_decode_offsets( fd_vote_authorized_voter_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorized_voter_encode( fd_vote_authorized_voter_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_authorized_voter_destroy( fd_vote_authorized_voter_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_authorized_voter_walk( void * w, fd_vote_authorized_voter_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_authorized_voter_size( fd_vote_authorized_voter_t const * self );
ulong fd_vote_authorized_voter_footprint( void );
ulong fd_vote_authorized_voter_align( void );

void fd_vote_prior_voter_new( fd_vote_prior_voter_t * self );
int fd_vote_prior_voter_decode( fd_vote_prior_voter_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voter_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_prior_voter_decode_unsafe( fd_vote_prior_voter_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voter_decode_offsets( fd_vote_prior_voter_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voter_encode( fd_vote_prior_voter_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_prior_voter_destroy( fd_vote_prior_voter_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_prior_voter_walk( void * w, fd_vote_prior_voter_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_prior_voter_size( fd_vote_prior_voter_t const * self );
ulong fd_vote_prior_voter_footprint( void );
ulong fd_vote_prior_voter_align( void );

void fd_vote_prior_voter_0_23_5_new( fd_vote_prior_voter_0_23_5_t * self );
int fd_vote_prior_voter_0_23_5_decode( fd_vote_prior_voter_0_23_5_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voter_0_23_5_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_prior_voter_0_23_5_decode_unsafe( fd_vote_prior_voter_0_23_5_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voter_0_23_5_decode_offsets( fd_vote_prior_voter_0_23_5_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voter_0_23_5_encode( fd_vote_prior_voter_0_23_5_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_prior_voter_0_23_5_destroy( fd_vote_prior_voter_0_23_5_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_prior_voter_0_23_5_walk( void * w, fd_vote_prior_voter_0_23_5_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_prior_voter_0_23_5_size( fd_vote_prior_voter_0_23_5_t const * self );
ulong fd_vote_prior_voter_0_23_5_footprint( void );
ulong fd_vote_prior_voter_0_23_5_align( void );

void fd_vote_epoch_credits_new( fd_vote_epoch_credits_t * self );
int fd_vote_epoch_credits_decode( fd_vote_epoch_credits_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_epoch_credits_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_epoch_credits_decode_unsafe( fd_vote_epoch_credits_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_epoch_credits_decode_offsets( fd_vote_epoch_credits_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_epoch_credits_encode( fd_vote_epoch_credits_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_epoch_credits_destroy( fd_vote_epoch_credits_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_epoch_credits_walk( void * w, fd_vote_epoch_credits_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_epoch_credits_size( fd_vote_epoch_credits_t const * self );
ulong fd_vote_epoch_credits_footprint( void );
ulong fd_vote_epoch_credits_align( void );

void fd_vote_block_timestamp_new( fd_vote_block_timestamp_t * self );
int fd_vote_block_timestamp_decode( fd_vote_block_timestamp_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_block_timestamp_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_block_timestamp_decode_unsafe( fd_vote_block_timestamp_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_block_timestamp_decode_offsets( fd_vote_block_timestamp_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_block_timestamp_encode( fd_vote_block_timestamp_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_block_timestamp_destroy( fd_vote_block_timestamp_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_block_timestamp_walk( void * w, fd_vote_block_timestamp_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_block_timestamp_size( fd_vote_block_timestamp_t const * self );
ulong fd_vote_block_timestamp_footprint( void );
ulong fd_vote_block_timestamp_align( void );

void fd_vote_prior_voters_new( fd_vote_prior_voters_t * self );
int fd_vote_prior_voters_decode( fd_vote_prior_voters_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voters_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_prior_voters_decode_unsafe( fd_vote_prior_voters_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voters_decode_offsets( fd_vote_prior_voters_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voters_encode( fd_vote_prior_voters_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_prior_voters_destroy( fd_vote_prior_voters_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_prior_voters_walk( void * w, fd_vote_prior_voters_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_prior_voters_size( fd_vote_prior_voters_t const * self );
ulong fd_vote_prior_voters_footprint( void );
ulong fd_vote_prior_voters_align( void );

void fd_vote_prior_voters_0_23_5_new( fd_vote_prior_voters_0_23_5_t * self );
int fd_vote_prior_voters_0_23_5_decode( fd_vote_prior_voters_0_23_5_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voters_0_23_5_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_prior_voters_0_23_5_decode_unsafe( fd_vote_prior_voters_0_23_5_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voters_0_23_5_decode_offsets( fd_vote_prior_voters_0_23_5_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_prior_voters_0_23_5_encode( fd_vote_prior_voters_0_23_5_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_prior_voters_0_23_5_destroy( fd_vote_prior_voters_0_23_5_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_prior_voters_0_23_5_walk( void * w, fd_vote_prior_voters_0_23_5_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_prior_voters_0_23_5_size( fd_vote_prior_voters_0_23_5_t const * self );
ulong fd_vote_prior_voters_0_23_5_footprint( void );
ulong fd_vote_prior_voters_0_23_5_align( void );

void fd_landed_vote_new( fd_landed_vote_t * self );
int fd_landed_vote_decode( fd_landed_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_landed_vote_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_landed_vote_decode_unsafe( fd_landed_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_landed_vote_decode_offsets( fd_landed_vote_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_landed_vote_encode( fd_landed_vote_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_landed_vote_destroy( fd_landed_vote_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_landed_vote_walk( void * w, fd_landed_vote_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_landed_vote_size( fd_landed_vote_t const * self );
ulong fd_landed_vote_footprint( void );
ulong fd_landed_vote_align( void );

void fd_vote_state_0_23_5_new( fd_vote_state_0_23_5_t * self );
int fd_vote_state_0_23_5_decode( fd_vote_state_0_23_5_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_0_23_5_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_state_0_23_5_decode_unsafe( fd_vote_state_0_23_5_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_0_23_5_decode_offsets( fd_vote_state_0_23_5_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_0_23_5_encode( fd_vote_state_0_23_5_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_state_0_23_5_destroy( fd_vote_state_0_23_5_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_state_0_23_5_walk( void * w, fd_vote_state_0_23_5_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_state_0_23_5_size( fd_vote_state_0_23_5_t const * self );
ulong fd_vote_state_0_23_5_footprint( void );
ulong fd_vote_state_0_23_5_align( void );

void fd_vote_authorized_voters_new( fd_vote_authorized_voters_t * self );
int fd_vote_authorized_voters_decode( fd_vote_authorized_voters_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorized_voters_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_authorized_voters_decode_unsafe( fd_vote_authorized_voters_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorized_voters_decode_offsets( fd_vote_authorized_voters_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorized_voters_encode( fd_vote_authorized_voters_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_authorized_voters_destroy( fd_vote_authorized_voters_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_authorized_voters_walk( void * w, fd_vote_authorized_voters_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_authorized_voters_size( fd_vote_authorized_voters_t const * self );
ulong fd_vote_authorized_voters_footprint( void );
ulong fd_vote_authorized_voters_align( void );

void fd_vote_state_1_14_11_new( fd_vote_state_1_14_11_t * self );
int fd_vote_state_1_14_11_decode( fd_vote_state_1_14_11_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_1_14_11_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_state_1_14_11_decode_unsafe( fd_vote_state_1_14_11_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_1_14_11_decode_offsets( fd_vote_state_1_14_11_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_1_14_11_encode( fd_vote_state_1_14_11_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_state_1_14_11_destroy( fd_vote_state_1_14_11_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_state_1_14_11_walk( void * w, fd_vote_state_1_14_11_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_state_1_14_11_size( fd_vote_state_1_14_11_t const * self );
ulong fd_vote_state_1_14_11_footprint( void );
ulong fd_vote_state_1_14_11_align( void );

void fd_vote_state_new( fd_vote_state_t * self );
int fd_vote_state_decode( fd_vote_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_state_decode_unsafe( fd_vote_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_decode_offsets( fd_vote_state_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_encode( fd_vote_state_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_state_destroy( fd_vote_state_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_state_walk( void * w, fd_vote_state_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_state_size( fd_vote_state_t const * self );
ulong fd_vote_state_footprint( void );
ulong fd_vote_state_align( void );

void fd_vote_state_versioned_new_disc( fd_vote_state_versioned_t * self, uint discriminant );
void fd_vote_state_versioned_new( fd_vote_state_versioned_t * self );
int fd_vote_state_versioned_decode( fd_vote_state_versioned_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_versioned_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_state_versioned_decode_unsafe( fd_vote_state_versioned_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_versioned_decode_offsets( fd_vote_state_versioned_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_versioned_encode( fd_vote_state_versioned_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_state_versioned_destroy( fd_vote_state_versioned_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_state_versioned_walk( void * w, fd_vote_state_versioned_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_state_versioned_size( fd_vote_state_versioned_t const * self );
ulong fd_vote_state_versioned_footprint( void );
ulong fd_vote_state_versioned_align( void );

FD_FN_PURE uchar fd_vote_state_versioned_is_v0_23_5( fd_vote_state_versioned_t const * self );
FD_FN_PURE uchar fd_vote_state_versioned_is_v1_14_11( fd_vote_state_versioned_t const * self );
FD_FN_PURE uchar fd_vote_state_versioned_is_current( fd_vote_state_versioned_t const * self );
enum {
fd_vote_state_versioned_enum_v0_23_5 = 0,
fd_vote_state_versioned_enum_v1_14_11 = 1,
fd_vote_state_versioned_enum_current = 2,
}; 
void fd_vote_state_update_new( fd_vote_state_update_t * self );
int fd_vote_state_update_decode( fd_vote_state_update_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_update_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_state_update_decode_unsafe( fd_vote_state_update_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_update_decode_offsets( fd_vote_state_update_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_state_update_encode( fd_vote_state_update_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_state_update_destroy( fd_vote_state_update_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_state_update_walk( void * w, fd_vote_state_update_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_state_update_size( fd_vote_state_update_t const * self );
ulong fd_vote_state_update_footprint( void );
ulong fd_vote_state_update_align( void );

void fd_compact_vote_state_update_new( fd_compact_vote_state_update_t * self );
int fd_compact_vote_state_update_decode( fd_compact_vote_state_update_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_vote_state_update_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_compact_vote_state_update_decode_unsafe( fd_compact_vote_state_update_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_vote_state_update_decode_offsets( fd_compact_vote_state_update_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_vote_state_update_encode( fd_compact_vote_state_update_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_compact_vote_state_update_destroy( fd_compact_vote_state_update_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_compact_vote_state_update_walk( void * w, fd_compact_vote_state_update_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_compact_vote_state_update_size( fd_compact_vote_state_update_t const * self );
ulong fd_compact_vote_state_update_footprint( void );
ulong fd_compact_vote_state_update_align( void );

void fd_compact_vote_state_update_switch_new( fd_compact_vote_state_update_switch_t * self );
int fd_compact_vote_state_update_switch_decode( fd_compact_vote_state_update_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_vote_state_update_switch_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_compact_vote_state_update_switch_decode_unsafe( fd_compact_vote_state_update_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_vote_state_update_switch_decode_offsets( fd_compact_vote_state_update_switch_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_vote_state_update_switch_encode( fd_compact_vote_state_update_switch_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_compact_vote_state_update_switch_destroy( fd_compact_vote_state_update_switch_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_compact_vote_state_update_switch_walk( void * w, fd_compact_vote_state_update_switch_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_compact_vote_state_update_switch_size( fd_compact_vote_state_update_switch_t const * self );
ulong fd_compact_vote_state_update_switch_footprint( void );
ulong fd_compact_vote_state_update_switch_align( void );

void fd_compact_tower_sync_new( fd_compact_tower_sync_t * self );
int fd_compact_tower_sync_decode( fd_compact_tower_sync_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_tower_sync_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_compact_tower_sync_decode_unsafe( fd_compact_tower_sync_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_tower_sync_decode_offsets( fd_compact_tower_sync_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compact_tower_sync_encode( fd_compact_tower_sync_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_compact_tower_sync_destroy( fd_compact_tower_sync_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_compact_tower_sync_walk( void * w, fd_compact_tower_sync_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_compact_tower_sync_size( fd_compact_tower_sync_t const * self );
ulong fd_compact_tower_sync_footprint( void );
ulong fd_compact_tower_sync_align( void );

void fd_tower_sync_new( fd_tower_sync_t * self );
int fd_tower_sync_decode( fd_tower_sync_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_tower_sync_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_tower_sync_decode_unsafe( fd_tower_sync_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_tower_sync_decode_offsets( fd_tower_sync_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_tower_sync_encode( fd_tower_sync_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_tower_sync_destroy( fd_tower_sync_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_tower_sync_walk( void * w, fd_tower_sync_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_tower_sync_size( fd_tower_sync_t const * self );
ulong fd_tower_sync_footprint( void );
ulong fd_tower_sync_align( void );

void fd_tower_sync_switch_new( fd_tower_sync_switch_t * self );
int fd_tower_sync_switch_decode( fd_tower_sync_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_tower_sync_switch_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_tower_sync_switch_decode_unsafe( fd_tower_sync_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_tower_sync_switch_decode_offsets( fd_tower_sync_switch_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_tower_sync_switch_encode( fd_tower_sync_switch_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_tower_sync_switch_destroy( fd_tower_sync_switch_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_tower_sync_switch_walk( void * w, fd_tower_sync_switch_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_tower_sync_switch_size( fd_tower_sync_switch_t const * self );
ulong fd_tower_sync_switch_footprint( void );
ulong fd_tower_sync_switch_align( void );

void fd_slot_history_inner_new( fd_slot_history_inner_t * self );
int fd_slot_history_inner_decode( fd_slot_history_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_inner_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_history_inner_decode_unsafe( fd_slot_history_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_inner_decode_offsets( fd_slot_history_inner_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_inner_encode( fd_slot_history_inner_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_history_inner_destroy( fd_slot_history_inner_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_history_inner_walk( void * w, fd_slot_history_inner_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_history_inner_size( fd_slot_history_inner_t const * self );
ulong fd_slot_history_inner_footprint( void );
ulong fd_slot_history_inner_align( void );

void fd_slot_history_bitvec_new( fd_slot_history_bitvec_t * self );
int fd_slot_history_bitvec_decode( fd_slot_history_bitvec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_bitvec_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_history_bitvec_decode_unsafe( fd_slot_history_bitvec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_bitvec_decode_offsets( fd_slot_history_bitvec_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_bitvec_encode( fd_slot_history_bitvec_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_history_bitvec_destroy( fd_slot_history_bitvec_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_history_bitvec_walk( void * w, fd_slot_history_bitvec_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_history_bitvec_size( fd_slot_history_bitvec_t const * self );
ulong fd_slot_history_bitvec_footprint( void );
ulong fd_slot_history_bitvec_align( void );

void fd_slot_history_new( fd_slot_history_t * self );
int fd_slot_history_decode( fd_slot_history_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_history_decode_unsafe( fd_slot_history_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_decode_offsets( fd_slot_history_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_history_encode( fd_slot_history_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_history_destroy( fd_slot_history_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_history_walk( void * w, fd_slot_history_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_history_size( fd_slot_history_t const * self );
ulong fd_slot_history_footprint( void );
ulong fd_slot_history_align( void );

void fd_slot_hash_new( fd_slot_hash_t * self );
int fd_slot_hash_decode( fd_slot_hash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_hash_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_hash_decode_unsafe( fd_slot_hash_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_hash_decode_offsets( fd_slot_hash_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_hash_encode( fd_slot_hash_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_hash_destroy( fd_slot_hash_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_hash_walk( void * w, fd_slot_hash_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_hash_size( fd_slot_hash_t const * self );
ulong fd_slot_hash_footprint( void );
ulong fd_slot_hash_align( void );

void fd_slot_hashes_new( fd_slot_hashes_t * self );
int fd_slot_hashes_decode( fd_slot_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_hashes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_hashes_decode_unsafe( fd_slot_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_hashes_decode_offsets( fd_slot_hashes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_hashes_encode( fd_slot_hashes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_hashes_destroy( fd_slot_hashes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_hashes_walk( void * w, fd_slot_hashes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_hashes_size( fd_slot_hashes_t const * self );
ulong fd_slot_hashes_footprint( void );
ulong fd_slot_hashes_align( void );

void fd_block_block_hash_entry_new( fd_block_block_hash_entry_t * self );
int fd_block_block_hash_entry_decode( fd_block_block_hash_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_block_hash_entry_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_block_block_hash_entry_decode_unsafe( fd_block_block_hash_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_block_hash_entry_decode_offsets( fd_block_block_hash_entry_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_block_hash_entry_encode( fd_block_block_hash_entry_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_block_block_hash_entry_destroy( fd_block_block_hash_entry_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_block_block_hash_entry_walk( void * w, fd_block_block_hash_entry_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_block_block_hash_entry_size( fd_block_block_hash_entry_t const * self );
ulong fd_block_block_hash_entry_footprint( void );
ulong fd_block_block_hash_entry_align( void );
int fd_block_block_hash_entry_decode_archival( fd_block_block_hash_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_block_hash_entry_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_block_block_hash_entry_decode_archival_unsafe( fd_block_block_hash_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_block_block_hash_entry_encode_archival( fd_block_block_hash_entry_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_recent_block_hashes_new( fd_recent_block_hashes_t * self );
int fd_recent_block_hashes_decode( fd_recent_block_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_recent_block_hashes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_recent_block_hashes_decode_unsafe( fd_recent_block_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_recent_block_hashes_decode_offsets( fd_recent_block_hashes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_recent_block_hashes_encode( fd_recent_block_hashes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_recent_block_hashes_destroy( fd_recent_block_hashes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_recent_block_hashes_walk( void * w, fd_recent_block_hashes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_recent_block_hashes_size( fd_recent_block_hashes_t const * self );
ulong fd_recent_block_hashes_footprint( void );
ulong fd_recent_block_hashes_align( void );
int fd_recent_block_hashes_decode_archival( fd_recent_block_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_recent_block_hashes_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_recent_block_hashes_decode_archival_unsafe( fd_recent_block_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_recent_block_hashes_encode_archival( fd_recent_block_hashes_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_slot_meta_new( fd_slot_meta_t * self );
int fd_slot_meta_decode( fd_slot_meta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_meta_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_meta_decode_unsafe( fd_slot_meta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_meta_decode_offsets( fd_slot_meta_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_meta_encode( fd_slot_meta_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_meta_destroy( fd_slot_meta_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_meta_walk( void * w, fd_slot_meta_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_meta_size( fd_slot_meta_t const * self );
ulong fd_slot_meta_footprint( void );
ulong fd_slot_meta_align( void );

void fd_clock_timestamp_vote_new( fd_clock_timestamp_vote_t * self );
int fd_clock_timestamp_vote_decode( fd_clock_timestamp_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_vote_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_clock_timestamp_vote_decode_unsafe( fd_clock_timestamp_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_vote_decode_offsets( fd_clock_timestamp_vote_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_vote_encode( fd_clock_timestamp_vote_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_clock_timestamp_vote_destroy( fd_clock_timestamp_vote_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_clock_timestamp_vote_walk( void * w, fd_clock_timestamp_vote_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_clock_timestamp_vote_size( fd_clock_timestamp_vote_t const * self );
ulong fd_clock_timestamp_vote_footprint( void );
ulong fd_clock_timestamp_vote_align( void );
int fd_clock_timestamp_vote_decode_archival( fd_clock_timestamp_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_vote_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_clock_timestamp_vote_decode_archival_unsafe( fd_clock_timestamp_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_vote_encode_archival( fd_clock_timestamp_vote_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_clock_timestamp_votes_new( fd_clock_timestamp_votes_t * self );
int fd_clock_timestamp_votes_decode( fd_clock_timestamp_votes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_votes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_clock_timestamp_votes_decode_unsafe( fd_clock_timestamp_votes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_votes_decode_offsets( fd_clock_timestamp_votes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_votes_encode( fd_clock_timestamp_votes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_clock_timestamp_votes_destroy( fd_clock_timestamp_votes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_clock_timestamp_votes_walk( void * w, fd_clock_timestamp_votes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_clock_timestamp_votes_size( fd_clock_timestamp_votes_t const * self );
ulong fd_clock_timestamp_votes_footprint( void );
ulong fd_clock_timestamp_votes_align( void );
int fd_clock_timestamp_votes_decode_archival( fd_clock_timestamp_votes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_votes_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_clock_timestamp_votes_decode_archival_unsafe( fd_clock_timestamp_votes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_clock_timestamp_votes_encode_archival( fd_clock_timestamp_votes_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_sysvar_fees_new( fd_sysvar_fees_t * self );
int fd_sysvar_fees_decode( fd_sysvar_fees_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sysvar_fees_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_sysvar_fees_decode_unsafe( fd_sysvar_fees_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sysvar_fees_decode_offsets( fd_sysvar_fees_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sysvar_fees_encode( fd_sysvar_fees_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_sysvar_fees_destroy( fd_sysvar_fees_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_sysvar_fees_walk( void * w, fd_sysvar_fees_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_sysvar_fees_size( fd_sysvar_fees_t const * self );
ulong fd_sysvar_fees_footprint( void );
ulong fd_sysvar_fees_align( void );

void fd_sysvar_epoch_rewards_new( fd_sysvar_epoch_rewards_t * self );
int fd_sysvar_epoch_rewards_decode( fd_sysvar_epoch_rewards_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sysvar_epoch_rewards_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_sysvar_epoch_rewards_decode_unsafe( fd_sysvar_epoch_rewards_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sysvar_epoch_rewards_decode_offsets( fd_sysvar_epoch_rewards_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_sysvar_epoch_rewards_encode( fd_sysvar_epoch_rewards_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_sysvar_epoch_rewards_destroy( fd_sysvar_epoch_rewards_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_sysvar_epoch_rewards_walk( void * w, fd_sysvar_epoch_rewards_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_sysvar_epoch_rewards_size( fd_sysvar_epoch_rewards_t const * self );
ulong fd_sysvar_epoch_rewards_footprint( void );
ulong fd_sysvar_epoch_rewards_align( void );

void fd_config_keys_pair_new( fd_config_keys_pair_t * self );
int fd_config_keys_pair_decode( fd_config_keys_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_config_keys_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_config_keys_pair_decode_unsafe( fd_config_keys_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_config_keys_pair_decode_offsets( fd_config_keys_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_config_keys_pair_encode( fd_config_keys_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_config_keys_pair_destroy( fd_config_keys_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_config_keys_pair_walk( void * w, fd_config_keys_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_config_keys_pair_size( fd_config_keys_pair_t const * self );
ulong fd_config_keys_pair_footprint( void );
ulong fd_config_keys_pair_align( void );

void fd_stake_config_new( fd_stake_config_t * self );
int fd_stake_config_decode( fd_stake_config_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_config_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_config_decode_unsafe( fd_stake_config_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_config_decode_offsets( fd_stake_config_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_config_encode( fd_stake_config_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_config_destroy( fd_stake_config_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_config_walk( void * w, fd_stake_config_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_config_size( fd_stake_config_t const * self );
ulong fd_stake_config_footprint( void );
ulong fd_stake_config_align( void );

void fd_feature_entry_new( fd_feature_entry_t * self );
int fd_feature_entry_decode( fd_feature_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_feature_entry_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_feature_entry_decode_unsafe( fd_feature_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_feature_entry_decode_offsets( fd_feature_entry_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_feature_entry_encode( fd_feature_entry_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_feature_entry_destroy( fd_feature_entry_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_feature_entry_walk( void * w, fd_feature_entry_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_feature_entry_size( fd_feature_entry_t const * self );
ulong fd_feature_entry_footprint( void );
ulong fd_feature_entry_align( void );

void fd_firedancer_bank_new( fd_firedancer_bank_t * self );
int fd_firedancer_bank_decode( fd_firedancer_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_firedancer_bank_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_firedancer_bank_decode_unsafe( fd_firedancer_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_firedancer_bank_decode_offsets( fd_firedancer_bank_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_firedancer_bank_encode( fd_firedancer_bank_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_firedancer_bank_destroy( fd_firedancer_bank_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_firedancer_bank_walk( void * w, fd_firedancer_bank_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_firedancer_bank_size( fd_firedancer_bank_t const * self );
ulong fd_firedancer_bank_footprint( void );
ulong fd_firedancer_bank_align( void );

void fd_cluster_type_new_disc( fd_cluster_type_t * self, uint discriminant );
void fd_cluster_type_new( fd_cluster_type_t * self );
int fd_cluster_type_decode( fd_cluster_type_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_cluster_type_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_cluster_type_decode_unsafe( fd_cluster_type_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_cluster_type_encode( fd_cluster_type_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_cluster_type_destroy( fd_cluster_type_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_cluster_type_walk( void * w, fd_cluster_type_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_cluster_type_size( fd_cluster_type_t const * self );
ulong fd_cluster_type_footprint( void );
ulong fd_cluster_type_align( void );

FD_FN_PURE uchar fd_cluster_type_is_Testnet( fd_cluster_type_t const * self );
FD_FN_PURE uchar fd_cluster_type_is_MainnetBeta( fd_cluster_type_t const * self );
FD_FN_PURE uchar fd_cluster_type_is_Devnet( fd_cluster_type_t const * self );
FD_FN_PURE uchar fd_cluster_type_is_Development( fd_cluster_type_t const * self );
enum {
fd_cluster_type_enum_Testnet = 0,
fd_cluster_type_enum_MainnetBeta = 1,
fd_cluster_type_enum_Devnet = 2,
fd_cluster_type_enum_Development = 3,
}; 
void fd_epoch_bank_new( fd_epoch_bank_t * self );
int fd_epoch_bank_decode( fd_epoch_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_bank_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_bank_decode_unsafe( fd_epoch_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_bank_decode_offsets( fd_epoch_bank_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_bank_encode( fd_epoch_bank_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_epoch_bank_destroy( fd_epoch_bank_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_epoch_bank_walk( void * w, fd_epoch_bank_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_epoch_bank_size( fd_epoch_bank_t const * self );
ulong fd_epoch_bank_footprint( void );
ulong fd_epoch_bank_align( void );
int fd_epoch_bank_decode_archival( fd_epoch_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_bank_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_epoch_bank_decode_archival_unsafe( fd_epoch_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_epoch_bank_encode_archival( fd_epoch_bank_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_slot_bank_new( fd_slot_bank_t * self );
int fd_slot_bank_decode( fd_slot_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_bank_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_bank_decode_unsafe( fd_slot_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_bank_decode_offsets( fd_slot_bank_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_bank_encode( fd_slot_bank_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_bank_destroy( fd_slot_bank_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_bank_walk( void * w, fd_slot_bank_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_bank_size( fd_slot_bank_t const * self );
ulong fd_slot_bank_footprint( void );
ulong fd_slot_bank_align( void );
int fd_slot_bank_decode_archival( fd_slot_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_bank_decode_archival_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_bank_decode_archival_unsafe( fd_slot_bank_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_bank_encode_archival( fd_slot_bank_t const * self, fd_bincode_encode_ctx_t * ctx );

void fd_prev_epoch_inflation_rewards_new( fd_prev_epoch_inflation_rewards_t * self );
int fd_prev_epoch_inflation_rewards_decode( fd_prev_epoch_inflation_rewards_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_prev_epoch_inflation_rewards_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_prev_epoch_inflation_rewards_decode_unsafe( fd_prev_epoch_inflation_rewards_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_prev_epoch_inflation_rewards_decode_offsets( fd_prev_epoch_inflation_rewards_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_prev_epoch_inflation_rewards_encode( fd_prev_epoch_inflation_rewards_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_prev_epoch_inflation_rewards_destroy( fd_prev_epoch_inflation_rewards_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_prev_epoch_inflation_rewards_walk( void * w, fd_prev_epoch_inflation_rewards_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_prev_epoch_inflation_rewards_size( fd_prev_epoch_inflation_rewards_t const * self );
ulong fd_prev_epoch_inflation_rewards_footprint( void );
ulong fd_prev_epoch_inflation_rewards_align( void );

void fd_vote_new( fd_vote_t * self );
int fd_vote_decode( fd_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_decode_unsafe( fd_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_decode_offsets( fd_vote_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_encode( fd_vote_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_destroy( fd_vote_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_walk( void * w, fd_vote_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_size( fd_vote_t const * self );
ulong fd_vote_footprint( void );
ulong fd_vote_align( void );

void fd_vote_init_new( fd_vote_init_t * self );
int fd_vote_init_decode( fd_vote_init_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_init_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_init_decode_unsafe( fd_vote_init_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_init_decode_offsets( fd_vote_init_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_init_encode( fd_vote_init_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_init_destroy( fd_vote_init_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_init_walk( void * w, fd_vote_init_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_init_size( fd_vote_init_t const * self );
ulong fd_vote_init_footprint( void );
ulong fd_vote_init_align( void );

void fd_vote_authorize_new_disc( fd_vote_authorize_t * self, uint discriminant );
void fd_vote_authorize_new( fd_vote_authorize_t * self );
int fd_vote_authorize_decode( fd_vote_authorize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_authorize_decode_unsafe( fd_vote_authorize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_encode( fd_vote_authorize_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_authorize_destroy( fd_vote_authorize_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_authorize_walk( void * w, fd_vote_authorize_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_authorize_size( fd_vote_authorize_t const * self );
ulong fd_vote_authorize_footprint( void );
ulong fd_vote_authorize_align( void );

FD_FN_PURE uchar fd_vote_authorize_is_voter( fd_vote_authorize_t const * self );
FD_FN_PURE uchar fd_vote_authorize_is_withdrawer( fd_vote_authorize_t const * self );
enum {
fd_vote_authorize_enum_voter = 0,
fd_vote_authorize_enum_withdrawer = 1,
}; 
void fd_vote_authorize_pubkey_new( fd_vote_authorize_pubkey_t * self );
int fd_vote_authorize_pubkey_decode( fd_vote_authorize_pubkey_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_pubkey_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_authorize_pubkey_decode_unsafe( fd_vote_authorize_pubkey_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_pubkey_decode_offsets( fd_vote_authorize_pubkey_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_pubkey_encode( fd_vote_authorize_pubkey_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_authorize_pubkey_destroy( fd_vote_authorize_pubkey_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_authorize_pubkey_walk( void * w, fd_vote_authorize_pubkey_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_authorize_pubkey_size( fd_vote_authorize_pubkey_t const * self );
ulong fd_vote_authorize_pubkey_footprint( void );
ulong fd_vote_authorize_pubkey_align( void );

void fd_vote_switch_new( fd_vote_switch_t * self );
int fd_vote_switch_decode( fd_vote_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_switch_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_switch_decode_unsafe( fd_vote_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_switch_decode_offsets( fd_vote_switch_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_switch_encode( fd_vote_switch_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_switch_destroy( fd_vote_switch_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_switch_walk( void * w, fd_vote_switch_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_switch_size( fd_vote_switch_t const * self );
ulong fd_vote_switch_footprint( void );
ulong fd_vote_switch_align( void );

void fd_update_vote_state_switch_new( fd_update_vote_state_switch_t * self );
int fd_update_vote_state_switch_decode( fd_update_vote_state_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_update_vote_state_switch_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_update_vote_state_switch_decode_unsafe( fd_update_vote_state_switch_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_update_vote_state_switch_decode_offsets( fd_update_vote_state_switch_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_update_vote_state_switch_encode( fd_update_vote_state_switch_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_update_vote_state_switch_destroy( fd_update_vote_state_switch_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_update_vote_state_switch_walk( void * w, fd_update_vote_state_switch_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_update_vote_state_switch_size( fd_update_vote_state_switch_t const * self );
ulong fd_update_vote_state_switch_footprint( void );
ulong fd_update_vote_state_switch_align( void );

void fd_vote_authorize_with_seed_args_new( fd_vote_authorize_with_seed_args_t * self );
int fd_vote_authorize_with_seed_args_decode( fd_vote_authorize_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_with_seed_args_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_authorize_with_seed_args_decode_unsafe( fd_vote_authorize_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_with_seed_args_decode_offsets( fd_vote_authorize_with_seed_args_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_with_seed_args_encode( fd_vote_authorize_with_seed_args_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_authorize_with_seed_args_destroy( fd_vote_authorize_with_seed_args_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_authorize_with_seed_args_walk( void * w, fd_vote_authorize_with_seed_args_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_authorize_with_seed_args_size( fd_vote_authorize_with_seed_args_t const * self );
ulong fd_vote_authorize_with_seed_args_footprint( void );
ulong fd_vote_authorize_with_seed_args_align( void );

void fd_vote_authorize_checked_with_seed_args_new( fd_vote_authorize_checked_with_seed_args_t * self );
int fd_vote_authorize_checked_with_seed_args_decode( fd_vote_authorize_checked_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_checked_with_seed_args_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_authorize_checked_with_seed_args_decode_unsafe( fd_vote_authorize_checked_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_checked_with_seed_args_decode_offsets( fd_vote_authorize_checked_with_seed_args_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_authorize_checked_with_seed_args_encode( fd_vote_authorize_checked_with_seed_args_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_authorize_checked_with_seed_args_destroy( fd_vote_authorize_checked_with_seed_args_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_authorize_checked_with_seed_args_walk( void * w, fd_vote_authorize_checked_with_seed_args_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_authorize_checked_with_seed_args_size( fd_vote_authorize_checked_with_seed_args_t const * self );
ulong fd_vote_authorize_checked_with_seed_args_footprint( void );
ulong fd_vote_authorize_checked_with_seed_args_align( void );

void fd_vote_instruction_new_disc( fd_vote_instruction_t * self, uint discriminant );
void fd_vote_instruction_new( fd_vote_instruction_t * self );
int fd_vote_instruction_decode( fd_vote_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_vote_instruction_decode_unsafe( fd_vote_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_vote_instruction_encode( fd_vote_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_vote_instruction_destroy( fd_vote_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_vote_instruction_walk( void * w, fd_vote_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_vote_instruction_size( fd_vote_instruction_t const * self );
ulong fd_vote_instruction_footprint( void );
ulong fd_vote_instruction_align( void );

FD_FN_PURE uchar fd_vote_instruction_is_initialize_account( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_authorize( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_vote( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_withdraw( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_update_validator_identity( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_update_commission( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_vote_switch( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_authorize_checked( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_update_vote_state( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_update_vote_state_switch( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_authorize_with_seed( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_authorize_checked_with_seed( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_compact_update_vote_state( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_compact_update_vote_state_switch( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_tower_sync( fd_vote_instruction_t const * self );
FD_FN_PURE uchar fd_vote_instruction_is_tower_sync_switch( fd_vote_instruction_t const * self );
enum {
fd_vote_instruction_enum_initialize_account = 0,
fd_vote_instruction_enum_authorize = 1,
fd_vote_instruction_enum_vote = 2,
fd_vote_instruction_enum_withdraw = 3,
fd_vote_instruction_enum_update_validator_identity = 4,
fd_vote_instruction_enum_update_commission = 5,
fd_vote_instruction_enum_vote_switch = 6,
fd_vote_instruction_enum_authorize_checked = 7,
fd_vote_instruction_enum_update_vote_state = 8,
fd_vote_instruction_enum_update_vote_state_switch = 9,
fd_vote_instruction_enum_authorize_with_seed = 10,
fd_vote_instruction_enum_authorize_checked_with_seed = 11,
fd_vote_instruction_enum_compact_update_vote_state = 12,
fd_vote_instruction_enum_compact_update_vote_state_switch = 13,
fd_vote_instruction_enum_tower_sync = 14,
fd_vote_instruction_enum_tower_sync_switch = 15,
}; 
void fd_system_program_instruction_create_account_new( fd_system_program_instruction_create_account_t * self );
int fd_system_program_instruction_create_account_decode( fd_system_program_instruction_create_account_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_create_account_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_system_program_instruction_create_account_decode_unsafe( fd_system_program_instruction_create_account_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_create_account_decode_offsets( fd_system_program_instruction_create_account_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_create_account_encode( fd_system_program_instruction_create_account_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_system_program_instruction_create_account_destroy( fd_system_program_instruction_create_account_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_system_program_instruction_create_account_walk( void * w, fd_system_program_instruction_create_account_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_system_program_instruction_create_account_size( fd_system_program_instruction_create_account_t const * self );
ulong fd_system_program_instruction_create_account_footprint( void );
ulong fd_system_program_instruction_create_account_align( void );

void fd_system_program_instruction_create_account_with_seed_new( fd_system_program_instruction_create_account_with_seed_t * self );
int fd_system_program_instruction_create_account_with_seed_decode( fd_system_program_instruction_create_account_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_create_account_with_seed_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_system_program_instruction_create_account_with_seed_decode_unsafe( fd_system_program_instruction_create_account_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_create_account_with_seed_decode_offsets( fd_system_program_instruction_create_account_with_seed_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_create_account_with_seed_encode( fd_system_program_instruction_create_account_with_seed_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_system_program_instruction_create_account_with_seed_destroy( fd_system_program_instruction_create_account_with_seed_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_system_program_instruction_create_account_with_seed_walk( void * w, fd_system_program_instruction_create_account_with_seed_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_system_program_instruction_create_account_with_seed_size( fd_system_program_instruction_create_account_with_seed_t const * self );
ulong fd_system_program_instruction_create_account_with_seed_footprint( void );
ulong fd_system_program_instruction_create_account_with_seed_align( void );

void fd_system_program_instruction_allocate_with_seed_new( fd_system_program_instruction_allocate_with_seed_t * self );
int fd_system_program_instruction_allocate_with_seed_decode( fd_system_program_instruction_allocate_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_allocate_with_seed_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_system_program_instruction_allocate_with_seed_decode_unsafe( fd_system_program_instruction_allocate_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_allocate_with_seed_decode_offsets( fd_system_program_instruction_allocate_with_seed_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_allocate_with_seed_encode( fd_system_program_instruction_allocate_with_seed_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_system_program_instruction_allocate_with_seed_destroy( fd_system_program_instruction_allocate_with_seed_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_system_program_instruction_allocate_with_seed_walk( void * w, fd_system_program_instruction_allocate_with_seed_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_system_program_instruction_allocate_with_seed_size( fd_system_program_instruction_allocate_with_seed_t const * self );
ulong fd_system_program_instruction_allocate_with_seed_footprint( void );
ulong fd_system_program_instruction_allocate_with_seed_align( void );

void fd_system_program_instruction_assign_with_seed_new( fd_system_program_instruction_assign_with_seed_t * self );
int fd_system_program_instruction_assign_with_seed_decode( fd_system_program_instruction_assign_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_assign_with_seed_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_system_program_instruction_assign_with_seed_decode_unsafe( fd_system_program_instruction_assign_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_assign_with_seed_decode_offsets( fd_system_program_instruction_assign_with_seed_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_assign_with_seed_encode( fd_system_program_instruction_assign_with_seed_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_system_program_instruction_assign_with_seed_destroy( fd_system_program_instruction_assign_with_seed_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_system_program_instruction_assign_with_seed_walk( void * w, fd_system_program_instruction_assign_with_seed_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_system_program_instruction_assign_with_seed_size( fd_system_program_instruction_assign_with_seed_t const * self );
ulong fd_system_program_instruction_assign_with_seed_footprint( void );
ulong fd_system_program_instruction_assign_with_seed_align( void );

void fd_system_program_instruction_transfer_with_seed_new( fd_system_program_instruction_transfer_with_seed_t * self );
int fd_system_program_instruction_transfer_with_seed_decode( fd_system_program_instruction_transfer_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_transfer_with_seed_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_system_program_instruction_transfer_with_seed_decode_unsafe( fd_system_program_instruction_transfer_with_seed_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_transfer_with_seed_decode_offsets( fd_system_program_instruction_transfer_with_seed_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_transfer_with_seed_encode( fd_system_program_instruction_transfer_with_seed_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_system_program_instruction_transfer_with_seed_destroy( fd_system_program_instruction_transfer_with_seed_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_system_program_instruction_transfer_with_seed_walk( void * w, fd_system_program_instruction_transfer_with_seed_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_system_program_instruction_transfer_with_seed_size( fd_system_program_instruction_transfer_with_seed_t const * self );
ulong fd_system_program_instruction_transfer_with_seed_footprint( void );
ulong fd_system_program_instruction_transfer_with_seed_align( void );

void fd_system_program_instruction_new_disc( fd_system_program_instruction_t * self, uint discriminant );
void fd_system_program_instruction_new( fd_system_program_instruction_t * self );
int fd_system_program_instruction_decode( fd_system_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_system_program_instruction_decode_unsafe( fd_system_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_program_instruction_encode( fd_system_program_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_system_program_instruction_destroy( fd_system_program_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_system_program_instruction_walk( void * w, fd_system_program_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_system_program_instruction_size( fd_system_program_instruction_t const * self );
ulong fd_system_program_instruction_footprint( void );
ulong fd_system_program_instruction_align( void );

FD_FN_PURE uchar fd_system_program_instruction_is_create_account( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_assign( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_transfer( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_create_account_with_seed( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_advance_nonce_account( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_withdraw_nonce_account( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_initialize_nonce_account( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_authorize_nonce_account( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_allocate( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_allocate_with_seed( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_assign_with_seed( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_transfer_with_seed( fd_system_program_instruction_t const * self );
FD_FN_PURE uchar fd_system_program_instruction_is_upgrade_nonce_account( fd_system_program_instruction_t const * self );
enum {
fd_system_program_instruction_enum_create_account = 0,
fd_system_program_instruction_enum_assign = 1,
fd_system_program_instruction_enum_transfer = 2,
fd_system_program_instruction_enum_create_account_with_seed = 3,
fd_system_program_instruction_enum_advance_nonce_account = 4,
fd_system_program_instruction_enum_withdraw_nonce_account = 5,
fd_system_program_instruction_enum_initialize_nonce_account = 6,
fd_system_program_instruction_enum_authorize_nonce_account = 7,
fd_system_program_instruction_enum_allocate = 8,
fd_system_program_instruction_enum_allocate_with_seed = 9,
fd_system_program_instruction_enum_assign_with_seed = 10,
fd_system_program_instruction_enum_transfer_with_seed = 11,
fd_system_program_instruction_enum_upgrade_nonce_account = 12,
}; 
void fd_system_error_new_disc( fd_system_error_t * self, uint discriminant );
void fd_system_error_new( fd_system_error_t * self );
int fd_system_error_decode( fd_system_error_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_error_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_system_error_decode_unsafe( fd_system_error_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_system_error_encode( fd_system_error_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_system_error_destroy( fd_system_error_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_system_error_walk( void * w, fd_system_error_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_system_error_size( fd_system_error_t const * self );
ulong fd_system_error_footprint( void );
ulong fd_system_error_align( void );

FD_FN_PURE uchar fd_system_error_is_account_already_in_use( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_result_with_negative_lamports( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_invalid_program_id( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_invalid_account_data_length( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_max_seed_length_exceeded( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_address_with_seed_mismatch( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_nonce_no_recent_blockhashes( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_nonce_blockhash_not_expired( fd_system_error_t const * self );
FD_FN_PURE uchar fd_system_error_is_nonce_unexpected_blockhash_value( fd_system_error_t const * self );
enum {
fd_system_error_enum_account_already_in_use = 0,
fd_system_error_enum_result_with_negative_lamports = 1,
fd_system_error_enum_invalid_program_id = 2,
fd_system_error_enum_invalid_account_data_length = 3,
fd_system_error_enum_max_seed_length_exceeded = 4,
fd_system_error_enum_address_with_seed_mismatch = 5,
fd_system_error_enum_nonce_no_recent_blockhashes = 6,
fd_system_error_enum_nonce_blockhash_not_expired = 7,
fd_system_error_enum_nonce_unexpected_blockhash_value = 8,
}; 
void fd_stake_authorized_new( fd_stake_authorized_t * self );
int fd_stake_authorized_decode( fd_stake_authorized_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_authorized_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_authorized_decode_unsafe( fd_stake_authorized_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_authorized_decode_offsets( fd_stake_authorized_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_authorized_encode( fd_stake_authorized_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_authorized_destroy( fd_stake_authorized_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_authorized_walk( void * w, fd_stake_authorized_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_authorized_size( fd_stake_authorized_t const * self );
ulong fd_stake_authorized_footprint( void );
ulong fd_stake_authorized_align( void );

void fd_stake_lockup_new( fd_stake_lockup_t * self );
int fd_stake_lockup_decode( fd_stake_lockup_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_lockup_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_lockup_decode_unsafe( fd_stake_lockup_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_lockup_decode_offsets( fd_stake_lockup_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_lockup_encode( fd_stake_lockup_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_lockup_destroy( fd_stake_lockup_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_lockup_walk( void * w, fd_stake_lockup_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_lockup_size( fd_stake_lockup_t const * self );
ulong fd_stake_lockup_footprint( void );
ulong fd_stake_lockup_align( void );

void fd_stake_instruction_initialize_new( fd_stake_instruction_initialize_t * self );
int fd_stake_instruction_initialize_decode( fd_stake_instruction_initialize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_initialize_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_instruction_initialize_decode_unsafe( fd_stake_instruction_initialize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_initialize_decode_offsets( fd_stake_instruction_initialize_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_initialize_encode( fd_stake_instruction_initialize_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_instruction_initialize_destroy( fd_stake_instruction_initialize_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_instruction_initialize_walk( void * w, fd_stake_instruction_initialize_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_instruction_initialize_size( fd_stake_instruction_initialize_t const * self );
ulong fd_stake_instruction_initialize_footprint( void );
ulong fd_stake_instruction_initialize_align( void );

void fd_stake_lockup_custodian_args_new( fd_stake_lockup_custodian_args_t * self );
int fd_stake_lockup_custodian_args_decode( fd_stake_lockup_custodian_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_lockup_custodian_args_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_lockup_custodian_args_decode_unsafe( fd_stake_lockup_custodian_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_lockup_custodian_args_decode_offsets( fd_stake_lockup_custodian_args_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_lockup_custodian_args_encode( fd_stake_lockup_custodian_args_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_lockup_custodian_args_destroy( fd_stake_lockup_custodian_args_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_lockup_custodian_args_walk( void * w, fd_stake_lockup_custodian_args_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_lockup_custodian_args_size( fd_stake_lockup_custodian_args_t const * self );
ulong fd_stake_lockup_custodian_args_footprint( void );
ulong fd_stake_lockup_custodian_args_align( void );

void fd_stake_authorize_new_disc( fd_stake_authorize_t * self, uint discriminant );
void fd_stake_authorize_new( fd_stake_authorize_t * self );
int fd_stake_authorize_decode( fd_stake_authorize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_authorize_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_authorize_decode_unsafe( fd_stake_authorize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_authorize_encode( fd_stake_authorize_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_authorize_destroy( fd_stake_authorize_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_authorize_walk( void * w, fd_stake_authorize_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_authorize_size( fd_stake_authorize_t const * self );
ulong fd_stake_authorize_footprint( void );
ulong fd_stake_authorize_align( void );

FD_FN_PURE uchar fd_stake_authorize_is_staker( fd_stake_authorize_t const * self );
FD_FN_PURE uchar fd_stake_authorize_is_withdrawer( fd_stake_authorize_t const * self );
enum {
fd_stake_authorize_enum_staker = 0,
fd_stake_authorize_enum_withdrawer = 1,
}; 
void fd_stake_instruction_authorize_new( fd_stake_instruction_authorize_t * self );
int fd_stake_instruction_authorize_decode( fd_stake_instruction_authorize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_authorize_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_instruction_authorize_decode_unsafe( fd_stake_instruction_authorize_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_authorize_decode_offsets( fd_stake_instruction_authorize_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_authorize_encode( fd_stake_instruction_authorize_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_instruction_authorize_destroy( fd_stake_instruction_authorize_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_instruction_authorize_walk( void * w, fd_stake_instruction_authorize_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_instruction_authorize_size( fd_stake_instruction_authorize_t const * self );
ulong fd_stake_instruction_authorize_footprint( void );
ulong fd_stake_instruction_authorize_align( void );

void fd_authorize_with_seed_args_new( fd_authorize_with_seed_args_t * self );
int fd_authorize_with_seed_args_decode( fd_authorize_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_authorize_with_seed_args_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_authorize_with_seed_args_decode_unsafe( fd_authorize_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_authorize_with_seed_args_decode_offsets( fd_authorize_with_seed_args_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_authorize_with_seed_args_encode( fd_authorize_with_seed_args_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_authorize_with_seed_args_destroy( fd_authorize_with_seed_args_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_authorize_with_seed_args_walk( void * w, fd_authorize_with_seed_args_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_authorize_with_seed_args_size( fd_authorize_with_seed_args_t const * self );
ulong fd_authorize_with_seed_args_footprint( void );
ulong fd_authorize_with_seed_args_align( void );

void fd_authorize_checked_with_seed_args_new( fd_authorize_checked_with_seed_args_t * self );
int fd_authorize_checked_with_seed_args_decode( fd_authorize_checked_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_authorize_checked_with_seed_args_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_authorize_checked_with_seed_args_decode_unsafe( fd_authorize_checked_with_seed_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_authorize_checked_with_seed_args_decode_offsets( fd_authorize_checked_with_seed_args_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_authorize_checked_with_seed_args_encode( fd_authorize_checked_with_seed_args_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_authorize_checked_with_seed_args_destroy( fd_authorize_checked_with_seed_args_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_authorize_checked_with_seed_args_walk( void * w, fd_authorize_checked_with_seed_args_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_authorize_checked_with_seed_args_size( fd_authorize_checked_with_seed_args_t const * self );
ulong fd_authorize_checked_with_seed_args_footprint( void );
ulong fd_authorize_checked_with_seed_args_align( void );

void fd_lockup_checked_args_new( fd_lockup_checked_args_t * self );
int fd_lockup_checked_args_decode( fd_lockup_checked_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockup_checked_args_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_lockup_checked_args_decode_unsafe( fd_lockup_checked_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockup_checked_args_decode_offsets( fd_lockup_checked_args_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockup_checked_args_encode( fd_lockup_checked_args_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_lockup_checked_args_destroy( fd_lockup_checked_args_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_lockup_checked_args_walk( void * w, fd_lockup_checked_args_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_lockup_checked_args_size( fd_lockup_checked_args_t const * self );
ulong fd_lockup_checked_args_footprint( void );
ulong fd_lockup_checked_args_align( void );

void fd_lockup_args_new( fd_lockup_args_t * self );
int fd_lockup_args_decode( fd_lockup_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockup_args_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_lockup_args_decode_unsafe( fd_lockup_args_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockup_args_decode_offsets( fd_lockup_args_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lockup_args_encode( fd_lockup_args_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_lockup_args_destroy( fd_lockup_args_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_lockup_args_walk( void * w, fd_lockup_args_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_lockup_args_size( fd_lockup_args_t const * self );
ulong fd_lockup_args_footprint( void );
ulong fd_lockup_args_align( void );

void fd_stake_instruction_new_disc( fd_stake_instruction_t * self, uint discriminant );
void fd_stake_instruction_new( fd_stake_instruction_t * self );
int fd_stake_instruction_decode( fd_stake_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_instruction_decode_unsafe( fd_stake_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_instruction_encode( fd_stake_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_instruction_destroy( fd_stake_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_instruction_walk( void * w, fd_stake_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_instruction_size( fd_stake_instruction_t const * self );
ulong fd_stake_instruction_footprint( void );
ulong fd_stake_instruction_align( void );

FD_FN_PURE uchar fd_stake_instruction_is_initialize( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_authorize( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_delegate_stake( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_split( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_withdraw( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_deactivate( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_set_lockup( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_merge( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_authorize_with_seed( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_initialize_checked( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_authorize_checked( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_authorize_checked_with_seed( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_set_lockup_checked( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_get_minimum_delegation( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_deactivate_delinquent( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_redelegate( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_move_stake( fd_stake_instruction_t const * self );
FD_FN_PURE uchar fd_stake_instruction_is_move_lamports( fd_stake_instruction_t const * self );
enum {
fd_stake_instruction_enum_initialize = 0,
fd_stake_instruction_enum_authorize = 1,
fd_stake_instruction_enum_delegate_stake = 2,
fd_stake_instruction_enum_split = 3,
fd_stake_instruction_enum_withdraw = 4,
fd_stake_instruction_enum_deactivate = 5,
fd_stake_instruction_enum_set_lockup = 6,
fd_stake_instruction_enum_merge = 7,
fd_stake_instruction_enum_authorize_with_seed = 8,
fd_stake_instruction_enum_initialize_checked = 9,
fd_stake_instruction_enum_authorize_checked = 10,
fd_stake_instruction_enum_authorize_checked_with_seed = 11,
fd_stake_instruction_enum_set_lockup_checked = 12,
fd_stake_instruction_enum_get_minimum_delegation = 13,
fd_stake_instruction_enum_deactivate_delinquent = 14,
fd_stake_instruction_enum_redelegate = 15,
fd_stake_instruction_enum_move_stake = 16,
fd_stake_instruction_enum_move_lamports = 17,
}; 
void fd_stake_meta_new( fd_stake_meta_t * self );
int fd_stake_meta_decode( fd_stake_meta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_meta_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_meta_decode_unsafe( fd_stake_meta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_meta_decode_offsets( fd_stake_meta_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_meta_encode( fd_stake_meta_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_meta_destroy( fd_stake_meta_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_meta_walk( void * w, fd_stake_meta_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_meta_size( fd_stake_meta_t const * self );
ulong fd_stake_meta_footprint( void );
ulong fd_stake_meta_align( void );

void fd_stake_flags_new( fd_stake_flags_t * self );
int fd_stake_flags_decode( fd_stake_flags_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_flags_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_flags_decode_unsafe( fd_stake_flags_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_flags_decode_offsets( fd_stake_flags_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_flags_encode( fd_stake_flags_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_flags_destroy( fd_stake_flags_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_flags_walk( void * w, fd_stake_flags_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_flags_size( fd_stake_flags_t const * self );
ulong fd_stake_flags_footprint( void );
ulong fd_stake_flags_align( void );

void fd_stake_state_v2_initialized_new( fd_stake_state_v2_initialized_t * self );
int fd_stake_state_v2_initialized_decode( fd_stake_state_v2_initialized_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_initialized_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_state_v2_initialized_decode_unsafe( fd_stake_state_v2_initialized_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_initialized_decode_offsets( fd_stake_state_v2_initialized_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_initialized_encode( fd_stake_state_v2_initialized_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_state_v2_initialized_destroy( fd_stake_state_v2_initialized_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_state_v2_initialized_walk( void * w, fd_stake_state_v2_initialized_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_state_v2_initialized_size( fd_stake_state_v2_initialized_t const * self );
ulong fd_stake_state_v2_initialized_footprint( void );
ulong fd_stake_state_v2_initialized_align( void );

void fd_stake_state_v2_stake_new( fd_stake_state_v2_stake_t * self );
int fd_stake_state_v2_stake_decode( fd_stake_state_v2_stake_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_stake_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_state_v2_stake_decode_unsafe( fd_stake_state_v2_stake_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_stake_decode_offsets( fd_stake_state_v2_stake_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_stake_encode( fd_stake_state_v2_stake_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_state_v2_stake_destroy( fd_stake_state_v2_stake_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_state_v2_stake_walk( void * w, fd_stake_state_v2_stake_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_state_v2_stake_size( fd_stake_state_v2_stake_t const * self );
ulong fd_stake_state_v2_stake_footprint( void );
ulong fd_stake_state_v2_stake_align( void );

void fd_stake_state_v2_new_disc( fd_stake_state_v2_t * self, uint discriminant );
void fd_stake_state_v2_new( fd_stake_state_v2_t * self );
int fd_stake_state_v2_decode( fd_stake_state_v2_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_stake_state_v2_decode_unsafe( fd_stake_state_v2_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_stake_state_v2_encode( fd_stake_state_v2_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_stake_state_v2_destroy( fd_stake_state_v2_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_stake_state_v2_walk( void * w, fd_stake_state_v2_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_stake_state_v2_size( fd_stake_state_v2_t const * self );
ulong fd_stake_state_v2_footprint( void );
ulong fd_stake_state_v2_align( void );

FD_FN_PURE uchar fd_stake_state_v2_is_uninitialized( fd_stake_state_v2_t const * self );
FD_FN_PURE uchar fd_stake_state_v2_is_initialized( fd_stake_state_v2_t const * self );
FD_FN_PURE uchar fd_stake_state_v2_is_stake( fd_stake_state_v2_t const * self );
FD_FN_PURE uchar fd_stake_state_v2_is_rewards_pool( fd_stake_state_v2_t const * self );
enum {
fd_stake_state_v2_enum_uninitialized = 0,
fd_stake_state_v2_enum_initialized = 1,
fd_stake_state_v2_enum_stake = 2,
fd_stake_state_v2_enum_rewards_pool = 3,
}; 
void fd_nonce_data_new( fd_nonce_data_t * self );
int fd_nonce_data_decode( fd_nonce_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_nonce_data_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_nonce_data_decode_unsafe( fd_nonce_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_nonce_data_decode_offsets( fd_nonce_data_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_nonce_data_encode( fd_nonce_data_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_nonce_data_destroy( fd_nonce_data_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_nonce_data_walk( void * w, fd_nonce_data_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_nonce_data_size( fd_nonce_data_t const * self );
ulong fd_nonce_data_footprint( void );
ulong fd_nonce_data_align( void );

void fd_nonce_state_new_disc( fd_nonce_state_t * self, uint discriminant );
void fd_nonce_state_new( fd_nonce_state_t * self );
int fd_nonce_state_decode( fd_nonce_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_nonce_state_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_nonce_state_decode_unsafe( fd_nonce_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_nonce_state_encode( fd_nonce_state_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_nonce_state_destroy( fd_nonce_state_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_nonce_state_walk( void * w, fd_nonce_state_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_nonce_state_size( fd_nonce_state_t const * self );
ulong fd_nonce_state_footprint( void );
ulong fd_nonce_state_align( void );

FD_FN_PURE uchar fd_nonce_state_is_uninitialized( fd_nonce_state_t const * self );
FD_FN_PURE uchar fd_nonce_state_is_initialized( fd_nonce_state_t const * self );
enum {
fd_nonce_state_enum_uninitialized = 0,
fd_nonce_state_enum_initialized = 1,
}; 
void fd_nonce_state_versions_new_disc( fd_nonce_state_versions_t * self, uint discriminant );
void fd_nonce_state_versions_new( fd_nonce_state_versions_t * self );
int fd_nonce_state_versions_decode( fd_nonce_state_versions_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_nonce_state_versions_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_nonce_state_versions_decode_unsafe( fd_nonce_state_versions_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_nonce_state_versions_encode( fd_nonce_state_versions_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_nonce_state_versions_destroy( fd_nonce_state_versions_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_nonce_state_versions_walk( void * w, fd_nonce_state_versions_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_nonce_state_versions_size( fd_nonce_state_versions_t const * self );
ulong fd_nonce_state_versions_footprint( void );
ulong fd_nonce_state_versions_align( void );

FD_FN_PURE uchar fd_nonce_state_versions_is_legacy( fd_nonce_state_versions_t const * self );
FD_FN_PURE uchar fd_nonce_state_versions_is_current( fd_nonce_state_versions_t const * self );
enum {
fd_nonce_state_versions_enum_legacy = 0,
fd_nonce_state_versions_enum_current = 1,
}; 
void fd_compute_budget_program_instruction_request_units_deprecated_new( fd_compute_budget_program_instruction_request_units_deprecated_t * self );
int fd_compute_budget_program_instruction_request_units_deprecated_decode( fd_compute_budget_program_instruction_request_units_deprecated_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compute_budget_program_instruction_request_units_deprecated_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_compute_budget_program_instruction_request_units_deprecated_decode_unsafe( fd_compute_budget_program_instruction_request_units_deprecated_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compute_budget_program_instruction_request_units_deprecated_decode_offsets( fd_compute_budget_program_instruction_request_units_deprecated_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compute_budget_program_instruction_request_units_deprecated_encode( fd_compute_budget_program_instruction_request_units_deprecated_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_compute_budget_program_instruction_request_units_deprecated_destroy( fd_compute_budget_program_instruction_request_units_deprecated_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_compute_budget_program_instruction_request_units_deprecated_walk( void * w, fd_compute_budget_program_instruction_request_units_deprecated_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_compute_budget_program_instruction_request_units_deprecated_size( fd_compute_budget_program_instruction_request_units_deprecated_t const * self );
ulong fd_compute_budget_program_instruction_request_units_deprecated_footprint( void );
ulong fd_compute_budget_program_instruction_request_units_deprecated_align( void );

void fd_compute_budget_program_instruction_new_disc( fd_compute_budget_program_instruction_t * self, uint discriminant );
void fd_compute_budget_program_instruction_new( fd_compute_budget_program_instruction_t * self );
int fd_compute_budget_program_instruction_decode( fd_compute_budget_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compute_budget_program_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_compute_budget_program_instruction_decode_unsafe( fd_compute_budget_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_compute_budget_program_instruction_encode( fd_compute_budget_program_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_compute_budget_program_instruction_destroy( fd_compute_budget_program_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_compute_budget_program_instruction_walk( void * w, fd_compute_budget_program_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_compute_budget_program_instruction_size( fd_compute_budget_program_instruction_t const * self );
ulong fd_compute_budget_program_instruction_footprint( void );
ulong fd_compute_budget_program_instruction_align( void );

FD_FN_PURE uchar fd_compute_budget_program_instruction_is_request_units_deprecated( fd_compute_budget_program_instruction_t const * self );
FD_FN_PURE uchar fd_compute_budget_program_instruction_is_request_heap_frame( fd_compute_budget_program_instruction_t const * self );
FD_FN_PURE uchar fd_compute_budget_program_instruction_is_set_compute_unit_limit( fd_compute_budget_program_instruction_t const * self );
FD_FN_PURE uchar fd_compute_budget_program_instruction_is_set_compute_unit_price( fd_compute_budget_program_instruction_t const * self );
FD_FN_PURE uchar fd_compute_budget_program_instruction_is_set_loaded_accounts_data_size_limit( fd_compute_budget_program_instruction_t const * self );
enum {
fd_compute_budget_program_instruction_enum_request_units_deprecated = 0,
fd_compute_budget_program_instruction_enum_request_heap_frame = 1,
fd_compute_budget_program_instruction_enum_set_compute_unit_limit = 2,
fd_compute_budget_program_instruction_enum_set_compute_unit_price = 3,
fd_compute_budget_program_instruction_enum_set_loaded_accounts_data_size_limit = 4,
}; 
void fd_config_keys_new( fd_config_keys_t * self );
int fd_config_keys_decode( fd_config_keys_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_config_keys_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_config_keys_decode_unsafe( fd_config_keys_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_config_keys_decode_offsets( fd_config_keys_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_config_keys_encode( fd_config_keys_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_config_keys_destroy( fd_config_keys_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_config_keys_walk( void * w, fd_config_keys_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_config_keys_size( fd_config_keys_t const * self );
ulong fd_config_keys_footprint( void );
ulong fd_config_keys_align( void );

void fd_bpf_loader_program_instruction_write_new( fd_bpf_loader_program_instruction_write_t * self );
int fd_bpf_loader_program_instruction_write_decode( fd_bpf_loader_program_instruction_write_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_loader_program_instruction_write_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_loader_program_instruction_write_decode_unsafe( fd_bpf_loader_program_instruction_write_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_loader_program_instruction_write_decode_offsets( fd_bpf_loader_program_instruction_write_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_loader_program_instruction_write_encode( fd_bpf_loader_program_instruction_write_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_loader_program_instruction_write_destroy( fd_bpf_loader_program_instruction_write_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_loader_program_instruction_write_walk( void * w, fd_bpf_loader_program_instruction_write_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_loader_program_instruction_write_size( fd_bpf_loader_program_instruction_write_t const * self );
ulong fd_bpf_loader_program_instruction_write_footprint( void );
ulong fd_bpf_loader_program_instruction_write_align( void );

void fd_bpf_loader_program_instruction_new_disc( fd_bpf_loader_program_instruction_t * self, uint discriminant );
void fd_bpf_loader_program_instruction_new( fd_bpf_loader_program_instruction_t * self );
int fd_bpf_loader_program_instruction_decode( fd_bpf_loader_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_loader_program_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_loader_program_instruction_decode_unsafe( fd_bpf_loader_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_loader_program_instruction_encode( fd_bpf_loader_program_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_loader_program_instruction_destroy( fd_bpf_loader_program_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_loader_program_instruction_walk( void * w, fd_bpf_loader_program_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_loader_program_instruction_size( fd_bpf_loader_program_instruction_t const * self );
ulong fd_bpf_loader_program_instruction_footprint( void );
ulong fd_bpf_loader_program_instruction_align( void );

FD_FN_PURE uchar fd_bpf_loader_program_instruction_is_write( fd_bpf_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_loader_program_instruction_is_finalize( fd_bpf_loader_program_instruction_t const * self );
enum {
fd_bpf_loader_program_instruction_enum_write = 0,
fd_bpf_loader_program_instruction_enum_finalize = 1,
}; 
void fd_loader_v4_program_instruction_write_new( fd_loader_v4_program_instruction_write_t * self );
int fd_loader_v4_program_instruction_write_decode( fd_loader_v4_program_instruction_write_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_write_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_loader_v4_program_instruction_write_decode_unsafe( fd_loader_v4_program_instruction_write_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_write_decode_offsets( fd_loader_v4_program_instruction_write_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_write_encode( fd_loader_v4_program_instruction_write_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_loader_v4_program_instruction_write_destroy( fd_loader_v4_program_instruction_write_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_loader_v4_program_instruction_write_walk( void * w, fd_loader_v4_program_instruction_write_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_loader_v4_program_instruction_write_size( fd_loader_v4_program_instruction_write_t const * self );
ulong fd_loader_v4_program_instruction_write_footprint( void );
ulong fd_loader_v4_program_instruction_write_align( void );

void fd_loader_v4_program_instruction_truncate_new( fd_loader_v4_program_instruction_truncate_t * self );
int fd_loader_v4_program_instruction_truncate_decode( fd_loader_v4_program_instruction_truncate_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_truncate_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_loader_v4_program_instruction_truncate_decode_unsafe( fd_loader_v4_program_instruction_truncate_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_truncate_decode_offsets( fd_loader_v4_program_instruction_truncate_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_truncate_encode( fd_loader_v4_program_instruction_truncate_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_loader_v4_program_instruction_truncate_destroy( fd_loader_v4_program_instruction_truncate_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_loader_v4_program_instruction_truncate_walk( void * w, fd_loader_v4_program_instruction_truncate_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_loader_v4_program_instruction_truncate_size( fd_loader_v4_program_instruction_truncate_t const * self );
ulong fd_loader_v4_program_instruction_truncate_footprint( void );
ulong fd_loader_v4_program_instruction_truncate_align( void );

void fd_loader_v4_program_instruction_new_disc( fd_loader_v4_program_instruction_t * self, uint discriminant );
void fd_loader_v4_program_instruction_new( fd_loader_v4_program_instruction_t * self );
int fd_loader_v4_program_instruction_decode( fd_loader_v4_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_loader_v4_program_instruction_decode_unsafe( fd_loader_v4_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_program_instruction_encode( fd_loader_v4_program_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_loader_v4_program_instruction_destroy( fd_loader_v4_program_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_loader_v4_program_instruction_walk( void * w, fd_loader_v4_program_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_loader_v4_program_instruction_size( fd_loader_v4_program_instruction_t const * self );
ulong fd_loader_v4_program_instruction_footprint( void );
ulong fd_loader_v4_program_instruction_align( void );

FD_FN_PURE uchar fd_loader_v4_program_instruction_is_write( fd_loader_v4_program_instruction_t const * self );
FD_FN_PURE uchar fd_loader_v4_program_instruction_is_truncate( fd_loader_v4_program_instruction_t const * self );
FD_FN_PURE uchar fd_loader_v4_program_instruction_is_deploy( fd_loader_v4_program_instruction_t const * self );
FD_FN_PURE uchar fd_loader_v4_program_instruction_is_retract( fd_loader_v4_program_instruction_t const * self );
FD_FN_PURE uchar fd_loader_v4_program_instruction_is_transfer_authority( fd_loader_v4_program_instruction_t const * self );
FD_FN_PURE uchar fd_loader_v4_program_instruction_is_finalize( fd_loader_v4_program_instruction_t const * self );
enum {
fd_loader_v4_program_instruction_enum_write = 0,
fd_loader_v4_program_instruction_enum_truncate = 1,
fd_loader_v4_program_instruction_enum_deploy = 2,
fd_loader_v4_program_instruction_enum_retract = 3,
fd_loader_v4_program_instruction_enum_transfer_authority = 4,
fd_loader_v4_program_instruction_enum_finalize = 5,
}; 
void fd_bpf_upgradeable_loader_program_instruction_write_new( fd_bpf_upgradeable_loader_program_instruction_write_t * self );
int fd_bpf_upgradeable_loader_program_instruction_write_decode( fd_bpf_upgradeable_loader_program_instruction_write_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_write_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_write_decode_unsafe( fd_bpf_upgradeable_loader_program_instruction_write_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_write_decode_offsets( fd_bpf_upgradeable_loader_program_instruction_write_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_write_encode( fd_bpf_upgradeable_loader_program_instruction_write_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_write_destroy( fd_bpf_upgradeable_loader_program_instruction_write_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_write_walk( void * w, fd_bpf_upgradeable_loader_program_instruction_write_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_program_instruction_write_size( fd_bpf_upgradeable_loader_program_instruction_write_t const * self );
ulong fd_bpf_upgradeable_loader_program_instruction_write_footprint( void );
ulong fd_bpf_upgradeable_loader_program_instruction_write_align( void );

void fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_new( fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t * self );
int fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_decode( fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_decode_unsafe( fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_decode_offsets( fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_encode( fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_destroy( fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_walk( void * w, fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_size( fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_t const * self );
ulong fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_footprint( void );
ulong fd_bpf_upgradeable_loader_program_instruction_deploy_with_max_data_len_align( void );

void fd_bpf_upgradeable_loader_program_instruction_extend_program_new( fd_bpf_upgradeable_loader_program_instruction_extend_program_t * self );
int fd_bpf_upgradeable_loader_program_instruction_extend_program_decode( fd_bpf_upgradeable_loader_program_instruction_extend_program_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_extend_program_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_extend_program_decode_unsafe( fd_bpf_upgradeable_loader_program_instruction_extend_program_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_extend_program_decode_offsets( fd_bpf_upgradeable_loader_program_instruction_extend_program_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_extend_program_encode( fd_bpf_upgradeable_loader_program_instruction_extend_program_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_extend_program_destroy( fd_bpf_upgradeable_loader_program_instruction_extend_program_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_extend_program_walk( void * w, fd_bpf_upgradeable_loader_program_instruction_extend_program_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_program_instruction_extend_program_size( fd_bpf_upgradeable_loader_program_instruction_extend_program_t const * self );
ulong fd_bpf_upgradeable_loader_program_instruction_extend_program_footprint( void );
ulong fd_bpf_upgradeable_loader_program_instruction_extend_program_align( void );

void fd_bpf_upgradeable_loader_program_instruction_new_disc( fd_bpf_upgradeable_loader_program_instruction_t * self, uint discriminant );
void fd_bpf_upgradeable_loader_program_instruction_new( fd_bpf_upgradeable_loader_program_instruction_t * self );
int fd_bpf_upgradeable_loader_program_instruction_decode( fd_bpf_upgradeable_loader_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_decode_unsafe( fd_bpf_upgradeable_loader_program_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_program_instruction_encode( fd_bpf_upgradeable_loader_program_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_destroy( fd_bpf_upgradeable_loader_program_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_program_instruction_walk( void * w, fd_bpf_upgradeable_loader_program_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_program_instruction_size( fd_bpf_upgradeable_loader_program_instruction_t const * self );
ulong fd_bpf_upgradeable_loader_program_instruction_footprint( void );
ulong fd_bpf_upgradeable_loader_program_instruction_align( void );

FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_initialize_buffer( fd_bpf_upgradeable_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_write( fd_bpf_upgradeable_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_deploy_with_max_data_len( fd_bpf_upgradeable_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_upgrade( fd_bpf_upgradeable_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_set_authority( fd_bpf_upgradeable_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_close( fd_bpf_upgradeable_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_extend_program( fd_bpf_upgradeable_loader_program_instruction_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_program_instruction_is_set_authority_checked( fd_bpf_upgradeable_loader_program_instruction_t const * self );
enum {
fd_bpf_upgradeable_loader_program_instruction_enum_initialize_buffer = 0,
fd_bpf_upgradeable_loader_program_instruction_enum_write = 1,
fd_bpf_upgradeable_loader_program_instruction_enum_deploy_with_max_data_len = 2,
fd_bpf_upgradeable_loader_program_instruction_enum_upgrade = 3,
fd_bpf_upgradeable_loader_program_instruction_enum_set_authority = 4,
fd_bpf_upgradeable_loader_program_instruction_enum_close = 5,
fd_bpf_upgradeable_loader_program_instruction_enum_extend_program = 6,
fd_bpf_upgradeable_loader_program_instruction_enum_set_authority_checked = 7,
}; 
void fd_bpf_upgradeable_loader_state_buffer_new( fd_bpf_upgradeable_loader_state_buffer_t * self );
int fd_bpf_upgradeable_loader_state_buffer_decode( fd_bpf_upgradeable_loader_state_buffer_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_buffer_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_buffer_decode_unsafe( fd_bpf_upgradeable_loader_state_buffer_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_buffer_decode_offsets( fd_bpf_upgradeable_loader_state_buffer_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_buffer_encode( fd_bpf_upgradeable_loader_state_buffer_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_buffer_destroy( fd_bpf_upgradeable_loader_state_buffer_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_buffer_walk( void * w, fd_bpf_upgradeable_loader_state_buffer_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_state_buffer_size( fd_bpf_upgradeable_loader_state_buffer_t const * self );
ulong fd_bpf_upgradeable_loader_state_buffer_footprint( void );
ulong fd_bpf_upgradeable_loader_state_buffer_align( void );

void fd_bpf_upgradeable_loader_state_program_new( fd_bpf_upgradeable_loader_state_program_t * self );
int fd_bpf_upgradeable_loader_state_program_decode( fd_bpf_upgradeable_loader_state_program_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_program_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_program_decode_unsafe( fd_bpf_upgradeable_loader_state_program_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_program_decode_offsets( fd_bpf_upgradeable_loader_state_program_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_program_encode( fd_bpf_upgradeable_loader_state_program_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_program_destroy( fd_bpf_upgradeable_loader_state_program_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_program_walk( void * w, fd_bpf_upgradeable_loader_state_program_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_state_program_size( fd_bpf_upgradeable_loader_state_program_t const * self );
ulong fd_bpf_upgradeable_loader_state_program_footprint( void );
ulong fd_bpf_upgradeable_loader_state_program_align( void );

void fd_bpf_upgradeable_loader_state_program_data_new( fd_bpf_upgradeable_loader_state_program_data_t * self );
int fd_bpf_upgradeable_loader_state_program_data_decode( fd_bpf_upgradeable_loader_state_program_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_program_data_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_program_data_decode_unsafe( fd_bpf_upgradeable_loader_state_program_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_program_data_decode_offsets( fd_bpf_upgradeable_loader_state_program_data_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_program_data_encode( fd_bpf_upgradeable_loader_state_program_data_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_program_data_destroy( fd_bpf_upgradeable_loader_state_program_data_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_program_data_walk( void * w, fd_bpf_upgradeable_loader_state_program_data_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_state_program_data_size( fd_bpf_upgradeable_loader_state_program_data_t const * self );
ulong fd_bpf_upgradeable_loader_state_program_data_footprint( void );
ulong fd_bpf_upgradeable_loader_state_program_data_align( void );

void fd_bpf_upgradeable_loader_state_new_disc( fd_bpf_upgradeable_loader_state_t * self, uint discriminant );
void fd_bpf_upgradeable_loader_state_new( fd_bpf_upgradeable_loader_state_t * self );
int fd_bpf_upgradeable_loader_state_decode( fd_bpf_upgradeable_loader_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_decode_unsafe( fd_bpf_upgradeable_loader_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bpf_upgradeable_loader_state_encode( fd_bpf_upgradeable_loader_state_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_destroy( fd_bpf_upgradeable_loader_state_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bpf_upgradeable_loader_state_walk( void * w, fd_bpf_upgradeable_loader_state_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bpf_upgradeable_loader_state_size( fd_bpf_upgradeable_loader_state_t const * self );
ulong fd_bpf_upgradeable_loader_state_footprint( void );
ulong fd_bpf_upgradeable_loader_state_align( void );

FD_FN_PURE uchar fd_bpf_upgradeable_loader_state_is_uninitialized( fd_bpf_upgradeable_loader_state_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_state_is_buffer( fd_bpf_upgradeable_loader_state_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_state_is_program( fd_bpf_upgradeable_loader_state_t const * self );
FD_FN_PURE uchar fd_bpf_upgradeable_loader_state_is_program_data( fd_bpf_upgradeable_loader_state_t const * self );
enum {
fd_bpf_upgradeable_loader_state_enum_uninitialized = 0,
fd_bpf_upgradeable_loader_state_enum_buffer = 1,
fd_bpf_upgradeable_loader_state_enum_program = 2,
fd_bpf_upgradeable_loader_state_enum_program_data = 3,
}; 
void fd_loader_v4_state_new( fd_loader_v4_state_t * self );
int fd_loader_v4_state_decode( fd_loader_v4_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_state_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_loader_v4_state_decode_unsafe( fd_loader_v4_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_state_decode_offsets( fd_loader_v4_state_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_loader_v4_state_encode( fd_loader_v4_state_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_loader_v4_state_destroy( fd_loader_v4_state_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_loader_v4_state_walk( void * w, fd_loader_v4_state_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_loader_v4_state_size( fd_loader_v4_state_t const * self );
ulong fd_loader_v4_state_footprint( void );
ulong fd_loader_v4_state_align( void );

void fd_frozen_hash_status_new( fd_frozen_hash_status_t * self );
int fd_frozen_hash_status_decode( fd_frozen_hash_status_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_frozen_hash_status_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_frozen_hash_status_decode_unsafe( fd_frozen_hash_status_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_frozen_hash_status_decode_offsets( fd_frozen_hash_status_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_frozen_hash_status_encode( fd_frozen_hash_status_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_frozen_hash_status_destroy( fd_frozen_hash_status_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_frozen_hash_status_walk( void * w, fd_frozen_hash_status_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_frozen_hash_status_size( fd_frozen_hash_status_t const * self );
ulong fd_frozen_hash_status_footprint( void );
ulong fd_frozen_hash_status_align( void );

void fd_frozen_hash_versioned_new_disc( fd_frozen_hash_versioned_t * self, uint discriminant );
void fd_frozen_hash_versioned_new( fd_frozen_hash_versioned_t * self );
int fd_frozen_hash_versioned_decode( fd_frozen_hash_versioned_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_frozen_hash_versioned_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_frozen_hash_versioned_decode_unsafe( fd_frozen_hash_versioned_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_frozen_hash_versioned_encode( fd_frozen_hash_versioned_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_frozen_hash_versioned_destroy( fd_frozen_hash_versioned_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_frozen_hash_versioned_walk( void * w, fd_frozen_hash_versioned_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_frozen_hash_versioned_size( fd_frozen_hash_versioned_t const * self );
ulong fd_frozen_hash_versioned_footprint( void );
ulong fd_frozen_hash_versioned_align( void );

FD_FN_PURE uchar fd_frozen_hash_versioned_is_current( fd_frozen_hash_versioned_t const * self );
enum {
fd_frozen_hash_versioned_enum_current = 0,
}; 
void fd_lookup_table_meta_new( fd_lookup_table_meta_t * self );
int fd_lookup_table_meta_decode( fd_lookup_table_meta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lookup_table_meta_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_lookup_table_meta_decode_unsafe( fd_lookup_table_meta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lookup_table_meta_decode_offsets( fd_lookup_table_meta_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_lookup_table_meta_encode( fd_lookup_table_meta_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_lookup_table_meta_destroy( fd_lookup_table_meta_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_lookup_table_meta_walk( void * w, fd_lookup_table_meta_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_lookup_table_meta_size( fd_lookup_table_meta_t const * self );
ulong fd_lookup_table_meta_footprint( void );
ulong fd_lookup_table_meta_align( void );

void fd_address_lookup_table_new( fd_address_lookup_table_t * self );
int fd_address_lookup_table_decode( fd_address_lookup_table_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_address_lookup_table_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_address_lookup_table_decode_unsafe( fd_address_lookup_table_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_address_lookup_table_decode_offsets( fd_address_lookup_table_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_address_lookup_table_encode( fd_address_lookup_table_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_address_lookup_table_destroy( fd_address_lookup_table_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_address_lookup_table_walk( void * w, fd_address_lookup_table_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_address_lookup_table_size( fd_address_lookup_table_t const * self );
ulong fd_address_lookup_table_footprint( void );
ulong fd_address_lookup_table_align( void );

void fd_address_lookup_table_state_new_disc( fd_address_lookup_table_state_t * self, uint discriminant );
void fd_address_lookup_table_state_new( fd_address_lookup_table_state_t * self );
int fd_address_lookup_table_state_decode( fd_address_lookup_table_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_address_lookup_table_state_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_address_lookup_table_state_decode_unsafe( fd_address_lookup_table_state_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_address_lookup_table_state_encode( fd_address_lookup_table_state_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_address_lookup_table_state_destroy( fd_address_lookup_table_state_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_address_lookup_table_state_walk( void * w, fd_address_lookup_table_state_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_address_lookup_table_state_size( fd_address_lookup_table_state_t const * self );
ulong fd_address_lookup_table_state_footprint( void );
ulong fd_address_lookup_table_state_align( void );

FD_FN_PURE uchar fd_address_lookup_table_state_is_uninitialized( fd_address_lookup_table_state_t const * self );
FD_FN_PURE uchar fd_address_lookup_table_state_is_lookup_table( fd_address_lookup_table_state_t const * self );
enum {
fd_address_lookup_table_state_enum_uninitialized = 0,
fd_address_lookup_table_state_enum_lookup_table = 1,
}; 
void fd_gossip_bitvec_u8_inner_new( fd_gossip_bitvec_u8_inner_t * self );
int fd_gossip_bitvec_u8_inner_decode( fd_gossip_bitvec_u8_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u8_inner_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_bitvec_u8_inner_decode_unsafe( fd_gossip_bitvec_u8_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u8_inner_decode_offsets( fd_gossip_bitvec_u8_inner_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u8_inner_encode( fd_gossip_bitvec_u8_inner_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_bitvec_u8_inner_destroy( fd_gossip_bitvec_u8_inner_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_bitvec_u8_inner_walk( void * w, fd_gossip_bitvec_u8_inner_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_bitvec_u8_inner_size( fd_gossip_bitvec_u8_inner_t const * self );
ulong fd_gossip_bitvec_u8_inner_footprint( void );
ulong fd_gossip_bitvec_u8_inner_align( void );

void fd_gossip_bitvec_u8_new( fd_gossip_bitvec_u8_t * self );
int fd_gossip_bitvec_u8_decode( fd_gossip_bitvec_u8_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u8_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_bitvec_u8_decode_unsafe( fd_gossip_bitvec_u8_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u8_decode_offsets( fd_gossip_bitvec_u8_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u8_encode( fd_gossip_bitvec_u8_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_bitvec_u8_destroy( fd_gossip_bitvec_u8_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_bitvec_u8_walk( void * w, fd_gossip_bitvec_u8_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_bitvec_u8_size( fd_gossip_bitvec_u8_t const * self );
ulong fd_gossip_bitvec_u8_footprint( void );
ulong fd_gossip_bitvec_u8_align( void );

void fd_gossip_bitvec_u64_inner_new( fd_gossip_bitvec_u64_inner_t * self );
int fd_gossip_bitvec_u64_inner_decode( fd_gossip_bitvec_u64_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u64_inner_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_bitvec_u64_inner_decode_unsafe( fd_gossip_bitvec_u64_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u64_inner_decode_offsets( fd_gossip_bitvec_u64_inner_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u64_inner_encode( fd_gossip_bitvec_u64_inner_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_bitvec_u64_inner_destroy( fd_gossip_bitvec_u64_inner_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_bitvec_u64_inner_walk( void * w, fd_gossip_bitvec_u64_inner_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_bitvec_u64_inner_size( fd_gossip_bitvec_u64_inner_t const * self );
ulong fd_gossip_bitvec_u64_inner_footprint( void );
ulong fd_gossip_bitvec_u64_inner_align( void );

void fd_gossip_bitvec_u64_new( fd_gossip_bitvec_u64_t * self );
int fd_gossip_bitvec_u64_decode( fd_gossip_bitvec_u64_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u64_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_bitvec_u64_decode_unsafe( fd_gossip_bitvec_u64_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u64_decode_offsets( fd_gossip_bitvec_u64_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_bitvec_u64_encode( fd_gossip_bitvec_u64_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_bitvec_u64_destroy( fd_gossip_bitvec_u64_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_bitvec_u64_walk( void * w, fd_gossip_bitvec_u64_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_bitvec_u64_size( fd_gossip_bitvec_u64_t const * self );
ulong fd_gossip_bitvec_u64_footprint( void );
ulong fd_gossip_bitvec_u64_align( void );

void fd_gossip_ping_new( fd_gossip_ping_t * self );
int fd_gossip_ping_decode( fd_gossip_ping_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ping_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_ping_decode_unsafe( fd_gossip_ping_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ping_decode_offsets( fd_gossip_ping_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ping_encode( fd_gossip_ping_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_ping_destroy( fd_gossip_ping_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_ping_walk( void * w, fd_gossip_ping_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_ping_size( fd_gossip_ping_t const * self );
ulong fd_gossip_ping_footprint( void );
ulong fd_gossip_ping_align( void );

void fd_gossip_ip_addr_new_disc( fd_gossip_ip_addr_t * self, uint discriminant );
void fd_gossip_ip_addr_new( fd_gossip_ip_addr_t * self );
int fd_gossip_ip_addr_decode( fd_gossip_ip_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ip_addr_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_ip_addr_decode_unsafe( fd_gossip_ip_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_ip_addr_encode( fd_gossip_ip_addr_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_ip_addr_destroy( fd_gossip_ip_addr_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_ip_addr_walk( void * w, fd_gossip_ip_addr_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_ip_addr_size( fd_gossip_ip_addr_t const * self );
ulong fd_gossip_ip_addr_footprint( void );
ulong fd_gossip_ip_addr_align( void );

FD_FN_PURE uchar fd_gossip_ip_addr_is_ip4( fd_gossip_ip_addr_t const * self );
FD_FN_PURE uchar fd_gossip_ip_addr_is_ip6( fd_gossip_ip_addr_t const * self );
enum {
fd_gossip_ip_addr_enum_ip4 = 0,
fd_gossip_ip_addr_enum_ip6 = 1,
}; 
void fd_gossip_prune_data_new( fd_gossip_prune_data_t * self );
int fd_gossip_prune_data_decode( fd_gossip_prune_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_data_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_prune_data_decode_unsafe( fd_gossip_prune_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_data_decode_offsets( fd_gossip_prune_data_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_data_encode( fd_gossip_prune_data_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_prune_data_destroy( fd_gossip_prune_data_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_prune_data_walk( void * w, fd_gossip_prune_data_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_prune_data_size( fd_gossip_prune_data_t const * self );
ulong fd_gossip_prune_data_footprint( void );
ulong fd_gossip_prune_data_align( void );

void fd_gossip_prune_sign_data_new( fd_gossip_prune_sign_data_t * self );
int fd_gossip_prune_sign_data_decode( fd_gossip_prune_sign_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_sign_data_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_prune_sign_data_decode_unsafe( fd_gossip_prune_sign_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_sign_data_decode_offsets( fd_gossip_prune_sign_data_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_sign_data_encode( fd_gossip_prune_sign_data_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_prune_sign_data_destroy( fd_gossip_prune_sign_data_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_prune_sign_data_walk( void * w, fd_gossip_prune_sign_data_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_prune_sign_data_size( fd_gossip_prune_sign_data_t const * self );
ulong fd_gossip_prune_sign_data_footprint( void );
ulong fd_gossip_prune_sign_data_align( void );

void fd_gossip_prune_sign_data_with_prefix_new( fd_gossip_prune_sign_data_with_prefix_t * self );
int fd_gossip_prune_sign_data_with_prefix_decode( fd_gossip_prune_sign_data_with_prefix_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_sign_data_with_prefix_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_prune_sign_data_with_prefix_decode_unsafe( fd_gossip_prune_sign_data_with_prefix_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_sign_data_with_prefix_decode_offsets( fd_gossip_prune_sign_data_with_prefix_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_sign_data_with_prefix_encode( fd_gossip_prune_sign_data_with_prefix_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_prune_sign_data_with_prefix_destroy( fd_gossip_prune_sign_data_with_prefix_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_prune_sign_data_with_prefix_walk( void * w, fd_gossip_prune_sign_data_with_prefix_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_prune_sign_data_with_prefix_size( fd_gossip_prune_sign_data_with_prefix_t const * self );
ulong fd_gossip_prune_sign_data_with_prefix_footprint( void );
ulong fd_gossip_prune_sign_data_with_prefix_align( void );

void fd_gossip_socket_addr_old_new( fd_gossip_socket_addr_old_t * self );
int fd_gossip_socket_addr_old_decode( fd_gossip_socket_addr_old_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_old_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_socket_addr_old_decode_unsafe( fd_gossip_socket_addr_old_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_old_decode_offsets( fd_gossip_socket_addr_old_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_old_encode( fd_gossip_socket_addr_old_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_socket_addr_old_destroy( fd_gossip_socket_addr_old_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_socket_addr_old_walk( void * w, fd_gossip_socket_addr_old_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_socket_addr_old_size( fd_gossip_socket_addr_old_t const * self );
ulong fd_gossip_socket_addr_old_footprint( void );
ulong fd_gossip_socket_addr_old_align( void );

void fd_gossip_socket_addr_ip4_new( fd_gossip_socket_addr_ip4_t * self );
int fd_gossip_socket_addr_ip4_decode( fd_gossip_socket_addr_ip4_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_ip4_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_socket_addr_ip4_decode_unsafe( fd_gossip_socket_addr_ip4_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_ip4_decode_offsets( fd_gossip_socket_addr_ip4_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_ip4_encode( fd_gossip_socket_addr_ip4_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_socket_addr_ip4_destroy( fd_gossip_socket_addr_ip4_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_socket_addr_ip4_walk( void * w, fd_gossip_socket_addr_ip4_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_socket_addr_ip4_size( fd_gossip_socket_addr_ip4_t const * self );
ulong fd_gossip_socket_addr_ip4_footprint( void );
ulong fd_gossip_socket_addr_ip4_align( void );

void fd_gossip_socket_addr_ip6_new( fd_gossip_socket_addr_ip6_t * self );
int fd_gossip_socket_addr_ip6_decode( fd_gossip_socket_addr_ip6_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_ip6_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_socket_addr_ip6_decode_unsafe( fd_gossip_socket_addr_ip6_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_ip6_decode_offsets( fd_gossip_socket_addr_ip6_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_ip6_encode( fd_gossip_socket_addr_ip6_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_socket_addr_ip6_destroy( fd_gossip_socket_addr_ip6_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_socket_addr_ip6_walk( void * w, fd_gossip_socket_addr_ip6_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_socket_addr_ip6_size( fd_gossip_socket_addr_ip6_t const * self );
ulong fd_gossip_socket_addr_ip6_footprint( void );
ulong fd_gossip_socket_addr_ip6_align( void );

void fd_gossip_socket_addr_new_disc( fd_gossip_socket_addr_t * self, uint discriminant );
void fd_gossip_socket_addr_new( fd_gossip_socket_addr_t * self );
int fd_gossip_socket_addr_decode( fd_gossip_socket_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_socket_addr_decode_unsafe( fd_gossip_socket_addr_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_addr_encode( fd_gossip_socket_addr_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_socket_addr_destroy( fd_gossip_socket_addr_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_socket_addr_walk( void * w, fd_gossip_socket_addr_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_socket_addr_size( fd_gossip_socket_addr_t const * self );
ulong fd_gossip_socket_addr_footprint( void );
ulong fd_gossip_socket_addr_align( void );

FD_FN_PURE uchar fd_gossip_socket_addr_is_ip4( fd_gossip_socket_addr_t const * self );
FD_FN_PURE uchar fd_gossip_socket_addr_is_ip6( fd_gossip_socket_addr_t const * self );
enum {
fd_gossip_socket_addr_enum_ip4 = 0,
fd_gossip_socket_addr_enum_ip6 = 1,
}; 
void fd_gossip_contact_info_v1_new( fd_gossip_contact_info_v1_t * self );
int fd_gossip_contact_info_v1_decode( fd_gossip_contact_info_v1_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_contact_info_v1_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_contact_info_v1_decode_unsafe( fd_gossip_contact_info_v1_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_contact_info_v1_decode_offsets( fd_gossip_contact_info_v1_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_contact_info_v1_encode( fd_gossip_contact_info_v1_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_contact_info_v1_destroy( fd_gossip_contact_info_v1_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_contact_info_v1_walk( void * w, fd_gossip_contact_info_v1_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_contact_info_v1_size( fd_gossip_contact_info_v1_t const * self );
ulong fd_gossip_contact_info_v1_footprint( void );
ulong fd_gossip_contact_info_v1_align( void );

void fd_gossip_vote_new( fd_gossip_vote_t * self );
int fd_gossip_vote_decode( fd_gossip_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_vote_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_vote_decode_unsafe( fd_gossip_vote_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_vote_decode_offsets( fd_gossip_vote_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_vote_encode( fd_gossip_vote_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_vote_destroy( fd_gossip_vote_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_vote_walk( void * w, fd_gossip_vote_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_vote_size( fd_gossip_vote_t const * self );
ulong fd_gossip_vote_footprint( void );
ulong fd_gossip_vote_align( void );

void fd_gossip_lowest_slot_new( fd_gossip_lowest_slot_t * self );
int fd_gossip_lowest_slot_decode( fd_gossip_lowest_slot_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_lowest_slot_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_lowest_slot_decode_unsafe( fd_gossip_lowest_slot_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_lowest_slot_decode_offsets( fd_gossip_lowest_slot_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_lowest_slot_encode( fd_gossip_lowest_slot_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_lowest_slot_destroy( fd_gossip_lowest_slot_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_lowest_slot_walk( void * w, fd_gossip_lowest_slot_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_lowest_slot_size( fd_gossip_lowest_slot_t const * self );
ulong fd_gossip_lowest_slot_footprint( void );
ulong fd_gossip_lowest_slot_align( void );

void fd_gossip_slot_hashes_new( fd_gossip_slot_hashes_t * self );
int fd_gossip_slot_hashes_decode( fd_gossip_slot_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slot_hashes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_slot_hashes_decode_unsafe( fd_gossip_slot_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slot_hashes_decode_offsets( fd_gossip_slot_hashes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slot_hashes_encode( fd_gossip_slot_hashes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_slot_hashes_destroy( fd_gossip_slot_hashes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_slot_hashes_walk( void * w, fd_gossip_slot_hashes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_slot_hashes_size( fd_gossip_slot_hashes_t const * self );
ulong fd_gossip_slot_hashes_footprint( void );
ulong fd_gossip_slot_hashes_align( void );

void fd_gossip_slots_new( fd_gossip_slots_t * self );
int fd_gossip_slots_decode( fd_gossip_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slots_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_slots_decode_unsafe( fd_gossip_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slots_decode_offsets( fd_gossip_slots_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slots_encode( fd_gossip_slots_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_slots_destroy( fd_gossip_slots_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_slots_walk( void * w, fd_gossip_slots_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_slots_size( fd_gossip_slots_t const * self );
ulong fd_gossip_slots_footprint( void );
ulong fd_gossip_slots_align( void );

void fd_gossip_flate2_slots_new( fd_gossip_flate2_slots_t * self );
int fd_gossip_flate2_slots_decode( fd_gossip_flate2_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_flate2_slots_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_flate2_slots_decode_unsafe( fd_gossip_flate2_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_flate2_slots_decode_offsets( fd_gossip_flate2_slots_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_flate2_slots_encode( fd_gossip_flate2_slots_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_flate2_slots_destroy( fd_gossip_flate2_slots_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_flate2_slots_walk( void * w, fd_gossip_flate2_slots_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_flate2_slots_size( fd_gossip_flate2_slots_t const * self );
ulong fd_gossip_flate2_slots_footprint( void );
ulong fd_gossip_flate2_slots_align( void );

void fd_gossip_slots_enum_new_disc( fd_gossip_slots_enum_t * self, uint discriminant );
void fd_gossip_slots_enum_new( fd_gossip_slots_enum_t * self );
int fd_gossip_slots_enum_decode( fd_gossip_slots_enum_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slots_enum_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_slots_enum_decode_unsafe( fd_gossip_slots_enum_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_slots_enum_encode( fd_gossip_slots_enum_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_slots_enum_destroy( fd_gossip_slots_enum_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_slots_enum_walk( void * w, fd_gossip_slots_enum_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_slots_enum_size( fd_gossip_slots_enum_t const * self );
ulong fd_gossip_slots_enum_footprint( void );
ulong fd_gossip_slots_enum_align( void );

FD_FN_PURE uchar fd_gossip_slots_enum_is_flate2( fd_gossip_slots_enum_t const * self );
FD_FN_PURE uchar fd_gossip_slots_enum_is_uncompressed( fd_gossip_slots_enum_t const * self );
enum {
fd_gossip_slots_enum_enum_flate2 = 0,
fd_gossip_slots_enum_enum_uncompressed = 1,
}; 
void fd_gossip_epoch_slots_new( fd_gossip_epoch_slots_t * self );
int fd_gossip_epoch_slots_decode( fd_gossip_epoch_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_epoch_slots_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_epoch_slots_decode_unsafe( fd_gossip_epoch_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_epoch_slots_decode_offsets( fd_gossip_epoch_slots_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_epoch_slots_encode( fd_gossip_epoch_slots_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_epoch_slots_destroy( fd_gossip_epoch_slots_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_epoch_slots_walk( void * w, fd_gossip_epoch_slots_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_epoch_slots_size( fd_gossip_epoch_slots_t const * self );
ulong fd_gossip_epoch_slots_footprint( void );
ulong fd_gossip_epoch_slots_align( void );

void fd_gossip_version_v1_new( fd_gossip_version_v1_t * self );
int fd_gossip_version_v1_decode( fd_gossip_version_v1_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v1_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_version_v1_decode_unsafe( fd_gossip_version_v1_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v1_decode_offsets( fd_gossip_version_v1_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v1_encode( fd_gossip_version_v1_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_version_v1_destroy( fd_gossip_version_v1_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_version_v1_walk( void * w, fd_gossip_version_v1_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_version_v1_size( fd_gossip_version_v1_t const * self );
ulong fd_gossip_version_v1_footprint( void );
ulong fd_gossip_version_v1_align( void );

void fd_gossip_version_v2_new( fd_gossip_version_v2_t * self );
int fd_gossip_version_v2_decode( fd_gossip_version_v2_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v2_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_version_v2_decode_unsafe( fd_gossip_version_v2_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v2_decode_offsets( fd_gossip_version_v2_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v2_encode( fd_gossip_version_v2_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_version_v2_destroy( fd_gossip_version_v2_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_version_v2_walk( void * w, fd_gossip_version_v2_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_version_v2_size( fd_gossip_version_v2_t const * self );
ulong fd_gossip_version_v2_footprint( void );
ulong fd_gossip_version_v2_align( void );

void fd_gossip_version_v3_new( fd_gossip_version_v3_t * self );
int fd_gossip_version_v3_decode( fd_gossip_version_v3_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v3_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_version_v3_decode_unsafe( fd_gossip_version_v3_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v3_decode_offsets( fd_gossip_version_v3_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_version_v3_encode( fd_gossip_version_v3_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_version_v3_destroy( fd_gossip_version_v3_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_version_v3_walk( void * w, fd_gossip_version_v3_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_version_v3_size( fd_gossip_version_v3_t const * self );
ulong fd_gossip_version_v3_footprint( void );
ulong fd_gossip_version_v3_align( void );

void fd_gossip_node_instance_new( fd_gossip_node_instance_t * self );
int fd_gossip_node_instance_decode( fd_gossip_node_instance_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_node_instance_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_node_instance_decode_unsafe( fd_gossip_node_instance_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_node_instance_decode_offsets( fd_gossip_node_instance_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_node_instance_encode( fd_gossip_node_instance_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_node_instance_destroy( fd_gossip_node_instance_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_node_instance_walk( void * w, fd_gossip_node_instance_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_node_instance_size( fd_gossip_node_instance_t const * self );
ulong fd_gossip_node_instance_footprint( void );
ulong fd_gossip_node_instance_align( void );

void fd_gossip_duplicate_shred_new( fd_gossip_duplicate_shred_t * self );
int fd_gossip_duplicate_shred_decode( fd_gossip_duplicate_shred_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_duplicate_shred_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_duplicate_shred_decode_unsafe( fd_gossip_duplicate_shred_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_duplicate_shred_decode_offsets( fd_gossip_duplicate_shred_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_duplicate_shred_encode( fd_gossip_duplicate_shred_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_duplicate_shred_destroy( fd_gossip_duplicate_shred_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_duplicate_shred_walk( void * w, fd_gossip_duplicate_shred_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_duplicate_shred_size( fd_gossip_duplicate_shred_t const * self );
ulong fd_gossip_duplicate_shred_footprint( void );
ulong fd_gossip_duplicate_shred_align( void );

void fd_gossip_incremental_snapshot_hashes_new( fd_gossip_incremental_snapshot_hashes_t * self );
int fd_gossip_incremental_snapshot_hashes_decode( fd_gossip_incremental_snapshot_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_incremental_snapshot_hashes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_incremental_snapshot_hashes_decode_unsafe( fd_gossip_incremental_snapshot_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_incremental_snapshot_hashes_decode_offsets( fd_gossip_incremental_snapshot_hashes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_incremental_snapshot_hashes_encode( fd_gossip_incremental_snapshot_hashes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_incremental_snapshot_hashes_destroy( fd_gossip_incremental_snapshot_hashes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_incremental_snapshot_hashes_walk( void * w, fd_gossip_incremental_snapshot_hashes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_incremental_snapshot_hashes_size( fd_gossip_incremental_snapshot_hashes_t const * self );
ulong fd_gossip_incremental_snapshot_hashes_footprint( void );
ulong fd_gossip_incremental_snapshot_hashes_align( void );

void fd_gossip_socket_entry_new( fd_gossip_socket_entry_t * self );
int fd_gossip_socket_entry_decode( fd_gossip_socket_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_entry_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_socket_entry_decode_unsafe( fd_gossip_socket_entry_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_entry_decode_offsets( fd_gossip_socket_entry_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_socket_entry_encode( fd_gossip_socket_entry_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_socket_entry_destroy( fd_gossip_socket_entry_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_socket_entry_walk( void * w, fd_gossip_socket_entry_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_socket_entry_size( fd_gossip_socket_entry_t const * self );
ulong fd_gossip_socket_entry_footprint( void );
ulong fd_gossip_socket_entry_align( void );

void fd_gossip_contact_info_v2_new( fd_gossip_contact_info_v2_t * self );
int fd_gossip_contact_info_v2_decode( fd_gossip_contact_info_v2_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_contact_info_v2_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_contact_info_v2_decode_unsafe( fd_gossip_contact_info_v2_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_contact_info_v2_decode_offsets( fd_gossip_contact_info_v2_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_contact_info_v2_encode( fd_gossip_contact_info_v2_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_contact_info_v2_destroy( fd_gossip_contact_info_v2_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_contact_info_v2_walk( void * w, fd_gossip_contact_info_v2_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_contact_info_v2_size( fd_gossip_contact_info_v2_t const * self );
ulong fd_gossip_contact_info_v2_footprint( void );
ulong fd_gossip_contact_info_v2_align( void );

void fd_restart_run_length_encoding_inner_new( fd_restart_run_length_encoding_inner_t * self );
int fd_restart_run_length_encoding_inner_decode( fd_restart_run_length_encoding_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_run_length_encoding_inner_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_restart_run_length_encoding_inner_decode_unsafe( fd_restart_run_length_encoding_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_run_length_encoding_inner_decode_offsets( fd_restart_run_length_encoding_inner_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_run_length_encoding_inner_encode( fd_restart_run_length_encoding_inner_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_restart_run_length_encoding_inner_destroy( fd_restart_run_length_encoding_inner_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_restart_run_length_encoding_inner_walk( void * w, fd_restart_run_length_encoding_inner_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_restart_run_length_encoding_inner_size( fd_restart_run_length_encoding_inner_t const * self );
ulong fd_restart_run_length_encoding_inner_footprint( void );
ulong fd_restart_run_length_encoding_inner_align( void );

void fd_restart_run_length_encoding_new( fd_restart_run_length_encoding_t * self );
int fd_restart_run_length_encoding_decode( fd_restart_run_length_encoding_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_run_length_encoding_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_restart_run_length_encoding_decode_unsafe( fd_restart_run_length_encoding_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_run_length_encoding_decode_offsets( fd_restart_run_length_encoding_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_run_length_encoding_encode( fd_restart_run_length_encoding_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_restart_run_length_encoding_destroy( fd_restart_run_length_encoding_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_restart_run_length_encoding_walk( void * w, fd_restart_run_length_encoding_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_restart_run_length_encoding_size( fd_restart_run_length_encoding_t const * self );
ulong fd_restart_run_length_encoding_footprint( void );
ulong fd_restart_run_length_encoding_align( void );

void fd_restart_raw_offsets_bitvec_u8_inner_new( fd_restart_raw_offsets_bitvec_u8_inner_t * self );
int fd_restart_raw_offsets_bitvec_u8_inner_decode( fd_restart_raw_offsets_bitvec_u8_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_bitvec_u8_inner_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_restart_raw_offsets_bitvec_u8_inner_decode_unsafe( fd_restart_raw_offsets_bitvec_u8_inner_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_bitvec_u8_inner_decode_offsets( fd_restart_raw_offsets_bitvec_u8_inner_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_bitvec_u8_inner_encode( fd_restart_raw_offsets_bitvec_u8_inner_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_restart_raw_offsets_bitvec_u8_inner_destroy( fd_restart_raw_offsets_bitvec_u8_inner_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_restart_raw_offsets_bitvec_u8_inner_walk( void * w, fd_restart_raw_offsets_bitvec_u8_inner_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_restart_raw_offsets_bitvec_u8_inner_size( fd_restart_raw_offsets_bitvec_u8_inner_t const * self );
ulong fd_restart_raw_offsets_bitvec_u8_inner_footprint( void );
ulong fd_restart_raw_offsets_bitvec_u8_inner_align( void );

void fd_restart_raw_offsets_bitvec_new( fd_restart_raw_offsets_bitvec_t * self );
int fd_restart_raw_offsets_bitvec_decode( fd_restart_raw_offsets_bitvec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_bitvec_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_restart_raw_offsets_bitvec_decode_unsafe( fd_restart_raw_offsets_bitvec_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_bitvec_decode_offsets( fd_restart_raw_offsets_bitvec_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_bitvec_encode( fd_restart_raw_offsets_bitvec_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_restart_raw_offsets_bitvec_destroy( fd_restart_raw_offsets_bitvec_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_restart_raw_offsets_bitvec_walk( void * w, fd_restart_raw_offsets_bitvec_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_restart_raw_offsets_bitvec_size( fd_restart_raw_offsets_bitvec_t const * self );
ulong fd_restart_raw_offsets_bitvec_footprint( void );
ulong fd_restart_raw_offsets_bitvec_align( void );

void fd_restart_raw_offsets_new( fd_restart_raw_offsets_t * self );
int fd_restart_raw_offsets_decode( fd_restart_raw_offsets_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_restart_raw_offsets_decode_unsafe( fd_restart_raw_offsets_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_decode_offsets( fd_restart_raw_offsets_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_raw_offsets_encode( fd_restart_raw_offsets_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_restart_raw_offsets_destroy( fd_restart_raw_offsets_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_restart_raw_offsets_walk( void * w, fd_restart_raw_offsets_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_restart_raw_offsets_size( fd_restart_raw_offsets_t const * self );
ulong fd_restart_raw_offsets_footprint( void );
ulong fd_restart_raw_offsets_align( void );

void fd_restart_slots_offsets_new_disc( fd_restart_slots_offsets_t * self, uint discriminant );
void fd_restart_slots_offsets_new( fd_restart_slots_offsets_t * self );
int fd_restart_slots_offsets_decode( fd_restart_slots_offsets_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_slots_offsets_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_restart_slots_offsets_decode_unsafe( fd_restart_slots_offsets_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_restart_slots_offsets_encode( fd_restart_slots_offsets_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_restart_slots_offsets_destroy( fd_restart_slots_offsets_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_restart_slots_offsets_walk( void * w, fd_restart_slots_offsets_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_restart_slots_offsets_size( fd_restart_slots_offsets_t const * self );
ulong fd_restart_slots_offsets_footprint( void );
ulong fd_restart_slots_offsets_align( void );

FD_FN_PURE uchar fd_restart_slots_offsets_is_run_length_encoding( fd_restart_slots_offsets_t const * self );
FD_FN_PURE uchar fd_restart_slots_offsets_is_raw_offsets( fd_restart_slots_offsets_t const * self );
enum {
fd_restart_slots_offsets_enum_run_length_encoding = 0,
fd_restart_slots_offsets_enum_raw_offsets = 1,
}; 
void fd_gossip_restart_last_voted_fork_slots_new( fd_gossip_restart_last_voted_fork_slots_t * self );
int fd_gossip_restart_last_voted_fork_slots_decode( fd_gossip_restart_last_voted_fork_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_restart_last_voted_fork_slots_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_restart_last_voted_fork_slots_decode_unsafe( fd_gossip_restart_last_voted_fork_slots_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_restart_last_voted_fork_slots_decode_offsets( fd_gossip_restart_last_voted_fork_slots_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_restart_last_voted_fork_slots_encode( fd_gossip_restart_last_voted_fork_slots_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_restart_last_voted_fork_slots_destroy( fd_gossip_restart_last_voted_fork_slots_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_restart_last_voted_fork_slots_walk( void * w, fd_gossip_restart_last_voted_fork_slots_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_restart_last_voted_fork_slots_size( fd_gossip_restart_last_voted_fork_slots_t const * self );
ulong fd_gossip_restart_last_voted_fork_slots_footprint( void );
ulong fd_gossip_restart_last_voted_fork_slots_align( void );

void fd_gossip_restart_heaviest_fork_new( fd_gossip_restart_heaviest_fork_t * self );
int fd_gossip_restart_heaviest_fork_decode( fd_gossip_restart_heaviest_fork_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_restart_heaviest_fork_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_restart_heaviest_fork_decode_unsafe( fd_gossip_restart_heaviest_fork_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_restart_heaviest_fork_decode_offsets( fd_gossip_restart_heaviest_fork_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_restart_heaviest_fork_encode( fd_gossip_restart_heaviest_fork_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_restart_heaviest_fork_destroy( fd_gossip_restart_heaviest_fork_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_restart_heaviest_fork_walk( void * w, fd_gossip_restart_heaviest_fork_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_restart_heaviest_fork_size( fd_gossip_restart_heaviest_fork_t const * self );
ulong fd_gossip_restart_heaviest_fork_footprint( void );
ulong fd_gossip_restart_heaviest_fork_align( void );

void fd_crds_data_new_disc( fd_crds_data_t * self, uint discriminant );
void fd_crds_data_new( fd_crds_data_t * self );
int fd_crds_data_decode( fd_crds_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_data_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_crds_data_decode_unsafe( fd_crds_data_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_data_encode( fd_crds_data_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_crds_data_destroy( fd_crds_data_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_crds_data_walk( void * w, fd_crds_data_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_crds_data_size( fd_crds_data_t const * self );
ulong fd_crds_data_footprint( void );
ulong fd_crds_data_align( void );

FD_FN_PURE uchar fd_crds_data_is_contact_info_v1( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_vote( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_lowest_slot( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_snapshot_hashes( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_accounts_hashes( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_epoch_slots( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_version_v1( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_version_v2( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_node_instance( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_duplicate_shred( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_incremental_snapshot_hashes( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_contact_info_v2( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_restart_last_voted_fork_slots( fd_crds_data_t const * self );
FD_FN_PURE uchar fd_crds_data_is_restart_heaviest_fork( fd_crds_data_t const * self );
enum {
fd_crds_data_enum_contact_info_v1 = 0,
fd_crds_data_enum_vote = 1,
fd_crds_data_enum_lowest_slot = 2,
fd_crds_data_enum_snapshot_hashes = 3,
fd_crds_data_enum_accounts_hashes = 4,
fd_crds_data_enum_epoch_slots = 5,
fd_crds_data_enum_version_v1 = 6,
fd_crds_data_enum_version_v2 = 7,
fd_crds_data_enum_node_instance = 8,
fd_crds_data_enum_duplicate_shred = 9,
fd_crds_data_enum_incremental_snapshot_hashes = 10,
fd_crds_data_enum_contact_info_v2 = 11,
fd_crds_data_enum_restart_last_voted_fork_slots = 12,
fd_crds_data_enum_restart_heaviest_fork = 13,
}; 
void fd_crds_bloom_new( fd_crds_bloom_t * self );
int fd_crds_bloom_decode( fd_crds_bloom_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_bloom_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_crds_bloom_decode_unsafe( fd_crds_bloom_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_bloom_decode_offsets( fd_crds_bloom_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_bloom_encode( fd_crds_bloom_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_crds_bloom_destroy( fd_crds_bloom_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_crds_bloom_walk( void * w, fd_crds_bloom_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_crds_bloom_size( fd_crds_bloom_t const * self );
ulong fd_crds_bloom_footprint( void );
ulong fd_crds_bloom_align( void );

void fd_crds_filter_new( fd_crds_filter_t * self );
int fd_crds_filter_decode( fd_crds_filter_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_filter_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_crds_filter_decode_unsafe( fd_crds_filter_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_filter_decode_offsets( fd_crds_filter_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_filter_encode( fd_crds_filter_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_crds_filter_destroy( fd_crds_filter_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_crds_filter_walk( void * w, fd_crds_filter_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_crds_filter_size( fd_crds_filter_t const * self );
ulong fd_crds_filter_footprint( void );
ulong fd_crds_filter_align( void );

void fd_crds_value_new( fd_crds_value_t * self );
int fd_crds_value_decode( fd_crds_value_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_value_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_crds_value_decode_unsafe( fd_crds_value_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_value_decode_offsets( fd_crds_value_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_crds_value_encode( fd_crds_value_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_crds_value_destroy( fd_crds_value_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_crds_value_walk( void * w, fd_crds_value_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_crds_value_size( fd_crds_value_t const * self );
ulong fd_crds_value_footprint( void );
ulong fd_crds_value_align( void );

void fd_gossip_pull_req_new( fd_gossip_pull_req_t * self );
int fd_gossip_pull_req_decode( fd_gossip_pull_req_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_pull_req_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_pull_req_decode_unsafe( fd_gossip_pull_req_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_pull_req_decode_offsets( fd_gossip_pull_req_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_pull_req_encode( fd_gossip_pull_req_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_pull_req_destroy( fd_gossip_pull_req_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_pull_req_walk( void * w, fd_gossip_pull_req_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_pull_req_size( fd_gossip_pull_req_t const * self );
ulong fd_gossip_pull_req_footprint( void );
ulong fd_gossip_pull_req_align( void );

void fd_gossip_pull_resp_new( fd_gossip_pull_resp_t * self );
int fd_gossip_pull_resp_decode( fd_gossip_pull_resp_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_pull_resp_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_pull_resp_decode_unsafe( fd_gossip_pull_resp_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_pull_resp_decode_offsets( fd_gossip_pull_resp_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_pull_resp_encode( fd_gossip_pull_resp_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_pull_resp_destroy( fd_gossip_pull_resp_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_pull_resp_walk( void * w, fd_gossip_pull_resp_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_pull_resp_size( fd_gossip_pull_resp_t const * self );
ulong fd_gossip_pull_resp_footprint( void );
ulong fd_gossip_pull_resp_align( void );

void fd_gossip_push_msg_new( fd_gossip_push_msg_t * self );
int fd_gossip_push_msg_decode( fd_gossip_push_msg_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_push_msg_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_push_msg_decode_unsafe( fd_gossip_push_msg_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_push_msg_decode_offsets( fd_gossip_push_msg_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_push_msg_encode( fd_gossip_push_msg_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_push_msg_destroy( fd_gossip_push_msg_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_push_msg_walk( void * w, fd_gossip_push_msg_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_push_msg_size( fd_gossip_push_msg_t const * self );
ulong fd_gossip_push_msg_footprint( void );
ulong fd_gossip_push_msg_align( void );

void fd_gossip_prune_msg_new( fd_gossip_prune_msg_t * self );
int fd_gossip_prune_msg_decode( fd_gossip_prune_msg_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_msg_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_prune_msg_decode_unsafe( fd_gossip_prune_msg_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_msg_decode_offsets( fd_gossip_prune_msg_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_prune_msg_encode( fd_gossip_prune_msg_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_prune_msg_destroy( fd_gossip_prune_msg_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_prune_msg_walk( void * w, fd_gossip_prune_msg_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_prune_msg_size( fd_gossip_prune_msg_t const * self );
ulong fd_gossip_prune_msg_footprint( void );
ulong fd_gossip_prune_msg_align( void );

void fd_gossip_msg_new_disc( fd_gossip_msg_t * self, uint discriminant );
void fd_gossip_msg_new( fd_gossip_msg_t * self );
int fd_gossip_msg_decode( fd_gossip_msg_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_msg_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_gossip_msg_decode_unsafe( fd_gossip_msg_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_gossip_msg_encode( fd_gossip_msg_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_gossip_msg_destroy( fd_gossip_msg_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_gossip_msg_walk( void * w, fd_gossip_msg_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_gossip_msg_size( fd_gossip_msg_t const * self );
ulong fd_gossip_msg_footprint( void );
ulong fd_gossip_msg_align( void );

FD_FN_PURE uchar fd_gossip_msg_is_pull_req( fd_gossip_msg_t const * self );
FD_FN_PURE uchar fd_gossip_msg_is_pull_resp( fd_gossip_msg_t const * self );
FD_FN_PURE uchar fd_gossip_msg_is_push_msg( fd_gossip_msg_t const * self );
FD_FN_PURE uchar fd_gossip_msg_is_prune_msg( fd_gossip_msg_t const * self );
FD_FN_PURE uchar fd_gossip_msg_is_ping( fd_gossip_msg_t const * self );
FD_FN_PURE uchar fd_gossip_msg_is_pong( fd_gossip_msg_t const * self );
enum {
fd_gossip_msg_enum_pull_req = 0,
fd_gossip_msg_enum_pull_resp = 1,
fd_gossip_msg_enum_push_msg = 2,
fd_gossip_msg_enum_prune_msg = 3,
fd_gossip_msg_enum_ping = 4,
fd_gossip_msg_enum_pong = 5,
}; 
void fd_addrlut_create_new( fd_addrlut_create_t * self );
int fd_addrlut_create_decode( fd_addrlut_create_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_create_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_addrlut_create_decode_unsafe( fd_addrlut_create_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_create_decode_offsets( fd_addrlut_create_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_create_encode( fd_addrlut_create_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_addrlut_create_destroy( fd_addrlut_create_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_addrlut_create_walk( void * w, fd_addrlut_create_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_addrlut_create_size( fd_addrlut_create_t const * self );
ulong fd_addrlut_create_footprint( void );
ulong fd_addrlut_create_align( void );

void fd_addrlut_extend_new( fd_addrlut_extend_t * self );
int fd_addrlut_extend_decode( fd_addrlut_extend_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_extend_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_addrlut_extend_decode_unsafe( fd_addrlut_extend_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_extend_decode_offsets( fd_addrlut_extend_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_extend_encode( fd_addrlut_extend_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_addrlut_extend_destroy( fd_addrlut_extend_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_addrlut_extend_walk( void * w, fd_addrlut_extend_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_addrlut_extend_size( fd_addrlut_extend_t const * self );
ulong fd_addrlut_extend_footprint( void );
ulong fd_addrlut_extend_align( void );

void fd_addrlut_instruction_new_disc( fd_addrlut_instruction_t * self, uint discriminant );
void fd_addrlut_instruction_new( fd_addrlut_instruction_t * self );
int fd_addrlut_instruction_decode( fd_addrlut_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_instruction_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_addrlut_instruction_decode_unsafe( fd_addrlut_instruction_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_addrlut_instruction_encode( fd_addrlut_instruction_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_addrlut_instruction_destroy( fd_addrlut_instruction_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_addrlut_instruction_walk( void * w, fd_addrlut_instruction_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_addrlut_instruction_size( fd_addrlut_instruction_t const * self );
ulong fd_addrlut_instruction_footprint( void );
ulong fd_addrlut_instruction_align( void );

FD_FN_PURE uchar fd_addrlut_instruction_is_create_lut( fd_addrlut_instruction_t const * self );
FD_FN_PURE uchar fd_addrlut_instruction_is_freeze_lut( fd_addrlut_instruction_t const * self );
FD_FN_PURE uchar fd_addrlut_instruction_is_extend_lut( fd_addrlut_instruction_t const * self );
FD_FN_PURE uchar fd_addrlut_instruction_is_deactivate_lut( fd_addrlut_instruction_t const * self );
FD_FN_PURE uchar fd_addrlut_instruction_is_close_lut( fd_addrlut_instruction_t const * self );
enum {
fd_addrlut_instruction_enum_create_lut = 0,
fd_addrlut_instruction_enum_freeze_lut = 1,
fd_addrlut_instruction_enum_extend_lut = 2,
fd_addrlut_instruction_enum_deactivate_lut = 3,
fd_addrlut_instruction_enum_close_lut = 4,
}; 
void fd_repair_request_header_new( fd_repair_request_header_t * self );
int fd_repair_request_header_decode( fd_repair_request_header_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_request_header_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_repair_request_header_decode_unsafe( fd_repair_request_header_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_request_header_decode_offsets( fd_repair_request_header_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_request_header_encode( fd_repair_request_header_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_repair_request_header_destroy( fd_repair_request_header_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_repair_request_header_walk( void * w, fd_repair_request_header_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_repair_request_header_size( fd_repair_request_header_t const * self );
ulong fd_repair_request_header_footprint( void );
ulong fd_repair_request_header_align( void );

void fd_repair_window_index_new( fd_repair_window_index_t * self );
int fd_repair_window_index_decode( fd_repair_window_index_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_window_index_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_repair_window_index_decode_unsafe( fd_repair_window_index_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_window_index_decode_offsets( fd_repair_window_index_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_window_index_encode( fd_repair_window_index_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_repair_window_index_destroy( fd_repair_window_index_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_repair_window_index_walk( void * w, fd_repair_window_index_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_repair_window_index_size( fd_repair_window_index_t const * self );
ulong fd_repair_window_index_footprint( void );
ulong fd_repair_window_index_align( void );

void fd_repair_highest_window_index_new( fd_repair_highest_window_index_t * self );
int fd_repair_highest_window_index_decode( fd_repair_highest_window_index_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_highest_window_index_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_repair_highest_window_index_decode_unsafe( fd_repair_highest_window_index_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_highest_window_index_decode_offsets( fd_repair_highest_window_index_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_highest_window_index_encode( fd_repair_highest_window_index_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_repair_highest_window_index_destroy( fd_repair_highest_window_index_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_repair_highest_window_index_walk( void * w, fd_repair_highest_window_index_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_repair_highest_window_index_size( fd_repair_highest_window_index_t const * self );
ulong fd_repair_highest_window_index_footprint( void );
ulong fd_repair_highest_window_index_align( void );

void fd_repair_orphan_new( fd_repair_orphan_t * self );
int fd_repair_orphan_decode( fd_repair_orphan_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_orphan_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_repair_orphan_decode_unsafe( fd_repair_orphan_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_orphan_decode_offsets( fd_repair_orphan_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_orphan_encode( fd_repair_orphan_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_repair_orphan_destroy( fd_repair_orphan_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_repair_orphan_walk( void * w, fd_repair_orphan_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_repair_orphan_size( fd_repair_orphan_t const * self );
ulong fd_repair_orphan_footprint( void );
ulong fd_repair_orphan_align( void );

void fd_repair_ancestor_hashes_new( fd_repair_ancestor_hashes_t * self );
int fd_repair_ancestor_hashes_decode( fd_repair_ancestor_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_ancestor_hashes_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_repair_ancestor_hashes_decode_unsafe( fd_repair_ancestor_hashes_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_ancestor_hashes_decode_offsets( fd_repair_ancestor_hashes_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_ancestor_hashes_encode( fd_repair_ancestor_hashes_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_repair_ancestor_hashes_destroy( fd_repair_ancestor_hashes_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_repair_ancestor_hashes_walk( void * w, fd_repair_ancestor_hashes_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_repair_ancestor_hashes_size( fd_repair_ancestor_hashes_t const * self );
ulong fd_repair_ancestor_hashes_footprint( void );
ulong fd_repair_ancestor_hashes_align( void );

void fd_repair_protocol_new_disc( fd_repair_protocol_t * self, uint discriminant );
void fd_repair_protocol_new( fd_repair_protocol_t * self );
int fd_repair_protocol_decode( fd_repair_protocol_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_protocol_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_repair_protocol_decode_unsafe( fd_repair_protocol_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_protocol_encode( fd_repair_protocol_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_repair_protocol_destroy( fd_repair_protocol_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_repair_protocol_walk( void * w, fd_repair_protocol_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_repair_protocol_size( fd_repair_protocol_t const * self );
ulong fd_repair_protocol_footprint( void );
ulong fd_repair_protocol_align( void );

FD_FN_PURE uchar fd_repair_protocol_is_LegacyWindowIndex( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_LegacyHighestWindowIndex( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_LegacyOrphan( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_LegacyWindowIndexWithNonce( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_LegacyHighestWindowIndexWithNonce( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_LegacyOrphanWithNonce( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_LegacyAncestorHashes( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_pong( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_window_index( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_highest_window_index( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_orphan( fd_repair_protocol_t const * self );
FD_FN_PURE uchar fd_repair_protocol_is_ancestor_hashes( fd_repair_protocol_t const * self );
enum {
fd_repair_protocol_enum_LegacyWindowIndex = 0,
fd_repair_protocol_enum_LegacyHighestWindowIndex = 1,
fd_repair_protocol_enum_LegacyOrphan = 2,
fd_repair_protocol_enum_LegacyWindowIndexWithNonce = 3,
fd_repair_protocol_enum_LegacyHighestWindowIndexWithNonce = 4,
fd_repair_protocol_enum_LegacyOrphanWithNonce = 5,
fd_repair_protocol_enum_LegacyAncestorHashes = 6,
fd_repair_protocol_enum_pong = 7,
fd_repair_protocol_enum_window_index = 8,
fd_repair_protocol_enum_highest_window_index = 9,
fd_repair_protocol_enum_orphan = 10,
fd_repair_protocol_enum_ancestor_hashes = 11,
}; 
void fd_repair_response_new_disc( fd_repair_response_t * self, uint discriminant );
void fd_repair_response_new( fd_repair_response_t * self );
int fd_repair_response_decode( fd_repair_response_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_response_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_repair_response_decode_unsafe( fd_repair_response_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_repair_response_encode( fd_repair_response_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_repair_response_destroy( fd_repair_response_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_repair_response_walk( void * w, fd_repair_response_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_repair_response_size( fd_repair_response_t const * self );
ulong fd_repair_response_footprint( void );
ulong fd_repair_response_align( void );

FD_FN_PURE uchar fd_repair_response_is_ping( fd_repair_response_t const * self );
enum {
fd_repair_response_enum_ping = 0,
}; 
void fd_instr_error_enum_new_disc( fd_instr_error_enum_t * self, uint discriminant );
void fd_instr_error_enum_new( fd_instr_error_enum_t * self );
int fd_instr_error_enum_decode( fd_instr_error_enum_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_instr_error_enum_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_instr_error_enum_decode_unsafe( fd_instr_error_enum_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_instr_error_enum_encode( fd_instr_error_enum_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_instr_error_enum_destroy( fd_instr_error_enum_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_instr_error_enum_walk( void * w, fd_instr_error_enum_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_instr_error_enum_size( fd_instr_error_enum_t const * self );
ulong fd_instr_error_enum_footprint( void );
ulong fd_instr_error_enum_align( void );

FD_FN_PURE uchar fd_instr_error_enum_is_generic_error( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_invalid_argument( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_invalid_instruction_data( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_invalid_account_data( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_account_data_too_small( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_insufficient_funds( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_incorrect_program_id( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_missing_required_signature( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_account_already_initialized( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_uninitialized_account( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_unbalanced_instruction( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_modified_program_id( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_external_account_lamport_spend( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_external_account_data_modified( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_readonly_lamport_change( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_readonly_data_modified( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_duplicate_account_index( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_executable_modified( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_rent_epoch_modified( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_not_enough_account_keys( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_account_data_size_changed( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_account_not_executable( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_account_borrow_failed( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_account_borrow_outstanding( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_duplicate_account_out_of_sync( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_custom( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_invalid_error( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_executable_data_modified( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_executable_lamport_change( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_executable_account_not_rent_exempt( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_unsupported_program_id( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_call_depth( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_missing_account( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_reentrancy_not_allowed( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_max_seed_length_exceeded( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_invalid_seeds( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_invalid_realloc( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_computational_budget_exceeded( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_privilege_escalation( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_program_environment_setup_failure( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_program_failed_to_complete( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_program_failed_to_compile( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_immutable( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_incorrect_authority( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_borsh_io_error( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_account_not_rent_exempt( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_invalid_account_owner( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_arithmetic_overflow( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_unsupported_sysvar( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_illegal_owner( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_max_accounts_data_allocations_exceeded( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_max_accounts_exceeded( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_max_instruction_trace_length_exceeded( fd_instr_error_enum_t const * self );
FD_FN_PURE uchar fd_instr_error_enum_is_builtin_programs_must_consume_compute_units( fd_instr_error_enum_t const * self );
enum {
fd_instr_error_enum_enum_generic_error = 0,
fd_instr_error_enum_enum_invalid_argument = 1,
fd_instr_error_enum_enum_invalid_instruction_data = 2,
fd_instr_error_enum_enum_invalid_account_data = 3,
fd_instr_error_enum_enum_account_data_too_small = 4,
fd_instr_error_enum_enum_insufficient_funds = 5,
fd_instr_error_enum_enum_incorrect_program_id = 6,
fd_instr_error_enum_enum_missing_required_signature = 7,
fd_instr_error_enum_enum_account_already_initialized = 8,
fd_instr_error_enum_enum_uninitialized_account = 9,
fd_instr_error_enum_enum_unbalanced_instruction = 10,
fd_instr_error_enum_enum_modified_program_id = 11,
fd_instr_error_enum_enum_external_account_lamport_spend = 12,
fd_instr_error_enum_enum_external_account_data_modified = 13,
fd_instr_error_enum_enum_readonly_lamport_change = 14,
fd_instr_error_enum_enum_readonly_data_modified = 15,
fd_instr_error_enum_enum_duplicate_account_index = 16,
fd_instr_error_enum_enum_executable_modified = 17,
fd_instr_error_enum_enum_rent_epoch_modified = 18,
fd_instr_error_enum_enum_not_enough_account_keys = 19,
fd_instr_error_enum_enum_account_data_size_changed = 20,
fd_instr_error_enum_enum_account_not_executable = 21,
fd_instr_error_enum_enum_account_borrow_failed = 22,
fd_instr_error_enum_enum_account_borrow_outstanding = 23,
fd_instr_error_enum_enum_duplicate_account_out_of_sync = 24,
fd_instr_error_enum_enum_custom = 25,
fd_instr_error_enum_enum_invalid_error = 26,
fd_instr_error_enum_enum_executable_data_modified = 27,
fd_instr_error_enum_enum_executable_lamport_change = 28,
fd_instr_error_enum_enum_executable_account_not_rent_exempt = 29,
fd_instr_error_enum_enum_unsupported_program_id = 30,
fd_instr_error_enum_enum_call_depth = 31,
fd_instr_error_enum_enum_missing_account = 32,
fd_instr_error_enum_enum_reentrancy_not_allowed = 33,
fd_instr_error_enum_enum_max_seed_length_exceeded = 34,
fd_instr_error_enum_enum_invalid_seeds = 35,
fd_instr_error_enum_enum_invalid_realloc = 36,
fd_instr_error_enum_enum_computational_budget_exceeded = 37,
fd_instr_error_enum_enum_privilege_escalation = 38,
fd_instr_error_enum_enum_program_environment_setup_failure = 39,
fd_instr_error_enum_enum_program_failed_to_complete = 40,
fd_instr_error_enum_enum_program_failed_to_compile = 41,
fd_instr_error_enum_enum_immutable = 42,
fd_instr_error_enum_enum_incorrect_authority = 43,
fd_instr_error_enum_enum_borsh_io_error = 44,
fd_instr_error_enum_enum_account_not_rent_exempt = 45,
fd_instr_error_enum_enum_invalid_account_owner = 46,
fd_instr_error_enum_enum_arithmetic_overflow = 47,
fd_instr_error_enum_enum_unsupported_sysvar = 48,
fd_instr_error_enum_enum_illegal_owner = 49,
fd_instr_error_enum_enum_max_accounts_data_allocations_exceeded = 50,
fd_instr_error_enum_enum_max_accounts_exceeded = 51,
fd_instr_error_enum_enum_max_instruction_trace_length_exceeded = 52,
fd_instr_error_enum_enum_builtin_programs_must_consume_compute_units = 53,
}; 
void fd_txn_instr_error_new( fd_txn_instr_error_t * self );
int fd_txn_instr_error_decode( fd_txn_instr_error_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_txn_instr_error_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_txn_instr_error_decode_unsafe( fd_txn_instr_error_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_txn_instr_error_decode_offsets( fd_txn_instr_error_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_txn_instr_error_encode( fd_txn_instr_error_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_txn_instr_error_destroy( fd_txn_instr_error_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_txn_instr_error_walk( void * w, fd_txn_instr_error_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_txn_instr_error_size( fd_txn_instr_error_t const * self );
ulong fd_txn_instr_error_footprint( void );
ulong fd_txn_instr_error_align( void );

void fd_txn_error_enum_new_disc( fd_txn_error_enum_t * self, uint discriminant );
void fd_txn_error_enum_new( fd_txn_error_enum_t * self );
int fd_txn_error_enum_decode( fd_txn_error_enum_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_txn_error_enum_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_txn_error_enum_decode_unsafe( fd_txn_error_enum_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_txn_error_enum_encode( fd_txn_error_enum_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_txn_error_enum_destroy( fd_txn_error_enum_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_txn_error_enum_walk( void * w, fd_txn_error_enum_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_txn_error_enum_size( fd_txn_error_enum_t const * self );
ulong fd_txn_error_enum_footprint( void );
ulong fd_txn_error_enum_align( void );

FD_FN_PURE uchar fd_txn_error_enum_is_account_in_use( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_account_loaded_twice( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_account_not_found( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_program_account_not_found( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_insufficient_funds_for_fee( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_account_for_fee( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_already_processed( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_blockhash_not_found( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_instruction_error( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_call_chain_too_deep( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_missing_signature_for_fee( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_account_index( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_signature_failure( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_program_for_execution( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_sanitize_failure( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_cluster_maintenance( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_account_borrow_outstanding( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_would_exceed_max_block_cost_limit( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_unsupported_version( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_writable_account( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_would_exceed_max_account_cost_limit( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_would_exceed_account_data_block_limit( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_too_many_account_locks( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_address_lookup_table_not_found( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_address_lookup_table_owner( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_address_lookup_table_data( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_address_lookup_table_index( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_rent_paying_account( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_would_exceed_max_vote_cost_limit( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_would_exceed_account_data_total_limit( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_duplicate_instruction( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_insufficient_funds_for_rent( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_max_loaded_accounts_data_size_exceeded( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_invalid_loaded_accounts_data_size_limit( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_resanitization_needed( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_program_execution_temporarily_restricted( fd_txn_error_enum_t const * self );
FD_FN_PURE uchar fd_txn_error_enum_is_unbalanced_transaction( fd_txn_error_enum_t const * self );
enum {
fd_txn_error_enum_enum_account_in_use = 0,
fd_txn_error_enum_enum_account_loaded_twice = 1,
fd_txn_error_enum_enum_account_not_found = 2,
fd_txn_error_enum_enum_program_account_not_found = 3,
fd_txn_error_enum_enum_insufficient_funds_for_fee = 4,
fd_txn_error_enum_enum_invalid_account_for_fee = 5,
fd_txn_error_enum_enum_already_processed = 6,
fd_txn_error_enum_enum_blockhash_not_found = 7,
fd_txn_error_enum_enum_instruction_error = 8,
fd_txn_error_enum_enum_call_chain_too_deep = 9,
fd_txn_error_enum_enum_missing_signature_for_fee = 10,
fd_txn_error_enum_enum_invalid_account_index = 11,
fd_txn_error_enum_enum_signature_failure = 12,
fd_txn_error_enum_enum_invalid_program_for_execution = 13,
fd_txn_error_enum_enum_sanitize_failure = 14,
fd_txn_error_enum_enum_cluster_maintenance = 15,
fd_txn_error_enum_enum_account_borrow_outstanding = 16,
fd_txn_error_enum_enum_would_exceed_max_block_cost_limit = 17,
fd_txn_error_enum_enum_unsupported_version = 18,
fd_txn_error_enum_enum_invalid_writable_account = 19,
fd_txn_error_enum_enum_would_exceed_max_account_cost_limit = 20,
fd_txn_error_enum_enum_would_exceed_account_data_block_limit = 21,
fd_txn_error_enum_enum_too_many_account_locks = 22,
fd_txn_error_enum_enum_address_lookup_table_not_found = 23,
fd_txn_error_enum_enum_invalid_address_lookup_table_owner = 24,
fd_txn_error_enum_enum_invalid_address_lookup_table_data = 25,
fd_txn_error_enum_enum_invalid_address_lookup_table_index = 26,
fd_txn_error_enum_enum_invalid_rent_paying_account = 27,
fd_txn_error_enum_enum_would_exceed_max_vote_cost_limit = 28,
fd_txn_error_enum_enum_would_exceed_account_data_total_limit = 29,
fd_txn_error_enum_enum_duplicate_instruction = 30,
fd_txn_error_enum_enum_insufficient_funds_for_rent = 31,
fd_txn_error_enum_enum_max_loaded_accounts_data_size_exceeded = 32,
fd_txn_error_enum_enum_invalid_loaded_accounts_data_size_limit = 33,
fd_txn_error_enum_enum_resanitization_needed = 34,
fd_txn_error_enum_enum_program_execution_temporarily_restricted = 35,
fd_txn_error_enum_enum_unbalanced_transaction = 36,
}; 
void fd_txn_result_new_disc( fd_txn_result_t * self, uint discriminant );
void fd_txn_result_new( fd_txn_result_t * self );
int fd_txn_result_decode( fd_txn_result_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_txn_result_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_txn_result_decode_unsafe( fd_txn_result_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_txn_result_encode( fd_txn_result_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_txn_result_destroy( fd_txn_result_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_txn_result_walk( void * w, fd_txn_result_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_txn_result_size( fd_txn_result_t const * self );
ulong fd_txn_result_footprint( void );
ulong fd_txn_result_align( void );

FD_FN_PURE uchar fd_txn_result_is_ok( fd_txn_result_t const * self );
FD_FN_PURE uchar fd_txn_result_is_error( fd_txn_result_t const * self );
enum {
fd_txn_result_enum_ok = 0,
fd_txn_result_enum_error = 1,
}; 
void fd_cache_status_new( fd_cache_status_t * self );
int fd_cache_status_decode( fd_cache_status_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_cache_status_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_cache_status_decode_unsafe( fd_cache_status_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_cache_status_decode_offsets( fd_cache_status_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_cache_status_encode( fd_cache_status_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_cache_status_destroy( fd_cache_status_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_cache_status_walk( void * w, fd_cache_status_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_cache_status_size( fd_cache_status_t const * self );
ulong fd_cache_status_footprint( void );
ulong fd_cache_status_align( void );

void fd_status_value_new( fd_status_value_t * self );
int fd_status_value_decode( fd_status_value_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_status_value_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_status_value_decode_unsafe( fd_status_value_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_status_value_decode_offsets( fd_status_value_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_status_value_encode( fd_status_value_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_status_value_destroy( fd_status_value_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_status_value_walk( void * w, fd_status_value_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_status_value_size( fd_status_value_t const * self );
ulong fd_status_value_footprint( void );
ulong fd_status_value_align( void );

void fd_status_pair_new( fd_status_pair_t * self );
int fd_status_pair_decode( fd_status_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_status_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_status_pair_decode_unsafe( fd_status_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_status_pair_decode_offsets( fd_status_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_status_pair_encode( fd_status_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_status_pair_destroy( fd_status_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_status_pair_walk( void * w, fd_status_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_status_pair_size( fd_status_pair_t const * self );
ulong fd_status_pair_footprint( void );
ulong fd_status_pair_align( void );

void fd_slot_delta_new( fd_slot_delta_t * self );
int fd_slot_delta_decode( fd_slot_delta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_delta_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_slot_delta_decode_unsafe( fd_slot_delta_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_delta_decode_offsets( fd_slot_delta_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_slot_delta_encode( fd_slot_delta_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_slot_delta_destroy( fd_slot_delta_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_slot_delta_walk( void * w, fd_slot_delta_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_slot_delta_size( fd_slot_delta_t const * self );
ulong fd_slot_delta_footprint( void );
ulong fd_slot_delta_align( void );

void fd_bank_slot_deltas_new( fd_bank_slot_deltas_t * self );
int fd_bank_slot_deltas_decode( fd_bank_slot_deltas_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_slot_deltas_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_bank_slot_deltas_decode_unsafe( fd_bank_slot_deltas_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_slot_deltas_decode_offsets( fd_bank_slot_deltas_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_bank_slot_deltas_encode( fd_bank_slot_deltas_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_bank_slot_deltas_destroy( fd_bank_slot_deltas_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_bank_slot_deltas_walk( void * w, fd_bank_slot_deltas_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_bank_slot_deltas_size( fd_bank_slot_deltas_t const * self );
ulong fd_bank_slot_deltas_footprint( void );
ulong fd_bank_slot_deltas_align( void );

void fd_pubkey_rewardinfo_pair_new( fd_pubkey_rewardinfo_pair_t * self );
int fd_pubkey_rewardinfo_pair_decode( fd_pubkey_rewardinfo_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_rewardinfo_pair_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_pubkey_rewardinfo_pair_decode_unsafe( fd_pubkey_rewardinfo_pair_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_rewardinfo_pair_decode_offsets( fd_pubkey_rewardinfo_pair_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_pubkey_rewardinfo_pair_encode( fd_pubkey_rewardinfo_pair_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_pubkey_rewardinfo_pair_destroy( fd_pubkey_rewardinfo_pair_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_pubkey_rewardinfo_pair_walk( void * w, fd_pubkey_rewardinfo_pair_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_pubkey_rewardinfo_pair_size( fd_pubkey_rewardinfo_pair_t const * self );
ulong fd_pubkey_rewardinfo_pair_footprint( void );
ulong fd_pubkey_rewardinfo_pair_align( void );

void fd_optional_account_new( fd_optional_account_t * self );
int fd_optional_account_decode( fd_optional_account_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_optional_account_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_optional_account_decode_unsafe( fd_optional_account_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_optional_account_decode_offsets( fd_optional_account_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_optional_account_encode( fd_optional_account_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_optional_account_destroy( fd_optional_account_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_optional_account_walk( void * w, fd_optional_account_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_optional_account_size( fd_optional_account_t const * self );
ulong fd_optional_account_footprint( void );
ulong fd_optional_account_align( void );

void fd_calculated_stake_points_new( fd_calculated_stake_points_t * self );
int fd_calculated_stake_points_decode( fd_calculated_stake_points_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_calculated_stake_points_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_calculated_stake_points_decode_unsafe( fd_calculated_stake_points_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_calculated_stake_points_decode_offsets( fd_calculated_stake_points_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_calculated_stake_points_encode( fd_calculated_stake_points_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_calculated_stake_points_destroy( fd_calculated_stake_points_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_calculated_stake_points_walk( void * w, fd_calculated_stake_points_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_calculated_stake_points_size( fd_calculated_stake_points_t const * self );
ulong fd_calculated_stake_points_footprint( void );
ulong fd_calculated_stake_points_align( void );

void fd_calculated_stake_rewards_new( fd_calculated_stake_rewards_t * self );
int fd_calculated_stake_rewards_decode( fd_calculated_stake_rewards_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_calculated_stake_rewards_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_calculated_stake_rewards_decode_unsafe( fd_calculated_stake_rewards_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_calculated_stake_rewards_decode_offsets( fd_calculated_stake_rewards_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_calculated_stake_rewards_encode( fd_calculated_stake_rewards_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_calculated_stake_rewards_destroy( fd_calculated_stake_rewards_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_calculated_stake_rewards_walk( void * w, fd_calculated_stake_rewards_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_calculated_stake_rewards_size( fd_calculated_stake_rewards_t const * self );
ulong fd_calculated_stake_rewards_footprint( void );
ulong fd_calculated_stake_rewards_align( void );

void fd_duplicate_slot_proof_new( fd_duplicate_slot_proof_t * self );
int fd_duplicate_slot_proof_decode( fd_duplicate_slot_proof_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_duplicate_slot_proof_decode_preflight( fd_bincode_decode_ctx_t * ctx );
void fd_duplicate_slot_proof_decode_unsafe( fd_duplicate_slot_proof_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_duplicate_slot_proof_decode_offsets( fd_duplicate_slot_proof_off_t * self, fd_bincode_decode_ctx_t * ctx );
int fd_duplicate_slot_proof_encode( fd_duplicate_slot_proof_t const * self, fd_bincode_encode_ctx_t * ctx );
void fd_duplicate_slot_proof_destroy( fd_duplicate_slot_proof_t * self, fd_bincode_destroy_ctx_t * ctx );
void fd_duplicate_slot_proof_walk( void * w, fd_duplicate_slot_proof_t const * self, fd_types_walk_fn_t fun, const char *name, uint level );
ulong fd_duplicate_slot_proof_size( fd_duplicate_slot_proof_t const * self );
ulong fd_duplicate_slot_proof_footprint( void );
ulong fd_duplicate_slot_proof_align( void );

FD_PROTOTYPES_END

#endif // HEADER_FD_RUNTIME_TYPES
