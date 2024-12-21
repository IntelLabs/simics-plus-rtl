#!/usr/bin/env bash

echo "NOTE: the patches used in this script are for Chipyard 1.11.0. Manually inspect patched files for newer releases."

# set up new chipyard module
cd chipyard
git apply ../patches/variables.mk.patch
git apply ../patches/build.sbt.patch
cd generators
ln -s ../../simics-chipyard ./

# set up gemmini MMIO wrapper
cd gemmini/software
ln -s ../../../../gemmini-mmio ./

echo "Done"
