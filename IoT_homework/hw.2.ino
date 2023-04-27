#include <Wire.h>
#include <SeeedOLED.h>
#include "Ultrasonic.h"
//#include <avr/pgmspace.h>
#define LIGHT_SENSOR A0//Grove - Light Sensor is connected to A0 of Arduino

const int ledPin=12;                 //Connect the LED Grove module to Pin12, Digital 12
const int thresholdvalue=10;         //The treshold for which the LED should turn on. Setting it lower will make it go on at more light, higher for more darkness
float Rsensor; //Resistance of sensor in K
Ultrasonic ultrasonic(2);

void setup()
{
  Serial.begin(9600);                //Start the Serial connection
    pinMode(ledPin,OUTPUT);            //Set the LED on Digital 12 as an OUTPUT
  Wire.begin();	
  SeeedOled.init();  //initialze SEEED OLED display
}

/*void setDisplayToOriginalState(char testCase)

{
  delay(5000);
  SeeedOled.init();                       //initialze SEEED OLED display
  SeeedOled.clearDisplay();               // clear the screen and set start position to top left corner
  SeeedOled.deactivateScroll();           // deactivete Scroll (might be activated by previous test case)
  SeeedOled.setNormalDisplay();           // Non-inverted Display 
  SeeedOled.setPageMode();                // Page mode to start with
  SeeedOled.setTextXY(2,0);               // 0 Page, 0th Column  
  SeeedOled.putString("Test Case ");
  SeeedOled.putNumber(testCase);
  SeeedOled.setTextXY(3,0);
  SeeedOled.putString("Test Case ");
  SeeedOled.putNumber(testCase);
  delay(2000);
  


}*/


void loop()
{
  int sensorValue = analogRead(LIGHT_SENSOR); 
    Rsensor = (float)(4095-sensorValue)*10/sensorValue;
    Serial.println("the analog read data is ");
    Serial.println(sensorValue);
    Serial.println("the sensor resistance is ");
    Serial.println(Rsensor,DEC);//show the ligth intensity on the serial monitor;
    delay(250);
    
 // long RangeInInches;
  long RangeInCentimeters;

  /*Serial.println("The distance to obstacles in front is: ");
  RangeInInches = ultrasonic.MeasureInInches();
  Serial.print(RangeInInches);//0~157 inches
  Serial.println(" inch");
  delay(250);*/

  RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  delay(250);

  float U = RangeInCentimeters;
  float l = analogRead (LIGHT_SENSOR);

 /*SeeedOled.clearDisplay();
 Serial.println("Range: ");
 Serial.print("u: ");
 Serial.println(U);
 Serial.println("Light value: ");
 Serial.println(" %\t");
 Serial.println(l);
 Serial.println("---------------------");*/
SeeedOled.clearDisplay();
SeeedOled.setTextXY(0,0);
SeeedOled.putNumber(U);
SeeedOled.putString(" ");
SeeedOled.putString("cm");
 
 //SeeedOled.clearDisplay();
 SeeedOled.setTextXY(1,0);
 SeeedOled.putNumber(l);
 SeeedOled.putString(" ");
 SeeedOled.putString("light");

 delay(500);
}
/*#define LIGHT_SENSOR A0//Grove - Light Sensor is connected to A0 of Arduino
const int ledPin=12;                 //Connect the LED Grove module to Pin12, Digital 12
const int thresholdvalue=10;         //The treshold for which the LED should turn on. Setting it lower will make it go on at more light, higher for more darkness
float Rsensor; //Resistance of sensor in K
void setup() 
{
    Serial.begin(9600);                //Start the Serial connection
    pinMode(ledPin,OUTPUT);            //Set the LED on Digital 12 as an OUTPUT
}
void loop() 
{
    int sensorValue = analogRead(LIGHT_SENSOR); 
    Rsensor = (float)(4095-sensorValue)*10/sensorValue;
    Serial.println("the analog read data is ");
    Serial.println(sensorValue);
    Serial.println("the sensor resistance is ");
    Serial.println(Rsensor,DEC);//show the ligth intensity on the serial monitor;
    delay(250);
}*/
