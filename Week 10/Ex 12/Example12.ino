char DriveSteps[] = {1, 2, 4, 8}; //Activation pattern of wave drive
char position = 0;

void setup() {
  // put your setup code here, to run once:
  DDRB = 0b00001111; //Set the 4 pins as output
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB = DriveSteps[position];
  position++;
  if (position >= 4)
  {
    position = 0;
  }
  delay(5);
}
