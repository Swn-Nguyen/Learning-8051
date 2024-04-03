#ifndef _EEPROM_H_
#define _EEPROM_H_


unsigned char EEPROM_25LCXXX_WIB();
void EEPROM_25LCXXX_Write(unsigned int add, unsigned char b);
unsigned char EEPROM_25LCXXX_Read(unsigned int add);

#endif