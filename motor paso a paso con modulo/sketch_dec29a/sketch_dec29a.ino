#include<Stepper.h>
Stepper motor1(2048, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
motor1.setSpeed(15);
}

void loop() {
  // put your main code here, to run repeatedly:
motor1.step(550);
delay(1000);
motor1.step(-550);
delay(1000);
}
