#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check wiring.");
    delay(1000);
  }
  Serial.println("LoRa init successful.");
}

void loop() {
  String payload = String(gps.location.lat(),6) + "," + String(gps.location.lng(),6) + "," + String(depthSensor.depth());
  LoRa.beginPacket();
  LoRa.print(payload);
  LoRa.endPacket();

  Serial.println("Data sent via LoRa: " + payload);
  delay(2000);
}
