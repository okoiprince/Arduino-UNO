int led;

void setup() {
  // put your setup code here, to run once:
  for(led=2; led<5; led++)
  {
    pinMode(led, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for(led=2; led<5; led++)
  {
    //green led
    if(led==2) {
      digitalWrite(led, HIGH);
      delay(15000);
      digitalWrite(led, LOW);
    }
    //yellow led
    else if (led==3) {
      digitalWrite(led, HIGH);
      delay(15000);
      digitalWrite(led, LOW);  
    }
    //red led
    else if (led==4) {
      digitalWrite(led, HIGH);
      delay(15000);
      digitalWrite(led, LOW);
    }
    
  }

}
