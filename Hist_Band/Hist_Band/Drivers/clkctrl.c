/*
 * clkctrl.c
 *
 * Created: 7/9/2024 10:50:27
 *  Author: Felipe
 */ 
#include <avr/io.h>
#include <avr/xmega.h>
#include "clkctrl.h"

/* The CLKCTRL_init() function configures the clock system as follows:
It sets the clock prescaler to divide the system clock by 8 and enables the prescaler.
It configures the 20 MHz internal oscillator as the clock source and disables clock output to external pins.
It waits until the clock system has stabilized and the changes are applied. */
void CLKCTRL_init(void)
{
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, CLKCTRL_PDIV_8X_gc | CLKCTRL_PEN_bm);
	_PROTECTED_WRITE(CLKCTRL.MCLKCTRLA, !CLKCTRL_CLKOUT_bm | CLKCTRL_CLKSEL_OSC20M_gc);
	while (!(CLKCTRL.MCLKSTATUS));
}

/* The RTC_init() function configures the Real-Time Clock (RTC) as follows:
It sets the prescaler to divide the clock by 512, enabling the RTC, but disables its operation during standby mode.
It sets the period value to 0x44 (68 decimal), meaning the RTC will generate an overflow event after counting to this value.
It enables the overflow interrupt, so that an interrupt is triggered when the RTC overflows,
while disabling the compare match interrupt. */
void RTC_init(void)
{
	RTC.CTRLA = RTC_PRESCALER_DIV512_gc /* 512 */
	| 1 << RTC_RTCEN_bp     /* Enable: enabled */
	| 0 << RTC_RUNSTDBY_bp; /* Run In Standby: disabled */

	RTC.PER = 0x44; /* Period: 0xd */

	RTC.INTCTRL = 0 << RTC_CMP_bp    /* Compare Match Interrupt enable: disabled */
	| 1 << RTC_OVF_bp; /* Overflow Interrupt enable: enabled */
}