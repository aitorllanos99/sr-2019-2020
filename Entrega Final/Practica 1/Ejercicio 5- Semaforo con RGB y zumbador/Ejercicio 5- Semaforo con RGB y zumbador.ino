int ledPeatonVerde= 2;
int ledPeatonRojo = 3;
int ledRGB1Rojo = 6;
int ledRGB1Verde= 5;

int ledRGB2Rojo = 10;
int ledRGB2Verde = 9;

int zumbador = 11;

void setup() {
  pinMode(ledPeatonVerde, OUTPUT);
  pinMode(ledPeatonRojo, OUTPUT);
  pinMode(ledRGB1Rojo, OUTPUT);
  pinMode(ledRGB1Verde, OUTPUT);
  pinMode(ledRGB2Rojo, OUTPUT);
  pinMode(ledRGB2Verde, OUTPUT);

  pinMode(zumbador, OUTPUT);




}

void loop() {
  semaforo2Verde();
  delay(4000);
  semaforo2Amarillo();
  delay(3000);
  ambosRojos();
  //delay(2000);
  semaforo2Rojo();
  delay(4000);
  semaforo1Amarillo();
  delay(3000);
  ambosRojos();
 // delay(2000);

}

void semaforo2Verde(){
  digitalWrite(ledRGB1Rojo, HIGH);
  digitalWrite(ledRGB1Verde, LOW);

  digitalWrite(ledRGB2Rojo, LOW);
  digitalWrite(ledRGB2Verde, HIGH);

  digitalWrite(ledPeatonVerde, LOW);
  digitalWrite(ledPeatonRojo, HIGH);
  noTone(zumbador);

  }

void semaforo2Amarillo(){
  digitalWrite(ledRGB1Rojo, HIGH);
  digitalWrite(ledRGB1Verde, LOW);

  analogWrite(ledRGB2Rojo, 255);
  analogWrite(ledRGB2Verde, 255);

  digitalWrite(ledPeatonVerde, LOW);
  digitalWrite(ledPeatonRojo, HIGH);
  noTone(zumbador);

  }

  void semaforo2Rojo(){
  digitalWrite(ledRGB1Rojo, LOW);
  digitalWrite(ledRGB1Verde, HIGH);

  digitalWrite(ledRGB2Rojo, HIGH);
  digitalWrite(ledRGB2Verde, LOW);

  digitalWrite(ledPeatonVerde, LOW);
  digitalWrite(ledPeatonRojo, HIGH);
  noTone(zumbador);

  }

  void semaforo1Amarillo(){

  digitalWrite(ledRGB2Rojo, HIGH);
  digitalWrite(ledRGB2Verde, LOW);

  digitalWrite(ledPeatonVerde, LOW);
  digitalWrite(ledPeatonRojo, HIGH);
  
  analogWrite(ledRGB1Rojo, 255);
  analogWrite(ledRGB1Verde, 255);
  noTone(zumbador);

  }

  void ambosRojos() {
  digitalWrite(ledRGB1Rojo, HIGH);
  digitalWrite(ledRGB1Verde, LOW);

  digitalWrite(ledRGB2Rojo, HIGH);
  digitalWrite(ledRGB2Verde, LOW);   

  digitalWrite(ledPeatonVerde, HIGH);
  digitalWrite(ledPeatonRojo, LOW);

  
  for (int i = 10; i > 0; i--) {
    tone(zumbador, 100, 2000);
    delay(100*i);
    tone(zumbador, 1000, 500);
    delay(100*i);
  }
  

  }
