// Atividade 7: Escrever frase na serial 10 vezes (for e while)
// Exemplo de uso de laços para escrever mensagens na serial repetidamente.

#include <Arduino.h>

void setup(){
  Serial.begin(115200); // Inicializa a comunicação serial

  // Usando for para escrever 10 vezes
  for (int i = 0; i < 10; i++){
    Serial.print("Esta é uma frase!");
    delay(1000); // Espera 1 segundo entre as mensagens
  }

  // Usando while para escrever 10 vezes
  int i = 0;
  while(i < 10){
    Serial.print("Esta é uma frase!");
    i = i + 1;
  }
}

void loop(){}
