#include "DHT.h"

#define PIR 9
#define L1 5
#define L2 4
#define L3 0
#define L4 2
#define L5 13
#define L6 16
#define F1 14
#define F2 12

DHT dht;

int stat = 0;
float temperature = 0, humidity = 0;
int fanon = 0, lighton = 0;
int start_loop = 0;
void setup()
{ 
  Serial.begin(9600);
  pinMode(PIR,INPUT);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(L5,OUTPUT);
  pinMode(L6,OUTPUT);
  pinMode(F1,OUTPUT);
  pinMode(F2,OUTPUT);
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(F1,HIGH);
  digitalWrite(F2,HIGH);
  dht.setup(10);
  
}

void loop()
{ 
  if (start_loop == 0)
  {
    delay(10000);
   start_loop = 1;
   Serial.println("starting loop please wait");
  }

  else
  {
  int movement = pir_read();
  temperature_read();
  int ldr = read_ldr();
  
  
  if(movement == 1)
  {
  delay(2000);
  if(temperature > 34)
  {
  fanon = 1;
  fan_control(fanon);
  }
  else
  { fanon = 0;
    fan_control(fanon);
    }

   if(ldr == 1)
   {
    
    lighton = 1;
    light_control(lighton);
   }
//    else
//    {
//      lighton = 0;
//      light_control(lighton);  
//      }
  }

  else
  { 
    delay(200);
    digitalWrite(L1,HIGH);
    digitalWrite(L2,HIGH);
    delay(200);
    digitalWrite(L3,HIGH);
    digitalWrite(L4,HIGH);
    delay(200);
    digitalWrite(L5,HIGH);
    digitalWrite(L6,HIGH);
    delay(200);
    digitalWrite(F1,HIGH);
    digitalWrite(F2,HIGH);
    lighton = 0;
  }
   Serial.print("movement : ");
   Serial.println(movement);
   Serial.print("ldr");
   Serial.println(ldr);
   Serial.print("temperature");
   Serial.println(temperature);
   Serial.print("fan on");
   Serial.println(fanon);
   Serial.print("Light on");
   Serial.println(lighton);

   Serial.println("_______________________________");
  delay(200);
}

}
int pir_read()
{
  int a = digitalRead(PIR);
  return a;
}

int read_ldr()
{

  int sensor_value = analogRead(A0);
  
  if (sensor_value < 900)
  {
    stat = 1;
  }
  else
  {
    stat = 0;
  }
  return stat;
}


  
void temperature_read()
{
    delay(dht.getMinimumSamplingPeriod()); 
    humidity = dht.getHumidity();
    temperature = dht.getTemperature();
}


void fan_control(int Fonoff)
{
  if(Fonoff == 1)
  {
    delay(500);
    digitalWrite(F1,LOW);
    delay(500);
    digitalWrite(F2,LOW);
  }
  else
  {
    delay(200);
    digitalWrite(F1,HIGH);
    delay(200);
    digitalWrite(F2,HIGH);
  }
  
}


void light_control(int Lonoff)
{
  if(Lonoff == 1)
  {
    delay(500);
    digitalWrite(L1,LOW);
    delay(500);
    digitalWrite(L2,LOW);
    delay(500);
    digitalWrite(L3,LOW);
    delay(500);
    digitalWrite(L4,LOW);
    delay(500);
    digitalWrite(L5,LOW);
    delay(500);
    digitalWrite(L6,LOW);
  }
  else
  {
    delay(200);
    digitalWrite(L1,HIGH);
    digitalWrite(L2,HIGH);
    delay(200);
    digitalWrite(L3,HIGH);
    digitalWrite(L4,HIGH);
    delay(200);
    digitalWrite(L5,HIGH);
    digitalWrite(L6,HIGH);
  }
}
