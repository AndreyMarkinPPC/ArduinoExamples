int echoPin = 7;
int trigPin = 8;
int ledPin = LED_BUILTIN;
int maximumRange = 10;
int minimumRange = 0;
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;

  if(distance < maximumRange) { 
    Serial.println(distance);
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println(distance);
    digitalWrite(ledPin, LOW);
  }
  delay(5);
  
}
