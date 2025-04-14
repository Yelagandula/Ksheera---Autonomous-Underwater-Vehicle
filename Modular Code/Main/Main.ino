#include <Arduino.h>
#include "Sensors.h"
#include "Storage.h"
#include "Telemetry.h"
#include "Control.h"

void setup() {
  Serial.begin(9600);
  GPS_SERIAL.begin(9600);

  initSensors();
  initStorage();
  initTelemetry();
  initControl();
}

void loop() {
  readAllSensors();
  handleDepthControl();
  String logLine = buildDataString();
  logToSD(logLine);
  sendTelemetry(logLine);
  delay(1000);
}


// ===== File: Sensors.h =====
#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>

extern float currentDepth, bmpTemp, bmpPressure;
extern float latitude, longitude;
extern int16_t ax, ay, az;

void initSensors();
void readAllSensors();
String buildDataString();

#endif
