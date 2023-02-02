#include <DHT.h>
#include <DHT_U.h>

DHT dht (12, DHT11);
float tempe, hume;
void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  hume= dht.readHumidity();
  tempe= dht.readTemperature();

  //temperatura
  Serial.println("temperatura: " + String(tempe));

  //humedad
  Serial.println("humedad: " +String(hume));
  delay(1000);
}
