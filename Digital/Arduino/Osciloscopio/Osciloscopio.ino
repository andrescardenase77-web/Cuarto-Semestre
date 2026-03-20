int motor =3;
int led = 5;
int pwm = 0;

void setup(){
  pinMode(motor,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop(){
  if(pwm >= 255){
    pwm = 0;
  }
  pwm++;
  analogWrite(motor,pwm);
  analogWrite(led,pwm);
  delay(50);
}