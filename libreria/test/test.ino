void setup(){ //SE INICIALIZAR LOS PINES DEL 2 AL 18 COMO SALIDA
  for (int j=2; j<19; j++) 
  pinMode(j, OUTPUT); 
} 
void loop(){ 
  // SE LIMPIA LA MATRIZ DE LEDS
  for (int j=2; j<10; j++){ 
    digitalWrite(j, HIGH); 
    for (int k= 10 ; k<18 ; k++){ 
      digitalWrite(k, LOW); 
    } 
  } 
  //SE ENCIENDA LED POR LEDS
  //RECOGE CADA FILA DE CADA COLUMNA
  for (int j=2; j<10; j++){ 
    digitalWrite(j, LOW); 
    for (int k= 10 ; k<18 ; k++){ 
      digitalWrite(k, HIGH); 
      delay(100); 
      digitalWrite(k, LOW); 
    } 
    digitalWrite(j, HIGH);
  } 
} 
