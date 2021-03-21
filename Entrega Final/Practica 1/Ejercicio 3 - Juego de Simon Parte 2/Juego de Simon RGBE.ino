int pulsadorVerde = 2;
int ledRojo = 3;
int ledVerde = 4;
int ledAzul = 8;
int pulsadorRojo = 5;

int zumbador = 6;

int secuencia[8];

int nAciertos = 2;

int song[] = {261, 349, 392, 440, 392, 330, -10, 261, 349, 392, 440,
392, -10, -10, 261, 349, 392, 440, 392, 330, -10, 330, 349, 330, 261,
261};

boolean acierto = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(pulsadorVerde,INPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAzul,OUTPUT);
  pinMode(pulsadorRojo,INPUT);
  pinMode(zumbador,OUTPUT);

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
  delay(500);
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
      tone(zumbador,500);
      digitalWrite(ledRojo,HIGH);
      digitalWrite(ledVerde,LOW);
      Serial.println("Se enseña el led: rojo");
    }else{
      tone(zumbador,274);
      digitalWrite(ledRojo,LOW);
      digitalWrite(ledVerde,HIGH);
      Serial.println("Se enseña el led: verde");
    }
   
    delay(1000);
    tone(zumbador,-10);
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,LOW);
    delay(1000);
  }
}

void comprobarSecuencia(){
  int input = 0;
  while(input <= nAciertos ){
      if(digitalRead(pulsadorRojo)== HIGH){
        tone(zumbador,500);
        comprobarEntrada(0,input); 
        digitalWrite(ledRojo,HIGH);
        digitalWrite(ledVerde,LOW);
        delay(200);
        digitalWrite(ledRojo,LOW);
        input++;
        Serial.println(" rojo "+digitalRead(pulsadorRojo));     
      }else if(digitalRead(pulsadorVerde)==HIGH){
        tone(zumbador,274);
        comprobarEntrada(1,input);       
        digitalWrite(ledRojo,LOW);
        digitalWrite(ledVerde,HIGH);
        delay(200);
        digitalWrite(ledVerde,LOW);
        input++;
        Serial.println(" verde "+digitalRead(pulsadorVerde));
      }
      delay(500);
      tone(zumbador,-10);
  }
}

void comprobarEntrada(int color,int i){
 if(!(secuencia[i] == color)){
  Serial.println("perdiste");
  digitalWrite(ledAzul,HIGH);
  tone(zumbador, 350);
  delay(2000);
  tone(zumbador,0);
  reiniciar();
 }
}

void comprobarVictoria(){
  if(nAciertos == 8){
      for (int i = 0; i < sizeof(song)/sizeof(int); i++) {
          tone(zumbador, song[i]);
          int r = random(0,3);
          switch(r){
            case 0:
              digitalWrite(ledAzul,LOW);
              digitalWrite(ledVerde,LOW);
              digitalWrite(ledRojo,HIGH);
              break;
            case 1:
              digitalWrite(ledAzul,LOW);
              digitalWrite(ledVerde,HIGH);
              digitalWrite(ledRojo,LOW);
              break;
            case 2:
              digitalWrite(ledAzul,HIGH);
              digitalWrite(ledVerde,LOW);
              digitalWrite(ledRojo,LOW);
              break;
              
          }
          delay(500);
        }

      Serial.print("ganaste");
//      digitalWrite(ledAzul,HIGH);
//      delay(500);
//      digitalWrite(ledAzul,LOW);
//      digitalWrite(ledRojo,HIGH);
//      delay(500);
//      digitalWrite(ledRojo,LOW);
//      digitalWrite(ledVerde,HIGH);
//      delay(500);
//      digitalWrite(ledVerde,LOW);
//      digitalWrite(ledAzul,HIGH);
//      delay(500);
//      digitalWrite(ledAzul,LOW);
//      digitalWrite(ledRojo,HIGH);
//      delay(500);
//      digitalWrite(ledRojo,LOW);
//      digitalWrite(ledVerde,HIGH);
//      delay(500);
//      digitalWrite(ledVerde,LOW);
      reiniciar();
  }
}

void reiniciar(){
  nAciertos = 2;
  delay(1000);
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledRojo,LOW);
  digitalWrite(ledVerde,LOW);
  delay(500);
  resetFunc();
}
