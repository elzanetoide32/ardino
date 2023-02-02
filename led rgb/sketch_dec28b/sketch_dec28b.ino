int ledrojo =9;
int ledverde =10;
int ledazul =11;


void setup() {
  // put your setup code here, to run once:
pinMode(ledrojo, OUTPUT);
pinMode(ledverde,OUTPUT);
pinMode(ledazul, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(ledrojo, 255);
analogWrite(ledverde, 0);
analogWrite(ledazul, 0);
delay(100);

analogWrite(ledrojo, 0);
analogWrite(ledverde, 255);
analogWrite(ledazul, 0);
delay(100);


analogWrite(ledrojo, 0);
analogWrite(ledverde, 0);
analogWrite(ledazul, 255);
delay(100);


}
