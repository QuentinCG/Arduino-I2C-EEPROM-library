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

I2CEEPROM::I2CEEPROM(int i2c_device_address, int addressing_mode)
{
  _i2c_device_address = i2c_device_address;
  _addressing_mode = addressing_mode;

  if(addressing_mode == ADDRESS_MODE_16BIT) {
    _i2c_address_mask = 0xFF;
  } else {
    _i2c_address_mask = (0xFF << addressing_mode);
  }
}

void I2CEEPROM::write(unsigned int address, byte data) const
{
  uint8_t dev_address = generate_I2C_address(address);

  Wire.beginTransmission(dev_address);
  // Send an extra address byte in 16 bit addressing:
  if(_addressing_mode == ADDRESS_MODE_16BIT) Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.write(data);                  // Write byte
  Wire.endTransmission();

  // Writing in I2C EEPROM takes ~5ms (even if I2C writing already done)
  delay(5);
}

byte I2CEEPROM::read(unsigned int address) const
{
  uint8_t dev_address = generate_I2C_address(address);
  byte read_data = 0xFF;

  Wire.beginTransmission(dev_address);
  // Send an extra address byte in 16 bit addressing:
  if(_addressing_mode == ADDRESS_MODE_16BIT) Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();

  // Request 1 byte from device
  Wire.requestFrom(dev_address, 1);

  if (Wire.available()) {
    read_data = Wire.read();
  }

  return read_data;
}

uint8_t I2CEEPROM::generate_I2C_address(uint16_t address) const 
{
  uint8_t dev_address = _i2c_device_address;

  if(_addressing_mode != ADDRESS_MODE_16BIT) {
    // Set the N LSB of the address to the N LSB of the high-byte of the address
    dev_address = (_i2c_device_address & _i2c_address_mask) | ((address >> 8) & (~_i2c_address_mask));
  }

  return dev_address;
}