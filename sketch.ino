#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define PIR_PIN 14
#define DHTPIN 15
#define DHTTYPE DHT22
#define BUTTON_PIN 4

DHT dht(DHTPIN, DHTTYPE);

bool treinoAtivo = false;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Erro ao iniciar OLED"));
    for(;;);
  }
  display.clearDisplay();
}

void loop() {
  int presenca = digitalRead(PIR_PIN);
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (digitalRead(BUTTON_PIN) == LOW) {
    treinoAtivo = !treinoAtivo;
    delay(500); // debounce
  }

  String statusQuadra = (presenca == HIGH || treinoAtivo) ? "ocupada" : "livre";

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Quadra: ");
  display.println(statusQuadra);
  display.print("Temp: ");
  display.print(temperatura);
  display.println(" C");
  display.print("Umid: ");
  display.print(umidade);
  display.println(" %");
  display.display();

  Serial.print("{\"quadra\":\"Quadra01\",\"status\":\"");
  Serial.print(statusQuadra);
  Serial.print("\",\"temperatura\":");
  Serial.print(temperatura);
  Serial.print(",\"umidade\":");
  Serial.print(umidade);
  Serial.print(",\"presenca\":");
  Serial.print(presenca);
  Serial.print(",\"treinoAtivo\":");
  Serial.print(treinoAtivo ? 1 : 0);
  Serial.println("}");

  delay(3000);
}
