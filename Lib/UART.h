#ifndef _UART_H_
#define _UART_H_

void UART_Init(); //khoi tao UART mode 1
void UART_Write_Text1(unsigned char *s); //ghi chuoi cach 1
char UART_Data_Ready(); //kiem tra xem co nhan duoc byte du lieu chua, tra ve 1: da nhan duoc, tra ve 0: chua nhan duoc
char UART_Read(); //doc byte du lieu nhan tu UART
void UART_Write(char c); //ghi ky tu
void UART_Write_Text2(char *str); //ghi chuoi bang cach 2 
#endif