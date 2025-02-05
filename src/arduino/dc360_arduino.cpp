
#include <Servo.h>

//innecesario para arduino ide, essencial para vscode:
#include <Arduino.h>



int enA = 5;
int in1 = 2;
int in2 = 3;
int maxSpeed = 255;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void directionControl() {
  // Set motor direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  delay(2000); // Run for 2 seconds before switching to speed control
}

void speedControl() {
  // Reverse motor direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Accelerate from zero to maximum speed with a small delay
  for (int i = 100; i <= maxSpeed; i++) {
    analogWrite(enA, i);

   
  }
}
void loop() {
  directionControl();
  speedControl();
}

