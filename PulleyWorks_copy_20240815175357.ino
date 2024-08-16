#include "AccelStepper.h" 
#include <Servo.h>

// Create the servo object
Servo PULLEY;

#define pulley_home_switch 3 // Pin 3 connected to limit switch

// Setup section to run once
void setup() {
  PULLEY.attach(13); // attach the servo to our servo object
  PULLEY.write(90); // stop the motor

  //Serial.begin(9600); // Start the Serial monitor with speed of 9600 Bauds
  pinMode(pulley_home_switch, INPUT_PULLUP);
  delay(5); // Wait for driver wake up
}

// Loop to keep the motor turning!
void loop() {
  PULLEY.write(94); // stop the motor
  delay(5000); // stay stopped
// PULLEY HOMING
  while (digitalRead(pulley_home_switch)) {  // Make the Stepper move CW until the switch is activated   
  PULLEY.write(135); // rotate the motor counter-clockwise 3 times (135)
  //delay(30000); // keep rotating for 5 seconds (5000 milliseconds)
  }

  PULLEY.write(94); // stop the motor
  delay(5000); // stay stopped

  PULLEY.write(45); // rotate the motor clockwise
  delay(20000); // keep rotating 😀

  PULLEY.write(94); // stop the motor
  delay(5000); // stay stopped
}