#include "../fd_tests.h"
int test_1191(fd_executor_test_suite_t *suite) {
  fd_executor_test_t test;
  fd_memset( &test, 0, FD_EXECUTOR_TEST_FOOTPRINT );
  test.disable_cnt = 47;
  uchar disabled_features[] = { 105,110,55,77,121,116,106,103,112,30,27,113,122,123,124,2,24,120,80,128,111,126,109,82,61,114,125,76,56,26,79,62,89,75,117,90,83,118,33,78,98,92,108,15,87,29,127 };
  test.disable_feature = disabled_features;
  test.bt = "   2: solana_stake_program::stake_instruction::tests::test_stake_process_instruction_error_ordering::new_behavior             at ./src/stake_instruction.rs:6511:5   3: solana_stake_program::stake_instruction::tests::test_stake_process_instruction_error_ordering::new_behavior::{{closure}}             at ./src/stake_instruction.rs:6511:5   4: core::ops::function::FnOnce::call_once             at /rustc/0677edc86e342f333d4828b0ee1ef395a4e70fe5/library/core/src/ops/function.rs:227:5";
  test.test_name = "stake_instruction::tests::test_stake_process_instruction_error_ordering::new_behavior";
  test.test_nonce  = 451;
  test.test_number = 1191;
  if (fd_executor_test_suite_check_filter(suite, &test)) return -9999;
  ulong test_accs_len = 0;
  fd_executor_test_acc_t* test_accs = fd_alloca( 1UL, FD_EXECUTOR_TEST_ACC_FOOTPRINT * test_accs_len );
  fd_memset( test_accs, 0, FD_EXECUTOR_TEST_ACC_FOOTPRINT * test_accs_len );

  fd_base58_decode_32( "Stake11111111111111111111111111111111111111",  (unsigned char *) &test.program_id);
  static uchar const fd_flamenco_native_prog_test_1191_raw[] = { 0x00,0x00,0x00,0x01,0x01,0x06,0xa1,0xd8,0x17,0x91,0x37,0x54,0x2a,0x98,0x34,0x37,0xbd,0xfe,0x2a,0x7a,0xb2,0x55,0x7f,0x53,0x5c,0x8a,0x78,0x72,0x2b,0x68,0xa4,0x9d,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x08,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff };
  test.raw_tx = fd_flamenco_native_prog_test_1191_raw;
  test.raw_tx_len = 81UL;
  test.expected_result = -20;
  test.custom_err = 0;

  test.accs_len = test_accs_len;
  test.accs = test_accs;

  return fd_executor_run_test( &test, suite );
}
