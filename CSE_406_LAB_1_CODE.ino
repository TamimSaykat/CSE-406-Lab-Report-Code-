// Task 1: DHT Sensor
// Example testing sketch for various DHT humidity/temperature sensors 

#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();     // Celsius
  float f = dht.readTemperature(true); // Fahrenheit

  if (isnan(h) || isnan(t) || isnan(f)) {
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
  Serial.println(F("°F"));
}

// -----------------------------------------------

// Task 2: Arduino LED Blink

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on
  delay(2000);                      // wait for 2 seconds
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
  delay(2000);                      // wait for 2 seconds
}

// -----------------------------------------------

// Task 3: Water Sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  int sensor = analogRead(A0); // Incoming analog signal read
  Serial.println(sensor);
}
