/*
 * main.c
 *
 * Created: 2/27/2024 8:35:04 PM
 *  Author: mohaned
 */ 

//#include <xc.h>
#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRA=0xFF;
	unsigned char num[10]={63,6,91,79,102,109,125,7,127,111};
		DDRC=0xFF;
		PORTC=0b01000000;
    while(1)
    {
		for (int i =0; i<10;i++)
		{
			PORTA=num[i]*2;
			_delay_ms(500);
		}
    }
}