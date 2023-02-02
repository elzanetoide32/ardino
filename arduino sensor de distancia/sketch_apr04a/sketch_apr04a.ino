#include<Wire.h>
#include<LiquidCrystal_I2C.h>
const int trigPin =9;
const int echoPin = 10;
long duracion;
int distancia;
LiquidCrystal_I2C lcd (0x27, 16,2);


void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
lcd.init();
lcd.backlight();


}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duracion = pulseIn(echoPin, HIGH);
distancia =(duracion * 0.034)/2;

Serial.println(distancia);

lcd.setCursor(0,0);
lcd.print("distancia: ");
lcd.print(distancia);
lcd.print("cm");

 delay(100);
 



}
