#include "DCMotor.h"

void setup() {
  // put your setup code here, to run once:
  DCMotor motor1('B', 0, 1000);
  motor1.Write(0.2);
  while (1)
  {
    motor1.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
