//Definición de pines
uint8_t PULSADOR = 5;

uint8_t LEDVERDE1 = 13; //Luz verde del semáforo vehicular
uint8_t LEDAMARILLO = 10;
uint8_t LEDROJO1 = 9;  //Luz roja del semaforo vehicular

uint8_t LEDVERDE2 = 3;  //Luz verde del semaforo peatonal
uint8_t LEDROJO2 = 2;   //Luz roja del semaforo peatonal


unsigned long TiempoCambio = 0;

void setup() {
  //Definición de entradas y salidas, en este caso la única entrada sería el pulsador
  pinMode(PULSADOR, INPUT);
  pinMode(LEDVERDE1, OUTPUT);
  pinMode(LEDVERDE2, OUTPUT);
  pinMode(LEDROJO1, OUTPUT);
  pinMode(LEDROJO2, OUTPUT);
  pinMode(LEDAMARILLO, OUTPUT);

  //Definición de condiciones iniciales. En caso de reset el semaforo quedaría de esta manera
  digitalWrite(LEDVERDE1, HIGH);
  digitalWrite(LEDROJO2, HIGH);
}

void loop() {

    funcionamientoSemaforo();
    millis();
  }

//Función de la máquina de estado
void funcionamientoSemaforo(void)
{
  static int Estado = 0;
  int pulsador = digitalRead(PULSADOR);

  switch(Estado){
  case 0:  //Luz vehicular verde y luz peatonal roja encendidas
  digitalWrite(LEDVERDE1, 1);
  digitalWrite(LEDROJO2, 1);
  if (pulsador == HIGH || (millis() - TiempoCambio) > 85000){  //Condiciones para que se mantenga o cambie el estado
    Estado = 1;
  }
  if((millis() - TiempoCambio) <= 85000){
    Estado = 0;
  }
  break;
 
  case 1:  //Luz vehicular verde parpadeando y luz peatonal roja encendida
  for (int x=0; x<5; x++) {
  digitalWrite(LEDVERDE1, HIGH); 
  delay(250); 
  digitalWrite(LEDVERDE1, LOW); 
  delay(250); 
  }
  if((millis() - TiempoCambio) > 5000){  //Condiciones para que se mantenga o cambie el estado
    Estado = 2;
  }
  if((millis() - TiempoCambio) <= 5000){
   Estado = 1;
  }
  break;

  case 2: //Luz vehicular amarilla y luz peatonal roja encendidas
  digitalWrite(LEDAMARILLO, HIGH);
  digitalWrite(LEDVERDE1, LOW);
  if((millis() - TiempoCambio) > 5000){ //Condiciones para que se mantenga o cambie el estado
    Estado = 3;
  }
  if((millis() - TiempoCambio) <= 5000){
    Estado = 2;
  }
  break;

  case 3:  //Luz vehicular roja y luz peatonal verde encendidas
  digitalWrite(LEDAMARILLO, LOW); 
  digitalWrite(LEDROJO1, HIGH);
  digitalWrite(LEDVERDE2, HIGH);
  digitalWrite(LEDROJO2, LOW); 
  if((millis() - TiempoCambio) <= 15000){
    Estado = 3;
  }
  if((millis() - TiempoCambio) > 15000){
    Estado = 4;
  }
 
  case 4:  //Luz vehicular roja encendida y luz peatonal verde parpadeando
  digitalWrite(LEDROJO2, HIGH); 
  digitalWrite(LEDAMARILLO, HIGH); 
  digitalWrite(LEDROJO1, LOW); 
   for (int x=0; x<5; x++) {
  digitalWrite(LEDVERDE2, HIGH); 
  delay(250); 
  digitalWrite(LEDVERDE2, LOW); 
  delay(250); 
  }
  if((millis() - TiempoCambio) > 5000){
    Estado = 0;
  }
  
  if((millis() - TiempoCambio) < 5000){
    Estado = 4;
  }
  
  TiempoCambio = millis();
 
 
 
}}
