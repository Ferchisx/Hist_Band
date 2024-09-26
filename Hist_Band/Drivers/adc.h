/*
 * adc.h
 *
 * Created: 7/9/2024 13:35:19
 *  Author: Felipe
 */ 
/*
Library function: Initializes the Analog-Digital Converter

stdint.h: Ensures access to standard, fixed-width integer types like uint8_t, int16_t
stdbool.h: Provides a standardized way to use Boolean types (true, false)
ADC0_init: Function that initializes the ADC0 hardware
ADC0_start: Function that starts a new ADC conversion using ADC0 (Analog-Digital Converter)
temp_conv: Takes the digital value after the ADC and converts it into the respective temperature value
*/

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <stdbool.h>

void ADC0_init(void);
void ADC0_start(void);
uint8_t temp_conv(int *temperature);

#endif /* ADC_H_ */