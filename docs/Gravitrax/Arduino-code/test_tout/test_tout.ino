#include <Servo.h>

#define TEST_LED
#define TEST_PIEZO
#define TEST_SERVO
#define TEST_IR

#define PIN_LED 5
// #define LED_BUILTIN is the led on the board

#define PIN_PIEZO 0

#define PIN_SERVO 4
#define MIN_PULSE 500
#define MAX_PULSE 2500
Servo myservo;  // create servo object to control a servo

//#define PIN_DIGITAL_IR  4
#define PIN_ANALOG_IR A0

void setup() {
  Serial.begin(9600);
  Serial.println();

  Serial.println("\n\n---- Setup ----");

  // Led
  pinMode(PIN_LED, OUTPUT); // initialize digital pin LED_BUILTIN as an output.
  Serial.print("PIN_LED n°");
  Serial.print(PIN_LED);
  Serial.println(" initialized");

  // Piezo
  pinMode(PIN_PIEZO, OUTPUT);
  Serial.print("PIN_PIEZO n°");
  Serial.print(PIN_PIEZO);
  noTone(PIN_PIEZO);
  Serial.println(" initialized");

  // Servo
  myservo.attach(PIN_SERVO,MIN_PULSE,MAX_PULSE);  // attaches the servo on GIO2 to the servo object
  Serial.print("Servo on PIN n°");
  Serial.print(PIN_SERVO);
  Serial.print(" initialized with MIN_PULSE=");
  Serial.print(MIN_PULSE);
  Serial.print(" and MAX_PULSE=");
  Serial.print(MAX_PULSE);
  Serial.println("it correspond to the min and max angle for my servo motor");

  // IR
//  pinMode(PIN_DIGITAL_IR,INPUT);
  pinMode(PIN_ANALOG_IR,INPUT);
}

// the loop function runs over and over again forever
void loop() {

#ifdef TEST_LED
  // Test led
  Serial.println("\n---- Test led ----");
  int nb_repeat_led = 4;
  int duration_led = 500;
  Serial.print("Test Led (blink ");
  Serial.print(nb_repeat_led);
  Serial.print(" times every ");
  Serial.print(duration_led);
  Serial.println(" miliseconde");
  for(int i=0; i<nb_repeat_led; i++) {
    digitalWrite(PIN_LED, HIGH);
    Serial.println(" -> Turn ON");
    delay(duration_led);
    digitalWrite(PIN_LED, LOW);
    Serial.println(" -> Turn OFF");
    delay(duration_led);
  }
#endif

#ifdef TEST_PIEZO
  Serial.println("\n---- Test piezo ----");
  int nb_repeat_piezo = 1;
  int duration_piezo = 1000;
  int tone1 = 600;
  int tone2 = 900;
  Serial.print("Test piezo (repeat ");
  Serial.print(nb_repeat_piezo);
  Serial.print(" times every ");
  Serial.print(duration_piezo);
  Serial.println(" miliseconde");
  for(int i=0; i<nb_repeat_piezo; i++) {
    tone (PIN_PIEZO, 600);
    Serial.print(" -> tone: ");
    Serial.println(tone1);
    delay(50);
    tone (PIN_PIEZO, 900);
    Serial.print(" -> tone: ");
    Serial.println(tone2);
    delay(50);
    noTone(PIN_PIEZO);
    Serial.println(" -> noTone");
    delay(duration_piezo);
  }
#endif

#ifdef TEST_SERVO
  Serial.println("\n---- Test servo ----");
  int nb_repeat_servo = 2;
  int duration_servo = 1000;
  Serial.print("Test servo (0°, 45°, 90°, 135°, 180°, 0° repeat ");
  Serial.print(nb_repeat_servo);
  Serial.print(" times every ");
  Serial.print(duration_servo);
  Serial.println(" miliseconde");

  for(int i=0; i<nb_repeat_servo; i++) {
    myservo.write(0);
    Serial.println(" -> 0°");
    delay(duration_servo);

    myservo.write(45);
    Serial.println(" -> 450°");
    delay(duration_servo);

    myservo.write(90);
    Serial.println(" -> 90°");
    delay(duration_servo);

    myservo.write(135);
    Serial.println(" -> 135°");
    delay(duration_servo);

    myservo.write(180);
    Serial.println(" -> 180°");
    delay(duration_servo);

    myservo.write(0);
    Serial.println(" -> 0°");
  }  
#endif

#ifdef TEST_IR
  int duration = 4000;
  int d = millis() + duration;
  Serial.print("Test IR during: ");
  Serial.println(duration);
  while(millis() < d) {
    Serial.print("Analog Reading=");
    Serial.println(analogRead(PIN_ANALOG_IR));
//    Serial.print("\t Digital Reading=");
//   Serial.println(digitalRead(PIN_DIGITAL_IR));
    delay(10);
  }
#endif

  Serial.println("\n---- END OF TEST (repeat now) ----");

}