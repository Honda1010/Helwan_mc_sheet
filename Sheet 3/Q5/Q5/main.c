/*
 * main.c
 *
 * Created: 4/20/2024 2:47:25 PM
 *  Author: mohaned
 */ 

#include <xc.h>
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Lib/BITMATH.h"
#include "Lib/ADC_func.h"
int main(void)
{
	DDRC=0xFF;
	DDRD=0xFF;
	uint8_t r=0;
	unsigned int t=0,th,tl;
	unsigned int num[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	ADC_inti();
	while(1)
	{
		r=ADC_read_8bit(0);
		t= 100-(r*0.390625); // (100*5)/(5*256)
		tl=t%10;
		th=t/10;
		PORTC=num[th];
		PORTD=num[tl];
		_delay_ms(100); //hkjh
	}
}