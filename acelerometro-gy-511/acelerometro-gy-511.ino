#include <Wire.h>
#include <LSM303.h>
LSM303 compass;

void setup()
{
Serial.begin(9600);
Wire.begin();
compass.init();
compass.enableDefault();
Serial.println("Accelerometer Uncalibrated (Units in mGal)");
}

void loop()
{
compass.read();
float Xa_print, Ya_print, Za_print;

Xa_print = compass.a.x/16.0; //Acceleration data registers contain a left-aligned 12-bit number, so values should be shifted right by 4 bits (divided by 16)
Ya_print = compass.a.y/16.0;
Za_print = compass.a.z/16.0;

Serial.print(Xa_print); Serial.print(" "); Serial.print(Ya_print); Serial.print(" "); Serial.println(Za_print);
delay(125);
}
