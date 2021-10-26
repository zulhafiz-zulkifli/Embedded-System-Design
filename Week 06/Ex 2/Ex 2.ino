//Timer 0 OC0A - PD6 - Pin 6 Uno
//Timer 0 OC0B - PD5 - Pin 5 Uno
//Timer 1 OC1A - PB1 - Pin 9 Uno
//Timer 1 OC1B - PB2 - Pin 10 Uno
//Timer 2 OC2A - PB3 - Pin 11 Uno
//Timer 2 OC2B - PD3 - Pin 3 Uno

void setup(){
  DDRD = 0b00100000;     //PD5 - Pin 5 Uno
  OCR0B = 127;           //50% duty cycle
  TCCR0A = 0b00100011;   //Normal output channel B, Fast PWM 255 top
  TCCR0B = 0b00000001;   //1 pre-scaler
}

void loop(){
}