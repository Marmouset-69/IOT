# How to set ON/OFF a group of notifications

Add the following commands to "config.yaml"
``` config.yaml 
# By kangapi - switch ON/OFF a set of automation
group:
  vacation:
    unique_id: "20240815_1822"
    name: "Vacation Group"
    entities:
      - automation.alerte_motion_detection_salon_sms
      - automation.zigbee_detection_escalier
      - automation.pir_1_sms_dehors
      - automation.pir_2_detect_sms
      - automation.pir_3_detect_sms
      - automation.alerte_porte_de_garage_fermee_ouverte_sms
      - automation.alerte_porte_de_garage_ouverte_fermee_sms
```
