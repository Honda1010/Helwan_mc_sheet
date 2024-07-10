/*
 * main.c
 *
 * Created: 2/27/2024 6:47:05 PM
 *  Author: mohaned
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
volatile int counter;
void start(){
	counter=0;
	PORTA=0b00001100;
	_delay_ms(500);
}
int main(void)
{
	// 0 red
	//1 bazzar
	// 2 green 
	// 3 motor
	// 4 sensor
	// 5 start
DDRA=0x0F;
    while(1)
    {
		if ((PINA>>4)&1) // sensor
		{
			counter++;
			_delay_ms(500);
		}
        if (counter==12) // stop
        {
			PORTA=0b00000011;
			_delay_ms(500);
        }
		if ((PINA>>5)&1)
		{
			start();
		}
    }
}