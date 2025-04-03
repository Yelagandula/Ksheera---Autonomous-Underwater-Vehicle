#include <SPI.h>
#include <SD.h>

File dataFile;

void setup() {
  Serial.begin(9600);
  if (!SD.begin(53)) {
    Serial.println("SD Card initialization failed!");
    return;
  }
  Serial.println("SD Card initialized.");

  dataFile = SD.open("log.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println("Timestamp,Latitude,Longitude,Depth,Temp,Pressure,AccelX,AccelY,AccelZ");
    dataFile.close();
  }
}

void loop() {
  dataFile = SD.open("log.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.print(millis()); dataFile.print(",");
    dataFile.print(gps.location.lat(), 6); dataFile.print(",");
    dataFile.print(gps.location.lng(), 6); dataFile.print(",");
    dataFile.print(depthSensor.depth()); dataFile.print(",");
    dataFile.print(bmp.readTemperature()); dataFile.print(",");
    dataFile.print(bmp.readPressure()); dataFile.print(",");
    dataFile.print(ax); dataFile.print(",");
    dataFile.print(ay); dataFile.print(",");
    dataFile.println(az);

    dataFile.close();
  }
  delay(1000);
}
