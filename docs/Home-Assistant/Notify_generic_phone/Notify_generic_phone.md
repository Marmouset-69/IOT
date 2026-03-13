# Door Monitoring Automation with Mobile Alerts

This automation monitors the entrance door sensor in Home Assistant.
It detects when the door changes state from closed to open.
When the change occurs, the automation is triggered immediately.
A push notification is then sent to the user’s phone.
This alert informs the user that the front door has just been opened.

Define a generic notification service in configuration.yaml.
Create a group notify service that points to the phone notification service.
Example: notify.mon_telephone mapped to mobile_app_iphone_xxx.
You can then reuse notify.mon_telephone in any automation without changing the phone name.


``` Automation.yaml
alias: "ALERT: FRONT DOOR (closed -> open) -> SMS"
description: ""
mode: single
triggers:
  - entity_id:
      - binary_sensor.zigbee_door_sensor_2_entree_contact
    from: "off"
    to: "on"
    trigger: state
conditions: []
actions:
  - metadata: {}
    data:
      message: "It has just been opened!"
      title: "Front Door"
      data:
        push:
          sound:
            name: default
            critical: 1
            volume: 0.5
    action: notify.{{ states('input_text.mon_telephone') }}
```

``` configration.yaml
input_text:
  mon_telephone:
    initial: "mobile_app_iphone_17_pro_max_papa"
 ```