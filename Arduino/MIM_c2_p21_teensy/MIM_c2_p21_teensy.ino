

int switchState = 0;
int count = 0;

void setup() 
{
  pinMode(12,OUTPUT);
  pinMode(11,INPUT);
}


void loop() 
{
  if (digitalRead(11) == 1)
  {
    digitalWrite(12,HIGH);
  }
  else
  {
    digitalWrite(12,LOW);
  }
}
