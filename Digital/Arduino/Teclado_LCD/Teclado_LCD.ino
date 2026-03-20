#include <Keypad.h>
#include <LiquidCrystal.h>
//Elaborado por Nelson Andino y Andres Cardenas

#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 10
#define LCD_D5 11
#define LCD_D6 12
#define LCD_D7 7 

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);


const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

byte rowPins[KEYPAD_ROWS] = {21, 20, 19, 18};
byte colPins[KEYPAD_COLS] = {17, 16, 15, 14};

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'.', '0', '-', 'D'} 
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Tecla pulsada:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lcd.setCursor(8, 1);     
    lcd.print(key);       
  }
}