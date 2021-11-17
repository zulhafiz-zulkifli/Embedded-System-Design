char DriveSteps[] = {1, 3, 2, 6, 4, 12, 8, 9}; //Activation pattern of half-step drive
char position = 0;
unsigned long last; //Stores last time the motor moved

void setup(){
  DDRB = 0b00001111; //Set the 4 pins as output
}

void loop(){
  unsigned long now = millis();
  if (now - last >= 4){
    PORTB = DriveSteps[position];
    position--;
    if (position < 0 ){
      position = 7;
    }
    last = now;
  }
}
