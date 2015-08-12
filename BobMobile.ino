//Motor Driver / main code for BobMobile
//Written for RCJA QLD States 2015
//Authored by John Board

/* Includes */
#include <Servo.h> 

/* Constants */
const LEFT_MOTOR_PIN = 2;
const RIGHT_MOTOR_PIN = 3;

/* Objects */
Servo leftMotor;
Servo rightMotor;

/* Program Code */

void setup() {
  startMotors(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);
}

void loop() {}

/* Driver Code */

void startMotors(int leftMotorPin, int rightMotorPin){
  leftMotor.attach(leftMotorPin);
  rightMotor.attach(rightMotorPin);

  //Set both motors to stop
  leftMotor.writeMicroseconds(1500);
  rightMotor.writeMicroseconds(1500);
}

void setSpeeds(int speedL, int speedR){
  leftMotor.writeMicroseconds(speedL);
  rightMotor.writeMicroseconds(speedR);   
}

void stopMotors(){
  setSpeeds(1500, 1500);
}

void forward(int speed){
  // Any speed outside the 0-100 range will be brought back within range
  if (speed > 100){
    speed = 100;
  } else if (speed < 0){
    speed = 0;
  }

  //As speed is from 0-100 and range is from 0-1000 (1500-2500), input gets multipled by 10
  speed = speed * 10;

  //1500 = neutral. 500 = full forward. 50 = half forward. 50*10 = 500. 1500-500 = 1000 - half forward.
  speed = 1500-speed;

  //Offset code here

  //Write speeds to motors
  setSpeeds(speedL, speedR);
}

void backward(int speed){
  // Any speed outside the 0-100 range will be brought back within range
  if (speed > 100){
    speed = 100;
  } else if (speed < 0){
    speed = 0;
  }

  //As speed is from 0-100 and range is from 0-1000 (1500-2500), input gets multipled by 10
  speed = speed * 10;

  //1500 = neutral. 500 = full forward. 50 = half forward. 50*10 = 500. 1500-500 = 1000 - half forward.
  speed = 1500+speed;

  //Offset code here

  //Write speeds to motors
  setSpeeds(speedL, speedR);
}
