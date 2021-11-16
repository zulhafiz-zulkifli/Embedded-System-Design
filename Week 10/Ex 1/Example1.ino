#include "Blinky.h"

void setup() {
  // put your setup code here, to run once:
  Blinky blinker('B', 5, 1000000, 1000000); //Blink PB5 1s ON and 1s OFF
  while (1)
  {
    blinker.Refresh();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
