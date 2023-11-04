#include <Servo.h>

// In this example, I use : 
// S0008P 8g plastic gear digital servo
// Voltage: 4.8-6 DC
// Torque *:≥1.4kgf.cm at 6v
// Speed * : ≤0.12sec./60° at 4.8V
// Operating Angle: 180±10°
// Mechanical limit Angle: 360°
// Weight: 8g
// Size: 22.8x11.5x23.7mm
// Shell material: ABS
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
