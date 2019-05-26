// variable initialize
//------------------
int S1, S2, S3, S4, S5, S6;
int Speed = -  90;
int const Limit = 100;
long R = 0;
int S[5];

//---------------------
int mr1 = 12;   // motor left  pin 12 -> IN3
int mr2 = 13;   // motor left  pin 13 -> IN4
int pmwr = 11;  // motor left  Pulse Width Modulation -> EN2
//----------------------

int ml1 = 8;  // motor right pin 8 -> IN1
int ml2 = 9; // motor right pin 9 -> IN2
int pmwl = 10; // motor right Pulse Width Modulation -> EN1

//-------------------------
int led1 = 2;// -> B
int led2 = 3; //-> A
int led3 = 4; //-> G
int led4 = 5; //-> D
int led5 = 6; //-> C


void AutoCalibration()
{
  for ( int i = 0; i < 5; i++ )
    S[i] = analogRead(i);

}


void Motors(int MR , int ML )
{
  // MOTOR LEFT CONTROL DIRECTION
  if ( ML < 0 ) {
    digitalWrite(ml1, 0);
    digitalWrite(ml2, 1);
    analogWrite(pmwl, -ML);
  } else {
    digitalWrite(ml1, 1);
    digitalWrite(ml2, 0);
    analogWrite(pmwl, ML);
  }
// MOTOR RIGHT CONTROL DIRECTION
  if ( MR < 0 ) {
    digitalWrite(mr1, 0);
    digitalWrite(mr2, 1);
    analogWrite(pmwr, -MR);
  } else {
    digitalWrite(mr1, 1);
    digitalWrite(mr2, 0);
    analogWrite(pmwr, MR);
  }
}
void PrintSensorSerial() {
  Serial.print("s1 = ");
  Serial.print(S1);
  Serial.print(" s2 = ");
  Serial.print(S2);
  Serial.print(" s3 = ");
  Serial.print(S3);
  Serial.print(" s4 = ");
  Serial.print(S4);
  Serial.print(" s5 = ");
  Serial.println(S5);
}
void ReadSensors()
{
  S1 = analogRead(A0);//  A0 ->
  S2 = analogRead(A1);//  A1 ->
  S3 = analogRead(A2);//  A2 ->
  S4 = analogRead(A3);//  A3 ->
  S5 = analogRead(A4);//  A4 ->
  //PrintSensorSerial();
  if (S1 < (S[0] - Limit)) {
    S1 = 1;
    digitalWrite(led1, HIGH);
  } else {
    S1 = 0;
    digitalWrite(led1, LOW);
  }
  if (S2 < (S[1] - Limit)) {
    S2 = 1;
    digitalWrite(led2, HIGH);
  } else {
    S2 = 0;
    digitalWrite(led2, LOW);
  }

  if (S3 < (S[2] - Limit)) {
    S3 = 1;
    digitalWrite(led3, HIGH);
  } else {
    S3 = 0;
    digitalWrite(led3, LOW);
  }

  if (S4 < (S[3] - Limit)) {
    S4 = 1;
    digitalWrite(led4, HIGH);
  }  else    {
    S4 = 0;
    digitalWrite(led4, LOW);
  }

  if (S5 < (S[4] - Limit))  {
    S5 = 1;
    digitalWrite(led5, HIGH);
  } else  {
    S5 = 0;
    digitalWrite(led5, LOW);
  }
    //PrintSensorSerial();
  R = S1 * 1 + S2 * 10 + S3 * 100 + S4 * 1000 + S5 * 10000;

}

void setup()
{
  pinMode (mr1, OUTPUT);
  pinMode (mr2, OUTPUT);
  pinMode (ml1, OUTPUT);
  pinMode (ml2, OUTPUT);
  delay(1000);
  AutoCalibration();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop()
{ 
  ReadSensors();
  Serial.println(R);
  if ( R == 100 ) // 00100 -> forward
    Motors(Speed, Speed);
  else if ( R == 110 || R == 10 ) // some what right
    Motors(Speed - .2 * Speed, Speed);
  else if ( R == 11 ) //right
    Motors(0, Speed);
  else if ( R == 111 || R == 1 || R == 1111 ) // right
    Motors(-Speed, Speed);
      else if ( R == 1000  || R == 1100 ) //some what left
    Motors(Speed, Speed - .2 * Speed);
  else if ( R == 11000)  //left
    Motors(Speed, 0);
  else if ( R == 10000 || R == 11100 || R == 11110 )  //left
    Motors(Speed, -Speed);
}
