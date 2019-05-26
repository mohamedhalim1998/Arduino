int const forward = 2;
int const reverse = 3;
int const forwardButton  = 8;
int const reverseButton = 9;

void setup() {
  pinMode(forward, OUTPUT);
  pinMode(reverse, OUTPUT);

  pinMode(forwardButton, INPUT);
  pinMode(reverseButton, INPUT);
}

void loop() {
  if (digitalRead(forwardButton) == HIGH) {
    digitalWrite(reverse, LOW);
    digitalWrite(forward, HIGH);
  } else if (digitalRead(reverseButton) == HIGH) {
    digitalWrite(reverse, HIGH);
    digitalWrite(forward, LOW);
  } else {
    digitalWrite(reverse, LOW);
    digitalWrite(forward, LOW);
  }

}
