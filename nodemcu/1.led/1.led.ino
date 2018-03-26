void setup() {
  pinMode(D1, OUTPUT);
}

void loop() {
  for(int i=0; i<1024; i+=50) {
    analogWrite(D1, i);
    delay(100);
  }
}
