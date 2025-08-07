#include "esphome.h"

class MQ2GasSensor : public PollingComponent, public Sensor {
 public:
  MQ2GasSensor() : PollingComponent(5000) {}

  void setup() override {}

  void update() override {
    float voltage = analogRead(this->pin_) * 3.3 / 4095.0;
    float ppm = voltage_to_ppm(voltage);
    publish_state(ppm);
  }

  void set_pin(uint8_t pin) { this->pin_ = pin; }

 protected:
  uint8_t pin_;

  float voltage_to_ppm(float voltage) {
    return (voltage - 2.5) * (10000.0 / (4.0 - 2.5));
  }
};