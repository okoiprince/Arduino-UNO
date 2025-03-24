#include <SoftwareSerial.h> //software serial library for serial communication b/w arduino & GSM

SoftwareSerial mySerial(3,2);//connect Tx pin of GSM to pin 8 of arduino && Rx pin of GSM to pin no 9 of arduino

int led = 7;
String message;


void setup()
{
     // Setting the baud rate of GSM Module  
  Serial.begin(115200);    // Setting the baud rate of Serial Monitor (Arduino)
  mySerial.begin(115200);

   mySerial.println("AT+CMGF=1"); // use full functionality (calls, sms, gprs) - see app note
   mySerial.println("AT+CLIP=1"); // enable presentation number

  Serial.println("Initializing.....");


  mySerial.println("AT+CNMI=1,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);

   if (Serial.available()){
  message = mySerial.readString();
  }
}

void loop()
{
   if(message.indexOf("ON") > -1){
      Serial.println("LED ON");
     digitalWrite(led,HIGH);
     }
    else if(message.indexOf("OFF") > -1){

      Serial.println("LED OFF");
      digitalWrite(led,LOW);

  }

  delay(10);
}
