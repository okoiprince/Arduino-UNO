int swt=5;
int led=6;

void setup() {
  // put your setup code here, to run once:
pinMode(swt, INPUT_PULLUP);
pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int socket = digitalRead(swt); 

  if (socket) {

    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  

}
