//SISTEMAS EMBEBIDOS 
//JUAN JOSE VASQUEZ 
//LABORATORIO 4
#include <SoftwareSerial.h>

 #define rxPin 10
 #define txPin 11

 SoftwareSerial puerto =  SoftwareSerial(rxPin, txPin);

int matriz[14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
  };
int m1;
int col=0;
int fil=0;
int Ex=0;
int Ey=0;
long int Exy=0;
long int Ex2=0;
long int Ex_2=0;
int n=14;
float Bo;
float m;
String dato;
int estatura;
float peso;

void setup() {
  pinMode(rxPin, INPUT);
   pinMode(txPin, OUTPUT);
   
  Serial.begin(9600);
  puerto.begin(9600);
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey=Ey+matriz[fil][1];
    Exy=Exy+(matriz[fil][0]*matriz[fil][1]);
    Ex2=Ex2+pow(matriz[fil][0],2);
    }
    Ex_2=pow(Ex,2);
    Bo=(float(Ex2*Ey)-float(Ex*Exy))/(float(n*Ex2-Ex_2));
    m1=((n*Exy)-(Ex*Ey));
    m=float(m1)/(float(n*Ex2-Ex_2));
    Serial.println("El modelo es: ");
    Serial.println(String("y= ")+String(Bo)+String("+")+String(m)+String("x"));
    Serial.println("Ingrese su estatura:");
    
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=m*estatura+Bo;
    Serial.println("");
    Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura:");
   
    puerto.write(estatura);
    puerto.write(peso); 
    }
}
