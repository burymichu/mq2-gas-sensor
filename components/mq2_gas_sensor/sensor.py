import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, CONF_PIN

mq2_ns = cg.esphome_ns.namespace("mq2_gas_sensor")
MQ2GasSensor = mq2_ns.class_("MQ2GasSensor", sensor.Sensor, cg.PollingComponent)

CONFIG_SCHEMA = sensor.sensor_schema().extend({
    cv.Required(CONF_PIN): cv.gpio_pin,
}).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await sensor.register_sensor(var, config)
    cg.add(var.set_pin(config[CONF_PIN]))
