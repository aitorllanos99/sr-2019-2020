#include <Servo.h>

#define joystickBoton 8
#define joystickX A0
#define joystickY A1 

Servo servo;

void setup() {
  servo.attach(3);
  
  pinMode(joystickBoton,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int valorX = analogRead(joystickX);
  Serial.println("X: "+String(valorX));
  
  int valorY = analogRead(joystickY);

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
  
  delay(200);
}
