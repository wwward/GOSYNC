#include <Wire.h>

int count = 0;

void setup()
{
 Wire.begin(80);
 //Wire.onReceive(receiveEvent);
 Wire.onRequest(requestEvent);
}

void loop()
{
}

void requestEvent()
{
  if (count == 0)
    Wire.write(0x05);
  if (count == 1)
    Wire.write(0x05);
  if (count == 2)
    Wire.write(0x01);
  if (count == 3)
    Wire.write(0x0b);
    
  count = (count+1)%4;
}

void receiveEvent(int howMany)
{
  // do nothing, just ack
  //x = Wire.read();
}
