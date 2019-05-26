
void setup() {
  for(int i = 1 ;i<4;i++)
    pinMode(i,OUTPUT);

  digitalWrite(1,HIGH);
  delay(500);
}

void loop() {
  for(int i = 2 ;i< 4 ; i++){
    digitalWrite(i , HIGH);
    digitalWrite(i-1,LOW);
    delay(500);
  }
 // digitalWrite(3,LOW);
  for(int i = 2;i > 0; i--){
    digitalWrite(i+1,LOW);
    digitalWrite(i, HIGH);
    delay(500);
  }
}
