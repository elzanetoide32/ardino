#include <Servo.h>
Servo servom13;



void setup() {
  // put your setup code here, to run once:
servom13.attach(3);



}

void loop() {
  // put your main code here, to run repeatedly:

servom13.write(90);
delay(1000);
servom13.write(180);
delay(100);
servom13.write(90);
delay(100);

}
