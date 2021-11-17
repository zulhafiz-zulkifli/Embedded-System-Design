#include "Servo.h"
Servo motor1('B', 0, 20000);
Servo motor2('B', 1, 20000);
Servo motor3('B', 2, 20000);
Servo motor4('B', 3, 20000);

void setup(){
  motor1.Write(1500);
  motor2.Write(1500);
  motor3.Write(1500);
  motor4.Write(1500);
}

void loop(){
  motor1.Refresh();
  motor2.Refresh();
  motor3.Refresh();
  motor4.Refresh();
}
