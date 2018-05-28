#define DXL_BUS_SERIAL1 1

#define M1 1
#define M2 2
#define M3 3
#define M4 4
#define M5 5


Dynamixel Dxl (DXL_BUS_SERIAL1);

  int m1Angle = 1023/2;
  int m2Angle = 1023/2; 
  int m3Angle = 1023/2;
  int m4Angle = 1023/2; 
  int m5Angle = 1023/2; 
  int m6Angle = 1023/2; 
  cont int minAngle = 10; 
  const int maxAngle = 29
  const int deltaAngle = 20;
void setup () {
  SerialUSB.begin(); 
  Dxl.begin(3);
  Dxl.jointMode(M1);
  Dxl.jointMode(M2);
  Dxl.jointMode(M3);
  Dxl.jointMode(M4);
  Dxl.jointMode(M5);

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
              }Oar
              
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
          }
        }
