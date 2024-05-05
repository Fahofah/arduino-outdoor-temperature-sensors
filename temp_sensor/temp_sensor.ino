/* 
Author: Fahri Ulucay
Purpose: Take temperature readings from DS3231 sensors at set intervals and write to an SD card. 
         Also, incoprorates RTC for off power time continuation. 
First prod release date: 31.03.2024
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <SD.h>
#include <SPI.h>
#include <RTClib.h>
#include <Wire.h>



// Digital inputs
#define TempSensors 8
const int chipSelect = 10;

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(TempSensors);	

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

// Shared variables and constants
String sensor1_tempC;
String sensor2_tempC;
String reading_timestamp; 
File myFile;

long reading_delay_minutes = 30; 
const String file_name = "temp.csv";

// real-time-clock setup
RTC_DS3231 rtc;
String reading_time;

int tempSensorCount = 0;
const String Sensor1Address = "28e94fcfb121064b"; // long cables (lower) 
const String Sensor2Address = "28b72bf5b121062b"; // short cables (upper) - taped 

void setup(void)
{
  sensors.begin();	// Start up the library
  Wire.begin();
  rtc.begin();
  Serial.begin(9600);
  
  Serial.println("#######################################");
  Serial.println();
  // locate devices on the bus
  Serial.print("Locating temperature sensor(s)...");
  Serial.print("Found ");
  tempSensorCount = sensors.getDeviceCount();
  Serial.print(tempSensorCount, DEC);
  Serial.println(" temp sensors.");

  Serial.print("Initializing SD card...");
  /*Check if the SD card exist or not*/
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    while (1);
  }
  else {
    Serial.println("initialization done.");
    delay(100);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  Serial.println();
  Serial.println("#######################################");
  Serial.println();
}

void loop(void)
{ 
   // Get recording time
  reading_time = getTime();
  
  // Send command to all the sensors for new temperature readings
  sensors.requestTemperatures(); 

  // iterate through the detected sensors and execute write functions for the readings
  for(int i=0; i < tempSensorCount ; i++){
    DeviceAddress sensorAddress;
    sensors.getAddress(sensorAddress, i);

    //Uncomment the below during first setup for sensor labelling
    //Serial.println(addressString(sensorAddress));

    // Read temperature from the sensor and write to SD
    writeTempRecord(sensorAddress, reading_time, file_name);
  }

  // display file - useful for quick debugging
  //readSD(myFileName);

  // Wait for the specified period
  delay(reading_delay_minutes * 60000);
}

void writeTempRecord(DeviceAddress sensor, String reading_timestamp, String fileName)
{
  myFile = SD.open(fileName, FILE_WRITE);

  String sensor_tempC = String(sensors.getTempC(sensor),1);
  String sensor_name = labelSensor(sensor);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing ");
    Serial.print(sensor_name);
    Serial.print(" ");
    Serial.print(sensor_tempC); 
    Serial.print(" into "); 
    Serial.print(fileName);
    Serial.print(" ...");

    myFile.print(reading_timestamp);
    myFile.print(",");
    myFile.print(sensor_name);
    myFile.print(",");
    myFile.println(sensor_tempC);

    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening " + fileName);
  }

}

void readSD(String fileName)
{
  // open the file for reading:
  myFile = SD.open(fileName);
  if (myFile) {
    Serial.println(fileName + ":");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening " + fileName);
  }
}

String addressString(DeviceAddress deviceAddress) {
  // Create a String to store the converted address
  String address_string = "";

  // Convert each byte of the address to a two-digit hexadecimal string
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) {
      address_string += "0";  // Add leading zero for single-digit values
    }
    address_string += String(deviceAddress[i], HEX);
  }

  return address_string;
}

String labelSensor(DeviceAddress sensor)
{
  String sensor_id = addressString(sensor);
  String sensor_name;

  if (sensor_id.equals(Sensor1Address)){
      sensor_name = "INNER";
  } else if (sensor_id.equals(Sensor2Address)){
      sensor_name = "OUTER";
  } else {
      sensor_name = "UNKNOWN_SENSOR";
  }

  return sensor_name;
}

String getTime(){
  char dt[32];
  DateTime now = rtc.now();
  sprintf(dt, "%02d:%02d:00 %02d/%02d/%02d", now.hour(), now.minute(), now.day(), now.month(), now.year()); 
  return String(dt); 
}


