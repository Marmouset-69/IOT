# Control screen

## Raspberry setup

### VNC config
Just go to menu /Preference / Raspberr pi Configuration / Interface to activate VNC
Use "VNC viewer" app. to view the screen

### Start chromium in kiosk mode
Launch Chromium at boot in full screen (kiosk mode)

[See Philippe Garry blog ](http://blog.philippegarry.com/2016/03/29/faire-de-son-pi-une-borne-raspberry-pi-kiosk-mode-jessie-version/)

```
cd ~/.config/autostart/
vi ~/.config/autostart/autoChromium.desktop
```
Within the file "autoChromium.desktop" add the following text to the bottom of the file.
```
[Desktop Entry]
Type=Application
Exec=/usr/bin/chromium-browser --noerrdialogs --disable-session-crashed-bubble --disable-infobars --kiosk http://www.google.com
Hidden=false
X-GNOME-Autostart-enabled=true
Name[en_US]=AutoChromium
Name=AutoChromium
Comment=Start Chromium when GNOME starts
```
```
reboot
```


!!! info "Quit kiosk mode"
    Alt+F4 (or Mac : fn + Cmd + F4)

### How to mount Raspberry on Mac OS

See [Pi My Life Up](https://pimylifeup.com/raspberry-pi-afp/)

```
sudo apt update
sudo apt upgrade
sudo apt install netatalk
sudo vi /etc/netatalk/afp.conf
```

```
[Homes]
    basedir regex = /home
```
Restart
```
sudo systemctl restart netatalk
```

Write this IP down as we will need it for connecting to the shared drive.

```
sudo hostname -I
```

### Setup PIR sensor
#### Wire
#### Files

```
import sys
import time
import RPi.GPIO as io
import subprocess

io.setmode(io.BOARD)
SHUTOFF_DELAY = 120 # seconds
PIR_PIN=11

# Attention, apres une detection, le PIR renvoyer 1 pendant une 15aine de seconde

def main():
    print ("Detection started.")
    print ("Wait", SHUTOFF_DELAY, "sec before all is OK")
    io.setup(PIR_PIN, io.IN)
    turned_off = False
    last_motion_time = time.time()
    while True:
        if io.input(PIR_PIN):
            last_motion_time = time.time()
            sys.stdout.flush()
            if turned_off:
                turned_off = False
                turn_on()
                print ("ON")
        else:
            if not turned_off and time.time() > (last_motion_time + SHUTOFF_DELAY):
                turned_off = True
                turn_off()
                print ("OFF")
            if not turned_off and time.time() > (last_motion_time + 1):
                time.sleep(.1)

def turn_on():
    subprocess.call("sh /home/pi/Desktop/Cuisine/monitor_on.sh", shell=True)

def turn_off():
    subprocess.call("sh /home/pi/Desktop/Cuisine/monitor_off.sh", shell=True)

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        io.cleanup()
```

```
vcgencmd display_power 1 > /dev/null
```
```
vcgencmd display_power O > /dev/null
```
