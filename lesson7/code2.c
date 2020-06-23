#include <MsTimer2.h>
int tick = 0;
int pinInterrupt=2;
#define IN1 10
#define IN2 11
#define IN3 12
#define IN4 13
void myfunc()
{
   if(tick > 9)
   {
     tick=0;
   }
   digitalWrite(IN1,tick&0x1);
   digitalWrite(IN2,(tick>>1)&0x1);
   digitalWrite(IN3,(tick>>2)&0x1);
   digitalWrite(IN4,(tick>>3)&0x1);   
   tick++;
}

void re0()
{
  tick=0;
}

void setup()
{
  pinMode(pinInterrupt, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), re0, CHANGE);
  MsTimer2::set(1000, myfunc); 
  MsTimer2::start(); 
}

void loop()
{
}  