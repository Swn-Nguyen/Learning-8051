#include <IE74595.h>
#include <main.h>
#include <port.h>

void IE74595_OUT_BYTE(unsigned char d) 
{
	unsigned int i;
	for (i=0; i<8; i++)
	{
		IE74595_DS = d &(0x80>>i);  //lay tung bit cua byte d gui vao DS, lay bit MSB truoc
		// tao xung SHCP - xung dich du lieu tu thanh ghi DS
		IE74595_SHCP = 0; 
		IE74595_SHCP = 1;	
	}
	//tao xung STCP - xung xuat du lieu tu thanh ghi DS
	IE74595_STCP = 0;
	IE74595_STCP = 1;
}

void IE74595_OUT_MULTI(unsigned char *p, unsigned char n)
{
	unsigned char i, j, b;
	for (j=0; j<n; j++)
	{
		b = *(p+n-j-1);
		for(i=0; i<8; i++)
		{
			IE74595_DS = b & (0x80 >>1);
			IE74595_SHCP =0;
			IE74595_SHCP =1;
		}
	}
	IE74595_STCP= 0;
	IE74595_STCP= 1;
}