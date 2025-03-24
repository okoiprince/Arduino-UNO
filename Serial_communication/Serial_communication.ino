int led = 3;

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT); 
digitalWrite(led, LOW);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
if (Serial.available()>0){
  char key = Serial.read();

  if (key =='1')
  {
    digitalWrite(led, HIGH);
    
  } else if (key == '0') {
    digitalWrite(led, LOW);
  }
}
}
