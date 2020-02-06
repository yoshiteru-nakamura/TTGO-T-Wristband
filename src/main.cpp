#include <Arduino.h>
#include <Wire.h>
#include <rom/rtc.h>
#include "wristband-tft.hpp"
#include "wristband-ota.hpp"
#include "clock.hpp"
#include "pages.hpp"
#include "mpu.hpp"

void setup()
{
  deactivateWifi();
  btStop();
  Serial.begin(115200);
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  Wire.setClock(400000);
  setupADC();
  initClock();
  initMPU();
  tftInit();
  initButton();
  setupBattery();
}

void loop()
{
  handleUi();
  updateBatteryChargeStatus();
}
