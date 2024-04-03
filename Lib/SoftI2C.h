#ifndef _SOFTI2C_H_
#define _SOFTI2C_H_

void Soft_I2c_Init();
void Soft_I2c_Start();
bit Soft_I2c_Get_Ack();
bit Soft_I2c_Write(unsigned char dat);
void Soft_I2c_Ack();
void Soft_I2c_Nak();
unsigned char Soft_I2c_Read(bit ack);
void Soft_I2c_Stop();


#endif 