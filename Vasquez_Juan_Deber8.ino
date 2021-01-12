/*UNIVERSIDAD TECNICA DEL NORTE 
 * JUAN JOSE VASQUEZ
 * SISTEMAS EMBEBIDOS
 */
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include<MsTimer2.h>

int puls = 0; 
int t=0; 
int cont = 0; 

void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000,reloj);
  attachInterrupt(0,encendido,LOW);
}

void loop() {
  delay(1000);
}




void encendido(){
  switch(puls){
    case 0:
      t= 60;
      Serial.println("SISTEMA ENCENDIDO");
      MsTimer2::start();
      puls++;
    break;

    case 1:
      Serial.println("SISTEMA APAGADO");
      t= 0;
      puls = 0;
      cont = 0;
      MsTimer2::stop();
      power_adc_disable();
    break;
  }
}



void reloj(){
  if(cont != 1){
    power_adc_disable();
  }
  else{
    power_adc_enable();
    delay(50);
    Serial.println(String("La lectura es: ")+String(analogRead(0)));
  }

  if(cont == 60){
    cont = 0;
  }

  cont++;
  power_adc_disable();     
}
