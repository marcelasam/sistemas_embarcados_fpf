// Atividade 3: Leitura serial e operações básicas
// Este exemplo mostra como ler dados enviados pelo computador para a placa via serial
// e realizar operações simples com esse dado.

#include <Arduino.h>

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps
}

void loop() {
  // Verifica se há dados disponíveis na serial
  if(Serial.available() > 0){
    int dado = Serial.read(); // Lê um byte da serial (um caractere ou número)

    // Soma 5 ao valor lido e imprime o resultado na serial
    Serial.println(dado + 5);

    // Multiplica o valor lido por 200 e imprime o resultado
    Serial.println(dado * 200);

    // Se o valor lido for maior que 5, imprime uma mensagem
    if (dado > 5){
      Serial.println("Maior que 5!");
    }

    // Exemplo de laço: imprime os números de 0 a 3
    for(int i = 0; i < 4; i++){
      Serial.println(i);
    }
  }
}
