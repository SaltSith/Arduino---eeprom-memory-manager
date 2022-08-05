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

class data_storage
{
private:
	uint16_t size;							/// Eeprom meory size
	uint32_t marker;						/// Data marker
	static data_info_t *data_storage_cfg;	/// Data storage config

	void mark_as_set(const data_type_t id);
	void mark_as_free(const data_type_t id);

public:
	void init(void);
	int set(const data_type_t id, const uint8_t *source);
	int get(const data_type_t id, uint8_t *destination);
	int release(const data_type_t id);
	bool is_set(const data_type_t id);
};
