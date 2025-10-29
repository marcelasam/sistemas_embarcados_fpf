// Atividade 1: Piscar LED no Arduino UNO
// Este é o exemplo mais clássico para começar a aprender programação embarcada:
// Vamos acender e apagar o LED da placa de forma automática.

#include <Arduino.h> // Inclui a biblioteca principal do Arduino

// A função setup() é executada uma única vez quando a placa é ligada ou reiniciada
void setup() {
  // pinMode configura o modo de funcionamento de um pino
  // Aqui, estamos dizendo que o pino 13 será uma saída (OUTPUT)
  pinMode(13, OUTPUT);

  // Serial.begin inicializa a comunicação serial com o computador
  // O número 9600 é a velocidade de comunicação (baud rate)
  Serial.begin(9600);
}

// A função loop() roda repetidamente, em um ciclo infinito
void loop() {
  // digitalWrite envia um valor (HIGH ou LOW) para um pino
  // HIGH = 5V (liga o LED), LOW = 0V (desliga o LED)
  digitalWrite(13, HIGH); // Liga o LED
  Serial.println("Led ligado!"); // Escreve mensagem no monitor serial

  // delay faz o programa "esperar" pelo tempo indicado em milissegundos (1000 ms = 1 segundo)
  delay(1000); // Espera 1 segundo

  digitalWrite(13, LOW); // Desliga o LED
  Serial.println("Led desligado!");
  delay(1000); // Espera 1 segundo
}
