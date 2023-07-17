#include <DHT11.h>

#include <Keypad.h>
#include <Servo.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

#define BTN_LIGHT_OUTSIDE 22
#define BTN_LIGHT_INSIDE 23
#define BTN_FAN_INSIDE 24
#define BTN_CURTAIN_INSIDE 25

#define LIGHT_OUTSIDE 26
#define LIGHT_INSIDE 27
#define FAN_INSIDE 28
#define CURTAIN_INSIDE_A 29
#define CURTAIN_INSIDE_B 30

#define TEMP 11
#define servo 10

DHT11 dht11(TEMP);

const byte ROWS = 4; 
const byte COLS = 4;
char MatrixKey[ROWS][COLS] = 
{
  {'7','8','9','F'},
  {'4','5','6','E'},
  {'1','2','3','D'},
  {'A','0','B','C'}
};
byte rowPins[ROWS] = {2,3,4,5}; // R1,R2,R3,R4
byte colPins[COLS] = {6,7,8,9}; // C1,C2,C3,C4

Keypad Mykeys = Keypad( makeKeymap(MatrixKey), rowPins, colPins, ROWS, COLS); 

// 
char password[5];
char On_equip[]="5522";
char Off_equip[]="2211";

int i,on;

int STATE_LIGHT_OUTSIDE = 0;
int STATE_LIGHT_INSIDE = 0;
int STATE_FAN_INSIDE = 0;
int STATE_CURTAIN_INSIDE = 0;
int STATE_COUNT_CURTAIN_INSIDE = 0;
String STATE_WARMING_DOOR = "NO-WARMING";
String STATE_CLOSE_DOOR = "CLOSE";
unsigned long previousMillis = 0;
int STATE_TEMPERATURE = 0;
int STATE_HUMIDITY = 0;
const unsigned long interval = 3000; // Thời gian delay 1000 milliseconds (1 giây)

void setup(){
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(BTN_LIGHT_OUTSIDE,INPUT);
  pinMode(BTN_LIGHT_INSIDE,INPUT);
  pinMode(BTN_FAN_INSIDE,INPUT);
  pinMode(BTN_CURTAIN_INSIDE,INPUT);

  pinMode(LIGHT_OUTSIDE,OUTPUT);
  pinMode(LIGHT_INSIDE,OUTPUT);
  pinMode(FAN_INSIDE,OUTPUT);
  pinMode(CURTAIN_INSIDE_A,OUTPUT);
  pinMode(CURTAIN_INSIDE_B,OUTPUT);

  lcd.init();
  lcd.backlight();

  myservo.attach(servo); 
  myservo.write (90);
  Serial.println("mega");
  lcd.setCursor(4,0);
  lcd.print("HI - IAC");
}
void loop(){
  check_data_recv();
  checkPass();
  readTemp();
  check_btn();
  output_device();
  send_data();
}
void readTemp(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    float humidity = dht11.readHumidity();
    float temperature = dht11.readTemperature();
    if (temperature != -1 && humidity != -1)
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" C");
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
        STATE_TEMPERATURE = (int)temperature;
        STATE_HUMIDITY = (int)humidity;
    }
    else
    {
        Serial.println("Error reading data");
    }
  }
}
void checkPass(){
  char EnterKey = Mykeys.getKey();
  if(EnterKey){
    if(i == 0){
      lcd.setCursor(1,0);
      lcd.print("Enter Password");
    }
    if(EnterKey){
      password[i]=EnterKey;
      i++;
      on++;
      Serial.println(password);
      if (i == 0) {
        password[0] = EnterKey;
        lcd.setCursor(6, 1);
        lcd.print(password[0]);
        delay(500);
        lcd.setCursor(6, 1);
        lcd.print("*");
      }
      if (i == 1) {
        password[1] = EnterKey;
        lcd.setCursor(7, 1);
        lcd.print(password[1]);
        delay(500);
        lcd.setCursor(7, 1);
        lcd.print("*");
      }
      if (i == 2) {
        password[2] = EnterKey;
        lcd.setCursor(8, 1);
        lcd.print(password[2]);
        delay(500);
        lcd.setCursor(8, 1);
        lcd.print("*");
      }
      if (i == 3) {
        password[3] = EnterKey;
        lcd.setCursor(9, 1);
        lcd.print(password[3]);
        delay(500);
        lcd.setCursor(9, 1);
        lcd.print("*");
      }
    }
    if(on==4){
      if(!strcmp(password,On_equip)){
        lcd.clear();
        lcd.print("    Correct!");
        myservo.write(180);
        delay(1000);
        lcd.clear();
        lcd.print("      Opened!");
        i=0;
        Serial.println(" Dung mat khau mo cua!");
        STATE_WARMING_DOOR = "WARMING";
        STATE_CLOSE_DOOR = "OPEN";
      }
      if(!strcmp(password,Off_equip)){
        lcd.clear();
        myservo.write(120); // Đóng cửa 
        lcd.print("     Closed!");
        delay(2000);
        lcd.clear();
        lcd.print(" Enter Password");
        i=0;
        STATE_WARMING_DOOR = "NO-WARMING";
        STATE_CLOSE_DOOR = "CLOSE";
      }
      if(strcmp(password,On_equip)){
        if(strcmp(password,Off_equip)){
          lcd.clear();
          lcd.print("   Incorrect!");
          delay(1000);
          lcd.clear();
          lcd.print("   Try Again!");
          delay(1000);
          lcd.clear();
          lcd.print(" Enter Password");
          i = 0;
          Serial.println(" Sai mat khau nhap lai.............");
          STATE_WARMING_DOOR = "STRANGER";
          STATE_CLOSE_DOOR = "CLOSE";
        }
      }
      on=0;
    }
  }
}
void check_data_recv(){
  if(Serial3.available()){
    String data = Serial3.readString();
    if(data = "outside_light_on"){
      STATE_LIGHT_OUTSIDE = 1;
    }
    if(data = "outside_light_off"){
      STATE_LIGHT_OUTSIDE = 0;
    }
    if(data = "inside_light_on"){
      STATE_LIGHT_INSIDE = 1;
    }
    if(data = "inside_light_off"){
      STATE_LIGHT_INSIDE = 0;
    }
    if(data = "inside_fan_on"){
      STATE_FAN_INSIDE = 1;
    }
    if(data = "inside_fan_off"){
      STATE_FAN_INSIDE = 0;
    }
    if(data = "inside_curtain_on"){
      STATE_CURTAIN_INSIDE = 1;
    }
    if(data = "inside_curtain_off"){
      STATE_CURTAIN_INSIDE = 0;
    }
  }
}
void send_data(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    // String data = "{\"outside\":{\"light\":"+(String)STATE_LIGHT_OUTSIDE+",\"temperature\":"+String(STATE_TEMPERATURE)+",\"humidity\":"+String(STATE_HUMIDITY)+",\"door\":{\"warming\":\""+STATE_WARMING_DOOR+"\",\"state\":\""+STATE_CLOSE_DOOR+"\"}},\"inside\":{\"light\":"+(String)STATE_LIGHT_INSIDE+",\"fan\":"+(String)STATE_FAN_INSIDE+",\"curtain\":"+(String)STATE_CURTAIN_INSIDE+"}}";
    Serial3.print("{\"outside\":{\"light\":"+(String)STATE_LIGHT_OUTSIDE+",\"temperature\":"+String(STATE_TEMPERATURE)+",\"humidity\":"+String(STATE_HUMIDITY)+",\"door\":{\"warming\":\""+STATE_WARMING_DOOR+"\",\"state\":\""+STATE_CLOSE_DOOR+"\"}},\"inside\":{\"light\":"+(String)STATE_LIGHT_INSIDE+",\"fan\":"+(String)STATE_FAN_INSIDE+",\"curtain\":"+(String)STATE_CURTAIN_INSIDE+"}}");
  }
}
void check_btn(){
  if(digitalRead(BTN_LIGHT_OUTSIDE) == 1){
    delay(20);
    if(digitalRead(BTN_LIGHT_OUTSIDE) == 1){
      if(STATE_LIGHT_OUTSIDE == 0){
        STATE_LIGHT_OUTSIDE = 1;
      }
      else{
        STATE_LIGHT_OUTSIDE = 0;
      }
      while(digitalRead(BTN_LIGHT_OUTSIDE) == 1);
    }
  }
  if(digitalRead(BTN_LIGHT_INSIDE) == 1){
    delay(20);
    if(digitalRead(BTN_LIGHT_INSIDE) == 1){
      if(STATE_LIGHT_INSIDE == 0){
        STATE_LIGHT_INSIDE = 1;
      }
      else{
        STATE_LIGHT_INSIDE = 0;
      }
      while(digitalRead(BTN_LIGHT_INSIDE) == 1);
    }
  }
  if(digitalRead(BTN_FAN_INSIDE) == 1){
    delay(20);
    if(digitalRead(BTN_FAN_INSIDE) == 1){
      if(STATE_FAN_INSIDE == 0){
        STATE_FAN_INSIDE = 1;
      }
      else{
        STATE_FAN_INSIDE = 0;
      }
      while(digitalRead(BTN_FAN_INSIDE) == 1);
    }
  }
  if(digitalRead(BTN_CURTAIN_INSIDE) == 1){
    delay(20);
    if(digitalRead(BTN_CURTAIN_INSIDE) == 1){
      if(STATE_CURTAIN_INSIDE == 0){
        STATE_CURTAIN_INSIDE = 1;
        STATE_COUNT_CURTAIN_INSIDE = 0;
      }
      else{
        STATE_CURTAIN_INSIDE = 0;
        STATE_COUNT_CURTAIN_INSIDE = 0;
      }
      while(digitalRead(BTN_CURTAIN_INSIDE) == 1);
    }
  }
}
void output_device(){
  digitalWrite(LIGHT_OUTSIDE,STATE_LIGHT_OUTSIDE);
  digitalWrite(LIGHT_INSIDE,STATE_LIGHT_INSIDE);
  digitalWrite(FAN_INSIDE,STATE_FAN_INSIDE);
  if(STATE_CURTAIN_INSIDE == 1){
    if(STATE_COUNT_CURTAIN_INSIDE == 0){
      digitalWrite(CURTAIN_INSIDE_A,1);
      digitalWrite(CURTAIN_INSIDE_B,0);
      delay(2000);
      digitalWrite(CURTAIN_INSIDE_A,0);
      digitalWrite(CURTAIN_INSIDE_B,0);
      STATE_COUNT_CURTAIN_INSIDE++;
    }
  }
  else{
    if(STATE_COUNT_CURTAIN_INSIDE == 0){
      digitalWrite(CURTAIN_INSIDE_A,0);
      digitalWrite(CURTAIN_INSIDE_B,1);
      delay(2000);
      digitalWrite(CURTAIN_INSIDE_A,0);
      digitalWrite(CURTAIN_INSIDE_B,0);
      STATE_COUNT_CURTAIN_INSIDE++;
    }
  }
}