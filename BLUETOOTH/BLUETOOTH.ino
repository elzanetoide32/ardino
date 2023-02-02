#include <SoftwareSerial.h>
SoftwareSerial ale(0,1);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
ale.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("todomicro....");
ale.print("la tecnologia en tus manos..");
delay(1000);
}
