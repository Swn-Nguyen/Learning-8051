#include "UART.h"
#include "main.h"


void UART_Init()
{
	SCON = 0x50; // chon che do UART 1 SM1=1; REN = 1
	TMOD &= 0x0F;
	TMOD |= 0x20;// chon che do timer 1 8 bit tu dong nap lai
	
	#if(BAUD_RATE== 9600)
	TH1 = 0xFD; // toc do baud 9600
	#elif(BAUD_RATE==2400)
	TH1 = 0xF4;
	#elif(BAUD_RATE == 1200)
	TH1 = 0xE8;
	#elif(BAUD_RATE == 19200)
	TH1 = 0xFD;
	PCON |=0x80;
	#else
		#error "Toc do Baud khong ho tro"
	#endif
	
	TR1 = 1; // timer 1 bat dau chay
	TI = 1;
}

void UART_Write_Text1(unsigned char *s)
{
	while (*s)
	{
		SBUF = *s++;
		while (TI ==0);
		TI=0;
	}
}

char UART_Data_Ready()
{
	return RI;
}
char UART_Read()
{
	RI = 0;
	return SBUF;
}
void UART_Write(char c)
{
	while(TI==0);
	TI=0;
	SBUF= c;
}
void UART_Write_Text2(char *str)
{
	unsigned char i=0;
	while(str[i]!=0)
	{
		UART_Write(str[i]);
		i++;
	}
}