# © 2010 Intel Corporation
#
# This software and the related documents are Intel copyrighted materials, and
# your use of them is governed by the express license under which they were
# provided to you ("License"). Unless the License provides otherwise, you may
# not use, modify, copy, publish, distribute, disclose or transmit this software
# or the related documents without Intel's prior written permission.
#
# This software and the related documents are provided as is, with no express or
# implied warranties, other than those that are expressly stated in the License.


import cli
import pci_common
import simics
from comp import StandardConnectorComponent, PciBusUpConnector, SimpleConfigAttribute

device_class_name = "crc32_pcie_dml"

from cli import new_info_command, new_status_command

def info(obj):
    return [(None,
             [("Memory Space", obj.attr.target_mem_space)])]

def status(obj):
    return [ (None,
              [("DMA source addr", "0x%x" % obj.attr.regs_source),
               ("DMA dest addr", "0x%x" % obj.attr.regs_dest),
               ("DMA control addr", "0x%x" % obj.attr.regs_control)])]

new_info_command("crc32_pcie_dml", info)
new_status_command("crc32_pcie_dml", status)

class crc32_pcie_dml_comp(StandardConnectorComponent):
    """PCIe CRC32 accelerator component"""
    _class_desc = "PCIe CRC32 accelerator component"

    def setup(self):
        super().setup()
        if not self.instantiated.val:
            self.add_objects()
        self.add_connector('pci', PciBusUpConnector(0, 'mycrc32_dev', hotpluggable = True, required = True))

    def add_objects(self):
        mycrc32_dev = self.add_pre_obj('mycrc32_dev', 'crc32_pcie_dml')

crc32_pcie_dml_comp.register()
