#ifndef TL_PCIE_DEVICE_H
#define TL_PCIE_DEVICE_H

#include <simics/device-api.h>

#ifdef __cplusplus
extern "C" {
#endif

    SIM_INTERFACE(tl_pcie_mem_if) {
        void (*get)(conf_object_t *obj, uint64 addr, buffer_t buf, uint64 *ret);
        void (*put)(conf_object_t *obj, uint64 addr, buffer_t buf, uint64 *ret);
    };

    void init_harness(conf_object_t *obj);
    void rocc(conf_object_t *obj, uint32 inst, uint64 rs1, uint64 rs2);

#ifdef __cplusplus
}
#endif

#endif