#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11

const int DHTPIN = 8;
DHT_Unified dht(DHTPIN, DHTTYPE);

const int relay = 4;

void setup(){
 Serial.begin(9600);
 dht.begin();
 pinMode(relay, OUTPUT);
 delay(500);
 
 Serial.print("**Electropeak**\n\n");
}

void loop(){
   sensors_event_t event;

   dht.humidity().getEvent(&event);
   Serial.print("humidity = ");
   Serial.print(event.relative_humidity);
   Serial.print("%  ");

   dht.temperature().getEvent(&event);
   Serial.print("temperature = ");
   Serial.print(event.temperature); 
   Serial.println("C  ");
   digitalWrite(relay, HIGH);
   delay(1000);
   digitalWrite(relay, LOW);
   delay(3000);
}
