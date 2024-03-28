#ifndef SIMICS_PCI_MEMORY_HPP
#define SIMICS_PCI_MEMORY_HPP

// simics API for PCI-based memory access
#include <simics/c++/devs/pci.h>
#include <simics/c++/devs/memory-space.h>

static conf_object_t * device = NULL;
static conf_object_t * memory_space = NULL;
static const memory_space_interface_t * mifc = NULL;

int setup_pci_interface(conf_object_t * _device, conf_object_t * _memory_space) {
    assert(_device != NULL && _memory_space != NULL);
    const interface_t * _mifc = SIM_get_interface(_memory_space, "memory_space");
    assert (_mifc != NULL);
    // assign static variables for use in subsequent read/write calls
    device = _device;
    memory_space = _memory_space;
    mifc = static_cast<const memory_space_interface_t *>(_mifc);
    return 0;
}

uint64_t rtl_memory_read(uint64_t src_addr, uint64_t len) {
    assert (device != NULL && memory_space != NULL && mifc != NULL);
    assert (len == 1 || len == 2 || len == 4 || len == 8);
    uint64_t dst = 0;
    exception_type_t ret = mifc->access_simple(memory_space, device, src_addr, (uint8_t *) &dst, len, Sim_RW_Read, Sim_Endian_Target);
    assert(ret == Sim_PE_No_Exception);
    return dst;
}

void rtl_memory_write(uint64_t dst_addr, uint64_t len, uint64_t src) {
    assert (device != NULL && memory_space != NULL && mifc != NULL);
    assert (len == 1 || len == 2 || len == 4 || len == 8);
    exception_type_t ret = mifc->access_simple(memory_space, device, dst_addr, (uint8_t *) &src, len, Sim_RW_Write, Sim_Endian_Target);
    assert(ret == Sim_PE_No_Exception);
}

#endif
