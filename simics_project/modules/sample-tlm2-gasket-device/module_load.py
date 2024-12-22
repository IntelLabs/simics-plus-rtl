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


import cli
from . import utility

device_class_names = ["sample_tlm2_gasket_device",]

#
# ------------------------ info -----------------------
#

def get_info(obj):
    return []

for name in device_class_names:
    cli.new_info_command(name, get_info)

#
# ------------------------ status -----------------------
#

for name in device_class_names:
    cli.new_status_command(name, utility.get_status)
