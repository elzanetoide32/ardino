#include <WiFi.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>    // incluye libreria de bus I2C
#include <Adafruit_Sensor.h>  // incluye librerias para sensor BMP280
#include <Adafruit_BMP280.h>


//------------------Servidor Web en puerto 80---------------------

WiFiServer server(100);
Adafruit_BMP280 bmp;    // crea objeto con nombre bmp

//---------------------Credenciales de WiFi-----------------------

const char* ssid     = "movistar fibra";
const char* password = "21436587";

//---------------------VARIABLES GLOBALES-------------------------
int contconexion = 0;

String header, estadoSalida = "off";; // Variable para guardar el HTTP request
const int salida = 2;

//------------------------CODIGO HTML------------------------------
String paginaInicio = "<!DOCTYPE html>"
"<html>"
"<head>"
"<meta charset='utf-8' />"
"<title>Servidor Web ESP32</title>"
"<META HTTP-EQUIV='Refresh' CONTENT='10'>"
"</head>"
"<body>"
"<h1>Servidor Web ESP32</h1>"
"<p><a href='/on'><button style='height:50px;width:40px;color:red;align:right'>ON</button></a>"
"    <a href='/off'><button style='height:50px;width:40px;color:blue;aling:left'>OFF</button></a>  led 2</p>"

"<p><a href='/true'><button style='height:50px;width:40px;color:red;align:right'>ON</button></a>"
"    <a href='/false'><button style='height:50px;width:40px;color:blue;aling:left'>OFF</button></a>  lampara cocina</p>"
"<p>";


String paginaFin = 
"</p>"
"</body>"
"</html>";
DHT dht (15, DHT11);
float tempe, hume, PRESION,TEMPERATURA;

//---------------------------SETUP--------------------------------
void setup() {
  Serial.begin(115200);
  Serial.println("");
  pinMode(salida, OUTPUT); 
  digitalWrite(salida, LOW);
  
  Serial.println("Iniciando:");     // texto de inicio
  if ( !bmp.begin() ) {       // si falla la comunicacion con el sensor mostrar
    Serial.println("BMP280 no encontrado !"); // texto y detener flujo del programa
    while (1);          // mediante bucle infinito
  }
  
  // Conexión WIFI
  WiFi.begin(ssid, password);
  //Cuenta hasta 50 si no se puede conectar lo cancela
  while (WiFi.status() != WL_CONNECTED and contconexion <50) { 
    ++contconexion;
    delay(500);
    Serial.print(".");
  }
  if (contconexion <50) {
      //para usar con ip fija
      IPAddress ip(192,168,1,55); 
      IPAddress gateway(192,168,1,1); 
      IPAddress subnet(255,255,255,0); 
      WiFi.config(ip, gateway, subnet); 
      
      Serial.println("");
      Serial.println("WiFi conectado");
      Serial.println(WiFi.localIP());
      server.begin(); // iniciamos el servidor
  }
  else { 
      Serial.println("");
      Serial.println("Error de conexion");
  }
  dht.begin();
}

//----------------------------LOOP----------------------------------

void loop(){
  
  WiFiClient client = server.available();   // Escucha a los clientes entrantes

  if (client) {                             // Si se conecta un nuevo cliente
    Serial.println("New Client.");          // 
    String currentLine = "";                //
    while (client.connected()) {            // loop mientras el cliente está conectado
      if (client.available()) {             // si hay bytes para leer desde el cliente
        char c = client.read();             // lee un byte
        Serial.write(c);                    // imprime ese byte en el monitor serial
        header += c;
        if (c == '\n') {                    // si el byte es un caracter de salto de linea
          // si la nueva linea está en blanco significa que es el fin del 
          // HTTP request del cliente, entonces respondemos:
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /on") >= 0) {
              Serial.println("GPIO on");              
              digitalWrite(salida, HIGH);
            } 
            else if (header.indexOf("GET /off") >= 0) {
              Serial.println("GPIO off");             
              digitalWrite(salida, LOW);
            }
            else if (header.indexOf("GET /true") >= 0) {
              Serial.println("GPIO on");
              digitalWrite(12, HIGH);
              digitalWrite(salida, HIGH);
            } else if (header.indexOf("GET /false") >= 0) {
              Serial.println("GPIO off");
              digitalWrite(12, LOW);
            }

            //lectura de sensores
            tempe= dht.readTemperature();
            hume= dht.readHumidity();
            TEMPERATURA = bmp.readTemperature(); 
            PRESION = bmp.readPressure()/100;   // almacena en variable el valor de presion divido
            
                                    
               // Muestra la página web
            client.println(paginaInicio); 
            client.println("Temperatura: " + String(tempe)+ " °C<br><br>");
            client.println("Humedad: " +String(hume)+ " g/m3 <br><br>");            
            client.println(" Presion: "+String(PRESION)+ " hPa <br><br>");

            
            if(tempe>=28){
              client.print("hola .)");
            }
            client.println(paginaFin);
            
            // la respuesta HTTP temina con una linea en blanco
            client.println();
            break;
          } else { // si tenemos una nueva linea limpiamos currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // si C es distinto al caracter de retorno de carro
          currentLine += c;      // lo agrega al final de currentLine
        }
      }
    }
    // Limpiamos la variable header
    header = "";
    // Cerramos la conexión
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
  delay(10);
}
