int ledRojo1= 2;
int ledAmarillo1 = 3;
int ledVerde1 = 4;
int ledRojo2= 5;
int ledAmarillo2 = 6;
int ledVerde2 = 7;

void setup() {
  pinMode(ledRojo1, OUTPUT);
  pinMode(ledAmarillo1, OUTPUT);
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledRojo2, OUTPUT);
  pinMode(ledAmarillo2, OUTPUT);
  pinMode(ledVerde2, OUTPUT);

}

void loop() {
  semaforo2Verde();
  delay(4000);
  semaforo2Amarillo();
  delay(3000);
  ambosRojos();
  delay(6000);
  semaforo2Rojo();
  delay(4000);
  semaforo1Amarillo();
  delay(3000);
  ambosRojos();
  delay(6000);

}

void semaforo2Verde(){
  digitalWrite(ledRojo1, HIGH);
  digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledVerde1, LOW);

  digitalWrite(ledRojo2, LOW);
  digitalWrite(ledAmarillo2, LOW);
  digitalWrite(ledVerde2, HIGH);

  }

void semaforo2Amarillo(){
  digitalWrite(ledRojo1, HIGH);
  digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledVerde1, LOW);

  digitalWrite(ledRojo2, LOW);
  digitalWrite(ledAmarillo2, HIGH);
  digitalWrite(ledVerde2, LOW);

  }

  void semaforo2Rojo(){
  digitalWrite(ledRojo1, LOW);
  digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledVerde1, HIGH);

  digitalWrite(ledRojo2, HIGH);
  digitalWrite(ledAmarillo2, LOW);
  digitalWrite(ledVerde2, LOW);

  }

  void semaforo1Amarillo(){
  digitalWrite(ledRojo1, LOW);
  digitalWrite(ledAmarillo1, HIGH);
  digitalWrite(ledVerde1, LOW);

  digitalWrite(ledRojo2, HIGH);
  digitalWrite(ledAmarillo2, LOW);
  digitalWrite(ledVerde2, LOW);

  }

  void ambosRojos() {
  digitalWrite(ledRojo1, HIGH);
  digitalWrite(ledAmarillo1, LOW);
  digitalWrite(ledVerde1, LOW);

  digitalWrite(ledRojo2, HIGH);
  digitalWrite(ledAmarillo2, LOW);
  digitalWrite(ledVerde2, LOW);   
  }

  
  
