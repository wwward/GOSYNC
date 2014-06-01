
uint32_t pin_13 = (1u << 27); // mask for pin 13

void setup()
{                  
  REG_PIOB_OER = pin_13; // pin 13 as output of port B
}

void loop()
{
    REG_PIOB_CODR = pin_13; // turns pin 13 off (clear)
    REG_PIOB_SODR = pin_13; // turns pin 13 on (set)
}
