/*
 * main.c
 *
 * Created: 2/27/2024 5:29:16 PM
 *  Author: mohaned
 */ 

// #include <xc.h>
#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	MCUCSR|=1<<JTD;
	MCUCSR|=1<<JTD;
	unsigned char a=0;
	DDRC=0xFF;
	DDRD=0x00;
    while(1)
    {
		PORTC=a;
		_delay_ms(500);
		if (!((PIND>>2)&1))
		{
			a++;
			PORTC=a;
			_delay_ms(500);
		}
		if (!((PIND>>3)&1))
		{
			a--;
			PORTC=a;
			_delay_ms(500);
		}
    }
}