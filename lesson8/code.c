//播放根据更改而更改的音高
//模拟输入
int sensorReading = 0;

void setup()
{
  pinMode(A0, INPUT);//设置AO口为输入
  Serial.begin(9600);//串口初始化

  pinMode(9, OUTPUT);//九号口输出
}

void loop()
{
  // read the sensor
  sensorReading = analogRead(A0);
  // 打印传感器读数，以便知道其范围（ analogRead()函数的作用是模拟输入，范围0-1023）
  Serial.println(sensorReading);
  // 将传感器读数输出到串口
  tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
  //tone函数：tone（pin,frequency,durationg）,pin:接口，引脚；frequency：频率，必须是int；duration，持续时间（ms）
  //constrain():将数字约束在一个范围内。constrain(x, a, b)。x：要约束的数字；a：范围的下限；b：范围的上限
  delay(10); // 延时
}