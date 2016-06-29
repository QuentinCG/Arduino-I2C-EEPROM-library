# I2C EEPROMs library for Arduino

## What is it?

This library (with examples) is designed to be integrated in projects using I2C EEPROM.
It can read and write data from I2C EEPROMs.
It has been fully tested with 24LC256 device but should work with others.

## How to connect I2C EEPROM to arduino

Most of I2C EEPROMs are connected the same way.

Here is the connection for 24LC256 device:

24LC256  | Arduino Source
-------- |  --------
VCC      | 5V
GND      | GND
SCL      | SCL (A5)
SDA      | SDA (A4)
Others   | GND (-> I2C address = 0x50)

<img src="schematics.png" width="400">

## Examples

Three examples are provided with this library:

### Simple Read through all EEPROM
<a href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/I2CEEPROM/examples/I2CEEPROM_Read/I2CEEPROM_Read.ino">Link to source code</a>

### Simple Write though all EEPROM
<a href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/I2CEEPROM/examples/I2CEEPROM_Write/I2CEEPROM_Write.ino">Link to source code</a>

### Check consistency of the EEPROM
<a href="https://github.com/QuentinCG/Arduino-I2C-EEPROM-library/blob/master/I2CEEPROM/examples/I2CEEPROM_FullCheck/I2CEEPROM_FullCheck.ino">Link to source code</a>

## License

This project is under MIT license. This means you can use it as you want (just don't delete the library header).

## Contribute

If you want to add more examples or improve the library, just push your change with proper commit message and right wrapping.