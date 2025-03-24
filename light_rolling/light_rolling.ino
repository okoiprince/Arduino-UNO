
int led; 

void setup() {
  // put your setup code here, to run once:
  for (led= 3; led<10; led++)
  {
    pinMode(led, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (led=3; led < 10; led++)
  {
    digitalWrite(led, HIGH);
    delay(30);

    digitalWrite(led, LOW);
    
  }
  
}
