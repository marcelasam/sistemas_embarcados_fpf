// Atividade 4: Leitura serial e impressão em hexadecimal
// Este exemplo mostra como ler um caractere enviado pela serial e imprimir seu valor em hexadecimal.

#include <Arduino.h>

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(LED_BUILTIN, OUTPUT); // Configura o LED da placa como saída
}

void loop() {
  // Se receber algo pela serial
  if(Serial.available() > 0){
    char msg = Serial.read(); // Lê um caractere
    Serial.println(msg, HEX); // Imprime o valor do caractere em hexadecimal
  }
}
