# © 2010 Intel Corporation

import cli
import pci_common
import simics
from pprint import pprint

from comp import StandardConnectorComponent, StandardConnector, PciBusUpConnector, SimpleConfigAttribute
from cli import new_info_command, new_status_command

class_name = 'tl_pcie_device'

#
# ------------------------ info -----------------------
#

def get_info(obj):
    # USER-TODO: Return something useful here
    return [(None, [("VM Translator", obj.attr.vm_translator)])]

cli.new_info_command(class_name, get_info)

#
# ------------------------ status -----------------------
#

def get_status(obj):
    # USER-TODO: Return something useful here
    return []

cli.new_status_command(class_name, get_status)

class VmUpConnector(StandardConnector):
    def __init__(self, device, required = False):
        self.device = device
        self.type = "processor-info-v2"
        self.hotpluggable = False
        self.required = required
        self.multi = False
        self.direction = simics.Sim_Connector_Direction_Up

class tl_pcie_dml_comp(StandardConnectorComponent):
    """Tilelink-PCIe component"""
    _class_desc = "Tilelink-PCIe component"

    def setup(self):
        super().setup()
        if not self.instantiated.val:
            self.add_objects()
        self.add_connector('upstream_target', PciBusUpConnector(0, 'tl_dev', hotpluggable = True, required = True))
        # self.add_connector("vm_translator", VmUpConnector("tl_dev", required = True))

    def add_objects(self):
        # pprint(vars(self))
        # pprint(self.top_component.__dict__)
        tl_dev = self.add_pre_obj('tl_dev', 'tl_pcie_device')

tl_pcie_dml_comp.register()
