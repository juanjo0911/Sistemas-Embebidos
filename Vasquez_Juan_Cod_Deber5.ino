#include<Servo.h>

Servo servo1;
int on=0;
int ciclo=0;
String dato;
int giro;
void setup() {
servo1.attach(5);
Serial.begin(9600);
attachInterrupt(0,inicio,LOW);
 

}

void loop() {
   
  if(on==2){
    if(Serial.available()>0){
    
    
      delay(500);
      dato=Serial.readString();
      giro=dato.toInt();
      if(giro<=180 && giro>=0){
      servo1.write(giro);
      
      
      }else{
        
        Serial.println("Dato erroneo:");
        delay(20);
        }
      }
     }
    
}

void inicio(){
  switch(on){
    case 0:
    Serial.println("Sistema encendido");
    on++;
    break;

    case 1:
     Serial.println("Giro del motor");
     Serial.println("Ingrese el giro del motor");
    
    on++;
    break;
    case 2:
    Serial.println("Sistema apagado");
    on=0;
    
    break;
  }
}
