

int simulation = 0;
int startSim = 0;
int count = 0;

void setup() 
{
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7, INPUT);
}


void loop() 
{
  digitalWrite(11, HIGH);
  
  if (startSim ==0 && digitalRead(7) == HIGH)
  {
    startSim = 1;
    delay(1000);
  }
    
  
  if (startSim == 1)
  {  
    if (simulation == 0) 
    {
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
}
