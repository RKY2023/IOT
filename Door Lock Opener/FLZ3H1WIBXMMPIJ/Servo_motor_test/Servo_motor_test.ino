// Chapter 5 - Motor Control
// Controlling Speed
// By Cornel Amariei for Packt Publishing

// Include the Servo library
#include <Servo.h> 
Servo s1;
// Declare the Servo pin
int servoPin = 3;
// Create a servo object


void setup() {
  // We need to attach the servo to the used pin number
  s1.attach(9);
}

void loop(){
  // Make servo go to 0 degrees
  s1.write(0);
  delay(1000);
  // // Make servo go to 90 degrees
  // s1.write(90);
  // delay(1000);
  // Make servo go to 180 degrees
  s1.write(180);
  delay(1000);
  s1.write(0);
}

