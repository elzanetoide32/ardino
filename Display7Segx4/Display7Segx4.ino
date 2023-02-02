/*:::::::::::::::::::::::::::::::::::::::::::::::::
 * ::::::::::::::::::::::::::::::::::::::::::::::::
 * ::::Control Display 7Seg 4 digitos - MAX7219::::
 * :::::::Canal Youtube: Jorge APC ::::::::::::::::
 * :::::::::::::::::::::::::::::::::::::::::::::::*/
#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,10);
  lc.clearDisplay(0);
}


void count() {
  for(int i=0;i<10;i++) {
    lc.setDigit(0,3,i,false);
    for(int f=0;f<10;f++){
      lc.setDigit(0,2,f,false);
        for(int g=0;g<10;g++){
          lc.setDigit(0,1,g,false);
            for(int h=0;h<10;h++){
              lc.setDigit(0,0,h,false);
              delay(100);
          }
        }
      }
  }
  lc.clearDisplay(0);
  delay(500);
}

void loop() { 
  count();
}
