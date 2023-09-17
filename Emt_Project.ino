#include <Servo.h>
Servo myservo;
Servo myservo1;
int ConvBeltpos = 3;
int ConvBeltneg = 4;
int ir = 6;
int pwm = 5;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  myservo1.attach(10);
  pinMode(A0,0);
  pinMode(ConvBeltpos,1);
  pinMode(ConvBeltneg,1);
  pinMode(ir,0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo1.write(0);
  analogWrite(pwm,250);
  int det = digitalRead(6);
  if (det!=1){
    digitalWrite(ConvBeltpos,0);
    digitalWrite(ConvBeltneg,0);
    myservo1.write(80);
    delay(3000);
    int mag = analogRead(A0);
    delay(1000);
    if(mag<100){
        myservo.write(10);
        myservo1.write(0);
        digitalWrite(ConvBeltpos,1);
        digitalWrite(ConvBeltneg,0);
        delay(1000);
    }
    else {
        myservo.write(100);
        myservo1.write(0);
        digitalWrite(ConvBeltpos,1);
        digitalWrite(ConvBeltneg,0);
        delay(1000);
    }
    }
  else{
    digitalWrite(ConvBeltpos,1);
    digitalWrite(ConvBeltneg,0);
    myservo1.write(0);
  }
}
