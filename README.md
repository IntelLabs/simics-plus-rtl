## Overview

This repository contains collateral for a [Chisel](https://www.chisel-lang.org/)-based RTL accelerator which is connected to a functional PCI bus using [Simics](https://www.intel.com/content/www/us/en/developer/articles/tool/simics-simulator.html). This accelerator carries out a simple operation: [CRC32](https://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks#CRC-32_algorithm) calculation on the input bytes. User software running above an OS on the CPU can leverage the PCI accelerator for CRC32 computation.

The following 3 ingredients are located within this repository:

1. Chisel source code and associated C++ harness.
2. Simics device/component and unit tests.
3. Target test code.

## Installation

### Build a container with Apptainer

Install Apptainer on a machine where you have root access. Follow the instructions [here](https://apptainer.org/docs/admin/main/installation.html#install-from-pre-built-packages). Also install [Singularity Python](https://singularityhub.github.io/singularity-cli/) which will help convert Docker recipes into Singularity recipes.

1. `cd docker`
2. `spython recipe Dockerfile &> Singularity.def`
3. `sudo -E apptainer build simicsplusrtl.sif Singularity.def`

The generated sif file should be around 1 GB in size, and can now be moved to a different machine and run even without root access.

You may also use Docker, podman, or simply install packages on your local machines according to the recipe provided in `docker/Dockerfile`.

### Install the Simics Public Release

1. Install the [Simics Public Release](https://www.intel.com/content/www/us/en/developer/articles/tool/simics-simulator.html).
2. The instructions here assume Release Version `2024.41`.
3. Note the location of the simics-public directory. For instance, it might be at: `~/simics-public/`. In the subsequent instructions, we will assume it is located at `/path/to/simics-public/`, please substitute your location accordingly.

## Start the container

1. Change to *this* directory (ie. top-level within this git repository).
2. Drop into an interactive shell within the container. By default, Apptainer does not allow writes to the image. To work around this limitation, we are mounting a host directory as `/mnt` within the container and changing the home directory to `/tmp/user`. Since file modifications will be confined to these two directories, no write errors are encountered. Mount this repository and the Simics installation directory:
    - `apptainer shell --fakeroot -B ./:/run -B ./:/root -B ./:/mnt -B /path/to/simics-public/:/simics -H /tmp/user docker/simicsplusrtl.sif`
3. Subsequent steps involve executing commands in this shell - so keep it open. They will be prefixed with the `Apptainer> ` prompt for clarity.

## Chisel source code and associated C++ harness

In this step, we will generate Verilog code from the Chisel source, verilate it into C++, and combine it with the harness to build a shared library at `/mnt/lib/libaccel_rtl_crc32.so`

1. `Apptainer> cd /mnt`
2. `Apptainer> make clean`
3. `Apptainer> export SIMICS_BASE=/simics/simics-7.21.0`
4. `Apptainer> make`
5. `Apptainer> export LD_LIBRARY_PATH=/mnt/lib:$LD_LIBRARY_PATH`

## Simics device/component and unit tests

The Simics device and component instantiate the shared library built in the section above and interface with it to provide the required CRC32 functionality. The DML code for the device, and Python code for the component, together provide the required PCI infrastructure for instantiating it within a system. By relying on several utility templates and interfaces provided by Simics, the boilerplate can be minimized signifantly.

1. `Apptainer> cd /mnt`
2. `Apptainer> $SIMICS_BASE/bin/project-setup --ignore-existing-files simics_project`
3. `Apptainer> cd simics_project`
4. `Apptainer> make clean`
5. `Apptainer> make test`

## Simics QSP enabling

We will now enable the required Quick Start Platform (QSP) packages with this Simics project so we can have a full-fledged system.

1. `Apptainer> cd /mnt/simics_project`
2. `Apptainer> ./bin/addon-manager -C`
3. `Apptainer> ./bin/addon-manager -s /simics/simics-qsp-x86-7.15.0/`
4. `Apptainer> ./bin/addon-manager -s /simics/simics-qsp-cpu-7.4.0/`

## Target test code

We will now boot an operating system using Simics. We can use a recent Linux Live CD to boot, one choice might be [ArchLinux](https://archlinux.org/download/). In the following, we assume you have downloaded `archlinux-2024.12.01-x86_64.iso` to the `/mnt/simics_project` directory, using the Mirror List provided.

Note that while we will start Simics from the container (`Apptainer> `), we will also enter commands directly into Simics (`simics> `), and eventually interact with the OS directly (`# `).

1. `Apptainer> cd /mnt/simics_project`
2. `Apptainer> ./bin/craff -o os.craff archlinux-2024.12.01-x86_64.iso`
3. `Apptainer> ./simics qsp-clearlinux-pci-crc32.simics disk0_image=os.craff iso_image=$SIMICS_BASE/targets/common/images/simics_agent_binaries.iso`
4. `simics> c`
5. Wait a few minutes until the OS logs in, follow the progress in the window with title: "machine.mb.gpu.vga - graphics console".After the OS has logged you in as root, you can interact with the machine as you normally would on this OS. 
6. If network problems cause messages with "Refresh Pacman mirrorlist with Reflector" to appear periodically, disable it with:
    - `# systemctl stop reflector`
7. Ensure the PCI device has been enumerated and can be seen by the OS. Note the memory address (assumed to be 0x800001000 in the following).
    - `# lspci -d 8086:cc32 -v`
8. Start the Simics Agent so we can easily send files between the host and target systems
    - `# mkdir /root/media`
    - `# mount /dev/sr0 /root/media`
    - `# /root/media/simics_agent_x86_linux64 &`
    - `simics> start-agent-manager`
    - `simics> agent_manager.connect-to-agent`
9. Now let's interact with our accelerator! Use the memory address mapped for the device that we obtained above as the 1st argument to the Python script. This script will self-check against a Python implementation of CRC32. You should see "PASS" printed out if everything works correctly. Try with other 8 byte hex data as the 2nd argument to test more thoroughly.
    - `simics> matic0.upload calc_crc32.py /root`
    - `# python3 /root/calc_crc32.py 0x800001000 0xabababababababab`
