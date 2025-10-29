// Atividade 9: Ecoar metade da mensagem recebida na serial
// Este exemplo mostra como manipular strings recebidas pela serial.
// O programa lê uma mensagem e devolve apenas a metade dela.

#include <Arduino.h>

void setup(){
  Serial.begin(115200); // Inicializa a comunicação serial
}

void loop(){
  if(Serial.available() > 0){
    String msg = Serial.readStringUntil('\n'); // Lê a mensagem até o Enter
    // Pega apenas a metade da mensagem recebida
    String new_msg = msg.substring(0, msg.length() / 2);
    Serial.println(new_msg); // Envia a metade de volta
  }
  delay(10); // Pequeno atraso para evitar sobrecarga
}
