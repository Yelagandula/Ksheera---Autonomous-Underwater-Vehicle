#include <SPI.h>
#include <PID_v1.h>
#include <SD.h>
#include <Wire.h>
#include <LoRa.h>
#include <TinyGPS++.h>
#include <AccelStepper.h>
#include <MPU6050.h>
#include "MS5837.h"
#include <Adafruit_BMP280.h>
#include <SoftwareSerial.h>


// ----------------------------- PID Setup -----------------------------
double Setpoint = 1.5; // Target Depth in meters
double Input;          // Current Depth
double Output;         // Motor Steps to move
double Kp = 300, Ki = 10, Kd = 50; // PID tuning (adjust as needed)
PID depthPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// ----------------------------- Sensor Instances -----------------------------
MPU6050 imu;
MS5837 depthSensor;
Adafruit_BMP280 bmp;
TinyGPSPlus gps;

// ----------------------------- SD Card -----------------------------
File dataFile;
#define SD_CS_PIN 53

// ----------------------------- LoRa -----------------------------
#define LORA_CS 48
#define LORA_RST 47
#define LORA_IRQ 2

// ----------------------------- Stepper Motor (TB6600) -----------------------------
#define DIR_PIN 8
#define STEP_PIN 9
#define ENABLE_PIN 10
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// ----------------------------- GPS -----------------------------
#define GPS_SERIAL Serial1

SoftwareSerial GPS_SERIAL(4, 3);

void setup() {
  Serial.begin(9600);
  GPS_SERIAL.begin(9600);
  
  // ----------------------------- Sensor Init -----------------------------
  Wire.begin();
  imu.initialize();
  depthSensor.init();
  depthSensor.setModel(MS5837::MS5837_30BA);
  depthSensor.setFluidDensity(997); // Freshwater

  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 init failed!");
  }

  // ----------------------------- SD Card Init -----------------------------
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD init failed!");
  } else {
    Serial.println("SD initialized.");
    dataFile = SD.open("mission.csv", FILE_WRITE);
    if (dataFile) {
      dataFile.println("Time,Latitude,Longitude,Depth,Temp,Pressure,Ax,Ay,Az");
      dataFile.close();
    }
  }

  // ----------------------------- LoRa Init -----------------------------
  LoRa.setPins(LORA_CS, LORA_RST, LORA_IRQ);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed!");
  } else {
    Serial.println("LoRa initialized.");
  }

  // ----------------------------- Stepper Init -----------------------------
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW); // Enable motor driver
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);

  // ----------------------------- PID Init -----------------------------
  depthPID.SetMode(AUTOMATIC);
  depthPID.SetOutputLimits(-800, 800); // Limit stepper output range
}

void loop() {
  // ----------------------------- GPS Data -----------------------------
  while (GPS_SERIAL.available() > 0) gps.encode(GPS_SERIAL.read());
  float lat = gps.location.isValid() ? gps.location.lat() : 0.0;
  float lng = gps.location.isValid() ? gps.location.lng() : 0.0;

  // ----------------------------- IMU Data -----------------------------
  int16_t ax, ay, az, gx, gy, gz;
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // ----------------------------- Depth Sensor -----------------------------
  depthSensor.read();
  float currentDepth = depthSensor.depth();

  // ----------------------------- BMP280 Data -----------------------------
  float bmpTemp = bmp.readTemperature();
  float bmpPressure = bmp.readPressure();

  // ----------------------------- PID Control -----------------------------
  Input = currentDepth;
  depthPID.Compute();  // Calculates Output
  stepper.moveTo(Output);
  stepper.run();

  // ----------------------------- Data Logging -----------------------------
  unsigned long timestamp = millis();
  String dataString = String(timestamp) + "," + String(lat,6) + "," + String(lng,6) + "," + 
                      String(currentDepth,2) + "," + String(bmpTemp,2) + "," + String(bmpPressure,2) + "," +
                      String(ax) + "," + String(ay) + "," + String(az);

  // Log to SD
  dataFile = SD.open("mission.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println("Logged to SD: " + dataString);
  } else {
    Serial.println("SD logging error.");
  }

  // Send via LoRa
  LoRa.beginPacket();
  LoRa.print(dataString);
  LoRa.endPacket();
  Serial.println("Sent via LoRa: " + dataString);

  delay(1000); // Adjust as needed for real-time performance
}
