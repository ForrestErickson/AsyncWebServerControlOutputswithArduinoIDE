/*********
  File: AsyncWebServerControlOutputswithArduinoIDE
  Program: ESP32 Async Web Server – Control Outputs with Arduino IDE
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-async-web-server-espasyncwebserver-library/
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  From: https://randomnerdtutorials.com/esp32-async-web-server-espasyncwebserver-library/

*********/

/*Add Wink into code and then going to make modules as a demonstration
   Forrest Erickson
   Date: 20210605
   Date: 20210606 Break wink out into .h and .cpp files.
   Date: 20210607 Break http page and string processor into .h and .cpp file
   Date: 20210607 Break web page routes into .h and .cpp file
   Date: 20210607 Move GPIO setup into .h and .cpp file
   Date: 20210607 Move wireless setup into .h and .cpp file
*/

// Import required libraries


//--------------- Includes ---------------------------
#include "Arduino.h"
#include "wink.h"
#include "http.h"
#include "routes.h"
#include "gpio.h"
#include "wireless.h"


void setup() {
  //  //Use LED_BUILDIN to instrument start and stop of setup().
  setupWinkStart();

  // Serial port for debugging purposes
  Serial.begin(115200);

  // Set GPIO pins as IO
  setupGPIO();

  //Init the WiFi and print the IP address
  initWiFi();

  //Server routes set
  serverOnHome();
  serverOnUpdate();

  // Start server
  serverBegin();

  setupWinkEnd();
}//end setup()

void loop() {

  // put your main code here, to run repeatedly:

  winkLED_BUILTIN();
}
