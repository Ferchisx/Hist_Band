/*
 * gpio.c
 *
 * Created: 7/9/2024 14:16:37
 *  Author: Felipe
 */ 
#include <avr/io.h>
#include <stdbool.h>
#include "gpio.h"

/*This function looks for the direction of PORTA and configures its pin 2 as an output pin*/
void GPIO_init(void)
{
	PORTA.DIR |= PIN2_bm;
}

/*This function takes the active value (True or False) to work like:
If active = true, the relay is turned on by setting the output of pin 2 to HIGH.
If active = false, the relay is turned off by setting the output of pin 2 to LOW.*/
void GPIO_relay(bool active)
{
	if(active) {
		PORTA.OUT |= PIN2_bm;
		} else {
		PORTA.OUT &= ~PIN2_bm;
	}
}