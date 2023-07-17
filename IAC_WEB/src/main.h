#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <SoftwareSerial.h>

#include <ArduinoJson.h>

#include "web.h"

#define SSID_SR "IAC IOT"
#define PASSWORD_SR "11111111"


SoftwareSerial mySerial(D5, D6); // RX, TX

IPAddress staticIP_AP(192, 168, 6, 1);     // Set the static IP address for AP mode
IPAddress gateway_AP(192, 168, 6, 1);
IPAddress subnet_AP(255, 255, 255, 0);

String stateHomeString = "{\"outside\":{\"light\":1,\"temperature\":11,\"humidity\":11,\"door\":{\"warming\":\"no-warming\",\"state\":\"CLOSE\"}},\"inside\":{\"light\":1,\"fan\":1,\"curtain\":1}}";

