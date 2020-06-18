char ch = 0;
void setup()
{
    char i;
  Serial.begin(9600);
    for(i=10;i<14;i++)
    {
      pinMode(i,OUTPUT);
      digitalWrite(i,LOW);
    }
}
void loop()
{
  if(Serial.available()>0)
   {    
      ch = Serial.read();
      switch(ch)
      {
        case 'W':
          digitalWrite(10,HIGH);
          digitalWrite(11,LOW);
          digitalWrite(12,HIGH);
          digitalWrite(13,LOW);
          break;
        case 'S':
          digitalWrite(10,LOW);
          digitalWrite(11,HIGH);
          digitalWrite(12,LOW);
          digitalWrite(13,HIGH);
          break;
        case 'A':
          digitalWrite(10,HIGH);
          digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          digitalWrite(13,HIGH);
          break;
        case 'D': 
          digitalWrite(10,LOW);
          digitalWrite(11,HIGH);
          digitalWrite(12,HIGH);
          digitalWrite(13,LOW);
          break;
       default:
          break;
     }
 }
}