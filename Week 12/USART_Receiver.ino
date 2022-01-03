int value;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if(Serial1.available()){
    value = Serial1.read();
    Serial.println(value);
  }
}
