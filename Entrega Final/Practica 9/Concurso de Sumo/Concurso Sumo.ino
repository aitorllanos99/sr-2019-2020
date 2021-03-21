#include <Servo.h>

const int PhotoSensorLeft = 2;
const int PhotoSensorRight = 3;
const int PhotoSensorExteriorLeft = 11;
const int PhotoSensorExteriorRight = 10;

const int BLANCO = 0;
const int NEGRO = 1;

Servo servoIz;
Servo servoDe;

void setup() {
  delay(5000);
  pinMode(PhotoSensorLeft, INPUT);
  pinMode(PhotoSensorRight, INPUT);
  pinMode(PhotoSensorExteriorLeft, INPUT);
  pinMode(PhotoSensorExteriorRight, INPUT);

  servoIz.attach(8);
  servoDe.attach(9);
}

void loop() {
  
  if(digitalRead(PhotoSensorLeft) == BLANCO && digitalRead(PhotoSensorRight) == BLANCO &&
     digitalRead(PhotoSensorExteriorLeft) == BLANCO && digitalRead(PhotoSensorExteriorRight) == BLANCO){
    avanzar();
  }else if (digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == NEGRO &&
            digitalRead(PhotoSensorExteriorLeft) == BLANCO && digitalRead(PhotoSensorExteriorRight) == BLANCO){
    avanzar(); 
  } else if (digitalRead(PhotoSensorLeft) == BLANCO && digitalRead(PhotoSensorRight) == NEGRO) {
    girar_derecha();
  } else if (digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == BLANCO) {
    girar_izquierda();
  }else if(digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == NEGRO &&
            digitalRead(PhotoSensorExteriorLeft) == BLANCO && digitalRead(PhotoSensorExteriorRight) == NEGRO){
    parar();
    delay(300);
    if(digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == NEGRO){
      avanzar();
      delay(300);
      if(digitalRead(PhotoSensorLeft) != NEGRO && digitalRead(PhotoSensorRight) != NEGRO){
        girar_derecha();
        delay(400);
      }
    }
  }else if(digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == NEGRO &&
            digitalRead(PhotoSensorExteriorLeft) == NEGRO && digitalRead(PhotoSensorExteriorRight) == BLANCO){
    parar();
    delay(300);
    if(digitalRead(PhotoSensorExteriorLeft) == NEGRO){
        girar_izquierda();
        delay(400);
        avanzar();
        delay(300);
        girar_izquierda();
        delay(100);
    }else{
      avanzar();
      delay(300);
    }
  }else if(digitalRead(PhotoSensorLeft) == NEGRO && digitalRead(PhotoSensorRight) == NEGRO &&
            digitalRead(PhotoSensorExteriorLeft) == NEGRO && digitalRead(PhotoSensorExteriorRight) == NEGRO){
    parar();
   }
  
}

void retroceder(){
  while(digitalRead(PhotoSensorLeft) != NEGRO && digitalRead(PhotoSensorRight) != NEGRO){
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
