#include "Servo.h"

void setup() {
  // put your setup code here, to run once:
  Servo motor1('B', 0, 20000);
  Servo motor2('B', 1, 20000);
  Servo motor3('B', 2, 20000);
  Servo motor4('B', 3, 20000);
  ServoSweeper a(&servo1, 500, 2000, 10, 15);
  ServoSweeper b(&servo2, 500, 2000, 10, 20);
  ServoSweeper c(&servo3, 800, 1500, 10, 15);
  ServoSweeper d(&servo4, 800, 1500, 10, 20);
  while (1)
  {
    a.Refresh();
    b.Refresh();
    c.Refresh();
    d.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
