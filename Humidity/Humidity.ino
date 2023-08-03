#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 7;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
}

void loop() {
  // wait a few seconds between measurements.
  delay(9000);

  // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();

  if(humi > 40) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // check if any reads failed
  if ((isnan(humi) || isnan(tempC))) 
  {
    Serial.println("Failed to read from DHT sensor!");
  }
    
  else 
  {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println("°C ~ ");
  }  
}