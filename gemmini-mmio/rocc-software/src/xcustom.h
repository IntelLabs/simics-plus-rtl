#ifndef ROCC_SOFTWARE_SRC_XCUSTOM_H_
#define ROCC_SOFTWARE_SRC_XCUSTOM_H_

uint8_t *pcie_control_base = NULL;

#define GEMMINI_RS1_ADDR   (pcie_control_base + 0x0)
#define GEMMINI_RS2_ADDR   (pcie_control_base + 0x8)
#define GEMMINI_INST_ADDR  (pcie_control_base + 0x10)
#define GEMMINI_ISSUE_ADDR (pcie_control_base + 0x18)

#undef ROCC_INSTRUCTION_0_R_R
#define ROCC_INSTRUCTION_0_R_R(x, rs1, rs2, funct) { \
    *((volatile uint64_t *) GEMMINI_RS1_ADDR) = (uint64_t) (rs1); \
    *((volatile uint64_t *) GEMMINI_RS2_ADDR) = (uint64_t) (rs2); \
    *((volatile uint32_t *) GEMMINI_INST_ADDR) = (0x7B) | (0 << 7) | (3 << 12) | (1 << 15) | (2 << 20) | ((funct) << 25); \
    *((volatile uint8_t *) GEMMINI_ISSUE_ADDR) = 1; \
}

#undef ROCC_INSTRUCTION
#define ROCC_INSTRUCTION(x, rd, rs1, rs2, funct) { 0; }

// DANGEROUS, might screw things up but we need this for x86 compatibility
#define _volatile(x) volatile(x)
#define volatile(str) ("nop")

#endif  // ROCC_SOFTWARE_SRC_XCUSTOM_H_
