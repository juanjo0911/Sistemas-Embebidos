#define tam_sig 110 //tamaño de la señal
#define tam_imp 13 //tamaño del impulso

//Import signal to another .h file
extern double ecg_100Hz[tam_sig];
extern double Impulse_response[tam_imp];
double output[tam_sig+tam_imp]; //vector de salida
//double output_signal[tam_sig];
double signalNR[tam_sig];
void convolucion(double *sig_in,double *sig_out, double *imp, int sig_tam, int imp_tam);// definir funcion
void plot_signal(void);

void setup() {
  Serial.begin(9600);

}

void loop() {
  convolucion((double *)&ecg_100Hz[0], (double *)&output[0], (double *)&Impulse_response[0],
                   (int) tam_sig, (int) tam_imp);
  SNoise();
  plot_signal();
  //delay(100);

}

//////////////////////FILTROS FIR/////////////7
void convolucion(double *sig_in,double *sig_out, double *imp, int sig_tam, int imp_tam){
  int i,j;
  //poner ceros a vector de salida
  for(i=0;i<(sig_tam+imp_tam);i++){
    sig_out[i]=0;
  }
  for(i=0;i<sig_tam;i++){
    for(j=0;j<imp_tam;j++){
      sig_out[i+j]=sig_out[i+j]+sig_in[i]*imp[j];
    }
  }
}
void SNoise(){
  double sn[tam_sig];
  double sn2[tam_sig];
  for(int i=0;i<tam_sig;i++){
    sn[i]=pow(ecg_100Hz[i],2);
    sn2[i]=pow((ecg_100Hz[i]-output[i]),2);
    signalNR[i]=10*log(sn[i]/sn2[i]);
    
  }
}


void plot_signal(void){ //puede ir sin void pero se pone para una manera mejor estrutura 
  int i;
  for(i=0;i<tam_sig;i++){
    Serial.print(ecg_100Hz[i]+10);
    Serial.print(",");
    Serial.print(output[i]+5);
    Serial.print(",");
    Serial.println(signalNR[i]-100);
    delay(5);
  }
}
