/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int lastPos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(115200);

  myservo.attach(15, 500, 2500);  // Value for 2g servo motor
  // OK : 0, 2, 4, 5, 16, 14, 12, 13, 15
  SetPosition(lastPos);
  delay(500);
  }

void SetPosition(int angle)  {
  int s;
  if(angle > lastPos) {
    s = 1;
  } else {
    s = -1;
  }
  while (lastPos != angle ) {
    lastPos += s;
    myservo.write(lastPos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15 ms for the servo to reach the position
  }
    Serial.print("Set position to: ");
    Serial.println(angle);
}

void loop() {
  int pos;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    SetPosition(pos);
    //myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15 ms for the servo to reach the position
  }
}
