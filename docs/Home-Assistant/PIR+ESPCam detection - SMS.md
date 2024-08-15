# Motion detection and sending a snapshot from an ESPcam

Create the automation:
(see [https://www.youtube.com/watch?v=6jkzy2Cv9Pk]())
```yaml
alias: "ALERTE : motion detection - chaîne Hifi -> SMS"
description: ""
trigger:
  - type: occupied
    platform: device
    device_id: 49a8895fa0bc2c1106a685725bf46d5e
    entity_id: 0f7c8449187ec675d2c5fd4afda12ac5
    domain: binary_sensor
condition: []
action:
  - service: camera.snapshot
    target:
      device_id: bc1a3182b42a909df92afdf00304cdc0
    data:
      filename: /config/www/tmp/snapshot-salon.jpg
  - service: notify.mobile_app_iphone_xi_papge
    data:
      message: "Il y a quelqu'un dans le salon (PIR #3)"
      data:
        image: https://homeassistant.papge.fr/local/tmp/snapshot-salon.jpg
        entity_id: camera.esp32_cam_7
        actions:
          - action: URI
            title: Ouvrir Cameras
            uri: https://homeassistant.papge.fr/dashboard-cameras
mode: single
```
