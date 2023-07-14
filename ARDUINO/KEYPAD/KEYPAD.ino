#include <SoftwareSerial.h>

#include <Keypad.h>
#include <Servo.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>      // Khai báo thư viện LCD sử dụng I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 địa chỉ LCD, 16 cột và 2 hàng
Servo myservo; //Tạo biến myServo của loại Servo

//pin 
int servo = 10;
int RedLed = 13;
const int trig = 11;     // chân trig của HC-SR04
const int echo = 12;     // chân echo của HC-SR04

#define rxPin A2
#define txPin A3

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

int i = 0;
int on = 0;
int countClr = 0;
const byte ROWS = 4; 
const byte COLS = 4; 

char password[5];
char On_equip[]="5522"; // Mật khẩu mở cửa
char Off_equip[]="2211"; // Mật khẩu đóng cửa

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(RedLed,OUTPUT);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);

  pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
  pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu

  lcd.init(); // Khởi tạo màn hình Màn hình
  lcd.backlight(); // Bật đèn màn hình Màn hình

  myservo.attach(servo); 
  myservo.write (0);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long duration; // biến đo thời gian
  int distance;           // biến lưu khoảng cách
  
  /* Phát xung từ chân trig */
  digitalWrite(trig,0);   // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig,1);   // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  digitalWrite(trig,0);   // tắt chân trig
  
  /* Tính toán thời gian */
  // Đo độ rộng xung HIGH ở chân echo. 
  duration = pulseIn(echo,HIGH);  
  // Tính khoảng cách đến vật.
  distance = int(duration/2/29.412); // khoảng cách cm
  char EnterKey = Mykeys.getKey();
  if(distance < 30){
    if(i == 0){
      lcd.setCursor(1,0);
      lcd.print("Enter Password");
    }
    if(EnterKey){
      password[i]=EnterKey; // Nhập lần lượt các ký tự vào biến chuỗi ký tự Psssword
      i++;
      on++;
      Serial.println(password);
      // Nhập mật khẩu
      if (i == 0) {
        password[0] = EnterKey;
        lcd.setCursor(6, 1);
        lcd.print(password[0]);
        delay(500); // Ký tự hiển thị trên màn hình LCD trong 0.5s
        lcd.setCursor(6, 1);
        lcd.print("*"); // Ký tự được thay bởi dấu *
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
        myservo.write(180); // Mở cửa!
        digitalWrite(RedLed,LOW);
        delay(1000);
        lcd.clear();
        lcd.print("      Opened!");
        i=0;
        Serial.println(" Dung mat khau mo cua!");
      }
      if(!strcmp(password,Off_equip)){
        lcd.clear();
        myservo.write(0); // Đóng cửa 
        lcd.print("     Closed!");
        digitalWrite(RedLed,0);
        delay(2000);
        lcd.clear();
        lcd.print(" Enter Password");
        i=0;
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
          digitalWrite(RedLed,1);
        }
      }
      on=0;
    }
    countClr = 0;
  }
  else{
    myservo.write(0); // Đóng cửa 
    if(countClr == 0){
      lcd.clear();
      countClr++;
    } 
    i = 0;
    on = 0;
    lcd.setCursor(4,0);
    lcd.print("Closed!");
  }
}
