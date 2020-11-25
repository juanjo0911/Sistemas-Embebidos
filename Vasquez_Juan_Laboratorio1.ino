#include <LiquidCrystal.h>
#include <Keypad.h> 
const byte ROWS = 4;     
const byte COLS = 4;    
char keys[ROWS][COLS] = {    
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','J'}
};

byte pinesFilas[ROWS] = {10,9,8,7};   // pines correspondientes a las filas
byte pinesColumnas[COLS] = {13,12,11,6}; // pines correspondientes a las columnas

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad keypad = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,ROWS,COLS);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Preciona Tecla: ");
  lcd.setCursor(0,1);
}

void loop() {
  char key= keypad.getKey();
  if(key){
    lcd.print(key);
    }
}
