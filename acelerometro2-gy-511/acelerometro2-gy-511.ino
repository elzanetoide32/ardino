#include <Wire.h>
#include <LSM303.h>
LSM303 compass;

void setup()
{
Serial.begin(9600);
Wire.begin();
compass.init();
compass.enableDefault();
Serial.println("Accelerometer Calibrated (Units in mGal)");
}

void loop()
{
compass.read();
float Xa_off, Ya_off, Za_off, Xa_cal, Ya_cal, Za_cal;

Xa_off = compass.a.x/16.0 + 6.008747; //X-axis combined bias (Non calibrated data - bias)
Ya_off = compass.a.y/16.0 - 18.648762; //Y-axis combined bias (Default: substracting bias)
Za_off = compass.a.z/16.0 + 10.808316; //Z-axis combined bias

Xa_cal =  0.980977*Xa_off + 0.001993*Ya_off - 0.004377*Za_off; //X-axis correction for combined scale factors (Default: positive factors)
Ya_cal =  0.001993*Xa_off + 0.998259*Ya_off - 0.000417*Za_off; //Y-axis correction for combined scale factors
Za_cal = -0.004377*Xa_off - 0.000417*Ya_off + 0.942771*Za_off; //Z-axis correction for combined scale factors

Serial.print(Xa_cal); Serial.print(" "); Serial.print(Ya_cal); Serial.print(" "); Serial.println(Za_cal);
delay(125);
}
