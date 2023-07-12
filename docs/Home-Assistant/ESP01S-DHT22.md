# ESP8266 ESP-01S DHT22 

![](Images/ESP01-DHT22/IMG_7133.jpg){ width="300" }
![](Images/ESP01-DHT22/IMG_7134.jpg){ width="213" }

## Add to home assistant via ESPHome
![](Images/ESP01-DHT22/2023-07-12_15-01-51.png){ width="213" }

![](Images/ESP01-DHT22/2023-07-12_14-59-38.png){ width="300" }

![](Images/ESP01-DHT22/2023-07-12_16-04-07.png){ width="213" }
![](Images/ESP01-DHT22/2023-07-12_15-03-20.png){ width="300" }
![](Images/ESP01-DHT22/2023-07-12_15-03-34.png){ width="213" }

![](Images/ESP01-DHT22/2023-07-12_15-04-07.png){ width="213" }
![](Images/ESP01-DHT22/2023-07-12_16-09-50.png){ width="300" }

``` yaml

esphome:
  name: esp01-dht22-06
  comment: entree

esp8266:
  board: esp01_1m

# to access via web client
web_server:
  port: 80

# Enable logging
logger:

# Enable Home Assistant API
api:

ota:
  password: "fe5bdec0ad718dcdc24d7cbcb96ee0ae"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Esp01-Dht22-06 Fallback Hotspot"
    password: "FmsCHnjpuR5g"

captive_portal:
sensor:
  - platform: dht
    # model: DHT22 don't work with the ESP-01S
    model: AM2302
    pin: GPIO02
    temperature:
      name: "entree-temperature-DHT22"
      filters:
        - offset: 0.0
    humidity:
      name: "entree-humidite-DHT22"
      filters:
        - offset: 0.0
    update_interval: 600s

```

![](Images/ESP01-DHT22/2023-07-12_16-15-23.png){ width="320" }

![](Images/ESP01-DHT22/2023-07-12_15-09-41.png){ width="320" }

![](Images/ESP01-DHT22/2023-07-12_15-10-03.png){ width="320" }

![](Images/ESP01-DHT22/2023-07-12_16-32-46.png){ width="320" }

Use ESPHome-flasher to flash ESP01S entity

![](Images/ESP01-DHT22/2023-07-12_15-10-51.png){ width="320" }

## Test the device

UNPLUG it!!!

Try http://esp01-dht22-06.local

![](Images/ESP01-DHT22/2023-07-12_15-27-48.png){ width="500" }

Inside Home assistant :

![](Images/ESP01-DHT22/2023-07-12_16-42-50.png){ width="300" }
![](Images/ESP01-DHT22/2023-07-12_16-44-35.png){ width="300" }

![](Images/ESP01-DHT22/2023-07-12_16-45-31.png){ width="400" }

Finish the installation in Home Assistant

![](Images/ESP01-DHT22/2023-07-12_17-59-27.png){ width="250" }
![](Images/ESP01-DHT22/2023-07-12_17-59-45.png){ width="350" }

![](Images/ESP01-DHT22/2023-07-12_18-00-01.png){ width="250" }

