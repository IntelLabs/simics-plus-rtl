# -*- Makefile -*-

# © 2017 Intel Corporation
#
# This software and the related documents are Intel copyrighted materials, and
# your use of them is governed by the express license under which they were
# provided to you ("License"). Unless the License provides otherwise, you may
# not use, modify, copy, publish, distribute, disclose or transmit this software
# or the related documents without Intel's prior written permission.
#
# This software and the related documents are provided as is, with no express or
# implied warranties, other than those that are expressly stated in the License.

# Simics module makefile

MODULE_CLASSES = sample_tlm2_gasket_device \

SRC_FILES = gasket-device.cc simics-init.cc VCrc32__ALL.cpp
PYTHON_FILES = module_load.py utility.py
EXTRA_MODULE_VPATH = systemc-commands

CXXFLAGS += -I/home/awmoore/pta/simics-plus-rtl/build/verilator_sc
CXXFLAGS += -I/usr/share/verilator/include
LDFLAGS += /home/awmoore/pta/simics-plus-rtl/build/verilator_sc/VCrc32__ALL.a

# Simics compilation options
SIMICS_API := latest
THREAD_SAFE = yes
SYSTEMC = yes
USE_SIMICS_CHECKPOINTING=no

# Prefer Visual Studio on Windows
COMPILERS = cl gcc

include $(MODULE_MAKEFILE)
