/* Code generated by gen_features.py. DO NOT EDIT. */

#ifndef HEADER_fd_src_flamenco_features_fd_features_h
#error "Include fd_features.h instead of this file."
#endif

/* FEATURE_ID_CNT is the number of features in ids */

#define FD_FEATURE_ID_CNT (205UL)

union fd_features {

  ulong f[ FD_FEATURE_ID_CNT ];

  struct {
    /* 0x2577305f7cc65fe7 */ ulong deprecate_rewards_sysvar;
    /* 0x7095d36bc836da32 */ ulong pico_inflation;
    /* 0x8b990f20829df9b8 */ ulong devnet_and_testnet;
    /* 0x47e18859d27e3aa3 */ ulong full_inflation_vote;
    /* 0xe7571f86aa06f160 */ ulong full_inflation_enable;
    /* 0xd924059c5749c4c1 */ ulong secp256k1_program_enabled;
    /* 0x159967bd804742c2 */ ulong spl_token_v2_multisig_fix;
    /* 0x1d41fee249e6cc37 */ ulong no_overflow_rent_distribution;
    /* 0xa6d8eedf48633be2 */ ulong filter_stake_delegation_accounts;
    /* 0x65b79c7f3e7441b3 */ ulong require_custodian_for_locked_stake_authorize;
    /* 0x51949af2871c7c99 */ ulong spl_token_v2_self_transfer_fix;
    /* 0xfaa4899494a281ec */ ulong warp_timestamp_again;
    /* 0x30ab53221abfd626 */ ulong check_init_vote_data;
    /* 0x4ab8b2b10003ad50 */ ulong secp256k1_recover_syscall_enabled;
    /* 0xe8f97382b03240a1 */ ulong system_transfer_zero_check;
    /* 0xe994a4b8eeea84f4 */ ulong blake3_syscall_enabled;
    /* 0x10a1e092dd7f1573 */ ulong dedupe_config_program_signers;
    /* 0xc6eb259e772475c8 */ ulong verify_tx_signatures_len;
    /* 0xfba69c4970d7ad9d */ ulong vote_stake_checked_instructions;
    /* 0xb5b508c4a6313e99 */ ulong rent_for_sysvars;
    /* 0xabff1d2abfa0c4bc */ ulong libsecp256k1_0_5_upgrade_enabled;
    /* 0xa952e12150121a45 */ ulong tx_wide_compute_cap;
    /* 0x62885c46a116e1d6 */ ulong spl_token_v2_set_authority_fix;
    /* 0xd5830390d36ee60e */ ulong merge_nonce_error_into_system_error;
    /* 0xff00aac3cfaafcfe */ ulong disable_fees_sysvar;
    /* 0x6d22c4ce75df6f0b */ ulong stake_merge_with_unmatched_credits_observed;
    /* 0xd544636252beca0e */ ulong zk_token_sdk_enabled;
    /* 0x4b1e586fc635dc65 */ ulong curve25519_syscall_enabled;
    /* 0x7ca46573f5a27822 */ ulong versioned_tx_message_enabled;
    /* 0x1a6958db2ff09870 */ ulong libsecp256k1_fail_on_bad_count;
    /* 0x15766ba9a908483c */ ulong libsecp256k1_fail_on_bad_count2;
    /* 0x4b5c55d9eaf96eee */ ulong instructions_sysvar_owned_by_sysvar;
    /* 0xf162e5606a687206 */ ulong stake_program_advance_activating_credits_observed;
    /* 0x35dd1ed4b9d19b9b */ ulong credits_auto_rewind;
    /* 0x30bf137796030f21 */ ulong demote_program_write_locks;
    /* 0xa5ece90c9d468a56 */ ulong ed25519_program_enabled;
    /* 0xf1084016618f3ec0 */ ulong return_data_syscall_enabled;
    /* 0x92be3cd65cb3e2c3 */ ulong reduce_required_deploy_balance;
    /* 0xbd02d2f51146c257 */ ulong sol_log_data_syscall_enabled;
    /* 0xfcd1ef949cf886f1 */ ulong stakes_remove_delegation_if_inactive;
    /* 0xee2a44e1f54f5e5a */ ulong do_support_realloc;
    /* 0xc548c6b11d33172f */ ulong prevent_calling_precompiles_as_programs;
    /* 0xf1d277eeafe62810 */ ulong optimize_epoch_boundary_updates;
    /* 0xbdb86acdf94382f4 */ ulong remove_native_loader;
    /* 0xa7654aedafa0a2a4 */ ulong send_to_tpu_vote_port;
    /* 0x3ab28ef5d5cf7ca6 */ ulong requestable_heap_size;
    /* 0x9021d56a2c13c119 */ ulong disable_fee_calculator;
    /* 0x2b8134b3adacd035 */ ulong add_compute_budget_program;
    /* 0x1cec25430fa6229f */ ulong nonce_must_be_writable;
    /* 0x4c8dc4f1e61649dd */ ulong spl_token_v3_3_0_release;
    /* 0xe79e065446760ac3 */ ulong leave_nonce_on_success;
    /* 0x7a63cd44b42c0b82 */ ulong reject_empty_instruction_without_program;
    /* 0x168bc52564a1181f */ ulong fixed_memcpy_nonoverlapping_check;
    /* 0xe4f010aefd867566 */ ulong reject_non_rent_exempt_vote_withdraws;
    /* 0xa85d651d8da169c6 */ ulong evict_invalid_stakes_cache_entries;
    /* 0x7bc99a080444c8d9 */ ulong allow_votes_to_directly_update_vote_state;
    /* 0x0203237cf1901d09 */ ulong cap_accounts_data_len;
    /* 0x7e8f67ed363c31a6 */ ulong max_tx_account_locks;
    /* 0xf28b599c33eda89f */ ulong require_rent_exempt_accounts;
    /* 0xffed385aa352ef27 */ ulong filter_votes_outside_slot_hashes;
    /* 0x06adecee02a12019 */ ulong update_syscall_base_costs;
    /* 0xd79987a3abf61d2d */ ulong stake_deactivate_delinquent_instruction;
    /* 0xd56fc1708dc98c13 */ ulong stake_redelegate_instruction;
    /* 0x317a863da11d0a8d */ ulong vote_withdraw_authority_may_change_authorized_voter;
    /* 0x96ac475392d395d8 */ ulong spl_associated_token_account_v1_0_4;
    /* 0x9479e273205da38a */ ulong reject_vote_account_close_unless_zero_credit_epoch;
    /* 0xd89ef3a8c30d1ba7 */ ulong add_get_processed_sibling_instruction_syscall;
    /* 0xe2276359bb5e6007 */ ulong bank_transaction_count_fix;
    /* 0xf02385c19b529325 */ ulong disable_bpf_deprecated_load_instructions;
    /* 0xf1762ae45609273b */ ulong disable_bpf_unresolved_symbols_at_runtime;
    /* 0xbff452bfed793f26 */ ulong record_instruction_in_transaction_context_push;
    /* 0xe505bd1df7964bfc */ ulong syscall_saturated_math;
    /* 0x80288c645d23a80b */ ulong check_physical_overlapping;
    /* 0x499ab78fe1142d63 */ ulong limit_secp256k1_recovery_id;
    /* 0x9f43d6cae453a7e5 */ ulong disable_deprecated_loader;
    /* 0x562f76c6d74c31ea */ ulong check_slice_translation_size;
    /* 0xf70ae71daf8a1bd6 */ ulong stake_split_uses_rent_sysvar;
    /* 0x7f6371bf4a56a106 */ ulong add_get_minimum_delegation_instruction_to_stake_program;
    /* 0x3ca58e628f040b68 */ ulong error_on_syscall_bpf_function_hash_collisions;
    /* 0x7e787d5c6d662d23 */ ulong reject_callx_r10;
    /* 0xffc496b47872d42f */ ulong drop_redundant_turbine_path;
    /* 0x2bf29bf13f0e1d5d */ ulong executables_incur_cpi_data_cost;
    /* 0x073a0a7d3f570b55 */ ulong fix_recent_blockhashes;
    /* 0x4d6ae02c256bdf10 */ ulong update_rewards_from_cached_accounts;
    /* 0x5bf898a97b29c67f */ ulong enable_partitioned_epoch_reward;
    /* 0xe8f10f26141749dd */ ulong spl_token_v3_4_0;
    /* 0xe02ac5f848d395d8 */ ulong spl_associated_token_account_v1_1_0;
    /* 0x7b285d0430faf2fc */ ulong default_units_per_instruction;
    /* 0xf3ee1d3b0fcfec0c */ ulong stake_allow_zero_undelegated_amount;
    /* 0xfc0fb9c317b6c16b */ ulong require_static_program_ids_in_transaction;
    /* 0x562011e7dbadd982 */ ulong stake_raise_minimum_delegation_to_1_sol;
    /* 0x5458f71cc7cd31e0 */ ulong stake_minimum_delegation_for_rewards;
    /* 0x606490c1431ae278 */ ulong add_set_compute_unit_price_ix;
    /* 0xd151c2100e71455b */ ulong disable_deploy_of_alloc_free_syscall;
    /* 0x2fdc300bd0720815 */ ulong include_account_index_in_rent_error;
    /* 0x5a5c2eab595223bf */ ulong add_shred_type_to_shred_seed;
    /* 0xdda7e56980356920 */ ulong warp_timestamp_with_a_vengeance;
    /* 0xc358973434287fe8 */ ulong separate_nonce_from_blockhash;
    /* 0xe210655c824cfb2f */ ulong enable_durable_nonce;
    /* 0xc3cc3bdc6eea2eb1 */ ulong vote_state_update_credit_per_dequeue;
    /* 0x2758d3af483c6abe */ ulong quick_bail_on_panic;
    /* 0xb0e571b1579c09fc */ ulong nonce_must_be_authorized;
    /* 0xcb5d0779751b0c2b */ ulong nonce_must_be_advanceable;
    /* 0x5795654d01457757 */ ulong vote_authorize_with_seed;
    /* 0x6799d3fbcc438c0c */ ulong cap_accounts_data_size_per_block;
    /* 0x4439548ebff1d6f1 */ ulong preserve_rent_epoch_for_rent_exempt_accounts;
    /* 0xe5394b6d65186d70 */ ulong enable_bpf_loader_extend_program_ix;
    /* 0x8f688d4e3ab17a60 */ ulong enable_early_verification_of_account_modifications;
    /* 0xe364c75ced9b53a7 */ ulong skip_rent_rewrites;
    /* 0x41b914ee34cb0368 */ ulong prevent_crediting_accounts_that_end_rent_paying;
    /* 0x14a73a8e87cee681 */ ulong cap_bpf_program_instruction_accounts;
    /* 0xe21e6fa7a57304e2 */ ulong loosen_cpi_size_restriction;
    /* 0x6d1e7092a4aae574 */ ulong use_default_units_in_fee_calculation;
    /* 0x2ca5833736ba5c69 */ ulong compact_vote_state_updates;
    /* 0x855543b1e6e31e10 */ ulong incremental_snapshot_only_incremental_hash_calculation;
    /* 0x204b4907aacbc996 */ ulong disable_cpi_setting_executable_and_rent_epoch;
    /* 0x80f1bedb2c2facaf */ ulong on_load_preserve_rent_epoch_for_rent_exempt_accounts;
    /* 0x6796bad7d20e8806 */ ulong account_hash_ignore_slot;
    /* 0xe0724b3421984e49 */ ulong set_exempt_rent_epoch_max;
    /* 0xada15a4b53efaad4 */ ulong relax_authority_signer_check_for_lookup_table_creation;
    /* 0x41fd0d35fd8339c9 */ ulong stop_sibling_instruction_search_at_parent;
    /* 0x91b03055f3636ce0 */ ulong vote_state_update_root_fix;
    /* 0x5b2c24f10d5a1a81 */ ulong cap_accounts_data_allocations_per_transaction;
    /* 0x1728caf9bc767c3f */ ulong epoch_accounts_hash;
    /* 0x819bd0526bd811cb */ ulong remove_deprecated_request_unit_ix;
    /* 0x0d8a57d3828615b9 */ ulong disable_rehash_for_rent_epoch;
    /* 0xb527e5f5e76ce07b */ ulong increase_tx_account_lock_limit;
    /* 0x2ac194a6a536cee4 */ ulong limit_max_instruction_trace_length;
    /* 0xa6862bcb2044252b */ ulong check_syscall_outputs_do_not_overlap;
    /* 0x9f4323f726178849 */ ulong enable_bpf_loader_set_authority_checked_ix;
    /* 0xaaef1edeb6c5bf85 */ ulong enable_alt_bn128_syscall;
    /* 0x795c88a20bcb6dfd */ ulong enable_program_redeployment_cooldown;
    /* 0x8a8eb9085ca2bb0b */ ulong commission_updates_only_allowed_in_first_half_of_epoch;
    /* 0x33e6e44dc3a9cfb2 */ ulong enable_turbine_fanout_experiments;
    /* 0xc3df53505d0f7aed */ ulong disable_turbine_fanout_experiments;
    /* 0x784adb4f1d180869 */ ulong drop_merkle_shreds;
    /* 0x71eba1d288ba2bfc */ ulong keep_merkle_shreds;
    /* 0x823d14dd6235f859 */ ulong move_serialized_len_ptr_in_cpi;
    /* 0xb3f6cd09abba192b */ ulong update_hashes_per_tick;
    /* 0x3a315b1ab012eec3 */ ulong enable_big_mod_exp_syscall;
    /* 0x500aab8a23ff8b33 */ ulong disable_builtin_loader_ownership_chains;
    /* 0xffe35ea7abb29bbb */ ulong cap_transaction_accounts_data_size;
    /* 0x8a22c4e80489c387 */ ulong remove_congestion_multiplier_from_fee_calculation;
    /* 0xce82bcc13c5649fa */ ulong enable_request_heap_frame_ix;
    /* 0x8ff9cf8537529ed8 */ ulong prevent_rent_paying_rent_recipients;
    /* 0xd6120d1b80de5fea */ ulong delay_visibility_of_program_deployment;
    /* 0xca9ab2701c9aa81b */ ulong apply_cost_tracker_during_replay;
    /* 0x3f190188b368d6ca */ ulong bpf_account_data_direct_mapping;
    /* 0x55d3a0c392cf63e0 */ ulong add_set_tx_loaded_accounts_data_size_instruction;
    /* 0x0e7aa95037c5daac */ ulong switch_to_new_elf_parser;
    /* 0xe2d13039d5f9c6a6 */ ulong round_up_heap_size;
    /* 0xcae3ec6191402713 */ ulong remove_bpf_loader_incorrect_program_id;
    /* 0xa6b1a5bbb608b7c9 */ ulong include_loaded_accounts_data_size_in_fee_calculation;
    /* 0x50a615bae8ca3874 */ ulong native_programs_consume_cu;
    /* 0xda4dd6055b75ae43 */ ulong simplify_writable_program_account_check;
    /* 0x2f51d89fe8ee0500 */ ulong stop_truncating_strings_in_syscalls;
    /* 0x61aaf185493a599f */ ulong clean_up_delegation_errors;
    /* 0x74326f811fd7d861 */ ulong vote_state_add_vote_latency;
    /* 0x2bd7391d0e103c41 */ ulong checked_arithmetic_in_fee_validation;
    /* 0x401b668e4b13b8f9 */ ulong last_restart_slot_sysvar;
    /* 0x74b022574093eeec */ ulong reduce_stake_warmup_cooldown;
    /* 0x81b8fd99bea25f9b */ ulong revise_turbine_epoch_stakes;
    /* 0x3cbf822ccb2eebd4 */ ulong enable_poseidon_syscall;
    /* 0xe9d32123513c4d0d */ ulong timely_vote_credits;
    /* 0x64205286d7935342 */ ulong remaining_compute_units_syscall_enabled;
    /* 0x97f912be04ecd673 */ ulong enable_program_runtime_v2_and_loader_v4;
    /* 0x4b241cb4c6f3b3b2 */ ulong require_rent_exempt_split_destination;
    /* 0x21746beaa849f9d9 */ ulong better_error_codes_for_tx_lamport_check;
    /* 0x9bb55b5df1c396c5 */ ulong enable_alt_bn128_compression_syscall;
    /* 0x6b9b55aefe23036c */ ulong programify_feature_gate_program;
    /* 0xe779d032af3fc8c8 */ ulong update_hashes_per_tick2;
    /* 0x583989aa9681db6a */ ulong update_hashes_per_tick3;
    /* 0xa511cde5058d996f */ ulong update_hashes_per_tick4;
    /* 0xa414b36a8ea378a1 */ ulong update_hashes_per_tick5;
    /* 0x6c49f08f6ae2dad4 */ ulong update_hashes_per_tick6;
    /* 0x8c2c2963ae9f420c */ ulong validate_fee_collector_account;
    /* 0xcd42326b6c24cb0e */ ulong enable_zk_transfer_with_fee;
    /* 0xd17b392feb1e0fe6 */ ulong drop_legacy_shreds;
    /* 0x0207866b7b2c7452 */ ulong consume_blockstore_duplicate_proofs;
    /* 0x592e701c2ba17409 */ ulong index_erasure_conflict_duplicate_proofs;
    /* 0xbe955088bcb5a209 */ ulong curve25519_restrict_msm_length;
    /* 0xfbce25936c716309 */ ulong allow_commission_decrease_at_any_time;
    /* 0x116e31cc55ce7d0b */ ulong merkle_conflict_duplicate_proofs;
    /* 0x8c43e9b9ea49be60 */ ulong disable_bpf_loader_instructions;
    /* 0x9b6307ae6da60a0b */ ulong deprecate_executable_meta_update_in_bpf_loader;
    /* 0xf423d4e1d688cb0e */ ulong enable_zk_proof_from_account;
    /* 0xa1518043438beb0d */ ulong cost_model_requested_write_lock_cost;
    /* 0xdb27ab6a4a6379d5 */ ulong enable_gossip_duplicate_proof_ingestion;
    /* 0x814079c434b79c66 */ ulong enable_chained_merkle_shreds;
    /* 0xfde0b578d38fc5a1 */ ulong remove_rounding_in_fee_calculation;
    /* 0xf711255aedfe2d0d */ ulong enable_tower_sync_ix;
    /* 0x81f658d2653a6051 */ ulong deprecate_unused_legacy_vote_plumbing;
    /* 0xf1f206f6027db529 */ ulong reward_full_priority_fee;
    /* 0x1d15c9469c7c0ca8 */ ulong disable_rent_fees_collection;
    /* 0xb6edac8134dff06e */ ulong add_new_reserved_account_keys;
    /* 0x7e4172e5ba362509 */ ulong chained_merkle_conflict_duplicate_proofs;
    /* 0x8ba9e9038d9fdcff */ ulong simplify_alt_bn128_syscall_error_codes;
    /* 0xafe148ad652172dd */ ulong abort_on_invalid_curve;
    /* 0x91a7af96555ea309 */ ulong ed25519_precompile_verify_strict;
    /* 0x8e1411a93085cb0e */ ulong zk_elgamal_proof_program_enabled;
    /* 0x0b9047b5bb9ef961 */ ulong move_stake_and_move_lamports_ixs;
    /* 0xa5a66405d0ab6309 */ ulong deprecate_legacy_vote_ixs;
    /* 0x81fcbfa0d0f6b105 */ ulong partitioned_epoch_rewards_superfeature;
    /* 0x2c38e34ff071060d */ ulong enable_secp256r1_precompile;
    /* 0x829062f252ef5ba8 */ ulong get_sysvar_syscall_enabled;
  };

};
