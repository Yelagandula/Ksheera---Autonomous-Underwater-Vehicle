#include <Wire.h>
#include <MPU6050.h>
#include "MS5837.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// Sensor Instances
MPU6050 imu;
MS5837 depthSensor;
Adafruit_BMP280 bmp;

// Variables for MPU6050
int16_t ax, ay, az, gx, gy, gz;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // MPU6050 initialization
  imu.initialize();
  if (imu.testConnection()) {
    Serial.println("MPU6050 OK!");
  } else {
    Serial.println("MPU6050 Failed!");
  }

  // MS5837 initialization
  if (depthSensor.init()) {
    Serial.println("MS5837 OK!");
    depthSensor.setModel(MS5837::MS5837_30BA);
    depthSensor.setFluidDensity(997); // Adjust if using seawater
  } else {
    Serial.println("MS5837 Failed!");
  }

  // BMP280 initialization
  if (!bmp.begin(0x76)) { // Try 0x77 if this fails
    Serial.println("BMP280 Failed!");
    while (1);
  } else {
    Serial.println("BMP280 OK!");
  }
}

void loop() {
  // IMU Data
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial.print("IMU Accel (X,Y,Z): ");
  Serial.print(ax); Serial.print(", ");
  Serial.print(ay); Serial.print(", ");
  Serial.print(az);

  Serial.print(" | Gyro (X,Y,Z): ");
  Serial.print(gx); Serial.print(", ");
  Serial.print(gy); Serial.print(", ");
  Serial.println(gz);

  // MS5837 Depth Sensor
  depthSensor.read();
  Serial.print("Depth(m): ");
  Serial.print(depthSensor.depth());
  Serial.print(" | Pressure(mbar): ");
  Serial.print(depthSensor.pressure());
  Serial.print(" | Temp(°C): ");
  Serial.println(depthSensor.temperature());

  // BMP280 Pressure and Temperature Sensor
  Serial.print("Ambient Temp(°C): ");
  Serial.print(bmp.readTemperature());
  Serial.print(" | Ambient Pressure(Pa): ");
  Serial.println(bmp.readPressure());

  Serial.println("-------------------------------------");
  delay(1000);  // Adjust based on logging frequency needed
}
