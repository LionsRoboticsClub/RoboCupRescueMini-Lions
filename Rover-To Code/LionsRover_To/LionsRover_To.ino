#define DXL_BUS_SERIAL1 1
//ARM
#define M1 1
#define M2 2
#define M3 3
#define M4 4
#define M5 5
//WHEELS
#define M6 6
#define M7 7
#define M8 8
#define M9 9
#define M10 10
#define M11 11
//SERVOS
#define M12 12
#define M13 13
#define M14 14
#define M15 15
#define M16 16
#define M17 17
//^^^^^^^^^^^^

//VARIABLES
Dynamixel Dxl (DXL_BUS_SERIAL1);
  int Vel = 1000;

  //brazo
  /*
    1->512
    2->350
    3->800
    4->950
    5->800
*/

  int m1Angle = 1023/2;
  int m2Angle = 350; 
  int m3Angle = 800;
  int m4Angle = 950; 
  int m5Angle = 800; 

  //servos
  int m12Angle = 200;
  int m13Angle = 1023/2;
  int m14Angle = 1023/2;
  int m15Angle = 1023/2;
  int m16Angle = 1023/2;
  int m17Angle = 1023/2;

  const int minAngle = 10; 
  const int maxAngle = 290;
  const int deltaAngle = 20;

  const int highSpeed = 1000;
  const int midSpeed = 600;
  const int lowSpeed = 300; 
  int directionAngle = 512;
  
  char actualState = 't'; 

//SETUP
void setup(){
  SerialUSB.begin(); 
  Dxl.begin(3);
  Dxl.jointMode(M1);
  Dxl.maxTorque(M2, 1023);
  Dxl.jointMode(M2);
  Dxl.jointMode(M3);
  Dxl.maxTorque(M4, 1023);
  Dxl.jointMode(M4);
  Dxl.maxTorque(M5, 1023);
  Dxl.jointMode(M5);
  //Dxl.maxTorque(M6, 1023);
  Dxl.wheelMode(M6);
  Dxl.maxTorque(M7, 1023);
  Dxl.wheelMode(M7);
  Dxl.maxTorque(M8, 1023);
  Dxl.wheelMode(M8);
  Dxl.maxTorque(M9, 1023);
  Dxl.wheelMode(M9);
  Dxl.maxTorque(M10, 1023);
  Dxl.wheelMode(M10);
  Dxl.maxTorque(M11, 1023);
  Dxl.wheelMode(M11);
  Dxl.jointMode(M12);
  Dxl.jointMode(M13);
  Dxl.jointMode(M14);
  Dxl.jointMode(M15);
  Dxl.jointMode(M16);
  Dxl.jointMode(M17);
}

  void loop(){
  if (SerialUSB.available()){
    char c = SerialUSB.read(); 
    if (c == 'l'){ 
      SerialUSB.print("derecha ");
      m1Angle-=deltaAngle;
      if(m1Angle<=0) 
        m1Angle=0;
      Dxl.goalPosition(M1, m1Angle);
      SerialUSB.println(m1Angle);
      delay(2);
    }
    if (c == 'j'){ 
      SerialUSB.print("izquierda ");
      m1Angle+=deltaAngle;
      if(m1Angle >= 1000) 
        m1Angle = 1000; 
      Dxl.goalPosition(M1, m1Angle);
      SerialUSB.println(m1Angle);
      delay(2);
    }else if (c == 'i'){
      SerialUSB.println("m2 enfrente");
      m2Angle-=deltaAngle;
      if(m2Angle<=0) 
        m2Angle=0;
      Dxl.setPosition(M2, m2Angle, 100); 
      //Dxl.goalPosition(M2, m2Angle);
      delay(2);
    }else if (c == 'k'){ 
      SerialUSB.println("m2 atras");
      m2Angle+=deltaAngle;
      if(m2Angle>=1000) 
        m2Angle = 1000;
      Dxl.setPosition(M2, m2Angle, 100); 
      //Dxl.goalPosition(M2, m2Angle);
      delay(2);
    }else if (c == 'p'){
      SerialUSB.println("garra abre");  
      m5Angle-=deltaAngle;     
      if(m5Angle<=400) 
        m5Angle=400;
      Dxl.setPosition(M5, m5Angle, 100);       
      //Dxl.goalPosition(M5, m5Angle);
      delay(2); 
    }else if (c == 'o'){
      SerialUSB.println("garra cierra");
      m5Angle+=deltaAngle; 
      if(m5Angle>=1000) 
        m5Angle = 1000;
      Dxl.setPosition(M5, m5Angle, 100); 
      //Dxl.goalPosition(M5, m5Angle);
      delay(2);
    }else if (c == 'u'){
      SerialUSB.println("garra Derecha");
      m3Angle-=deltaAngle;
      if(m3Angle<=0) 
        m3Angle=0;
      Dxl.goalPosition(M3, m3Angle);
      delay(2);
    }else if (c == 'y'){
      SerialUSB.println("garra Izquierda");
      m3Angle+=deltaAngle;
      if(m3Angle>=1000) 
        m3Angle = 1000;
      Dxl.goalPosition(M3, m3Angle);
      delay(2);
    }else if(c == 't'){
      actualState = c;
      SerialUSB.println("llantas adelante");
      Dxl.goalPosition(M12, 512);
      Dxl.goalPosition(M13, 512);
      Dxl.goalPosition(M14, 512);
      Dxl.goalPosition(M15, 512);
      Dxl.goalPosition(M16, 512);
      Dxl.goalPosition(M17, 512);
    }else if(c=='f'){
      actualState = c;
      SerialUSB.println("llantas circulo");
      Dxl.goalPosition(M12, 200);
      Dxl.goalPosition(M13, 200);
      Dxl.goalPosition(M14, 200);
      Dxl.goalPosition(M15, 200);
      Dxl.goalPosition(M16, 200);
      Dxl.goalPosition(M17, 200);
    }else if(c=='x'){
      actualState = c;
      SerialUSB.println("llantas de lado");
      Dxl.goalPosition(M12, 300);
      Dxl.goalPosition(M13, 512);
      Dxl.goalPosition(M14, 700);
      Dxl.goalPosition(M15, 700);
      Dxl.goalPosition(M16, 512);
      Dxl.goalPosition(M17, 300);
    }else if (c == 'm'){
      SerialUSB.println("m4 adelante");
      m4Angle-=deltaAngle;
      if(m4Angle<=100) 
        m4Angle=100;
      Dxl.goalPosition(M4, m4Angle);
      delay(2);
    }else if (c == 'n'){
      SerialUSB.println("m4 atras");
      m4Angle+=deltaAngle;
      if(m4Angle>=900) 
        m4Angle = 900;
      Dxl.goalPosition(M4,m4Angle+=deltaAngle);
      delay(2); 
    }else if(c == 'z'){
      SerialUSB.println("pos inicial");
      Dxl.setPosition(M1,512,100);
      Dxl.setPosition(M2,350,100);
      Dxl.setPosition(M3,800,100);
      Dxl.setPosition(M4,950,100);
      m1Angle = 512; 
      m2Angle = 350; 
      m3Angle = 800;
      m4Angle = 950;
    }
    if (c == 'w'){ 

      if(actualState == 'x'){
      actualState = 't';
      SerialUSB.println("llantas adelante");
      Dxl.goalPosition(M12, 512);
      Dxl.goalPosition(M13, 512);
      Dxl.goalPosition(M14, 512);
      Dxl.goalPosition(M15, 512);
      Dxl.goalPosition(M16, 512);
      Dxl.goalPosition(M17, 512);
      }

      SerialUSB.println("adelante");
      Dxl.cwTurn(M6, Vel);
      Dxl.cwTurn(M7, Vel);
      Dxl.cwTurn(M8, Vel);
      Dxl.ccwTurn(M9, Vel);
      Dxl.ccwTurn(M10, Vel);
      Dxl.ccwTurn(M11, Vel);
      delay(150);
      Dxl.goalSpeed(M6, 0);
      Dxl.goalSpeed(M7, 0);
      Dxl.goalSpeed(M8, 0);
      Dxl.goalSpeed(M9, 0);
      Dxl.goalSpeed(M10, 0);
      Dxl.goalSpeed(M11, 0);
    }

    if (c == 's'){ 
      if(actualState == 'x'){

      actualState = 't';
      SerialUSB.println("llantas adelante");
      Dxl.goalPosition(M12, 512);
      Dxl.goalPosition(M13, 512);
      Dxl.goalPosition(M14, 512);
      Dxl.goalPosition(M15, 512);
      Dxl.goalPosition(M16, 512);
      Dxl.goalPosition(M17, 512);

      }

      SerialUSB.println("atras");

      Dxl.ccwTurn(M6, Vel);
      Dxl.ccwTurn(M7, Vel);
      Dxl.ccwTurn(M8, Vel);
      Dxl.cwTurn(M9, Vel);
      Dxl.cwTurn(M10, Vel);
      Dxl.cwTurn(M11, Vel);
      delay(150);
      Dxl.goalSpeed(M6, 0);
      Dxl.goalSpeed(M7, 0);
      Dxl.goalSpeed(M8, 0);
      Dxl.goalSpeed(M9, 0);
      Dxl.goalSpeed(M10, 0);
      Dxl.goalSpeed(M11, 0);
    }else if (c == 'a' && actualState != 'f'){
      SerialUSB.println("izquierda");

      actualState = 'x';
      SerialUSB.println("llantas circulo");
      Dxl.goalPosition(M12, 200);
      Dxl.goalPosition(M13, 200);
      Dxl.goalPosition(M14, 200);
      Dxl.goalPosition(M15, 200);
      Dxl.goalPosition(M16, 200);
      Dxl.goalPosition(M17, 200);

      Dxl.cwTurn(M6, Vel);
      Dxl.cwTurn(M7, Vel);
      Dxl.cwTurn(M8, Vel);
      Dxl.cwTurn(M9, Vel);
      Dxl.cwTurn(M10, Vel);
      Dxl.cwTurn(M11, Vel);
      delay(150);
      Dxl.goalSpeed(M6, 0);
      Dxl.goalSpeed(M7, 0);
      Dxl.goalSpeed(M8, 0);
      Dxl.goalSpeed(M9, 0);
      Dxl.goalSpeed(M10, 0);
      Dxl.goalSpeed(M11, 0);
    }else if (c == 'd' && actualState != 'f'){
      SerialUSB.println("derecha");   

      actualState = 'x';
      SerialUSB.println("llantas circulo");
      Dxl.goalPosition(M12, 200);
      Dxl.goalPosition(M13, 200);
      Dxl.goalPosition(M14, 200);
      Dxl.goalPosition(M15, 200);
      Dxl.goalPosition(M16, 200);
      Dxl.goalPosition(M17, 200);

      Dxl.ccwTurn(M6, Vel);
      Dxl.ccwTurn(M7, Vel);
      Dxl.ccwTurn(M8, Vel);
      Dxl.ccwTurn(M9, Vel);
      Dxl.ccwTurn(M10, Vel);
      Dxl.ccwTurn(M11, Vel);
      delay(150);
      Dxl.goalSpeed(M6, 0);
      Dxl.goalSpeed(M7, 0);
      Dxl.goalSpeed(M8, 0);
      Dxl.goalSpeed(M9, 0);
      Dxl.goalSpeed(M10, 0);
      Dxl.goalSpeed(M11, 0);
    }else if (c == 'e'){
         SerialUSB.println("Velocidad Mas");
         if (Vel + 300 >= 1000)
           Vel = 1000;
         else
         Vel += 300;
      }else if (c == 'r'){
         SerialUSB.println("Velocidad Menos");
         if (Vel - 300 <= 400)
           Vel = 400;
         else
         Vel -= 300;
    }
  }
}
