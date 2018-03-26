void setup() {
  pinMode(D1, INPUT);
  pinMode(D0, OUTPUT);
}

void loop() {
  if (!digitalRead(D1)) {
    digitalWrite(D0, HIGH);
  } else {
    digitalWrite(D0, LOW);
  }
}
