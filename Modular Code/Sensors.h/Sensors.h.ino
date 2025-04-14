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
