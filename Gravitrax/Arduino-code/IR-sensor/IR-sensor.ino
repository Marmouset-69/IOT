// for Arduino microcontroller
const int digital_pin = 4;
const int analog_pin = A0;

// for ESP8266 microcontroller
//const int digital_pin = D7;
//const int analog_pin = A0;

// for ESP32 microcontroller
//const int digital_pin = 4;
//const int analog_pin = 0;

void setup(){
  Serial.begin(9600);
  pinMode(digital_pin,INPUT);
}

void loop(){
  Serial.print("Analog Reading=");
  Serial.print(analogRead(analog_pin));
  Serial.print("\t Digital Reading=");
  Serial.println(digitalRead(digital_pin));
  delay(100);
}