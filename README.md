# Simics-Gemmini

## 1. Set up Conda

Follow instructions in https://github.com/conda-forge/miniforge/releases

## 2. Set up Chipyard

Clone and run the setup script for chipyard, which will install relevant conda packages and clone chipyard submodules. The chipyard conda environment handles firtool as well as the RISCV toolchain, including gcc, gdb and binutils.

There is one single dependency before the setup script can be run.
```
conda install -n base conda-lock
```
Optionally, installing `fd` will speed up chipyard compilation times.

The repository is based on the 1.11.0 release, with small changes to Gemmini and the build system. At the root direcotry,
```
git clone https://github.com/ucb-bar/chipyard
cd chipyard
git checkout 1.11.0
./build-setup.sh --use-lean-conda -ud
```
Check that the submodules in `chipyard/generators` are not empty directories, and `$RISCV` is set when conda is activated.

## 3. Set up Simics

1. Install the [Simics Public Release](https://www.intel.com/content/www/us/en/developer/articles/tool/simics-simulator.html). The instructions here assume Release Version `2024.41`. Note the location of the simics-public directory. For instance, it might be at: `~/simics-public/`.

2. To run the Simics GUI and compile the RTL harness device, the following packages are required, either in a container, in conda, or installed through a system package manager.
```
curl make openjdk-21-jdk g++ libgtk2.0-0 libxpm4 libxxf86vm1 verilator
```

For Fedora or other Red Hat based systems, the package list is:
```
curl make openjdk-21-jdk g++ gtk2 libXpm libXxf86vm verilator-devel
```

3. Before running any compilations, the environment variable `SIMICS_BASE` must point to the simics installation directory, e.g.
```
export SIMICS_BASE=$(realpath ~/simics-public/simics-7.21.0)
```

## 4. Compiling RTL and the harness

1. First, some files in Chipyard must be patched to add the new RTL wrapper. This should be done automatically through the setup script `setup.sh`. At the root directory,
```
./setup.sh
```
Check that `chipyard/generators/simics-chipyard` is a valid link, and so is `chipyard/generators/gemmini/software/gemmini-mmio/`. For newer chipyard releases, the patch files might be outdated; you may have to manually apply the patches in `patches/`. This only has to be done once after cloning/pulling from remote.

The chipyard release does not contain an up-to-date version of Gemmini. As a temporary fix, go to `chipyard/generators/gemmini/` and do
```
git fetch
git checkout dma_read_ready
git submodule update --init --recursive software/gemmini-rocc-tests
```

2. Under the root directory of this project run:
```
conda activate `realpath chipyard/.conda-env`
export VERILATOR_INC_DIR=`realpath chipyard/.conda-env/share/verilator/include`
make clean
make
```
This will compile the RTL design at `chipyard/sims/verilator/generated-src/`, and link with the harness, producing `lib/libsimics_rtl_gemminitestharness.so`. If the compilation doesn't work, it might help to isolate the RTL compilation by doing
```
make clean
make chipyard
```

## 5. Compiling the DML device

1. A Simics project needs to be set up for the first time. To do this, at the root directory run the following, and reply with "y" to any questions:
```
$SIMICS_BASE/bin/project-setup --ignore-existing-files simics-project
cd simics-project
./bin/addon-manager -C
./bin/addon-manager -s $SIMICS_BASE/../simics-qsp-x86-7.15.0/
./bin/addon-manager -s $SIMICS_BASE/../simics-qsp-cpu-7.4.0/
```

2. Build the DML device under `simics-project/` by running
```
make
```
This generates `simics-project/linux64/lib/tl_pcie_device.so`. Check that the `ldd` output of this file shows that `libsimics_rtl_gemminitestharness.so` pointing to the library compiled in the previous step.


## 6. Set up guest system in Simics

We will now boot an operating system using Simics. We can use a recent Linux Live CD to boot, one choice might be [ArchLinux](https://archlinux.org/download/). In the following, we assume you have downloaded `archlinux.iso` to the `simics-project/` directory, using the Mirror List provided.

1. Convert the Live CD ISO file into the CRAFF disk format:
```
./bin/craff -o os.craff archlinux.iso
```

2. Boot Simics:
```
./simics qsp-clearlinux-pcie-gemmini.simics disk0_image=os.craff iso_image=$SIMICS_BASE/targets/common/images/simics_agent_binaries.iso`.
```
Type `c` for continue in the Simics command prompt to start execution. If no GUI windows show up, check the dependencies in section 3 are installed.

The OS takes a few minutes to boot up; there might be warnings about MSR registers in the Simics command line output, they are usually harmless. After booting up, the VGA graphics console should show a shell session as root. If network problems cause messages with "Refresh Pacman mirrorlist with Reflector" to appear periodically, disable it with: `# systemctl stop reflector`.

### Notes:

If Simics performs slowly, consider installing the VMP kernel according to Simics documentation (mostly involving running `./bin/vmp-kernel-install`). This may not be an option in a virtualized host system.

If Simics performs VERY slowly, consider disabling the guest networking in the `.simics` file by changing `connect_real_network` from `"napt"` to `"no"`. Note that this disables Internet access in the guest. Usually, this can be avoided by correctly configuring proxy settings and DNS resolution settings in the host.

## 7. Deploying workloads

1. First check that the PCIe device appears in the guest:
```
# lspci -d 8086:9e33 -v
```
If the device does not exist, check for error logs when Simics is launched; device loading might have failed. This could be due to Simics's inability to locate the library, in which case pointing `LD_LIBRARY_PATH` to the enclosing directory may fix the issue.

2. Compile & install the Gemmini hardware library. From the root directory on the host system:
```
cd gemmini-mmio
make lib
```
By default, the Makefile tries to use musl-gcc to compile a fully static library including libc for full portability. This will require installing the musl GCC wrapper, available in package managers (e.g. `musl-tools` on apt). To override this behavior, pass `USE_MUSL=0` to the `make` command. If the static linking does not work, either ensure compatible libc on the Simics guest for binary compatibility, switch to a distro where musl-gcc does work (such as Ubuntu), or set up the build environment directly in the Simics guest.

`gemmini-mmio/lib/libgemmini.so` is the hardware library. The built Gemmini unit tests which depend on the library can be found in `gemmini-mmio/build`.

2. Transfer the workload files. You can do this either through the Simics agent manager, or over the network using `scp`/`rsync` if you have networking correctly set up in the guest. To use the Simics agent, run in the guest:
```
# mount /dev/sr0 /root/media --mkdir
# /root/media/simics_agent_x86_linux64 &
```
and run in the Simics command prompt:
```
simics> start-agent-manager
simics> agent_manager.connect-to-agent
simics> matic0.upload-dir ../gemmini-mmio
```

3. Run the tests on the Simics target machine. 
```
# cd /gemmini-mmio
# chmod +x template-linux
# chmod +x tiled_matmul_ws-linux
# ./template-linux
# ./tiled_matmul_ws-linux
```
The final two commands will run the workload leveraging the gemmini RTL via `/gemmini-mmio/lib/libgemmini.so`. The cycles reported will be incorrect since they rely on a RISC-V assembly instruction. However, the Simics console should show printouts which report the RTL cycles taken as well as the simulation time/speed.

## 8. View waveforms

If the hardware is configured to dump waveforms, it will appear in `simics-project/`. To enable waveform dumping, modify `simics-chipyard/src/main/scala/GemminiTestHarness.scala` and change `case DumpWaveform => false` to `case DumpWaveform => true`. `make clean` and `make` again under the root directory to recompile the RTL harness library.
