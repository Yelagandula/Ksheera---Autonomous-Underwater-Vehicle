#include <Wire.h>
#include "MS5837.h"

MS5837 sensor;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize sensor
  if (sensor.init()) {
    Serial.println("MS5837 initialization successful!");
    sensor.setModel(MS5837::MS5837_30BA); // Set your specific sensor model
    sensor.setFluidDensity(997);          // Density of freshwater (kg/m³), adjust if needed (e.g., seawater ~1029 kg/m³)
  } else {
    Serial.println("MS5837 initialization failed!");
  }
}

void loop() {
  sensor.read();

  Serial.print("Depth (m): ");
  Serial.print(sensor.depth());
  Serial.print(" | Pressure (mbar): ");
  Serial.print(sensor.pressure());
  Serial.print(" | Temp (°C): ");
  Serial.println(sensor.temperature());

  delay(500);
}
