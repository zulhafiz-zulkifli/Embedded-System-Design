#include "Stepper.h"
#include "StepperRotator.h"

void setup() {
  // put your setup code here, to run once:
  Stepper stepper1('B', 'F');
  Stepper stepper2('D', 'H');
  StepperRotator rotator1(&stepper1, 1, 2000);
  StepperRotator rotator2(&stepper2, 0, 2000);
  while (1)
  {
    rotator1.Refresh();
    rotator2.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
