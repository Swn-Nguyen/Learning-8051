#include "main.h"
#include "EEPROM.h"
#include "SPI.h"
#include "port.h"



unsigned char EEPROM_25LCXXX_WIB()
{
	unsigned char  result;
	
	SPI_CS = 0;
	Soft_SPI_Write(0x05);
	result = Soft_SPI_Read();
	SPI_CS = 1;
	
	return result&0x01;
}
void EEPROM_25LCXXX_Write(unsigned int add, unsigned char b)
{
	SPI_CS = 0 ;
	Soft_SPI_Write(0x06);
	SPI_CS = 1;
	
	SPI_CS = 0;
	Soft_SPI_Write (0x02);
	Soft_SPI_Write (add>>8);
	Soft_SPI_Write (add & 0x00FF);
	Soft_SPI_Write (b);
	SPI_CS = 1;
	
	while(EEPROM_25LCXXX_WIB());
}
unsigned char EEPROM_25LCXXX_Read(unsigned int add)
{
	unsigned char b;
	SPI_CS= 0;
	Soft_SPI_Write(0x03);
	Soft_SPI_Write(add>>8);
	Soft_SPI_Write(add & 0x00FF);
	b= Soft_SPI_Read();
	SPI_CS = 1;
	
	return b;
}