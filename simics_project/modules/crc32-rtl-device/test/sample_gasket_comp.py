# © 2017 Intel Corporation
#
# This software and the related documents are Intel copyrighted materials, and
# your use of them is governed by the express license under which they were
# provided to you ("License"). Unless the License provides otherwise, you may
# not use, modify, copy, publish, distribute, disclose or transmit this software
# or the related documents without Intel's prior written permission.
#
# This software and the related documents are provided as is, with no express or
# implied warranties, other than those that are expressly stated in the License.

import dev_util as du
import stest
from comp import *

class mysnoop(pyobj.ConfObject):
    class snoop_memory(pyobj.Interface):
        def operation(self, a,b,c):
            print("operation called ")
            print(a)
            print(b)
            print(c)
            return 0

class fake_signal_target:
    cls = simics.confclass('fake-signal-target')
    cls.attr.state('b', default=False)

    @cls.iface.signal.signal_raise
    def signal_raise(self):
        stest.expect_false(self.state, "signal raised when already high")
        self.state = True

    @cls.iface.signal.signal_lower
    def signal_lower(self):
        stest.expect_true(self.state, "signal lowered when already low")
        self.state = False

class sample_gasket_comp(StandardConnectorComponent):
    """Sample Gasket component class."""
    _class_desc = "sample Gasket component"
    _help_categories = ()

    def setup(self):
        super().setup()
        if not self.instantiated.val:
            self.add_objects()

    def add_objects(self):
        gasket_list = []
        simulation = self.add_pre_obj('simulation', 'sample_tlm2_gasket_device')

        for sig in ["reset"]:
            signal_in = self.add_pre_obj(f'signal_in_{sig}',
                                        'sample_tlm2_gasket_device_gasket_simics2systemc_Signal')
            signal_in.signal = f'top.{sig}'
            signal_in.simulation = simulation
            gasket_list += [signal_in]

        for sig in ["io_busy"]:
            signal_object = self.add_pre_obj(f'signal_object_{sig}', 'fake-signal-target')
            signal_out = self.add_pre_obj(f'signal_out_{sig}',
                                        'sample_tlm2_gasket_device_gasket_systemc2simics_Signal')
            signal_out.signal = f'top.{sig}'
            signal_out.object = signal_object
            signal_out.simulation = simulation
            gasket_list += [signal_out]

        
        dma_image = self.add_pre_obj('dma_image', 'image')
        dma_image.size = 0x3001
        dma_ram = self.add_pre_obj('dma_ram', 'ram')
        dma_ram.image = dma_image
        dma_space = self.add_pre_obj('dma_space', 'memory-space')
        dma_space.map = [[0x0, dma_ram, 0, 0, dma_image.size]]

        simulation.phys_mem = dma_space 

        snp = self.add_pre_obj("mysnoop", "mysnoop")
        # dma_space.snoop_device = snp

        simulation.gasket_list = gasket_list

def create_sample_gasket_comp():
    simics.SIM_run_command("create-sample-gasket-comp")
    simics.SIM_run_command("instantiate-components")
