# © 2023 Intel Corporation

simics_add_module(tl_pcie-device
  CLASSES tl_pcie_device
  SOURCES tl_pcie-device.dml module_load.py
  SIMICS_API 6
)
add_subdirectory(test)
