#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int analogInPin1 = A5;
const int analogOutPin1 = 9;
const int analogInPin2 = A4;
const int analogOutPin2 = 9;

int sensorValue1 = 0;
int outputValue1 = 0;
int sensorValue2 = 0;
int outputValue2 = 0;

void setup() {
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
  uint8_t i;
  sensorValue1 = analogRead(analogInPin1);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
  analogWrite(analogOutPin1, outputValue1);

  sensorValue2 = analogRead(analogInPin2);
  outputValue2 = map(sensorValue2, 0,1023, 0, 225);
  analogWrite(analogOutPin2, outputValue2);
  if(outputValue1>=39)
  {
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
  else if(outputValue2>=39)
  {
      for(i=0; i<50; i++){
        if(outputValue1>=39 && outputValue2<=225)
        {
          continue;
          Serial.println("Obstacle detected!!");
          motor1.run(RELEASE);
          motor2.run(RELEASE);
          motor3.run(RELEASE);
          motor4.run(RELEASE);
          
        }
        else
        {
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
         break;
        }
    }
  }
  else
  {
    Serial.println("Obstacle detected!!");
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    
  }
} 
