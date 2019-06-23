#include <Arduino.h>
#include "EspEepromUtils.h"

#include <ESP.h>
#include <EEPROM.h>
#include <WString.h>

void EspEepromUtils::wipeEEPROM() {
	for (uint16_t i = 0 ; i < 4096; i++) {
		EEPROM.write(i, 0x00);
	}
	EEPROM.commit();
}

void EspEepromUtils::writeEEPROM(uint16_t addr, unsigned long data) {
	writeEEPROM(addr, String(data));
}

void EspEepromUtils::writeEEPROM(uint16_t addr, long data) {
	writeEEPROM(addr, String(data));
}

void EspEepromUtils::writeEEPROM(uint16_t addr, double data) {
	writeEEPROM(addr, data, 4);
}

void EspEepromUtils::writeEEPROM(uint16_t addr, double data, uint8_t precision) {
	writeEEPROM(addr, String(data, precision));
}

void EspEepromUtils::writeEEPROM(uint16_t addr, uint8_t data) {
	writeEEPROM(addr, String(data));
}

void EspEepromUtils::writeEEPROM(uint16_t addr, String data) {
	uint8_t size = data.length();
	for (uint8_t i = 0; i < size; i++) {
		EEPROM.write(addr + i, data.charAt(i));
	}
	EEPROM.write(addr + size, 0);
	EEPROM.commit();
}

String EspEepromUtils::readEEPROM(uint16_t addr) {
	String result = "";
	uint8_t count = 0;
	while (true) {
		char byte = EEPROM.read(addr + count);
		if (byte == '\0') {
			break;
		}
		else {
			result.concat(byte);
		}
		count++;
	}
	return result;
}
