#include <MsTimer2.h> //  librería timer 2
#include <LiquidCrystal.h> // librería LCD
#include<TimerOne.h>
int on=0;
int mod=0;
int i;
int j=0;
int k=0;
int cont=0;
int dato=0,hor;
long ledr,ledr2,sensr,sensr2;
const int led[4]={2,3,4,5};
const int sensores[4]={8,9,10,11};
LiquidCrystal lcd (53,52,51,50,49,48); // objeto para librería de LCD

int segundos=0; // Variable de seg
int minutos=-1; // Variable de min
int horas=0; // Variable de hors

void setup(){
 for(i=0;i<4;i++){
   pinMode(led[i],OUTPUT);
   pinMode(sensores[i],OUTPUT);
 }
 i=0;

 
 Serial.begin(9600);
 lcd.begin(16,2); // incia la LCD

 attachInterrupt(2,inicio,LOW);
 attachInterrupt(3,modo,LOW);
 
}
void loop(){
  if(mod==2){
    Serial.println("Modificar reloj");
    lcd.setCursor(0,1);
    lcd.print("                ");
    dato=analogRead(0);
    dato=map(dato,0,1023,0,59);
    hor=analogRead(1);
    hor=map(hor,0,1023,0,23);
    minutos=dato;
    horas=hor;
    
    Serial.println(dato);
    Serial.println(hor);
     if(minutos<10){
       lcd.setCursor(3,0);
       lcd.print(" "); 
      }
    if(minutos==10){
       lcd.setCursor(3,0);
       lcd.print(" "); }
    if(minutos==60){
      lcd.setCursor(3,0);
      lcd.print(" "); 
      lcd.setCursor(5,0);
      lcd.print(" ");
      minutos=0;
      horas++;
      if(horas==24){
        lcd.setCursor(1,0);
        lcd.print(" ");
        horas=0;
       }   
     }
    lcd.setCursor(0,0);
    lcd.print(horas);
    lcd.setCursor(2,0);
    lcd.print(":");
    lcd.setCursor(4,0);
    lcd.print(minutos);
    dato=0;
  }
  }
void reloj(){
  minutos++;
  if(minutos<10){
   lcd.setCursor(3,0);
   lcd.print("0"); 
  }
  if(minutos==10){
   lcd.setCursor(3,0);
   lcd.print(" "); }
  if(minutos==60){
    lcd.setCursor(3,0);
    lcd.print("0"); 
    lcd.setCursor(5,0);
    lcd.print(" ");
    minutos=0;
    horas++;
    if(horas==24){
      lcd.setCursor(1,0);
      lcd.print(" ");
      horas=0;
     }   
   }
  lcd.setCursor(0,0);
  lcd.print(horas);
  lcd.setCursor(2,0);
  lcd.print(":");
  lcd.setCursor(4,0);
  lcd.print(minutos);
}


void inicio(){
  switch (on){
  case 0:
        Serial.println("Inicio de Sistema");
         Timer1.initialize(100000000);
         Timer1.attachInterrupt(reloj);
         
        on++;
      break;
      case 1:
        Serial.println("Seleccion de modo");
        lcd.setCursor(0,1);
        lcd.print("Seleccion de modo");
        on++;
      break;
      case 2:
        Serial.println("Sistema apagado");
        Timer1.detachInterrupt();
        MsTimer2::stop();
        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0,1);      
        lcd.print("                ");
        for(i=0;i<4;i++){
          digitalWrite(led[i],LOW);
        }
        on=0;
        i=0;
       mod=0;
       cont=0;
      break;
      default:
      on=0;
      break;
    }
 }

void modo(){
  if(on==2){
    switch(mod){
      case 0:
      Serial.println("JUEGO DE LUCES ALEATORIAS");
      MsTimer2::set(1000,luces);
      MsTimer2::start();
      mod++;
      break;

      
      case 1:
      k=0;
      MsTimer2::stop();
      Timer1.detachInterrupt();
      mod++;
      break;

      case 2:
      Timer1.initialize(100000000);
      Timer1.attachInterrupt(reloj);
      mod++;
      break;
      case 3: //INTERRUPCION SENSORES
      MsTimer2::set(1000,sensor);
      MsTimer2::start();
        mod=0;
        cont=0;
      break;
      default:
      mod=0;
      
      break;
    }
  }
   
}

void luces(){
 if(k<20){
    lcd.setCursor(0,1);
    lcd.print("LEDS ENCENDIDAS");
    k++;
    ledr=random(0,4);
    ledr2=random(0,4);
    digitalWrite(led[ledr],HIGH);
    digitalWrite(led[ledr2],LOW);
    Serial.println(ledr);
    Serial.println(ledr2);
    if(k==20){
      k=20;
      for(j=0;j<k;j++){
        for(i=0;i<4;i++){
          digitalWrite(led[i],LOW);
          delay(500);
        }
      }
      lcd.setCursor(0,1);
      lcd.print("             ");
    }
  }
}

void sensor(){
 if(cont<10){
  cont++;
  sensr=random(1,5);
  sensr2=random(1,5);
  digitalWrite(sensores[sensr],HIGH);
  digitalWrite(sensores[sensr2],LOW);
  Serial.println(String("Se ha encendido el sensor "+String(sensr)));
  if(cont==10){
  for(j=0;j<cont;j++){
    for(i=0;i<4;i++){
      digitalWrite(sensores[i],LOW);
      delay(500);
    }
  }
 }
 } 
 
}
