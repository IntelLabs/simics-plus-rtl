#ifndef GEMMINI_MMIO_H
#define GEMMINI_MMIO_H
#ifndef GEMMINI_PARAMS_H
#error INCLUDE GEMMINI.H FIRST
#endif

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

extern uint8_t *pcie_control_base;
uint8_t *pcie_memory_base = NULL;

#ifndef PCIE_MEM_SIZE
#define PCIE_MEM_SIZE 8388608
#endif

void memcpy_to_pcie(size_t dst_offset, uint8_t *src_addr, size_t len) {
    printf("copying to base %p at offset %lx, length %lu, from %p\n", pcie_memory_base, dst_offset, len, src_addr);
    fflush(stdout);
    memcpy(pcie_memory_base + dst_offset, src_addr, len);
}

void memcpy_from_pcie(uint8_t *dst_addr, size_t src_offset, size_t len) {
    memcpy(dst_addr, pcie_memory_base + src_offset, len);
}

void pcie_setup() {
    int fd;
    unsigned char *rocc, *mem;
    const char *resource0 = "/sys/bus/pci/devices/0000:00:0c.0/resource0";
    const char *resource4 = "/sys/bus/pci/devices/0000:00:0c.0/resource4";

    fd = open(resource0, O_RDWR | O_SYNC);
    if (fd == -1) {
        fprintf(stderr, "ERROR: failed to open pcie control device\n");
        perror("open");
        return;
    }
    pcie_control_base = mmap(NULL, 32, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if ((ssize_t) pcie_control_base == -1) {
        fprintf(stderr, "ERROR: failed to mmap pcie control space\n");
    }
    close(fd);

    fd = open(resource4, O_RDWR | O_SYNC);
    if (fd == -1) {
        fprintf(stderr, "ERROR: failed to open pcie memory device\n");
        perror("open");
        return;
    }
    pcie_memory_base = mmap(NULL, PCIE_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if ((ssize_t) pcie_memory_base == -1) {
        fprintf(stderr, "ERROR: failed to mmap pcie memory space\n");
    }
    close(fd);

    // munmap(mem, 0);
}

__attribute__((constructor))
void before_main() {
    printf("initializing pcie addresses\n");
    pcie_setup();
}

#endif
