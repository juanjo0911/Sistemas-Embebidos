/*
 * Deber No 11
 * 
 */

#include "datos.h"

int resp;
int contador=0;
int por=0;
int knn (int veci, int eti, int tam_col, int col_fil); 
void setup() {
Serial.begin(9600);
  for(contador;contador<24;contador++){
    resp=knn(3,2,3,100);
  }
  
}

void loop() {
}
int knn (int veci, int eti, int tam_col, int tam_fil){
float datos_prueba [3]={matrizpf[contador][0],matrizpf[contador][1],matrizpf[contador][2]};
int co;
int fi=0;
int ic=0;
int jc;
float aux;
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
                
                  aux=matriz_k[2][ic];
                  matriz_k[2][ic]=matriz_k[2][jc];
                  matriz_k[2][jc]=aux;
               
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
 switch(label){
  case 1:
    Serial.println("Contaminado");
  break;
  case 2:
    Serial.println("Puro");
  break;
  }
  return label;
};
