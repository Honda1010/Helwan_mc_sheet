/*
 * ADC_func.c
 *
 * Created: 4/20/2024 12:56:45 PM
 *  Author: mohaned
 */ 
#include <avr/io.h>
#include "BITMATH.h"
void ADC_inti(){
	SET_BIT(ADMUX,REFS0); // AVCC to AREF
	SET_BIT(ADCSRA,ADPS0); // Choose prescalar
	SET_BIT(ADCSRA,ADPS1); // Choose prescalar
	SET_BIT(ADCSRA,ADEN); //Enable ADC
}
uint8_t ADC_read_8bit(uint8_t ch){
	SET_BIT(ADMUX,ADLAR);
	ADMUX &= 0xE0;
	ADMUX |=ch; // Choose Channal
	SET_BIT(ADCSRA,ADSC); // start conversion
	while(GET_BIT(ADCSRA,ADSC)==1);
	return ADCH;
}
uint16_t ADC_read_10bit(uint8_t ch){
	ADMUX &= 0xE0;
	ADMUX |=ch; // Choose Channal
	SET_BIT(ADCSRA,ADSC); // start conversion
	while(GET_BIT(ADCSRA,ADSC)==1);
	return ADC;
}