// Atividade: Comunicação serial com JSON (ArduinoJson)
// Este exemplo mostra como receber e enviar dados em formato JSON pela serial.
// O formato JSON é muito usado em IoT e integrações modernas.

#include <Arduino.h>
#include <ArduinoJson.h> // Biblioteca para manipular JSON

JsonDocument doc; // Objeto para armazenar dados JSON

void setup(){
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(2, OUTPUT);   // Configura o pino 2 como saída
}

void loop(){
  // Se receber algo pela serial
  if(Serial.available() > 0){
    String msg = Serial.readStringUntil('\n'); // Lê a mensagem até o Enter

    // Converte a string recebida em um objeto JSON
    deserializeJson(doc, msg);

    // Lê o valor do campo "led_state" do JSON
    bool led_state = doc["led_state"];
    digitalWrite(2, led_state); // Atualiza o LED conforme o valor recebido

    // Prepara uma resposta JSON com o estado atual do LED
    doc.clear();
    doc["led_state"] = led_state;
    String response;
    serializeJson(doc, response); // Converte o objeto JSON em string
    Serial.println(response);     // Envia a resposta pela serial
  }
}
