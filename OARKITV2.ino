#define DXL_BUS_SERIAL1 1

#define M1 1
#define M2 2
#define M3 3
#define M4 4
#define M5 5
#define M6 6
#define M7 7
#define M8 8
#define M9 9
#define M10 10
#define M11 11

Dynamixel Dxl (DXL_BUS_SERIAL1);
  int Vel = 1000;
  int m1Angle = 1023/2;
  int m2Angle = 1023/2; 
  int m3Angle = 1023/2;
  int m4Angle = 1023/2; 
  int m5Angle = 1023/2; 
  int m6Angle = 1023/2; 

  const int minAngle = 10; 
  const int maxAngle = 290;
  const int deltaAngle = 20;
  const int highSpeed = 1000;
  const int midSpeed = 600;
  const int lowSpeed = 300; 


void setup () {
  SerialUSB.begin(); 
  Dxl.begin(3);
  Dxl.jointMode(M1);
  Dxl.jointMode(M2);
  Dxl.jointMode(M3);
  Dxl.jointMode(M4);
  Dxl.jointMode(M5);
  Dxl.wheelMode(M6);
  Dxl.wheelMode(M7);
  Dxl.wheelMode(M8);
  Dxl.wheelMode(M9);
  Dxl.wheelMode(M10);
  Dxl.wheelMode(M11);
}

void loop () {

      if (SerialUSB.available()){
        char c = SerialUSB.read(); 
          if (c == 'l'){ 
            SerialUSB.println("derecha");
            if(m1Angle-deltaAngle<=0){
              m1Angle=deltaAngle;
            }
            Dxl.goalPosition(M1, (m1Angle-=deltaAngle));
            delay(2);
          }
            if (c == 'j'){ 
              SerialUSB.println("izquierda");
              Dxl.goalPosition(M1, (m1Angle+=deltaAngle));
              delay(2);
            }else if (c == 'i'){
            SerialUSB.println("m2 enfrente");
            if(m2Angle-deltaAngle<=0){
              m2Angle=deltaAngle;
            } 
            Dxl.goalPosition(M2, (m2Angle-=deltaAngle));
            delay(2);
            }else if (c == 'k') { 
              SerialUSB.println("m2 atras");
              Dxl.goalPosition(M2, (m2Angle+=deltaAngle));
              delay(2);
            }else if (c == 'p') {
              SerialUSB.println("garra abre");        
              if(m5Angle-deltaAngle<=0){
                m5Angle=deltaAngle;       
              }   
              Dxl.goalPosition(M5, (m5Angle-=deltaAngle));
              delay(2); 
             }else if (c == 'o') {
                SerialUSB.println("garra cierra");
                Dxl.goalPosition(M5, (m5Angle+=deltaAngle));
                delay(2);
              }else if (c == 'u') {
                SerialUSB.println("garra Derecha");
                if(m3Angle-deltaAngle<=0){
                  m3Angle=deltaAngle;
                }
                Dxl.goalPosition(M3, (m3Angle-=deltaAngle));
                delay(2);
              }else if (c == 'y') {
                SerialUSB.println("garra Izquierda");
                Dxl.goalPosition(M3, (m3Angle+=deltaAngle));
                delay(2); 
              }else if (c == 'm') {
                SerialUSB.println("m4 adelante");
              if(m4Angle-deltaAngle<=0){
                m4Angle=deltaAngle;
              }
              
              Dxl.goalPosition(M4, (m4Angle-=deltaAngle));
              delay(2); 
              }else if (c == 'n') {
                SerialUSB.println("m4 atras");
                Dxl.goalPosition(M4,m4Angle+=deltaAngle);
                delay(2); 
              }
              else if(c == 'z'){
                for(int i=1; i<5; i++){
                  Dxl.goalPosition(i,512);
                }
              }
                          if (c == 'w') { 
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
            if (c == 's') { 
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

            } 
            else if (c == 'a') { 
                  SerialUSB.println("izquierda");
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
 

            }
            else if (c == 'd') { 
                  SerialUSB.println("derecha");
                     
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
            } 
           else if (c == 'e') {
               SerialUSB.println("Velocidad Mas");
               if (Vel + 300 >= 1000){
                 Vel = 1000;
               }
               else
               Vel += 300;

}
          else if (c == 'r') {
               SerialUSB.println("Velocidad Menos");
               if (Vel - 300 <= 400){
                 Vel = 400;
               }
               else
               Vel -= 300;
}
          }
        }

        /////
