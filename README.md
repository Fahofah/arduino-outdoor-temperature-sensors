# Battery-Powered Thermometer with SD Card Data Logging and RTC

## Overview
This project implements a battery-powered thermometer that measures temperature at regular intervals and logs the data to an SD card. Additionally, it uses an RTC (Real-Time Clock) module to track time accurately and continously (even off-battery). 

The original purpose for this project was aimed at creating a tool to automatically and continually log temperatures during a thermophylic composting process. This process requires the compost to go through certain thermal stages for certain durations to acheive optimal some of the desired results, so this logging can be used to confirm that has taken place and also to analyse behaviour and identify improvements. However, the product can be extended and used in other scenarios if one wishes to.

image here

## Physical Components Used
- Arduino Uno board
- DS18B20 temperature sensor x2
- 4.7K Ohm resistor
- Breadboard (400 point would suffice)
- Jumper wires
- Micro SD TF Memory card reader w/ SPI interface
- RTC (Real-Time Clock) module w/ LIR2032 battery
- M12 Compression cable glands 
- USB Power bank
- 2L leak-proof food container (alterable)
- 3-Pin terminal block x2 (alterable)

## Code Description
The Arduino code for this project initializes the sensors, RTC module, SD card, and other components. It reads temperature data from DS18B20 sensors, timestamps it using the RTC module, and writes it to a CSV file on the SD card. The code includes functions for initializing the components, reading and writing data, and managing the RTC. 

The repo also contains a python script that plots the temperature logs on a timechart (dependency installations are not included).

## Pending improvements 
- error catching/logging
- additional LED indicators
- a button for graceful start/stop
- incorporating a weather api to separately add outside temperature for the timestamps readings were taken, so that it can be added to the timechard/analysis. 

## Setup Instructions
1. Strip the ends of the DS18B20 temperature sensor(s), and screw into the 3-pin terminal block(s). The signal wire requires a 4.7K Ohm resistor connected between the positive wire to produce the signal for reading. 
2. Connect Arduino 5V and GND connection to the associated lines on the breadboard.
3. Connect the RTC module first onto the breadboard, so that it is component on the circuit (had issues when it was not the first, probably could overcome if voltage drops are adjusted). Pin connections -> 
4. Connect the RTC module
5. Upload the provided Arduino code to the Arduino board.
6. Power on the system and monitor the temperature readings on the SD card.

images here

## Additional Notes
- Ensure proper wiring and connections to avoid any malfunctions.
- Monitor the battery voltage periodically and replace batteries as needed.
- Customize the Arduino code as per specific requirements or additional features.

## Author
Fahri Ulucay

## License
Free to use and distribute

