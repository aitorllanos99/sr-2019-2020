int pulsador = 2;
int led1 = 3;
int led2 = 4;
int led3 = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pulsador,INPUT);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

  randomSeed(analogRead(0));
}

void loop() {
  int read = digitalRead(pulsador);
  if(read == HIGH){
    int r = random(1,4);

    switch(r){
      case 1:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        break;
      case 2:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        break;
      case 3:
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        break; 
    }
    Serial.println(r);
    delay(1000);
  }

  
}
