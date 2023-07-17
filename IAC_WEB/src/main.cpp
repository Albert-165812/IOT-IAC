#include "main.h"

ESP8266WebServer    server(80);

void home();
void getState();
void control_outside_light_on();
void control_outside_light_off();
void control_inside_light_on();
void control_inside_light_off();
void control_inside_fan_on();
void control_inside_fan_off();
void control_inside_curtain_on();
void control_inside_curtain_off();

void getData();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mySerial.begin(9600);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(SSID_SR,PASSWORD_SR);
  // Set static IP address for Access Point (AP) mode
  if (!WiFi.softAPConfig(staticIP_AP, gateway_AP, subnet_AP)) {
    Serial.println("AP Failed to configure static IP");
  }
  server.on("/",home);
  server.on("/getState",getState);
  server.on("/control/outside/light/on",control_outside_light_on);
  server.on("/control/outside/light/off",control_outside_light_off);
  server.on("/control/inside/light/on",control_inside_light_on);
  server.on("/control/inside/light/off",control_inside_light_off);
  server.on("/control/inside/fan/on",control_inside_fan_on);
  server.on("/control/inside/fan/off",control_inside_fan_off);
  server.on("/control/inside/curtain/on",control_inside_curtain_on);
  server.on("/control/inside/curtain/off",control_inside_curtain_off);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  getData();
}
void getData(){
  if(mySerial.available()){
    stateHomeString = mySerial.readString();
  }
}
void home(){
  server.send(200,"text/html",Web);
}

void getState(){
  if(server.method() == HTTP_GET){
    server.send(200,"application/json", stateHomeString);
  }
}
void control_outside_light_on(){
  mySerial.write("outside_light_on");
  server.send(200,"text/plain","done");
};
void control_outside_light_off(){
  mySerial.write("outside_light_off");
  server.send(200,"text/plain","done");
};
void control_inside_light_on(){
  mySerial.write("inside_light_on");
  server.send(200,"text/plain","done");
};
void control_inside_light_off(){
  mySerial.write("inside_light_off");
  server.send(200,"text/plain","done");
};
void control_inside_fan_on(){
  mySerial.write("inside_fan_on");
  server.send(200,"text/plain","done");
};
void control_inside_fan_off(){
  mySerial.write("inside_fan_off");
  server.send(200,"text/plain","done");
};
void control_inside_curtain_on(){
  mySerial.write("inside_curtain_on");
  server.send(200,"text/plain","done");
};
void control_inside_curtain_off(){
  mySerial.write("inside_curtain_off");
  server.send(200,"text/plain","done");
};
