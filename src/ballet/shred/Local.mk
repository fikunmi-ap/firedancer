$(call add-hdrs,fd_shred.h)
$(call add-objs,fd_shred,fd_ballet)
$(call make-unit-test,test_shred,test_shred,fd_ballet fd_util)
$(call fuzz-test,fuzz_shred_parse,fuzz_shred_parse,fd_ballet fd_util)
$(call run-unit-test,test_shred,)
