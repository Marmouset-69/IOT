# Shelly 1 with MQTT

**How to use Shelly 1 & Shelly 1PM with Home Assistant**
!!! info
    An other interested page is https://sequr.be/blog/2020/10/getting-started-with-mqtt-and-home-assistant-and-shelly/

### Shelly 1 & Shelly 1PM

![](Images/IMG_4303.jpg){ width="320" }
![](Images/IMG_4326.JPG){ width="290" }


## Wire

### Shelly 1
![](../Images/Shelly-1PM/wire.png){ width="300" }

![](Images/IMG_4301.jpg){ width="300" }
![](Images/IMG_4302.jpg){ width="280" }

### Shelly 1PM

![](Images/IMG_4328.jpg){ width="260" }
![](Images/IMG_4329.jpg){ width="310" }

### Cumulus & Shelly 1PM

![](Images/IMG_4333.jpg){ width="280" }

## Configuration
### Shelly configuration
Plug in the Shelly. It does not appear on the network.
You have to go on the Shelly app first to declare it.
It's not necessary to go to the end of the installation.
We can stop when we ask for the name of the device.

![](Images/IMG_4305.PNG){ width="150" }
![](Images/IMG_4306.PNG){ width="150" }
![](Images/IMG_4307.PNG){ width="150" }
![](Images/IMG_4308.PNG){ width="150" }

You can now find the device on the networker. In my example the IP of the device is 10.0.4.
Go to the web interface of the Shelly and **remove the connection to the cloud**.

![](Images/2022-11-16_19-03-59-ck26n.png){ width="500" }

!!! warning
    **Update** the device. It's necessery to have **CoIot** protocol.
    
    ![](Images/2022-11-16_19-24-42-hapwu.png){ width="500" }

To configure MQTT protocol, fill in the fields with values defined in Home Assistant.


![](Images/2022-11-16_19-25-58-zzxi1.png){ width="400" }

!!! info
    Username and password are in the Mosquitto configuration. Password is a very long string

    ![](Images/2022-11-16_19-20-23-3sqrg.png){ width="200" }
    ![](Images/2022-11-16_19-20-32-61eiw.png){ width="300" }

    ![](Images/2022-11-16_19-20-48-pe6is.png){ width="400" }

Now, you can reboot the Shelly.

![](Images/2022-11-16_19-27-19-yhfdw.png){ width="400" }

### Home Assistant configuration

The configuration of the Shelly device is now finished. Go to Home Assistant for the last step.

![](Images/2022-11-16_20-02-51-kyree.png){ width="200" }
![](Images/2022-11-16_19-28-09-fri3x.png){ width="400" }

![](Images/2022-11-16_19-28-25-omh8v.png){ width="300" }
![](Images/2022-11-16_20-31-39-qci2t.png){ width="300" }


