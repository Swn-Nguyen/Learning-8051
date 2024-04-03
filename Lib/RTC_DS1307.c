#include "RTC_DS1307.h"
#include "SoftI2C.h"
#include <main.h>
#include <port.h>



void DS1307_Write(unsigned char add, unsigned char dat)
{
	Soft_I2c_Start();
	Soft_I2c_Write(0xD0);
	Soft_I2c_Write(add); 
	Soft_I2c_Write(dat); 
	Soft_I2c_Stop();
}
unsigned char DS1307_Read(unsigned char add)
{
	unsigned char dat;
	Soft_I2c_Start();
	Soft_I2c_Write(0xD0); 
	Soft_I2c_Write(add);
	Soft_I2c_Start(); 
	Soft_I2c_Write(0xD1); 
	dat = Soft_I2c_Read(0);
	Soft_I2c_Stop();
	return dat;
}
void DS1307_Init()
{
 	unsigned char tmp;
	Soft_I2c_Init();
	
	tmp = DS1307_Read(0x00);
	tmp &= 0x7F;
	DS1307_Write(0x00,tmp);		
}
bit DS1307_Read_Time(unsigned int * hour, unsigned int * minute, unsigned int * second)
{
	unsigned int h_tmp, m_tmp, s_tmp, *mode;
	bit am_pm;
	Soft_I2c_Start();
	Soft_I2c_Write(0xD0); 
	Soft_I2c_Write(0x00);
	Soft_I2c_Start(); 
	Soft_I2c_Write(0xD1); 
	s_tmp = Soft_I2c_Read(1);
	m_tmp = Soft_I2c_Read(1);
	h_tmp = Soft_I2c_Read(0);
	Soft_I2c_Stop();

	s_tmp &= 0x7F;
	*second = (s_tmp>>4)*10+(s_tmp&0x0F);
	m_tmp &= 0x7F;
	*minute = (m_tmp>>4)*10+(m_tmp&0x0F);

	if(h_tmp & 0x40) 		// Mode 12h
	{
		*mode = 12;
		if(h_tmp & 0x20)
		{
		 	am_pm = 1;		// PM
		}
		else
		{
		 	am_pm = 0;
		}
		h_tmp &= 0x1F;
	 	*hour = (h_tmp>>4)*10+(h_tmp&0x0F);
	}
	else
	{
		*mode = 24;
		h_tmp &= 0x3F;
	 	*hour = (h_tmp>>4)*10+(h_tmp&0x0F);
		if(*hour<12)
		{
		 	am_pm = 0;		// AM
		}
		else
		{
		 	am_pm = 1;
		}
	}	
	return am_pm;
}
void DS1307_Write_Time(unsigned int hour, unsigned int minute, unsigned int second)
{
	second = ((second/10)<<4)|(second%10);
	minute = ((minute/10)<<4)|(minute%10);
	hour   = ((hour  /10)<<4)|(hour  %10);

	Soft_I2c_Start();
	Soft_I2c_Write(0xD0);
	Soft_I2c_Write(0x00); 
	Soft_I2c_Write(second); 
	Soft_I2c_Write(minute);
	Soft_I2c_Write(hour);
	Soft_I2c_Stop();
}

void DS1307_Read_Date(unsigned int * day, unsigned int * date, 
											unsigned int * month, unsigned int * year)
{
	Soft_I2c_Start();
	Soft_I2c_Write(0xD0); 
	Soft_I2c_Write(0x03);
	Soft_I2c_Start(); 
	Soft_I2c_Write(0xD1);
	*day  = Soft_I2c_Read(1);
	*date = Soft_I2c_Read(1);
	*month= Soft_I2c_Read(1);
	*year = Soft_I2c_Read(0);
	Soft_I2c_Stop();
	*day &= 0x07;
	*date &= 0x3F;
	*date = (*date>>4)*10 + (*date & 0x0F);
	*month &= 0x1F;
	*month = (*month>>4)*10 + (*month & 0x0F);
	*year = (*year>>4)*10 + (*year & 0x0F);
}
void DS1307_Write_Date(unsigned char day, unsigned char date, 
											 unsigned char month, unsigned char year)
{
	date 	= ((date/10)<<4)  | (date%10);
	month 	= ((month/10)<<4) | (month%10);
	year	= ((year/10)<<4)  | (year%10);
	if(day<=1 || day>= 8) day = 1; 
	else day = day;
	Soft_I2c_Start();
	Soft_I2c_Write(0xD0);
	Soft_I2c_Write(0x03); 
	Soft_I2c_Write(day); 
	Soft_I2c_Write(date);
	Soft_I2c_Write(month);
	Soft_I2c_Write(year);
	Soft_I2c_Stop();
}
void DS1307_Write_Bytes(unsigned char add, unsigned char * buff,	unsigned char len)
{
	unsigned char i=0;

	Soft_I2c_Start();
	Soft_I2c_Write(0xD0);
	Soft_I2c_Write(add);
	for(i=0;i<len;i++)
	{ 	 
		Soft_I2c_Write(buff[i]); 
	} 
	Soft_I2c_Stop();
}
void DS1307_Read_Bytes(unsigned char add,unsigned char * buff,
	unsigned char len)
{
 	unsigned char i;

	Soft_I2c_Start();
	Soft_I2c_Write(0xD0); 
	Soft_I2c_Write(add);
	Soft_I2c_Start();
	Soft_I2c_Write(0xD1);
	for(i=0;i<len-1;i++)
	{ 
		buff[i]  = Soft_I2c_Read(1);
	}
	buff[i]  = Soft_I2c_Read(0);
	Soft_I2c_Stop();
}

