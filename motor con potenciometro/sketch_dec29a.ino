#include<Stepper.h>
Stepper motor1(2048, 8, 10, 9, 11);//in4, in3, in2, in1
int i;
void setup() {
  // put your setup code here, to run once:
motor1.setSpeed(15);
}

void loop() {
  // put your main code here, to run repeatedly:
  i= analogRead(A0);
  if(i<=341){
    motor1.step(0);
  }
  if(i<=681 && i>=342){
    motor1.step(-550);
  }
  if(i==1023 || i>=682){
    motor1.step(750);
  }
//750=90/180

}
