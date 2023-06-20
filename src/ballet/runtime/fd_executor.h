#ifndef HEADER_fd_src_ballet_runtime_fd_executor_h
#define HEADER_fd_src_ballet_runtime_fd_executor_h

#include "../fd_ballet_base.h"
#include "../txn/fd_txn.h"
#include "../block/fd_microblock.h"
#include "fd_banks_solana.h"
#include "fd_acc_mgr.h"
#include "../../funk/fd_funk.h"
#include "../poh/fd_poh.h"

FD_PROTOTYPES_BEGIN

typedef struct fd_global_ctx fd_global_ctx_t;

// Should we just get rid of fd_executor and pass the fd_global_ctx_t?
struct fd_executor {
  fd_global_ctx_t* global;
};
typedef struct fd_executor fd_executor_t;

#define FD_EXECUTOR_FOOTPRINT ( sizeof(fd_executor_t) )

void* fd_executor_new( void* mem, fd_global_ctx_t* global, ulong footprint );

fd_executor_t *fd_executor_join( void* mem );

void *fd_executor_leave( fd_executor_t* executor );

void* fd_executor_delete( void* mem );

/* Instruction error codes */
/* TODO: make sure these are serialized consistently with solana_program::InstructionError */
#define FD_EXECUTOR_INSTR_SUCCESS                                ( 0 )  /* Instruction executed successfully */
#define FD_EXECUTOR_INSTR_ERR_GENERIC_ERR                        ( -1 ) /* The program instruction returned an error */
#define FD_EXECUTOR_INSTR_ERR_INVALID_ARG                        ( -2 ) /* The arguments provided to a program were invalid */
#define FD_EXECUTOR_INSTR_ERR_INVALID_INSTR_DATA                 ( -3 ) /* An instruction's data contents were invalid */
#define FD_EXECUTOR_INSTR_ERR_INVALID_ACC_DATA                   ( -4 ) /* An account's data contents was invalid */
#define FD_EXECUTOR_INSTR_ERR_ACC_DATA_TOO_SMALL                 ( -5 ) /* An account's data was too small */
#define FD_EXECUTOR_INSTR_ERR_INSUFFICIENT_FUNDS                 ( -6 ) /* An account's balance was too small to complete the instruction */
#define FD_EXECUTOR_INSTR_ERR_INCORRECT_PROGRAM_ID               ( -7 ) /* The account did not have the expected program id */
#define FD_EXECUTOR_INSTR_ERR_MISSING_REQUIRED_SIGNATURE         ( -8 ) /* A signature was required but not found */
#define FD_EXECUTOR_INSTR_ERR_ACC_ALREADY_INITIALIZED            ( -9  ) /* An initialize instruction was sent to an account that has already been initialized. */
#define FD_EXECUTOR_INSTR_ERR_UNINITIALIZED_ACCOUNT              ( -10 ) /* An attempt to operate on an account that hasn't been initialized. */
#define FD_EXECUTOR_INSTR_ERR_UNBALANCED_INSTR                   ( -11 ) /* Program's instruction lamport balance does not equal the balance after the instruction */
#define FD_EXECUTOR_INSTR_ERR_MODIFIED_PROGRAM_ID                ( -12 ) /* Program illegally modified an account's program id */
#define FD_EXECUTOR_INSTR_ERR_EXTERNAL_ACCOUNT_LAMPORT_SPEND     ( -13 ) /* Program spent the lamports of an account that doesn't belong to it */
#define FD_EXECUTOR_INSTR_ERR_EXTERNAL_DATA_MODIFIED             ( -14 ) /* Program modified the data of an account that doesn't belong to it */
#define FD_EXECUTOR_INSTR_ERR_READONLY_LAMPORT_CHANGE            ( -15 ) /* Read-only account's lamports modified */
#define FD_EXECUTOR_INSTR_ERR_READONLY_DATA_MODIFIED             ( -16 ) /* Read-only account's data was modified */
#define FD_EXECUTOR_INSTR_ERR_DUPLICATE_ACCOUNT_IDX              ( -17 ) /* An account was referenced more than once in a single instruction. Deprecated. */
#define FD_EXECUTOR_INSTR_ERR_EXECUTABLE_MODIFIED                ( -18 ) /* Executable bit on account changed, but shouldn't have */
#define FD_EXECUTOR_INSTR_ERR_RENT_EPOCH_MODIFIED                ( -19 ) /* Rent_epoch account changed, but shouldn't have */
#define FD_EXECUTOR_INSTR_ERR_NOT_ENOUGH_ACC_KEYS                ( -20 ) /* The instruction expected additional account keys */
#define FD_EXECUTOR_INSTR_ERR_ACC_DATA_SIZE_CHANGED              ( -21 ) /* Program other than the account's owner changed the size of the account data */
#define FD_EXECUTOR_INSTR_ERR_ACC_NOT_EXECUTABLE                 ( -22 ) /* The instruction expected an executable account */
#define FD_EXECUTOR_INSTR_ERR_ACC_BORROW_FAILED                  ( -23 ) /* Failed to borrow a reference to account data, already borrowed */
#define FD_EXECUTOR_INSTR_ERR_ACC_BORROW_OUTSTANDING             ( -24 ) /* Account data has an outstanding reference after a program's execution */
#define FD_EXECUTOR_INSTR_ERR_DUPLICATE_ACCOUNT_OUT_OF_SYNC      ( -25 ) /* The same account was multiply passed to an on-chain program's entrypoint, but the program modified them differently. */
#define FD_EXECUTOR_INSTR_ERR_CUSTOM_ERR                         ( -26 ) /* Allows on-chain programs to implement program-specific error types and see them returned by the runtime. */
#define FD_EXECUTOR_INSTR_ERR_INVALID_ERR                        ( -27 ) /* The return value from the program was invalid.  */
#define FD_EXECUTOR_INSTR_ERR_EXECUTABLE_DATA_MODIFIED           ( -28 ) /* Executable account's data was modified */
#define FD_EXECUTOR_INSTR_ERR_EXECUTABLE_LAMPORT_CHANGE          ( -29 ) /* Executable account's lamports modified */
#define FD_EXECUTOR_INSTR_ERR_EXECUTABLE_ACCOUNT_NOT_RENT_EXEMPT ( -30 ) /* Executable accounts must be rent exempt */
#define FD_EXECUTOR_INSTR_ERR_UNSUPPORTED_PROGRAM_ID             ( -31 ) /* Unsupported program id */
#define FD_EXECUTOR_INSTR_ERR_CALL_DEPTH                         ( -32 ) /* Cross-program invocation call depth too deep */
#define FD_EXECUTOR_INSTR_ERR_MISSING_ACC                        ( -33 ) /* An account required by the instruction is missing */
#define FD_EXECUTOR_INSTR_ERR_REENTRANCY_NOT_ALLOWED             ( -34 ) /* Cross-program invocation reentrancy not allowed for this instruction */
#define FD_EXECUTOR_INSTR_ERR_MAX_SEED_LENGTH_EXCEEDED           ( -35 ) /* Length of the seed is too long for address generation */
#define FD_EXECUTOR_INSTR_ERR_INVALID_SEEDS                      ( -36 ) /* Provided seeds do not result in a valid address */
#define FD_EXECUTOR_INSTR_ERR_INVALID_REALLOC                    ( -37 ) /* Failed to reallocate account data of this length */
#define FD_EXECUTOR_INSTR_ERR_COMPUTE_BUDGET_EXCEEDED            ( -38 ) /* Computational budget exceeded */
#define FD_EXECUTOR_INSTR_ERR_PRIVILEGE_ESCALATION               ( -39 ) /* Cross-program invocation with unauthorized signer or writable account */
#define FD_EXECUTOR_INSTR_ERR_PROGRAM_ENVIRONMENT_SETUP_FAILURE  ( -40 ) /* Failed to create program execution environment */
#define FD_EXECUTOR_INSTR_ERR_PROGRAM_FAILED_TO_COMPLETE         ( -41 ) /* Program failed to complete */
#define FD_EXECUTOR_INSTR_ERR_PROGRAM_FAILED_TO_COMPILE          ( -42 ) /* Program failed to compile */
#define FD_EXECUTOR_INSTR_ERR_ACC_IMMUTABLE                      ( -43 ) /* Account is immutable */
#define FD_EXECUTOR_INSTR_ERR_INCORRECT_AUTHORITY                ( -44 ) /* Incorrect authority provided */
#define FD_EXECUTOR_INSTR_ERR_BORSH_IO_ERROR                     ( -45 ) /* Failed to serialize or deserialize account data */
#define FD_EXECUTOR_INSTR_ERR_ACC_NOT_RENT_EXEMPT                ( -46 ) /* An account does not have enough lamports to be rent-exempt */
#define FD_EXECUTOR_INSTR_ERR_INVALID_ACC_OWNER                  ( -47 ) /* Invalid account owner */
#define FD_EXECUTOR_INSTR_ERR_ARITHMETIC_OVERFLOW                ( -48 ) /* Program arithmetic overflowed */
#define FD_EXECUTOR_INSTR_ERR_UNSUPPORTED_SYSVAR                 ( -49 ) /* Unsupported sysvar */
#define FD_EXECUTOR_INSTR_ERR_ILLEGAL_OWNER                      ( -50 ) /* Provided owner is not allowed */
#define FD_EXECUTOR_INSTR_ERR_MAX_ACCS_DATA_SIZE_EXCEEDED        ( -51 ) /* Account data allocation exceeded the maximum accounts data size limit */
#define FD_EXECUTOR_INSTR_ERR_ACTIVE_VOTE_ACC_CLOSE              ( -52 ) /* Active vote account close */

#define FD_EXECUTOR_SYSTEM_ERR_ACCOUNT_ALREADY_IN_USE            ( -1 ) /* an account with the same address already exists */
#define FD_EXECUTOR_SYSTEM_ERR_RESULTS_WITH_NEGATIVE_LAMPORTS    ( -2 ) /* account does not have enough SOL to perform the operation */
#define FD_EXECUTOR_SYSTEM_ERR_INVALID_PROGRAM_ID                ( -3 ) /* cannot assign account to this program id */
#define FD_EXECUTOR_SYSTEM_ERR_INVALID_ACCOUNT_DATA_LENGTH       ( -4 ) /* cannot allocate account data of this length */
#define FD_EXECUTOR_SYSTEM_ERR_MAX_SEED_LENGTH_EXCEEDED          ( -5 ) /* length of requested seed is too long */
#define FD_EXECUTOR_SYSTEM_ERR_ADDRESS_WITH_SEED_MISMATCH        ( -6 ) /* provided address does not match addressed derived from seed */
#define FD_EXECUTOR_SYSTEM_ERR_NONCE_NO_RECENT_BLOCKHASHES       ( -7 ) /* advancing stored nonce requires a populated RecentBlockhashes sysvar */
#define FD_EXECUTOR_SYSTEM_ERR_NONCE_BLOCKHASH_NOT_EXPIRED       ( -8 ) /* stored nonce is still in recent_blockhashes */
#define FD_EXECUTOR_SYSTEM_ERR_NONCE_UNEXPECTED_BLOCKHASH_VALUE  ( -9 ) /* specified nonce does not match stored nonce */

#define FD_EXECUTOR_SIGN_ERR_DATA_OFFSETS                        (-100)
#define FD_EXECUTOR_SIGN_ERR_INSTRUCTION_DATA_SIZE               (-101)
#define FD_EXECUTOR_SIGN_ERR_SIGNATURE                           (-102)

struct fd_rawtxn_b {
  /* Pointer to txn in local wksp */
  void * raw;

  /* Size of txn */
  ushort txn_sz;
};
typedef struct fd_rawtxn_b fd_rawtxn_b_t;

/*
  Execute the given transaction.

  Makes changes to the Funk accounts DB. */
void
fd_execute_txn( fd_executor_t* executor, fd_txn_t * txn_descriptor, fd_rawtxn_b_t* txn_raw ) ;


#define FD_COMPUTE_BUDGET_PRIORITIZATION_FEE_TYPE_COMPUTE_UNIT_PRICE (0)
#define FD_COMPUTE_BUDGET_PRIORITIZATION_FEE_TYPE_DEPRECATED         (1)

/* Context needed to execute a single transaction. */
struct transaction_ctx {
  fd_global_ctx_t * global;
  ulong             compute_unit_limit;       /* Compute unit limit for this transaction. */
  ulong             compute_unit_price;       /* Compute unit price for this transaction. */
  ulong             heap_size;                /* Heap size for VM */
  uint              prioritization_fee_type;  /* The type of prioritization fee to use. */
  fd_txn_t*         txn_descriptor;           /* Descriptor of the transaction. */
  fd_rawtxn_b_t*    txn_raw;                  /* Raw bytes of the transaction. */
  uint              custom_err;               /* When a custom error is returned, this is where the numeric value gets stashed */
  
};
typedef struct transaction_ctx transaction_ctx_t;

/* Context needed to execute a single instruction. TODO: split into a hierarchy of layered contexts.  */
struct instruction_ctx {
  fd_global_ctx_t *   global;
  fd_txn_instr_t *    instr;    /* The instruction */
  transaction_ctx_t * txn_ctx;  /* The transaction context for this instruction */
};
typedef struct instruction_ctx instruction_ctx_t;

/* Type definition for native programs, akin to an interface for native programs.
   The executor will execute instructions designated for a given native program by invoking a function of this type. */
typedef int(*execute_instruction_func_t) ( instruction_ctx_t ctx );

execute_instruction_func_t
fd_executor_lookup_native_program( fd_global_ctx_t* global,  fd_pubkey_t *pubkey ) ;

FD_PROTOTYPES_END

#endif /* HEADER_fd_src_ballet_runtime_fd_executor_h */
