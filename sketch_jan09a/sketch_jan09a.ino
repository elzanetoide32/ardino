
// Arduino ISD1820 Voice Recorder & Playback Module
// electroniclinic.com
 
int P_E = 5; 
 
void setup() {
 
pinMode(P_E, INPUT_PULLUP); 
delay(2000);
 
}
 
void loop() {
 
digitalWrite(P_E, HIGH); 
delay(3000); 
digitalWrite(P_E, LOW); 
delay(3000); 
 
}
