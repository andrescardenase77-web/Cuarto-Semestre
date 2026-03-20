#include "SevenSegmentsK.h"
//Elaborado por Nelson Andino y Andres Cardenas
SevenSegmentsK display;

void setup() {
  // Configuración directa: pines segmentos (0-7), pin comun (13), pin PWM (9), catodo ('c'), 1 digito, 0 decimales
  int segs[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int dig[] = {13};
  display.set(segs, dig, 9, 'c', 1, 0);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    display.print(i);
    
    // Este bucle es obligatorio para que el simulador "dibuje" los segmentos
    for(int j = 0; j < 50; j++) {
      display.interrupt(); // Activa los pines segun el número
      delay(10); 
    }
  }
}