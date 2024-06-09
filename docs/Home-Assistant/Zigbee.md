# Zigbee device

## Zigbee dongle

![](Images/Zigbee/2024-05-15_14-42-04.png){ width="500" }

Doc from Aliexpress

```
Description
Report Item
Zigbee 3.0 USB Dongle Based on Silicon Labs EFR32MG21 Universal Zigbee Gateway
ZB-GW04 USB Dongle Support via ZHA Zigbee2MQTT Connect Zigbee Device

Notice:
This ZigBee 3.0 usb dongle already with ZigBee2MQTT software pre flashed.

Feature:

It comes pre-flashed with an unsigned EmberZNet 6.7.9 Zigbee NCP application
firmware with Silabs standard EZSP v8 (EmberZNet Serial Protocol version 8)
interface enabled as well as the standard Silabs Gecko Bootloader firmware
for recovery, meaning it can be used either as-is out-of-the-box or flashed
with custom application firmware via USB.

Hardware is at its core based onSilicon Labs EFR32MG21 Series 2 Multiprotocol
Wireless SoC(part numberEFR32MG21A020F768IM32) and aWCH CH340E USB to Serial/UART
Bridge Controller. While it only has a PCB circuit board antenna the radio has
an integrated +20 dBm Power Amplifier (output power) and -104.5 dBm Receive
Sensitivity which should be made for a very good Zigbee coordinator or Zigbee
router if both hardware and firmware were properly implemented.

TheElelabs EZSP Firmware Upgrade Utility(https://github.com/Elelabs/elelabs-zigbee-ezsp-utility/)
orwalthowd firmware update Docker image(https://github.com/walthowd/husbzb-firmware)
can be used to flash the firmware to a newer or older version. New and old firmware
official images are currently being provided at github
(https://github.com/xsp1989/zigbeeFirmware/tree/master/firmware/Zigbee3.0_Dongle)

If the device is following Zigbee standards it is possible it will work with
other gateway solutions, it is just not confirmed as working yet!

Specification:

Product model: ZB-GW04 USB dongle
Pre-flashed with EZSP v8 (EmberZNet Serial Protocol version 8)
Can use ZHA in Home Assistant or Zigbee2MQTT (pre-alpha)
Base on EFR32MG21+CH340E
+20dBm output gain，PCB antenna
Plastic Shell
Support OTA Via Uart (Press the BOOT button,then press and release
  the nRST button, finally release the BOOT button)
Baud rate: 115200
```

![](Images/Zigbee/ali1.jpg){ width="300" }
![](Images/Zigbee/ali2.jpg){ width="300" }

![](Images/Zigbee/ali3.jpg){ width="300" }
![](Images/Zigbee/ali4.jpg){ width="300" }

![](Images/Zigbee/ali5.jpg){ width="300" }
![](Images/Zigbee/ali-dongle.webp){ width="300" }



## Pir sensor

**Zigbee Mini PIR Motion Sensor Human Motion Infrared Detector
Security Alarm Work With Alexa Google Home Zigbee2MQTT Need Gateway**

![](Images/Zigbee/pir-zigbee.png){ width="200" }

Sensor purchased on Aliexpress:

![](Images/Zigbee/2024-05-15_14-29-57.png){ width="600" }

Aliexpress description :
```
Product Name: Zigbee PIR Motion Sensor
Wireless Procotol: Zigbee 3.0(Zigbee gateway is needed)
Operating Voltage: 3V
Battery Type: CR2450
Stand-by Time: 1 Year
App: eWelink
Material: ABS
Dimensions:  Φ 33*28mm

Mini body, small and exquisite.
Human motion detection, instant App notification, no missing alarm.
High precision infrared detector, more accurate.
Airflow suppression, avoid false detection.
Intelligent linkage with other ewelink products.
Multi-scenario application, easy to install.
```
![](Images/Zigbee/ali-pir1.jpg){ width="400" }
![](Images/Zigbee/ali-pir2.jpg){ width="400" }

### Home assistant installation

![](Images/Zigbee/2024-05-15_14-13-35.png){ width="300" }

![](Images/Zigbee/2024-05-15_14-13-53.png){ width="600" }

![](Images/Zigbee/2024-05-15_14-14-08.png){ width="600" }

**Add a new sensor**

![](Images/Zigbee/2024-05-15_14-14-21.png){ width="600" }

![](Images/Zigbee/2024-05-15_14-16-37.png){ width="300" }

![](Images/Zigbee/2024-05-15_14-17-59.png){ width="600" }

## Switch

![](Images/Zigbee/2024-05-15_15-12-37.png){ width="600" }

Aliexpress description:
```
Zigbee gateway is needed, ewelink zigbee hub/Zigbee2MQTT, Tuya not compatible currently!

Note: Intelligent linkage to ewelink smart devices for normal use only, `
can not be used alone without ewelink smart device.

Specifications:
Power supply: Battery CR2032 3V DC(included)
Communication: Zigbee 3.0 *(zigbee hub is needed, except Tuya)
Control distance: 30m open area
Dimensions: 50 X 50mm
Operating temperature: -10 °C~55 °C
Working Humidity: 0~99%RH
Life of battery: 2 years (General use)

Package Content:
1* Zigbee Smart Button
1* User Manual
1* Double-sided Sticker
1* CR2032 Battery

【Two-in-one device for wireless scene】In the scene mode, the button respectively
support single click, double click scene requirements. You don't need to click the
scene mode on your phone, just click the ZigBee smart remote control to open the smart scene.

【No need to install】 Can be hung on the wall, can also be placed on the table,
and you can get it at your fingertips.

【Create multiple intelligent scenes for ewelink smart devices in App under
scenario mode】To create any smart automation as you want on your smart phone
app to start your another intelligent lifestyle, when you are tired from one-day
work,such as home mode, waterproof level up to IP55 for wider applications.
```

### Home assistant installation
 
See pir sensor installation
