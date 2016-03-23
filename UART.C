#include "UART.h"

void USART_Init(unsigned int ubrr)
{
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0); //Dwa bity stopu
}


void USART_Transmit(unsigned char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

unsigned char USART_Receive(void)
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void Send_Znak(char znak)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR=znak;
}

void Send_Word(char *word)
{
	int lenght;
	int count=0;
	
	lenght=strlen(word);
	for(count=0;count<lenght;count++){
		Send_Znak(word[count]);
	}
}

uint8_t Receive_U8(void)
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}