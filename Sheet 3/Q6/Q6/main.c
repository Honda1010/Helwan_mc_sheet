/*
 * main.c
 *
 * Created: 4/24/2024 10:46:56 AM
 *  Author: mohaned
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include "ADC/ADC_func.h"
#include "Lib/BITMATH.h"
#define F_CPU 16000000UL
int main(void)
{   DDRA=0x00;
	DDRC=0X0F;
	ADC_inti();
	uint16_t t;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    while(1)
    {
		t=(ADC_read_10bit(0)*500)/1023;
      if (t<=30)
      {
		  SET_BIT(PORTC,0);
		  CLR_BIT(PORTC,1);
		  CLR_BIT(PORTC,2);
		  
      }
	  else if ((t>=30)&(t<=35))
	  {
		  SET_BIT(PORTC,1);
		  CLR_BIT(PORTC,0);
		  CLR_BIT(PORTC,2);
	  }
	  else if (t>35)
	  {
		  SET_BIT(PORTC,2);
		  CLR_BIT(PORTC,1);
		  CLR_BIT(PORTC,0);
	  }
    }
}