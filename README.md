# Hist_Band
This repository will contain a project in Microchip Studio to control a hysteresis band using the ATTINY424 microcontroller 

# Explanation
The hysteresis band works taking 2 thresholds (low and upper) and keeping the temperature in a box between this band. It is
made with 5 modules: Sensor, Step-Up, Microcontroller, Communications and Output.

![image](https://github.com/user-attachments/assets/66091c55-ece7-474b-8195-b073e385dce6)

# Modules:
 - Sensor: By using a thermoresistor we collect the information of temperature from inside a box, the box has a fan and a halogen lamp
 - Step-Up: The information is received in form of voltage, we use this module to increase the voltage to send it between the necessary
   values of the microcontroller pins (taking into account the references values in voltage,  2.5V)
 - Microcontroller: We use Microchip Studio to programm the ATTINY (see information below), receiving information via UART from the
   communication module, switching the relay based on the temperature level and sending information to a console
 - Communication: Via bluetooth we send the threshold values we want to this module, then we send it to the micro
 - Output: After reading and processing all the data in the micro, the relay is switched, changing the state in the box. If the lamp is
   activated and the temperature surprasses the upper threshold, it switches and turns off the lamp and turns on the fan. Inversly, if
   the lower threshold is surprassed, the lamp is activated, the fan turns off.

# ATTINY information:
This microcontroller is part of the tinyAVR2 family, it uses an AVR CPU with hardware multiplier

Memory Overview:
  - Flash memory --> 4Kb
  - SRAM     ------> 512B
  - EEPROM    -----> 128B
  - User Row    --->32B

Peripheral Oveview:
  - 14 pins
  - TSSOP,SSOP package
  - Maximum frequency = 20MHz
  - PORTS: ·PA[7:0]
           ·PB[3:0]
  - 12 external interrupts
  - 6 event system channels
  - 1 Real-Time Counter (RTC)
  - 2 USART/SPI host
  - 1 SPI
  - 1 TWI (I2C)
  - 1 ADC channel
