
#include <SoftwareSerial.h>  
        

SoftwareSerial miBT(10, 11);  // pin 10 como RX, pin 11 como TX

//placa l298n//
//motor A//
int IN1= 7;
int IN2= 6;

//motor B//
int IN3= 5;
int IN4= 4;

char DATO = 0;  


void setup() {
  // put your setup code here, to run once:
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
 miBT.begin(38400); 
}

void loop() {
  // put your main code here, to run repeatedly:
if (miBT.available()){      // si hay informacion disponible desde modulo
  DATO = miBT.read();   // almacena en DATO el caracter recibido desde modulo

  if( DATO == '1' ){
     adelantes();
  }

  if( DATO == '2' ){
     atrass();
  }
  
  if( DATO == '3' ){
     izquierdas();
  }
  
  if( DATO == '4' ){
    derechas();
  }
  
  if( DATO == '5' ){
    stops();
  }


}
}


//aca se detallan todas las funciones que seran utilizadas// 



void atrass(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void adelantes(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}

void izquierdas() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  }

void derechas(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  }

void stops(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  }
