#pragma once
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"

namespace esphome {
namespace mq2_gas_sensor {

class MQ2GasSensor : public PollingComponent, public sensor::Sensor {
 public:
  MQ2GasSensor() : PollingComponent(5000) {}

  void setup() override {}

  void update() override {
    float voltage = analogRead(this->pin_) * 3.3f / 4095.0f;
    float ppm = voltage_to_ppm(voltage);
    this->publish_state(ppm);
  }

  void set_pin(uint8_t pin) { this->pin_ = pin; }

 protected:
  uint8_t pin_;

  float voltage_to_ppm(float voltage) {
    return (voltage - 2.5f) * (10000.0f / (4.0f - 2.5f));
  }
};

}  // namespace mq2_gas_sensor
}  // namespace esphome
