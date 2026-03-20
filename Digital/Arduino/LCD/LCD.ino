#include <LiquidCrystal.h>

#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 10
#define LCD_D5 11
#define LCD_D6 12
#define LCD_D7 7

int i;

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
  lcd.begin(16,2); //
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("LCD");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(4,1);
  lcd.print("EJEMPLO");
  lcd.print(i);
  i++;
  delay(1000);
}