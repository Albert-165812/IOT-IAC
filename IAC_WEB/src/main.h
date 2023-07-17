#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <SoftwareSerial.h>

#include <ArduinoJson.h>

#include "web.h"

#define SSID_SR "IAC IOT"
#define PASSWORD_SR "11111111"


SoftwareSerial mySerial(D5, D6); // RX, TX // IO-14 và IO-12 trên esp8266

IPAddress staticIP_AP(192, 168, 6, 1);     // Set the static IP address for AP mode
IPAddress gateway_AP(192, 168, 6, 1);
IPAddress subnet_AP(255, 255, 255, 0);

String stateHomeString = "{\"outside\":{\"light\":0,\"temperature\":36,\"humidity\":30,\"door\":{\"warming\":\"no-warming\",\"state\":\"CLOSE\"}},\"inside\":{\"light\":0,\"fan\":0,\"curtain\":0}}";

