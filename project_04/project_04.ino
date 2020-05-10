int redled=10;
int yellowled=7;
int greenled=4;

void setup() {
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
}

void loop() {
  digitalWrite(greenled, HIGH);
  delay(5000);

  digitalWrite(greenled, LOW);
  for(int i=0; i < 3; i++) {
    delay(500);
    digitalWrite(yellowled, HIGH);
    delay(500);
    digitalWrite(yellowled, LOW);  
  }
  delay(500);
  digitalWrite(redled, HIGH);
  delay(5000);
  digitalWrite(redled, LOW);
}
