#define tam_sig 100 //tamaño de la señal
 //tamaño del impulso

//Import signal to another .h file
extern double noise_100Hz[tam_sig];


 //vector de salida
double output_signal[tam_sig];
double signalNR[tam_sig];


void moving_average (double *sig_in, double *output_signal, int sig_tam, int filter);
void plot_signal(void);

void setup() {
  Serial.begin(9600);

}

void loop() {
//  convolucion((double *)&noise_100Hz[0], (double *)&output[0], (double *)&Impulse_response[0],
//                   (int) tam_sig, (int) tam_imp);
  moving_average ((double *)&noise_100Hz[0], (double *)&output_signal[0], (int) tam_sig,12);
  sruido();
  plot_signal();
  delay(100);

}

//////////////////////FILTROS FIR/////////////7
//void convolucion(double *sig_in,double *sig_out, double *imp, int sig_tam, int imp_tam){
//  int i,j;
//  //poner ceros a vector de salida
//  for(i=0;i<(sig_tam+imp_tam);i++){
//    sig_out[i]=0;
//  }
//  for(i=0;i<sig_tam;i++){
//    for(j=0;j<imp_tam;j++){
//      sig_out[i+j]=sig_out[i+j]+sig_in[i]*imp[j];
//    }
//  }
//}

//////SUAVIZADO DE  LA SEÑAL ////////////////////////////
void moving_average (double *sig_in, double *output_signal, int sig_tam, int filter){
  int i,j;
  for(i=(filter/2);i<sig_tam-(filter/2)-1;i++){
    output_signal[i]=0;
    for(j=-(filter/2);j<(filter/2);j++){
        output_signal[i]=output_signal[i]+sig_in[i+j];
      }
      output_signal[i]=output_signal[i]/filter;
    }
  }
  void sruido(){
  double ru1 [tam_sig];
  double ru2 [tam_sig];
  for(int i=0;i<tam_sig;i++){
    ru1[i]=pow(noise_100Hz[i],2);
    ru2[i]=pow((noise_100Hz[i]-output_signal[i]),2);
    signalNR[i]=10*log(ru1[i]/ru2[i]); 
    }
  }

void plot_signal(void){ //puede ir sin void pero se pone para una manera mejor estrutura 
  int i;
  for(i=0;i<tam_sig;i++){
    Serial.print(noise_100Hz[i]+1000);
    Serial.print(",");
    Serial.print(output_signal[i]+5);
    Serial.print(",");
    Serial.println(signalNR[i]);
    delay(5);
  }
}
