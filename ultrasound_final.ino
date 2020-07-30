#include <AFMotor.h>
#define TRIG_PIN A1
#define ECHO_PIN A0

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void setup() {
  // put your setup code here, to run once:

pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
Serial.begin(9600); 

motor1.setSpeed(200);
motor2.setSpeed(200);
motor3.setSpeed(200);
motor4.setSpeed(200);

motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}

void loop() {
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);

float microseconds = pulseIn(ECHO_PIN, HIGH, 100000);
float seconds = microseconds / 1000000;
float meters = seconds * 343;
float cm = meters * 100;
cm = cm/2;
Serial.println(cm);
delay(50);

if(cm>=113 && cm<=132){
  motor1.run(FORWARD);
  motor1.setSpeed(200);
  delay(10);

  motor2.run(FORWARD);
  motor2.setSpeed(200);
  delay(10);

  motor3.run(BACKWARD);
  motor3.setSpeed(200);
  delay(10);

  motor4.run(FORWARD);
  motor4.setSpeed(200);
  delay(10);
}
else if(cm<113){
  motor1.run(BACKWARD);
  motor1.setSpeed(200);
  delay(10);

  motor2.run(BACKWARD);
  motor2.setSpeed(200);
  delay(10);

  motor3.run(FORWARD);
  motor3.setSpeed(200);
  delay(10);

  motor4.run(BACKWARD);
  motor4.setSpeed(200);
  delay(10);
}
else{
  motor1.run(FORWARD);
  delay(10);
  
  motor2.run(FORWARD);
  delay(10);

  motor3.run(BACKWARD);
  delay(10);

  motor4.run(FORWARD);
  delay(10);
}
}
