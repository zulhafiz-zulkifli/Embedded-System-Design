#include "DCMotor.h"
DCMotor motor1('B', 0, 1000);

void setup() {
  motor1.Write(0.2);
}

void loop() {
  motor1.Refresh();
}
