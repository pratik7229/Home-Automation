//
#define J2 5
#define J3 4
#define J4 0
#define J5 2
//#define F2 14  
//#define L1 16

#define L2 14
#define L3 12
#define L4 13
#define F1 16
//#define F2 5  
//#define L1 4


void setup()
{
//  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(F1,OUTPUT);
  pinMode(J2,OUTPUT);
  pinMode(J3,OUTPUT);
  pinMode(J4,OUTPUT);
  pinMode(J5,OUTPUT);
//  pinMode(F2,OUTPUT);
//  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(F1,HIGH);
  digitalWrite(J2,HIGH);
  digitalWrite(J3,HIGH);
  digitalWrite(J4,HIGH);
  digitalWrite(J5,HIGH);
//
//  digitalWrite(F2,HIGH);
}

void loop()
{

  delay(1000);
  digitalWrite(L2,LOW);
  delay(1000);
  digitalWrite(L3,LOW);
  delay(1000);
  digitalWrite(L4,LOW);
  delay(1000);
  digitalWrite(F1,LOW);
  delay(1000);
  digitalWrite(J2,LOW);
  delay(1000);
  digitalWrite(J3,LOW);
  delay(1000);
  digitalWrite(J4,LOW);
  delay(1000);
  digitalWrite(J5,LOW);
  delay(5000);
//  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  delay(1000);
  digitalWrite(L3,HIGH);
  delay(1000);
  digitalWrite(L4,HIGH);
  delay(1000);
  digitalWrite(F1,HIGH);
  delay(1000);

  digitalWrite(J2,HIGH);
  delay(1000);
  digitalWrite(J3,HIGH);
  delay(1000);
  digitalWrite(J4,HIGH);
  delay(1000);
  digitalWrite(J5,HIGH);
  delay(1000);
}
