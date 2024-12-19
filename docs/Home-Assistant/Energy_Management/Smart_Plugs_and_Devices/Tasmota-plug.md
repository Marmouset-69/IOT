# Tasmota - Athom Plug V2

## Configuration of Tasmota plug
Open Tasmota plug web page (here 10.0.4.97)

![](Images/Tasmota-plug/2022-12-17_09-53-06.png){ width="200" }
![](Images/Tasmota-plug/2022-12-17_11-09-07.png){ width="200" }
![](Images/Tasmota-plug/2022-12-17_09-58-08.png){ width="200" }

!!! warning  "Find passord"
    Go to MQTT configaration panel to find home assiatnt password.

    ![](Images/Tasmota-plug/2022-12-17_09-59-11.png){ width="305" }
    ![](Images/Tasmota-plug/2022-12-17_09-59-42.png){ width="250" }

Copy/passed password into Tasmota plug page.

Wait a few seconds. The new Tasmota plug is automaticaly discored.

![](Images/Tasmota-plug/2022-12-17_10-00-43.png){ width="600" }

![](Images/Tasmota-plug/2022-12-17_10-01-12.png){ width="600" }

![](Images/Tasmota-plug/2022-12-17_10-07-11.png){ width="600" }

## To reset total energey

![](Images/Tasmota-plug/2022-12-17_11-03-52.png){ width="300" }
![](Images/Tasmota-plug/2022-12-17_11-06-58.png){ width="300" }
![](Images/Tasmota-plug/2022-12-17_11-04-34.png){ width="600" }

```
EnergyReset3 0
```
!!! warning
    Warning: With version 10, this command has been replaced
    See: https://tasmota.github.io/docs/Commands/#power-monitoring