volatile bool changed = 0;

void setup(){
  DDRB = 0b00100000;      //PB5 as output
  SREG |= 0b10000000;     //Enable interrupts in general
  PCICR = 0b00000001;     //Enable PCINT0
  PCMSK0 = 0b00000001;     //Enable PCINT on PB0
}

extern "C"{
  ISR(PCINT0_vect){
    changed = 1;
  }
}
void loop(){
  if (changed == 1){
    PORTB = 0b00100000; //Same as digitalWrite(13, HIGH)
    changed = 0;
    delay(10); // Some delay to see the changes
  }
  else{
    PORTB = 0b00000000;
  }
}
