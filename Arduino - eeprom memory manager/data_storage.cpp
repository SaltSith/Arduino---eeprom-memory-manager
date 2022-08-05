#include "data_storage.h"

#include <Arduino.h>
#include <eeprom.h>

#define BASE_ADDRESS	0		/// Base address of eeprom memory
#define MARKER_ADDRESS  1		/// Marker address

const uint8_t data_storage_init_value = 0xA6;	/// Value to compare with eeprom value read from BASE_ADDRESS

extern data_info_t data_storage_cfg[];

data_info_t *data_storage::data_storage_config = data_storage_cfg;

void data_storage::mark_as_set(const data_type_t id)
{
}

void data_storage::mark_as_free(const data_type_t id)
{
}

void data_storage::init(void)
{
	this->size = EEPROM.length();
	this->marker = 0;

	uint8_t read_init_value = EEPROM.read(BASE_ADDRESS);

	if (read_init_value != data_storage_init_value) {
		Serial.println("Erasing eeprom");
		for (uint16_t i = 0; i < this->size; i++) {
			EEPROM.write(i, 0);
		}
		EEPROM.write(BASE_ADDRESS, data_storage_init_value);
	}

	uint16_t data_storage_base_address = sizeof(data_storage_init_value) + sizeof(this->marker);

	for (uint8_t id = DS_1; id < DS_LAST; id++) {
		data_storage_config[id].addr = data_storage_base_address;
		data_storage_base_address += data_storage_config[id].size;

		Serial.print(data_storage_config[id].id); Serial.print(" ");
		Serial.print(data_storage_config[id].addr); Serial.print(" ");
		Serial.println(data_storage_config[id].size);
	}
}

int data_storage::set(const data_type_t id, const uint8_t * source)
{
	return 0;
}

int data_storage::get(const data_type_t id, uint8_t * destination)
{
	return 0;
}

int data_storage::release(const data_type_t id)
{
	return 0;
}

bool data_storage::is_set(const data_type_t id)
{
	return false;
}
