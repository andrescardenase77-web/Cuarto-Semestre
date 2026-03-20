#define SEG_A 0
#define SEG_B 1
#define SEG_C 2
#define SEG_D 3
#define SEG_E 4
#define SEG_F 5
#define SEG_G 6


// This array converts a number 0-9 to a bit pattern to send to the GPIOs
int salida[10] = {
        0x3f,  // numero 0 = 0x3f o B00111111
        0x06,  // 1
        0x5b,  // 2
        0x4f,  // 3
        0x66,  // 4
        0x6d,  // 5
        0x7d,  // 6
        0x07,  // 7
        0x7f,  // 8
        0x67   // 9
};
int i;

void setup() {
for (int gpio = 0; gpio < 7; gpio++) {
        pinMode(gpio, OUTPUT); //pinMode(0, OUTPUT)
    }
}

void loop() {
  for (i=0; i<10;i++){        // digitalWrite (0, HIGH)                    
			digitalWrite(SEG_A,bitRead(salida[i], 0));  // 1    
      digitalWrite(SEG_B,bitRead(salida[i], 1));  // 1
      digitalWrite(SEG_C,bitRead(salida[i], 2));  // 1
      digitalWrite(SEG_D,bitRead(salida[i], 3));  // 1
      digitalWrite(SEG_E,bitRead(salida[i], 4));  // 1
      digitalWrite(SEG_F,bitRead(salida[i], 5));  // 1
      digitalWrite(SEG_G,bitRead(salida[i], 6));  // 0
			delay(1000);
  } 
}