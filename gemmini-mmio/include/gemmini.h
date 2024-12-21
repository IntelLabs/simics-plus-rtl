#ifndef GEMMINI_H_MMIO_WRAPPER
#define GEMMINI_H_MMIO_WRAPPER

#define EXPOSE_TOP_LEVEL_FNS

#include "../gemmini-rocc-tests/include/gemmini.h"

#include "include/gemmini_mmio.h"

#undef gemmini_fence
#define gemmini_fence() {}
#undef gemmini_counter_access
#define gemmini_counter_ccess(a, b) {}

#endif
