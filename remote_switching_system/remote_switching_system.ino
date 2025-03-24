#include <SoftwareSerial.h>

// if You use SoftwareSerial lib, declare object for GSM

SoftwareSerial gsm(3,2); // TX, RX

int LED_PIN=7;

void setup(){
     // initialise UART and GSM communication between Arduino and modem
     Serial.begin(115200);
     gsm.begin(115200);
     // wait 5-10sec. for modem whitch must connect to the network
     delay(5000);
     // configure modem - remember! modem didn't remeber Your's configuration!
     gsm.println("AT+CMGF=1"); // use full functionality (calls, sms, gprs) - see app note
     gsm.println("AT+CLIP=1"); // enable presentation number
     gsm.println("AT+CSCS=GSM"); // configure sms as standard text messages
     gsm.println("AT+CNMI=1,2,0,0,0"); // show received sms and store in sim (probobly, I don't compre this settings with app note but it's working :)
}
void loop(){
     String response = gsmAnswer();
    if(response.indexOf("+CMT:") > 0 ) { // SMS arrived
    // Now You can parse Your Message, if You wont controll only LED, just write
       if(response.indexOf("LED ON") > 0) {
          digitalWrite(LED_PIN, HIGH); // enable it
       }else if(response.indexOf("LED OFF") > 0) {
          digitalWrite(LED_PIN, LOW); // turn off
       }
       delay(1000);
    }
}


String gsmAnswer(){
   String answer;
   while(!gsm.available());
   while(gsm.available()){
     delay(5);
     if(Serial.available() > 0){
       char s = (char)gsm.read();
       answer += s;
     }
  }
  return answer;
}
