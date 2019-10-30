/*
 * \brief I2C EEPROMs data writer/reader (implementation)
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 29 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.1
 */

#include "I2CEEPROM.h"
#include <Wire.h>

I2CEEPROM::I2CEEPROM(int i2c_device_address)
{
  _i2c_device_address = i2c_device_address;
  Wire.begin();
}

void I2CEEPROM::write(unsigned int address, byte data) const
{
  Wire.beginTransmission(_i2c_device_address);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.write(data);                  // Write byte
  Wire.endTransmission();

  // Writing in I2C EEPROM takes ~5ms (even if I2C writing already done)
  delay(5);
}

byte I2CEEPROM::read(unsigned int address) const
{
  byte read_data = 0xFF;

  Wire.beginTransmission(_i2c_device_address);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();

  // Request 1 byte from device
  Wire.requestFrom(_i2c_device_address, 1);

  if (Wire.available()) {
    read_data = Wire.read();
  }

  return read_data;
}