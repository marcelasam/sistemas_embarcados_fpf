// Atividade: Média de N números lidos da serial, usando vector
// Este exemplo mostra como armazenar vários números em um vetor dinâmico (vector)
// e calcular a média quando o usuário desejar.

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>
#include <iostream>

std::vector<int> numbers; // Vetor dinâmico para armazenar os números

void setup() {
    Serial.begin(9600); 
    Serial.println("Digite números inteiros. Digite -1 para calcular a média.");
}

void loop() {
    // Se receber algo pela serial
    if (Serial.available() > 0) { 
        String input = Serial.readStringUntil('\n'); // Lê a linha enviada
        input.trim(); 
        int number = input.toInt(); // Converte para inteiro

        // Se o usuário digitar -1, calcula a média dos números já recebidos
        if (number == -1) {
            if (!numbers.empty()) { 
                int sum = 0;
                // Soma todos os números do vetor
                for (int n : numbers) {
                    sum += n;
                }
                // Calcula a média (float para permitir casas decimais)
                float average = (float)sum / numbers.size(); 
                Serial.print("Média dos números: ");
                Serial.println(average);
            } else {
                Serial.println("Nenhum número foi inserido.");
            }
            numbers.clear(); // Limpa o vetor para nova rodada
        } else {
            // Se não for -1, adiciona o número ao vetor
            numbers.push_back(number); 
            Serial.print("Número adicionado: ");
            Serial.println(number);
        }
    }
}
