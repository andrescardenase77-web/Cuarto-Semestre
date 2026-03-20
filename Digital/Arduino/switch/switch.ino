void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  // Leemos el switch. 
  // LOW (0) significa que el switch está cerrado (activado hacia tierra)
  if (digitalRead(2) == 0) {
    digitalWrite(13, HIGH); // Se queda encendido
  } else {
    digitalWrite(13, LOW);  // Se queda apagado
  }
}