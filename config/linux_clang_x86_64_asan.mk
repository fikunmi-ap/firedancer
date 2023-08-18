BUILDDIR:=linux/clang/x86_64_asan
include config/linux_clang_x86_64.mk

ifneq ($(DISABLE_OPTIMIZATION),)
CPPFLAGS+=-O0
endif

FD_HAS_ASAN:=1
CPPFLAGS+=-DFD_HAS_ASAN=1

CPPFLAGS+=-fsanitize=address
LDFLAGS+=-fsanitize=address

