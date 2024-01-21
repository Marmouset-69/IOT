## Flash esp-D1-mini
Flash Tasmota using a **Chrome** based browser for ESP82XX and ESP32

- [https://tasmota.github.io/docs/Getting-Started/#needed-software)](https://tasmota.github.io/docs/Getting-Started/#needed-software)
- [https://tasmota.github.io/install/](https://tasmota.github.io/install/)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-48-53.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-49-45.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-01.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-16.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-30.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-50.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-51-35.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-54.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-52-21.png){ width="350" }

### GPIO on a ESP-D1-mini
![](Images/PIR_and_Light_Sensor/ESP82566-D1-MINI-GPIO.png){ width="500" }

### Configuration of Tasmota entitie
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-52-34.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-00-41.png){ width="250" }

!!! Info
    To find the MQTT settings, you can go to the MQTT configure on Homeassitant
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-02-33.png){ width="400" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-02-47.png){ width="450" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-02-58.png){ width="350" }

Change : Host, User, Passwd and topic parameters.

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-03-09.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-03-59.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-04-15.png){ width="200" }

A new entity must be added to the list of MQTT entities (+1 in the number of entities)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-04-48.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_17-20-19.png){ width="400" }

Add the LED grid - WS2812

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_17-20-47.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-00-38.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-01-12.png){ width="450" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-01-34.png){ width="200" }

### Add led

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-13-49.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-20-01.png){ width="200" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-29-53.png){ width="400" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-23-14.png){ width="200" }

### Add Photo resistance

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_19-10-20.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_08-53-01.png){ width="550" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_19-11-50.png){ width="350" }

### PIR HCS-SR505

See :[https://tasmota.github.io/docs/PIR-Motion-Sensors/#tasmota-settings](https://tasmota.github.io/docs/PIR-Motion-Sensors/#tasmota-settings)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_07-45-43.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-20-10.png){ width="200" }

``` YAML
SwitchMode1 1
SwitchTopic 0
Rule1 on Switch1#state=1 do publish stat/%topic%/PIR1 ON endon on Switch1#state=0 do Publish stat/%topic%/PIR1 OFF endon
Rule1 1
```
``` YAML title="configuration.yaml"
mqtt:
  binary_sensor:
      - unique_id: "20240119_1746"
        state_topic: "stat/tasmota_escalier_2F9DA0/PIR1"
        name: "Escalier PIR"
        device_class: motion
        availability_topic: "tele/tasmota_escalier_2F9DA0/LWT"
        qos: 1
        payload_on: "ON"
        payload_off: "OFF"
        payload_available: "Online"
        payload_not_available: "Offline"
```

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-46-08.png){ width="700" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-47-44.png){ width="350" }

