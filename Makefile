CHISEL_TOP_NAME = Crc32
CHISEL_TOP_PACKAGE = accel
BUILD_NAME = build
OBJ = obj
chisel_target_name = $(CHISEL_TOP_PACKAGE).$(CHISEL_TOP_NAME)
verilator_build_dir = $(BUILD_NAME)/verilator
chisel_build_dir = $(BUILD_NAME)/chisel
# Build shared library
LOWER_CHISEL_TOP_NAME= $(shell echo $(CHISEL_TOP_NAME) | tr '[:upper:]' '[:lower:]')
LOWER_CHISEL_TOP_PACKAGE= $(shell echo $(CHISEL_TOP_PACKAGE) | tr '[:upper:]' '[:lower:]')
APPNAME = $(LOWER_CHISEL_TOP_PACKAGE)_rtl_$(LOWER_CHISEL_TOP_NAME)
LIBNAME = lib$(APPNAME)
SHARED_LIB = lib/$(LIBNAME).so

# Generate a vcd trace during simulation
USE_TRACE = 1
# Easier debugging with gdb
DEBUG = 1
# track coverage of Verilated code
USE_COVERAGE = 0

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

# includes
INCLUDES += -I/usr/include/
INCLUDES += -I./
INCLUDES += -I${verilator_build_dir}
INCLUDES += -isystem${VERILATOR_INC_DIR}/vltstd -isystem${VERILATOR_INC_DIR}
INCLUDES += -isystem/$(SIMICS_BASE)/src/devices/c++-api -DDISABLE_WARNING_ON_TECH_PREVIEW
INCLUDES += -isystem/$(SIMICS_BASE)/src/include
INCLUDES += -isystem/$(SIMICS_BASE)/linux64/api/7

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
verilator_opt += +define+RANDOMIZE_GARBAGE_ASSIGN
verilator_opt += +define+RANDOMIZE_REG_INIT
verilator_opt += +define+RANDOMIZE_MEM_INIT
verilator_opt += --x-assign unique
verilator_opt += --assert
verilator_opt += -Mdir ${verilator_build_dir}
verilator_opt += -I$(chisel_build_dir)
verilator_opt += -Wno-WIDTH
verilator_opt += -CFLAGS -fPIC

verilated_objs = $(verilator_build_dir)/verilated.o $(verilator_build_dir)/verilated_threads.o

ifeq ($(DEBUG), 1)
verilator_opt += -CFLAGS -DVL_DEBUG -CFLAGS -ggdb
LDFLAGS += -ggdb
endif

ifneq ($(USE_TRACE), 0)
verilator_cxx_flags += -DVM_TRACE=1
verilator_opt += --trace
verilated_objs += $(verilator_build_dir)/verilated_vcd_c.o
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

$(chisel_build_dir)/filelist.f: $(shell find src/main -type f)
	sbt 'runMain $(chisel_target_name) --target-dir $(chisel_build_dir)'

$(verilator_build_dir)/V%__ALL.a: $(chisel_build_dir)/filelist.f
	verilator --build --top-module $* $(verilator_opt) -f $<

$(verilator_build_dir)/%.o: $(VERILATOR_INC_DIR)/%.cpp
	$(CXX) -fPIC $(verilator_cxx_flags) -c $< -o $@

$(OBJ)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $*.cpp

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
