// Atividade: Piscar LED 5 vezes e dormir (ESP32)
// Exemplo de uso do laço do-while e do modo deep sleep do ESP32 para economia de energia.

#include <Arduino.h>

void setup() {
  int i = 0;
  // Pisca o LED 5 vezes usando do-while
  do{
    digitalWrite(2, HIGH); // Liga o LED
    delay(1000);           // Espera 1 segundo
    digitalWrite(2, LOW);  // Desliga o LED
    delay(1000);           // Espera 1 segundo
    i++;
  }while(i < 5);

  // Coloca o ESP32 em deep sleep por 10 segundos (10 milhões de microssegundos)
  esp_deep_sleep(10 * 1000000);
}

void loop() {}
