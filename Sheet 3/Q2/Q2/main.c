/*
 * main.c
 *
 * Created: 4/20/2024 12:35:01 PM
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
	int vi=0;
	float v=0.0,vf;
	unsigned int num[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	ADC_inti();
    while(1)
    {
		r=ADC_read_8bit(0);
		v= (r*5.0)/255;
		vi=(int)v;
		vf=v-vi;
		PORTC=num[vi];
		PORTD=num[(int)(vf*10)];
		_delay_ms(500);
    }
}