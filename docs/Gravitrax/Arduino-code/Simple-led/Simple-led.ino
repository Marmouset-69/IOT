// #define PIN_LED 14 // D5 = 14 -> buzzer
#define PIN_LED 5 // D1 = 5 
// 2 = led du D1 mini

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(PIN_LED, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}