#define tam_sig 100 
extern double noise_100Hz[tam_sig];
double output_signal2[tam_sig];
double senialNR2[tam_sig];
void median(double *sig_in, double *output_signal2, int sig_tam, int num);
void plot_signal(void);

void setup() {
  Serial.begin(9600);

}

void loop() {
  median((double *)&noise_100Hz[0], (double *)&output_signal2[0], (int) tam_sig,5);
  sruido2();
  plot_signal();
  delay(100);

}

//////SUAVIZADO DE  LA SEÑAL ////////////////////////////

void median (double *sig_in, double *output_signal2, int sig_tam, int num ) {
int i, j, k, cnt=0, sign;
int aux[num];

  while(cnt<tam_sig){
   for(k=0;k<num;k++){
     aux[k]=noise_100Hz[k+cnt];
    }
    for(j=0;j<(num-1);j++){
      for(i=j+1;i<num;i++){
        if(aux[i]<aux[j]){
          sign=aux[i];
          aux[i]=aux[j];
          aux[j]=sign;
        }
        
      }
      
    }
    
    output_signal2[cnt]=aux[1];

    cnt++;
  }


}

void sruido2(){
    double ru1 [tam_sig];
    double ru2 [tam_sig];
  for(int i=0;i<tam_sig;i++){
    
    ru1[i]=pow(noise_100Hz[i],2);
    ru2[i]=pow((noise_100Hz[i]-output_signal2[i]),2);
    senialNR2[i]=10*log(ru1[i]/ru2[i]); 
    }
  }

void plot_signal(void){ 
  int i;
  for(i=0;i<tam_sig;i++){
    Serial.print(noise_100Hz[i]);
    Serial.print(",");
    Serial.print(output_signal2[i]);
    Serial.print(",");
    Serial.println(senialNR2[i]-50);
    delay(5);
  }
}
