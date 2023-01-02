# ESP-01S ( work! )
![ESP-01S](Images/Images-ESP-01S/ESP-01S.JPG){ width="200" }

## Steps
(more details below)

- **Add** a new ESP device - **esp8266**

![ESP-8266](Images/Images-ESP-01S/2022-10-21_19-15-31-jmve3.png){ width="300" }
![ESP-Legacy](Images/Images-ESP-01S/2022-10-21_20-40-36-72n4c.png){ width="300" }

- copy the **code** (see below)
- **install** - "Manual download"

![Manual dowload](Images/Images-ESP-01S/2022-10-21_20-26-54-6cr0y.png){ width="500" }

- plug the esp01 on "**USB to ESP-01 Adapter** Board" (see below)
- flash the esp01 with **ESPHome-flasher**
- plug the **esp01 on the DHT22 board**
- use **LanScan** to find the new devise

![LanScan](Images/Images-ESP-01S/2022-10-21_18-55-21-ph0h2.png){ width="600" }

- go to your router and configure a **static IP** for this new device

![LanScan](Images/Images-ESP-01S/2022-10-21_20-52-41-f4m7a.png){ width="600" }

- unplug / plug the device to **update** the new IP
- go to integration of Homeassistant and **configure** the new integration

![LanScan](Images/Images-ESP-01S/2022-10-21_20-56-09-lri2o.png){ width="400" }

![LanScan](Images/Images-ESP-01S/2022-10-21_20-56-21-c0rbw.png){ width="200" }
![LanScan](Images/Images-ESP-01S/2022-10-21_20-56-49-lgmhm.png){ width="200" }

## esphome code

```
name: esp32-dht22-02

esp8266:
board: esp01_1m

# Enable logging
logger:

# Enable Home Assistant API
api:

ota:
password: "864868a05abffdf5f9bb073518cd0809"

wifi:
ssid: !secret wifi_ssid
password: !secret wifi_password

# Enable fallback hotspot (captive portal) in case wifi connection fails
ap:
ssid: "Esp32-Dht22-02 Fallback Hotspot"
password: "WXjJplTlkNPa"

captive_portal:
sensor:
- platform: dht
# model: DHT22 Don't work
model: AM2302
pin: GPIO02
temperature:
name: "esp01-dht22-04 Temperature"
filters:
- offset: 0.0
humidity:
name: "esp01-dht22-04 Humidite"
filters:
- offset: 0.0
update_interval: 600s
```

## Flash ESP
USB to ESP-01 Adapter Board

![adaptater-USB](Images/Images-ESP-01S/adaptater-USB.png){ width="200" }

### Home assistant

To be sure to correctly flash ESP make a .bin file. Use "Manual download"

![Manual download](Images/Images-ESP-01S/Manual-dowload.png){ width="300" }

## ESPHome-Flasher

Use "ESPHome-Flasher" to flash the ESP

![ESPHome logo](Images/Images-ESP-01S/esphome-flasher.png){ width="200" }

## Box

Make the associated USB cable (see page "USB Cable").


Solder the two male pins on the back of the ESP. Mark the positive terminal in red so as not to make a mistake.
Make a box with a 3D printer and put the whole thing inside.

It is finished.