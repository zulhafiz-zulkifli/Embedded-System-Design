#include "Wire.h"
int x = 0;

void setup(){
  Wire.begin(3); // join i2c bus with address #4
  Wire.onReceive(receiveCallback); // register callback function
  Serial.begin(9600); // use serial for output
}

void loop(){
  delay(500);
}


// function that executes whenever data is received from master
void receiveCallback(int howMany){
  // loop through all but the last
  while(1 < Wire.available()){
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}