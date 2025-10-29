// Atividade 2: Piscar LED no ESP32
// Este exemplo é igual ao anterior, mas adaptado para o ESP32.
// No ESP32, o LED "built-in" geralmente está no pino 2.

#include <Arduino.h>

void setup() {
  // Configura o pino 2 como saída (OUTPUT) para controlar o LED
  pinMode(2, OUTPUT);

  // Inicializa a comunicação serial. O ESP32 normalmente usa 115200 de baud rate
  Serial.begin(115200);
}

void loop() {
  // Liga o LED (pino 2 em nível alto)
  digitalWrite(2, HIGH);
  Serial.println("Led ligado!");
  delay(1000); // Espera 1 segundo

  // Desliga o LED (pino 2 em nível baixo)
  digitalWrite(2, LOW);
  Serial.println("Led desligado!");
  delay(1000); // Espera 1 segundo
}
