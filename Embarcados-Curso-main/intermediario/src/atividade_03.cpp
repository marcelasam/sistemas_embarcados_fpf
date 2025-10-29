// Atividade: Mapear valor entre escalas
// Este exemplo mostra como converter (mapear) um valor de uma escala para outra.
// Útil para sensores, potenciômetros, etc.

#include <Arduino.h>

const int paraMenor = 0;   // Menor valor da nova escala
const int paraMaior = 500; // Maior valor da nova escala

void setup() {
  Serial.begin(9600);
  Serial.println("Digite dois valores separados por vírgula: menor,maior");
}

void loop() {
  // Aguarda entrada pela serial
  if(Serial.available() > 0){
    String msg = Serial.readStringUntil('\n'); // Lê a linha enviada

    // Separa os valores digitados pelo usuário
    int inicial = msg.indexOf(',');
    String deMenor = msg.substring(0, inicial); // Primeiro valor
    String deMaior = msg.substring(deMenor.length() + 1, msg.length()); // Segundo valor
    int deMaiorInt = deMaior.toInt();
    int deMenorInt = deMenor.toInt();

    // Faz o mapeamento do valor 500 da escala original para a nova escala
    // map(valor, deMenor, deMaior, paraMenor, paraMaior)
    int result = map(500, deMenorInt, deMaiorInt, paraMenor, paraMaior);
    Serial.print("Resultado do mapeamento: ");
    Serial.println(result);
  }
}
