PZEM-004T

![](Images/IMG_4387.JPG){ width="250" }
![](Images/IMG_4388.JPG){ width="250" }
![](Images/IMG_4389.JPG){ width="250" }
![](Images/IMG_4411.JPG){ width="250" }
![](Images/IMG_4539.JPG){ width="250" }
![](Images/IMG_4540.JPG){ width="250" }

![](Images/2022-11-26_16-40-53-az832.png){ width="250" }
![](Images/2022-11-26_16-41-05-tgb8w.png){ width="250" }
![](Images/2022-11-26_16-42-21-h335r.png){ width="250" }
![](Images/2022-11-26_16-43-48-zk20r.png){ width="250" }
![](Images/2022-11-26_16-44-01-6s2cy.png){ width="250" }
![](Images/2022-11-26_16-44-17-ho3d7.png){ width="250" }

``` yaml
esphome:
    name: "energy-meter"
    comment: 'PZEM-004T power Meter'

esp8266:
    board: d1_mini

# Enable logging
logger:
    #level: VERY_VERBOSE

web_server:
    port: 80

api:

ota:

wifi:
    ssid: !secret wifi_ssid
    password: !secret wifi_password

# Enable fallback hotspot (captive portal) in case wifi connection fails
ap:
    ssid: "Power-Meter Fallback Hotspot"
    password: "rdG3mcBzeb32"

uart:
    rx_pin: D1
    tx_pin: D2
    baud_rate: 9600

captive_portal:

modbus:  # enable Modbus

sensor:
    - platform: pzemac
        current:
            name: 'Current'
        voltage:
            name: 'Voltage'
    energy:
        name: 'Energy'
        # convert it to kWh
        #filters:
        #  - multiply: 0.001
        #unit_of_measurement: 'kWh'
        #accuracy_decimals: 3
    power:
        name: 'Power'
    frequency:
        name: 'Frequency'
    power_factor:
        name: 'Power Factor'
    update_interval: 60s
```




![](Images/2022-11-26_17-07-25-rjyii.png){ width="250" }
![](Images/2022-11-26_17-10-45-smh5v.png){ width="250" }
![](Images/2022-11-26_17-11-06-vs9ad.png){ width="250" }
![](Images/2022-11-26_17-11-11-c2l75.png){ width="250" }
![](Images/2022-11-26_17-12-04-ky6jw.png){ width="250" }
![](Images/2022-11-26_17-12-14-24xym.png){ width="250" }
![](Images/2022-11-26_17-12-28-rrag8.png){ width="250" }
