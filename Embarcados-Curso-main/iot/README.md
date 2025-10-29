## Módulo IoT

Este módulo é dedicado a exemplos de Internet das Coisas (IoT), mostrando como comunicar dados estruturados entre dispositivos e computadores.

### Exemplo 1: Comunicação Serial com JSON

O código `atividade_01.cpp` mostra como receber e enviar dados em formato JSON pela serial, usando a biblioteca ArduinoJson. Esse formato é muito usado em IoT para integração com sistemas, apps e nuvem.

#### Como testar:
1. Abra a pasta `iot` no VS Code com PlatformIO.
2. Compile e envie o código para sua placa (ESP32 ou Arduino compatível).
3. Abra o monitor serial e envie uma mensagem JSON, por exemplo:
	```json
	{"led_state": true}
	```
	O LED irá ligar/desligar conforme o valor enviado, e a placa responderá com o mesmo JSON.

---

### Exemplo 2: Comunicação MQTT com ESP32

O código `atividade_02_mqtt.cpp` mostra como conectar o ESP32 a uma rede WiFi e a um broker MQTT público, publicar mensagens e receber comandos.

#### Como testar:
1. No arquivo, altere as linhas `const char* ssid = "SEU_WIFI";` e `const char* password = "SUA_SENHA";` para os dados da sua rede WiFi.
2. No `platformio.ini`, adicione a dependência:
	```ini
	lib_deps =
	  knolleary/PubSubClient
	```
3. Compile e envie para o ESP32.
4. Use o [MQTTX](https://mqttx.app/) ou outro cliente MQTT para publicar e assinar o tópico `curso/embarcados/teste` no broker `broker.hivemq.com`.
5. Veja as mensagens chegando e envie comandos para o ESP32!

---

#### Dica:
Você pode usar ferramentas como [MQTTX](https://mqttx.app/) ou [Insomnia](https://insomnia.rest/download) para simular integrações IoT mais avançadas.
