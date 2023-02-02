/*
Sensor de proximidad y al ser inferior a 10cm 
envia un pulso de alarma por  el pin 13

 HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 6 
  Trig al Arduino pin 7
  
Descargar planos de conexiones en http://elprofegarcia.com/
*/



 //lcd*//
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C  lcd(0x27, 16,2);

//led//
 int led2 =12;
 int led1 =11;

 //ultrasonico//
#define Pecho 6
#define Ptrig 7
long duracion, distancia;   

 //relay//

int relay = 10 ;

 
void setup() {   
               
  Serial.begin (9600); 

  //ultrasonico//
  pinMode(Pecho, INPUT);     
  pinMode(Ptrig, OUTPUT);    
  pinMode(13, 1);            
  pinMode(4, 1); 

  //led//
pinMode(led2,OUTPUT);
pinMode(led1,OUTPUT);

//lcd//
lcd.init ();
lcd.backlight();

//relay //

pinMode (relay , OUTPUT);

  }
  
void loop() {

  //ultrasonico//
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            
  
  if (distancia >= 500 || distancia <= 0){  
    Serial.println("---");                  
  }
  else {
    Serial.print(distancia);           
    Serial.println("cm");              
  } 


  //ledverde//
   if (distancia <5 ){
    digitalWrite(led1, 1);                     
    digitalWrite(led2, 0);
     
  }

   if (distancia < 3 ){
    digitalWrite(led1, 0);                     
    digitalWrite(led2, 0);
        
  }

delay(10);   


//ledrojo//

 if (distancia < 20 ){
    digitalWrite(led2, 1);                     
    digitalWrite(led1, 0); 
  
  
 }

if (distancia < 18 ){
    digitalWrite(led2, 0);                    
    digitalWrite(led1, 0); 
 }

delay(10);


//lcd//

lcd.setCursor(2,0);
lcd.print("distancia: ");
lcd.print(distancia); 



//relay//

if(distancia<5);{
  digitalWrite(relay, LOW);
  }

if(distancia<10);{
  digitalWrite(relay, HIGH);

  }

}
