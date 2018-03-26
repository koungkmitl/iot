int val;

void setup() {
  pinMode(D0, OUTPUT);
}

void loop() {
  val = analogRead(A0);
  analogWrite(D0, val);
}
