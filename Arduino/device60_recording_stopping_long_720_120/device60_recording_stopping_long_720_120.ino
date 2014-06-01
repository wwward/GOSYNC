#include <Wire.h>

int count = 1;
byte reply1[] = {0x12, 0x00, 0x00, 0x03, 0x01, 0x00, 
                 0x01, 0x3f, 0x01, 0x01, 0x01, 0x00, 
                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
                 
byte reply2[] = {0x02, 0x63, 0x76};

byte reply3[] = {0x02, 0x63, 0x76};

byte reply4[] = {0x28, 0x54, 0x44, 0x0e, 0x05,
                 0x1c, 0x14, 0x14, 0x2c,
                 0x00, 0x05, 0xff, 0x01, 0x09,
                 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x01,
                 0x02, 0x00, 0x00, 0x00, 0x04,
                 0x00, 0x00, 0x00, 0x00, 0x00,
                 0x00, 0x00, 0x00, 0x00, 0x01,
                 0x00, 0x00, 0x00, 0x00, 0x00};
          
byte reply5[] = {0x01, 0x00};

byte reply6[] = {0x03, 0x53, 0x59, 0x01};// This is recording trigger
byte reply7[] = {0x03, 0x53, 0x59, 0x01};// This is also used as stop 

int beHigh = 1;
int beLow = 0;

int pinHigh = 0;
int pinHigh2 = 0;

void setup()
{
 // This is for 0x60
 Wire.begin(96);
 Wire.onRequest(requestEvent);
 Wire.onReceive(receiveEvent);
 
 Serial.begin(9600);
 
 pinMode(13, OUTPUT);
 
 pinMode(7, OUTPUT); // indicate trigger pinHigh
 pinMode(8, OUTPUT); // indicate stopper pinHigh2
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
  
  if (count == 100)
  {
    beHigh = 0;
  }
  
  if (count == 200)
  {
    beHigh = 0;
  }
  
  if (pinHigh)
  {
    digitalWrite(7, HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(7, LOW);
    delay(10);
  }
  
  if (pinHigh2)
  {   
    digitalWrite(8, HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(8, LOW);
    delay(10);
  }
    
  delay(200);
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
    case 100:
      Wire.write(reply6, 4); // trigger
      pinHigh = 1;
      break;
    case 900:
      Wire.write(reply7, 4); // stop
      pinHigh2 = 1;
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


