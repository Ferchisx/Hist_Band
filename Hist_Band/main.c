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

volatile bool state = false; /* The keyword "volatile" tells the compiler not to optimize this variable, 
as it might be changed unexpectedly by something outside the normal program flow, like an interruption.*/
extern uint16_t sample;	//Variable which stores the data read in the ADC
uint8_t countTime;	//Used to count the number of clock cycles in a timer
uint8_t RXBuffer[20];	//Buffer to store data received via communication interfaces

extern bool UART_drdy; //Variable which determines whether the information sent via UART is ready or not to be processed
bool relay_state = false; //Variable to know if the rele is activated or not

ISR(RTC_CNT_vect)
{
	/* Insert your RTC Overflow interrupt handling code */
	state = true;
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
	
	int low_threshold = 20;
	int upper_threshold = 40;
	
	countTime = 0;	//Seconds counter
	char CommCon[40];	//String buffer
	
	memset(CommCon,0,40);	//Cleans the buffer by adding zeros to each position
	sprintf(CommCon, "HisBand Pro 1.0\r\n");
	UART_SendString(CommCon);
	
	/* Enable global interrupt */
	sei();
	
	/* Start a conversion */
	ADC0_start();
	
	/* Replace with your application code */
	while (1)
	{
		if(state) {
			if (countTime == 3) {
				memset(CommCon, 0, 40);
				sprintf(CommCon, "Temperature: %d\r\n", sample);
				UART_SendString(CommCon);
				countTime = 0;
			} else {
				countTime++;
			}
			
			if (sample > upper_threshold && !relay_state) {
				//Activate the relay
				GPIO_relay(true);
				relay_state = true;
				
				//Send activation message
				memset(CommCon, 0, 40);
				sprintf(CommCon, "Relay Turned ON-Temperature: %d\r\n",sample);
				UART_SendString(CommCon);
			} else if (sample < low_threshold && relay_state) {
				//Deactivate the relay
				GPIO_relay(false);
				relay_state = false;
			
				//Send deactivation message
				memset(CommCon, 0, 40);
				sprintf(CommCon, "Relay Turned OFF-Temperature: %d\r\n",sample);
				UART_SendString(CommCon);
			}
			
			if (UART_drdy)
			{
				//Get the new values for low and upper threshold
				data_process(&low_threshold, &upper_threshold);
			}
			state = false;
		}
	}
}