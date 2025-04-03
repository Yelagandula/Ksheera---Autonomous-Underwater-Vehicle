#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; 

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!bmp.begin(0x76)) { // Try 0x77 if 0x76 fails
    Serial.println("BMP280 sensor not found!");
    while (1);
  }
  Serial.println("BMP280 initialization successful!");
}

void loop() {
  Serial.print("Temperature (°C): ");
  Serial.print(bmp.readTemperature());
  
  Serial.print(" | Pressure (Pa): ");
  Serial.println(bmp.readPressure());

  delay(500);
}
