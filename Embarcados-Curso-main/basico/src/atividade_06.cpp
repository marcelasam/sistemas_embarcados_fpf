// Atividade 6: Piscar LED 10 vezes com for e while
// Este exemplo mostra como usar laços de repetição para executar uma tarefa várias vezes.

#include <Arduino.h>

void setup(){
  pinMode(2, OUTPUT); // Configura o pino 2 como saída

  // Usando o laço for para piscar o LED 10 vezes
  for (int i = 0; i < 10; i++){
    digitalWrite(2, HIGH); // Liga o LED
    delay(1000);           // Espera 1 segundo
    digitalWrite(2, LOW);  // Desliga o LED
    delay(1000);           // Espera 1 segundo
  }

  // Usando o laço while para piscar o LED 10 vezes
  int j = 0;
  while(j < 10){
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
    j = j + 1; // Incrementa o contador
  }
}

void loop(){}
