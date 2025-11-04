#define pinPiezo 0

void setup() {
   // initialise les broches
   pinMode(pinPiezo, OUTPUT);
}

void bip(int note, int note_delay){
  tone (pinPiezo, note);
  delay(note_delay);
  noTone(pinPiezo);
}
void loop() {
   bip(600,100);
   bip(900,100);
   delay(4000);
}