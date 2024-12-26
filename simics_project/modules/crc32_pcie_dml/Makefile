# -*- Makefile -*-

# © 2016 Intel Corporation
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

SIMICS_API := latest
THREAD_SAFE:=yes
MODULE_CLASSES = crc32_pcie_dml
MODULE_COMPONENTS = crc32_pcie_dml_comp
SRC_FILES= crc32_pcie_dml.dml
PYTHON_FILES := module_load.py

EXTRA_MODULE_VPATH += dml-lib
EXTRA_MODULE_VPATH += rtl-crc32-device

# COMPILE time settings. Tell the compiler where to find
# the headers and tell the linker where to find the library
# pass path to external lib and lib name to compiler/linker
EXTERNAL_LIB_BASE_NAME = accel_rtl_crc32
EXTERNAL_LIB_LOC_BUILD = ../../../../..
EXTERNAL_LIB_LOC_RUN = ../../../..
MODULE_CFLAGS  += -I$(EXTERNAL_LIB_LOC_BUILD)
MODULE_LDFLAGS += -L$(EXTERNAL_LIB_LOC_BUILD)/lib
# MODULE_LDFLAGS += -Wl,-rpath,'$(EXTERNAL_LIB_LOC_RUN)/lib'
# LIBS += -l$(EXTERNAL_LIB_BASE_NAME)

include $(MODULE_MAKEFILE)
