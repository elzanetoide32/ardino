int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=8;
int led6=9;
int led7=10;
int led8=11;
void setup() {
  // put your setup code here, to run once:
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  cero();
  delay(1000);
  clear();
  uno();
  delay(1000);
  clear();
  dos();
  delay(1000);
  clear();
  tres();
  delay(1000);
  clear();
  cuatro();
  delay(1000);
  clear();
  cinco();
  delay(1000);
  clear();
  seis();
  delay(1000);
  clear();
  siete();
  delay(1000);
  clear();
  ocho();
  delay(1000);
  clear();
  nueve();
  delay(1000);
  clear();
  /*H();
  delay(500);
  clear();
  cero();
  delay(500);
  clear();
  L();
  delay(500);
  clear();
  A();
  delay(500);
  clear();*/
}

void L(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  //digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  //digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  //digitalWrite(led7, HIGH);
  //digitalWrite(led8, HIGH);
}

void H(){
   digitalWrite(led1, HIGH);
  //digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  //digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}

void A(){
  digitalWrite(led1, HIGH);
  //digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}
void cero(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  //digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}
void uno(){
    //digitalWrite(led1, HIGH);
  //digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
//  digitalWrite(led4, HIGH); el punto
  //digitalWrite(led5, HIGH);
  //digitalWrite(led6, HIGH);
  //digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}

void dos(){
   digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
 //digitalWrite(led3, HIGH);
//  digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  //digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}

void tres(){
    //digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
//  digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  //digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}
void cuatro(){
   //digitalWrite(led1, HIGH);
  //digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  //digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}

void cinco(){
   //digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  //digitalWrite(led8, HIGH);
}

void seis(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  //digitalWrite(led8, HIGH);
}


void siete(){
    //digitalWrite(led1, HIGH);
  //digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
//  digitalWrite(led4, HIGH); el punto
  //digitalWrite(led5, HIGH);
  //digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}
void ocho(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}
void nueve(){
   //digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
}



void clear(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  //digitalWrite(led4, HIGH); el punto
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
}
