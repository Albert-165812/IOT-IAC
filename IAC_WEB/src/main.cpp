#include "main.h"

ESP8266WebServer    server(80);

void home();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(SSID_SR,PASSWORD_SR);
  // Set static IP address for Access Point (AP) mode
  if (!WiFi.softAPConfig(staticIP_AP, gateway_AP, subnet_AP)) {
    Serial.println("AP Failed to configure static IP");
  }
  server.on("/",home);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void home(){
  server.send(200,"text/html",Web);
}