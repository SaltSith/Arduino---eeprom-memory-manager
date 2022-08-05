#pragma once

#include <stdint.h>

/*
 * The enumeration of data types kept in eeprom.
 */
typedef enum {
	DS_1 = 0,
	DS_2,
	DS_3,
	DS_LAST
} data_type_t;

/*
 * The structure defines data info.
 */
typedef struct {
	const data_type_t id;		/// Data id
	uint16_t addr;				/// Address in eeprom memory
	uint16_t size;				/// Sizeof data in bytes
} data_info_t;

