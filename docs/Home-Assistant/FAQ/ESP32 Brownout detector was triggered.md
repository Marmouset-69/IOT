# ESP32 “Brownout detector was triggered”

ESP32 Troubleshooting Guide: See https://randomnerdtutorials.com/esp32-troubleshooting-guide/

## Error: “Brownout detector was triggered”
When you open your Arduino IDE Serial monitor and the error message “Brownout detector was triggered” is constantly being printed over and over again. It means that there’s some sort of hardware problem.

It’s often related to one of the following issues:

- **Poor quality USB cable;**
- USB cable is too long;
- Board with some defect (bad solder joints);
- Bad computer USB port;
- Or not enough power provided by the computer USB port.

**Solution:** try a different shorter USB cable (with data wires), try a different computer USB port or use a USB hub with an external power supply.