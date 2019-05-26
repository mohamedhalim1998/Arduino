#include <LiquidCrystal.h>
int rs = 8;
int en = 9;
int d4 = 10;
int d5 = 11;
int d6 = 12;
int d7 = 13;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  int temp = (analogRead (A0) * 5.0 / 1023.0) * 100;
  lcd.setCursor(0, 0);
  lcd.print(temp);
}
