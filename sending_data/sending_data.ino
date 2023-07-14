#include <WiFiNINA.h>
#include <ThingSpeak.h>

#define WIFI_SSID "Personal"  // moja wi-fi mreža
#define WIFI_PASS "12345678"

#define INTERVAL_SLANJA 1000  // in milliseconds 15000 = 15
#define INTERVAL_ISPISA 500  // in milliseconds 15000 = 15

#define SUM_MAX 40
#define NORMLANO_DISANJE 40    // threshold + - vrijednost senzora / ŠUM 
#define DEFAULT_VALUE 816

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
int previousValue = -1; // previous sensor value
int sensorValue = 0;

WiFiClient client;
unsigned long channelID = 2092782; // channel ID
const char * writeAPIKey = "N4AOAPENQQ43SF00"; //  API key

void setup() {
  Serial.begin(9600);
  while (!Serial);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  ThingSpeak.begin(client);
}

void loop() {
  unsigned long currentMillis = millis();
  int sensorValue = analogRead(A0);

  // vrijednosti izvan normalnog intervala - puno veća promijena
  if((abs(sensorValue - previousValue) > NORMLANO_DISANJE))
  {
    ThingSpeak.writeField(channelID, 1, sensorValue, writeAPIKey);
    Serial.print("Podatak se promijenio i šaljem ga : ");
    Serial.println(sensorValue);
    previousValue = sensorValue;
  }

  // slanje trenutnog podatka svakih 2 sec
  if (currentMillis - previousMillis1 >= INTERVAL_SLANJA)
  {
    Serial.print("Prošla je 1s, šaljem podatak : ");
    Serial.println(sensorValue);
    ThingSpeak.writeField(channelID, 1, sensorValue, writeAPIKey);
    previousMillis1 = currentMillis;
  }

  // ispis podataka svakih 1 sec 
  if (currentMillis - previousMillis2 >= INTERVAL_ISPISA)
  {
    Serial.print("Prošlo je 0.5s, ispisujem podatak : ");
    Serial.println(sensorValue);
    previousMillis2 = currentMillis;
    
  }
  


}








