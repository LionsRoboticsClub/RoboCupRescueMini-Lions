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

      if (SerialUSB.available()) { 
            char c = SerialUSB.read(); 
            if (c == 'l') { 
                  SerialUSB.println("derecha");
     //Dxl.goalSpeed(M1, 700 | 0x700);
    if(m1Angle-30<=0)
      m1Angle=30;
     Dxl.goalPosition(M1, (m1Angle-=30));
     delay(2);
     //Dxl.goalSpeed(M1, 0);


            } 
            if (c == 'j') { 
                  SerialUSB.println("izquierda");
    // Dxl.goalSpeed(M1, 700);
    Dxl.goalPosition(M1, (m1Angle+=30));
     delay(2);
     //Dxl.goalSpeed(M1, 0);

            } 
            else if (c == 'i') { 
                  SerialUSB.println("m2 enfrente");
    if(m2Angle-30<=0)
      m2Angle=30;
     Dxl.goalPosition(M2, (m2Angle-=20));
     delay(2);


            } 
            else if (c == 'k') { 
                  SerialUSB.println("m2 atras");
                     

     Dxl.goalPosition(M2, (m2Angle+=20));
     delay(2);
            } 
          else if (c == 'p') {
                SerialUSB.println("garra abre");
                
     if(m5Angle-30<=0)
      m5Angle=30;          
     Dxl.goalPosition(M5, (m5Angle-=30));
     delay(2); 
             }
      
          else if (c == 'o') {
                SerialUSB.println("garra cierra");
          
          
    Dxl.goalPosition(M5, (m5Angle+=30));
     delay(2);
            }
            
         else if (c == 'u') {
                SerialUSB.println("garra Derecha");
          
     if(m3Angle-30<=0)
      m3Angle=30;
    Dxl.goalPosition(M3, (m3Angle-=30));
     delay(2);
            }
            
         else if (c == 'y') {
                SerialUSB.println("garra Izquierda");

    Dxl.goalPosition(M3, (m3Angle+=30));
     delay(2); 
            }
            
            else if (c == 'm') {
                SerialUSB.println("m4 adelante");
          
    if(m4Angle-30<=0)
      m4Angle=30;
    Dxl.goalPosition(M4, (m4Angle-=30));
     delay(2); 
            }
            
            else if (c == 'n') {
                SerialUSB.println("m4 atras");
    Dxl.goalPosition(M4,m4Angle+=30);
     delay(2); 
            }

            
            

}
}

