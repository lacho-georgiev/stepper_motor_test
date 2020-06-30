/* Example sketch to control a stepper motor with L298N motor driver, Arduino UNO and Stepper.h library. More info: https://www.makerguides.com */

// Include the Stepper library:
#include <Stepper.h>

// Define number of steps per revolution:
const int STEPS_PER_REVOLUTION = 48; // number of steps for full motor revolution

const int PIN_SW = 2; // input pin from internal switch to stop motor when reach its bounds 

const int PIN_EN = 3; // output pin to motor driver to safe power

// callback function used to control stepper object
bool pause () { 
  return (digitalRead(PIN_SW) == LOW);
}

// Initialize the stepper library on pins 10 through 13:
Stepper myStepper = Stepper(STEPS_PER_REVOLUTION, 10, 11, 12, 13, &pause);

void setup() {
  // Set the motor speed (RPMs):
  myStepper.setSpeed(240);

  pinMode(PIN_EN, OUTPUT);
  
  pinMode(PIN_SW, INPUT);
}

void loop() {
  // enable motor driver
  digitalWrite(PIN_EN, HIGH);

  //needs some time the motor driver to become enabled
  delay(1000);
  
  // Step one revolution in one direction
  myStepper.step(480);
  
  // disable motor driver
  digitalWrite(PIN_EN, LOW);
  
  // some delay between each movements
  delay(2000);
}
