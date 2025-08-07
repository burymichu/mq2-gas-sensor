#include "mq2_gas_sensor.h"

namespace esphome {
namespace mq2_gas_sensor {

void MQ2GasSensor::setup() {}

void MQ2GasSensor::update() {
  float voltage = analogRead(pin_) * 3.3 / 4095.0;
  float ppm = voltage_to_ppm(voltage);
  publish_state(ppm);
}

float MQ2GasSensor::voltage_to_ppm(float voltage) {
  return (voltage - 2.5) * (10000.0 / (4.0 - 2.5));
}

}  // namespace mq2_gas_sensor
}  // namespace esphome