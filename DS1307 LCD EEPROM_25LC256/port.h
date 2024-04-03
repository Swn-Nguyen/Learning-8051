#ifndef _PORT_H_
#define _PORT_H_ 

sbit LCD_RS = P2^0;
sbit LCD_RW = P2^1;
sbit LCD_EN = P2^2;
sbit LCD_D4 = P2^4;
sbit LCD_D5 = P2^5;
sbit LCD_D6 = P2^6;
sbit LCD_D7 = P2^7;

sbit BTN_Mode = P1^0;
sbit BTN_Set  = P1^2;
sbit BTN_Back = P1^4;

sbit SOFT_I2C_SCL = P3^0;
sbit SOFT_I2C_SDA = P3^1;

sbit SPI_CLK = P0^0;
sbit SPI_MOSI = P0^1;
sbit SPI_MISO = P0^2;
sbit SPI_CS = P0^3;

#endif