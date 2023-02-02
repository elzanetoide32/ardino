#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C   lcd(0x27, 16,2);
#include <DHT.h>
int SENSOR = 12;
int temperatura;
int humedad;
DHT dht(SENSOR, DHT11);
int led=13;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
lcd.init ();
lcd.backlight();
lcd.setCursor(1,0);
}

void loop() {
  // put your main code here, to run repeatedly:
temperatura = dht.readTemperature();
humedad = dht.readHumidity();
Serial.print("Temperatura: ");
Serial.print(temperatura);

Serial.print(" Humedad:");
Serial.print(humedad  );
delay(500);

if( temperatura<25 ){
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  }

}
