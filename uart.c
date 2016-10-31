/*
 * uart.c
 *
 * Created: 10-04-2012 14:35:58
 *  Author: kela
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart.h"

//Call fdevopen. This is what binds printf to put_uart_char. The first
//parameter is the address of our function that will output a single
//character, the second parameter is an optional parameter that is
//used for get functions, ie. receiving a character from the UART.
//This is the function that uses malloc.
#define PRINTF_REDIRECT_TO_UART fdevopen(&put_uart_char, NULL)

//This function is used to read the available data
//from USART. This function will wait untill data is
//available.
char USARTReadChar()
{
    //Wait untill a data is available

    while (!(UCSRA & (1 << RXC))) {
        //Do nothing
    }

    //Now USART has got data from host
    //and is available is buffer

    return UDR;
}

//This fuction writes the given "data" to
//the USART which then transmit it via TX line
void USARTWriteChar(char data)
{
    //Wait untill the transmitter is ready

    while (!(UCSRA & (1 << UDRE))) {
        //Do nothing
    }

    //Now write the data to USART buffer

    UDR = data;
}

//print f handle
int put_uart_char(char c, FILE* fd)
{
    USARTWriteChar(c);
    return 0;
}

void uart_init9600(void)
{
    //http://extremeelectronics.co.in/avr-tutorials/using-the-usart-of-avr-microcontrollers-reading-and-writing-data/
    //UART Init
    UCSRB |= (1 << TXEN) | (1 << RXEN) | (1 << RXCIE); //Enable  Transmit,  Receive, Receive Interrupt
    UCSRC |= (1 << UCSZ1) | (1 << UCSZ0); //8 bit character size.

#define BAUD 9600
#include <util/setbaud.h>
    UBRRH = UBRRH_VALUE;
    UBRRL = UBRRL_VALUE;
#if USE_2X
    UCSRA |= (1 << U2X);
#else
    UCSRA &= ~(1 << U2X);
#endif

    PRINTF_REDIRECT_TO_UART;
}

//#pragma warning(disable:4700)
void uart_init19200(void)
{
    //http://extremeelectronics.co.in/avr-tutorials/using-the-usart-of-avr-microcontrollers-reading-and-writing-data/
    //UART Init
    UCSRB |= (1 << TXEN) | (1 << RXEN) | (1 << RXCIE); //Enable  Transmit,  Receive, Receive Interrupt
    UCSRC |= (1 << UCSZ1) | (1 << UCSZ0); //8 bit character size.

#define BAUD 19200
#include <util/setbaud.h>
    UBRRH = UBRRH_VALUE;
    UBRRL = UBRRL_VALUE;
#if USE_2X
    UCSRA |= (1 << U2X);
#else
    UCSRA &= ~(1 << U2X);
#endif

    PRINTF_REDIRECT_TO_UART;
}

//This function is used to initialize the USART
//at a given UBRR value
void USARTInit(uint16_t ubrr_value)
{
    //Set Baud rate
    UBRRL = ubrr_value;
    UBRRH = (ubrr_value >> 8);
    /*Set Frame Format
	>> Asynchronous mode
	>> No Parity
	>> 1 StopBit
	>> char size 8
	*/
    UCSRC = (1 << URSEL) | (3 << UCSZ0);
    //Enable The receiver and transmitter
    UCSRB = (1 << RXEN) | (1 << TXEN);

    PRINTF_REDIRECT_TO_UART;
}