#include <Wire.h>
#include <LSM303.h>
#include <Servo.h>

Servo servo;

LSM303 compass;

int co2 = A0;

void setup()
{
  pinMode(co2, INPUT);
  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.m_min = (LSM303::vector<int16_t>){-2000, -1870, -2366};
  compass.m_max = (LSM303::vector<int16_t>){+5221, +2410, +1372};
  servo.attach(3);
}

int angle; 
int balanceAngle;
int selection;
long long sum = 0;
int stack = 0;
int toxicity = 0;

void loop()
{
  int toxicity = analogRead(co2);
  compass.read();
  float heading = compass.heading();
  angle = map(compass.a.x, -16200, 16200, 0, 360);
  selection = map(angle, 0, 360, 1, 10);
  switch(selection){
    case(1):{
      /*10->1000*/
      /*0->1024*/
      balanceAngle = 180;
      break;
      }
    case(2):{
      balanceAngle = 160;
      break;
      }
    case(3):{
      balanceAngle = 120;
      break;
      }
    case(4):{
      balanceAngle = 80;
      break;
      }
    case(5):{
      balanceAngle = 70;
      break;
      }
    case(6):{
      balanceAngle = 60;
      break;
      }
    case(7):{
      balanceAngle =50;
      break;
      }
    case(8):{
      balanceAngle = 40;
      break;
      }
    case(9):{
      balanceAngle = 30;
      break;
      }
    case(10):{
      balanceAngle = 0;
      break;
      }
    }
    balanceAngle +=6;
    
    sum++;
    sum%=1000000007;
    stack += balanceAngle;

    if(sum%20==0){ //actualiza 5 veces por segundo
      //Serial.print(angle); 
      //Serial.print(": ");
      servo.write(stack/20);
      Serial.print("*");
      Serial.print(stack/20);
      Serial.print(",");
      Serial.print(heading);
      Serial.print(",");
      Serial.print(toxicity);
      Serial.print("*");
      Serial.println();
      stack = 0;
    }
  delay(10);
}
