#define pir 9
void setup() {
Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(pir,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int a = digitalRead(pir);
Serial.println(a);
}
