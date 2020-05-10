#include<Stepper.h>
#define STEPS 300

Stepper stepper(STEPS, 8,9,10,11);
int previous = 0;

void setup() {
  stepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(0);
  Serial.println(val);
  stepper.step(val - previous);
  previous = val;
}
