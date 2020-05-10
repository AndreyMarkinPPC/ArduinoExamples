int joyStickX = 0;
int joyStickY = 1; 
int joyStickZ = 3;

void setup() {
  pinMode(joyStickZ, INPUT);
  Serial.begin(9600);
}

void loop() { 
  int x,y,z;

  x = analogRead(joyStickX);
  y = analogRead(joyStickY);
  z = analogRead(joyStickZ);
  Serial.print(x, DEC);
  Serial.print(",");
  Serial.print(y, DEC);
  Serial.print(",");
  Serial.println(z, DEC);
  delay(100);
}
