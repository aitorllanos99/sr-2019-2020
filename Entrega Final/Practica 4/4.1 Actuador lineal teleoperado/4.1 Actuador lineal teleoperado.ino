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


  if(valorX > 600){
    servo.write(0);
  }else if(valorX  < 400){
    servo.write(180);
  }else{
    servo.write(90);
  }
  delay(200);
}
