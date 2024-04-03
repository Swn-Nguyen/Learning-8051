#ifndef _PORT_H_
#define _PORT_H_

void LCD_CMD(unsigned char cmd);
void LCD_Chr_Cp(char c);
void LCD_Out_Str(char *str);
void LCD_Init();
void LCD_SetCursor(unsigned int row, unsigned int col);
void LCD_Clear();

#endif