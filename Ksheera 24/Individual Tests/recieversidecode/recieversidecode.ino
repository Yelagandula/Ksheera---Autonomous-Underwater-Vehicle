#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  LoRa.setPins(SS, RST, DIO0); // Adjust pins accordingly
  LoRa.begin(433E6);
  Serial.println("LoRa Receiver ready.");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = "";
    while (LoRa.available()) {
      received += (char)LoRa.read();
    }
    Serial.println("Received: " + received);

    // Forward data to cloud (e.g., via cellular/Wi-Fi)
    // Add your cloud transmission code here (HTTP/MQTT)
  }
}
