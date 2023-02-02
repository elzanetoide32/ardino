int ledrojo= 13;
int ledverde= 12;
int ledamarillo= 11;


void setup() {
 
pinMode(ledrojo, OUTPUT);
pinMode(ledverde, OUTPUT);
pinMode(ledamarillo, OUTPUT);
}

void loop() {
  
digitalWrite(ledrojo, HIGH);
delay(50);
digitalWrite(ledverde, HIGH);
delay(50);
digitalWrite(ledamarillo, HIGH);
delay(50);

digitalWrite(ledrojo, LOW);
delay(52);
digitalWrite(ledverde, LOW);
delay(53);
digitalWrite(ledamarillo, LOW);
delay(54);
}
