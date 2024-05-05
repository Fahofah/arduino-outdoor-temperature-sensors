# Setup Instructions
This guide serves as a flexible reference for setting up a portable weatherproof multi-sensor temperature logger for yourself. Feel free to adapt the components and approaches to suit your needs.


<img src="/media/images/1.jpeg" width="100%" height="50%" alt="box_side">


## What You'll Need

- Arduino Uno board
- DS18B20 temperature sensor(s)
- 4.7K Ohm resistor
- Breadboard (400 points minimum)
- Jumper wires
- Micro SD card reader with SPI interface
- Micro SD card (and adapter if needed)
- RTC (Real-Time Clock) module with LIR2032 battery
- M12 Compression cable glands 
- USB power bank
- 2L leak-proof food container (modifiable)
- 3-Pin terminal block (modifiable)


## Setup Instructions
Please note that you can customize these instructions to better suit your setup. However, ensure to update the pin connections in the code accordingly. Refer to the [Customizing the Code](media/manuals/Customising_the_Code.md) document for details.

### Electronics

1. Begin by connecting the RTC module to the breadboard. Ensure it is the first component on the circuit as it didn't work for me otherwise - probably can fix it with better voltage adjustments but a quick workaround was making it the first component on the ciruit.

   - **Pin Connections:**
     - VCC to positive terminal (breadboard)
     - GND to negative terminal (breadboard)
     - SDA to A5 (Arduino Analog Input)
     - SCL to A4 (Arduino Analog Input)

2. Strip the ends of the DS18B20 temperature sensor wires and attach them to the 3-pin terminal block(s). This step may require careful wiring.

   - **Wire Connections:**
     - Yellow (Signal) to D8 (Arduino Digital Input)
     - Red to positive terminal (breadboard)
     - Black/Brown to negative terminal (breadboard)

3. Connect the SD card module.

   - **Pin Connections:**
     - VCC to positive terminal (breadboard)
     - GND to negative terminal (breadboard)
     - SO to D12 (Arduino Digital Input)
     - SI to D11 (Arduino Digital Input)
     - SCK to D13 (Arduino Digital Input)
     - CS to D10 (Arduino Digital Input)

4. Connect the Arduino's 5V pin to the positive and GND pin to the negative terminal of the breadboard.

Close-up of the breadboard wiring at this stage:

<img src="/media/images/wiring_closeup.jpg" width="100%" height="20%" alt="wiring_closeup">


5. Connect the Arduino to your computer via USB and upload the provided [Arduino code](/temp_sensor/temp_sensor.ino) using [Arduino IDE](https://www.arduino.cc/en/software).

6. After uploading successfully, open the [Serial Monitor](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) to make sure everything is working as expected. You should see some messages appearing on the Serial Monitor confirming the setup. If you have a different number of sensors or if it's the first time setting up the RTC, the messages might vary slightly, but look out for key messages like "sensor found," "SD initialization," and "successful write."

<img src="/media/images/serialMonitor.png" width="100%" height="20%" alt="upload_success">


### Enclosure

When wired neatly, all components fit onto the half of a 800 pin breadboard so a 400 pin breadboard would be sufficient, but I ended up using the empty half of my 800 pin breadboard as a place to secure the Arduino unit itself - there are no conenctions from the unit directly to the board apart from the above mentioned conenctions through jumper wires.

1. Find a suitable weatherproof container that will fit your components. I used a leak-proof food box as it was cost-effective, provided very easy access, and transperency was a plus to see the remaining battery without opening it. Make sure to consider anything you might want to add/change later on and factor these in for the size you will go for. 

2. Position your components into the chosen box and decide what are the best positions. Once decided, use the *screws*
of the cable galnds to mark the circles for where the sensor cable(s) will pass through. Carefully drill through these to create a nice clean opening and install the cable glands into place. Take the cable(s) through the gland(s) and tighthen the glands to estanlish a solid weatherproof connection. 

3. Place the power bank into it's position and connect it to the Arduino unit using a USB cable - a 90 degree angled one can work better here. 


<img src="/media/images/2.jpeg" width="100%" height="30%" alt="box_open">



4. Close the lid and you have your portable weatherproof tempereture logger ready to go! 



## Additional Notes
- Ensure proper wiring and connections to avoid any malfunctions.
- The number of DS18B20 temperature sensors can be increased or decreased as per your requirements - just keep adding the sensors in series and modify the box and [code](media/manuals/Customising_the_Code.md) as needed.
- The power bank I used displays remianing battery when in-use ,so it didn't require any further solution to track when it needs swapping (for long operation period). If you don't have one with that feature it could be possible to implement other solutions using some other components in between and extra code to indicate low battery. 
- Customize the [Arduino code](/temp_sensor/temp_sensor.ino) as per specific requirements or additional features.