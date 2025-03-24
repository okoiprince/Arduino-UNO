
int led; 
int button=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  for (led= 3; led<7; led++)
  {
  
pinMode(led, OUTPUT);
}
}
void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = digitalRead(button);
  if (sensorValue==true) {
    lightUp();

}
  }

  void lightUp(){
for(led=3; led<7; led++)
{
  digitalWrite(led, HIGH);
delay(40);
digitalWrite(led, LOW);
delay(30);
}
}

