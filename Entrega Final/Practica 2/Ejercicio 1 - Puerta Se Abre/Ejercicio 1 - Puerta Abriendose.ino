#include <Keypad.h>

int ledRojo = 8;
int ledVerde = 9;

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
}

void loop() {
  if(teclado.getKey() == 'A'){
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,HIGH);
    delay(5000);
  }
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledRojo,HIGH);
}
