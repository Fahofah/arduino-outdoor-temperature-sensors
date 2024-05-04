# Battery-Powered Multi-Thermometer with SD Card Data Logging and RTC

## Overview
This project introduces a battery-powered thermometer designed to monitor temperature consistently, recording data onto an SD card. Equipped with an RTC (Real-Time Clock) module, it ensures precise and uninterrupted time tracking, even when not connected to a power source.

The initial intent behind this project was to create a tool for consistent temperature monitoring during thermophilic composting. This process requires precise temperature control for specific time periods to achieve optimal results. The logged data serves the purpose of verifying the efficacy of the composting process and provides insights for potential enhancements. However, the tool's flexibility allows for its application in diverse scenarios beyond composting.

image here

## Physical Components Used
- Arduino Uno board
- DS18B20 temperature sensor x2
- 4.7K Ohm resistor
- Breadboard (400 points would suffice)
- Jumper wires
- Micro SD TF Memory card reader w/ SPI interface
- RTC (Real-Time Clock) module w/ LIR2032 battery
- M12 Compression cable glands 
- USB Power bank
- 2L leak-proof food container (alterable)
- 3-Pin terminal block x2 (alterable)

## Code Description
The Arduino code for this project initializes the sensors, RTC module, SD card, and other components. It reads temperature data from DS18B20 sensors, timestamps it using the RTC module, and writes it to a CSV file on the SD card. The code includes functions for initializing the components, reading and writing data, and managing the RTC. 

### Plotting the Results
The repo also contains a Python script that plots the temperature logs on a time chart (dependency installations are not included).

<img src="media/images/Figure_1.png" width="50%" height="50%" alt="plot_temp_log.py">


## Setup Instructions
1. Strip the ends of the DS18B20 temperature sensor(s), and screw into the 3-pin terminal block(s). The signal wire requires a 4.7K Ohm resistor connected in between the positive wire to produce the signal for the reading. 
2. Connect the Arduino 5V and GND connection to the associated lines on the breadboard.
3. Connect the RTC module first onto the breadboard, so that it is a component on the circuit (had issues when it was not the first, but probably could overcome if voltage drops are adjusted). Pin connections -> 
4. Connect the RTC module
5. Upload the provided Arduino code to the Arduino board.
6. Power on the system and monitor the temperature readings on the SD card.

images here

## Additional Notes
- Ensure proper wiring and connections to avoid any malfunctions.
- Monitor the battery voltage periodically and replace batteries as needed.
- Customize the Arduino code as per specific requirements or additional features.

## Pending improvements 
- error catching/logging
- additional LED indicators
- a button for graceful start/stop
- incorporating a weather API to separately add outside temperature for the timestamp readings taken, so that it can be added to the time chart/analysis. 


## Author
Fahri Ulucay

## License
Free to use and distribute.

