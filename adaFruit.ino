#include "AdafruitIO_WiFi.h"
#include <DHT.h>

// ========= ADAFRUIT ========
#define IO_USERNAME "GuilhermeMoreira"
#define IO_KEY "ADICIONAR IOKEY"

// ========= WiFi ============
#define WIFI_SSID "guilhermeTeste"
#define WIFI_PASS "maracuja"

// ======== DHT11 ==========
#define DHTPIN 4     // pino DATA do DHT11 ligado ao GPIO04
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ======= CONEXÃO ADAFRUIT ======
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

// ====== FEEDS ===========
AdafruitIO_Feed *temperatura = io.feed("temperatura");
AdafruitIO_Feed *umidade = io.feed("umidade");

// ====== VARIÁVEIS ==========
float ultimaTemp = -1000;
float ultimaUmidade = -1000;

void setup() {
  Serial.begin(115200);
  delay(1000);

  dht.begin();

  Serial.print("iniciando conexão com AdaFruit IO...");
  io.connect();

 // Loop com diagnóstico
  while (io.status() < AIO_CONNECTED) {
    Serial.print("Status: ");
    Serial.println(io.statusText());
    delay(1000);
  }

  Serial.println("Conectado ao AdaFruit IO!");
}

void loop() {
  io.run();


  // verifica conexão continuamente
  if(io.status() != AIO_CONNECTED) {
    Serial.print("Desconectado: ");
    Serial.println(io.statusText());
    return;
  }

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if(isnan(temp) || isnan(hum)) {
    Serial.println("Erro ao ler o DHT11");
    delay(2000);
    return;
  }

  if (abs(temp - ultimaTemp) >= 0.2) {
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");

    temperatura->save(temp);
    ultimaTemp = temp;
  }

  if (abs(hum - ultimaUmidade) >= 1.0) {
    Serial.print("Umídade: ");
    Serial.print(hum);
    Serial.println(" %");

    umidade->save(hum);
    ultimaUmidade = hum;
  }

  delay(3000);
}