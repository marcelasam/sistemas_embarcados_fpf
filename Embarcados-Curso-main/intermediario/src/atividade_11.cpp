// Atividade: Exemplo de uso de timer e interrupção (Arduino UNO)
// Este exemplo mostra como usar o timer interno do Arduino para piscar o LED sem usar delay.
// O timer gera uma interrupção periódica, que alterna o estado do LED.

#include<Arduino.h>

volatile bool ledState = false; // Estado do LED controlado pela interrupção

// Função chamada automaticamente quando o timer atinge o valor configurado
ISR(TIMER1_COMPA_vect) {
  ledState = !ledState; // Inverte o estado do LED
  digitalWrite(LED_BUILTIN, ledState); // Atualiza o LED
}

// Configura o timer para gerar interrupções em uma frequência desejada
void parallelBlink(int s){
  noInterrupts();           // Desabilita interrupções durante a configuração
  TCCR1A = 0;              // Zera registradores de controle
  TCCR1B = 0;
  TCNT1 = 0;               // Zera o contador
  OCR1A = 15624 / s;       // Define o valor de comparação para a frequência desejada
  TCCR1B |= (1 << WGM12);  // Modo CTC (Clear Timer on Compare Match)
  TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler de 1024
  TIMSK1 |= (1 << OCIE1A); // Habilita a interrupção do timer
  interrupts();             // Habilita interrupções novamente
}

void setup() {
  Serial.begin(9600);              // Inicializa a comunicação serial
  pinMode(LED_BUILTIN, OUTPUT);    // Configura o LED da placa como saída
  digitalWrite(LED_BUILTIN, LOW);  // Garante que o LED comece desligado
  parallelBlink(2);                // Configura o timer para piscar o LED a cada 0,5s (2 Hz)
}

void loop() {
  Serial.println("Rodando...");
  delay(500); // Apenas para mostrar que o loop continua rodando normalmente
}
