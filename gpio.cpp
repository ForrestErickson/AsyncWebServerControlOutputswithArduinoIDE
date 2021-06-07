/* gpio.cpp
    pin setup


*/

//--------------- Includes ---------------------------
#include "Arduino.h"
#include "gpio.h"

//Setup GPIO

void setupGPIO(void) {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  pinMode(33, OUTPUT);
  digitalWrite(33, LOW);
}//End setupGPIO
