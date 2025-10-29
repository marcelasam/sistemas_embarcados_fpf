// Atividade: Piscar LED 5 vezes e dormir, com verificação do motivo do wakeup (ESP32)
// Exemplo de uso do deep sleep do ESP32 e verificação do motivo do "acordo" (wakeup).

#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);      // Configura o pino 2 como saída
  Serial.begin(115200);    // Inicializa a comunicação serial

  // Verifica o motivo pelo qual o ESP32 acordou do deep sleep
  esp_sleep_wakeup_cause_t reason = esp_sleep_get_wakeup_cause();

  if (reason == ESP_SLEEP_WAKEUP_TIMER){
    // Se acordou pelo timer, pisca o LED 5 vezes
    int i = 0;
    do{
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);
      delay(1000);
      i++;
    }while(i < 5);
  }
  else if(reason == ESP_SLEEP_WAKEUP_EXT0){
    // Se acordou por um pino externo
    Serial.println("Acordou pelo pino exteno");
  }
  else{
    // Outros motivos
    Serial.println("Acordou por outro motivo...");
  }

  // Volta para o deep sleep por 10 segundos
  esp_deep_sleep(10 * 1000000);
}

void loop() {}
