#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11

const int DHTPIN = 8;
DHT_Unified dht(DHTPIN, DHTTYPE);

void setup(){
 Serial.begin(9600);
 dht.begin();
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
   delay(3000);
}
