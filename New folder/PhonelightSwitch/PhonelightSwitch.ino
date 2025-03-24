#include <Servo.h>
Servo myservo; 
/*
  AnalogReadSerial
 Reads an analog input on pin 0, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sensorValue > 1000){
    myservo.write (90);
    delay (2000);
    myservo.write(0);
  }
}
