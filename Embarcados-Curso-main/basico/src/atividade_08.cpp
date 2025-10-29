// Atividade 8: Piscar LED com controle de tempo pela serial
// Agora, o tempo do delay pode ser alterado enviando um valor pela serial.

#include <Arduino.h>

int time_ms = 1000; // Tempo padrão em milissegundos

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(2, OUTPUT);   // Configura o pino 2 como saída
}

void loop() {
  // Se receber um valor pela serial, atualiza o tempo do delay
  if(Serial.available() > 0){
    String msg = Serial.readStringUntil('\n'); // Lê a mensagem até o Enter
    time_ms = msg.toInt(); // Converte a mensagem para inteiro
  }

  digitalWrite(2, HIGH); // Liga o LED
  delay(time_ms);        // Espera o tempo definido
  digitalWrite(2, LOW);  // Desliga o LED
  delay(time_ms);        // Espera o tempo definido
}
