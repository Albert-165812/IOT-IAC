#define BTN_LIGHT_OUTSIDE_1 1
#define BTN_LIGHT_OUTSIDE_2 1
// #define TEMPERATURE_OUTSIDE 1
#define BTN_LIGHT_LIVINGROOM 1
#define BTN_FAN_LIVINGROOM 1
#define BTN_CURTAIN_LIVINGROOM 1
#define BTN_AIR_CONDITIONER_LIVINGROOM 1
#define BTN_AIR_FAN_KITCHEN 1
#define BTN_AIR_LIGHT_KITCHEN 1
// #define TEMPERATURE_KITCHEN 1

#define LIGHT_OUTSIDE_1 1
#define LIGHT_OUTSIDE_2 1

#define LIGHT_LIVINGROOM 1
#define FAN_LIVINGROOM 1
#define AIR_CONDITIONER_LIVINGROOM 1
#define CURTAIN_LIVINGROOM_a 1
#define CURTAIN_LIVINGROOM_b 1

#define LIGHT_KITCHEN 1
#define FAN_KITCHEN 1

int stateLightOutside_1 = 0;
int stateLightOutside_2 = 0;
int stateLightLivingRoom = 0;
int stateFanLivingRoom = 0;
int stateCurtainLivingRoom = 0;
int stateCurtainLivingRoom_a = 0;
int stateCurtainLivingRoom_b = 0;
int stateAirConditionerLivingRoom = 0;
int stateLightKitchen = 0;
int stateFanKitchen = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BTN_LIGHT_OUTSIDE_1,INPUT);
  pinMode(BTN_LIGHT_OUTSIDE_2,INPUT);
  // pinMode(TEMPERATURE_OUTSIDE,INPUT);
  pinMode(BTN_LIGHT_LIVINGROOM,INPUT);
  pinMode(BTN_FAN_LIVINGROOM,INPUT);
  pinMode(BTN_CURTAIN_LIVINGROOM,INPUT);
  pinMode(BTN_AIR_CONDITIONER_LIVINGROOM,INPUT);
  pinMode(BTN_AIR_FAN_KITCHEN,INPUT);
  pinMode(BTN_AIR_LIGHT_KITCHEN,INPUT);
  // pinMode(TEMPERATURE_KITCHEN,INPUT);

  pinMode(LIGHT_OUTSIDE_1,OUTPUT);
  pinMode(LIGHT_OUTSIDE_2,OUTPUT);
  pinMode(LIGHT_LIVINGROOM,OUTPUT);
  pinMode(FAN_LIVINGROOM,OUTPUT);
  pinMode(AIR_CONDITIONER_LIVINGROOM,OUTPUT);
  pinMode(CURTAIN_LIVINGROOM_a,OUTPUT);
  pinMode(CURTAIN_LIVINGROOM_b,OUTPUT);
  pinMode(LIGHT_KITCHEN,OUTPUT);
  pinMode(FAN_KITCHEN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BTN_LIGHT_OUTSIDE_1) == 1){
    delay(20);
    if(digitalRead(BTN_LIGHT_OUTSIDE_1) == 1){
      (stateLightOutside_1 == 1) ? stateLightOutside_1 = 0 : stateLightOutside_1 = 1; 
    while(digitalRead(BTN_LIGHT_OUTSIDE_1) == 1);
    }
  }
  if(digitalRead(BTN_LIGHT_OUTSIDE_2) == 1){
    delay(20);
    if(digitalRead(BTN_LIGHT_OUTSIDE_2) == 1){
      (stateLightOutside_2 == 1) ? stateLightOutside_2 = 0 : stateLightOutside_2 = 1; 
    while(digitalRead(BTN_LIGHT_OUTSIDE_2) == 1);
    }
  }

  if(digitalRead(BTN_LIGHT_LIVINGROOM) == 1){
    delay(20);
    if(digitalRead(BTN_LIGHT_LIVINGROOM) == 1){
      (stateLightLivingRoom == 1) ? stateLightLivingRoom = 0 : stateLightLivingRoom = 1; 
    while(digitalRead(BTN_LIGHT_LIVINGROOM) == 1);
    }
  }
  if(digitalRead(BTN_FAN_LIVINGROOM) == 1){
    delay(20);
    if(digitalRead(BTN_FAN_LIVINGROOM) == 1){
      (stateFanLivingRoom == 1) ? stateFanLivingRoom = 0 : stateFanLivingRoom = 1; 
    while(digitalRead(BTN_FAN_LIVINGROOM) == 1);
    }
  }
  if(digitalRead(BTN_CURTAIN_LIVINGROOM) == 1){
    delay(20);
    if(digitalRead(BTN_CURTAIN_LIVINGROOM) == 1){
      (stateFanLivingRoom == 1) ? stateFanLivingRoom = 0 : stateFanLivingRoom = 1; 
    while(digitalRead(BTN_CURTAIN_LIVINGROOM) == 1);
    }
  }
  // conf nuax
  if(digitalRead(BTN_FAN_LIVINGROOM) == 1){
    delay(20);
    if(digitalRead(BTN_FAN_LIVINGROOM) == 1){
      (stateFanLivingRoom == 1) ? stateFanLivingRoom = 0 : stateFanLivingRoom = 1; 
    while();
    }
  }
  control_device();
}
void control_device(){
  digitalWrite(LIGHT_OUTSIDE_1,stateLightOutside_1);
  digitalWrite(LIGHT_OUTSIDE_2,stateLightOutside_2);
  digitalWrite(LIGHT_LIVINGROOM,stateLightLivingRoom);
  digitalWrite(FAN_LIVINGROOM,stateFanLivingRoom);
  digitalWrite(AIR_CONDITIONER_LIVINGROOM,stateAirConditionerLivingRoom);
  digitalWrite(CURTAIN_LIVINGROOM_a,stateCurtainLivingRoom_a);
  digitalWrite(CURTAIN_LIVINGROOM_b,stateCurtainLivingRoom_b);
  digitalWrite(LIGHT_KITCHEN,stateLightKitchen);
  digitalWrite(FAN_KITCHEN,stateFanKitchen);
}