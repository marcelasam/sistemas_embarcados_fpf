// Atividade: Piscar LED com millis() e alternância de estado
// Este exemplo mostra como usar millis() para criar temporizações sem travar o programa (sem delay).
// Isso permite que o microcontrolador execute outras tarefas enquanto espera.

#include <Arduino.h>

unsigned long t_inicial = millis(); // Armazena o tempo da última mudança de estado
bool state = false;                 // Estado atual do LED (ligado/desligado)

void setup(){
  pinMode(2, OUTPUT); // Configura o pino 2 como saída
}

void loop(){
  // millis() retorna o tempo (em ms) desde que a placa foi ligada
  // Aqui, verificamos se já passou 1 segundo desde a última troca
  if (abs(int(millis()) - int(t_inicial)) >= 1000){
    state = !state; // Inverte o estado do LED
    digitalWrite(2, state); // Atualiza o LED
    t_inicial = millis();   // Atualiza o tempo da última troca
  }
}
// Dica: abs() retorna o valor absoluto (positivo) da diferença
