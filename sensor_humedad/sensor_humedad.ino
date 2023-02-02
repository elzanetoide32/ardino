void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int lectura= analogRead(A0);
Serial.print("la lectura es:");
Serial.println(lectura);
if (lectura>=1000){
  Serial.println(">>el suelo esta seco<<");
  }
  else if(lectura<600&&lectura>=370){
    Serial.println(">>el suelo esta humedo<<");
    }
    else if(lectura<370){
      
      Serial.println(">>el sensor esta en agua<<");
      }
      delay(1000);
}
