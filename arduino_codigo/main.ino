#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11

const int DHTPIN = 8;
DHT_Unified dht(DHTPIN, DHTTYPE);

const int RELAY = 4;

float deltaK = 10;
float i = 0;
float k = 0;
float alto = -deltaK * 0.3;
float bajo = deltaK * 0.3;
bool relayEstado = false;

void setup(){
 Serial.begin(9600);
 dht.begin();
 pinMode(RELAY, OUTPUT);
 delay(500);
 digitalWrite(RELAY, LOW);
 
 Serial.print("**Electropeak**\n\n");
}

void loop(){
   float humedad;
   float temperatura;
   if (i >= deltaK) {
    relayEstado = true;
    Serial.println("on");
    i = 0;
   }
   if (k >= deltaK){
    relayEstado = false;
     Serial.println("off");
     k = 0;
   }
    digitalWrite(RELAY, relayEstado);
   
   sensors_event_t event;

   dht.humidity().getEvent(&event);
   humedad = event.relative_humidity;
   Serial.print("humidity = ");
   Serial.print(humedad);
   Serial.print("%  ");

   dht.temperature().getEvent(&event);
   temperatura = event.temperature;
   Serial.print("temperature = ");
   Serial.print(temperatura); 
   Serial.println("C  ");

   if (temperatura >= 17 && temperatura <= 25) {   
    if (humedad >= 50 && humedad <= 60) {
        deltaK = 10;
      } 
   }
   if (temperatura > 25 && humedad > 60) {
      deltaK = 10;
      deltaK = deltaK + alto;
   }
   if (temperatura < 17) {
     deltaK = 10;
     deltaK = deltaK + bajo;
   }
    if (digitalRead(RELAY) == 0) {
        Serial.println(i);
        i = i + 1;

    }
    if (digitalRead(RELAY) == 1) {
        Serial.println(k);
        k = k + 1;
      }
     delay(1000);
}
