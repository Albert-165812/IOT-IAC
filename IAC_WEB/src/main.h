#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "web.h"

#define SSID_SR "IAC IOT"
#define PASSWORD_SR "11111111"

IPAddress staticIP_AP(192, 168, 6, 1);     // Set the static IP address for AP mode
IPAddress gateway_AP(192, 168, 6, 1);
IPAddress subnet_AP(255, 255, 255, 0);