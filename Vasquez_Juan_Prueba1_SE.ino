//CODIGO DE LAS VOCALES
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int tam,i,eq[10],j;
String dato,res="";
void setup() {
  lcd.begin(16,2);
 Serial.begin(9600);
 Serial.println("Ingrese las vocales: ");
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readStringUntil('\n');
    tam=dato.length();
    //Serial.println(String(tam)); 
    for(i=0;i<tam;i++){
      if(dato[i]=='a'){
        eq[i]=1;
      }
      if(dato[i]=='e'){
        eq[i]=2;
      }
      if(dato[i]=='i'){
        eq[i]=3;
      }
      if(dato[i]=='o'){
        eq[i]=4;
      }
      if(dato[i]=='u'){
        eq[i]=5;
      }
    }
    QuickSortAsc(eq, 0, tam - 1);
//    for(j=0;j<tam;j++){
//    Serial.print(String(eq[j]));
//    }

    for(j=0;j<tam;j++){
    if(eq[j]==1){
      res=res+'a';
    }
    if(eq[j]==2){
      res=res+'e';
    }
    if(eq[j]==3){
      res=res+'i';
    }
    if(eq[j]==4){
      res=res+'o';
    }
    if(eq[j]==5){
      res=res+'u';
    }
    }
    lcd.print(+res);
    Serial.println(" "+res);
    res="";
  } 
}

void QuickSortAsc(int* arr, const int left, const int right)
{
   int i = left, j = right;
   int tmp;
 
   int pivot = arr[(left + right) / 2];
   while (i <= j)
   {
      while (arr[i]<pivot) i++;
      while (arr[j]>pivot) j--;
      if (i <= j)
      {
         tmp = arr[i];
         arr[i] = arr[j];
         arr[j] = tmp;
         i++;
         j--;
      }
   };
 
   if (left<j)
      QuickSortAsc(arr, left, j);
   if (i<right)
      QuickSortAsc(arr, i, right);
}






//CODIGO SERVO MOTOR

#include<Servo.h>
#include<TimerOne.h>
Servo servo1;
int k=0;
int btnConfirm=13,btn1=12,btn2=11,btn3=10,btn4=9,btn5=8;
String pass="24153";
String pass2;

int error;
int giro=100;
int on=0;
void setup() {
pinMode(btn1,INPUT);
pinMode(btn2,INPUT);
pinMode(btn3,INPUT);
pinMode(btn4,INPUT);
pinMode(btn5,INPUT);
servo1.attach(5);
Serial.begin(9600);
attachInterrupt(0,interrupcion,LOW);
}

void loop() {
  timer();
}

void interrupcion(){
  switch(on){
    case 0:
    Serial.println("Inicio");
    on++;
    break;

    case 1:
    Serial.println("Por favor ingrese la secuencia con los pulsadores");
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(timer);
    
    on++;
   break;
    default:
    on=0;
    break;
  }
}


void timer(){
if(on==2){
  if(k<10){
    k++;
 if(digitalRead(btn1)==LOW){
 pass2=pass2+"1";
 delay(300);
    
 }
 if(digitalRead(btn2)==LOW){
  pass2=pass2+"2";
  delay(300);
    
    }
    if(digitalRead(btn3)==LOW){
    pass2=pass2+"3";
    delay(300);
    
    }
   if(digitalRead(btn4)==LOW){
    pass2=pass2+"4";
    delay(300);
   }
   if(digitalRead(btn5)==LOW){
    pass2=pass2+"5";
    delay(300);
    
   }
   if(digitalRead(btnConfirm)==LOW){
    delay(300);
   
   if(pass2==pass){
     Serial.println("Ingreso correcto");
     
       servo1.write(giro);
  }else{
  
    Serial.println("Error por favor ingrese de nuevo");
  }
}
  }else
  Serial.println("Tiempo Agotado");
}
}





//CODIGO CAMBIO DE MONEDAS

float mon1=0.00,mon2=0.00;
int ent=0,mon=0,mon1=0;
void setup() {

Serial.begin(9600);  
attachInterrupt(0,moneda,LOW);
attachInterrupt(1,entrada,LOW);

}

void loop() {

}

void moneda(){
 if(ent==1){
  switch(mon){
    case 0:
    Serial.println("EURO");
    mon++;
    break;

    case 1:
   
   
    Serial.println("DOLAR");
    mon++;
    break;
    case 2:
    
    
    
    Serial.println("PES.COL");
    mon++;
    break;
    case 3:
   
    Serial.println("PES.ARG");
    mon++;
    break;
    case 4:
    
    
    Serial.println("FRANCO SUIZO");
    mon++;
    break;

    case 5:
    Serial.println("REAL");
    mon++;
    break;
    default:
    
   
    mon=0;
    break; 
  }
 }

 if(ent==2){
  
  switch(mon1){
     case 0:
    Serial.println("EURO");
    mon1++;
    break;

    case 1:
   
   
    Serial.println("DOLAR");
    mon1++;
    break;
    case 2:
    
    
    
    Serial.println("PES.COL");
    mon1++;
    break;
    case 3:
   
    Serial.println("PES.ARG");
    mon1++;
    break;
    case 4:
    
    
    Serial.println("FRANCO SUIZO");
    mon1++;
    break;

    case 5:
    Serial.println("REAL");
    mon1++;
    break;
    default:
    
   
    mon1=0;
    break; 
  }
 }
}


void entrada(){
  
  switch(ent){
    case 0:
    lcd.setCursor(0,0);
    lcd.print("                ");
    delay(20);
    lcd.setCursor(0,0);
    lcd.print("INICIO");
    ent++;
    break;
    case 1:
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(20);
    lcd.setCursor(0,1);
    lcd.print("SALIDA");
    ent++;
    break;
    default:
    lcd.clear();
    ent=0;
    break;
  }
}
