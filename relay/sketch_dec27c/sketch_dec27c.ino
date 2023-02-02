int relay = 2;

void setup() {
  // put your setup code here, to run once:
pinMode(relay, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(relay , HIGH);
Serial.println("relay accion");
delay(10);

digitalWrite(relay, LOW);
Serial.println("relay no accion");
delay(100000);

}
