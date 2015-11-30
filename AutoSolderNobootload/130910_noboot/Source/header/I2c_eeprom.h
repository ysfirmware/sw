#ifndef __I2C_EEPROM
#define __I2C_EEPROM
#include "Custmodel.h"
void AT24C64Write(byte Slave_Addr,byte Addr ,  word Data);
void AT24C64ReadW(byte Slave_Addr,byte Addr);

#endif // __I2C_EEPROM
