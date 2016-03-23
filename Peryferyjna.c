/*
 * Peryferyjna.c
 *
 * Created: 12/2/2015 6:55:40 PM
 *  Author: Szymski
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "HD44780.h"
#include "I2C.h"
#include "UART.h"
#include "DS1307.h"
#include "24C16.h"

#define BAUD 2400
#define MYUBRR  F_CPU/BAUD/16-1

//adresy dla ekspandera

volatile unsigned char a=0;

int main(void)
{
	
	uint8_t year=0, month=0, day=0, hour=0, minute=0, second=0;
	char str[16];	
	uint8_t count = 0, men = 0;
		
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXC);	//odblokowanie przerwania z odbiorem na urat
	
	lcd_init();
	USART_Init(MYUBRR);
	initI2C();
	
	LCD_DISPLAY(LCDDISPLAY);
	LCD_CLEAR;
	LCD_LOCATE(0,0);
	lcd_puts("Hello!");	
	
	ds1307_setdate(91, 1, 14, 12, 00, 00);
	
	sei();
	
	while(1)
	{
		ds1307_getdate(&year, &month, &day, &hour, &minute, &second);
		
		if (a == "N")
		{
			LCD_CLEAR;
			men ++;
			_delay_ms(20);
		}
		
		switch(men){
			case 0:
			LCD_LOCATE(5,1);
			lcd_puts(itoa(hour, str, 10));
			lcd_puts(":");
			lcd_puts(itoa(minute, str, 10));
			lcd_puts(":");
			lcd_puts(itoa(second, str, 10));
			lcd_puts(a);
			break;
			case 1:
			LCD_LOCATE(5,1);
			lcd_puts("20");
			lcd_puts(itoa(year, str, 10));
			lcd_puts("-");
			lcd_puts(itoa(month, str, 10));
			lcd_puts("-");
			lcd_puts(itoa(day, str, 10));
			break;
			case 2:
			men = 0;
			break;
		}
		
		if (count == 20)
		{
			Send_Znak(a);
			count=0;
		}
		
		count++;
		
		_delay_ms(50);
	}
}

ISR(USART_RXC_vect)
{
	a =UDR;
}