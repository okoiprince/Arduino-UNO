#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mySerial.begin(115200);

  Serial.println("Initializing....");
  delay(1000);

  mySerial.println("AT");

  updateSerial();

  mySerial.println("AT+CNMI=2,2,0,0,0");
  updateSerial();

}

void loop() {
  // put your main code here, to run repeatedly:
  updateSerial();

}

void updateSerial() 
{
  delay(500);
  while(Serial.available())
  {
    mySerial.write (Serial.read());
  }

  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
}
