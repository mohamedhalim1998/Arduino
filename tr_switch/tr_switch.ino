void setup() {
  pinMode(0,OUTPUT);
  pinMode(1,INPUT);
}

void loop() {
  while(digitalRead(1) == LOW);
  digitalWrite(0,HIGH);
}
