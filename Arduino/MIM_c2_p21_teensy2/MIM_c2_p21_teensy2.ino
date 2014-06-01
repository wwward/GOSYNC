

int simulation = 0;
int count = 0;

void setup() 
{
  pinMode(12,OUTPUT);
  pinMode(11,INPUT);
}


void loop() 
{
  if (simulation == 0) 
  {
    if (digitalRead(11) == 1)
    {
      simulation = 1;
    }
  }
  else
  {
    digitalWrite(12,HIGH);
    delayMicroseconds(33333.3);
    digitalWrite(12,LOW);
    delayMicroseconds(10);
  }
}
