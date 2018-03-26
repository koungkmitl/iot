int buttonState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  /*
   * not press is LOW
   * press is HIGH
   */
  
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}
