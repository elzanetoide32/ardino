//a continuacion creamos 4 variable
      int Boton;       //definimos una variable para el boton del joystick
      int LED;         //definimos una vareiable para el led
      int Eje_X;       // definimos una variable para el eje x 
      int Eje_Y;       // definimos una variable para el eje y
 
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);      //iniciamoa lacomunicacion Seriala 9600 baudio
  
    pinMode(13, OUTPUT);     // este pin sera usado para el  LED
    pinMode(2,  INPUT);      // es pin sera la entada dijital del boton incluido enel cento el joystick
    digitalWrite(2, HIGH);  // turn on pullup resistors para el boton del  centro del joystick
}

//*************************************************************************************************************************************
 
void loop(void)              // inicio de nuestro codigo
{  

   int Eje_Y= analogRead(A0); // Leemos lapocin cdel Joystict en el eje Y y lo acumulamo en la Variable Eje_Y
   int Eje_X= analogRead(A1); // Leemos lapocin cdel Joystict en el eje X y lo acumulamo en la Variable Eje_X

   // La siguiente linea de codigo imprime la los cara ter X= y Y= y acontinuacion el valor dela variable Eje_x y Eje_y
   Serial.println("X=" + String(Eje_X) + ",Y=" + String(Eje_Y)); //imprimimos en elpueto serial los valores de X y Y
   delay(400);                // esperamos 100 milesegundo

   Boton = digitalRead(2);  // leemos elestado del boton
   if (Boton==LOW)           // si el boton fue precionaldo coremola siguiente secuencia de codigo
   
     {
        LED = digitalRead(13); //Leemoselestado del LED
        LED = 1-LED;           //invertimos el estado del LED
        digitalWrite(13,LED);  //escrivimos el nuevo valoe en el LED
        Serial.println("Estado del LED = " + String(LED) ); // imprimimosen elpuerto serial el estado del LED
        delay(1000);           // esperamo el 1000 milisegundo
         
     }

}
