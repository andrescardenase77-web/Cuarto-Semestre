#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

// Configuración TFT ILI9341
#define TFT_CS   45
#define TFT_RST  47
#define TFT_DC   49
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const byte ROWS = 4; 
const byte COLS = 2; 
char keys[ROWS][COLS] = {
  {'A', '1'},
  {'B', '2'},
  {'C', '3'},
  {'V', 'X'}
};
byte rowPins[ROWS] = {20, 19, 18, 17}; 
byte colPins[COLS] = {15, 16}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int pinMotor = 6;

void setup() {
  tft.begin();
  tft.setRotation(0); // MODO VERTICAL (240x320)
  tft.fillScreen(ILI9341_BLACK);
  
  tft.setTextColor(ILI9341_CYAN);
  tft.setTextSize(3); // Tamaño 3 es ideal para el ancho de 240px

  tft.setCursor(75, 100); 
  tft.print("LISTA");

  tft.setCursor(40, 150); 
  tft.print("PRODUCTOS");

  lcd.begin(16, 2);
  lcd.print("SISTEMA LISTO");

  pinMode(pinMotor, OUTPUT);
  digitalWrite(pinMotor, LOW);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TECLA: ");
    lcd.print(key);

    if (key == 'A') {
      digitalWrite(pinMotor, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("MOTOR: ENCENDIDO");
    } 
    else if (key == 'B') {
      digitalWrite(pinMotor, LOW);
      lcd.setCursor(0, 1);
      lcd.print("MOTOR: APAGADO");
    }
  }
}