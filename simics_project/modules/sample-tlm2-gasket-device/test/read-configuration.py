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

import stest
import dev_util as du
import sample_gasket_comp

def load_checkpoint():
    '''Load a checkpoint'''
    try:
        SIM_read_configuration(stest.scratch_file('gasket-object-ckpt'))
    except Exception as ex:
        print(ex)
        SIM_quit(1)

print("Loading checkpoint")
load_checkpoint()

stest.expect_equal(conf.component0.signal_object.state, True)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_in.output_pin.iface.sc_signal_read.read(), True)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_out.signal.iface.sc_signal_read.read(), True)

stest.expect_equal(conf.component0.signal_object_2.state, False)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_in_2.output_pin.iface.sc_signal_read.read(), False)
stest.expect_equal(conf.component0.simulation.gasket_top_sc_out_2.signal.iface.sc_signal_read.read(), False)

reg1 = du.Register_LE(conf.component0.gasket32, 0, size = 4)
reg2 = du.Register_LE(conf.component0.gasket64, 4, size = 8)
reg3 = du.Register_LE(conf.component0.multi_gasket, 12, size = 4)
reg4 = du.Register_LE(conf.component0.multi_gasket64, 16, size = 8)
stest.expect_equal(reg1.read(), 1)
stest.expect_equal(reg2.read(), 2)
stest.expect_equal(reg3.read(), 3)
stest.expect_equal(reg4.read(), 4)
