# -*- Makefile ; coding: utf-8 -*-

# © 2010 Intel Corporation

#
# See Simics Model Builder User's Guide for more details on what to put here.
#

MODULE_CLASSES = tl_pcie_device
MODULE_COMPONENTS = tl_pcie_dml_comp
SRC_FILES = tl_pcie_device.dml
PYTHON_FILES = module_load.py

EXTRA_MODULE_VPATH += dml-lib

SIMICS_API := 6
THREAD_SAFE := yes

ifeq ($(MODULE_MAKEFILE),)
$(error Make sure you compile your module from the project directory)
else
include $(MODULE_MAKEFILE)
endif

# COMPILE time settings. Tell the compiler where to find
# the headers and tell the linker where to find the library
# pass path to external lib and lib name to compiler/linker
EXTERNAL_LIB_BASE_NAME = simics_rtl_gemminitestharness
EXTERNAL_LIB_LOC_BUILD = $(PWD)/..
EXTERNAL_LIB_LOC_RUN = $(PWD)/..
$(info $(PWD))
MODULE_CFLAGS  += -I$(EXTERNAL_LIB_LOC_BUILD)
MODULE_LDFLAGS += -L$(EXTERNAL_LIB_LOC_BUILD)/lib
MODULE_LDFLAGS += -Wl,-rpath,'$(EXTERNAL_LIB_LOC_RUN)/lib'
LIBS += -l$(EXTERNAL_LIB_BASE_NAME)