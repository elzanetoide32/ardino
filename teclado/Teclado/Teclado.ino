#include <Keypad.h>

#define POWER 10
#define PROC 11
#define READY 12

const byte FILAS = 4;
const byte COLUMNAS = 4;

char matrizTeclas[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte filasPin[FILAS] = {2, 3, 4, 5};
byte colPin[COLUMNAS] = {9, 8, 7, 6};

Keypad arregloTeclado = Keypad(makeKeymap(matrizTeclas), filasPin, colPin, FILAS, COLUMNAS);

void setup() {
  Serial.begin(9600);
  pinMode(POWER, OUTPUT);
  pinMode(PROC, OUTPUT);
  pinMode(READY, OUTPUT);
  digitalWrite(POWER, HIGH);
}

void loop() {
  char tecla = arregloTeclado.getKey();
  if (tecla != NO_KEY) {
    Serial.println(tecla);
    digitalWrite(READY, HIGH);
    delay(100);
  } else {
    digitalWrite(READY, LOW);
  }

}
