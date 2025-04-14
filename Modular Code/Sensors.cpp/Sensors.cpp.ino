#include "Sensors.h"
#include <Wire.h>
#include <TinyGPS++.h>
#include <MPU6050.h>
#include "MS5837.h"
#include <Adafruit_BMP280.h>

MPU6050 imu;
MS5837 depthSensor;
Adafruit_BMP280 bmp;
TinyGPSPlus gps;

#define GPS_SERIAL Serial1

float currentDepth, bmpTemp, bmpPressure;
float latitude, longitude;
int16_t ax, ay, az, gx, gy, gz;

void initSensors() {
  Wire.begin();
  imu.initialize();
  depthSensor.init();
  depthSensor.setModel(MS5837::MS5837_30BA);
  depthSensor.setFluidDensity(997);
  bmp.begin(0x76);
}

void readAllSensors() {
  while (GPS_SERIAL.available()) gps.encode(GPS_SERIAL.read());
  latitude = gps.location.isValid() ? gps.location.lat() : 0.0;
  longitude = gps.location.isValid() ? gps.location.lng() : 0.0;

  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  depthSensor.read();
  currentDepth = depthSensor.depth();
  bmpTemp = bmp.readTemperature();
  bmpPressure = bmp.readPressure();
}

String buildDataString() {
  unsigned long timestamp = millis();
  return String(timestamp) + "," + String(latitude, 6) + "," + String(longitude, 6) + "," +
         String(currentDepth, 2) + "," + String(bmpTemp, 2) + "," + String(bmpPressure, 2) + "," +
         String(ax) + "," + String(ay) + "," + String(az);
}
