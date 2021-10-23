int value;

void setup()
{
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(A0);
  analogWrite (11, map(value, 0, 1023, 0, 255));
  Serial.println(value);
}
