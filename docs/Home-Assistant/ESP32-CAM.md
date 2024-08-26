# ESP32-CAM Installation

![](Images/ESP32-CAM/2022-09-24_10-57-04.png){ width="200" }

![](Images/ESP32-CAM/2022-09-24_10-57-03.png){ width="100" }

![](Images/ESP32-CAM/2022-09-24_10-57-30.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_10-57-39.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_10-57-50.png){ width="200" }

![](Images/ESP32-CAM/2022-09-24_10-58-20.png){ width="300" }

Edit the code :
``` yaml
esphome:
  name: esp32-cam-5

esp32:
  board: esp32dev
  framework:
    type: arduino

web_server:
  port: 80

# Enable logging
logger:

# Enable Home Assistant API
api:

ota:
  password: "7178cc19180874c5bd1aaf8cac96abbd"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Esp32-Cam-5 Fallback Hotspot"
    password: "nm87iYcQoqcp"

captive_portal:
# Configuration for Ai-Thinker Camera
# https://esphome.io/components/esp32_camera.html#configuration-for-ai-thinker-camera
esp32_camera:
  name: "ESP32-cam-5"
  external_clock:
    pin: GPIO0
    frequency: 20MHz
  i2c_pins:
    sda: GPIO26
    scl: GPIO27
  data_pins: [GPIO5, GPIO18, GPIO19, GPIO21, GPIO36, GPIO39, GPIO34, GPIO35]
  vsync_pin: GPIO25
  href_pin: GPIO23
  pixel_clock_pin: GPIO22
  power_down_pin: GPIO32
  # Image settings
  max_framerate: 10 fps    # default: 10 fps, max 60
  idle_framerate: 0.2 fps # default: 0.1 fps - framerate for 'picture' in HA dashboard
  resolution: 1024x768     # default: 640x480 (VGA) - higher res requires more memory
  jpeg_quality: 10        # 10 (best) to 63 (worst)

switch:
  - platform: gpio
    name: "ESP32-cam-5 flash"
    pin: 4
    #inverted: True
  - platform: restart
    name: "ESP32-cam-5 - Restart"
    id: restart_switch
```
Select **Manual download**

![](Images/ESP32-CAM/2022-09-24_16-31-14.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_16-34-35-mlttu.png){ width="500" }

![](Images/ESP32-CAM/2022-09-24_16-38-16-yfosd.png){ width="500" }

!!! WARNING
    If the ESP is not visible on the serial port, it may be due to the cable, you must try another one

    ![](Images/ESP32-CAM/IMG_3976.JPG){ width="300" }

!!! WARNING
    If an error appears, it means that the ESP is not in "write" mode. You must then press the "IO0" button THEN connect the ESP and flash it.

    ![](Images/ESP32-CAM/IMG_3975.jpg){ width="250" }


![](Images/ESP32-CAM/2022-09-24_17-16-04-wshpx.png){ width="500" }

>Disconnect then reconnect the ESP

![](Images/ESP32-CAM/2022-09-24_17-18-33-076n7.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_17-21-33-46yb4.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_17-21-41-m2uyz.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_17-21-51-oyfpp.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_17-22-04-kssti.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_17-22-14-me3k0.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_17-22-40-a70lt.png){ width="300" }

![](Images/ESP32-CAM/2022-09-24_17-24-21-2psnt.png){ width="300" }
