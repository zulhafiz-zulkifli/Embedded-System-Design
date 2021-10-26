volatile unsigned long ms;
unsigned long previousTime;

extern "C"{
  ISR(TIMER2_OVF_vect){
    ms++;
  }
}

unsigned long getMilliseconds(){
  TIMSK2 = 0b00000000; //Disable timer2 interrupts
  unsigned long val = ms; //Read the variable
  TIMSK2 = 0b00000001; //Re-enable timer2 interrupts
  return val;
}

void setup(){
  DDRB = 0b00100000; //Set PB5 as output
  TCCR2A = 0b00000011; //8-bit Fast PWM on timer2
  TCCR2B = 0b00000100; //Set pre-scaler to 64
  SREG |= 0b10000000; //Enable interrupts
  TIMSK2 = 0b00000001; //Enable timer2 overflow interrupt
}

void loop(){
  unsigned long currentTime = getMilliseconds();
  if ((PORTB) & 0b00100000){
    //If LED is currently ON
    if (currentTime - previousTime >= 1000){
      PORTB = 0; //Turn it OFF
      previousTime = currentTime;
    }
  }
  else{
    //If LED is currently OFF
    if (currentTime - previousTime >= 1000){
      PORTB = 0b00100000; //Turn it ON
      previousTime = currentTime;
    }
  }
}