int sensorValue;
void setup() {
 pinMode(0,OUTPUT);
}

void loop() {
  sensorValue = analogRead(A0);
  digitalWrite(0,HIGH);
  delay(sensorValue);
  digitalWrite(0,LOW);
  delay(sensorValue);

}
