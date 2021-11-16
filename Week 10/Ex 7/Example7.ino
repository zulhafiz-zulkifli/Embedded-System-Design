#include "DCMotor.h"

void setup() {
  // put your setup code here, to run once:
  DCMotor motor1('B', 0, 1000);
  DCMotor motor2('B', 1, 1000);
  DCMotor motor3('B', 2, 1000);
  DCMotor motor4('B', 3, 1000);
  motor1.Write(0.2);
  motor2.Write(0.4);
  motor3.Write(0.6);
  motor4.Write(0.8);
  while (1)
  {
    motor1.Refresh();
    motor2.Refresh();
    motor3.Refresh();
    motor4.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
