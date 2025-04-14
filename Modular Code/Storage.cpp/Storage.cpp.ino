#include "Storage.h"
#include <SD.h>

#define SD_CS_PIN 53
File dataFile;

void initStorage() {
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
}

void logToSD(const String& data) {
  dataFile = SD.open("mission.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println(data);
    dataFile.close();
    Serial.println("Logged to SD: " + data);
  } else {
    Serial.println("SD logging error.");
  }
}
