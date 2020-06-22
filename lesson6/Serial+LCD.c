String income="";
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11,9,8,7,6,5,4,3,2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  if(Serial.available()>0)
  {
    income = Serial.readString();
    lcd.print(income);
  }
}
 