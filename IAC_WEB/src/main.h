#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <ArduinoJson.h>

#include "web.h"

#define SSID_SR "IAC IOT"
#define PASSWORD_SR "11111111"

IPAddress staticIP_AP(192, 168, 6, 1);     // Set the static IP address for AP mode
IPAddress gateway_AP(192, 168, 6, 1);
IPAddress subnet_AP(255, 255, 255, 0);

String stateHomeString = "{\"outDoor\":{\"door\":{\"state\":\"done\",\"warming\":\"no-warming\"},\"lightGarden\":{\"light1\":\"ON\",\"light2\":\"ON\"},\"temperature\":1,\"humidity\":1},\"livingRoom\":{\"light\":\"ON\",\"curtain\":\"ON\",\"temperature\":1,\"fan\":\"ON\",\"airConditioner\":\"ON\"},\"kitchen\":{\"light\":\"ON\",\"temperature\":1,\"gas\":1,\"fan\":\"ON\",\"stateFanGas\":\"ON\"}}";
String stateHomeStringLast;

// outside
#define light_outside_1 2
#define light_outside_2 3
#define dht11_outside 2
// livingroom
#define light_livingroom 3
#define curtain_livingroom 2
#define fan_livingroom 2
#define air_conditioner_livingroom 3

// kitchen
#define light_kitchen 2
#define fan_kitchen 2
#define gas_fan_kitchen 4
#define gas_kitchen 5
#define dht11_kitchen 2

String state_light_outside_1;
String state_light_outside_2;
int state_dht11_outside;
String state_light_livingroom;
String state_curtain_livingroom;
String state_fan_livingroom;
String state_air_conditioner_livingroom;
String state_light_kitchen;
String state_fan_kitchen;
String state_gas_fan_kitchen;
int state_gas_kitchen;
int state_dht11_kitchen;
