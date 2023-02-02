#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
const char* ssid="movistar fibra";
const char* password="21436587";
//memoria flash con PROGMEM//
const char* html_page PROGMEM="<!DOCTYPE html><html><head> <title>hola, esta es una pagina</title> </head><body> <header> <nav> <ul> <li><a href=\"index.html\">inicio</a></li> <li><a href=\"mi cuenta.html\">mi cuenta</a></li> <li><a href=\"nosotros.html\">sobre nosotros</a></li> </ul> </nav> </header> <article> <section> <h1> esta pagina es acerca de nosotros </h1> <h3>Lorem ipsum dolor sit amet consectetur adipisicing elit. Temporibus recusandae impedit eligendi perferendis distinctio! A harum voluptatem repudiandae quas eum? Animi impedit molestias ipsa error rerum minima repellendus eius cupiditate. </h3> </section> </article> <aside> <h2> mas informacion</h2> <p> Lorem ipsum dolor sit amet consectetur adipisicing elit. Quod tempore dolor molestiae error dicta laudantium, aperiam adipisci neque perferendis minus labore nisi, qui obcaecati. Assumenda maiores perspiciatis magni error impedit? </p> </aside> <footer> <h4> copyrihg-todos los derechos reservados</h4> <p> segunos en:<b>redes</b></p> <a href=\"https://instagram/martu.zanetti/\">instagram</a> <a href=\"https://instagram/martu.zanetti/\">facebook</a> <a href=\"https://instagram/martu.zanetti/\">twiter</a> <a href=\"https://instagram/martu.zanetti/\">youtube</a> </footer></body></html>";
ESP8266WebServer server(80);
void handleRoot(){
  digitalWrite(2,1);
  server.send(200,"text/html",html_page);
  digitalWrite(2,0);
}

void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
Serial.begin(115200);
Serial.println("\nwifi station setting");
WiFi.mode(WIFI_STA);
WiFi.begin(ssid, password);
Serial.print("conneting ");
while(WiFi.status()!= WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
Serial.println("\nwifi ready");
Serial.print("my ip address: ");
Serial.println(WiFi.localIP());

server.on("/",handleRoot);
server.begin();
Serial.println("server http started");
}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}
