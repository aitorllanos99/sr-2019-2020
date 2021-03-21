#include <Servo.h>

const int PhotoSensorLeft = 2;
const int PhotoSensorRight = 3;

const int BLANCO = 0;
const int NEGRO = 1;

Servo servoIz;
Servo servoDe;

void setup() {
  pinMode(PhotoSensorLeft, INPUT);
  pinMode(PhotoSensorRight, INPUT);

  servoIz.attach(8);
  servoDe.attach(9);
}

void loop() {
  if(digitalRead(PhotoSensorLeft) == BLANCO && digitalRead(PhotoSensorRight) == BLANCO){
    parar();
  }else if (digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == NEGRO) {
    avanzar(); 
  } else if (digitalRead(PhotoSensorLeft) == BLANCO && digitalRead(PhotoSensorRight) == NEGRO) {
    girar_derecha();
  } else if (digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == BLANCO) {
    girar_izquierda();
  }
}

void avanzar() {
  servoDe.write(180);
  servoIz.write(0);
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
