void setup() {
Serial.begin(9600);
}

void loop() {
int x = analogRead(0);
Serial.println(x);
}
