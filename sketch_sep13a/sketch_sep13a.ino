#include <IRremote.h>
# define adelante 0xFF18E7 
#define atras 0xFF4AB5 
#define izquierda 0xFF10EF 
#define derecha 0xFF5AA5 
#define stop 0xFF38C7 
int sensor= 11;
//motor a
int in1= 5;
int in2= 2;
//motor b
int in3= 3;
int in4= 4;
IRrecv irrecv (sensor);
decode_results codigo;

void setup() {
  
Serial.begin(9600);
irrecv.enableIRIn();
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
}

void loop() {
  
if (irrecv.decode(&codigo)){
Serial.println(codigo.value,HEX); 
//todos los if
if (codigo.value == adelante){
  adelante1();
  }
if(codigo.value== atras){
  atras1();
  }

  if(codigo.value== derecha){
    derecha1();
    }

    if (codigo.value== izquierda){
      izquierda1();
      }
      
      if(codigo.value== stop){
        stop1();
      }

irrecv.resume();
}
delay(100);
}


//funciones
void adelante1(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void atras1(){
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void derecha1(){
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void izquierda1(){
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stop1(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
