void setup() {
  
}

void loop() {
  // analogWrite using at PWM port
  for(int i=0; i<=255; i+=5) {
    analogWrite(11, i);
    delay(30);
  }
}
