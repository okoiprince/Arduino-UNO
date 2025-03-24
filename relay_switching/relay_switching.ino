#include <SoftwareSerial.h>

SoftwareSerial gsm(3, 2);

//varIable to store message

String message="";
int relay =8;

void setup() {
  // put your setup code here, to run once:

  pinMode(relay, OUTPUT);

  //set serial baud rate
  Serial.begin(115200);
  gsm.begin(115200);
  
  digitalWrite (relay, HIGH);
  
  Serial.println("Initializing...");
  
  Serial.println("AT");

  delay(2000);

  Serial.println("MODULE IS READY");
  gsm.println("AT+CMGF=1");
  delay(200);
  gsm.println("AT+CNMI=2,2,0,0,0");
  delay(200);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(gsm.available())
  {
    message = gsm.readString();
    Serial.println(message);
    delay(200);

    if(message)
    {
      digitalWrite(relay, LOW);
    }
    else if (message.compareTo("OFF")==true){
    digitalWrite(relay, HIGH);
  }
  }}
