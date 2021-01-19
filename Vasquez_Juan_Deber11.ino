int matriz [14][2]={
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

float numero= 0;
float aux = 0;
int col = 0;  //moverse en columnas
int fil = 0;  //moverse en filas
int Ex = 0;  //Sumatoria de X
float Ey1 = 0;  //Sumatoria de Y
float Exy1 = 0;  //Sumatoria de XY
long int Ex2 = 0;  //Sumatoria de X^2
long int Ex_2 = 0;  //(Ex)^2
int n = 14;  //tam muestras
float B;  //Odenada en el origen
String dato;  //Recibir estatura
int estatura;  //convertir dato
float peso;
float A;

void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
    Ex = Ex+matriz[fil][0];
    Ey1 = Ey1+log(matriz[fil][1]);
    Exy1 = Exy1+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2 = Ex2+pow(matriz[fil][0],2);
  }
  Ex_2 = pow(Ex,2);
  numero = float(n*Exy1)-float(Ex*Ey1);
  aux = n*Ex2-Ex_2;
  B = float(numero/aux);
  float my1 = Ey1/n;
  float mx = Ex/n;
  float Bmx = B*mx;
  float A1 = my1-Bmx;
  A = exp(A1);
  Serial.println("El modelo es: ");
  Serial.println(String("Y = ")+String(A)+String(" * ")+String("e^(")+String(B)+String("*x)"));
  Serial.println("Ingrese su estatura: ");
}

void loop() {
  if(Serial.available()>0){
    dato = Serial.readString();
    estatura = dato.toInt();
    peso = A*exp(B*estatura);
    Serial.println(String(" Su peso es: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: ");
  }
}
