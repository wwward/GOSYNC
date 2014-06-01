

int simulation = 0;
int count = 0;

void setup() 
{
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}


void loop() 
{
  if (simulation == 0) 
  {
    digitalWrite(11, HIGH);
    delay(5000);
    digitalWrite(11, LOW);
    simulation = 1;
    delay(500);
    digitalWrite(11, HIGH);
    delay(20);
  }
  else
  {
    digitalWrite(12,HIGH);
    delay(34);
    digitalWrite(12,LOW);
    delayMicroseconds(10);
    digitalWrite(12,LOW);
    delayMicroseconds(10);
  }
}
