//Timer 0 OC0A - PD6 - Pin 6 Uno
//Timer 0 OC0B - PD5 - Pin 5 Uno
//Timer 1 OC1A - PB1 - Pin 9 Uno
//Timer 1 OC1B - PB2 - Pin 10 Uno
//Timer 2 OC2A - PB3 - Pin 11 Uno
//Timer 2 OC2B - PD3 - Pin 3 Uno

void setup() {
  DDRB = 0b00000010;     //PB1 - Pin 9 Uno
  OCR1A = 255;             //25% duty cycle
  TCCR1A = 0b10000011;     //Normal output channel A, 10 bit phase correct PWM
  TCCR1B = 0b00000010;     //8 pre-scaler
}

void loop() {
}
