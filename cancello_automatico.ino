// cancello 
#include <Stepper.h>


int pulsante = 7;

int inizioCorsa  = 2;
int fineCorsa  = 3;

int stato = 0;

Stepper myStepper(200, 8, 10, 9, 11);

void setup() {

  Serial.begin(9600); 
  
  pinMode(inizioCorsa, INPUT_PULLUP);
  pinMode(fineCorsa, INPUT_PULLUP);
  attachInterrupt(0, stopApri, FALLING);
  attachInterrupt(1, stopChiudi, FALLING);
  pinMode(pulsante,INPUT_PULLUP);
  
  myStepper.setSpeed(60);
}

void loop() {

  if (digitalRead(pulsante)== LOW){
    stato = 1;
  }   
  Serial.println(stato);
  
switch (stato) {

    case 1:
      apri();
      break;
      
    case 2:
      attendi();
      break;
      
    case 3:
      chiudi();
      break;
      
  }
   
}


void apri(){
  myStepper.step(200);
}

void stopApri(){
  if (stato==1){
    stato = 2;
  }
}

void attendi(){
  delay(3000);
  stato = 3;
}

void chiudi(){
  myStepper.step(-200);
}
void stopChiudi(){
  if (stato==3){
    stato = 0;
  }
}
