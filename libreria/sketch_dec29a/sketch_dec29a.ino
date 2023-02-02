int salida = 0;
int potenciometro = A0;
float lectura;
int FreqMin = 100;
int FreqMax = 1000;
void setup() {
  pinMode(salida, OUTPUT);
  pinMode(potenciometro, INPUT);
}

void loop() {
  lectura = analogRead(potenciometro);
  float frecuencia = map(lectura, 0, 1023, FreqMin, FreqMax);
  tone (salida, frecuencia, 300); //De aquí borrar el "300" si se quiere un tono continuo
  delay(500); // Borrar esta línea completa si se quiere un tono continuo
}
