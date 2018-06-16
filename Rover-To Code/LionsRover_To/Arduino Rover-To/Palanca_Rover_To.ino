#include <Servo.h>
#include <Wire.h>
#include <LSM303.h>

Servo servo; 
LSM303 compass;
int co2 = A3;
int angle = 90;
char isOn = '0'; 
int lectAngle; 
int initAngle;
int balanceAngle;
int selection;
int toxicity = 0;
int isAngleInit = false;
int actualAngle; 
int unitCircle[360];
char selectorChar = 'u';

void setup() {
  pinMode(co2, INPUT);
  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){-2000, -1870, -2366};
  compass.m_max = (LSM303::vector<int16_t>){+5221, +2410, +1372};
  servo.attach(3);

  for(int i=0; i<360; i++){//until 359
    unitCircle[i] = i;
    }
}


void loop() {
int toxicity = analogRead(co2);
compass.read();
float heading = compass.heading();

lectAngle = heading;

/*
for(int i=0; i<30; i++){
  lectAngle = map(compass.a.x, -16200, 16200, 0, 360);
  }
  lectAngle/=30;//30 lectures average
*/

if(!isAngleInit){
  initAngle = lectAngle; 
  isAngleInit = true; 
}

actualAngle = lectAngle - initAngle;

/*
 *selector chars
u - up
d - down
r - right
l - left
*/

if((actualAngle>315&&actualAngle<360)||actualAngle<45){
  selectorChar = 'u';
  }
if(actualAngle > 45 && actualAngle < 135){
  selectorChar = 'r';
  }
if(actualAngle > 135 && actualAngle < 225){
  selectorChar = 'd';
  }
if(actualAngle > 225 && actualAngle < 315){
  selectorChar = 'l';
  }
  

isOn = (char)Serial.read();

if(isOn == '1'){
  angle+=5;
  if(angle>=170) angle = 170;
  //Serial.println(angle);
  }
if(isOn == '0'){
  //Serial.println(angle);
  }

if(isOn == '2'){
  angle-=5; 
  if(angle<=20) angle = 20;
  //Serial.println(angle);
  }
  servo.write(angle);
  isOn = '0'; 
  Serial.print("*");
  Serial.print(selectorChar);
  Serial.print(",");
  Serial.print(toxicity);
  Serial.print("*");
  Serial.println();

}
