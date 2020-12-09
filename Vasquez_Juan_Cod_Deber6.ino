#include <MsTimer2.h> //  librería timer 2
#include<TimerOne.h>
#include <LiquidCrystal.h> // librería LCD

LiquidCrystal lcd (13,12,11,10,9,8); // objeto para librería de LCD
int on=0;
int led1=7;
int hor2,mint2;
String hor,mint;
int alm=0;
int segundos=0; // Variable de seg
int minutos=0; // Variable de min
int horas =0; // Variable de hors

void setup(){
 pinMode(led1,OUTPUT);
 lcd.begin(16,2); // incia la LCD
 Serial.begin(9600);
 attachInterrupt(0,inicio,LOW);
 attachInterrupt(1,alarma,LOW);
}
void loop(){

ho();
minut();


if(horas==hor2 && minutos==mint2){
  
  digitalWrite(led1,HIGH);
  delay(10000);
  digitalWrite(led1,LOW);
}

  
}
void reloj(){
  if(segundos<60){ // condición de seg
     segundos++; // incrementa variable
    }
   else{
      segundos=0;
      if(minutos<60){ // condición de min
         minutos++; // incrementa variable
        }
       else{
        minutos=0;
        if(horas<24){ // condición de horas
          horas++; // incrementa variable
          }
          else{
            horas=0;
            }
        } 
    }
    lcd.clear(); // borra anterior mensaje
    lcd.setCursor(0,0); // ubicación en LCD
    //mensaje
    lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos)); 
 }

 void inicio(){
 switch(on){
  case 0:
  Serial.println("Reloj encendido");
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(reloj);
  on++;
  break;

  case 1:
  Serial.println("Configuracion del alarma");
  
  on++;
  break;

  case 2:
  Serial.println("Reloj apagado");
  Timer1.detachInterrupt();
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);      
  lcd.print("                ");
  on=0;
  digitalWrite(led1,LOW);
  break;
 }
 }


 void alarma(){
  if(on==2){
  switch(alm) {  
      case 0:
      Serial.println("Ingrese la hora:");
      
      alm++;
      break;
      case 1:
      Serial.println("Ingrese los minutos:");
      alm++;
      break;
     case 2:
     Serial.println("Su alarma sonara a las"+String(hor2)+String(":")+String(mint2));
     alm++;
     break;
     case 3:
     alm=0;
     break;
    }
  }
 }


 void ho(){
  if(alm==1){
    if(Serial.available()>0){
   
      hor=Serial.readString();
      hor2=hor.toInt();
      Serial.println(hor2);
    }
  }
 }

void minut(){
  if(alm==2){
    if(Serial.available()>0){
      
      mint=Serial.readString();
      mint2=mint.toInt();
      Serial.println(mint2);
    }
  }
}
