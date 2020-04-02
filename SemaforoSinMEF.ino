int LEDROJO1 = 9 ;
 
int LEDAMARILLO = 10;
 
int LEDVERDE1 = 13;
 
int LEDROJO2 = 2;
 
int LEDVERDE2 = 3;
 
 
 
int button = 2;
 
 
 
int TiempoCruce = 5000;
 
unsigned long TiempoCambio = 0;
 
 
 
void setup(){
 
 
 
  pinMode(LEDROJO1, OUTPUT);
 
  pinMode(LEDAMARILLO, OUTPUT);
 
  pinMode(LEDVERDE1, OUTPUT);
 
  pinMode(LEDROJO2, OUTPUT);
 
  pinMode(LEDVERDE2, OUTPUT);
 
 
 
  pinMode(button, INPUT);
 
 
 
  digitalWrite(LEDVERDE1, HIGH);
 
  digitalWrite(LEDROJO2, HIGH);
 
}
 
 
 
void loop() {
 
 
 
  int estado = digitalRead(button);
 
 
 
  if (estado == HIGH && (millis() - TiempoCambio) > 5000 ){
 
   cambioLuz();
 
  }
 
}
 
 
 
void cambioLuz() {
 
 
 
  digitalWrite(LEDVERDE1,LOW);
 
  digitalWrite(LEDAMARILLO, HIGH);
 
  delay(2000);
 
 
 
  digitalWrite(LEDAMARILLO, LOW);
 
  digitalWrite(LEDROJO1, HIGH);
 
  delay(1000);
 
 
 
  digitalWrite(LEDROJO2, LOW);
 
  digitalWrite(LEDVERDE2, HIGH);
 
  delay(TiempoCruce);
 
 
 
  for (int x=0; x<10; x++) {
 
  digitalWrite(LEDVERDE2, HIGH);
 
  delay(250);
 
  digitalWrite(LEDVERDE2, LOW);
 
  delay(250);
 
 
 
  }
 
 
 
  digitalWrite(LEDROJO2, HIGH);
 
  delay(500);
 
 
 
  digitalWrite(LEDAMARILLO, HIGH);
 
  digitalWrite(LEDROJO1, LOW);
 
  delay(1000);
 
 
 
  digitalWrite(LEDVERDE1, HIGH);
 
  digitalWrite(LEDAMARILLO, LOW);
 
 
 
  TiempoCambio = millis();
 
 
 
}
