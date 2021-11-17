#include "Stepper.h"
#include "StepperRotator.h"
Stepper stepper1('B', 'F');
Stepper stepper2('D', 'H');
StepperRotator rotator1(&stepper1, 1, 2000);
StepperRotator rotator2(&stepper2, 0, 2000);

void setup(){

}

void loop(){
  rotator1.Refresh();
  rotator2.Refresh();
}
