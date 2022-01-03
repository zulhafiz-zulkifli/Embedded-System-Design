int value;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.write(value);
  delay(100);
  value++;
}
