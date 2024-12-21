// IR distante

#define PIN_DIGITAL_IR  12 // D6 -> 12
#define PIN_ANALOG_IR A0

void setup(){
  Serial.begin(9600);
  pinMode(PIN_DIGITAL_IR,INPUT);
  pinMode(PIN_ANALOG_IR,INPUT);
}

void loop(){
  Serial.print("Analog Reading=");
  Serial.print(analogRead(PIN_ANALOG_IR));
  Serial.print("\t Digital Reading=");
  Serial.println(digitalRead(PIN_DIGITAL_IR));
  delay(10);
}