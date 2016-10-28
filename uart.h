/*
 * uart.h
 *
 * Created: 10-04-2012 14:35:40
 *  Author: kela
 */


#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#define ENABLE_UART_INT UCSRB |= (1<<RXCIE)

int put_uart_char(char c, FILE *fd);

//No need to call this function directly, it's just here for printf().
//Outputs a single character to the UART when the transmit buffer is empty.
//This is the function that we bind to printf so it can output the string
//that printf generates. The FILE parameter is required by printf for behind-
//the-scenes bookkeeping. *Note that we can write a function that will put a
//single char anywhere we want -- parallel interface, SPI, I2C, etc.*

void uart_init9600(void);
void uart_init19200(void);

//Set up the registers that control the UART and bind put_uart_char
//as our output function.


char USARTReadChar();
void USARTWriteChar(char data);
void USARTInit(uint16_t ubrr_value);
#endif