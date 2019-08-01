#ifndef EspEepromUtils_h
#define EspEepromUtils_h

#include <WString.h>

class EspEepromUtils {
  public:
  static void wipeEEPROM();
  static void writeEEPROM(uint16_t, unsigned int);
  static void writeEEPROM(uint16_t, int);
  static void writeEEPROM(uint16_t, unsigned long);
  static void writeEEPROM(uint16_t, long);
  static void writeEEPROM(uint16_t, double);
  static void writeEEPROM(uint16_t, double, uint8_t);
  static void writeEEPROM(uint16_t, uint8_t);
  static void writeEEPROM(uint16_t, String);
  static String readEEPROM(uint16_t);
};

#endif
