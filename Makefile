CHISEL_TOP_NAME = GemminiTestHarness
CHISEL_TOP_PACKAGE = simics
BUILD_NAME = build
OBJ = $(BUILD_NAME)/obj

# Generate a vcd trace during simulation
USE_TRACE = 1
# Easier debugging with gdb
DEBUG = 1
# track coverage of Verilated code
USE_COVERAGE = 0

CHIPYARD_DIR = $(PWD)/chipyard
CHIPYARD_SUB_PROJECT ?= simics-gemmini
CHIPYARD_CONFIG ?= SimicsGemminiConfig
CHIPYARD_CONFIG_LONG_NAME ?= $(CHISEL_TOP_PACKAGE).$(CHISEL_TOP_NAME).$(CHIPYARD_CONFIG)

chipyard_verilator_dir = $(CHIPYARD_DIR)/sims/verilator
verilator_build_dir = $(chipyard_verilator_dir)/generated-src/$(CHIPYARD_CONFIG_LONG_NAME)/$(CHIPYARD_CONFIG_LONG_NAME).debug

# Build shared library
LOWER_CHISEL_TOP_NAME= $(shell echo $(CHISEL_TOP_NAME) | tr '[:upper:]' '[:lower:]')
LOWER_CHISEL_TOP_PACKAGE= $(shell echo $(CHISEL_TOP_PACKAGE) | tr '[:upper:]' '[:lower:]')
APPNAME = $(LOWER_CHISEL_TOP_PACKAGE)_rtl_$(LOWER_CHISEL_TOP_NAME)
LIBNAME = lib$(APPNAME)
SHARED_LIB = lib/$(LIBNAME).so

CXX     = g++
NPROCS :=$(shell grep -c ^processor /proc/cpuinfo)

# flags
DEFINES    = -DUSE_TRACE=$(USE_TRACE)
WARNINGS   = -Wall -Wextra -Werror
OPTFLAG = -O3 -g -rdynamic -ffloat-store ${GCC_XOPT_FLAGS}
LDFLAGS = -g -rdynamic -ldl
BASEDIR = $(shell pwd)

# Change VERILATOR_INC_DIR if Verilator is installed on a different location
ifeq (, $(VERILATOR_INC_DIR))
    ifeq (, $(wildcard /usr/local/share/verilator/include/*))
        ifeq (, $(wildcard /usr/share/verilator/include/*))
            $(error "Verilator include directory is not set properly")
        else
            VERILATOR_INC_DIR := /usr/share/verilator/include
        endif
    else
            VERILATOR_INC_DIR := /usr/local/share/verilator/include
    endif
endif

ifeq (, $(SIMICS_BASE))
    $(error SIMICS_BASE is not defined)
endif

# includes
INCLUDES += -I./
INCLUDES += -Isimics-project/modules/tl_pcie_device/
INCLUDES += -I${verilator_build_dir}
INCLUDES += -isystem${VERILATOR_INC_DIR}/vltstd -isystem${VERILATOR_INC_DIR}
INCLUDES += -isystem/$(SIMICS_BASE)/src/devices/c++-api -DDISABLE_WARNING_ON_TECH_PREVIEW
INCLUDES += -isystem/$(SIMICS_BASE)/src/include
INCLUDES += -isystem/$(SIMICS_BASE)/linux64/api/6/v2

CXXFLAGS = -faligned-new
LIB_OBJECTS = $(OBJ)/harness_${CHISEL_TOP_PACKAGE}_${CHISEL_TOP_NAME}.o

ifeq ($(USE_COVERAGE), 1)
DEFINES += -DUSE_COVERAGE=1
#LIB_OBJECTS += $(OBJ)/verilated_cov.o
CXXFLAGS += -fprofile-arcs -ftest-coverage
LDFLAGS += -fprofile-arcs
endif

# a collection of all compiler flags
CXXFLAGS += $(OPTFLAG) $(WARNINGS) $(DEFINES) $(INCLUDES)
CXXFLAGS += -fPIC -std=c++17

ifeq ($(DEBUG), 0)
verilator_cxx_flags = -O2 -Wall
else
verilator_cxx_flags = -O0 -g -Wall
endif

verilator_cxx_flags += -faligned-new -Wno-sign-compare
verilator_cxx_flags += -isystem$(VERILATOR_INC_DIR)
verilator_cxx_flags += -isystem$(VERILATOR_INC_DIR)/vltstd

verilator_opt = --cc
# verilator_opt += +define+RANDOMIZE_GARBAGE_ASSIGN
# verilator_opt += +define+RANDOMIZE_REG_INIT
# verilator_opt += +define+RANDOMIZE_MEM_INIT
# verilator_opt += --x-assign unique
# verilator_opt += --assert
# verilator_opt += -Mdir ${verilator_build_dir}
verilator_opt += -Wno-WIDTH -Wno-REDEFMACRO
# verilator_opt += -CFLAGS -fPIC

verilated_objs = $(verilator_build_dir)/verilated.o $(verilator_build_dir)/verilated_threads.o

# ifeq ($(DEBUG), 1)
# verilator_opt += -CFLAGS -DVL_DEBUG -CFLAGS -ggdb
# LDFLAGS += -ggdb
# endif

ifneq ($(USE_TRACE), 0)
verilator_cxx_flags += -DVM_TRACE=1
verilator_opt += --trace-fst
verilated_objs += $(verilator_build_dir)/verilated_fst_c.o
else
verilator_cxx_flags += -DVM_TRACE=0
endif

ifeq ($(USE_COVERAGE), 1)
verilator_opt += --coverage
verilated_objs += $(verilator_build_dir)/verilated_cov.o
endif

# build a library by default
default: shared

lib_path = $(verilator_build_dir)/V$(CHISEL_TOP_NAME)__ALL.a

FORCE: ;

chipyard: FORCE
	make -C $(chipyard_verilator_dir) -j20 EXTRA_SIM_CXXFLAGS="-fPIC" VERILATOR="verilator $(verilator_opt)" TIMESCALE_OPTS="" SUB_PROJECT=$(CHIPYARD_SUB_PROJECT) verilog
	make -C $(chipyard_verilator_dir) -j20 EXTRA_SIM_CXXFLAGS="-fPIC" VERILATOR="verilator $(verilator_opt)" TIMESCALE_OPTS="" SUB_PROJECT=$(CHIPYARD_SUB_PROJECT) debug 2>&1 | awk -v p="%Error" '$$0 ~ p {found=1} {print} END {exit found}'

$(verilator_build_dir)/%.o: chipyard FORCE;
$(lib_path): $(verilator_objs)

$(OBJ)/%.o: chipyard src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

init:
	@mkdir -p $(BASEDIR)/lib
	@mkdir -p $(BASEDIR)/$(OBJ)
	@mkdir -p $(BASEDIR)/$(BUILD_NAME)

shared: init $(lib_path) $(verilated_objs) $(LIB_OBJECTS)
	$(CXX) $(LDFLAGS) -shared -o $(SHARED_LIB) $(LIB_OBJECTS) $(lib_path) $(verilated_objs)

clean:
	rm -rf $(BASEDIR)/target $(BASEDIR)/project $(BASEDIR)/test_run_dir
	rm -rf $(BASEDIR)/$(BUILD_NAME)
	rm -rf $(BASEDIR)/$(OBJ)
	rm -rf $(BASEDIR)/lib
	make -C $(chipyard_verilator_dir) clean

clean_chipyard:
	make -C $(chipyard_verilator_dir) clean
