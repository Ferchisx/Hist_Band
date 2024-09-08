/*
 * clkctrl.h
 *
 * Created: 7/9/2024 10:50:13
 *  Author: Felipe
 */ 
/*
Library function: Initialize the Clock Control and the Real-Time Clock

CLKCTRL_init: Initializes and configures the system clock settings.
RTC_init: Sets up the real-time clock for timekeeping tasks.
*/

#ifndef CLKCTRL_H_
#define CLKCTRL_H_

void CLKCTRL_init(void);
void RTC_init(void);

#endif /* CLKCTRL_H_ */