# Shelly EM with MQTT

**How to use Shelly EM with Home Assistant**

### Shelly EM / Wire

![](Images/IMG_4549.jpg){ width="250" }
![](Images/IMG_4550.jpg){ width="310" }


## Configuration
### Shelly configuration
Plug in the Shelly. It does not appear on the network.
You have to go on the Shelly app first to declare it.
It's not necessary to go to the end of the installation.
We can stop when we ask for the name of the device.

![](Images/IMG_4541.PNG){ width="150" }
![](Images/IMG_4547.PNG){ width="150" }
![](Images/IMG_4543.PNG){ width="150" }
![](Images/IMG_4548.PNG){ width="150" }

![](Images/IMG_4542.PNG){ width="150" }
![](Images/IMG_4545.PNG){ width="150" }
![](Images/IMG_4546.PNG){ width="150" }

You can now find the device on the networker. In my example the IP of the device is 10.0.114.
Go to the web interface of the Shelly and **disable the connection to the cloud**.

![](Images/2022-12-07_15-49-38-cjt9x.png){ width="500" }


!!! warning
    **Update** the device. It's necessery to have **CoIot** protocol.

    ![](Images/2022-12-07_15-48-32-o0cu3.png){ width="500" }

To configure MQTT protocol, fill in the fields with values defined in Home Assistant.

![](Images/2022-12-07_15-51-53-axa1j.png){ width="400" }
![](Images/2022-12-07_15-56-47-69gzp.png){ width="400" }

!!! info
    Username and password are in the Mosquitto configuration. Password is a very long string

    ![](Images/2022-11-16_19-20-23-3sqrg.png){ width="200" }
    ![](Images/2022-11-16_19-20-32-61eiw.png){ width="300" }

    ![](Images/2022-11-16_19-20-48-pe6is.png){ width="400" }

Now, you can save and reboot the Shelly.

### Home Assistant configuration

The configuration of the Shelly device is now finished. Go to Home Assistant for the last step.

![](Images/2022-12-07_15-59-30-pnq91.png){ width="300" }
![](Images/2022-12-07_15-59-39-sv6r6.png){ width="400" }

![](Images/2022-12-07_15-59-57-l99ns.png){ width="300" }
![](Images/2022-12-07_16-01-04-usda6.png){ width="300" }

![](Images/2022-12-07_16-02-03-3vdm6.png){ width="700" }

![](Images/2022-12-07_17-24-28.png){ width="340" }
![](Images/2022-12-07_17-24-45.png){ width="400" }

