#include <SPI.h>
const int ENCODER_DT = 2;
const int ENCODER_CLOCK = 3;
int8_t count;
bool a;
bool b;

void ISR0(){
  a = digitalRead(ENCODER_DT);
  b = digitalRead(ENCODER_CLOCK);
  if (a == b)
    count++;
  else
    count--;
  Serial.println(count);
}

void ISR1(){
  a = digitalRead(ENCODER_DT);
  b = digitalRead(ENCODER_CLOCK);
  if (a != b)
    count++;
  else
    count--;
  Serial.println(count);
}

ISR(SPI_STC_vect){
  SPDR = count;
  count = 0;
}

void setup(){
  Serial.begin(9600);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_CLOCK, INPUT);
  attachInterrupt(0, ISR0, CHANGE);
  attachInterrupt(1, ISR1, CHANGE);
}

void loop(){
  
}