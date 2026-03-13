# 13/03/2026

alias: "ALERT : porte d'ENTREE (fermée -> ouvert) -> SMS"
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
      message: "On vient de s'ouvrir !"
      title: "Porte d'Entrée"
      data:
        push:
          sound:
            name: default
            critical: 1
            volume: 0.5
    action: notify.{{ states('input_text.mon_telephone') }}

