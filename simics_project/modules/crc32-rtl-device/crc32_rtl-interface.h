/*
  © 2017 Intel Corporation
*/

/* 	 
  crc32_pcie-interface.h - Skeleton code to base new interface modules on
*/
	 
/* This module is a template for defining new interface types. See the
   "Defining New Interface Types" section of the
   "Simics Model Builder User's Guide" for further documentation.

   The corresponding DML definition can be found in crc32_pcie_interface.dml */

#ifndef RTL_CRC32_INTERFACE_H
#define RTL_CRC32_INTERFACE_H

#include <simics/device-api.h>
#include <simics/pywrap.h>

#ifdef __cplusplus
extern "C" {
#endif

/* If you need to define new struct types, a definition like this will make it
   possible to allocate such structs from Python using crc32_pcie_data_t().

   Before doing this, you will have to load the crc32_pcie_interface
   Simics module, and import the crc32_pcie_interface Python module. */

/* This defines a new interface type. Its corresponding C data type will be
   called "crc32_pcie_interface_t". */
SIM_INTERFACE(crc32_rtl) {
        bool (*start_crc)(conf_object_t *obj, unsigned int src, unsigned int dst, size_t size, bool blocking);
};

/* Use a #define like this whenever you need to use the name of the interface
   type; the C compiler will then catch any typos at compile-time. */
#define CRC32_RTL_INTERFACE "crc32_rtl"

#ifdef __cplusplus
}
#endif

#endif /* ! CRC32_PCIE_INTERFACE_H */
