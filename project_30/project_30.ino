#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

#define DHTPIN 4     // Digital pin connected to the DHT sensor 
// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 13, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

uint32_t delayMS;
int ledPin = 10;
int movementPin = 9;
byte sensorPin = 3;
int echoPin = 7;
int trigPin = 8;
int maximumRange = 200;
int minimumRange = 0;
long duration, distance;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Initialize device.
  dht.begin(); 
  sensor_t sensor;
  delayMS = sensor.min_delay / 1000;
  pinMode(ledPin, OUTPUT);
  pinMode(movementPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Hello");
}

void loop() {
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
//
//  distance = duration/58.2;
  // Delay between measurements.
  delay(100);
  byte state = digitalRead(sensorPin);
  String movement;
  if(state == 1) {
    movement = "Movement";
  } else {
    movement = "No movement";
  }
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temp: "));
    Serial.print(event.temperature);
    Serial.print(F("°C\t"));
    dht.humidity().getEvent(&event);
    Serial.print(F("Hum: "));
    Serial.print(event.relative_humidity);
    Serial.print(F("%\t"));
    Serial.println(movement);
//    Serial.print(F("\t"));
//    Serial.println(distance);
    if(event.relative_humidity > 30) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }

    if(state == 1) {
      digitalWrite(movementPin, HIGH);
    } else {
      digitalWrite(movementPin, LOW);
    }
  }
  
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
//    Serial.print(F("Humidity: "));
//    Serial.print(event.relative_humidity);
//    Serial.println(F("%"));
  }
}
