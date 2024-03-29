# I2C EEPROMs library for Arduino
[![Build Status](https://travis-ci.org/QuentinCG/Arduino-I2C-EEPROM-library.svg?branch=master)](https://travis-ci.org/QuentinCG/Arduino-I2C-EEPROM-library) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/77f8ec4dae9c491a81c68d7df4e89eb1)](https://www.codacy.com/manual/QuentinCG/Arduino-I2C-EEPROM-library?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=QuentinCG/Arduino-I2C-EEPROM-library&amp;utm_campaign=Badge_Grade) [![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/LICENSE.md) [![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://paypal.me/QuentinCG)
 
## What is it

This library (with examples) is designed to be integrated in projects using I2C EEPROM.
It can read and write data from I2C EEPROMs.
It has been fully tested with 24LC256 device but should work with others.

It should be compatible with 24LCxxx and CAT24Cxxx EEPROMs:
 - 24LC512, 24LC256, 24LC128, ...
 - CAT24C01, CAT24C02, CAT24C04, CAT24C08, CAT24C16, ...

## How to install

1) Download <a target="_blank" href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/releases/">latest release (zip file, not the source code)</a>

2) On your Arduino IDE, click "Sketch" menu and then "Include Library > Add .ZIP Libraries"

3) You can now use the library for your project or launch an example ("File > Examples")

## How to connect I2C EEPROM to arduino

Most of I2C EEPROMs are connected the same way.

Here are the pin connections for 24LC256 device:

|24LC256|Arduino Source             |
|-------|-------                    |
|VCC    |5V                         |
|GND    |GND                        |
|SCL    |SCL (A5)                   |
|SDA    |SDA (A4)                   |
|Others |GND (-> I2C address = 0x50)|

<img src="schematics.png" width="400">

## How to use the EEPROM (CAT24Cxx & 24LCxxx & others) ?

 - If you use a 24LCxxx EEPROM, you can initialize the EEPROM this way:
```cpp
#define CHIP_ADDRESS 0x50 // Address of EEPROM chip

I2CEEPROM i2c_eeprom(CHIP_ADDRESS);

// Read and write the same value from EEPROM
i2c_eeprom.write(0 /* value address */, 15 /* value to write */);
unsigned int read_value = i2c_eeprom.read(0 /* value address */);
```
 - If you use a CAT24Cxx EEPROM, you need to initialize the EEPROM this way:
```cpp
#define CHIP_ADDRESS 0x50 // Address of EEPROM chip
#define CAT_EEPROM_DEVICE EEPROM_DEVICE_CAT24C01 // You can use one of those elements: EEPROM_DEVICE_CAT24C01, EEPROM_DEVICE_CAT24C02, EEPROM_DEVICE_CAT24C04, EEPROM_DEVICE_CAT24C08, EEPROM_DEVICE_CAT24C16

I2CEEPROM i2c_eeprom(CHIP_ADDRESS, CAT_EEPROM_DEVICE);

// Read and write the same value from EEPROM
i2c_eeprom.write(0 /* value address */, 15 /* value to write */);
unsigned int read_value = i2c_eeprom.read(0 /* value address */);
```
 - If you use an other EEPROM, it should work the same way as 24LCxxx EEPROM (maybe not the same I2C address)

## Examples

Three examples are provided with this library:

### Simple Read through all EEPROM
<a target="_blank" href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/examples/I2CEEPROM_Read/I2CEEPROM_Read.ino">Link to source code</a>

### Simple Write though all EEPROM
<a target="_blank" href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/examples/I2CEEPROM_Write/I2CEEPROM_Write.ino">Link to source code</a>

### Simple Update though all EEPROM
<a target="_blank" href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/examples/I2CEEPROM_Update/I2CEEPROM_Update.ino">Link to source code</a>

### Check consistency of the EEPROM
<a target="_blank" href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/examples/I2CEEPROM_FullCheck/I2CEEPROM_FullCheck.ino">Link to source code</a>

## License

This project is under MIT license. This means you can use it as you want (just don't delete the library header).

## Contribute

If you want to add more examples or improve the library, just create a pull request with proper commit message and right wrapping.

## Contributors

- Thank you <a target="_blank" href="https://github.com/Bu-Gee">Bu-Gee</a> for your help on adding CAT24Cxx compatibility from this <a target="_blank" href="https://github.com/Bu-Gee/Arduino-I2C-EEPROM-library">fork</a>.
