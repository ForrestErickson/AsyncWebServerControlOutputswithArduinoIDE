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
 * 
 */

// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

//--------------- Includes ---------------------------
#include "Arduino.h"
#include "wink.h"
#include "http.h"

// Replace with your network credentials
//const char* ssid = "REPLACE_WITH_YOUR_SSID";
//const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* ssid     = "NETGEAR_11N";     // Netgear WAC104 SN: 4SL373BC00087
const char* password = "Heavybox201";  // Lab wifi router
//const char* password = "Heavybox202";  // bad pw.


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


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

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    extern const char index_html[] ;   
    request->send_P(200, "text/html", index_html, processor); 
  });//end Sever.on("/"... 

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    // Switch ID and States
    const char* PARAM_INPUT_1 = "output";
    const char* PARAM_INPUT_2 = "state";

    String inputMessage1;
    String inputMessage2;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      digitalWrite(inputMessage1.toInt(), inputMessage2.toInt());
    }
    else {
      inputMessage1 = "No message sent";
      inputMessage2 = "No message sent";
    }
    Serial.print("GPIO: ");
    Serial.print(inputMessage1);
    Serial.print(" - Set to: ");
    Serial.println(inputMessage2);
    request->send(200, "text/plain", "OK");
  }); //end Sever.on("/update"... 

  // Start server
  server.begin();

  setupWinkEnd();
}//end setup()

void loop() {

   // put your main code here, to run repeatedly:

  winkLED_BUILTIN();
}
