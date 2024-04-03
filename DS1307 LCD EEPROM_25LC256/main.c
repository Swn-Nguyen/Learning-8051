#include <main.h>
#include <port.h>
#include <..\Lib\Thu_Vien_LCD.h>
#include <..\Lib\RTC_DS1307.h>
#include <..\Lib\SoftI2C.h>
#include <..\Lib\delay.h>
#include <..\Lib\SPI.h>
#include <..\Lib\EEPROM.h>

bit Alarm = 0;
void SetUpTime()
{
	bit condition = 1; 
	unsigned char * code Days[8]= {"Sun ","Mon ", "Tue ", "Wed ", "Thu ", "Fri ", "Sat "};
	unsigned int HH=0, MM=0, SS=0;
	unsigned char DAY=0, DATE=1, MONTH=1, YEAR = 0;
	LCD_Clear();
	// set hh
	if	(BTN_Back ==0) {LCD_Clear(); return;}
	while (condition)
	{
		if(BTN_Mode==0)
		{
			Delay_ms(20);

			if (BTN_Mode ==0)
			{
				HH +=1;
				while (BTN_Mode ==0);
			}
		}
	
		LCD_Gotoxy(4,0);
		LCD_Puts("Hour= ");
		if (HH <24)
		{
			if (HH <10)
			{
				LCD_PutNumber(0);
				LCD_PutNumber(HH);
			}
			else LCD_PutNumber(HH);
		}
		else HH = 0;
		if (BTN_Set ==0)
		{
			Delay_ms(20);
			if(BTN_Set==0)
			{
				condition =0;
				while (BTN_Set==0);
			}
		}
	}
	condition = 1; LCD_Clear();
	// set MM
	while (condition)
	{
		if(BTN_Mode==0)
		{
			Delay_ms(20);
			if (BTN_Mode ==0)
			{
				MM +=1;
				while (BTN_Mode ==0);
			}
		}
	
		LCD_Gotoxy(4,0);
		LCD_Puts("Minute= ");
		if (MM <60)
		{
			if (MM <10)
			{
				LCD_PutNumber(0);
				LCD_PutNumber(MM);
			}
			else LCD_PutNumber(MM);
		}
		
		if (BTN_Set ==0)
		{
			Delay_ms(20);
			if(BTN_Set==0)
			{
				condition =0;
				while (BTN_Set==0);
			}
		}
	}
	condition = 1; LCD_Clear();
	// set SS
	while (condition)
	{
		if(BTN_Mode==0)
		{
			Delay_ms(20);
			if (BTN_Mode ==0)
			{
				SS +=1;
				while (BTN_Mode ==0);
			}
		}
	
		LCD_Gotoxy(4,0);
		LCD_Puts("Second= ");
		if (SS <60)
		{
			if (SS <10)
			{
				LCD_PutNumber(0);
				LCD_PutNumber(SS);
			}
			else LCD_PutNumber(SS);
		}
		
		if (BTN_Set ==0)
		{
			Delay_ms(20);
			if(BTN_Set==0)
			{
				condition =0;
				while (BTN_Set==0);
			}
		}
	}
	condition = 1; LCD_Clear();
	// Set Day
	while (condition)
	{
		if(BTN_Mode==0)
		{
			Delay_ms(20);
			if (BTN_Mode ==0)
			{
				DAY +=1;
				while (BTN_Mode ==0);
			}
		}
	
		LCD_Gotoxy(4,0);
		LCD_Puts("DAY: ");
		LCD_Puts(Days[DAY]);
		if (DAY >=8 )
		{
			DAY =1;
		}
		
		if (BTN_Set ==0)
		{
			Delay_ms(20);
			if(BTN_Set==0)
			{
				condition =0;
				while (BTN_Set==0);
			}
		}
	}
	condition = 1; LCD_Clear();
	// Set Date
	while (condition)
	{
		if(BTN_Mode==0)
		{
			Delay_ms(20);
			if (BTN_Mode ==0)
			{
				DATE +=1;
				while (BTN_Mode ==0);
			}
		}
	
		LCD_Gotoxy(4,0);
		LCD_Puts("DATE: ");
		if(DATE <10)
		{
			LCD_PutNumber(0);
			LCD_PutNumber(DATE);
		}
		else 	LCD_PutNumber(DATE);
		if (DATE >=31 )
		{
			DATE =1;
		}
		
		if (BTN_Set ==0)
		{
			Delay_ms(20);
			if(BTN_Set==0)
			{
				condition =0;
				while (BTN_Set==0);
			}
		}
	}
	condition = 1; LCD_Clear();
	// Set MONTH
	while (condition)
	{
		if(BTN_Mode==0)
		{
			Delay_ms(20);
			if (BTN_Mode ==0)
			{
				MONTH +=1;
				while (BTN_Mode ==0);
			}
		}
	
		LCD_Gotoxy(4,0);
		LCD_Puts("MONTH: ");
		if(MONTH<10)
		{
			LCD_PutNumber(0);
			LCD_PutNumber(MONTH);
		}
		else LCD_PutNumber(MONTH);
		if (MONTH >12 )
		{
			MONTH =1;
		}
		
		if (BTN_Set ==0)
		{
			Delay_ms(20);
			if(BTN_Set==0)
			{
				condition =0;
				while (BTN_Set==0);
			}
		}
	}
	condition=1; LCD_Clear();
	// Set YEAR
	while (condition)
	{
		if(BTN_Mode==0)
		{
			Delay_ms(20);
			if (BTN_Mode ==0)
			{
				YEAR +=1;
				while (BTN_Mode ==0);
			}
		}
	
		LCD_Gotoxy(4,0);
		LCD_Puts("YEAR: ");
		LCD_PutNumber(20);
		if(YEAR <10)
		{
		LCD_PutNumber(0);LCD_PutNumber(YEAR);
		}
		LCD_PutNumber(YEAR);
		
		if (BTN_Set ==0)
		{
			Delay_ms(20);
			if(BTN_Set==0)
			{
				condition =0;
				while (BTN_Set==0);
			}
		}
	}
	DS1307_Write_Time(HH,MM,SS);
	DS1307_Write_Date(DAY, DATE, MONTH, YEAR);
	LCD_Clear();
}

void Set_Alarm()
{
    unsigned char Hour = 0, Minute = 0;
    bit condition = 1;

    LCD_Clear();
    LCD_Gotoxy(0, 0);
    LCD_Puts("Set Alarm");
    
    while (condition)
    {		
				if	(BTN_Back ==0) {LCD_Clear(); return;}
        if (BTN_Mode == 0)
        {
            Delay_ms(20);
            if (BTN_Mode == 0)
            {
                Hour += 1;
                while (BTN_Mode == 0);
            }
        }

        LCD_Gotoxy(0, 1);
        LCD_Puts("Hour= ");
        if (Hour < 24)
        {
            if (Hour < 10)
            {
                LCD_PutNumber(0);
                LCD_PutNumber(Hour);
            }
            else 
            {
                LCD_PutNumber(Hour);
            }
        }
        else 
        {
            Hour = 0;
        }

        if (BTN_Set == 0)
        {
            Delay_ms(20);
            if (BTN_Set == 0)
            {
                condition = 0;
                while (BTN_Set == 0);
            }
        }
    }

    condition = 1;
    LCD_Clear();
    
    while (condition)
    {
			if	(BTN_Back ==0) {LCD_Clear(); return;}
      if (BTN_Mode == 0)
      {
				Delay_ms(20);
				if (BTN_Mode == 0)
				{
						Minute += 1;
						while (BTN_Mode == 0);
				}
      }

			LCD_Gotoxy(0, 0);
			LCD_Puts("Minute= ");
			if (Minute < 60)
			{
				if (Minute < 10)
				{
					LCD_PutNumber(0);
					LCD_PutNumber(Minute);
				}
				else 
				{
					LCD_PutNumber(Minute);
				}
			}

			if (BTN_Set == 0)
			{
				Delay_ms(20);
				if (BTN_Set == 0)
				{
					condition = 0;
					while (BTN_Set == 0);
				}
			}
    }
		
		

    LCD_Clear();
    LCD_Gotoxy(2, 0);
    LCD_Puts("Set alarm at: ");
		LCD_Gotoxy(4,1);
    LCD_PutNumber(Hour);
		LCD_PutChar(':');
    LCD_PutNumber(Minute);
    Delay_ms(2000);
    LCD_Clear();
		Alarm = 1;		
		EEPROM_25LCXXX_Write(0, Hour);
		EEPROM_25LCXXX_Write(1, Minute);
}
void Delete_Alarm()
{
	Alarm = 0;
	LCD_Gotoxy(0,0);
	LCD_Puts("Delete Alarm success");
	Delay_ms(2000);
	LCD_Clear();
}
void Mode()
{
	bit condition = 1;
	unsigned char t=0, i=0;
	LCD_Clear();
	while(condition)
	{
		if (BTN_Mode ==0)
		{
			Delay_ms(20);	
			if(BTN_Mode==0)
			{	
				i++;
				LCD_Clear();
				if(i>3) i = 0;
				while(BTN_Mode ==0);				
			}	
		}
		if(BTN_Back==0) {LCD_Clear(); return;}
		
		LCD_Gotoxy(0,0);
		LCD_Puts("Mode: ");
		switch (i)
		{
			case 1:
				
				LCD_Gotoxy(3,1);
				LCD_Puts("Set Alarm");
				if(BTN_Set ==0) 
				{
					Delay_ms(20);
					if(BTN_Set==0)
					{
						while(BTN_Set ==0);
						Set_Alarm();
					}
				}					
				break;
			
			case 2:
				
				LCD_Gotoxy(1,1);
				LCD_Puts("Delete Alarm");
				if(BTN_Set ==0) 
				{
					Delay_ms(20);
					if(BTN_Set==0)
					{
						while(BTN_Set ==0);
						Delete_Alarm();
					}
				}		
				break;
				
			case 3:
				
				LCD_Gotoxy(3,1);
				LCD_Puts("Set Time");
				if(BTN_Set ==0) 
				{
					Delay_ms(20);
					if(BTN_Set==0)
					{
						while(BTN_Set ==0);
						SetUpTime();
					}
				}		
				break;
			default:
				break;
		}
	}
}

void main()
{
	unsigned char * code Days[7]= {"Sun ", "Mon ", "Tue ", "Wed ", "Thu ", "Fri ", "Sat "};
	
	unsigned int  Hour, Minute, Second, Day, Date, Month, Year;
	
	Soft_SPI_Init();
	Soft_I2c_Init();
	DS1307_Init();
	LCD_Init();
	DS1307_Write(0x07,0x90);	
	
	//ngat canh xuong 
	IT1 = 1;
	EX1 = 1;
	// cho phep ngat toan cuc
	EA = 1;
	while(1)
	{
		if(Alarm ==1 && Hour==EEPROM_25LCXXX_Read(0) && Minute ==EEPROM_25LCXXX_Read(1))
		{
			P1_5 =0;
		}
		else P1_5= 1;
		
		if(BTN_Mode==0) 
		{
			Delay_ms(20);
			while(BTN_Mode==0)
				Mode();
		}
		DS1307_Read_Time(&Hour, &Minute, &Second);
		LCD_Gotoxy(4,1);
		//print hour
		if(Hour <10)
		{
			LCD_PutNumber(0);
			LCD_PutNumber(Hour);
		}
		else
		{
			LCD_PutNumber(Hour);
		}

		LCD_Puts(":");
		//print minute
		if(Minute <10)
		{
			LCD_PutNumber(0);
			LCD_PutNumber(Minute);
		}
		else
		{
			LCD_PutNumber(Minute);
		}
		LCD_Puts(":");
		//print second
		if(Second <10)
		{
			LCD_PutNumber(0);
			LCD_PutNumber(Second);
		}
		else
		{
			LCD_PutNumber(Second);
		}
		
		//read day
		DS1307_Read_Date(&Day, &Date, &Month, &Year);
		LCD_Gotoxy(1,0);
		if(Day<=1)
			LCD_Puts(Days[0]);
		else
			LCD_Puts(Days[Day-1]);
		// date
		if(Date <10)
		{
			LCD_PutNumber(0);
			LCD_PutNumber(Date);
		}
		else
		{
			LCD_PutNumber(Date);
		}
		LCD_Puts("/");
		// month
		if(Month <10)
		{
			LCD_PutNumber(0);
			LCD_PutNumber(Month);
		}
		else
		{
			LCD_PutNumber(Month);
		}
		LCD_Puts("/");
		LCD_PutNumber(20);
		LCD_PutNumber(Year);
		PCON |= 0x01;
	}
}
 //Interrupt service routine
void EX1_ISR(void) interrupt 2 
{}