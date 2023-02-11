# Use Wifi on Intel NUC
## Install firmware-iwlwifi

!!! Info
    [Iwlwifi](https://wiki.debian.org/iwlwifi) (Intel Wireless WiFi Link) is the driver for Intel wireless cards.
### Add a "non-free" component to the apt sources.

Open the file `/etc/apt/sources.list` and add **contrib non-free** after **main** or just copy and paste following lines for Debian 11/Bullseye :
```bash title="sources.list"
deb http://deb.debian.org/debian bullseye main contrib non-free
deb-src http://deb.debian.org/debian bullseye main contrib non-free

deb http://deb.debian.org/debian-security/ bullseye-security main contrib non-free
deb-src http://deb.debian.org/debian-security/ bullseye-security main contrib non-free

deb http://deb.debian.org/debian bullseye-updates main contrib non-free
deb-src http://deb.debian.org/debian bullseye-updates main contrib non-free
```

### Update the list of available packages and install the iwlwifi package
    
```bash
apt update && apt install firmware-iwlwifi
```
```bash
modprobe -r iwlwifi ; modprobe iwlwifi
```
### Finally connect to your wifi network

Use the gnome network manager to connect to your wifi network.
