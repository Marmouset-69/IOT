/*
  Attiny85 - programme démo feu tricolore
  avec : 
     - Attiny85
     - led rouge
     - led jaune
     - led verte
     - resistance 560 ohms
  Source :     https://www.sla99.fr
  30/11/2019  v0    version initiale
 
*/
 
const int LED = 0;
 
void setup() {
  pinMode(LED, OUTPUT);
}
 
void loop() {
  //feu vert, 5 sec
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
  delay(100);

}
