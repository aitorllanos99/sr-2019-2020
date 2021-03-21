int pulsadorVerde = 2;
int ledRojo = 3;
int ledVerde = 4;
int pulsadorRojo = 5;

int secuencia[8];

int nAciertos = 2;
boolean acierto = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(pulsadorVerde,INPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(pulsadorRojo,INPUT);

  randomSeed(analogRead(0));

  for(int i=0;i<3;i++){
    secuencia[i] = random(0,2);
  }
}
void(* resetFunc) (void) = 0;
void loop() {
  // put your main code here, to run repeatedly:
  comprobarVictoria();

  printSecuencia();

  comprobarSecuencia();
  
  addNumber(); 
}

void addNumber(){
  //0 rojo, 1 verde;
  nAciertos++;
  
  int r = random(0,2);
  
  secuencia[nAciertos] = r;
  
}

void printSecuencia(){
   for(int i = 0;i<=nAciertos;i++){
    if(secuencia[i] == 0){
      digitalWrite(ledRojo,HIGH);
      digitalWrite(ledVerde,LOW);
      Serial.println("Se enseña el led: rojo");
    }else{
      digitalWrite(ledRojo,LOW);
      digitalWrite(ledVerde,HIGH);
      Serial.println("Se enseña el led: verde");
    }
   
    delay(1000);
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,LOW);
    delay(1000);
  }
}

void comprobarSecuencia(){
  int input = 0;
  while(input <= nAciertos ){
      if(digitalRead(pulsadorRojo)== HIGH){
        comprobarEntrada(0,input); 
        digitalWrite(ledRojo,HIGH);
        digitalWrite(ledVerde,LOW);
        delay(200);
        digitalWrite(ledRojo,LOW);
        input++;
        Serial.println(" rojo "+digitalRead(pulsadorRojo));     
      }else if(digitalRead(pulsadorVerde)==HIGH){
        comprobarEntrada(1,input);       
        digitalWrite(ledRojo,LOW);
        digitalWrite(ledVerde,HIGH);
        delay(200);
        digitalWrite(ledVerde,LOW);
        input++;
        Serial.println(" verde "+digitalRead(pulsadorVerde));
      }
      delay(500);
  }
}

void comprobarEntrada(int color,int i){
 if(!(secuencia[i] == color)){
  Serial.println("perdiste");
  reiniciar();
 }
}

void comprobarVictoria(){
  if(nAciertos == 8){
      Serial.print("ganaste");
      reiniciar();
  }
  
}

void reiniciar(){
  digitalWrite(ledRojo,HIGH);
  digitalWrite(ledVerde,HIGH);
  nAciertos = 2;
  delay(1000);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,LOW);
  delay(500);
  resetFunc();
 
}
