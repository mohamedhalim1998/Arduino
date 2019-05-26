void setup() {
  pinMode(A0, INPUT);
  pinMode(0, OUTPUT);
}

void loop() {
  int temp = (analogRead(A0) * 5.0 / 1023) * 100.0;
  //digitalWrite(0, HIGH);
  if (temp >= 30)
    digitalWrite(0, LOW);
  else
    digitalWrite(0, HIGH);

}
