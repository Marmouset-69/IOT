# FAQ

## Si l'esp n'ai pas reconnu
- changer de cable USB
- Changer d'adaptateur <br><img src="../Images/IMG_8334.jpg" width="300">
- installer le driver associé à l'esp (voir model sur le microprocesseur) <br><img src="../Images/IMG_8332.jpg" width="300"> <br><img src="../Images/Install-CP210x-VCP-Driver 2022-01-29 16-10-44.png" width="300">
- vérifier dans /dev si le port existe bien <br><img src="../Images/terminal.png" width="300">

## Impossibible de téléverser le code

<img src="../Images/upload-error.png" width="400"> 
http://127.0.0.1:8000/Home-Assistant/FAQ/FAQ/Images/IMG_8334.jpg

Il faut presser sur RESET + GPIO0 au moment du téléchargement. Attention il y a 3 boutons sur certain modèl ! Utiliser celui sous l’ESP et le GPIO0 du support.

ATTENTION : Il faut ensuite débrancher puis rebrancher l’ESP

Vidéo : https://youtu.be/v8s-UMqcTJs

Si cela ne fonctionne toujours pas
- débrancher l'alim. de l'esp (pin 5v ou 3.3v)
- débrancher toutes les pin et recommencer.

## Corespondance Dx -> GPIOx
<img src="../Images/ESP8266-NodeMCU-kit-12-E-pinout-gpio-pin.png" width="400">

## Re-discover / manually add Integration

!!! note
    You can just add the integration via the Add Integration button, use the device name with "**.local**" at the end for the host name.

![Image title](Images/2022-10-16_16-37-09-3zcj6.png){ width="200" }

![Image title](Images/2022-10-16_16-37-25-ckv2i.png){ width="380" } or
![Image title](Images/2022-12-30_22-03-45.png){ width="280" }

![Image title](Images/2022-10-16_16-33-14-5rq5p.png){ width="400" }

![Image title](Images/2022-10-16_16-33-28-1x9dq.png){ width="400" }

## Reset Shelly 1PM
Reset the device : https://www.youtube.com/watch?v=dz7Aq4mGnQc
Reset : On - 5 times off - On http://192.168.33.1