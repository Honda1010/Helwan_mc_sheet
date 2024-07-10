/*
 * main.c
 *
 * Created: 3/17/2024 9:20:24 PM
 *  Author: mohaned
 */ 
#define F_CPU 1600000UL
#define SET_BIT(reg,bit) reg |= (1<<bit)
#define CLR_BIT(reg,bit) reg &= (~(1<<bit))
#define TOG_BIT(reg,bit) reg ^= (1<<bit)
#define GET_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char c=9,b=0,a=0;
int main(void)
{
	//MCUCR
	//MCUSCR
	//GICR
	//SREG
	DDRC=0xFF;
	DDRA=0xFF;
	DDRD=0x03;
	SET_BIT(SREG,7);
	SET_BIT(PORTC,1);// green led
	SET_BIT(PORTD,2);// internal pullup
	SET_BIT(PORTD,3);// internal pullup
	SET_BIT(GICR,6); 
	SET_BIT(GICR,7);
	SET_BIT(MCUCR,1); // failing edge int0
	SET_BIT(MCUCR,3); // failing edge int1
	SET_BIT(PORTC,6);
	SET_BIT(PORTC,7);
	unsigned int num[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    while(1)
    {
	PORTA=num[c]*2;
	if (c==0)
	{
		CLR_BIT(PORTC,1);
	 SET_BIT(PORTC,0);	
	 
	}

    }
}
ISR(INT0_vect){
		c++;
}
ISR(INT1_vect){
		c--;
}