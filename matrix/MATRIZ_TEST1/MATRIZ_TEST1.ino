//SE DECLARA ARRAY DE BYTES CON LOS VALORES NECESARIOS
//PARA FORMAR CADA LETRA 0-> APAGADO, 1->ENCENDIDO
//SON 8 VALORES, UNO POR CADA FILA
// PARA FORMAR LA LETRA "K" SE CALCULA->
//EL VALOR 63 EQUIVALE A 01100011
//EL VALOR 66 EQUIVALE A 01100110
//EL VALOR 6C EQUIVALE A 01101100
//EL VALOR 78 EQUIVALE A 01111000
//EL VALOR 78 EQUIVALE A 01111000
//EL VALOR 6C EQUIVALE A 01101100
//EL VALOR 66 EQUIVALE A 01100110
//EL VALOR 63 EQUIVALE A 01100011
byte K[] = { 0x63, 0x66, 0x6C, 0x78, 0x78, 0x6C, 0x66, 0x63 }; 
byte O[] = { 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C }; 
byte D[] = { 0x78, 0x7C, 0x6E, 0x66, 0x66, 0x6E, 0x7C, 0x78 }; 
byte E[] = { 0x7C, 0x40, 0x40, 0x78, 0x78, 0x40, 0x40, 0x7C }; 
byte M[] = { 0x66, 0x7E, 0x5A, 0x42, 0x42, 0x42, 0x42, 0x42 }; 
byte Y[] = { 0xC3, 0xC3, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x18 }; 
//ESTE ARRAY ES PARA LIMPIAR MATRIZ
byte sp[]= { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; 
//SE INICIALIZA LOS PINES COMO SALIDA
void setup() { 
  for (int j=2; j<19; j++) 
    pinMode(j, OUTPUT); 
  Serial.begin(9600); 
} 
//FUNCION PARA IMPRIMIR LETRA EN MATRIZ DE LEDS
void SetChar(char p) { 
  Clear(); //FUNCION PARA LIMPIAR MATRIZ
  for (int fil = 0; fil <8 ; fil++) { 
    digitalWrite( fil + 10 , HIGH) ; 
    byte F = Selecciona( p, fil); 
    for (int col =7; col >= 0 ; col--) { 
      digitalWrite(8-col, HIGH);
      bool b = GetBit(F, col); 
      if (b) 
        digitalWrite( 9 - col ,LOW);
      else 
        digitalWrite( 9 - col ,HIGH); 
    } 
    digitalWrite( fil + 10 , LOW) ;
  } 
} 

//FUNCIÓN PARA CONVETIR HEXADECIMAL A BINARIO
bool GetBit( byte N, int pos) {
  int b = N >> pos ; 
  b = b & 1 ; 
  return b ; 
} 
//FUNCIÓN PARA LIMPIAR MATRIZ-TODOS LOS LEDS APAGADOS
void Clear() { 
  for (int j=2; j<10; j++) 
    digitalWrite(j, HIGH);
    for (int k= 10 ; k<18 ; k++) 
      digitalWrite(k, LOW);
} 

//SELECCIONA FILA DE ARRAY DE LETRA A IMPIRMIR
byte Selecciona( char c, byte fil) { 
  if ( c == 'K') return(K[fil]) ; 
  if ( c == 'O') return( O[fil]) ; 
  if ( c == 'D') return( D[fil]); 
  if (c == 'E') return( E[fil]); 
  if (c == 'M') return( M[fil]); 
  if (c == 'Y') return( Y[fil]); 
  if (c == ' ') return( sp[fil]); 
} 

void loop(){ 
  String s = "KODEMY " ; //PALABRA A IMPRIMIR
  int l = s.length();// CALCULO DE LONGITUD DE PALABRA
  for ( int n = 0; n< l; n++ ) { //RECORRE PALABRA E IMPRIME EN MATRIZ
    long t = millis(); 
    char c = s[n]; //RECORRE PALABRA Y OBTIENE LETRA POR LETRA
    while ( millis()< t+ 800) 
      SetChar(c); //LLAMADA A FUNCIÓN QUE IMPRIME EN MATRIZ
  } 
} 
