#ifndef SIMICS_PCIE_MEMORY_HPP
#define SIMICS_PCIE_MEMORY_HPP

// simics API for PCI-based memory access
#include "tl_pcie_device.h"

#define BUS_WIDTH 128
#define BUS_BYTES (BUS_WIDTH / 8)
#define BUS_WORDS (BUS_WIDTH / 32)

static conf_object_t *device = NULL;
static const tl_pcie_mem_if_interface_t *pcie_mem_if = NULL;

int setup_pcie_interface(conf_object_t * _device) {
    assert(_device != NULL);
    device = _device;
    pcie_mem_if = static_cast<const tl_pcie_mem_if_interface_t *>(SIM_c_get_interface(device, "tl_pcie_mem_if"));
    assert(pcie_mem_if);
    return 0;
}

bool interface_initialized() {
    return pcie_mem_if ? true : false;
}

void rtl_memory_get(uint64_t src_addr, uint8_t *buf, uint64_t len) {
    assert(device);
    assert(pcie_mem_if);

    buffer_t dst_buf = (buffer_t) {.data = buf, .len = len};

    uint64 ret_value = 1;
    memset(dst_buf.data, 0, BUS_BYTES);
    pcie_mem_if->get(device, src_addr, dst_buf, &ret_value);

    assert(ret_value == 0);
}

void rtl_memory_put(uint64_t dst_addr, uint8_t *buf, uint64_t len) {
    assert(device);
    assert(pcie_mem_if);

    buffer_t src_buf = (buffer_t) {.data = buf, .len = len};

    uint64 ret_value = 1;
    pcie_mem_if->put(device, dst_addr, src_buf, &ret_value);

    assert(ret_value == 0);
}

#endif