#include "DCMotor.h"
DCMotor motor1('B', 0, 50);

void setup() {
  motor1.Write(0.5);
}

void loop() {
  motor1.Refresh();
}
