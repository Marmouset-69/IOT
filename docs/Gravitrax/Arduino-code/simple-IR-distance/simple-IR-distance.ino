const int digital_pin = 12;
const int analog_pin = A0;

void setup(){
  Serial.begin(9600);
  pinMode(digital_pin,INPUT);
}

void loop(){
  Serial.print("Analog Reading=");
  Serial.print(analogRead(analog_pin));
  Serial.print("\t Digital Reading=");
  Serial.println(digitalRead(digital_pin));
  delay(10);
}