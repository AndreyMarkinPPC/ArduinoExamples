byte sensorPin = 3;
byte indicator = 13; 

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(indicator, OUTPUT);
  Serial.begin(9600);
}

void loop() { 
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator, state);
  if(state == 1) {
    Serial.println("Somebody in the area");
  } else {
    Serial.println("No one here");
  }
  delay(50);
}
