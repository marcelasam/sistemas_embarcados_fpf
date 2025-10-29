// Atividade: Exemplo de uso de interrupção com botão (Arduino UNO)
// Este exemplo mostra como usar interrupções externas para reagir a eventos (botão pressionado).
// Quando o botão no pino 3 é pressionado, o LED no pino 5 muda de estado.

#include<Arduino.h>

volatile bool ledState = false; // Variável que armazena o estado do LED (precisa ser volatile em interrupções)

// Função chamada automaticamente quando ocorre a interrupção
void interruptFunction(){
  ledState = !ledState;         // Inverte o estado do LED
  digitalWrite(5, ledState);    // Atualiza o LED no pino 5
}

void setup(){
  Serial.begin(9600);           // Inicializa a comunicação serial
  pinMode(3, INPUT_PULLUP);     // Configura o pino 3 como entrada com pull-up interno (botão)
  pinMode(5, OUTPUT);           // LED controlado pela interrupção
  pinMode(13, OUTPUT);          // LED para piscar normalmente
  // Configura a interrupção: quando o pino 3 mudar de estado, chama interruptFunction
  attachInterrupt(digitalPinToInterrupt(3), interruptFunction, CHANGE);
}

void loop(){
  // Pisca o LED do pino 13 normalmente
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
