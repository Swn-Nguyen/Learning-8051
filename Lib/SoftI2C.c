#include "main.h"
#include "port.h"
#include "delay.h"
#include "SoftI2C.h"

////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Init
// Operation: C�i d?t t�n hi?u SLC v� SDA
// Parameters: Kh�ng
// Return: Kh�ng
// Note: SCL = 1, SDA = 1
//
void Soft_I2c_Init()
{
 SOFT_I2C_SCL = 1;
 SOFT_I2C_SDA = 1;
}
////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Start
// Operation: C�i SDA = 0 trong khi SCL = 1
// Parameters: Kh�ng
// Return: Kh�ng 
//
void Soft_I2c_Start()
{
 SOFT_I2C_SCL = 1;
 Delay_us(1);
 SOFT_I2C_SDA = 0;
 Delay_us(1);
 SOFT_I2C_SCL = 0;
}
////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Get_Ack
// Operation: Nh?n Ack
// Parameters: Kh�ng 
// Return: result 
//
bit Soft_I2c_Get_Ack()
{
 bit result;
 SOFT_I2C_SDA = 1;
 Delay_us(1);
 SOFT_I2C_SCL = 1;
 Delay_us(1);
 result = SOFT_I2C_SDA;
 SOFT_I2C_SCL = 0;
 return result;
}
////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Write
// Operation: G?i data t? Master
// Parameters: dat 
// Return: Soft_I2c_Get_Ack() 
// Note: Sau khi g?i dat h�m tr? v? s? ki?m tra xem slave nh?n duoc // chua
//
bit Soft_I2c_Write(unsigned char dat)
{
 unsigned char i;
 for(i = 0; i < 8; i++)
 {
 SOFT_I2C_SDA = (bit)(dat&0x80); 
 SOFT_I2C_SCL = 1;
 Delay_us(1);
 SOFT_I2C_SCL = 0;
 dat<<=1;
 }
 return(Soft_I2c_Get_Ack());
}
////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Ack
// Operation: G?i Ack t? Master
// Parameters: Kh�ng
// Return: Kh�ng 
//
void Soft_I2c_Ack()
{
 SOFT_I2C_SDA = 0;
 Delay_us(1);
 SOFT_I2C_SCL = 1;
 Delay_us(1);
 SOFT_I2C_SCL = 0;
}
////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Nak
// Operation: G?i Nak t? Master
// Parameters: Kh�ng 
// Return: kh�ng 
//
void Soft_I2c_Nak()
{
 SOFT_I2C_SDA = 1;
 Delay_us(1);
 SOFT_I2C_SCL = 1;
 Delay_us(1);
 SOFT_I2C_SCL = 0;
}
////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Read
// Operation: �?c d? li?u t? Slave
// Parameters: ack
// Return: dat 
//
unsigned char Soft_I2c_Read(bit ack)
{
 unsigned char i, dat = 0;
 for(i = 0; i < 8; i ++)
 {
 SOFT_I2C_SDA = 1;
 Delay_us(1);
 SOFT_I2C_SCL = 1;
 Delay_us(1);
 dat <<= 1;
 if(SOFT_I2C_SDA)
 {
 dat |= 0x01;
 }
 SOFT_I2C_SCL = 0;
 }
 if(ack)
 {
 Soft_I2c_Ack();
 }
 else
 {
 Soft_I2c_Nak();
 }
 return dat;
}
////////////////////////////////////////////////////////////////
// Function: Soft_I2c_Stop
// Operation: SDA = 1 khi SCL = 1
// Parameters: Kh�ng
// Return: Kh�ng
//
void Soft_I2c_Stop()
{ 
 SOFT_I2C_SDA = 0;
 Delay_us(1);
 SOFT_I2C_SCL = 1;
 Delay_us(1);
 SOFT_I2C_SDA = 1;
}