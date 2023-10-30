# Gravitrax ATtiniy 85

DON'T WORK!

## Wire
![](../Gravitrax/Images/2023-10-30_09-55-08.png){ width="150" }

``` yaml
const int LED_VERTE = 0;

void setup() {
  pinMode(LED_VERTE, OUTPUT);
}

void loop() {
  //feu vert, 5 sec
  digitalWrite(LED_VERTE, LOW);
  delay(100);
  digitalWrite(LED_VERTE, HIGH);
  delay(100);

}
```
## Upload programme

[https://phmarduino.wordpress.com/2015/12/11/programmer-un-attiny-85/](https://phmarduino.wordpress.com/2015/12/11/programmer-un-attiny-85/)

![](../Gravitrax/Images/config-arduino.jpg){ width="200" }

![](../Gravitrax/Images/IMG_2704.jpg){ width="150" }

https://github.com/sui77/rc-switch

https://web.archive.org/web/20151007014308/https://code.google.com/p/rc-switch/wiki/HowTo_Send

https://mechatrofice.com/arduino/rf-remote-controller-using-arduino-and-ask-module