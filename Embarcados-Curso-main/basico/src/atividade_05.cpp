// Atividade 5: Piscar LED com tempo em variável
// Agora, o tempo que o LED fica ligado/desligado é controlado por uma variável.

#include <Arduino.h>

uint32_t t = 1000; // Variável que armazena o tempo em milissegundos (1 segundo)

void setup() {
  pinMode(2, OUTPUT); // Configura o pino 2 como saída
}

void loop() {
  digitalWrite(2, HIGH); // Liga o LED
  delay(t);              // Espera o tempo definido em t
  digitalWrite(2, LOW);  // Desliga o LED
  delay(t);              // Espera o tempo definido em t
}
