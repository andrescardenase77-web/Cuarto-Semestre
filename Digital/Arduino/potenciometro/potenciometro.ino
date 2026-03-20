#include <LiquidCrystal.h>
// Elaborado por Nelson Andino y Andres Cardenas

#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 10
#define LCD_D5 11
#define LCD_D6 12
#define LCD_D7 7 

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

const int potPin = A0;
int potValue = 0;
float voltage = 0; 

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCD");
  delay(500);
}

void loop() {
  potValue = analogRead(potPin);
  
  voltage = potValue * (5.0 / 1024.0);

  lcd.clear(); 

  lcd.setCursor(0, 0);      
  lcd.print("Dig: ");    
  lcd.print(potValue);      

  lcd.setCursor(0, 1);     
  lcd.print("Volt: ");      
  lcd.print(voltage);       
  lcd.print(" V");          

  delay(500); 
}