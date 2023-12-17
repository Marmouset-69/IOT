// Bip via Piezo
// 12/11/2023

#define pinPiezo 14


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
   delay(500);
   bip(900,100);
   delay(500);
}