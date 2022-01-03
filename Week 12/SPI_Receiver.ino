#include <SPI.h>
unsigned long currentmillis;
unsigned long prevmillis = 0;

const int SS1 = 40;
const int SS2 = 41;
int16_t X = 0;
int16_t Y = 0;
int8_t CountX = 0;
int8_t CountY = 0;

void setup(){
  Serial.begin(9600);
  pinMode (SS1, OUTPUT);
  pinMode (SS2, OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS1, HIGH);
  digitalWrite(SS2, HIGH);
}

void loop(){
  currentmillis = millis();
  if (currentmillis - prevmillis >= 50){
    digitalWrite(SS1, LOW);
    CountX = SPI.transfer(0);
    digitalWrite(SS1, HIGH);
    digitalWrite(SS2, LOW);
    CountY = SPI.transfer(0);
    digitalWrite(SS2, HIGH);
    X += CountX;
    Y += CountY;
    Serial.print(X);
    Serial.print("\t");
    Serial.println(Y);
    prevmillis = currentmillis;
  }
}