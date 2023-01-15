# control screen

## Raspberry setup

### VNC config
Just go to menu /Preference / Raspberr pi Configuration / Interface to activate VNC
Use "VNC viewer" app. to view the screen

### Start chromium in kiosk mode
Launch Chromium at boot in full screen (kiosk mode)

[See Philippe Garry blog ](http://blog.philippegarry.com/2016/03/29/faire-de-son-pi-une-borne-raspberry-pi-kiosk-mode-jessie-version/)

- cd ~/.config/autostart/
- vi ~/.config/autostart/autoChromium.desktop
- copy
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
- reboot

!!! info "Quit kiosk mode"
Alt+F4 (or Mac : fn + Cmd + F4)

