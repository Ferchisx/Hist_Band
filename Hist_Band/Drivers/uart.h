/*
 * uart.h
 *
 * Created: 7/9/2024 14:30:27
 *  Author: Felipe
 */ 
/*
Library function: Initialize and configure an operation to define the necessary BAUD_RATE in the UART

USART0_BAUD_RATE: Depending on the BAUD_RATE given, configures the Baud Rate of the USART taking into account a 1MHz clock
UART_init(): Initializes the UART, sets up the data format (8 bits, no parity, 1 stop bit), and enables the transmitter.
UART_SendString(const char *str): Sends a null-terminated string over UART by transmitting each character one at a time, 
waiting for the UART to be ready for each byte.
data_process: When a flag is activated take the data received and define new threshold values
*/

#ifndef UART_H_
#define UART_H_

#include <stdbool.h>
#include <stdlib.h>
#include <avr/io.h>

/* Normal Mode, Baud register value */
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(1000000 * 64 / (16 * (float)BAUD_RATE)) + 0.5)

void UART_init();
void UART_SendString(const char *str);
uint8_t data_process();

#endif /* UART_H_ */