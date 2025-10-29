// Atividade: Controle de LED por comandos ON/OFF via serial
// Este exemplo mostra como controlar o LED da placa enviando comandos de texto pela serial.
// O usuário pode digitar "ON" para ligar o LED e "OFF" para desligar.

#include <Arduino.h>

void setup(){
  pinMode(2, OUTPUT);      // Configura o pino 2 como saída
  Serial.begin(115200);    // Inicializa a comunicação serial
}

void loop(){
  // Se receber algo pela serial
  if (Serial.available() > 0){
    String msg = Serial.readStringUntil('\n'); // Lê a mensagem até o Enter
    Serial.println(msg); // Ecoa a mensagem recebida
    msg.trim();          // Remove espaços em branco
    msg.toUpperCase();   // Converte para maiúsculas

    // Se o comando for "ON", liga o LED
    if (msg == "ON"){
      digitalWrite(2, HIGH);
    }
    // Se o comando for "OFF", desliga o LED
    else if(msg == "OFF"){
      digitalWrite(2, LOW);
    }
  }
}
