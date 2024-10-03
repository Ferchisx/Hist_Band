/*
 * adc.c
 *
 * Created: 7/9/2024 13:35:29
 *  Author: Felipe
 */ 
#include <avr/interrupt.h>
#include "adc.h"

uint16_t sample;

/*The ISR for the ADC0_RESRDY interrupt performs the following tasks:
Clears the Interrupt Flag: The interruption can't be triggered repeatedly until a new condition occurs
Reads the ADC Result: The ADC0 conversion data is stored in the global variable "sample"
Starts a New Conversion: The ISR triggers a new ADC conversion, ensuring that the ADC is 
continuously sampling new data and the process is ongoing.*/
ISR(ADC0_RESRDY_vect)
{
	/* Clear the interrupt flag by writing 1: */
	ADC0.INTFLAGS = ADC_RESRDY_bm;
	
	sample = ADC0.RES;
	
	/* Start conversion */
	ADC0.COMMAND = ADC_STCONV_bm;
}

/*This initialization ensures that the ADC is ready to perform accurate 
conversions and trigger interrupts when new conversion results are available.*/
void ADC0_init(void)
{
	/* Disable digital input buffer */
	PORTA.PIN4CTRL &= ~PORT_ISC_gm;
	PORTA.PIN4CTRL |= PORT_ISC_INPUT_DISABLE_gc;
	
	/* Disable pull-up resistor */
	PORTA.PIN4CTRL &= ~PORT_PULLUPEN_bm;
	
	VREF.CTRLA |= VREF_ADC0REFSEL_2V5_gc;	/* Voltage reference  2.5V */
	VREF.CTRLB |= VREF_ADC0REFEN_bm;		/* Force Voltage reference */
	
	ADC0.CTRLC = ADC_PRESC_DIV8_gc |		/* CLK_PER divided by 8 */
	ADC_REFSEL_INTREF_gc;					/* Internal reference */
	
	ADC0.CTRLA |= ADC_ENABLE_bm |			/* ADC Enable: enabled */
	ADC_RESSEL_10BIT_gc;					/* 10-bit mode */
	
	/* Enable ADC interrupt */
	ADC0.INTCTRL = ADC_RESRDY_bm;
	
	/* Select ADC channel */
	ADC0.MUXPOS = ADC_MUXPOS_AIN4_gc;
}

/*This function is called after initializing the ADC with ADC0_init(void) and whenever we need to initiate a new conversion. 
After starting the conversion, the ADC will sample the input signal, convert it to a digital value, and set an interrupt flag 
(if configured) when the conversion is complete, allowing the program to read the result.*/
void ADC0_start(void)
{
	/* Start conversion */
	ADC0.COMMAND = ADC_STCONV_bm;
}

uint8_t temp_conv(int *temperature){
	*temperature = (sample * 0.1764) - 97.3529;
	return 1;
}