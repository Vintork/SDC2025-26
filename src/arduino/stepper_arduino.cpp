
//empieza en 10 el voltaje 
#include <AccelStepper.h>

//spin more
// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200;
const int stepsFor40Degrees = 22; // Number of steps for 40 degrees
const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second

void setup()
{
	// Declare pins as Outputs
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);
}

void loop()
{
	// Set motor direction clockwise
	digitalWrite(dirPin, HIGH);

	// Rotate motor by 40 degrees in 1 second
	for (int x = 0; x < stepsFor40Degrees; x++)
	{
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(1000); // Pulse width for the step
		digitalWrite(stepPin, LOW);
		delayMicroseconds(delayPerStep - 1000); // Ensure total time for each step matches delayPerStep
	}

	delay(1000); // Wait one second before the next rotation
}
