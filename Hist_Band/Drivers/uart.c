/*
 * uart.c
 *
 * Created: 7/9/2024 14:43:45
 *  Author: Felipe
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"

/*RXBuffer[20] is an external array where received data from UART is stored. It's declared with extern to indicate it's defined elsewhere.
rx_index = 0 is used to keep track of the current index in RXBuffer, helping to manage where the next received byte should be stored.*/
extern uint8_t RXBuffer[20];
uint8_t rx_index = 0;
bool UART_drdy = false;
const char delim[8] = "AIMNX:,";

/*This function initializes the UART with the necessary parameters like baud rate, and activating both
Receiver and Transmitter so it can get and send data though the same UART*/
void UART_init()
{

	USART0.BAUD = (uint16_t)USART0_BAUD_RATE(9600); /* set baud rate register */

	USART0.CTRLA = USART_RXCIE_bm;  /* Receive Complete Interrupt Enable: enabled */
	
	USART0.CTRLB = USART_RXEN_bm |    /* Receiver Enable: enabled */
	USART_TXEN_bm;    /* Transmitter Enable: enabled */
	
	/* Set TxD (PB2) as output */
	PORTB.DIR |= PIN2_bm;
}

/*This function takes a string and sends each character over UART until it reaches the end of the string (null terminator).
It ensures that each byte is sent only when the transmit buffer is empty and 
waits for the entire transmission to complete before clearing the corresponding flag.*/
void UART_SendString(const char *str)
{
	while (*str != '\0')
	{
		while (!(USART0.STATUS & USART_DREIF_bm)); //wait until Tx buffer is empty
		
		USART0.TXDATAL = *str;
		str++;
	}
	while (!(USART0.STATUS & USART_TXCIF_bm)); //wait until Tx finished
	
	USART0.STATUS |= USART_TXCIF_bm;
}


/*The ISR is triggered when data is received by USART0.
It stores the received byte in RXBuffer at the current rx_index.
The code checks if the byte is a newline (0x0A) or if the buffer is full. If either is true, the rx_index is reset to 0 
to prepare for the next message. Otherwise, the rx_index is incremented to store the next byte in the buffer.
The commented DataRDY = true; line is used to indicate when a complete message has been received.*/
ISR(USART0_RXC_vect)
{
	RXBuffer[rx_index] = USART0.RXDATAL;
	
	if((RXBuffer[rx_index] == 0x0A) || (rx_index == 19)) {
		UART_drdy = true;
		rx_index = 0;
		} else {
		rx_index++;
	}
}

/*This function was made to receive the data sent via UART after taking the string from the Bluetooth module, it takes the
string and divides it to look for a number to convert thanks to the ATOI function, saving the numeric values into the pointers
of my low and upper threshold, returning both to the main.c and printing correct execution when checking the control flag*/
uint8_t data_process(int *lower_threshold, int *upper_threshold){
	int control = 0;
	char *token = strtok((char *)RXBuffer, delim);
	if (token != NULL){
		*lower_threshold = atoi(token);
		control++;
	}
	token = strtok(NULL, delim);
	if (token != NULL){
		*upper_threshold = atoi(token);
		control++;
	}
	if (control == 2){
		return 1;
	}else{
		UART_SendString("Error en la obtención de datos");
		return 0;
	}
}