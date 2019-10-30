/*
 * \brief I2C EEPROMs data writer/reader library
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 29 June 2016
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2016 Quentin Comte-Gaz
 * \version 1.1
 *
 * \history
 *  - v1.0 Main design of the library
 *  - v1.1 Add Arduino < 1.0 compatibility
 */

#ifndef I2CEEPROM_h
#define I2CEEPROM_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class I2CEEPROM
{
  public:
    /*!
     * \brief I2CEEPROM Initialize I2C EEPROM instance
     * \param device_address (int) I2C address of the EEPROM device
     */
    I2CEEPROM(int i2c_device_address);

    /*!
     * \brief write Write one byte \p data in EEPROM device at EEPROM internal address \p address
     * \param address (unsigned int) EEPROM internal address (most of the time, first address is 0x00)
     * \param data (byte) Byte to write at EEPROM internal address \p address
     */
    void write(unsigned int address, byte data) const;

    /*!
     * \brief read Read one byte in EEPROM device at EEPROM internal address \p address
     * \param address (unsigned int) EEPROM internal address (most of the time, first address is 0x00)
     * \return (byte) Read Byte at EEPROM internal address \p address (returns 0xFF if an error occurred)
     */
    byte read(unsigned int address) const;

  private:
    int _i2c_device_address;
};

#endif //I2CEEPROM_h

