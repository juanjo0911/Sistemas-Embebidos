#include<Wire.h>
String mensaje;

void setup() {
Wire.begin();  
Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
    mensaje=Serial.readString();
    
  byte tam=mensaje.length()+1;
  char vec[tam];
      mensaje.toCharArray(vec,tam);
    Wire.beginTransmission(4);
    for(byte i=0;i<=tam;i++){
      Wire.write(vec[i]);
    }
    Wire.endTransmission();
    Serial.println("Se ha enviado el mensaje");
    delay(1000);
  }

}
