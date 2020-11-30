/*UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CITEL
 * JUAN JOSE VASQUEZ
 * SISTEMAS EMBEBIDOS
 */
const int D=11; 
const int C=10;
const int B=9;
const int A=8;
int cont;
int i=0;
String inicio;

String resp;
int r=0;

void setup() {
 Serial.begin(9600);
Serial.println("**Bienvenido a mi juego de preguntas**");
Serial.println("Por favor presione x para empezar");    
//randomSeed(analogRead());     
 pinMode(D,OUTPUT);
pinMode(C,OUTPUT);
pinMode(B,OUTPUT);
pinMode(A,OUTPUT);
     
}

void loop() {
  
 
    
  if(Serial.available()>0){
     delay(2000);
  inicio=Serial.readString();
  if(inicio=="x"){
    
  
  for(i=0;i<5;i++){
  cont=random(0,8);
    
  delay(3000);
  if(cont==0){
     
  
  Serial.println("¿El perro es un mamifero?");
  Serial.println("SI");
  Serial.println("NO");
  delay(5000);
  resp=Serial.readString();
  if(resp=="si"){
    
   Serial.println("Correcto");
   r++;
  }else
  Serial.println("Incorrecto");
 
 }
 if(cont==1){
  Serial.println("¿5 es mayor que 10?");
  Serial.println("SI");
  Serial.println("NO");
  delay(3000);
  resp=Serial.readString();
  if(resp=="no"){
    
   Serial.println("Correcto");
   r++;
  }else
  Serial.println("Incorrecto");
  
 }
 if(cont==2){
  Serial.println("¿Se puede dividr para cero?");
  Serial.println("SI");
  Serial.println("NO");
  delay(3000);
  resp=Serial.readString();
  if(resp=="no"){
    
   Serial.println("Correcto");
   r++;
  }else
  Serial.println("Incorrecto");
 }

 if(cont==3){
   Serial.println("¿Se puede sacar raiz cuadrada de un numero negativo?");
  Serial.println("SI");
  Serial.println("NO");
  delay(3000);
  resp=Serial.readString();
  if(resp=="no"){
    
   Serial.println("Correcto");
   r++;
  }else
  Serial.println("Incorrecto");
 }
 if(cont==4){
   Serial.println("¿Los dinosaurios están extintos?");
  Serial.println("SI");
  Serial.println("NO");
  delay(3000);
  resp=Serial.readString();
  if(resp=="si"){
    
   Serial.println("Correcto");
   r++;
  }else
 
  Serial.println("Incorrecto");
 }
 
    if(cont==5){
   Serial.println("¿El 1 es numero par?");
  Serial.println("SI");
  Serial.println("NO");
  delay(3000);
  resp=Serial.readString();
  if(resp=="no"){
    
   Serial.println("Correcto");
   r++;
  }else
  Serial.println("Incorrecto");

    }
if(cont==6){
   Serial.println("¿El 2 es numero impar?");
  Serial.println("SI");
  Serial.println("NO");
  delay(3000);
  resp=Serial.readString();
  if(resp=="no"){
    
   Serial.println("Correcto");
   r++;
  }else
  Serial.println("Incorrecto");
}
if(cont==7){
   Serial.println("¿Ecuador esta en Europa?");
  Serial.println("SI");
  Serial.println("NO");
  delay(3000);
  resp=Serial.readString();
  if(resp=="no"){
    
   Serial.println("Correcto");
   r++;
  }else
  Serial.println("Incorrecto");
}
  //switch
  delay(300);
   switch(r){
      case 0: 
        digitalWrite(D,LOW);
        digitalWrite(C,LOW);
        digitalWrite(B,LOW);
        digitalWrite(A,LOW);
        break;

      case 1: 
        digitalWrite(D,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(B,LOW);
        digitalWrite(A,LOW);
        break;

      case 2: 
        digitalWrite(D,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(A,LOW);
        break;

      case 3: 
        digitalWrite(D,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(A,LOW);
        break;

      case 4: 
        digitalWrite(D,LOW);
        digitalWrite(C,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(A,LOW);
        break;

      case 5: 
        digitalWrite(D,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(A,LOW);
        break;

      case 6: 
        digitalWrite(D,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(A,LOW);
        break;

      case 7: 
        digitalWrite(D,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(A,LOW);
        break;

      case 8: 
        digitalWrite(D,LOW);
        digitalWrite(C,LOW);
        digitalWrite(B,LOW);
        digitalWrite(A,HIGH);
        break;

      case 9: 
        digitalWrite(D,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(B,LOW);
        digitalWrite(A,HIGH);
        break;
  }
    
  } 
  }else
  Serial.println("Presione x por favor");
    
    
  }
}
