/*
 * main.c
 *
 * Created: 2/27/2024 2:18:23 PM
 *  Author: mohaned
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRA=0b00000001;
    while(1)
    {
		if((PINA>>2)&1){
			PORTA=0x01;
		}
	     if((PINA>>3)&1){
			PORTA=0x00;
		}

    }
}