# MQ2 Gas Sensor for ESPHome

Custom ESPHome component for MQ2 gas sensor using analog input.

## Usage

```yaml
external_components:
  - source: github://burymichu/mq2-esphome
    components: [mq2_gas_sensor]

sensor:
  - platform: mq2_gas_sensor
    name: "MQ2 Gas Sensor"
    pin: GPIO34
```