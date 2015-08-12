// zoomkat 10-4-10 serial servo test
// type servo position 0 to 180 in serial monitor
// for writeMicroseconds, use a value like 1500
// for IDE 0019 and later
// Powering a servo from the arduino usually DOES NOT WORK.

#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 
Servo myservo_;  // create servo object to control a servo 

void setup() {
  myservo.attach(2);  //the pin for the servo control 
  myservo.writeMicroseconds(2025); //7.37
  myservo_.attach(3);//7.13
  myservo_.writeMicroseconds(2000);
}

void loop() {
  myservo_.writeMicroseconds(2025);
  myservo.writeMicroseconds(2000);
  delay(10000);
 /* myservo.writeMicroseconds(2000);
  myservo_.writeMicroseconds(2000);
  delay(1000);
  myservo.writeMicroseconds(1500);
  myservo_.writeMicroseconds(1500);
  delay(1000);
  myservo.writeMicroseconds(1000);
  myservo_.writeMicroseconds(1000);
  delay(1000);  
  myservo.writeMicroseconds(1500);
  myservo_.writeMicroseconds(1500);
  delay(1000);*/
}
