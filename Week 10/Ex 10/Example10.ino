#include "Servo.h"

void setup() {
  // put your setup code here, to run once:
  unsigned long last_time;
  int Min = 544;
  int Max = 2400;
  int Step = 10;
  int Delay_ms = 25;
  int Current = Min;
  Servo servo('B', 0, 20000);
  while (1)
  {
    unsigned long now = millis();
    if (now - last_time >= Delay_ms)
    {
      last_time = now;
      Current += Step;
      servo.Write(Current);
      if (Current >= Max || Current <= Min)
      {
        Step = -Step;
      }
    }
    servo.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
