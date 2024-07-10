/*
 * LCD.h
 *
 * Created: 4/24/2024 3:36:12 AM
 *  Author: mohaned
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>

// Define LCD port and control pins
#define LCD_PORT PORTC
#define LCD_DDR DDRC
#define RS_PIN PC1
#define EN_PIN PC2
#define D4_PIN PC3
#define D5_PIN PC4
#define D6_PIN PC5
#define D7_PIN PC6

// Function prototypes
void lcd_init(uint8_t dispAttr);
void lcd_clear();
void lcd_gotoxy(uint8_t x, uint8_t y);
void lcd_putc(char c);
void lcd_puts(const char *s);

#endif /* LCD_H_ */