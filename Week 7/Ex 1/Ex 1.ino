void setup(){
  DDRB = 0b00100000;      //PB5 as output
  SREG |= 0b10000000;     //Enable interrupts in general
  EIMSK = 0b00000001;     //Enable INT0 (PD2)
  EICRA = 0b00000001;     //Set interrupt mode to any logic change
}

extern "C"{
  ISR(INT0_vect){
    bool pin_status = ((PIND) & 0b00000100);   //Read pin 2 (PD2)
    PORTB = pin_status << 5; //Same as digitalWrite(13, digitalRead(2))
  }
}

void loop(){
}
