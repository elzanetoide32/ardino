/* CONNECTIONS:
 DS1302 CLK/SCLK --> 5
 DS1302 DAT/IO --> 4
 DS1302 RST/CE --> 2
 DS1302 VCC --> 3.3v - 5v
 DS1302 GND --> GND*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C  lcd(0x27, 16,2);

#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

#define countof(a) (sizeof(a) / sizeof(a[0]))


long calculo;

void setup () 
{
   lcd.init ();
   lcd.backlight();
   
    Serial.begin(9600);
    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);    
    Rtc.Begin();
    
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();
    
    if (!Rtc.IsDateTimeValid()) 
    {
        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }


}

void loop () 
{
    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    Serial.println("  ");

    if (!now.IsValid())
    {
        // Common Causes:
        //    1) the battery on the device is low or even missing and the power line was disconnected
        Serial.println("RTC lost confidence in the DateTime!");
    }

    delay(1000);
    // read data
    uint8_t buff[20];
    const uint8_t count = sizeof(buff);
    // get our data
    uint8_t gotten = Rtc.GetMemory(buff, count);

    if (gotten != count) 
    {
        Serial.print("something didn't match, count = ");
        Serial.print(count, DEC);
        Serial.print(", gotten = ");
        Serial.print(gotten, DEC);
        Serial.println();
    }
     
}



void printDateTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Day(),
            dt.Month(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
    
    /*if (dt.Minute() == 29 ){
      Serial.print(" hola");
      }else{
        Serial.print(" ");
      }*/
      
    
      lcd.setCursor(0,0);
      lcd.print("Hora: ");
       lcd.print(dt.Hour());
        lcd.print(":");
       lcd.print(dt.Minute());
       lcd.print(":");
       lcd.print(dt.Second());
delay(10);
       lcd.setCursor(0,1);
       lcd.print("fecha:");
       lcd.print(dt.Day());
       lcd.print("/");
       lcd.print(dt.Month());
       lcd.print("/");
       lcd.print(dt.Year());
delay(10);

      
}
