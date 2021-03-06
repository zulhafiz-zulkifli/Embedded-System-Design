char DriveSteps[] = {3, 6, 12, 9}; //Activation pattern of full drive
char position = 0;
unsigned long last;               //Stores last time the motor moved

void setup(){
  DDRB = 0b00001111; //Set the 4 pins as output
}

void loop(){
  unsigned long now = millis();
  if (now - last >= 2){
    PORTB = DriveSteps[position];
    position++;
    if (position >= 4){
      position = 0;
    }
    last = now;
  }
}
