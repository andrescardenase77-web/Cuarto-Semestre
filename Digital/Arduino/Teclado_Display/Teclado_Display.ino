#include <Keypad.h>
//Elaborado por Nelson Andino y Andres Cardenas
// --- MAPEO DE PINES PARA EL DISPLAY (Pines 0-7) ---
#define SEG_A 0
#define SEG_B 1
#define SEG_C 2
#define SEG_D 3
#define SEG_E 4
#define SEG_F 5
#define SEG_G 6
#define SEG_H 7

#define LED_0 8
#define LED_1 9
#define LED_2 10
#define LED_3 11
#define LED_4 12
#define LED_5 22
#define LED_6 24
#define LED_7 26

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
  // Inicializa pines del Display (0-7)
  for (int i = 0; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }

  // Inicializa pines de los LEDs (8-26)
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    digitalWrite(8,  bitRead(key, 0));
    digitalWrite(9,  bitRead(key, 1));
    digitalWrite(10, bitRead(key, 2));
    digitalWrite(11, bitRead(key, 3));
    digitalWrite(12, bitRead(key, 4));
    digitalWrite(22, bitRead(key, 5));
    digitalWrite(24, bitRead(key, 6));
    digitalWrite(26, bitRead(key, 7));

    //Encender el display
    int patron = 0;
    switch (key) {
      case '0': patron = 0x3F; break; 
      case '1': patron = 0x06; break; 
      case '2': patron = 0x5B; break; 
      case '3': patron = 0x4F; break; 
      case '4': patron = 0x66; break; 
      case '5': patron = 0x6D; break; 
      case '6': patron = 0x7D; break; 
      case '7': patron = 0x07; break; 
      case '8': patron = 0x7F; break; 
      case '9': patron = 0x6F; break; 
      case 'A': patron = 0x77; break;
      case 'B': patron = 0x7C; break; // b minúscula
      case 'C': patron = 0x39; break;
      case 'D': patron = 0x5E; break; // d minúscula
      case '.': patron = 0x80; break; 
      case '-': patron = 0x40; break; 
    }

    // Enviamos los bits del patrón a los pines 0-7
    digitalWrite(SEG_A, bitRead(patron, 0));
    digitalWrite(SEG_B, bitRead(patron, 1));
    digitalWrite(SEG_C, bitRead(patron, 2));
    digitalWrite(SEG_D, bitRead(patron, 3));
    digitalWrite(SEG_E, bitRead(patron, 4));
    digitalWrite(SEG_F, bitRead(patron, 5));
    digitalWrite(SEG_G, bitRead(patron, 6));
    digitalWrite(SEG_H, bitRead(patron, 7));
  }
}