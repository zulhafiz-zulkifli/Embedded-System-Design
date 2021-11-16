#include "Blinky.h"

void setup() {
  // put your setup code here, to run once:
  Blinky blinker('D', 3, 100, 200);
  while (1)
  {
    blinker.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
