# © 2012 Intel Corporation
#
# This software and the related documents are Intel copyrighted materials, and
# your use of them is governed by the express license under which they were
# provided to you ("License"). Unless the License provides otherwise, you may
# not use, modify, copy, publish, distribute, disclose or transmit this software
# or the related documents without Intel's prior written permission.
#
# This software and the related documents are provided as is, with no express or
# implied warranties, other than those that are expressly stated in the License.


# Tests for the sample CRC32 DML device.
import zlib
import random
import simics
import stest
import dev_util as du
from simics import SIM_create_object

conf.sim.deprecations_as_errors = False

def create_regs(device):
    class regs:
        class f5:
            pass

    regs.bar0 = du.Register_LE((device, 255, 0x10), size = 4)
    regs.crc32_ctrl_reg = du.Register_LE(device.bank.regs, 0x0, 8, du.Bitfield({'SIZE': (15, 0)}))
    regs.crc32_src_reg = du.Register_LE(device.bank.regs, 0x8, 8)
    regs.crc32_dst_reg = du.Register_LE(device.bank.regs, 0x10, 8)
    return regs

# Test the PCI vendor and device IDs
def test_ids():
    stest.expect_equal(mycrc32.attr.pci_config_vendor_id, 0x8086, "Bad vendor ID")
    stest.expect_equal(mycrc32.attr.pci_config_device_id, 0xCC32, "Bad device ID")

def test_op(mem, regs, in_data):
    read_address = 0x1000
    write_address = 0x1200
    pad = (4 - len(in_data) % 4) % 4
    # mem.write wants data as a tuple. (always a multiple of 4)
    list_data = list(ord(c) for c in in_data) + [0]*pad
    test_data = tuple(list_data)
    test_words = len(test_data) // 4
    print("Data is: ", test_data)
    mem.write(None, read_address, test_data, 0)
    mem.write(None, write_address, (0,0,0,0), 0)
    # kick off the CRC32 computation
    regs.crc32_src_reg.write(read_address)
    regs.crc32_dst_reg.write(write_address)
    regs.crc32_ctrl_reg.write(SIZE = len(in_data))
    # ensure the result is correct
    stest.expect_equal(regs.crc32_ctrl_reg.SIZE, 0) # task is done
    out_data = mem.read(None, write_address, 4, 0)
    act = int.from_bytes(out_data, 'little')
    exp = zlib.crc32(str.encode(in_data)) & 0xffffffff
    stest.expect_equal(act, exp, "CRC32 result is incorrect")
    print("Obtained expected result:", hex(act))

SIM_run_command("log-level 4")

# Set up a PCI bus and a sample PCI device
pci_bridge = du.Dev([du.PciBridge])  # Non-used PCI bridge, required by bus
pci_conf = SIM_create_object('memory-space', 'pci_conf')
pci_io = SIM_create_object('memory-space', 'pci_io')
pci_mem = SIM_create_object('memory-space', 'pci_mem')
mem_image = simics.SIM_create_object('image', 'mem_image', [['size', 1 << 10]])
dma_ram = simics.SIM_create_object('ram', 'dma_ram', [['image', mem_image]])
pci_mem.map = [[0x1000, dma_ram, 0, 0, mem_image.size]]

pci_bus = SIM_create_object('pci-bus', 'pci_bus', [['conf_space', pci_conf],
                                                   ['io_space', pci_io],
                                                   ['memory_space', pci_mem],
                                                   ['bridge', pci_bridge.obj]])
mycrc32 = SIM_create_object('crc32_pcie_dml', 'mycrc32', [['pci_bus', pci_bus]])
regs = create_regs(mycrc32)
bank_regs = du.bank_regs(mycrc32.bank.pci_config)
cmd_reg = bank_regs.command
bar_reg = bank_regs.base_address_0

addr = 0x100
cmd_reg.write(2)     # Enable memory access
bar_reg.write(addr)  # Map bank at addr
print(pci_mem.attr.map)
stest.expect_equal(pci_mem.attr.map[0][1], mycrc32.bank.regs,
                    "PCI device should have been mapped")

test_ids()

for i in range(100):
    test_op(pci_mem.iface.memory_space, regs, ''.join(random.choices(string.ascii_lowercase + string.ascii_uppercase + string.digits, k=random.randint(2, 100))))
print("Test passed")

# Test setting BAR to map the device in memory
#test_mapping(regs, 0x100, 0x4711, pci_bus.io, pci_bus.mem, sample_pci)

# Test interface
#test_interface(sample_pci, sample_pci)

# Test DMA/memory access
#test_dma(pci_bus.mem, sample_pci)

print("All tests passed.")
