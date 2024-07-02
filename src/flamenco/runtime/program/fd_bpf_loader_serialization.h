#ifndef HEADER_fd_src_flamenco_runtime_program_fd_bpf_loader_serialization_h
#define HEADER_fd_src_flamenco_runtime_program_fd_bpf_loader_serialization_h

#include "../../fd_flamenco_base.h"

#define MAX_PERMITTED_DATA_INCREASE (10240UL)
#define FD_BPF_ALIGN_OF_U128        (8UL    )
#define FD_NON_DUP_MARKER           (0xFF   )

FD_PROTOTYPES_BEGIN

uchar *
fd_bpf_loader_input_serialize_aligned( fd_exec_instr_ctx_t ctx, 
                                       ulong *             sz, 
                                       ulong *             pre_lens,
                                       int                 copy_account_data );

int
fd_bpf_loader_input_deserialize_aligned( fd_exec_instr_ctx_t ctx, 
                                         ulong const *       pre_lens,
                                         uchar *             buffer,
                                         ulong               buffer_sz,
                                         int                 copy_account_data );

uchar *
fd_bpf_loader_input_serialize_unaligned( fd_exec_instr_ctx_t ctx, 
                                         ulong *             sz, 
                                         ulong *             pre_lens );

int
fd_bpf_loader_input_deserialize_unaligned( fd_exec_instr_ctx_t ctx, 
                                           ulong const *       pre_lens, 
                                           uchar *             input, 
                                           ulong               input_sz );


FD_PROTOTYPES_END

#endif /* HEADER_fd_src_flamenco_runtime_program_fd_bpf_loader_serialization_h */
