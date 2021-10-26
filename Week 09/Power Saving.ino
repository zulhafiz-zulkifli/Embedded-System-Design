void setup(){
  DDRB = 0b11111111;        //unused pins as output
  DDRC = 0b11111111;
  DDRD = 0b11111111;
  ADCSRA = 0b00000000;      //disable ADC
  ACSR = 1 << 7;            //disable Analog Comparator
}

void loop(){
  SMCR = 0b00000101;     //power down, sleep mode enabled.
  MCUCR = 0b01100000;    //Set BODS and BODSE
  MCUCR = 0b01000000;    //Set BODS but clear BODSE, BOD is disabled.
}
