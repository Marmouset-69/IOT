# Heating Management with Home Assistant, Shelly Plus 1PM, and ZWT198 Thermostat

![](Images/Shelly+ZWT198/ZWT198.png){ width="150" }
![](Images/Shelly+ZWT198/shellyPlus1PM.jpg){ width="150" }
![](Images/Shelly+ZWT198/radiator.png){ width="200" }

## Introduction

This project details the integration and automation of a heating system using:

- **Home Assistant (HA)** as the central platform.
- A **Zigbee Thermostat (ZWT198)** for temperature measurement and setpoint management.
- A **Shelly Plus 1PM** to control the electric radiator.

The goal is to enable bidirectional management between the thermostat and Home Assistant while automating radiator control.

---

## System Architecture

```text
+--------------------+     Zigbee       +--------------------+
| Thermostat ZWT198  | <--------------> |    Home Assistant  |
| (Temperature + Setpoint)             |
+--------------------+                  |
                                       |
                                       | Automations
                                       |
                                       v
                                +--------------------+
                                |   Shelly Plus 1PM  |
                                | (Radiator Control) |
                                +--------------------+
```

---

## Key Features

1. **Bidirectional Management:**
    - Modify the setpoint directly on the thermostat or via Home Assistant.
    - Automatic adaptation and state synchronization.

2. **Automation:**
    - The radiator is controlled based on the thermostat's state (active heating or not).

3. **Energy Monitoring:**
    - Monitor radiator consumption through the integrated Shelly Plus 1PM.

---

## Wiring Between the Radiator and Shelly Plus 1PM

The Shelly Plus 1PM is used to control the power supply to the radiator. Here are the steps to correctly connect the radiator:

1. **Required Materials:**
    - Shelly Plus 1PM
    - Electric radiator
    - Proper electrical wiring (appropriate gauge for the radiator's power).

2. **Wiring Diagram:**

   ```text
   [Main Power Supply (Phase)] ----> [Shelly Plus 1PM (Input)]
                                     |
                                     +--> [Shelly Output] ----> [Radiator (Phase)]
   [Main Power Supply (Neutral)] -----------------------------> [Radiator (Neutral)]
   ```

3. **Detailed Instructions:**
    - Connect the **phase** wire from the main power supply to the Shelly's input terminal (labeled `L`).
    - Connect the Shelly's output terminal (labeled `O`) to the **phase** wire of the radiator.
    - Directly connect the **neutral** wire from the main power supply to the radiator.
    - If required, connect the **ground** wire directly to the radiator (the Shelly does not have a ground terminal).

4. **Pre-Power-On Checks:**
    - Ensure all connections are properly insulated.
    - Verify the load on the Shelly does not exceed its maximum capacity (16A).

5. **Commissioning:**
    - Power on the Shelly and integrate it into Home Assistant via the Shelly app or the Home Assistant Shelly integration.
    - Test the radiator's power control via Home Assistant.

---

## Configuration in Home Assistant

### Zigbee Thermostat (ZWT198)

The thermostat is added to Home Assistant via a Zigbee gateway. The entity is detected as `climate.zigbee_thermostat`.

#### Example Lovelace Card:

```yaml
- type: thermostat
  entity: climate.zigbee_thermostat
  name: Dining Room Thermostat
```

---

### Radiator Control Automation

This automation links the thermostat to the Shelly.

#### `automations.yaml` File:

```yaml
alias: Radiator Control via ZWT198 Thermostat
description: >
  Synchronizes the radiator connected to the Shelly with the Zigbee thermostat.
  When the thermostat requests heating, the Shelly turns on.
  Otherwise, it turns off automatically.

triggers:
  - entity_id: climate.zigbee_thermostat
    attribute: hvac_action
    trigger: state
conditions: []
actions:
  - choose:
      - conditions:
          - condition: state
            entity_id: climate.zigbee_thermostat
            attribute: hvac_action
            state: heating
        sequence:
          - target:
              entity_id: switch.salle_a_manger_radiateur_shelly_1pm_switch_0
            action: switch.turn_on
            data: {}
      - conditions:
          - condition: state
            entity_id: climate.zigbee_thermostat
            attribute: hvac_action
            state: idle
        sequence:
          - target:
              entity_id: switch.salle_a_manger_radiateur_shelly_1pm_switch_0
            action: switch.turn_off
            data: {}
mode: single

```

---

### Energy Consumption Monitoring

The Shelly Plus 1PM measures the radiator's electrical consumption. Activate the `sensor.power` entity in Home Assistant to monitor power usage.

#### Example Lovelace Graph:

```yaml
- type: history-graph
  entities:
    - entity: sensor.dining_room_radiator_power
  hours_to_show: 24
  refresh_interval: 30
  title: Radiator Consumption
```

---

## Detailed Schematics

### Interaction with Home Assistant

```text
[Zigbee Thermostat ZWT198]  -->  [Home Assistant]
    + Setpoint                  + Automations
    + Measured Temperature      + State Updates

[Home Assistant]           -->  [Shelly Plus 1PM]
    + On/Off Command           + MQTT/HTTP API
```

---

## Testing Steps

1. **Test the Thermostat:**
   - Change the setpoint on the thermostat and verify that Home Assistant updates the target temperature.

2. **Test Radiator Control:**
   - Manually activate/deactivate the thermostat to see if the Shelly responds correctly.

3. **Test Energy Consumption:**
   - Turn on the radiator and monitor the power displayed in Home Assistant.

---

## Expected Results

- **Bidirectionality:** Any modification made from the thermostat or HA is synchronized and reflected.
- **Automation:** The radiator operates only when the thermostat requests heating.
- **Energy Monitoring:** The radiator's consumption is visible in HA.

---

## Future Improvements

- Add an "Eco" mode with reduced setpoints according to predefined schedules.
- Integrate additional sensors (humidity, window opening) to optimize heating management.
- Implement HA notifications to alert if the heating remains on for too long.
```

This Markdown page provides a comprehensive overview of your project, suitable for inclusion in your MkDocs site. If you have any further questions or need additional adjustments, feel free to ask! 😊