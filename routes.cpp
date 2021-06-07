/* routes.cpp
    Routes for web pages stored in Progam memory


*/

//--------------- Includes ---------------------------
#include "Arduino.h"
#include "routes.h"

// Create AsyncWebServer object on port 80
extern AsyncWebServer myServer(80);

// Start server
void serverBegin(void) {
  myServer.begin();
}

void serverOnHome(void) {
  // Route for root / web page
  myServer.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    extern const char index_html[] ;
    request->send_P(200, "text/html", index_html, processor);
  });//end Sever.on("/"...
}// severOnHome



void serverOnUpdate(void) {
  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  myServer.on("/update", HTTP_GET, [] (AsyncWebServerRequest * request) {
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
}// severOnUpdate
