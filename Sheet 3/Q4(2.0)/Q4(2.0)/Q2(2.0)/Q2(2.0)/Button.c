/*
 * Button.c
 *
 * Created: 10/24/2023 8:07:29 AM
 *  Author: user
 */ 
#include "DIO.h"
void button_vinit(unsigned char port,unsigned char pin)
{
	DIO_vsetPINDir(port,pin,0);
}
unsigned char button_u8read(unsigned char port,unsigned char pin)
{
	unsigned char z;
	z=DIO_readPIN(port,pin);
	
	return z;
}