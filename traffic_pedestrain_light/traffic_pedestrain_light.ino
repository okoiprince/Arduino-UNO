//variable declaration 
int pinOne = 3;
int pinTwo = 4;
int pinThree = 5;
int pinFour = 6;
int pinFive = 7;
int socketValue = 0;
int swt = 8;

void setup() {
  // put your setup code here, to run once:
  
  //DEFINE OUTPUT PIN
  pinMode(pinOne, OUTPUT);
  pinMode(pinTwo, OUTPUT);
  pinMode(pinThree, OUTPUT);
  pinMode(pinFour, OUTPUT);
  pinMode(pinFive, OUTPUT);
  
  //DEFINE INPUT PIN
  pinMode(swt, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
socketValue = digitalRead(swt);

  //Traffic light red
  digitalWrite(pinOne, HIGH);
  digitalWrite(pinFive, HIGH); 
  delay(3000);
  digitalWrite(pinOne, LOW);
  digitalWrite(pinFive, LOW);
  
  //Traffic light yellow
  digitalWrite(pinTwo, HIGH);
  digitalWrite(pinFour, HIGH);
  delay(2000);
  digitalWrite(pinTwo, LOW);
  digitalWrite(pinFour, LOW);
  
  //Traffic light green
  digitalWrite(pinThree, HIGH);
  digitalWrite(pinFour, HIGH);
  delay(3000);
  digitalWrite(pinThree, LOW);
  digitalWrite(pinFour, LOW);

  if (socketValue) {
    //Pedestrain light green
   
       digitalWrite(pinFour, HIGH);
       delay(3000);
       digitalWrite(pinFour, LOW);
    
       digitalWrite(pinFive, HIGH); 
       delay(3000); 
       digitalWrite(pinFive, LOW);
    }

}
