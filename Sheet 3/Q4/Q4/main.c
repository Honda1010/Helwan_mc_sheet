/*
 * main.c
 *
 * Created: 4/23/2024 6:08:20 PM
 *  Author: mohaned
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA PORTB
#define en PA6
#define rw PA5
#define rs PA4

void init_lcd();
void LCD_cmd(unsigned char cmd);
int main(void)
{
	DDRB=0xFF;
	DDRA=0xFF;
	init_lcd();
	_delay_ms(100);
	LCD_cmd(0x0C); // display on, cursor off
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
void init_lcd(){
	LCD_cmd(0x38); // initialization of 16x2 in 8bit mode
	_delay_ms(1);
	LCD_cmd(0x01);
}