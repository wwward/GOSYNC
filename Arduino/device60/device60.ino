#include <Wire.h>

int count = 1;
byte reply1[] = {0x12, 0x00, 0x00, 0x03, 0x01, 0x00, 
                 0x01, 0x3f, 0x01, 0x01, 0x01, 0x00, 
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
                 
byte reply2[] = {0x02, 0x63, 0x76};

byte reply3[] = {0x02, 0x63, 0x76};

byte reply4[] = {0x28, 0x54, 0x44, 0x0e, 0x05,
                 0x20, 0x12, 0x25, 0x20,
                 0x00, 0x05, 0xff, 0x09, 0x04,
                 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x01,
                 0x02, 0x00, 0x00, 0x00, 0x04,
                 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x0a};
          
byte reply5[] = {0x01, 0x00};

int beHigh = 1;
int beLow = 0;

void setup()
{
 // This is for 0x60
 Wire.begin(96);
 Wire.onRequest(requestEvent);
 Wire.onReceive(receiveEvent);
 
 Serial.begin(9600);
 
 pinMode(13, OUTPUT);
}

void loop()
{
  if (beHigh)
    digitalWrite(13,HIGH);
    
  if (!beHigh)
    digitalWrite(13,LOW);
    
  if (beLow) 
  {
    digitalWrite(13,LOW);
    delay(2);
    digitalWrite(13,HIGH); 
  }
    
  delay(250);
}

void requestEvent()
{
  beHigh = 1;
  switch (count)
  {
    case 1:
      Wire.write(reply1, 19);
      beLow = 1;
      break;      
    case 2:
      Wire.write(reply2, 3);
      break;      
    case 3:
      Wire.write(reply3, 3);
      break;
    case 4:
      Wire.write(reply4, 41); 
      break;   
    default:
      Wire.write(reply5, 2);
      break;
  }
  count++;
}

void receiveEvent(int num)
{
  Serial.print("Receive something"); 
  beHigh = 0;
}


