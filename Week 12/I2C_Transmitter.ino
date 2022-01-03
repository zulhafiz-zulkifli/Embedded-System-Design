#include "Wire.h"
int x = 0;

void setup(){
  // Start the I2C Bus as Master
  Wire.begin();
}

void loop(){
  Wire.beginTransmission(3); // transmit to device #3
  Wire.write(x);              // send a byte of x
  Wire.endTransmission();    // stop transmitting
  x++; // Increment x
  if(x>10) x = 0; // `reset x once it gets 6
  delay(500);
}
