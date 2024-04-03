#include <LCD.h>
#include <delay.h>
#include <port.h>
#include <main.h>

void LCD_CMD(unsigned char cmd)
{
	LCD_RS = 0;
	LCD_DATA = cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	
	if(cmd<= 0x02)
	{
		Delay_ms(2);
	}
	else
	{
		Delay_ms(1);
	}
}

void LCD_Chr_Cp(char c)
{
	LCD_RS = 1;
	LCD_DATA = c;
	LCD_EN = 0;
	LCD_EN = 1;
	Delay_ms(1);
}

void LCD_Out_Str(char *str)
{
	unsigned char i = 0;
	while (str[i] != 0)
	{
		LCD_Chr_Cp(str[i]);
		i++;
	}
}

void LCD_Init()
{
	LCD_CMD(0x30);
	Delay_ms(5);
	LCD_CMD(0x30);
	Delay_ms(1);
	LCD_CMD(0x30);
	LCD_CMD(0x38); //set 2 dong hien thi, font la 5*8
	LCD_CMD(0x01); //xoa noi dung hien thi
	LCD_CMD(0x0F); //Bat hien thi, bat con tro, nhap nhay 
}
void LCD_SetCursor(unsigned int row, unsigned int col)
{
	unsigned char cmd;
	cmd = row ==1? 0x80:0xC0 + col -1;
	LCD_CMD(cmd);
}

void LCD_Clear()
{
	LCD_CMD(0x01);
}