int buzzer = 8;
void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
}
