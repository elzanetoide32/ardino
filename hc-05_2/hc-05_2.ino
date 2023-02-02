#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial miBT(10, 11);  // pin 10 como RX, pin 11 como TX

char DATO = 0;      // variable para almacenar caracter recibido
int LED = 13;    // LED rojo a pin digital numero 2

void setup(){
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  pinMode(LED, OUTPUT); // pin 2 como salida
 }

void loop(){
if (miBT.available()){      // si hay informacion disponible desde modulo
  DATO = miBT.read();   // almacena en DATO el caracter recibido desde modulo

  if( DATO == '1' )       // si el caracter recibido es el numero 1
  digitalWrite(LED, HIGH); // escribe valor opuesto al leido del LED rojo

  if( DATO == '0' )       // si el caracter recibido es el numero 2
  digitalWrite(LED, LOW); // escribe valor opuesto al leido del LED verde

}
}
