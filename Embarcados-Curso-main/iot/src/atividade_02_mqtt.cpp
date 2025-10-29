// Atividade: Exemplo simples de comunicação MQTT com ESP32
// Este exemplo publica e assina mensagens em um broker MQTT público.
// Requer a biblioteca PubSubClient (adicione em lib_deps do platformio.ini)

#include <WiFi.h>
#include <PubSubClient.h>

// Defina seu WiFi
const char* ssid = "SEU_WIFI";
const char* password = "SUA_SENHA";

// Broker MQTT público (exemplo: broker.hivemq.com)
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando em ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado!");
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida em ");
  Serial.print(topic);
  Serial.print(": ");
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("conectado!");
      client.subscribe("curso/embarcados/teste");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Publica uma mensagem a cada 10 segundos
  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 10000) {
    lastMsg = millis();
    String msg = "Ola do ESP32!";
    client.publish("curso/embarcados/teste", msg.c_str());
    Serial.println("Mensagem publicada: " + msg);
  }
}
