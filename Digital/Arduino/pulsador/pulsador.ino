void setup() {
  pinMode(13, OUTPUT); 
  pinMode(2, INPUT_PULLUP); // Configuramos el Pin 2 con resistencia interna
}

void loop() {
  // Leemos el botón. Si es 0 (LOW), significa que está presionado.
  if (digitalRead(2) == 0) {
    digitalWrite(13, HIGH); // Enciende
  } else {
    digitalWrite(13, LOW);  // Apaga
  }
}