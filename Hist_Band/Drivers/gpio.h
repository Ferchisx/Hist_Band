/*
 * gpio.h
 *
 * Created: 7/9/2024 14:13:09
 *  Author: Felipe
 */ 
/*
Library function: Initialize the connections with the GPIO and its relay

GPIO_init: Initializes a GPIO pin for controlling the relay (typically setting it as an output).
GPIO_relay(bool active): Controls the relay state based on the active parameter. 
If true, the relay is turned on; if false, the relay is turned off.
*/

#ifndef GPIO_H_
#define GPIO_H_

void GPIO_init(void);
void GPIO_relay(bool active);

#endif /* GPIO_H_ */