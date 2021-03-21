#include <Keypad.h>

int ledRojo = 8;
int ledVerde = 9;

char pass[4] = {'9','8','7','6'};
double inicioCuentaTiempo;
const byte nfilas = 4;
const byte ncolumnas = 4;
char teclas[nfilas][ncolumnas] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte pfilas[nfilas] = {5,4,3,2}; // Filas
byte pcolumnas[ncolumnas] = {A3,A2,A1,A0}; //Columnas
Keypad teclado = Keypad( makeKeymap(teclas), pfilas, pcolumnas,
nfilas, ncolumnas );


void setup() {
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(comprobarPassword()){
    inicioCuentaTiempo = millis();
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,HIGH);
    while( millis() - inicioCuentaTiempo <= 5000 ){
       if(teclado.getKey() == 'C'){
           digitalWrite(ledVerde,LOW);
           digitalWrite(ledRojo,HIGH);
       }
    }
  }
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRojo,HIGH);
}

boolean comprobarPassword(){
  int i = 0;
  inicioCuentaTiempo = millis();
  boolean correcto = true;
  
    while(i < 4){
      Serial.print(i);
      while( millis() - inicioCuentaTiempo <= 1000 ){
        if(pass[i] != teclado.getKey()){
          correcto = false;
        }
      }
      i++;
    }
  return correcto;
}
