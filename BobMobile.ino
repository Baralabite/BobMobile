//Motor Driver / main code for BobMobile
//Written for RCJA QLD States 2015
//Authored by John Board

/* Includes */
#include <Servo.h> 

/* Constants */
const int LEFT_MOTOR_PIN = 2;
const int RIGHT_MOTOR_PIN = 3;
const int BUTTON_PIN = 12;

unsigned long t;

/* Objects */
Servo leftMotor;
Servo rightMotor;

/* Program Code */

void setup() {
  Serial.begin(9600);
  startMotors(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);

  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH); // pull-up
  /*startTimer();
  while(true){
    while (!handleButton()){}
    Serial.println("Button up.");
    Serial.println(getTime());
    while(handleButton()){}
    Serial.println("Button down.");
    Serial.println(getTime());
  }*/
  while(!handleButton()){}
  startTimer();
}

void beep(){
  for(int x=0; x<400; x++){
    analogWrite(5, 255);
    delayMicroseconds(200);
    analogWrite(5, 0);
    delayMicroseconds(200);
  }
}

boolean handleButton()
{
  int button_pressed = !digitalRead(BUTTON_PIN); // pin low -> pressed
  return button_pressed;
}

void loop() {
  beep();
  delay(18351);
  forward(40);
  delay(2000);
  stopMotors();
  
  
  delay(25786);
  backward(40);
  delay(2000);  
  stopMotors();

  while(true){}
  
}

void startTimer(){
  t = millis();
}

int getTime(){
  return millis()-t;
}

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

  int speedL = (speed/100)*90;
  int speedR = speed;

  //1500 = neutral. 500 = full forward. 50 = half forward. 50*10 = 500. 1500-500 = 1000 - half forward.
  speedL = 1500+speedL;
  speedR = 1500+speedR;  

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

  int speedL = speed;
  int speedR = (speed/100)*95;

  
  speedL = 1500-speedL;
  speedR = 1500-speedR;

  //Write speeds to motors
  setSpeeds(speedL, speedR);


  //1500 = neutral. 500
}
