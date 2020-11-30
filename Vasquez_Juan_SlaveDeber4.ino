#include<Wire.h>
char cadena[20];
byte nDato=0;
byte i=0;
void setup() {
 Wire.begin(4);
 Wire.onReceive(datoRecibido);
 Serial.begin(9600);

 
}

void loop() {
   
}

void datoRecibido(){
  while(Wire.available()>0){
  char dato=Wire.read();
  if(dato!='\0'){
    cadena[nDato]=dato;
    nDato++; 
  }else
  break;
  }
  for(byte i=0;i<=19;i++){
    Serial.print(cadena[i]);
    
  }
  Serial.println(" ");
 
}

void dateReenviar(){
  while(Serial.available()){
    
    cadena[i].toCharArray(vec,tam);
    vec[tam]=Serial.readString();
    Wire.beginTransmission(4);
    tam=cadena[i].length()+1;
    for(byte j=0;j<=tam;j++){
      wire.write(cadena[i]);
    }
    Wire.endTransmission();
    Serial.println("Se ha reenviado el mensaje");
    delay(1000);
  }
}
