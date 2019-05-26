// variable initialize
//---------------------
int ST, SB, SL, SC, SR;
int const Speed = - 150;
int const Limit = 50;
long R = 0;
int S[5];

int led1 = 2; //-> a *
int led2 = 3; //-> d *
int led3 = 4; //-> e *
int led4 = 5;// -> g *
int led5 = 6;// -> c *

//--------------------
int mr1 = 13;   // motor left  pin 12 -> IN3
int mr2 = 12;   // motor left  pin 13 -> IN4
int pmwr = 11;  // motor left  Pulse Width Modulation -> EN2
//---------------------

int ml1 = 9;  // motor right pin 8 -> IN1
int ml2 = 8; // motor right pin 9 -> IN2
int pmwl = 10; // motor right Pulse Width Modulation -> EN1

void AutoCalibration()
{
  for ( int i = 0; i < 5; i++ )
    S[i] = analogRead(i);
}


void Motors(int MR , int ML )
{
  if ( ML < 0 ) {
    digitalWrite(ml1, 0);
    digitalWrite(ml2, 1);
    analogWrite(pmwl, -ML);
  }
  else {
    digitalWrite(ml1, 1);
    digitalWrite(ml2, 0);
    analogWrite(pmwl, ML);
  }

  if ( MR < 0 ) {
    digitalWrite(mr1, 0);
    digitalWrite(mr2, 1);
    analogWrite(pmwr, -MR);
  }
  else {
    digitalWrite(mr1, 1);
    digitalWrite(mr2, 0);
    analogWrite(pmwr, MR);
  }
}


void PrintSensorSerial() {
  Serial.print("T = ");
  Serial.print(ST);
  Serial.print(" R = ");
  Serial.print(SR);
  Serial.print(" L = ");
  Serial.print(SL);
  Serial.print(" C = ");
  Serial.print(SC);
  Serial.print(" B = ");
  Serial.println(SB);
}


void ReadSensors() {
  ST = analogRead(A0);//  S1 -> TOP  5
  SB = analogRead(A1);//  S2 -> BOTTOM 6
  SL = analogRead(A2);//  S3 -> LEFT 8
  SC = analogRead(A3);//  S4 -> CENTER 9
  SR = analogRead(A4);//  S5 -> RIGHT 10
  PrintSensorSerial();
  if (ST < (S[0] - Limit)) {
    ST = 1;
    digitalWrite (led1, HIGH);
  } else   {
    ST = 0;
    digitalWrite (led1, LOW);
  }
  if (SB < (S[1] - Limit)) {
    SB = 1;
    digitalWrite (led2, HIGH);
  } else {
    SB = 0;
    digitalWrite (led2, LOW);
  }
  if (SL < (S[2] - Limit)) {
    SL = 1;
    digitalWrite (led3, HIGH);
  } else   {
    SL = 0;
    digitalWrite (led3, LOW);
  }
  if (SC < (S[3] - Limit)) {
    SC = 1;
    digitalWrite (led4, HIGH);
  } else {
    SC = 0;
    digitalWrite (led4, LOW);
  }

  if (SR < (S[4] - Limit)) {
    SR = 1;
    digitalWrite (led5, HIGH);

  } else {
    S, R = 0;
    digitalWrite (led5, LOW);
  }
  //PrintSensorSerial();
  R = SR * 1 + SB * 10 + SC * 100 + ST * 1000 + SL * 10000 + 500000;
  //PrintSensorSerial();
}
void setup() {
  // MOTOR drive
  pinMode (mr1, OUTPUT);
  pinMode (mr2, OUTPUT);
  pinMode (ml1, OUTPUT);
  pinMode (ml2, OUTPUT);

  // led sensor indicator
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  delay(1000);
  AutoCalibration();
  Serial.begin(9600);
}

void testDirections() {
  // forward
  Motors(Speed, Speed);
  delay(5000);
  //Right
  Motors(Speed, 0);
  delay(2000);
  // forward
  Motors(Speed, Speed);
  delay(5000);
  // LEFT
  Motors(0, Speed);
  delay(2000);
  Motors(Speed, Speed);
  delay(5000);
}
void loop() {
  ReadSensors();
  //Serial.println(R);
 /* Motors(Speed, Speed);
  delay(3000);
  Motors(0, Speed); // right
  delay(3000);
  Motors(Speed, 0); // left
  delay(3000);*/
  // R = S8  + S5 + S9 + S6  + S10;
    if (R == 501110 || R == 501111 || R == 511110 || R == 511111) {
      Motors(Speed, Speed); // forward
    } else if (R == 510010 ) {
      Motors(Speed - .2 * Speed , Speed); // slightly left
    } else if (R == 500011 ) {
      Motors(Speed, Speed - .2 * Speed); // slightly right
    } else if (R == 510110) {
      Motors(Speed, 0); // left
    } else if (R == 500111) {
      Motors(0, Speed); // right
    }
}
