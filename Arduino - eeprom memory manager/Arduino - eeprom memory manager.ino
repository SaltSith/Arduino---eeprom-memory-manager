/*
 Name:		Arduino___eeprom_memory_manager.ino
 Created:	8/5/2022 9:49:53 PM
 Author:	marcin
*/

#include "data_storage.h"

static data_storage ds;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	Serial.println("Eeprom storage");
	ds.init();

	uint8_t buf[] = { 5, 9, 20, 25 };
	uint8_t read_buf[20] = { 0 };

	int result = ds.set(DS_1, buf);
	if (result == 0) {
		Serial.println("save ok");
	}
	else {
		Serial.println("save error");
	}

	result = ds.get(DS_1, read_buf);
	if (result == 0) {
		Serial.println("read ok");
	}
	else {
		Serial.println("read error");
	}

	result = memcmp(buf, read_buf, 4);
	if (result == 0) {
		Serial.println("read data is correct");
	}
	else {
		Serial.println("read error");
	}

	ds.release(DS_1);
	Serial.println("Release data");
	result = ds.get(DS_1, read_buf);
	if (result == -2) {
		Serial.println("ok - data are not available");
	}
	else {
		Serial.println("read");
	}
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
