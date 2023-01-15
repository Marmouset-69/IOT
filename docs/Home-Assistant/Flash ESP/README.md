# Flash ESP
## Example of ESP8266 + DHT22

<img src="Images/2022-10-09_10-11-25-fdr4h.png" width="600"/>

``` yaml
esphome:
  name: esp8266-01

esp8266:
  board: esp01_1m

# Enable logging
logger:

# Enable Home Assistant API
api:

ota:
  password: "fce4d1f6a9c5d8fb2a1158b0013b182c"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Esp8266-01 Fallback Hotspot"
    password: "uUcRFwj1RvMz"

captive_portal:
sensor:
  - platform: dht
    model: DHT22
    pin: 4
    temperature:
      name: "Salon Temperature (ESP8622-salon .44)"
      filters:
        offset: 0.2      
    humidity:
      name: "Salon Humidity  (ESP8622-salon .44)"
      filters:
        offset: -0.25      
    update_interval: 600s
```

<img src="Images/2022-10-09_09-47-21-xd5ut.png" width="400"/>

<img src="Images/2022-10-09_09-47-30-g6m3z.png" width="300"/>

<img src="Images/2022-10-09_09-47-50-sji1a.png" width="500"/>

<img src="Images/2022-10-09_10-09-49-h4082.png" width="500"/>


!!! failure "Could not open serial port"

    <img src="Images/2022-10-09_10-27-42-7c6gd.png" width="450"/>

    ESP is not in flash mode -> press boot button when you flash

    <img src="Images/2022-10-09_10-30-32-mrxj3.png" width="450"/>

    <img src="Images/2022-10-09_10-30-51-i8pkx.png" width="450"/>

