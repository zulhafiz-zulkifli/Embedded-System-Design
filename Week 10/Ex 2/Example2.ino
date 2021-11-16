#include "Blinky.h"

void setup() {
  // put your setup code here, to run once:
  Blinky blinker('B', 5, 200, 300);
  while (1)
  {
    blinker.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
