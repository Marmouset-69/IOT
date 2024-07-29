int solenoide = 12;
int led = 2;

void setup () {
  pinMode (solenoide, OUTPUT) ;
  pinMode (led, OUTPUT) ;
}
void loop () {
  digitalWrite (solenoide, HIGH) ;
  digitalWrite (led, HIGH) ;
  delay (5000) ;
  digitalWrite (solenoide, LOW);
  digitalWrite (led, LOW) ;
  delay (5000);
}