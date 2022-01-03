int inByte; // To store incoming command

void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT); // Set LED pin as output
  Serial.println("Ready to receive command");
}

void loop(){
  if (Serial.available() > 0){ // A byte is ready to receive
    inByte = Serial.read();
    if (inByte == 'z') { // if byte incoming is 'z'
      digitalWrite(13, HIGH);
      Serial.println("ON");
    }
    else { // byte isn't 'a'
      digitalWrite(13, LOW);
      Serial.println("OFF");
    }
  }
}
