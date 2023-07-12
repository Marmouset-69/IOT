# Lovelace alignement with "lovelace-layout-card"
See [lovelace-layout-card](https://github.com/thomasloven/lovelace-layout-card) documentation

## Two entities with % width
![](Images/Lovelace-alignement/2023-03-05_18-43-39.png){ width="700" }

### Insert new card "Layout Card"
![](Images/Lovelace-alignement/2023-03-05_18-33-23.png){ width="700" }

![](Images/Lovelace-alignement/2023-03-05_18-46-27.png){ width="700" }

![](Images/Lovelace-alignement/2023-03-05_18-46-41.png){ width="350" }
![](Images/Lovelace-alignement/2023-03-05_18-46-53.png){ width="350" }

``` yaml title="Layout options (layout-card)"
grid-template-columns: 30% auto
```
``` yaml title="Editor code"
type: custom:layout-card
layout_type: custom:grid-layout
layout:
    grid-template-columns: 30% auto
cards:
  - type: markdown
    content: 'The **Markdown** card allows you to write any text. '
  - type: markdown
    content: >
      The **Markdown** card allows you to write any text. You can style it
      **bold**, *italicized*, ~strikethrough~ etc. You can do images, links, and
      more.
```



## Three entities with % width
![](Images/Lovelace-alignement/2023-03-04_15-48-30.png){ width="700" }

![](Images/Lovelace-alignement/2023-03-04_15-53-56.png){ width="800" }
![](Images/Lovelace-alignement/2023-03-04_15-54-08.png){ width="400" }
![](Images/Lovelace-alignement/2023-03-04_15-54-16.png){ width="400" }

![](Images/Lovelace-alignement/2023-03-04_15-54-25.png){ width="400" }

``` yaml title="Layout options (layout-card)"
grid-template-columns: 40% auto
grid-template-areas: /
    "zonel zoneV"
    "zone2 zoneV"
```

``` yaml title="Editor code"
type: custom:layout-card
layout_type: custom:grid-layout
layout:
  grid-template-columns: 40% auto
  grid-template-areas: / "zone1 zoneV" "zone2 zoneV"
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

### Fixed height
![](Images/Lovelace-alignement/2023-03-04_17-10-41.png){ width="700" }

``` yaml title="Layout options (layout-card)"
grid-template-columns: 30% auto
grid-template-rows: auto 200px
grid-template-areas: |
  "zone1 zoneV"
  "zone2 zoneV"
```

### Width 100% of the window
![](Images/Lovelace-alignement/2023-03-04_17-42-36.png){ width="700" }

- Go to your lovelace views and select "Edit Dashboard"
- Click the pencil symbol next to the view name to open up the view properties
- Select "Side bar" from the "View type" dropdown list
- Click "Save"

![](Images/Lovelace-alignement/2023-03-04_17-25-00.png){ width="500" }

![](Images/Lovelace-alignement/2023-03-05_19-15-21.png){ width="300" }
