int tecla=2;
int h;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(tecla, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
h= digitalRead(tecla);

if(h==1){
  Serial.println("conectado");
  delay(100);
}
else{
  Serial.println("desconectado");
  delay(100);
}

}
