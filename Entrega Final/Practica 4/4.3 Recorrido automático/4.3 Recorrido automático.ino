#include <Servo.h>

#define joystickBoton 12
#define joystickX A0
#define joystickY A1
#define pararIz 8
#define pararDe 7

Servo servo;
int modo = 2;
void setup() {
  servo.attach(3);
  
  pinMode(joystickBoton,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(modo == 1){
    int valorX = analogRead(joystickX);
    Serial.println("X: "+String(valorX));
   
    if(valorX<100){
      servo.write(180);
    }else if(valorX >= 100 && valorX <= 412){
      servo.write(100);
    }else if(valorX >= 412 && valorX <= 612){
      servo.write(90);
    }else if(valorX >= 612 && valorX <= 913){
      servo.write(80);
    }else{
      servo.write(0);
    }
  }if(modo == 2){
    if(digitalRead(pararIz) == 1){
      servo.write(180);
      Serial.println("llego a la iz");
    }
    if(digitalRead(pararDe) == 1){
      servo.write(0);
      Serial.println("llego a la de");
    }
  }
}
