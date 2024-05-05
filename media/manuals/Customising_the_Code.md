# Customising the code
The parameters in the code that you might want to change or adjust.

## Setting the Sensor Labels
Each DS18B20 temperature sensor has a unique id adress to it, and the code uses these ids to translate them into human-friendly names wihle writing to the CSV file - this helps when you have more than one sensor in play and want to identify which reading is from which sensor. 

As the default code uses the IDs of my sensors, you should see UKNOWN_SENSOR appearing as the label for your sensors once you plug everything in and start running. Don;t worry though, it is easy to change these two what you want with the below steps.

1. Locate and uncomment the line of code (currently 95) that will print out to the Serial Monitor the unique ID(s) of your sensor(s).

<img src="/media/images/sensor_addresses_comment.png" width="50%" height="30%" alt="sensor_addresses_comment">

*Uncomment means deleting the leading double slashes //*

<img src="/media/images/sensor_addresses_uncomment.png" width="50%" height="30%" alt="sensor_addresses_uncomment">

2. Upload this version back to the Arduino and check the Serial Monitor for the IDs.

<img src="/media/images/sensor_addresses_output.png" width="100%" height="20%" alt="sensor_addresses_output">

3. Locate the constant setting lines for sensor address(es) (currently 41) and replace the ID(s) there with your ID(s) obtained in the previuos step.

<img src="/media/images/sensor_addresses_variables.png" width="50%" height="40%" alt="sensor_addresses_variables">

4. Now, locate the labelSesor() function (currently line 174) and change the sensor_name values as you like for each sensor ID - these names will be the ones appearing in the CSV and the Serial Monitor. If you have more than 2 sensor duplicate the *else if satetements* for the number of sensor IDs you have.

*Tip: conenct the sensors one by one and mark them with a coloured durable tape on the wire and add comments next to its assoiated address in the code, so it is easier to keep track of what ID/name is assinged to each sensor*

<img src="/media/images/sensor_addresses_labels.png" width="50%" height="20%" alt="sensor_addresses_labels">

5. Not mandatory but you can reverse step 1 and comment back the printing of IDs so there is a cleaner display when serail monitor is used.

6. Once all sensor IDs are registered and you are happy with the names, upload the code back to Ardunio and make sure all running as expected.

## Changing the reading interval and CSV file name
By default the interval for temperature reading is every 30 minutes, you can change this to fit your needs by changing the value for the *reading_delay_minutes*, notice it is expecting the duration in minutes.

The CSV file name has no impact but if you want to change it to something else do so by changing the file_name value. 

<img src="/media/images/delay_and_fileName.png" width="40%" height="20%" alt="delay_and_fileName">

*If you change the file name here and want to use the [Python script](/plot_temp_log.py) to plot the results graph, make sure to match the name in there too.*


<img src="/media/images/sensor_addresses_output.png" width="100%" height="20%" alt="sensor_addresses_output">

## Changing the pin connections

Finally if you decide to use different pin connections for any reason, the two that requires updating is the Signal cable from the temperature sensors and the Chip Select (CS) pin from the SD card module.

Again locate the below variables and change the values accordingly, if needed.

<img src="/media/images/digital_inputs.png" width="50%" height="20%" alt="digital_inputs">



