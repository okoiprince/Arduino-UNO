byte Digital[10] = {0xfc, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe0, 0xfe, 0xf6};
void setup() {
  // put your setup code here, to run once:
int i=2;
for(i=2; i<10; i++)
{
  pinMode (i, OUTPUT);
  digitalWrite(i, HIGH);
}
}

void loop() {
  // put your main code here, to run repeatedly:

  int i=0;
  int j;

  for(i=0; i<10; i++)
  {
    for(j=0; j<8; j++)
    {

      if (Digital[i] & 1 <<j)
      digitalWrite (9-j, LOW);
      else
      digitalWrite (9-j, HIGH);
    }
    delay(500);
  }

}
