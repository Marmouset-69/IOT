# Shelly 1 with MQTT

**How to use Shelly 1 & Shelly 1PM with Home Assistant**
!!! info
    An other interested page is https://sequr.be/blog/2020/10/getting-started-with-mqtt-and-home-assistant-and-shelly/

### Shelly 1 & Shelly 1PM

![](Images/Shelly-1PM/IMG_4303.jpg){ width="320" }
![](Images/Shelly-1PM/IMG_4326.JPG){ width="290" }


## Wire
### Shelly 1PM
![](Images/Shelly-1PM/wire.png){ width="260" }
![](Images/Shelly-1PM/IMG_5070.jpg){ width="420" }

![](Images/Shelly-1PM/IMG_4302.jpg){ width="280" }

![](Images/Shelly-1PM/IMG_5067.jpg){ width="240" }
![](Images/Shelly-1PM/IMG_4333.jpg){ width="330" }

!!! danger "Do not use with a ceramic hob, it can consume more than 3500 W (Shelly 1PM limit)"
    ![](Images/Shelly-1PM/IMG_5057.JPG){ width="280" }

### How to reset Shelly 1PM
- video : Reset the device : [youtube video](https://www.youtube.com/watch?v=dz7Aq4mGnQc)
- Reset : On - 5 times off - On
- go to http://192.168.33.1

### Configuration Shelly device : Solution 1 (with the Web browse)

Configuration method with the Web browser. We do not use the Shelly application.

!!! info
    This is the best solution. In fact app. Shelly v.1.35.22 doesn't work.

1. plug the Shelly device.
2. connect to the Shelly network
3. In a browser, go to http://192.168.33.1 (see below)
4. Configure the Shelly device

Find the Shelly network

![](Images/Shelly-1PM/2022-12-30_20-46-19.png){ width="300" }

Connect to [http://192.168.33.1](http://192.168.33.1)

![](Images/Shelly-1PM/2022-12-30_20-47-12.png){ width="300" }

Configure the network

![](Images/Shelly-1PM/2022-12-30_20-47-41.png){ width="300" }
![](Images/Shelly-1PM/2022-12-30_20-48-12.png){ width="300" }

Change your wi-fi network back to your home network.
Find the new device on your wifi network.
You can use [LanScan app.](https://www.iwaxx.com/lanscan/) (on [App Store](https://apps.apple.com/fr/app/lanscan/id472226235?mt=12) )

Update the firmware

![](Images/Shelly-1PM/2022-12-30_20-52-30.png){ width="300" }

Remove the cloud

![](Images/Shelly-1PM/2022-12-30_20-53-23.png){ width="300" }

Configure MQTT. See below

### Solution 2
Plug in the Shelly. It does not appear on the network.
You have to go on the Shelly app first to declare it.
It's not necessary to go to the end of the installation.
We can stop when we ask for the name of the device.

![](Images/Shelly-1PM/IMG_4305.PNG){ width="150" }
![](Images/Shelly-1PM/IMG_4306.PNG){ width="150" }
![](Images/Shelly-1PM/IMG_4307.PNG){ width="150" }
![](Images/Shelly-1PM/IMG_4308.PNG){ width="150" }

You can now find the device on the networker. In my example the IP of the device is 10.0.4.
Go to the web interface of the Shelly and **remove the connection to the cloud**.

![](Images/Shelly-1PM/2022-11-16_19-03-59-ck26n.png){ width="500" }

!!! warning
    **Update** the device. It's necessery to have **CoIot** protocol.

    ![](Images/Shelly-1PM/2022-11-16_19-24-42-hapwu.png){ width="500" }

## Configure MQTT

To configure MQTT protocol, fill in the fields with values defined in Home Assistant.

![](Images/Shelly-1PM/2022-11-16_19-25-58-zzxi1.png){ width="400" }

!!! info "Username and password are in the Mosquitto configuration. Password is a very long string"
    ![](Images/Shelly-1PM/2022-11-16_19-20-23-3sqrg.png){ width="200" }
    ![](Images/Shelly-1PM/2022-11-16_19-20-32-61eiw.png){ width="300" }
    ![](Images/Shelly-1PM/2022-11-16_19-20-48-pe6is.png){ width="400" }

Set "Restore Last Mode - Configure Shelly device to Restore the last mode it was in, when it has power."

![](Images/Shelly-1PM/2022-12-18_11-28-04.png){ width="380" }

Now, you can reboot the Shelly.

![](Images/Shelly-1PM/2022-11-16_19-27-19-yhfdw.png){ width="400" }

### Home Assistant configuration

The configuration of the Shelly device is now finished. Go to Home Assistant for the last step.

![](Images/Shelly-1PM/2022-11-16_20-02-51-kyree.png){ width="200" }
![](Images/Shelly-1PM/2022-11-16_19-28-09-fri3x.png){ width="400" }

![](Images/Shelly-1PM/2022-11-16_19-28-25-omh8v.png){ width="300" }
![](Images/Shelly-1PM/2022-11-16_20-31-39-qci2t.png){ width="300" }

### Static IP

Now you can change the IP on your router to have a static IP

### Rename entitie

Go to web interface and rename the Shelly

Go to Shelly configaration parameters on Home Assistant. Rename by clicking on the three dots menu

![](Images/Shelly-1PM/2023-03-01_15-07-37.png){ width="300" }
![](Images/Shelly-1PM/2023-03-01_15-07-52.png){ width="300" }

