#ifndef HEADER_fd_src_disco_gui_fd_gui_h
#define HEADER_fd_src_disco_gui_fd_gui_h

#include "../fd_disco_base.h"

#include "../../ballet/http/fd_http_server.h"
#include "../../ballet/http/fd_hcache.h"
#include "../../flamenco/types/fd_types.h"
#include "../../flamenco/leaders/fd_leaders.h"

#include "../topo/fd_topo.h"

#define FD_GUI_SLOT_LEVEL_INCOMPLETE               (0)
#define FD_GUI_SLOT_LEVEL_COMPLETED                (1)
#define FD_GUI_SLOT_LEVEL_OPTIMISTICALLY_CONFIRMED (2)
#define FD_GUI_SLOT_LEVEL_ROOTED                   (3)
#define FD_GUI_SLOT_LEVEL_FINALIZED                (4)

struct fd_gui_gossip_peer {
  fd_pubkey_t pubkey[ 1 ];
  ulong       wallclock;
  ushort      shred_version;

  int has_version;
  struct {
    ushort major;
    ushort minor;
    ushort patch;

    int    has_commit;
    uint   commit;

    uint   feature_set;
  } version;

  struct {
    uint   ipv4;
    ushort port;
  } sockets[ 12 ];
};

struct fd_gui_vote_account {
  fd_pubkey_t pubkey[ 1 ];
  fd_pubkey_t vote_account[ 1 ];

  ulong       activated_stake;
  ulong       last_vote;
  ulong       root_slot;
  ulong       epoch_credits;
  uchar       commission;
  int         delinquent;
};

struct fd_gui_validator_info {
  fd_pubkey_t pubkey[ 1 ];

  char name[ 64 ];
  char website[ 128 ];
  char details[ 256 ];
  char icon_uri[ 128 ];
};

struct fd_gui_txn_waterfall {
  struct {
    ulong quic;
    ulong udp;
    ulong gossip;
  } in;

  struct {
    ulong quic_overrun;
    ulong quic_quic_invalid;
    ulong quic_udp_invalid;
    ulong verify_overrun;
    ulong verify_parse;
    ulong verify_failed;
    ulong verify_duplicate;
    ulong dedup_duplicate;
    ulong pack_invalid;
    ulong pack_retained;
    ulong pack_wait_full;
    ulong pack_leader_slow;
    ulong bank_invalid;
    ulong block_success;
    ulong block_fail;
  } out;
};

typedef struct fd_gui_txn_waterfall fd_gui_txn_waterfall_t;

struct fd_gui_tile_timers {
  ulong housekeeping_ticks;
  ulong backpressure_ticks;
  ulong caught_up_ticks;
  ulong overrun_polling_ticks;
  ulong overrun_reading_ticks;
  ulong filter_before_frag_ticks;
  ulong filter_after_frag_ticks;
  ulong finish_ticks;
};

typedef struct fd_gui_tile_timers fd_gui_tile_timers_t;

struct fd_gui_slot {
  ulong slot;
  long  completed_time;
  int   mine;
  int   skipped;
  int   level;
  ulong total_txn_cnt;
  ulong vote_txn_cnt;
  ulong failed_txn_cnt;
  ulong compute_units;
  ulong fees;

  fd_gui_txn_waterfall_t waterfall_begin[ 1 ];
  fd_gui_txn_waterfall_t waterfall_end[ 1 ];

  ulong                  tile_timers_begin_snap_idx;
  fd_gui_tile_timers_t   tile_timers_begin[ 64 ];
  ulong                  tile_timers_end_snap_idx;
  fd_gui_tile_timers_t   tile_timers_end[ 64 ];
};

typedef struct fd_gui_slot fd_gui_slot_t;

struct fd_gui {
  fd_hcache_t * hcache;

  fd_topo_t * topo;

  long next_sample_100millis;
  long next_sample_10millis;

  struct {
    fd_pubkey_t identity_key[ 1 ];
    char identity_key_base58[ FD_BASE58_ENCODED_32_SZ+1 ];

    char const * version;        
    char const * cluster;

    long  startup_time_nanos;

    ulong balance;
    ulong estimated_slot_duration_nanos;

    ulong net_tile_cnt;
    ulong quic_tile_cnt;
    ulong verify_tile_cnt;
    ulong bank_tile_cnt;
    ulong shred_tile_cnt;

    ulong slot_rooted;
    ulong slot_optimistically_confirmed;
    ulong slot_completed;
    ulong slot_estimated;

    ulong estimated_tps;
    ulong estimated_vote_tps;
    ulong estimated_failed_tps;

    fd_gui_txn_waterfall_t txn_waterfall_reference[ 1 ];
    fd_gui_txn_waterfall_t txn_waterfall_current[ 1 ];

    ulong                  tile_timers_snap_idx;
    fd_gui_tile_timers_t   tile_timers_snap[ 432000UL ][ 64 ]; /* TODO: This can only store about 1 hour of samples */
  } summary;

  fd_gui_slot_t slots[ 864000UL ][ 1 ];

  struct {
    int has_epoch[ 2 ];

    struct {
      ulong epoch;
      ulong start_slot;
      ulong end_slot;
      ulong excluded_stake;
      fd_epoch_leaders_t * lsched;
      uchar __attribute__((aligned(FD_EPOCH_LEADERS_ALIGN))) _lsched[ FD_EPOCH_LEADERS_FOOTPRINT(50000UL, 432000UL) ];
      fd_stake_weight_t stakes[ 50000UL ];
    } epochs[ 2 ];
  } epoch;

  struct {
    ulong                     peer_cnt;
    struct fd_gui_gossip_peer peers[ 40200 ];
  } gossip;

  struct {
    ulong                      vote_account_cnt;
    struct fd_gui_vote_account vote_accounts[ 40200 ];
  } vote_account;

  struct {
    ulong                        info_cnt;
    struct fd_gui_validator_info info[ 40200 ];
  } validator_info;
};

typedef struct fd_gui fd_gui_t;

FD_PROTOTYPES_BEGIN

FD_FN_CONST ulong
fd_gui_align( void );

FD_FN_CONST ulong
fd_gui_footprint( void );

void *
fd_gui_new( void *        shmem,
            fd_hcache_t * hcache,
            char const *  version,
            char const *  cluster,
            uchar const * identity_key,
            fd_topo_t *   topo );

fd_gui_t *
fd_gui_join( void * shmem );

void
fd_gui_ws_open( fd_gui_t *  gui,
                ulong       conn_id );

int
fd_gui_ws_message( fd_gui_t *    gui,
                   ulong         ws_conn_id,
                   uchar const * data,
                   ulong         data_len );

void
fd_gui_plugin_message( fd_gui_t *    gui,
                       ulong         plugin_msg,
                       uchar const * msg,
                       ulong         msg_len );

void
fd_gui_poll( fd_gui_t * gui );

FD_PROTOTYPES_END

#endif /* HEADER_fd_src_disco_gui_fd_gui_h */
