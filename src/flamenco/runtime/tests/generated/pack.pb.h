/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8-dev */

#ifndef PB_ORG_SOLANA_SEALEVEL_V1_PACK_PB_H_INCLUDED
#define PB_ORG_SOLANA_SEALEVEL_V1_PACK_PB_H_INCLUDED

#include "../../../nanopb/pb_firedancer.h"
#include "metadata.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct fd_exec_test_pack_compute_budget_context {
    pb_size_t instr_datas_count;
    pb_bytes_array_t **instr_datas;
} fd_exec_test_pack_compute_budget_context_t;

typedef struct fd_exec_test_pack_compute_budget_effects {
    uint64_t compute_unit_limit;
    uint64_t rewards;
    uint32_t heap_sz;
    uint32_t loaded_acct_data_sz;
    /* To prevent empty effects when encoding a "skipped" effects */
    uint32_t is_empty;
} fd_exec_test_pack_compute_budget_effects_t;

typedef struct fd_exec_test_pack_compute_budget_fixture {
    bool has_metadata;
    fd_exec_test_fixture_metadata_t metadata;
    bool has_input;
    fd_exec_test_pack_compute_budget_context_t input;
    bool has_output;
    fd_exec_test_pack_compute_budget_effects_t output;
} fd_exec_test_pack_compute_budget_fixture_t;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_INIT_DEFAULT {0, NULL}
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_INIT_DEFAULT {0, 0, 0, 0, 0}
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_INIT_DEFAULT {false, FD_EXEC_TEST_FIXTURE_METADATA_INIT_DEFAULT, false, FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_INIT_DEFAULT, false, FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_INIT_DEFAULT}
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_INIT_ZERO {0, NULL}
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_INIT_ZERO {0, 0, 0, 0, 0}
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_INIT_ZERO {false, FD_EXEC_TEST_FIXTURE_METADATA_INIT_ZERO, false, FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_INIT_ZERO, false, FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_INIT_ZERO}

/* Field tags (for use in manual encoding/decoding) */
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_INSTR_DATAS_TAG 1
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_COMPUTE_UNIT_LIMIT_TAG 1
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_REWARDS_TAG 2
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_HEAP_SZ_TAG 3
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_LOADED_ACCT_DATA_SZ_TAG 4
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_IS_EMPTY_TAG 5
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_METADATA_TAG 1
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_INPUT_TAG 2
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_OUTPUT_TAG 3

/* Struct field encoding specification for nanopb */
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_FIELDLIST(X, a) \
X(a, POINTER,  REPEATED, BYTES,    instr_datas,       1)
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_CALLBACK NULL
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_DEFAULT NULL

#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT64,   compute_unit_limit,   1) \
X(a, STATIC,   SINGULAR, UINT64,   rewards,           2) \
X(a, STATIC,   SINGULAR, UINT32,   heap_sz,           3) \
X(a, STATIC,   SINGULAR, UINT32,   loaded_acct_data_sz,   4) \
X(a, STATIC,   SINGULAR, UINT32,   is_empty,          5)
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_CALLBACK NULL
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_DEFAULT NULL

#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  metadata,          1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  input,             2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  output,            3)
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_CALLBACK NULL
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_DEFAULT NULL
#define fd_exec_test_pack_compute_budget_fixture_t_metadata_MSGTYPE fd_exec_test_fixture_metadata_t
#define fd_exec_test_pack_compute_budget_fixture_t_input_MSGTYPE fd_exec_test_pack_compute_budget_context_t
#define fd_exec_test_pack_compute_budget_fixture_t_output_MSGTYPE fd_exec_test_pack_compute_budget_effects_t

extern const pb_msgdesc_t fd_exec_test_pack_compute_budget_context_t_msg;
extern const pb_msgdesc_t fd_exec_test_pack_compute_budget_effects_t_msg;
extern const pb_msgdesc_t fd_exec_test_pack_compute_budget_fixture_t_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_FIELDS &fd_exec_test_pack_compute_budget_context_t_msg
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_FIELDS &fd_exec_test_pack_compute_budget_effects_t_msg
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_FIELDS &fd_exec_test_pack_compute_budget_fixture_t_msg

/* Maximum encoded size of messages (where known) */
/* fd_exec_test_PackComputeBudgetContext_size depends on runtime parameters */
/* fd_exec_test_PackComputeBudgetFixture_size depends on runtime parameters */
#define FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_SIZE 40
#define ORG_SOLANA_SEALEVEL_V1_PACK_PB_H_MAX_SIZE FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_SIZE

/* Mapping from canonical names (mangle_names or overridden package name) */
#define org_solana_sealevel_v1_PackComputeBudgetContext fd_exec_test_PackComputeBudgetContext
#define org_solana_sealevel_v1_PackComputeBudgetEffects fd_exec_test_PackComputeBudgetEffects
#define org_solana_sealevel_v1_PackComputeBudgetFixture fd_exec_test_PackComputeBudgetFixture
#define ORG_SOLANA_SEALEVEL_V1_PACK_COMPUTE_BUDGET_CONTEXT_INIT_DEFAULT FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_INIT_DEFAULT
#define ORG_SOLANA_SEALEVEL_V1_PACK_COMPUTE_BUDGET_EFFECTS_INIT_DEFAULT FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_INIT_DEFAULT
#define ORG_SOLANA_SEALEVEL_V1_PACK_COMPUTE_BUDGET_FIXTURE_INIT_DEFAULT FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_INIT_DEFAULT
#define ORG_SOLANA_SEALEVEL_V1_PACK_COMPUTE_BUDGET_CONTEXT_INIT_ZERO FD_EXEC_TEST_PACK_COMPUTE_BUDGET_CONTEXT_INIT_ZERO
#define ORG_SOLANA_SEALEVEL_V1_PACK_COMPUTE_BUDGET_EFFECTS_INIT_ZERO FD_EXEC_TEST_PACK_COMPUTE_BUDGET_EFFECTS_INIT_ZERO
#define ORG_SOLANA_SEALEVEL_V1_PACK_COMPUTE_BUDGET_FIXTURE_INIT_ZERO FD_EXEC_TEST_PACK_COMPUTE_BUDGET_FIXTURE_INIT_ZERO

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
