/*
 * main.c
 *
 * Created: 3/17/2024 9:20:24 PM
 *  Author: mohaned
 */ 
#define F_CPU 1000000UL
#define SET_BIT(reg,bit) reg |= (1<<bit)
#define CLR_BIT(reg,bit) reg &= (~(1<<bit))
#define TOG_BIT(reg,bit) reg ^= (1<<bit)
#define GET_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char c=0;
int main(void)
{
	//MCUCR
	//MCUSCR
	//GICR
	//SREG
	DDRC=0xFF;
	SET_BIT(SREG,7);
	SET_BIT(PORTD,2);
	SET_BIT(PORTD,3);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);
	SET_BIT(MCUCR,1);
	
    while(1)
    {
    }
}
ISR(INT0_vect){
	SET_BIT(PORTC,0);
}
ISR(INT1_vect){
	CLR_BIT(PORTC,0);
}