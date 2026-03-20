#include <Keypad.h>
#include <SevSeg.h> 

// --- OBJETOS ---
SevSeg sevseg; 

// --- TECLADO (Sin cambios) ---
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'}, // A = Iniciar
  {'4','5','6','B'},
  {'7','8','9','C'}, // C = Reset
  {'.','0','-','D'}
};
byte rowPins[ROWS] = {21, 20, 19, 18}; 
byte colPins[COLS] = {17, 16, 15, 14}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// --- VARIABLES ---
long totalSegundos = 0;
int valorIngresado = 0;
bool cuentaRegresivaActiva = false;
unsigned long tiempoAnterior = 0;

void setup() {
  // --- CONFIGURACIÓN DE PINES (MODIFICADO) ---
  byte numDigits = 4;
  
  // AHORA USAMOS PINES 8, 9, 10, 11 PARA LOS DÍGITOS (Evitamos el 13)
  byte digitPins[] = {8, 9, 10, 11}; 
  
  // AHORA USAMOS PINES 0 AL 7 PARA LOS SEGMENTOS (A,B,C,D,E,F,G,DP)
  byte segmentPins[] = {0, 1, 2, 3, 4, 5, 6, 7}; 
  
  bool resistorsOnSegments = false; 
  byte hardwareConfig = COMMON_CATHODE; // Si sale al revés, cambia a COMMON_ANODE
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, false, true);
  sevseg.setBrightness(90);
}

void loop() {
  // Refresco constante del display
  sevseg.refreshDisplay(); 

  // Lectura del teclado
  char key = keypad.getKey();

  if (key) {
    // Si es número y no estamos contando: Ingresar datos
    if (key >= '0' && key <= '9' && !cuentaRegresivaActiva) {
      if (valorIngresado < 1000) { 
        valorIngresado = (valorIngresado * 10) + (key - '0');
      }
      sevseg.setNumber(valorIngresado, 2); 
    }
    
    // 'A': INICIAR
    else if (key == 'A') {
      int minutos = valorIngresado / 100;
      int segundos = valorIngresado % 100;
      totalSegundos = (minutos * 60) + segundos;
      
      cuentaRegresivaActiva = true;
      tiempoAnterior = millis(); 
    }
    
    // 'C': RESET
    else if (key == 'C') {
      cuentaRegresivaActiva = false;
      valorIngresado = 0;
      totalSegundos = 0;
      sevseg.setNumber(0, 2);
    }
  }

  // Lógica de Cuenta Regresiva (Sin delay)
  if (cuentaRegresivaActiva && totalSegundos > 0) {
    if (millis() - tiempoAnterior >= 1000) {
      tiempoAnterior = millis(); 
      totalSegundos--;           
      
      int minutosRestantes = totalSegundos / 60;
      int segundosRestantes = totalSegundos % 60;
      int numeroParaMostrar = (minutosRestantes * 100) + segundosRestantes;
      
      sevseg.setNumber(numeroParaMostrar, 2); 
      
      if (totalSegundos == 0) {
        cuentaRegresivaActiva = false; 
      }
    }
  }
}