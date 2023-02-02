#include <IRremote.h>
int sensor = 11;
IRrecv irrecv(sensor);
decode_results codigo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
irrecv.enableIRIn();

}

void loop() {
  // put your main code here, to run repeatedly:
if(irrecv.decode(&codigo)) {
Serial.println(codigo.value, HEX);
irrecv.resume();
}
delay(100);
}
