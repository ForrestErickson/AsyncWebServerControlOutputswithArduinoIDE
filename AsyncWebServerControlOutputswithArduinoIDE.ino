/*********
 * File: AsyncWebServerControlOutputswithArduinoIDE
 * Program: ESP32 Async Web Server – Control Outputs with Arduino IDE
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-async-web-server-espasyncwebserver-library/
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  From: https://randomnerdtutorials.com/esp32-async-web-server-espasyncwebserver-library/
  
*********/

/*Add Wink into code and then going to make modules as a demonstration
 * Forrest Erickson
 * Date: 20210605
 * Date: 20210606 Break wink out into .h and .cpp files.
 * Date: 20210607 Break http page and string processor into .h and .cpp file
 * Date: 20210607 Break web page routes into .h and .cpp file
 * 
 */

// Import required libraries
#include <WiFi.h>
//#include <AsyncTCP.h>
//#include <ESPAsyncWebServer.h>

//--------------- Includes ---------------------------
#include "Arduino.h"
#include "wink.h"
#include "http.h"
#include "routes.h"

// Replace with your network credentials
//const char* ssid = "REPLACE_WITH_YOUR_SSID";
//const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* ssid     = "NETGEAR_11N";     // Netgear WAC104 SN: 4SL373BC00087
const char* password = "Heavybox201";  // Lab wifi router
//const char* password = "Heavybox202";  // bad pw.




void setup(){
//  //Use LED_BUILDIN to instrument start and stop of setup().
  setupWinkStart();
  
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  pinMode(33, OUTPUT);
  digitalWrite(33, LOW);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

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
