# Lovelace alignement

![](Images/Lovelace-alignement/2023-03-04_15-48-30.png){ width="700" }

![](Images/Lovelace-alignement/2023-03-04_15-53-56.png){ width="700" }

![](Images/Lovelace-alignement/2023-03-04_15-54-08.png){ width="300" }
![](Images/Lovelace-alignement/2023-03-04_15-54-16.png){ width="300" }
![](Images/Lovelace-alignement/2023-03-04_15-54-25.png){ width="300" }

``` yaml
type: custom:layout-card
layout_type: grid
layout:
    grid-template-columns: 40% 60%
    grid-template-areas: |
    "zone1 zoneV"
    "zone2 zoneV"
cards:
  - type: entity
    entity: sensor.bureau_dht22_temperature
    view_layout:
       grid-area: zone1
  - type: entity
    entity: sensor.bureau_dht22_temperature
    view_layout:
        grid-area: zoneV
  - type: entity
    entity: sensor.bureau_dht22_temperature
    view_layout:
        grid-area: zone2

```