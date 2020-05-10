#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include "MHZ19.h"
#include <Arduino.h>
#include <SoftwareSerial.h>


#define DHTPIN 4     // Digital pin connected to the DHT sensor 
// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
#define RX_PIN 10
#define TX_PIN 11

RTC_DS3231 rtc;
char t[32];
DHT_Unified dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a
uint32_t delayMS;
//int ledPin = 10;
int movementPin = 9;
byte sensorPin = 3;
int echoPin = 7;
int trigPin = 8;
const int photoResistorPin = A0;
float resistorVoltage;
float ldrVoltage;
float ldrResistance;
float ldrLux;
int val = 0;
int maximumRange = 200;
int minimumRange = 0;
long duration, distance;

// CO2
MHZ19 myMHZ19;   
SoftwareSerial mySerial(RX_PIN, TX_PIN);    

unsigned long getDataTimer = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  myMHZ19.begin(mySerial);   
  myMHZ19.autoCalibration(); 
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("T:"); 
  lcd.setCursor(0,1);
  lcd.print("H:");
  lcd.setCursor(0,2);
  lcd.print("C:");  
  // Initialize device.
  dht.begin(); 
  sensor_t sensor;
  delayMS = sensor.min_delay / 1000;
  //pinMode(ledPin, OUTPUT);
  pinMode(movementPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  pinMode(photoResistorPin, INPUT);
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
  DateTime now = rtc.now();
  delay(1000);
  val = analogRead(photoResistorPin);
  resistorVoltage = (float)val/1023 * 10;
  ldrVoltage = 5 - resistorVoltage;
  ldrResistance = ldrVoltage / resistorVoltage * 5;
  ldrLux = 12518931 * pow(ldrResistance, -1.405);
  byte state = digitalRead(sensorPin);
  String movement;
  int CO2;

  if(millis() - getDataTimer >= 2000) {
    CO2 = myMHZ19.getCO2();     
    getDataTimer = millis();  
  }

  
   
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
    Serial.print(event.temperature,0);
    lcd.setCursor(3, 0);
    lcd.print(event.temperature,0);
    lcd.setCursor(5, 0);
    lcd.print((char)223);
    Serial.print(F("°C\t"));
    dht.humidity().getEvent(&event);
    Serial.print(F("Hum: "));
    Serial.print(event.relative_humidity,0);
    lcd.setCursor(3, 1);
    lcd.print(event.relative_humidity,0);
    lcd.setCursor(5, 1);
    lcd.print(F("%"));
    lcd.setCursor(3, 2);
    lcd.print(CO2);
    Serial.print(F("\tC02: "));
    Serial.print(CO2);
    //lcd.print((int)ldrLux/100);
    lcd.setCursor(0, 3);
    sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());
    lcd.print(t);
//    lcd.setCursor(3, 3);
//    lcd.print("-");
//    lcd.setCursor(4, 3);
//    lcd.print(now.month(), DEC);
    Serial.print(F("%\t"));
    Serial.println(movement);
//    Serial.print(F("\t"));
//    Serial.println(distance);
//    if(event.relative_humidity > 30) {
//      digitalWrite(ledPin, HIGH);
//    } else {
//      digitalWrite(ledPin, LOW);
//    }

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
