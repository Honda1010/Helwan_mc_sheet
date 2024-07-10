/*
 * CFile1.c
 *
 * Created: 4/24/2024 3:34:52 AM
 *  Author: mohaned
 */ 
#include "lcd.h"

void lcd_init(uint8_t dispAttr) {
	LCD_DDR |= (1 << RS_PIN) | (1 << EN_PIN) | (1 << D4_PIN) | (1 << D5_PIN) | (1 << D6_PIN) | (1 << D7_PIN);
	_delay_ms(15);
	lcd_write_cmd(0x03);
	_delay_ms(5);
	lcd_write_cmd(0x03);
	_delay_us(100);
	lcd_write_cmd(0x03);
	_delay_us(100);
	lcd_write_cmd(0x02);
	_delay_us(100);
	lcd_write_cmd(0x28);
	_delay_us(100);
	lcd_write_cmd(0x08);
	_delay_us(100);
	lcd_clear();
	lcd_write_cmd(0x06);
	_delay_us(100);
	lcd_write_cmd(dispAttr);
}

void lcd_clear() {
	lcd_write_cmd(0x01);
	_delay_us(2000);
}

void lcd_gotoxy(uint8_t x, uint8_t y) {
	uint8_t addr = 0x80;
	if (y == 1) {
		addr |= (0x40 + x);
		} else {
		addr |= x;
	}
	lcd_write_cmd(addr);
}

void lcd_putc(char c) {
	LCD_PORT |= (1 << RS_PIN);
	lcd_write_data(c);
}

void lcd_puts(const char *s) {
	while (*s) {
		lcd_putc(*s++);
	}
}

void lcd_write_cmd(uint8_t cmd) {
	LCD_PORT &= ~(1 << RS_PIN);
	lcd_send_half(cmd >> 4);
	lcd_send_half(cmd);
	_delay_us(100);
}

void lcd_write_data(uint8_t data) {
	LCD_PORT |= (1 << RS_PIN);
	lcd_send_half(data >> 4);
	lcd_send_half(data);
	_delay_us(100);
}

void lcd_send_half(uint8_t value) {
	LCD_PORT = (LCD_PORT & 0x0F) | (value << 4);
	LCD_PORT |= (1 << EN_PIN);
	_delay_us(1);
	LCD_PORT &= ~(1 << EN_PIN);
}

