/*
 * \brief Read all bytes of I2C EEPROMs
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 29 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.0
 */

#include <I2CEEPROM.h>

#define CHIP_ADDRESS 0x50 // Address of EEPROM chip (24LC256->0x50)
#define EEPROM_BYTES 32768 // Number of bytes in EEPROM chip

I2CEEPROM i2c_eeprom(CHIP_ADDRESS); // Create I2C EEPROM instance
unsigned int current_address = 0;

void setup(void)
{
  Serial.begin(9600);

  Serial.print("CHIP_ADDRESS=0x");
  Serial.print(CHIP_ADDRESS, HEX);
  Serial.print("\n");

  Serial.print("EEPROM_BYTES=");
  Serial.print(EEPROM_BYTES, DEC);
  Serial.print("\n\n");
}

void loop()
{
  Serial.print("Read: 0x");
  Serial.print(current_address, HEX);
  Serial.print(" (address) -> 0x");
  Serial.print(i2c_eeprom.read(current_address), HEX);
  Serial.print(" (data)\n");

  current_address++;
  if (current_address >= EEPROM_BYTES) {
    while(1) {
      Serial.print("End of demo\n");
      delay(60000);
    }
  }
  delay(1000);
}
