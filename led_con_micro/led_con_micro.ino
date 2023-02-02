int led1=7;
int led2=6;
int led3=5;
int i;
void setup() {
Serial.begin(9600);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
}

void loop() {
i=analogRead(A0);
Serial.println(i);
if(i>3){
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
}
if(i>6){
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
}
if(i>9){
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led3, LOW);
}


}

void secuencia(){
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  delay(100);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led3, LOW);
  delay(100);
}
