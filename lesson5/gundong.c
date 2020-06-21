byte income[100];
int i,j,k,p;
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S1 8
#define S2 9
#define S3 10
#define S4 11
#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    int n = 0;
    while(Serial.available()>0)
    {
      income[n] = Serial.read();
      income[n] -= '0';
      delay(10);
      n+=1;
    }
    
    byte a[n];
    for(i=0;i<n;i++)
    {
      a[i]=income[i];
      delay(10);
      Serial.println(a[i]);
    }
    
    while(1)
    {
      j=i+1;k=i+2;p=i+3;
      if(i>=n) i-=n;
      if(j>=n) j-=n;
      if(k>=n) k-=n;
      if(p>=n) p-=n;
      digitalWrite(S1,LOW);
      digitalWrite(IN1,a[i]&0x1);
      digitalWrite(IN2,(a[i]>>1)&0x1);
      digitalWrite(IN3,(a[i]>>2)&0x1);
      digitalWrite(IN4,(a[i]>>3)&0x1);
      digitalWrite(S1,HIGH);
      delay(10);
      
      digitalWrite(S2,LOW);
      digitalWrite(IN1,a[j]&0x1);
      digitalWrite(IN2,(a[j]>>1)&0x1);
      digitalWrite(IN3,(a[j]>>2)&0x1);
      digitalWrite(IN4,(a[j]>>3)&0x1);
      digitalWrite(S2,HIGH);
      delay(10);
      
      digitalWrite(S3,LOW);
      digitalWrite(IN1,a[k]&0x1);
      digitalWrite(IN2,(a[k]>>1)&0x1);
      digitalWrite(IN3,(a[k]>>2)&0x1);
      digitalWrite(IN4,(a[k]>>3)&0x1);
      digitalWrite(S3,HIGH);
      delay(10);
      
      digitalWrite(S4,LOW);
      digitalWrite(IN1,a[p]&0x1);
      digitalWrite(IN2,(a[p]>>1)&0x1);
      digitalWrite(IN3,(a[p]>>2)&0x1);
      digitalWrite(IN4,(a[p]>>3)&0x1);
      digitalWrite(S4,HIGH);
      delay(10);
      
      delay(2000);
      i+=1;
    }
  }
}
