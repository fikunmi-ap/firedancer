#ifndef HEADER_fd_src_flamenco_runtime_fd_types_custom
#define HEADER_fd_src_flamenco_runtime_fd_types_custom

#include "fd_types_meta.h"
#include "fd_bincode.h"
#include "../../ballet/ed25519/fd_ed25519.h"

typedef void
(* fd_types_walk_fn_t)( void *       self,
                        void const * arg,
                        char const * name,
                        int          type,
                        char const * type_name,
                        uint         level );

#define FD_HASH_FOOTPRINT (32UL)
#define FD_HASH_ALIGN (8UL)
#define FD_PUBKEY_FOOTPRINT FD_HASH_FOOTPRINT
#define FD_PUBKEY_ALIGN FD_HASH_ALIGN

union __attribute__((aligned(FD_HASH_ALIGN))) fd_hash {
  uchar hash[ FD_HASH_FOOTPRINT ];
  uchar key [ FD_HASH_FOOTPRINT ]; // Making fd_hash and fd_pubkey interchangable

  // Generic type specific accessors
  ulong ul  [ FD_HASH_FOOTPRINT / sizeof(ulong) ];
  uchar uc  [ FD_HASH_FOOTPRINT ];
};

typedef union fd_hash fd_hash_t;
typedef union fd_hash fd_pubkey_t;

FD_PROTOTYPES_BEGIN

static inline void
fd_hash_new( fd_hash_t * self FD_FN_UNUSED ) {}

static inline int
fd_hash_decode( fd_hash_t *               self,
                fd_bincode_decode_ctx_t * ctx ) {
  return fd_bincode_bytes_decode( &self->hash[0], sizeof(self->hash), ctx );
}

static inline void
fd_hash_destroy( fd_hash_t const *          self FD_FN_UNUSED,
                 fd_bincode_destroy_ctx_t * ctx  FD_FN_UNUSED ) {}

static inline ulong
fd_hash_size( fd_hash_t const * self FD_FN_UNUSED ) {
  return 32;
}

static inline int
fd_hash_encode( fd_hash_t const *         self,
                fd_bincode_encode_ctx_t * ctx ) {
  return fd_bincode_bytes_encode( &self->hash[0], sizeof(self->hash), ctx );
}

static inline void
fd_hash_walk( void *             w,
              fd_hash_t *        self,
              fd_types_walk_fn_t fun,
              char const *       name,
              uint               level ) {
  fun( w, self->hash, name, FD_FLAMENCO_TYPE_HASH256, name, level );
}

#define fd_hash_check_zero(_x) (!((_x)->ul[0] | (_x)->ul[1] | (_x)->ul[2] | (_x)->ul[3]))
#define fd_hash_set_zero(_x)   {((_x)->ul[0] = 0); ((_x)->ul[1] = 0); ((_x)->ul[2] = 0); ((_x)->ul[3] = 0);}

#define fd_pubkey_new         fd_hash_new
#define fd_pubkey_decode      fd_hash_decode
#define fd_pubkey_encode      fd_hash_encode
#define fd_pubkey_destroy     fd_hash_destroy
#define fd_pubkey_size        fd_hash_size
#define fd_pubkey_check_zero  fd_hash_check_zero
#define fd_pubkey_set_zero    fd_hash_set_zero
#define fd_pubkey_walk        fd_hash_walk

/* https://github.com/solana-labs/solana/blob/8f2c8b8388a495d2728909e30460aa40dcc5d733/sdk/program/src/epoch_schedule.rs#L26 */
struct fd_epoch_schedule {
  ulong slots_per_epoch;
  ulong leader_schedule_slot_offset;
  uchar warmup;
  uchar _pad11[7];  /* Padding, must be zero */
  ulong first_normal_epoch;
  ulong first_normal_slot;
};
typedef struct fd_epoch_schedule fd_epoch_schedule_t;
#define FD_EPOCH_SCHEDULE_FOOTPRINT sizeof(fd_epoch_schedule_t)
#define FD_EPOCH_SCHEDULE_ALIGN (8UL)

void fd_epoch_schedule_new(fd_epoch_schedule_t* self);
int fd_epoch_schedule_decode(fd_epoch_schedule_t* self, fd_bincode_decode_ctx_t * ctx);
int fd_epoch_schedule_encode(fd_epoch_schedule_t const * self, fd_bincode_encode_ctx_t * ctx);
void fd_epoch_schedule_destroy(fd_epoch_schedule_t* self, fd_bincode_destroy_ctx_t * ctx);
void fd_epoch_schedule_walk(void * w, fd_epoch_schedule_t* self, fd_types_walk_fn_t fun, const char *name, uint level);
ulong fd_epoch_schedule_size(fd_epoch_schedule_t const * self);

/* Index structure needed for transaction status (metadata) blocks */
struct fd_txnstatusidx {
    fd_ed25519_sig_t sig;
    ulong offset;
    ulong status_sz;
};
typedef struct fd_txnstatusidx fd_txnstatusidx_t;

FD_PROTOTYPES_END

#endif /* HEADER_fd_src_flamenco_runtime_fd_types_custom */
