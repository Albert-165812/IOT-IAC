#include "main.h"

ESP8266WebServer    server(80);

void home();
void getState();

void control_outside_light_1_on();
void control_outside_light_1_off();
void control_outside_light_2_on();
void control_outside_light_2_off();
void control_livingroom_light_on();
void control_livingroom_light_off();
void control_livingroom_curtain_on();
void control_livingroom_curtain_off();
void control_livingroom_fan_on();
void control_livingroom_fan_off();
void control_livingroom_air_conditioner_on();
void control_livingroom_air_conditioner_off();
void control_kitchen_light_on();
void control_kitchen_light_off();
void control_kitchen_fan_on();
void control_kitchen_fan_off();
void control_kitchen_gas_fan_on();
void control_kitchen_gas_fan_off();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode (light_outside_1, OUTPUT);
  pinMode (light_outside_2, OUTPUT);
  pinMode (dht11_outside, INPUT);
  pinMode (light_livingroom, OUTPUT);
  pinMode (curtain_livingroom, OUTPUT);
  pinMode (fan_livingroom, OUTPUT);
  pinMode (air_conditioner_livingroom, OUTPUT);
  pinMode (light_kitchen, OUTPUT);
  pinMode (fan_kitchen, OUTPUT);
  pinMode (gas_fan_kitchen, OUTPUT);
  pinMode (gas_kitchen, INPUT);
  pinMode (dht11_kitchen, INPUT);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(SSID_SR,PASSWORD_SR);
  // Set static IP address for Access Point (AP) mode
  if (!WiFi.softAPConfig(staticIP_AP, gateway_AP, subnet_AP)) {
    Serial.println("AP Failed to configure static IP");
  }
  server.on("/",home);
  server.on("/getState",getState);
  server.on("/control/outside/light_1/ON",control_outside_light_1_on);
  server.on("/control/outside/light_1/OFF",control_outside_light_1_off);
  server.on("/control/outside/light_2/ON",control_outside_light_2_on);
  server.on("/control/outside/light_2/OFF",control_outside_light_2_off);
  server.on("/control/livingroom/light/ON",control_livingroom_light_on);
  server.on("/control/livingroom/light/OFF",control_livingroom_light_off);
  server.on("/control/livingroom/curtain/ON",control_livingroom_curtain_on);
  server.on("/control/livingroom/curtain/OFF",control_livingroom_curtain_off);
  server.on("/control/livingroom/fan/ON",control_livingroom_fan_on);
  server.on("/control/livingroom/fan/OFF",control_livingroom_fan_off);
  server.on("/control/livingroom/air_conditioner/ON",control_livingroom_air_conditioner_on);
  server.on("/control/livingroom/air_conditioner/OFF",control_livingroom_air_conditioner_off);
  server.on("/control/kitchen/light/ON",control_kitchen_light_on);
  server.on("/control/kitchen/light/OFF",control_kitchen_light_off);
  server.on("/control/kitchen/fan/ON",control_kitchen_fan_on);
  server.on("/control/kitchen/fan/OFF",control_kitchen_fan_off);
  server.on("/control/kitchen/gas_fan/ON",control_kitchen_gas_fan_on);
  server.on("/control/kitchen/gas_fan/OFF",control_kitchen_gas_fan_off);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void home(){
  server.send(200,"text/html",Web);
}
void getState(){
  if(server.method() == HTTP_GET){
    StaticJsonDocument<1024> doc;
    deserializeJson(doc, stateHomeString);

    (digitalRead(light_outside_1) == 1) ? doc["outDoor"]["lightGarden"]["light1"] = "ON" : doc["outDoor"]["lightGarden"]["light1"] = "OFF";
    (digitalRead(light_outside_2) == 1) ? doc["outDoor"]["lightGarden"]["light2"] = "ON" : doc["outDoor"]["lightGarden"]["light2"] = "OFF";

    (digitalRead(light_livingroom) == 1) ? doc["livingRoom"]["light"] = "ON" : doc["livingRoom"]["light"] = "OFF";
    (digitalRead(curtain_livingroom) == 1) ? doc["livingRoom"]["curtain"] = "ON" : doc["livingRoom"]["curtain"] = "OFF";
    (digitalRead(fan_livingroom) == 1) ? doc["livingRoom"]["fan"] = "ON" : doc["livingRoom"]["fan"] = "OFF";
    (digitalRead(air_conditioner_livingroom) == 1) ? doc["livingRoom"]["airConditioner"] = "ON" : doc["livingRoom"]["airConditioner"] = "OFF";

    (digitalRead(light_kitchen) == 1) ? doc["kitchen"]["light"] = "ON" : doc["kitchen"]["light"] = "OFF";
    (digitalRead(fan_kitchen) == 1) ? doc["kitchen"]["fan"] = "ON" : doc["kitchen"]["fan"] = "OFF";
    (digitalRead(gas_fan_kitchen) == 1) ? doc["kitchen"]["stateFanGas"] = "ON" : doc["kitchen"]["stateFanGas"] = "OFF";

    serializeJson(doc, stateHomeStringLast);
    server.send(200,"text/json", stateHomeStringLast);
  }
}

void control_outside_light_1_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_outside_1,1);
    server.send(200,"text/plain","done");
  }
}
void control_outside_light_1_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_outside_1,0);
    server.send(200,"text/plain","done");
  }
}
void control_outside_light_2_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_outside_2,1);
    server.send(200,"text/plain","done");
  }
}
void control_outside_light_2_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_outside_2,0);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_light_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_livingroom,1);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_light_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_livingroom,0);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_curtain_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(curtain_livingroom,1);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_curtain_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(curtain_livingroom,0);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_fan_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(fan_livingroom,1);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_fan_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(fan_livingroom,0);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_air_conditioner_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(air_conditioner_livingroom,1);
    server.send(200,"text/plain","done");
  }
}
void control_livingroom_air_conditioner_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(air_conditioner_livingroom,0);
    server.send(200,"text/plain","done");
  }
}
void control_kitchen_light_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_kitchen,1);
    server.send(200,"text/plain","done");
  }
}
void control_kitchen_light_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(light_kitchen,0);
    server.send(200,"text/plain","done");
  }
}
void control_kitchen_fan_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(fan_kitchen,1);
    server.send(200,"text/plain","done");
  }
}
void control_kitchen_fan_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(fan_kitchen,0);
    server.send(200,"text/plain","done");
  }
}
void control_kitchen_gas_fan_on(){
  if(server.method() == HTTP_GET){
    digitalWrite(gas_fan_kitchen,1);
    server.send(200,"text/plain","done");
  }
}
void control_kitchen_gas_fan_off(){
  if(server.method() == HTTP_GET){
    digitalWrite(gas_fan_kitchen,0);
    server.send(200,"text/plain","done");
  }
}