#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#define placa "ESP32"
DHT dht(DHTPIN, DHTTYPE);
int Gas_analog = 14;
void setup(){
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}
void loop(){
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  int gassensorAnalog = analogRead(Gas_analog);
  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.print(F("°F  "));
  Serial.print("Carbondioxide: ");
  Serial.print(gassensorAnalog);
  Serial.println(" PPM");
  Serial.println();
}
