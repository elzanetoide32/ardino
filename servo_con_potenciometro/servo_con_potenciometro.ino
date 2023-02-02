int motor=2;
int i;
#include <Servo.h>
Servo servom2;
void setup()
{
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
  servom2.attach(2);
}

void loop()
{
  i=analogRead(A0);
  Serial.println(i);
  if(i<=341){
     servom2.write(0);
  }
    
    if(i<=681 && i>341){
     servom2.write(90);
    }
    
    if(i==1023 && i>=682) {
      servom2.write(180);
    }
}
