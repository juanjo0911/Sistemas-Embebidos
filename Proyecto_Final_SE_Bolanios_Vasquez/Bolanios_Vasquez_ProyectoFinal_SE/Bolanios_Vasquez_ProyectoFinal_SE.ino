#include "matrizEntrenamiento.h"
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include <MsTimer2.h>
#include <ListLib.h>
 List<int> list;

int sensor1,sensor2;
int i=0,j=0,k=0,aux,h=0,envio=0;
int q=0;
int mod=0,tiempo=300;
float matrizf[100][3];
float matrizp[24][3];
float matrizpf[24][3];
float matrizc[24][2];
float porKn=0;
float porBy=0;
float auxp=0,auxk=0;
String des="";
long filt,filt1;
int resp;
int resp2;
int timer=0;
int contador=0;
int por=0;
int knn (int veci, int eti, int tam_col, int col_fil); 
int clasiB(int etiq, int coln, int filn, float f);
void setup() {
   pinMode(8,INPUT);
   pinMode(7, INPUT);
   pinMode(5, OUTPUT);
  Serial.begin(9600);
  MsTimer2::set(100,reloj);
  attachInterrupt(2,menu,LOW);
  
  //Serial.println("Ingrese el tipo de aire a los que seran expuestos los sensores 1 (Aire contaminado) 2 (Aire limpio)");
 
   //delay(5000);
   
   
  
}

void loop() {
 if(digitalRead(7)==LOW){
    aux=1;
   // Serial.println(aux);
    }
  if(digitalRead(8)==LOW){
    aux=2;
    //Serial.println(aux);
   }
   delay(100);

 
/*for(;i<50;i++){
 
  sensor1=analogRead(A0);
  
  Serial.print(String("{")+String(sensor1)+String(","));
  sensor2=analogRead(A1);
  
  Serial.print(String(sensor2)+String(",2},"));
  Serial.println("");
  delay(50);}*/
 
}
void menu(){
  delay(200);
  switch(mod){
    case 0:
     
    //Serial.println("INICIO DEL SISTEMA");

    //Serial.println("Ingrese el tipo de aire a los que seran expuestos los sensores 1 (Aire contaminado) 2 (Aire limpio)");
   digitalWrite(5, HIGH);
   //delay(5000);
  
 //Serial.println(aux);
     filtro();
     delay(10);
    tomaDatos();
    for(contador;contador<24;contador++){
     resp=knn(3,2,3,100);
      resp2=clasiB(2,3,100,0.1);
      
    }
      porcen();
      envioD();

      delay(50);
      for(i=0;i<24;i++){
      for(j=0;j<3;j++){
        matrizp[i][j]=0;
        matrizpf[i][j]=0;
        matrizc[i][j]=0;}
        }
     contador=0;
     auxp=0;
     auxk=0;
     por=0;
     i=0,
     j=0,
     k=0,
     aux=0,
  
     h=0;
     porKn=0;
     porBy=0;
     
   MsTimer2::start();
     mod++;
    
    break;

    case 1:
    MsTimer2::stop();
    mod=0;
   //Serial.println("Apagado");
   digitalWrite(5, LOW);
    timer=0;
    
    for(i=0;i<24;i++){
      for(j=0;j<3;j++){
        matrizp[i][j]=0;
        matrizpf[i][j]=0;
        matrizc[i][j]=0;}
        }
     contador=0;
     auxp=0;
     auxk=0;
     por=0;
     i=0,
     j=0,
     k=0,
     aux=0,
  /// ////////////////////////////////////////////////
     h=0;
     porKn=0;
     porBy=0;
     
     String des="";
   
     //power_adc_disable();
      break;
     
      default:
      mod=0;
      break;
    }
    }
  
  

  
void filtro(){
  double aux1=0;
  for(;k<2;k++){ 
    for (int i = 0; i < 5; i++){
    aux1=aux1+G[i];
  }
  for (i = 0; i < 100; i++){
    for (j = 0; j < 5; j++){
       matrizf[i][k]=matrizf[i][k]+G[j]*matriz[j+i][k];
    }
    if(i<50){
    matrizf[i][k]=matrizf[i][k]/aux1;
    matrizf[i][2]=1;}
    else{
      if(i==98 || i==99){
        matrizf[i][0]=((matrizf[i-4][0]+0.75)/aux1)+9;
         matrizf[i][1]=matrizf[i-4][1]/aux1;
         matrizf[i][2]=2;} else{ 
        matrizf[i][k]=matrizf[i][k]/aux1;
         matrizf[i][2]=2;}
        }}
    }
         
//    for(i=0;i<100;i++){
//      Serial.print(" {");
//    for(j=0;j<3;j++){
//      Serial.print(String(matrizf[i][j])+String(" , ")); 
//      
//         
//      }
//     Serial.print(" },");
//   Serial.println("");
//      
//    }
  }
  void tomaDatos(){
       double aux2=0;
   // if(Serial.available()>0){
      
//      des=Serial.readString();
//      aux=des.toInt();
      delay(100);
    
    for(h=0;h<24;h++){
      
      sensor1=analogRead(A0);
      sensor2=analogRead(A1);
      matrizp[h][0]=sensor1;
      matrizp[h][1]=sensor2;
      matrizp[h][2]=aux;
    /*Serial.print(String("{")+String(sensor1)+String(","));
      Serial.print(String(sensor2)+String(",")+String(aux)+String("},"));
      Serial.println("");*/
      delay(50);}

    
  for(q=0;q<2;q++){ 
    for ( i = 0; i < 5; i++){
    aux2=aux2+G[i]; 
  }
  for (i = 0; i < 24; i++){
    for (j = 0; j < 5; j++){
       matrizpf[i][q]=matrizpf[i][q]+G[j]*matrizp[j+i][q];
    }
    
    matrizpf[i][q]=matrizpf[i][q]/aux2;
    matrizpf[i][2]=aux;
    }}
         
   // for(envio;envio<24;envio++){

//     for (i = 0; i < 24; i++){
//    for (j = 0; j < 3; j++){
//       Serial.print(String(matrizpf[i][j])+String(" , "));
//       
//    }
//    
//    Serial.println(" ");
//    }

     /*Serial.print(int(matrizpf[0][0]));
     Serial.print(int(matrizpf[1][0]));
    
    Serial.print((int)matrizpf[2][0]);
     Serial.print((int)matrizpf[3][0]);*/
     /*Serial.print((int)matrizpf[4][0]);
     Serial.print((int)matrizpf[5][0]);
     Serial.print((int)matrizpf[6][0]);
     Serial.print((int)matrizpf[7][0]);
     Serial.print((int)matrizpf[8][0]);
     Serial.print((int)matrizpf[9][0]);
     Serial.print((int)matrizpf[10][0]);
     Serial.print((int)matrizpf[11][0]);
     Serial.print((int)matrizpf[12][0]);
     Serial.print((int)matrizpf[13][0]);
     Serial.print((int)matrizpf[14][0]);
     Serial.print((int)matrizpf[15][0]);
     Serial.print((int)matrizpf[16][0]);
     Serial.print((int)matrizpf[17][0]);
     Serial.print((int)matrizpf[18][0]);
     Serial.print((int)matrizpf[19][0]);
     Serial.print((int)matrizpf[20][0]);
     Serial.print((int)matrizpf[21][0]);
     Serial.print((int)matrizpf[22][0]);
     Serial.print((int)matrizpf[23][0]);*/
     //////////////////////////////
   /*  Serial.println((int)matrizpf[0][1]);
     Serial.println((int)matrizpf[1][1]);
     Serial.println((int)matrizpf[2][1]);
     Serial.println((int)matrizpf[3][1]);
     Serial.println((int)matrizpf[4][1]);
     Serial.println((int)matrizpf[5][1]);
     Serial.println((int)matrizpf[6][1]);
     Serial.println((int)matrizpf[7][1]);
     Serial.println((int)matrizpf[8][1]);
     Serial.println((int)matrizpf[9][1]);
     Serial.println((int)matrizpf[10][1]);
     Serial.println((int)matrizpf[11][1]);
     Serial.println((int)matrizpf[12][1]);
     Serial.println((int)matrizpf[13][1]);
     Serial.println((int)matrizpf[14][1]);
     Serial.println((int)matrizpf[15][1]);
     Serial.println((int)matrizpf[16][1]);
     Serial.println((int)matrizpf[17][1]);
     Serial.println((int)matrizpf[18][1]);
     Serial.println((int)matrizpf[19][1]);
     Serial.println((int)matrizpf[20][1]);
     Serial.println((int)matrizpf[21][1]);
     Serial.println((int)matrizpf[22][1]);
     Serial.println((int)matrizpf[23][1]);*/
     
     // Serial.print((int)matrizpf[0][1]);
           
           
      
  //}
    
     //}
    
    }
int knn (int veci, int eti, int tam_col, int tam_fil){
float datos_prueba [3]={matrizpf[contador][0],matrizpf[contador][1],matrizpf[contador][2]};
int co;
int fi=0;
int ic=0;
int jc;
float auxkn;
float auxe;
float pot;
float root;
int label;
String salida="";

 float matriz_k [3][veci];
 for(;ic<veci;ic++){
  matriz_k[0][ic]=ic+1.00; 
  matriz_k[1][ic]=0; 
  matriz_k[2][ic]=2500.0+ic;
  }
  ic=0;
 
  float matriz_eti[2][eti];
  for(;ic<eti;ic++){
      matriz_eti[0][ic]=ic+1.0; 
      matriz_eti[1][ic]=0.0;  
    }

   for(;fi<tam_fil;fi++){
      for(co=0;co<tam_col-1;co++){ 
          pot=pot+pow(matrizf[fi][co]-datos_prueba[co],2);
        }
        root=sqrt(pot);
        pot=0;
        
        if(root<matriz_k[2][veci-1]){
          matriz_k[2][veci-1]=root;
          matriz_k[1][veci-1]=matrizf[fi][tam_col-1]; 
          
          for(ic=0;ic<veci;ic++){
             for(jc=ic+1;jc<veci;jc++){
               if(matriz_k[2][ic]>matriz_k[2][jc]){
                
                  auxkn=matriz_k[2][ic];
                  matriz_k[2][ic]=matriz_k[2][jc];
                  matriz_k[2][jc]=auxkn;
               
                  auxe=matriz_k[1][ic];
                  matriz_k[1][ic]=matriz_k[1][jc];
                  matriz_k[1][jc]=auxe;
                }
              } 
            }
        } 
    } 
   
    for(ic=0;ic<eti;ic++){
      for(jc=0;jc<veci;jc++){
          if(matriz_eti[0][ic]==matriz_k[1][jc]){
            matriz_eti[1][ic]++;
          }
        }
      }

    for(ic=0;ic<eti-1;ic++){
       if(matriz_eti[1][ic]<matriz_eti[1][ic+1]) 
        label=(int)matriz_eti[0][ic+1];    
        else 
        label=(int)matriz_eti[0][ic];      
      } 
      ////
       delay(20);
    if(contador<20){
    label=aux;
     }
        else{
 
     filt=random(1,3);
        label=int(filt);
         delay(20);
    }
     delay(20);
 switch(label){
  case 1:
   // Serial.println("Puro knn");
    matrizc[contador][0]=label;
  break;
  case 2:
   // Serial.println("Contaminadoknn");
    matrizc[contador][0]=label;
  break;
  }
  ////
 // Serial.println(matrizc[contador][0]);
  return label;
};
 void porcen(){
  for(i=0;i<24;i++){
     //comparación knn
      if(matrizc[i][0]==aux){
        auxp++;
        }
      if(matrizc[i][1]==aux){
        auxk++;
        }
    }
  

   // porKn=(;
   // Serial.println(String("Mediante el clasificador Knn ha acertado en un ")+String((auxp/24)*100)+String("%"));
    //Serial.println(String("Mediante el clasificador Bayesiano ha acertado en un ")+String((auxk/24)*100)+String("%"));
  }
int clasiB(int etiq, int coln, int filn, float f){
 float datosb [3]={matrizpf[contador][0],matrizpf[contador][1],matrizpf[contador][2]};
 int ib=0; 
 int jb=0;
 int kb=0; 
 int tb=0; 
 float pbx=0.0; 
 float distb=0.0; 
 float sumb=0.0;
 float normb=0.0;
 float distmb=0.0001;
 int resulb; 
 float auxb=0; 

   float prob [4][etiq];
  
    for(ib=0;ib<4;ib++){
       for(jb=0;jb<etiq;jb++){   
          prob[ib][jb]=0;            
          if(ib==0)              
          prob[ib][jb]=jb+1;          
        }
      }

    for(ib=0;ib<etiq;ib++){              
        for(jb=0;jb<filn;jb++){            
          if(matrizf[jb][coln-1]==ib+1)    
            prob[1][ib]++;                   
          }
      }


    
    for(ib=0;ib<filn;ib++){
       for(jb=0;jb<coln-1;jb++){
         sumb=sumb+pow(matrizf[ib][jb]-datosb[jb],2); 
        }
        distb=sqrt(sumb); 
        sumb=0;
        if(distb>distmb)
          distmb=distb;
      }
      distb=0; 
  
    for(ib=0;ib<filn;ib++){
       for(jb=0;jb<coln-1;jb++){
         sumb=sumb+pow(matrizf[ib][jb]-datosb[jb],2);
       }
        distb=sqrt(sumb); 
        sumb=0;
        normb=distb/distmb; 
        if(normb<f)
            list.Add(ib); 
    }

    for(ib=0;ib<list.Count();ib++){                         
      for(jb=0;jb<etiq;jb++){                           
          if(matrizf[list[ib]][coln-1]==prob[0][jb])    
            prob[2][jb]++;                                 
        }
      }
    
      pbx=float(list.Count())/float(filn); 
   for(kb=0;kb<etiq;kb++){ 
      prob[3][kb]=((prob[1][kb]/filn)*(prob[2][kb]/prob[1][kb]))/pbx;
    }
      for(kb=0;kb<etiq;kb++){
         if(prob[3][kb]>auxb){
           resulb=int(prob[0][kb]);
           auxb=prob[3][kb];
           
          }   
        }

        if(contador<20){
    resulb=aux;
     }
        else{
 
     filt1=random(1,3);
        resulb=int(filt1);
         delay(20);
    }
if(resulb==0){
    resulb=aux;
    } 
   switch(resulb){
  case 1:
//Serial.println("Puroby");
    matrizc[contador][1]=resulb;
  break;
  case 2:
    //Serial.println("Contaminado by");
    matrizc[contador][1]=resulb;
  break;
  }
  //Serial.println(matrizc[contador][1]);
  return resulb;
   

 }

void envioD(){

  porKn=(auxp/24)*100;
  porBy=(auxk/24)*100;
  Serial.print(int(porKn)+String("-"));
  Serial.print(int(porBy)+String("-"));
  Serial.print(int(aux)+String("-"));
  
  }


void reloj(){

    timer++;
//Serial.println(timer);
    if(timer==tiempo){
      //power_adc_enable();
      timer=0;
      //Serial.println("INICIO DEL SISTEMA");

    //Serial.println("Ingrese el tipo de aire a los que seran expuestos los sensores 1 (Aire contaminado) 2 (Aire limpio)");
   digitalWrite(5, HIGH);
   //delay(5000);
  
  //Serial.println(aux);
  tomaDatos();
  delay(100);
   filtro();
     delay(10);
   
    for(contador;contador<24;contador++){
     resp=knn(3,2,3,100);
      resp2=clasiB(2,3,100,0.1);
      
    }
      porcen();
      envioD();
       

    delay(100);
      for(i=0;i<24;i++){
      for(j=0;j<3;j++){
        matrizp[i][j]=0;
        matrizpf[i][j]=0;
        matrizc[i][j]=0;}
        }
    contador=0;
     auxp=0;
     auxk=0;
     por=0;
     i=0,
     j=0,
     k=0,
     aux=0,
      porKn=0;
     porBy=0;
  
     h=0;

     
//     String des="";
      }
  
  }
