/*JUAN JOSÉ VÁSQUEZ 
 * SISTEMAS EMBEBIDOS
 * DEBER 2
 * 
 */
//DECLARO MIS VARIABLES INDICANDO CADA UNO DE LOS PUERTOS 
const int A=8;
const int B=9;
const int C=10;
const int D=11;
const int boton=7;
const int unid=12;
const int dece=13;
int cont=0; 
int uni;
int dec;




void setup() {
 pinMode(A,OUTPUT);
 pinMode(B,OUTPUT);
 pinMode(C,OUTPUT);
 pinMode(D,OUTPUT);
 pinMode(boton,INPUT);
 pinMode(unid,OUTPUT);
 pinMode(dece,OUTPUT);
 
}

void loop(){
  //CONDICIONO PARA QUE CUANDO EL BOTON SE ENCIENDA COMIENCE A CONTAR CADA UNO DE LOS NUMEROS PRIMOS
   if(digitalRead(boton)==HIGH){
      delay(100);//DELAY DE 100ms 
      if(cont<=26){//ESTABLEZCO LOS CASOS PARA QUE ME CUENTE UNICAMENTE LOS NUMEROS PRIMOS 
        cont++;
        switch(cont){
        case 1:
          uni=1;
          dec=0;
          break;
        case 2:
          uni=2;
          dec=0;
          break;
        case 3:
          uni=3;
          dec=0;
          break;
        case 4:
          uni=5;
          dec=0;
          break;
         case 5:
          uni=7;
          dec=0;
          break;
         case 6:
          uni=1;
          dec=1;
          break;
         case 7:
          uni=3;
          dec=1;
          break;
         case 8:
          uni=7;
          dec=1;
          break;
         case 9:
          uni=9;
          dec=1;
          break;
         case 10:
          uni=3;
          dec=2;
          break;
         case 11:
          uni=9;
          dec=2;
          break;
         case 12:
          uni=1;
          dec=3;
          break;
         case 13:
          uni=7;
          dec=3;
          break;
         case 14:
          uni=1;
          dec=4;
          break;
         case 15:
          uni=3;
          dec=4;
          break;
         case 16:
          uni=7;
          dec=4;
          break;
         case 17:
          uni=3;
          dec=5;
          break;
         case 18:
          uni=9;
          dec=5;
          break;
         case 19:
          uni=1;
          dec=6;
          break;
         case 20:
          uni=7;
          dec=6;
          break;
         case 21:
          uni=1;
          dec=7;
          break;
         case 22:
          uni=3;
          dec=7;
          break;
         case 23:
          uni=9;
          dec=7;
          break;
         case 24:
          uni=3;
          dec=8;
          break;
         case 25:
          uni=9;
          dec=8;
          break;
         case 26:
          uni=7;
          dec=9;
          break;
          
        }
         
    }
    digitalWrite(unid,HIGH);
         digitalWrite(dece,LOW);
         contador(uni);
         delay(300);
         digitalWrite(unid,LOW);
         digitalWrite(dece,HIGH);
         contador(dec);
         delay(300); 
          
}}

   //ESTABLEZCO UN METODO EL CUAL ME IMPRIMIRÁ EN CADA DISPLAY LOS NUMEROS DEL 0 AL 9 EN LOS DISPLAYS DE 7 SEGMENTOS
void contador(int num){
   switch(num){
  case 0:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;

  case 1:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;

  case 2:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;

   case 3:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  break;

   case 4:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;

   case 5:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
   case 6:
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
   case 7:
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  break;
   case 8:
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  break;
   case 9:
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  break;
  }  
}
