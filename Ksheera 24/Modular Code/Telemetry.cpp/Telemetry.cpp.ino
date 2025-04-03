#include "Telemetry.h"
#include <LoRa.h>

#define LORA_CS 48
#define LORA_RST 47
#define LORA_IRQ 2

void initTelemetry() {
  LoRa.setPins(LORA_CS, LORA_RST, LORA_IRQ);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed!");
  } else {
    Serial.println("LoRa initialized.");
  }
}

void sendTelemetry(const String& data) {
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();
  Serial.println("Sent via LoRa: " + data);
}
