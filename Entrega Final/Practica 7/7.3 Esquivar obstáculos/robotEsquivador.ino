#include <Servo.h>

const int PhotoSensorLeft = 2;
const int PhotoSensorRight = 3;

const int BLANCO = 0;
const int NEGRO = 1;

boolean busca = true;
int periodo = 200;

int pinTrig = 4;
int pinEcho = 5;

const float umbral = 5.0;
Servo servoIz;
Servo servoDe;

void setup() {
  pinMode(PhotoSensorLeft, INPUT);
  pinMode(PhotoSensorRight, INPUT);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  servoIz.attach(8);
  servoDe.attach(9);
}

void loop() {
  while(digitalRead(PhotoSensorLeft) == BLANCO && digitalRead(PhotoSensorRight) == BLANCO){
    unsigned long tiempo = millis();
    while(millis() < tiempo + periodo){
      avanzar();
      comprobarObstaculo();
    }
    girar_90();
    if(periodo <= 1000){
      periodo+=200;
    }
  }
  if (digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == NEGRO) {
    avanzar(); 
  } else if (digitalRead(PhotoSensorLeft) == BLANCO && digitalRead(PhotoSensorRight) == NEGRO) {
    girar_derecha();
  } else if (digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == BLANCO) {
    girar_izquierda();
  }
  comprobarObstaculo();
  periodo = 200;
}

void avanzar() {
  servoDe.write(180);
  servoIz.write(0);
}

void retroceder(){
  servoDe.write(0);
  servoIz.write(180);
}
void parar() {
  servoDe.write(90);
  servoIz.write(90);
}

void girar_izquierda() {
  servoDe.write(180);
  servoIz.write(180);
}

void girar_derecha() {
  servoDe.write(0);
  servoIz.write(0);
}

void girar_90(){
  unsigned long tiempo = millis();
  while(millis()< tiempo + 500){
    servoDe.write(0);
    servoIz.write(90);
  }
}
void comprobarObstaculo(){
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2); 
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig,LOW);
  unsigned long tiempo = pulseIn(pinEcho, HIGH);
  long distancia = 0.017* tiempo;
  if (distancia < umbral)
  {
    esquivar();
  }
}
void esquivar(){
  unsigned long tiempo = millis();
  while(millis()< tiempo + 800){
    girar_izquierda();
  }
}
