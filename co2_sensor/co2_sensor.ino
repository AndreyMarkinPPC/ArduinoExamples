#include <Wire.h>
#include "MHZ19.h"
#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
  
#define RX_PIN 10
#define TX_PIN 11
#define DHTPIN 4
#define DHTTYPE DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

// CO2
MHZ19 myMHZ19;   
SoftwareSerial mySerial(RX_PIN, TX_PIN);    

unsigned long getDataTimer = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  mySerial.begin(9600);
  myMHZ19.begin(mySerial);   
  myMHZ19.autoCalibration(); 
}

void loop() {
  int CO2;
  sensors_event_t event;
  
  if(millis() - getDataTimer >= 2000) {
    CO2 = myMHZ19.getCO2();     
    getDataTimer = millis();  
  }
    Serial.print(CO2);
    Serial.print(F(","));
    // get temperature
    dht.temperature().getEvent(&event);
    Serial.print(event.temperature,2);
    Serial.print(F(","));
    //get humidity
    dht.humidity().getEvent(&event);
    Serial.println(event.relative_humidity,2);
    delay(60000);
  
}
