#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define MOSI 9
#define CLK 10
#define DC 11
#define CS 12
#define RESET 13
Adafruit_SSD1306 pantalla(MOSI, CLK, DC, RESET, CS);


void setup() {
  // put your setup code here, to run once:
pantalla.begin(SSD1306_SWITCHCAPVCC);
pantalla.clearDisplay();
pantalla.setTextSize(1);
pantalla.setTextColor(WHITE);
//pantalla.setBackground(BLACK);
pantalla.setCursor(25, 15);
pantalla.println("hola");
pantalla.display();
delay(1000);


}

void loop() {
  // put your main code here, to run repeatedly:
pantalla.clearDisplay();
pantalla.setTextSize(10);
pantalla.setCursor(0,0);
pantalla.println("pelotuda");
pantalla.setCursor(0,10);
pantalla.println("pelotuda");
pantalla.display();
delay(100);
}
