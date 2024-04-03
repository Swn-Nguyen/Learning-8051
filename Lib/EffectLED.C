#include <EffectLED.h>
#include <REGX51.H>

#define LED_PORT P2

void delayms(unsigned int t){
        unsigned int i,j;
        for(i=0;i<t;i++)
        for(j=0;j<125;j++);}
void Effect1()//LED_PORT = 0xAA; chop tat LED xen ke
{
	LED_PORT = ~(LED_PORT);
}

void Effect2()//LED_PORT = 0x00; LED sang dan & LED tat dan
{
  int i;
	for (i=0; i<8; i++)
	{
		LED_PORT = (LED_PORT<<1) | 1;
		delayms(300);
	}
	for(i=0; i <8; i++)
	{
		LED_PORT = LED_PORT <<1;
		delayms(300);
	}
}

void Effect3() //LED_PORT = 0x00; LED sang dan & LED tat dan
{
	int i;
	for(i=0; i <8; i++)
	{
		LED_PORT= (LED_PORT>>1)| 0x80;
		delayms(300);
	}
	for(i=0; i<8; i++)
	{
		LED_PORT= LED_PORT>>1;
		delayms(300);
	}
}

void Effect4() 
{
	
	int Effect40[5] = {0x00, 0x81, 0xC3, 0xE7, 0xFF};
	int Effect41[5] = {0xFF, 0xE7, 0xC3, 0x81, 0x00};
	unsigned int i;
	LED_PORT= 0x00;
	for (i=0; i<5; i++)
	{
		LED_PORT = Effect40[i];
		delayms(200);
	}
	for (i=0; i<5; i++)
	{
		LED_PORT = Effect41[i];
		delayms(200);
	}
}

void Effect5() 
{
	int effect50[8] = {0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};
	int i, j;
	LED_PORT = 0x00;
	
	for (i = 7; i >= 0; i--)
	{
		for(j = 0; j <= i; j++)
		{
			LED_PORT |= (1 << j);
			delayms(200);
		}
		LED_PORT = effect50[7 - i];
	}

	// Tat tat ca các LED
	LED_PORT = 0xFF;
	delayms(500);

	// Bat len lu?t t? trái sang ph?i
	for(i = 0; i < 8; i++)
	{
		LED_PORT |= (1 << i);
		delayms(500);
	}
	
	// T?t t?t c? các LED
	
}
