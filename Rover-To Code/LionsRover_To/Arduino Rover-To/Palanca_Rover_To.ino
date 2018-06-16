#include <Servo.h>

Servo servo; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

servo.attach(3);
}

int angle = 90; 
char isOn = '0'; 

void loop() {

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
  // put your main code here, to run repeatedly:

}
