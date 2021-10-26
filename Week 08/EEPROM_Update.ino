#include <EEPROM.h>

void setup(){
  for (int i = 0; i < 255; i++){
    // this performs as EEPROM.write(i, i)
    EEPROM.update(i, i);
  }
  for (int i = 0; i < 255; i++){
    // write value "12" to cell 3 only the first time
    // will not write the cell the remaining 254 times
    EEPROM.update(3, 12);
  }
}

void loop(){
}
