#include<ESP8266WiFi.h>
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("\nwifi scan begin");
int n=WiFi.scanNetworks();
if(n==0){
  Serial.println("no networks");
}
//numero  nombre  potencia  mac

for(int i=0;i<n;i++){
  Serial.print(i+1);
  Serial.print("-");
  Serial.print(WiFi.SSID(i));
  Serial.print(" (");
  Serial.print(WiFi.RSSI(i));
  Serial.print(") MAC: ");
  Serial.println(WiFi.BSSIDstr(i));
}
delay(5000);
}
