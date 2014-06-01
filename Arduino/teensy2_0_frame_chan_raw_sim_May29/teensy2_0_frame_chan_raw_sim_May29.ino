

int simulation = 0;
int startSim = 0;
int count = 0;

void setup() 
{
  pinMode(12,OUTPUT);
}


void loop() 
{
    digitalWrite(12,HIGH);
    delay(34);
    digitalWrite(12,LOW);
    delayMicroseconds(10);
    digitalWrite(12,LOW);
    delayMicroseconds(10);
}
