void setup() {
  // put your setup code here, to run once:
 
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (0, HIGH);
  digitalWrite (1, HIGH);
  digitalWrite (2, HIGH);
  digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  digitalWrite (5, HIGH);
  digitalWrite (6, LOW);
  delay(1000);// this speeds up the simulation
  digitalWrite (0, LOW);
  digitalWrite (1, HIGH);
  digitalWrite (2, HIGH);
  digitalWrite (3, 0);
  digitalWrite (4, 0);
  digitalWrite (5, 0);
  digitalWrite (6, LOW);
  delay(1000);// this speeds up the simulation


}