/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include "Ultrasonic.h"

Ultrasonic ultrasonic(2);
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

 
 int pos=0;    // variable to store the servo position
 int distinct=20;
void setup() {
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
  Serial.begin(9600);
}

void loop() {

  long RangeInCentimeters;
  
 RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval

  int U = RangeInCentimeters;

  
  if(144 <= U && U <= 180){
  
    for (pos = 0; pos <= 35; pos += 1){
    //pos=0;
   // pos+=1;
    //pos <=35;
    myservo.write(pos); 
    delay (100);
                        
    //pos=0;

  }
  }
  
    else if(108 <= U && U <= 144){
   for (pos = 36; pos <= 71; pos += 1){
    //pos=0;
   // pos+=1;
    //pos <=35;
    myservo.write(pos); 
    delay (100);
                        
    //pos=0;

  }
  }
    else if(72 <= U && U <= 108){
   for (pos = 72; pos <= 107; pos += 1){
    //pos=0;
   // pos+=1;
    //pos <=35;
    myservo.write(pos); 
    delay (100);
                        
    //pos=0;

  }
  }
    else if(36 <= U && U <= 72){
   for (pos = 108; pos <= 143; pos += 1){
    //pos=0;
   // pos+=1;
    //pos <=35;
    myservo.write(pos); 
    delay (100);
                        
    //pos=0;

  }
  }
  else if(1 <= U && U <= 36){
   for (pos = 144; pos <= 179; pos += 1){
    //pos=0;
   // pos+=1;
    //pos <=35;
    myservo.write(pos); 
    delay (100);
                        
    //pos=0;

  }
  }
  else if(U == 0){
    pos = 180;
    delay (100);
  }
}

/*Ultrasonic ultrasonic(2);

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  long RangeInInches;
  long RangeInCentimeters;

  Serial.println("The distance to obstacles in front is: ");
  RangeInInches = ultrasonic.MeasureInInches();
  Serial.print(RangeInInches);//0~157 inches
  Serial.println(" inch");
  delay(250);

  RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
  Serial.print(RangeInCentimeters);//0~400cm
  Serial.println(" cm");
  delay(250);
}*/
