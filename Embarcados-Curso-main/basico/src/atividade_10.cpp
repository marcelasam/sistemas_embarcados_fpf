// Atividade 10: Controle de LED pela serial (switch case)
// Exemplo de uso do comando switch para tomar decisões com base em dados recebidos pela serial.

#include <Arduino.h>

void setup(){
    Serial.begin(115200); // Inicializa a comunicação serial
    pinMode(2, OUTPUT);   // Configura o pino 2 como saída
}

void loop(){
    // Se receber um valor pela serial, executa o comando correspondente
    if (Serial.available() > 0){
        uint8_t msg = Serial.read(); // Lê um byte
        switch (msg) {
            case 0: {
                digitalWrite(2, LOW); // Desliga o LED se receber 0
                break;
            }
            case 1: {
                digitalWrite(2, HIGH); // Liga o LED se receber 1
                break;
            }
            default: {
                // Para outros valores, não faz nada
                break;
            }
        }
    }
    delay(10); // Pequeno atraso para evitar sobrecarga
}
