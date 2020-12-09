#include <EEPROM.h>
 int on=0;    
 int cont=0;    
 int cad;    
 int ent2;     
int pass = 4563;    
 String entrada;       
void setup() {
cad=EEPROM.read(0);           
EEPROM.update(0,4563);        
Serial.begin(9600);           
attachInterrupt(0,inicio,LOW);      
attachInterrupt(1,contador,LOW);        
}
void loop() {
    if(on==2){                    
      if(cont==1){              
        if(Serial.available()>0){              
          entrada=Serial.readString();                       
          cad=entrada.toInt();              
          EEPROM.update(0,cad);              
          Serial.println("password Guardado");              
        }
      }
      if(cont==0){             
        if(Serial.available()>0){              
          entrada=Serial.readString();              
          ent2=entrada.toInt();              
          if(cad==ent2){              
            Serial.println("password Correcto");               
          }else{
            Serial.println("password Incorrecto");              
          }
        }
      }
    }
}
void inicio(){                    
  switch(on){                         
    case 0: 
    Serial.println("SISTEMA ENCENDIDO");     
    Serial.println("Ingrese lo que quiere hacer");              
    on++;     
    break;
    case 1:
      switch(cont){
        case 1:
          Serial.println("Ingrese la nueva password");              
        break;
        case 0:
          Serial.println("Ingrese su password para verificar");              
        break;
      }
    on++;               
    break;
    case 2:
    Serial.println("Presione para volver al Menu Principal");              
    cont=0;             
    on=0;               
    break;
  }
}
void contador(){        
  if(on==1){           
    switch(cont){
      case 0:
        Serial.println("Actualizar contrasenia");              
        cont=1;              
      break;
       case 1:
       Serial.println("Verificar contrasenia");             
        cont=0;               
       break;
    }
  }
}
