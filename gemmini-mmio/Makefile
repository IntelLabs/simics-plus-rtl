tests_base = template tiled_matmul_ws
tests_linux = $(tests_base:=-linux)

all: $(tests_linux) lib

.PHONY: lib
# .PHONY: config
# config:
# 	cd ../gemmini-rocc-tests/ && \
# 	autoconf && \
# 	cd ../gemmini-mmio && \
# 	mkdir -p build && cd build && \
# 	../../gemmini-rocc-tests/configure
# make_args = abs_top_srcdir=$$(realpath ../../gemmini-rocc-tests) \
# 			XLEN=64 \
# 			src_dir=$$(realpath ../../gemmini-rocc-tests/bareMetalC) \
# 			CC_LINUX=musl-gcc \
# 			CFLAGS="$(CFLAGS)" \
# 			GEMMINI_HEADERS=$(GEMMINI_HEADERS)

USE_MUSL := 1
ifeq ($(USE_MUSL), 1)
	GCC := musl-gcc -lm -lc -static
else
	GCC := gcc
endif


SRC_DIR := $(shell realpath src)
BASE_DIR := $(shell realpath .)
GEMMINI_HEADERS := $(shell realpath include/gemmini.h) $(shell realpath include/gemmini_params.h) $(shell realpath include/gemmini_testutils.h)

CFLAGS := -std=gnu99 -ffast-math -fPIC -I$(BASE_DIR)

vpath %.c $(SRC_DIR)

%-linux: %.c $(GEMMINI_HEADERS)
	mkdir -p build && cd build && \
	$(GCC) $(CFLAGS) $< $(LFLAGS) -o $@

lib: libgemmini.so

libgemmini.so: $(GEMMINI_HEADERS)
	mkdir -p lib && cd lib && \
	$(GCC) $(CFLAGS) -shared $< $(BASE_DIR)/stub.c $(LFAGS) -o libgemmini.so
