#include "ServoSweeper.h"
Servo servo1('B', 0, 20000);
Servo servo2('B', 1, 20000);
Servo servo3('B', 2, 20000);
Servo servo4('B', 3, 20000);
ServoSweeper a(&servo1, 500, 2000, 10, 15);
ServoSweeper b(&servo2, 500, 2000, 10, 20);
ServoSweeper c(&servo3, 800, 1500, 10, 15);
ServoSweeper d(&servo4, 800, 1500, 10, 20);

void setup(){

}

void loop(){
  a.Refresh();
  b.Refresh();
  c.Refresh();
  d.Refresh();
}
