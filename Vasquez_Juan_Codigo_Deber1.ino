/*JUAN JOSE VÁSQUEZ 
 * SISTEMAS EMBEBIDOS 
 * DEBER #1
 * JUEGOS DE LUCES CON SWITCH
 */ 
const int led1=8;
const int led2=9;
const int led3=10;
const int led4=11;
const int led5=12;
const int led6=13;

const int dipsw1=4;
const int dipsw2=5;
const int dipsw3=6;
const int dipsw4=7;
int i=0;
int j=0;
int k=0;
int l=0;
void setup() {
 
 pinMode(dipsw1,INPUT);
 pinMode(dipsw2,INPUT);
 pinMode(dipsw3,INPUT);
 pinMode(dipsw4,INPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);
 pinMode(led5,OUTPUT);
 pinMode(led6,OUTPUT);

}

void loop() {
 //primer caso: se encienden los pares
 if(digitalRead(dipsw1)==HIGH){ //condicional para que el programa se ejecute cuando se prenda el switch1
while(i<=9){
  
    digitalWrite(led2,HIGH);
    
    digitalWrite(led4,HIGH);
    
    digitalWrite(led6,HIGH);
    delay(500);
    digitalWrite(led2,LOW);
    
    digitalWrite(led4,LOW);
    
    digitalWrite(led6,LOW);
    delay(500);
  i++;
    
}
 }
 else{
   digitalWrite(led2,LOW);
    
    digitalWrite(led4,LOW);
    
    digitalWrite(led6,LOW);
 }

 //segundo caso:se encienden los impares 
 //condiciono para que funcione este trozo del codigo en caso de que se prenda el switch2
 if(digitalRead(dipsw2)==HIGH){
  while(j<=9){
    digitalWrite(led1,HIGH);
    
    digitalWrite(led3,HIGH);
    
    digitalWrite(led5,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    
    digitalWrite(led3,LOW);
    
    digitalWrite(led5,LOW);
    delay(500);
  j++;
    
  }
 }
 else{
  digitalWrite(led1,LOW);
    
    digitalWrite(led3,LOW);
    
    digitalWrite(led5,LOW);
 }

//caso 3: Los led se encienden secuencialmente, en mi caso haré que se enciendan 5 veces
if(digitalRead(dipsw3)==HIGH){
  while(k<=4){
    digitalWrite(led1,HIGH);
    delay(500);
    digitalWrite(led2,HIGH);
    delay(500);
    digitalWrite(led3,HIGH);
    delay(500);
    digitalWrite(led4,HIGH);
    delay(500);
    digitalWrite(led5,HIGH);
    delay(500);
    digitalWrite(led6,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    delay(500);
  }
}

//caso 4: Lo que yo quiero es que primero se enciendan todos los leds de forma ascendente y que se vayan apagando de manera descendente y que luego se enciendan los 3 ultimos leds nuevamente 
if(digitalRead(dipsw4)==HIGH){
  while(l<=2){
 
    digitalWrite(led1,HIGH);
    delay(600);
    digitalWrite(led2,HIGH);
    delay(600);
    digitalWrite(led3,HIGH);
    delay(600);
    digitalWrite(led4,HIGH);
    delay(600);
    digitalWrite(led5,HIGH);
    delay(600);
    digitalWrite(led6,HIGH);
    delay(600);
    digitalWrite(led6,LOW);
    delay(600);
    digitalWrite(led5,LOW);
    delay(600);
    digitalWrite(led4,LOW);
    delay(600);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH);
    delay(600);
    digitalWrite(led1,LOW);
    
    digitalWrite(led2,LOW);
    
    digitalWrite(led3,LOW);
    
    digitalWrite(led4,LOW);
    
    digitalWrite(led5,LOW);
    
    digitalWrite(led6,LOW);
    delay(600);
    l++;
  }
}

}
