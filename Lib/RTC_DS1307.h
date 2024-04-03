#ifndef _RTC_DS1307_H_
#define _RTC_DS1307_H_

void DS1307_Write(unsigned char add, unsigned char dat);
unsigned char DS1307_Read(unsigned char add);
void DS1307_Init();
bit DS1307_Read_Time(unsigned int * hour, unsigned int * minute, unsigned int * second);
void DS1307_Write_Time(unsigned int hour, unsigned int minute, unsigned int second);
void DS1307_Read_Date(unsigned int * day, unsigned int * date, unsigned int * month, unsigned int * year);
void DS1307_Write_Date(unsigned char day, unsigned char date, 
											 unsigned char month, unsigned char year);
void DS1307_Write_Bytes(unsigned char add, unsigned char * buff,	unsigned char len);
void DS1307_Read_Bytes(unsigned char add,unsigned char * buff,
	unsigned char len);
#endif 