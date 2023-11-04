#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  myservo.attach(15,500,2500);  // attaches the servo on GIO2 to the servo object
}

void SetPos(int pos){
  myservo.write(pos);
}
void loop() {
  SetPos(0);
  delay(2000);
  SetPos(45);
  delay(2000);
  SetPos(90);
  delay(2000);
  SetPos(180);
  delay(2000);
}
