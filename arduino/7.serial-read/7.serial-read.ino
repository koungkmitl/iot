char inByte = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("Hello, type something");
}

void loop() {
  if (Serial.available()) {
    inByte = Serial.read();
    Serial.print("> ");
    Serial.println(inByte);
  }
}
