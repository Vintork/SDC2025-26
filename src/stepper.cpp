#include <AccelStepper.h>

// Define the stepper motor connections and motor interface type
#define STEP_PIN 52
#define DIR_PIN 40

// Create a stepper object
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// Define steps per revolution (for your stepper motor)
const int stepsPerRevolution = 20; // Change this according to your motor
const float degreesPerStep = 360.0 / stepsPerRevolution; // degrees per step

// Calculate the number of steps for 10 degrees
const int stepsFor10Degrees = (10 / degreesPerStep) * stepsPerRevolution;

void setup() {
  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(1000); // steps per second
  stepper.setAcceleration(500); // steps per second^2
}

void loop() {
  // Move the stepper motor 10 degrees clockwise
  stepper.moveTo(stepper.currentPosition() + stepsFor10Degrees);
  
  // Move the motor to the target position
  while (stepper.currentPosition() != stepper.targetPosition()) {
    stepper.run();
  }

  // Wait for 1 second
  delay(1000);
}
