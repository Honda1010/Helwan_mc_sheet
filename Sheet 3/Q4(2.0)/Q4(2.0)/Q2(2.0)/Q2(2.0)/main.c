/*
 * Q4(2.0).c
 *
 * Created: 4/13/2024 4:20:05 PM
 *  Author: Mohaned
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include "ADC//ADC_func.h"
#include "LCD/Lcd.h"
#include <util/delay.h>
unsigned short t = 9999;
int main(void)
{
	lcd_vinit();
	ADC_inti();
	lcd_vsend_string("Temperature=");
    while(1)
    {	
// 		if((ADC_read_10bit(0)*500)/1023!=t)))
// 		{
			t=((ADC_read_10bit(0)*500)/1023);
			
			if(t<10)
			{
				lcd_move_cursor(0,12);
				lcd_vsend_char(t+48);
				lcd_vsend_char(0xDF);
				lcd_vsend_char('C');
				lcd_move_cursor(1,0);
				lcd_vsend_char(0x20);
			}
			else if((t<100)&(t>9))
			{
				lcd_move_cursor(0,12);
				lcd_vsend_char((t/10)+48);
				lcd_vsend_char((t%10)+48);
				lcd_vsend_char(0xDF);
				lcd_vsend_char('C');
				lcd_move_cursor(1,0);
				lcd_vsend_char(0x20);
			}
			else if((t<=150)&(t>99))
			{
				lcd_move_cursor(0,12);
				lcd_vsend_char((t/100)+48);
				lcd_vsend_char(((t/10)%10)+48);
				lcd_vsend_char((t%10)+48);
				lcd_vsend_char(0xDF);
				lcd_move_cursor(1,0);
				lcd_vsend_char('C');
			}
		
			
		}	
				
		_delay_ms(1000);
  /*  }*/
}