# © 2021 Intel Corporation
#
# This software and the related documents are Intel copyrighted materials, and
# your use of them is governed by the express license under which they were
# provided to you ("License"). Unless the License provides otherwise, you may
# not use, modify, copy, publish, distribute, disclose or transmit this software
# or the related documents without Intel's prior written permission.
#
# This software and the related documents are provided as is, with no express or
# implied warranties, other than those that are expressly stated in the License.


# <add id="sample-tlm2-gasket-device/gasket-vector-test">
# <insert-until text="# EOF_GASKET_VECTOR_TEST"/></add>
import dev_util as du
import simics
import conf
# SIMICS-21543
conf.sim.deprecation_level = 0

adapter = simics.pre_conf_object('adapter', 'sample_tlm2_gasket_device_doc_vector_example')

VECTOR_SIZE = 100
vector_in = [None] * VECTOR_SIZE
for idx in range(VECTOR_SIZE):
    vector_in[idx] = simics.pre_conf_object('vector_in_%d' % idx,
                                            'sample_tlm2_gasket_device_gasket_simics2systemc_Signal')
    vector_in[idx].signal = 'top.sc_in_vec_%d' % idx
    vector_in[idx].simulation = adapter

signal_object_vect = [du.Dev([du.Signal]) for _ in range(VECTOR_SIZE)]
vector_out = [None] * VECTOR_SIZE
for idx in range(VECTOR_SIZE):
    vector_out[idx] = simics.pre_conf_object('vector_out_%d_' % idx,
                                             'sample_tlm2_gasket_device_gasket_systemc2simics_Signal')
    vector_out[idx].signal = 'top.sc_out_vec_%d' % idx
    vector_out[idx].object = signal_object_vect[idx].obj
    vector_out[idx].simulation = adapter

adapter.gasket_list = vector_in + vector_out

simics.SIM_add_configuration([adapter] + vector_in + vector_out, None)

# EOF_GASKET_VECTOR_TEST
