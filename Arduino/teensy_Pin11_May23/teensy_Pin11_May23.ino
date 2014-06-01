int switchState = 0;
int delayInterval = 0.1;
int period = 0;

void setup() 
{
  //DDRC = B11111111; 
  pinMode(12,OUTPUT);
}

void loop() 
{
  digitalWriteFast(12,HIGH);
  digitalWriteFast(12,LOW);
  delayMicroseconds(10);  
}
