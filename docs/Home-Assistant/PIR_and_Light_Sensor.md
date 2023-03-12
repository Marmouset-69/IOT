# PIR and Light Sensor

see [Instructables pages](https://www.instructables.com/ESPHome-Wireless-PIR-and-Light-Sensor/)

## Wire

![](Images/PIR_and_Light_Sensor/IMG_5820.jpg){ width="400" }
![](Images/PIR_and_Light_Sensor/IMG_5825.jpg){ width="295" }

![](Images/PIR_and_Light_Sensor/IMG_5821.JPG){ width="400" }
![](Images/PIR_and_Light_Sensor/IMG_5822.jpg){ width="300" }

![](Images/PIR_and_Light_Sensor/IMG_5823.jpg){ width="350" }
![](Images/PIR_and_Light_Sensor/IMG_5824.jpg){ width="350" }

!!! warning
    Be careful to put the led ribbon in the right direction. The current only flows in one direction.

## Automations
![](Images/PIR_and_Light_Sensor/2023-03-11_22-26-15.png){ width="800" }

## Turn ON

![](Images/PIR_and_Light_Sensor/2023-03-11_22-25-17.png){ width="400" }
![](Images/PIR_and_Light_Sensor/2023-03-11_22-25-38.png){ width="400" }

![](Images/PIR_and_Light_Sensor/2023-03-11_22-25-55.png){ width="400" }

```yaml
alias: Extérieur PIR détection -> ON
description: ""
trigger:
    - platform: state
      entity_id:
          - binary_sensor.entree_pir
      to: "on"
      for:
          hours: 0
          minutes: 0
          seconds: 0
condition:
    - condition: numeric_state
      entity_id: sensor.lux_sensor
      below: 100
action:
    - type: turn_on
      device_id: f531fa200093b0b1467237c61076a741
      entity_id: switch.exterieur_tasmota
      domain: switch
mode: single
```

## Turn OFF

![](Images/PIR_and_Light_Sensor/2023-03-11_22-26-30.png){ width="400" }
![](Images/PIR_and_Light_Sensor/2023-03-11_22-26-49.png){ width="400" }

```yaml
alias: Extérieur PIR non détecté -> OFF
description: ""
trigger:
    - platform: state
      entity_id:
          - binary_sensor.entree_pir
      to: "off"
condition: []
action:
    - type: turn_off
      device_id: f531fa200093b0b1467237c61076a741
      entity_id: switch.exterieur_tasmota
      domain: switch
mode: single
```
