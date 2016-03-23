#include <avr/io.h>

void USART_Init(unsigned int ubrr);

void USART_Transmit(unsigned char data);

unsigned char USART_Receive(void);

void Send_Znak(char znak);

void Send_Word(char *word);

uint8_t Receive_U8(void);