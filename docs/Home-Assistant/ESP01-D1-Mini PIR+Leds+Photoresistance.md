# ESP01 D1 mini Motion sensor + photoresistor + grid of led +
## Flash the esp-D1-mini to install Tasmota
Flash Tasmota using a **Chrome** based browser for ESP82XX and ESP32

- [https://tasmota.github.io/docs/Getting-Started/#needed-software)](https://tasmota.github.io/docs/Getting-Started/#needed-software)
- [https://tasmota.github.io/install/](https://tasmota.github.io/install/)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-48-53.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-49-45.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-01.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-16.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-30.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-50.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-51-35.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-50-54.png){ width="250" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-52-21.png){ width="250" }

## GPIO on a ESP-D1-mini
![](Images/PIR_and_Light_Sensor/ESP82566-D1-MINI-GPIO.png){ width="500" }

## Configuration of MQTT
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_14-52-34.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-00-41.png){ width="146" }

!!! Info
    To find the MQTT settings, you can go to the MQTT configure on Homeassitant

    ![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-02-33.png){ width="210" }
    ![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-02-47.png){ width="250" }

    ![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-02-58.png){ width="250" }
    ![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-03-09.png){ width="250" }

Change : Host, User, Passwd and topic parameters.

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-03-59.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-04-15.png){ width="200" }

A new entity is automatically added to the MQTT list of entities already found (+1 in the number of entities)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_15-04-48.png){ width="250" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_17-20-19.png){ width="500" }

## Add the LED grid - WS2812

See: [tasmota.github.io/docs/Lights/](https://tasmota.github.io/docs/Lights/)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_17-20-47.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-00-38.png){ width="180" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-01-12.png){ width="450" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-01-34.png){ width="200" }

## Add a single led

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-13-49.png){ width="178" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-20-01.png){ width="200" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-29-53.png){ width="400" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-23-14.png){ width="200" }

## Add the Photoresistor

See: [tasmota.github.io/docs/ADC/](https://tasmota.github.io/docs/ADC/)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_19-10-20.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_08-53-01.png){ width="550" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_19-11-50.png){ width="350" }

The change in the photoresistor value is unfortunately not sent automatically with each change.
You must therefore define a rule directly in Tasmota.
See : [PIR-Motion-Sensors documentation](https://tasmota.github.io/docs/PIR-Motion-Sensors/)

```YAML
SwitchMode1 1
SwitchTopic 0
Rule1
  ON analog#a0>%var1% DO
    Backlog var1 %value%;
            publish stat/%topic%/photoresistor %value%;
            var2 %value%;
            add1 10;
            sub2 10;
  ENDON

  ON analog#a0<%var2% DO
    Backlog var2 %value%;
            publish stat/%topic%/photoresistor %value%;
            var1 %value%;
            add1 10;
            sub2 10;
  ENDON
Rule1 1
```

## Motion sensor (PIR HCS-SR505)

See :[https://tasmota.github.io/docs/PIR-Motion-Sensors/#tasmota-settings](https://tasmota.github.io/docs/PIR-Motion-Sensors/#tasmota-settings)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_07-45-43.png){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-20_18-20-10.png){ width="200" }

``` YAML
SwitchMode1 1
SwitchTopic 0
Rule2 on Switch1#state=1 do publish stat/%topic%/PIR1 ON endon on Switch1#state=0 do Publish stat/%topic%/PIR1 OFF endon
Rule1 2
```
See [tasmota.github.io/docs/Home-Assistant/](https://tasmota.github.io/docs/Home-Assistant/)

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
!!! Info
    To find the topic name, go to the console and select the wring name

    ![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-24_15-21-56.png){ width="500" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-46-08.png){ width="700" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_10-47-44.png){ width="350" }



## Temperature sensor - DHT22

!!! Warning
    Don't select DHT11 but use **AM2301**

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_14-29-43.png){ width="240" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_14-30-00.png){ width="224" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-21_14-30-21.png){ width="450" }



## Graph with *custom:apexcharts-card* and *type: custom:mini-graph-card*
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-27_15-24-34.png){ width="350" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-27_15-25-00.png){ width="266" }

#### Graph with : motion sensor TRUE (green), led grid ON (orange) + luminosity (grey)

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-27_15-36-17.png){ width="266" }

```YAML
type: custom:apexcharts-card
update_interval: 10min
header:
  show: true
  title: Éclairage escalier
  show_states: false
  colorize_states: true
graph_span: 24h
span:
  end: day
apex_config:
  legend:
    show: false
  chart:
    height: 260
now:
  show: true
  color: grey
  label: Now
series:
  - entity: sensor.escalier_photoresistor
    group_by:
      func: avg
      duration: 10min
    type: area
    opacity: 0.3
    stroke_width: 1
    color: rgb(200, 200, 200)
    extend_to: now
    transform: return x / 10.24
  - entity: binary_sensor.escalier_pir
    color: green
    type: column
    stroke_width: 3
    opacity: 0.1
    transform: 'return x === ''on'' ? 72 : 0;'
  - entity: light.esp_tasmota_escalier_tasmota2
    type: column
    color: orange
    transform: 'return x === ''off'' ? 75 : 0;'
    stroke_width: 1.5
yaxis:
  - min: 70
    max: 100
    show: false

```

#### Show values of luminosity (0 - 1024), Temperature and motion sensor

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-27_15-30-30.png){ width="266" }

```YAML
type: horizontal-stack
cards:
  - type: custom:mini-graph-card
    name: Luminosité
    entities:
      - sensor.escalier_photoresistor
    line_color: blue
    line_width: 8
    font_size: 75
  - type: custom:mini-graph-card
    name: °C
    entities:
      - sensor.esp_tasmota_escalier_am2301_temperature
    line_color: '#e74c3c'
    line_width: 8
    font_size: 75
  - type: custom:mini-graph-card
    name: PIR
    entities:
      - sensor.escalier_pir_x_100
    line_color: var(--accent-color)
    line_width: 8
    font_size: 75

```

## Automation

Turns ON the LED grid if movement is detected and there is not enough light

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-28_17-25-07.png){ width="300" }

Turns OFF the LED grid if the "detected" state changes to "not detected"

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-28_17-25-58.png){ width="300" }

## PCB - CNC

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/2024-01-27_16-42-18.png){ width="266" }

![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/IMG_3763.jpg){ width="200" }
![](Images/ESP01-D1-Mini PIR+Leds+Photoresistance/IMG_3764.jpg){ width="190" }
