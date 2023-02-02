//a continuacion creamos 4 variable
     
      int Eje_X;       // definimos una variable para el eje x 
      int Eje_Y;       // definimos una variable para el eje y
      #include <Servo.h>
Servo servom3;
 
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);      //iniciamoa lacomunicacion Seriala 9600 baudio
  servom3.attach(3);
  
   
}

//*************************************************************************************************************************************
 
void loop(void)              // inicio de nuestro codigo
{  

   int Eje_Y= analogRead(A0); // Leemos lapocin cdel Joystict en el eje Y y lo acumulamo en la Variable Eje_Y
   int Eje_X= analogRead(A1); // Leemos lapocin cdel Joystict en el eje X y lo acumulamo en la Variable Eje_X

   // La siguiente linea de codigo imprime la los cara ter X= y Y= y acontinuacion el valor dela variable Eje_x y Eje_y
   Serial.println("X=" + String(Eje_X) + ",Y=" + String(Eje_Y)); //imprimimos en elpueto serial los valores de X y Y
                // esperamos 100 milesegundo
   if(Eje_Y==0 && Eje_X==524){
    servom3.write(90);
    }
   if(Eje_Y==1023 && Eje_X==524){
    servom3.write(180);
    }
   if(Eje_Y==524 && Eje_X==1023){
    servom3.write(90);
    }
   else{
      servom3.write(0);
    }
  

}
