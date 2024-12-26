# © 2024 Intel Corporation
#
# This software and the related documents are Intel copyrighted materials, and
# your use of them is governed by the express license under which they were
# provided to you ("License"). Unless the License provides otherwise, you may
# not use, modify, copy, publish, distribute, disclose or transmit this software
# or the related documents without Intel's prior written permission.
#
# This software and the related documents are provided as is, with no express or
# implied warranties, other than those that are expressly stated in the License.

# Test checkpoint feature still works
import stest
import dev_util as du
import os
import shutil
import simics

from sample_gasket_comp import *

create_sample_gasket_comp()

def save_checkpoint():
    '''Save a checkpoint'''
    ckpt = stest.scratch_file('gasket-object-ckpt')
    if os.path.exists(ckpt):
        shutil.rmtree(ckpt)
    simics.SIM_write_configuration_to_file(ckpt, 0)

reg1 = du.Register_LE(conf.component0.gasket32, 0, size = 4)
reg2 = du.Register_LE(conf.component0.gasket64, 4, size = 8)
reg3 = du.Register_LE(conf.component0.multi_gasket, 12, size = 4)
reg4 = du.Register_LE(conf.component0.multi_gasket64, 16, size = 8)

reg1.write(1)
stest.expect_equal(reg1.read(), 1)

reg2.write(2)
stest.expect_equal(reg2.read(), 2)

reg3.write(3)
stest.expect_equal(reg3.read(), 3)

reg4.write(4)
stest.expect_equal(reg4.read(), 4)

conf.component0.signal_in.iface.signal.signal_raise()
stest.expect_equal(conf.component0.signal_object.state, True)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_in.output_pin.iface.sc_signal_read.read(), True)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_out.signal.iface.sc_signal_read.read(), True)

conf.component0.signal_in_2.iface.signal.signal_lower()
stest.expect_equal(conf.component0.signal_object_2.state, False)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_in_2.output_pin.iface.sc_signal_read.read(), False)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_out_2.signal.iface.sc_signal_read.read(), False)

print("Saving checkpoint")
save_checkpoint()
simics.SIM_run_command("restart-simics read-configuration.py")
