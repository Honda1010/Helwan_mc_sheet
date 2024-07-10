/*
 * main.c
 *
 * Created: 2/27/2024 5:29:16 PM
 *  Author: mohaned
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	unsigned char a=0,b=0,d=0;
	DDRA=0b00001111;
	DDRB=0x0F;
	DDRD=0x0F;
    while(1)
    {
		PORTA=a;
		_delay_ms(500);
		PORTB=b;//0 1 2 3 4 5 6 7
		_delay_ms(500);
		PORTD=d;
		_delay_ms(500);
		if ((PINA>>4)&1)
		{
			a++;
			if (a>9)
			{
				b++;
			}
			if (b>9)
			{
				d++;
			}	
		}
		if ((PINA>>6)&1)
		{
			a--;
		}
    }
}