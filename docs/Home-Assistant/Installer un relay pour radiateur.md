# Installation of Z-Wave and Qubino entities

![](Images/Z-Wave-Qubino/usb-z-wave-plus-z-stick-gen5.jpg){ width="200" }
![](Images/Z-Wave-Qubino/micro-module-commutateur-qubino-1-relais-et-conso-metre-z-wave-plus.jpg){ width="200" }

Plug the Z-Wave usb dongle on your Home Assistant server

The dongle is automaticaly reconnized

![](Images/Z-Wave-Qubino/2023-03-01_15-45-06.png){ width="300" }
![](Images/Z-Wave-Qubino/2023-03-01_15-45-18.png){ width="300" }

![](Images/Z-Wave-Qubino/2023-03-01_15-45-39.png){ width="300" }
![](Images/Z-Wave-Qubino/2023-03-01_15-46-05.png){ width="300" }

![](Images/Z-Wave-Qubino/2023-03-01_15-47-19.png){ width="300" }

That's all!


# Old instructions



## Qubino Flush 2 relay on an electric radiator
### Model
![](Images/Z-Wave-Qubino/relay_7494.JPG){ width="200" }

!!! info
    Site de Qubino : [https://qubino.com/products/flush-2-relays/](https://qubino.com/products/flush-2-relays/)

![](Images/Z-Wave-Qubino/relay_7496.PNG){ width="200" }
![](Images/Z-Wave-Qubino/relay_7497.PNG){ width="200" }
![](Images/Z-Wave-Qubino/relay_7498.PNG){ width="200" }
![](Images/Z-Wave-Qubino/relay_7499.PNG){ width="200" }
![](Images/Z-Wave-Qubino/relay_7500.PNG){ width="200" }
![](Images/Z-Wave-Qubino/relay_7501.PNG){ width="200" }
![](Images/Z-Wave-Qubino/relay_7502.PNG){ width="200" }

### Wire
Replace the bulb with the radiator!!!

![](Images/Z-Wave-Qubino/relay_7492.JPG){ width="300" }
![](Images/Z-Wave-Qubino/relay_7493.JPG){ width="300" }

### Home Assistant Config

![](Images/Z-Wave-Qubino/relay_2022-01-02-16-54-16.png){ width="450" }

![](Images/Z-Wave-Qubino/relay_HA_2022-01-02-16-59-09.png){ width="450" }

![](Images/Z-Wave-Qubino/relay_HA_2022-01-02-16-59-18.png){ width="450" }

![](Images/Z-Wave-Qubino/relay_HA_2022-01-02-17-05-40.png){ width="350" }

### Rename relay
![](Images/Z-Wave-Qubino/relay_18-14-13.png){ width="450" }

![](Images/Z-Wave-Qubino/relay_18-14-28.png){ width="450" }

![](Images/Z-Wave-Qubino/relay_18-19-20.png){ width="450" }

![](Images/Z-Wave-Qubino/relay_18-19-47.png){ width="450" }

![](Images/Z-Wave-Qubino/relay_18-20-09.png){ width="450" }

### If the relay is no longer accessible

!!! note
    Read [documentation](Docs/Qubino_Flush-2-Relay-PLUS-extended-manual_eng_2.3.pdf ).

Do a factory reset :
Unplug - replug 5 times in less than 3 seconds in the first minute of operation!

!!! info
    FACTORY RESET
        1. Connect the device to the power supply
        2. Within the first minute (60 seconds) the device is connected to the >power supply, toggle the switch connected to the I1 terminal 5 times >within 3 seconds (5 times change switch state).