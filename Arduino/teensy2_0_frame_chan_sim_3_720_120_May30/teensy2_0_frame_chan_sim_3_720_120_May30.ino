

int simulation = 0;
int startSim = 0;
int stopSim = 0;
int firstStop = 1;
int count = 0;

void setup() 
{
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}


void loop() 
{
  digitalWrite(11, HIGH);
  
  if (startSim ==0 && digitalRead(7) == HIGH)
  {
    startSim = 1;
    delay(1000);
  }
  
  if (stopSim == 0 && digitalRead(8) == HIGH )
  {
    stopSim = 1;
  }
    
  if (startSim == 1 && count < 100)
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
      delayMicroseconds(8331);
      digitalWrite(12,LOW);
      delayMicroseconds(10);
      digitalWrite(12,LOW);
      delayMicroseconds(10);
    }
  }
  
  if (stopSim == 1 && firstStop == 1)
  {  
      if (firstStop == 1)
      {
        digitalWrite(11, LOW);
        delay(1);
        digitalWrite(11, HIGH);
        firstStop = 0;
      }
  }
  
  if (stopSim == 1 && count < 200)
    count = count+1;
}
