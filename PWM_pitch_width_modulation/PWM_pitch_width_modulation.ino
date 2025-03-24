int fadeAmount = 5;
int brightness = 0;
int led = 3;

void setup ()
{
  pinMode(led,OUTPUT);
}
void loop()
{
  analogWrite(led, brightness);

  brightness = brightness + fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = (-fadeAmount);
  }
   delay(30);
}

