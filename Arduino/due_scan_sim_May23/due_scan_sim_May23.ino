volatile boolean l;
uint32_t pin_13 = (1u << 27); // mask for pin 13
int state = 0;

//TC1 ch 0
void TC3_Handler()
{
        TC_GetStatus(TC1, 0);
        //digitalWrite(13, l = !l);
        REG_PIOB_CODR = pin_13; // turns pin 13 off (clear)
        REG_PIOB_CODR = pin_13;
        REG_PIOB_CODR = pin_13;
        REG_PIOB_CODR = pin_13;
        REG_PIOB_CODR = pin_13;
        REG_PIOB_SODR = pin_13;
}

void startTimer(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency) {
        pmc_set_writeprotect(false);
        pmc_enable_periph_clk((uint32_t)irq);
        TC_Configure(tc, channel, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK4);
        uint32_t rc = VARIANT_MCK/128/frequency; //128 because we selected TIMER_CLOCK4 above
        TC_SetRA(tc, channel, rc/2); //50% high, 50% low
        TC_SetRC(tc, channel, rc);
        TC_Start(tc, channel);
        tc->TC_CHANNEL[channel].TC_IER=TC_IER_CPCS;
        tc->TC_CHANNEL[channel].TC_IDR=~TC_IER_CPCS;
        NVIC_EnableIRQ(irq);
}

void setup(){
        //pinMode(13,OUTPUT);
        REG_PIOB_OER = pin_13;
        startTimer(TC1, 0, TC3_IRQn, 65600); //TC1 channel 0, the IRQ for that channel and the desired frequency
}

void loop(){
}
