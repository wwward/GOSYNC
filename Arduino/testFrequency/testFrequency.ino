#include "TimerOne.h"

int switchState = 0;
int delayInterval = 0.1;
int period = 0;

void setup() 
{
  DDRD = B11100000; 
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(callback);
}

void callback()
{
  PORTD = B11100000;
  delay(0.1);
  PORTD = B00000000; 
}

void loop() 
{

}
