/*
 * Hist_Band.c
 *
 * Created: 7/9/2024 10:28:43
 * Author : Felipe
 */ 
/*
Library inclusion:

avr/io.h: This header file includes the appropriate IO definitions for the selected device
avr/interrupt.h: Used for managing and handling interrupts. Provides macros and functions that enable, 
disable, and define interrupt service routines (ISRs)
stdio.h: Provides functions for input and output operations
string.h: Provides functions for manipulating strings (character arrays) and memory blocks
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include "adc.h"
#include "clkctrl.h"
#include "gpio.h"
#include "uart.h"

volatile bool drdy = false; /* The keyword "volatile" tells the compiler not to optimize this variable, 
as it might be changed unexpectedly by something outside the normal program flow, like an interruption.
The variable drdy is a short for "data ready", express with True or False if the data is ready to be processed */
uint8_t countTime;	//Used to count the number of clock cycles in a timer
uint16_t sample;	//Variable which stores the data read in the ADC
uint8_t RXBuffer[20];	//Buffer to store data received via communication interfaces

ISR(RTC_CNT_vect)
{
	/* Insert your RTC Overflow interrupt handling code */
	drdy = true;
	/* Overflow interrupt flag has to be cleared manually */
	RTC.INTFLAGS = RTC_OVF_bm;
}

int main(void)
{
	/* Configure modules, Initialize all needed functions */
	CLKCTRL_init();
	RTC_init();
	ADC0_init();
	GPIO_init();
	UART_init();
	
	countTime = 0;
	char CommCon[40];
	
	memset(CommCon,0,40);
	sprintf(CommCon, "HisBand Pro 1.0\r\n");
	UART_SendString(CommCon);
	
	/* Enable global interrupt */
	sei();
	
	/* Start a conversion */
	ADC0_start();
	
	//GPIO_relay(true);
	//GPIO_relay(false);
	
	/* Replace with your application code */
	while (1)
	{
		if(drdy)
		{
			if (countTime == 1) {
				memset(CommCon,0,40);
				sprintf(CommCon,"Temperature: %d\r\n", sample);
				UART_SendString(CommCon);
				countTime++;
				} else if(countTime == 3) {
				countTime = 0;
				} else {
				countTime++;
			}
			
			drdy = false;
		}
	}
}