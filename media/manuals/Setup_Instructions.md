# Setup Instructions
Will write detailed instructions so you can build this too


<img src="media/images/1.jpeg" width="100%" height="50%" alt="box_side">


## Physical Components Used
- Arduino Uno board
- DS18B20 temperature sensor x2
- 4.7K Ohm resistor
- Breadboard (400 points would suffice)
- Jumper wires
- Micro SD TF Memory card reader w/ SPI interface
- Micro SD Card (+ adapter if needed for computer connection)
- RTC (Real-Time Clock) module w/ LIR2032 battery
- M12 Compression cable glands 
- USB Power bank
- 2L leak-proof food container (alterable)
- 3-Pin terminal block x2 (alterable)

<img src="media/images/2.jpeg" width="100%" height="100%" alt="box_open">


## Setup Instructions
1. Strip the ends of the DS18B20 temperature sensor(s), and screw into the 3-pin terminal block(s). The signal wire requires a 4.7K Ohm resistor connected in between the positive wire to produce the signal for the reading. 
2. Connect the Arduino 5V and GND connection to the associated lines on the breadboard.
3. Connect the RTC module first onto the breadboard, so that it is a component on the circuit (had issues when it was not the first, but probably could overcome if voltage drops are adjusted). Pin connections -> 
4. Connect the RTC module
5. Upload the provided Arduino code to the Arduino board.
6. Power on the system and monitor the temperature readings on the SD card.

<img src="media/images/3.jpeg" width="50%" height="50%" alt="sensor_wiring">




## Additional Notes
- Ensure proper wiring and connections to avoid any malfunctions.
- Monitor the battery voltage periodically and replace batteries as needed.
- Customize the Arduino code as per specific requirements or additional features.