char *admux = (char*)0x7C; 
volatile unsigned char *adcsra = (unsigned char*) 0x7A;
volatile unsigned char *adch = (unsigned char*) 0x79;
volatile unsigned char *adcl = (unsigned char*) 0x78;

void setup() {
  // put your setup code here, to run once:
  *admux = 0b01000011; 
  *adcsra = 0b11000111; 
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  *adcsra |= 0b01000000; //Start conversion (Set ADSC bit)
  while (((*adcsra) & 0b01000000)) //As long as ADSC bit is HIGH
  {
    //Do nothing
  }
  int lowbyte = (*adcl); //Capture low byte
  int highbyte = (*adch); //Capture high byte
  int value = (highbyte << 8) | lowbyte; 
  analogWrite (11, map(value, 0, 1023, 0, 255));
  Serial.println(value);
}
