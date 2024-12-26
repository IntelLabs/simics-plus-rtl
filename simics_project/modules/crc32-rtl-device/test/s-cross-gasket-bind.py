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


import stest
from comp import *

class sample_cross_gasket_comp(StandardConnectorComponent):
    """Sample cross gasket component class."""
    _class_desc = "sample cross gasket component"
    _help_categories = ()

    def setup(self):
        super().setup()
        if not self.instantiated.val:
            self.add_objects()

    def add_objects(self):
        simulation = self.add_pre_obj('simulation', 'sample_tlm2_gasket_device')
        gasket = self.add_pre_obj('gasket', 'sample_tlm2_dma_device_gasket_simics2tlm_IoMemory')
        gasket.target = 'top.socket32'
        gasket.simulation = simulation

        simulation.gasket_list = [gasket]

class LogHandler:
    _logs = []
    def __init__(self):
        simics.SIM_add_output_handler(self.log, None)

    def log(self, data, src, _):
        for line in src.splitlines():
            self._logs.append(line)

    def match(self, line):
        stest.expect_equal(self._logs.pop(0), line)

stest.untrap_log("error")
log = LogHandler()
SIM_run_command("create-sample-cross-gasket-comp")
SIM_run_command("instantiate-components")
log.match('[component0.simulation error] Incompatible gasket (component0.gasket) connected; version mismatch')
