// Atividade: Média de 5 números lidos da serial
// Este exemplo mostra como ler vários números enviados pelo usuário e calcular a média.
// Introduz o conceito de acumulador e uso de variáveis para controle de fluxo.

#include <Arduino.h>

int i = 1;    // Variável para contar quantos números já foram lidos
int acm = 0;  // Acumulador para somar os valores recebidos

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  // Solicita ao usuário digitar um número
  Serial.print("Digite o número ");
  Serial.print(i);
  Serial.println(": ");

  // Espera até que o usuário envie algo pela serial
  while(Serial.available() == 0);

  // Lê o número enviado, converte para inteiro e soma ao acumulador
  acm = acm + Serial.readStringUntil('\n').toInt();

  // Quando já leu 5 números, calcula e mostra a média
  if (i == 5){
    i = 1; // Reinicia o contador
    Serial.print("Média: ");
    Serial.println(acm / 5); // Mostra a média
    acm = 0; // Zera o acumulador para próxima rodada
  } else {
    i++; // Vai para o próximo número
  }

  delay(10); // Pequeno atraso para estabilidade
}
