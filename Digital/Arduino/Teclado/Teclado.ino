#include <Keypad.h>

#define SEG_A 8
#define SEG_B 9
#define SEG_C 10
#define SEG_D 11
#define SEG_E 12
#define SEG_F 22
#define SEG_G 24
#define SEG_H 26

/* Keypad setup */
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {21, 20, 19, 18};
byte colPins[KEYPAD_COLS] = {17, 16, 15, 14};
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);


void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
}

void loop() {// obtiene tecla presionada y asigna a variable
  char key = keypad.getKey();
  // comprueba que se haya presionado una tecla
  if (key) {

      digitalWrite(SEG_A,bitRead(key, 0));     
      digitalWrite(SEG_B,bitRead(key, 1));  
      digitalWrite(SEG_C,bitRead(key, 2)); 
      digitalWrite(SEG_D,bitRead(key, 3)); 
      digitalWrite(SEG_E,bitRead(key, 4));  
      digitalWrite(SEG_F,bitRead(key, 5));
      digitalWrite(SEG_G,bitRead(key, 6));
      digitalWrite(SEG_H,bitRead(key, 7)); 


  }// put your main code here, to run repeatedly:

}
