/*
 * \brief Check consistency of I2C EEPROM
 *
 * It will write test values in the entire EEPROM and try to read them.
 * All errors will be displayed.
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 15 January 2023
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2023 Quentin Comte-Gaz
 * \version 1.3
 */

#include <I2CEEPROM.h>

#define CHIP_ADDRESS 0x50 // Address of EEPROM chip (24LC256->0x50)
#define EEPROM_BYTES 32768 // Number of bytes in EEPROM chip

// Uncomment if you use a CAT24Cxx EEPROM (not needed for 24LCxxx EEPROM)
//#define CAT_EEPROM_DEVICE EEPROM_DEVICE_CAT24C16 // You can use one of those elements: EEPROM_DEVICE_CAT24C01, EEPROM_DEVICE_CAT24C02, EEPROM_DEVICE_CAT24C04, EEPROM_DEVICE_CAT24C08, EEPROM_DEVICE_CAT24C16

I2CEEPROM i2c_eeprom(CHIP_ADDRESS/*, CAT_EEPROM_DEVICE*/); // Create I2C EEPROM instance

void setup(void)
{
  Serial.begin(9600);

  // Variables
  Serial.print("CHIP_ADDRESS=0x");
  Serial.print(CHIP_ADDRESS, HEX);
  Serial.print("\n");

  Serial.print("EEPROM_BYTES=");
  Serial.print(EEPROM_BYTES, DEC);
  Serial.print("\n\n");

  Serial.print("This test will: \n -Write all the EEPROM\n -Read all the EEPROM and check consistency\n\n");
  // For even more extended test, you may write values ("writeTest()"), reboot and read values ("readTest()")
  // This would ensure that the EEPROM is holding values even after a reboot.

  Serial.print("Beginning EEPROM check-up...\n");

  writeTest();
  readTest();

  Serial.print("EEPROM check-up done\n");
}

void loop()
{
  // We do the check only once (in the setup)
}

/*!
 * \brief Write all bytes in I2C EEPROM for test scenario
 */
void writeTest(void)
{
  Serial.print("Writing test values in EEPROM...\n");
  for (unsigned int address = 0; address < EEPROM_BYTES; address++)
  {
    i2c_eeprom.write(address, address/1024);

    if ((address%1024) == 0)
    {
      Serial.print(address, DEC);
      Serial.print("/");
      Serial.print(EEPROM_BYTES, DEC);
      Serial.print(" bytes done\n");
    }
  }
}

/*!
 * \brief Try to read all bytes in I2C EEPROM from test scenario
 */
void readTest()
{
  unsigned int errors = 0;
  unsigned int data = 0;

  Serial.print("Reading the EEPROM and check consistency\n");

  for (unsigned int address = 0; address < EEPROM_BYTES; address++)
  {
    data = i2c_eeprom.read(address);

    if (data != address/1024)
    {
      errors++;
      Serial.print("Error on address ");
      Serial.print(address, HEX);
      Serial.print(" : data in EEPROM is ");
      Serial.print(data, HEX);
      Serial.print(" while it should be ");
      Serial.print(address/1024, DEC);
      Serial.print("\n");
    }

    if ((address%1024) == 0)
    {
      Serial.print(address, DEC);
      Serial.print("/");
      Serial.print(EEPROM_BYTES, DEC);
      Serial.print(" bytes done\n");
    }
  }

  Serial.print("All EEPROM read\n");
  Serial.print("Number of errors: ");
  Serial.print(errors);
  Serial.print("\n");
}
