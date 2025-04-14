#ifndef TELEMETRY_H
#define TELEMETRY_H
#include <Arduino.h>

void initTelemetry();
void sendTelemetry(const String& data);

#endif
