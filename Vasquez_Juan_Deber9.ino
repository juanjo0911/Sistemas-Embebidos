/*UNIVERSIDAD TECNICA DEL NORTE
 * JUAN JOSE VASQUEZ
 * SISTEMAS EMBEBIDOS
 * 
 */
#include <avr/wdt.h> // Libreria WDT
#include <MsTimer2.h>

int cont = 0;
int on = 0;
int ad = 0;
int t=0;
int t2=1;

void setup(){
  Serial.begin(9600);
  Serial.println("INICIO");
  MsTimer2::set(1000, reset);
  attachInterrupt(0,modo,LOW);
}

void loop() {
  if(on==1){
    ad = analogRead(0);
    t= map(ad, 0, 1023, 0, 60);
    delay(50);
    if (t2!=t){
      Serial.println(String("Tiempo: ")+String(t));  
    }
    t2=t;
  }
}

void reset() {
  cont++;
  if (cont==t){
  wdt_disable();
  wdt_enable(WDTO_500MS);
  }
}

void modo() {
  switch(on){
    case 0:
      Serial.println("SISTEMA ENCENDIDO");
      Serial.println("Por favor configure el tiempo de reinicio");
      on++;
    break;
    
    case 1:
      Serial.println(String("Reinicio del sistema sera en: ")+String(t)+String(" segundos"));
      MsTimer2::start();
      on=0;
    break;
  }
}
