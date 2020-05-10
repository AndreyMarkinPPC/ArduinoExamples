int a = 7;
int b = 6;
int c = 5;
int d = 10;
int e = 11;
int f = 8;
int g = 9;
int dp = 4;

void digital_0(void) {
  unsigned char j;
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}

void digital_1(void) {
  unsigned char j;
  digitalWrite(c, HIGH);
  digitalWrite(b, HIGH);
  for (j = 7; j <= 11; j++) {
    digitalWrite(j, LOW);
    digitalWrite(dp, LOW);
  }
}


void digital_(void) {
  unsigned char j;
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);
}

void setup() {
  int i;
  for(i = 4; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  while(1) {
    digital_0();
    delay(500);
    digital_1();
    delay(500);
    digital_();
    delay(1500);
  }
}
