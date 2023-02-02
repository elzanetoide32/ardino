int a=13;
int b =12;
int c =11;
int d =10;
int e =9;
int f =8;
int g =7;
int dp =6;
int tiempo = 250;


void setup() {

for(int i=6; i<14; i++)
{
pinMode(i, HIGH);
}
}

void loop() {
cero(); 
delay(tiempo);
limpiar();
dos();
delay(tiempo);
limpiar();
uno();
delay(tiempo);
limpiar();
tres();
delay(tiempo);
limpiar();
cuatro();
delay(tiempo);
limpiar();
cinco();
delay(tiempo);
limpiar();
seis();
delay(tiempo);
limpiar();
siete();
delay(tiempo);
limpiar();
ocho();
delay(tiempo);
limpiar();
nueve();
delay(tiempo);
limpiar();

}
 
void cero(){
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(f, HIGH);
digitalWrite(dp, HIGH);
 }


void uno(){
//funcion dos//  
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(dp, HIGH);
digitalWrite(g, HIGH);
}

void dos(){
//funcion uno//  

digitalWrite(b, HIGH);
digitalWrite(d, HIGH);

}

void tres(){
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(g, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);

}

void cuatro(){
digitalWrite(b, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
//digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
}

void cinco(){
digitalWrite(a, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
//digitalWrite(dp, HIGH);
}

void seis(){
digitalWrite(a, HIGH);
digitalWrite(f,HIGH);
digitalWrite(g, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(dp, HIGH);
}

void siete(){
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(d, HIGH);
}

void ocho(){
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);
digitalWrite(dp, HIGH);
}

void nueve(){
digitalWrite(a, HIGH);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, HIGH);

}

void limpiar(){
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
digitalWrite(dp, LOW);
}
