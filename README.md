# I2C EEPROMs library for Arduino

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

<img src="schematics.png" width="200">

## Examples

Three examples are provided with this library:

### Simple Read through all EEPROM
<a href="I2CEEPROM/examples/I2CEEPROM_Read/I2CEEPROM_FullCheck.ino">Link to source code</a>

### Simple Write though all EEPROM
<a href="I2CEEPROM/examples/I2CEEPROM_Write/I2CEEPROM_FullCheck.ino">Link to source code</a>

### Check consistency of the EEPROM
<a href="I2CEEPROM/examples/I2CEEPROM_FullCheck/I2CEEPROM_FullCheck.ino">Link to source code</a>