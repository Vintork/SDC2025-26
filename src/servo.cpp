// #include <Servo.h>
// #include <Arduino.h>

// Servo myservo;  // create servo object to control a servo
// #define SERVO_PIN 31  // Define the pin to which the servo is connected
// int pos = 0;    // variable to store the servo position

// void setup() {
//   myservo.attach(SERVO_PIN);  // attaches the servo on pin 31 to the servo object
//   Serial.begin(9600);         // Initialize serial communication
// }

// void loop() {
  
//   // Sweep from 0 to 180 degrees
//   for (pos = 0; pos <= 90; pos += 1) { 
//     myservo.write(pos);       // tell servo to go to position in variable 'pos'
//     delay(15);                // waits 15ms for the servo to reach the position
//     Serial.println("red");    // Print "red" when moving from 0 to 180
//   }
  
//   // Sweep from 180 to 0 degrees
//   for (pos = 90; pos >= 0; pos -= 1) {
//     myservo.write(pos);       // tell servo to go to position in variable 'pos'
//     delay(15);                // waits 15ms for the servo to reach the position
//     Serial.println("blue");   // Print "blue" when moving from 180 to 0
//   }
// }
#include <Servo.h>
#include <Arduino.h>

Servo myservo;  // create servo object to control a servo
#define SERVO_PIN 31  // Define the pin to which the servo is connected
int pos = 0;    // variable to store the servo position
char input;
bool left=false;
bool right=false;


void setup() {
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 31 to the servo object
  Serial.begin(9600);         // Initialize serial communication
}

void loop() {
    if (Serial.available() > 0) {
      input = Serial.read();  // Read the incoming byte}
    }
  // Sweep from 0 to 180 degrees
  if ((input == 'L' || input == 'l')&&left==false) {
    left=true;
    right=false;

    for (pos = 0; pos <= 90; pos += 1) { 
      myservo.write(pos);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("red");    // Print "red" when moving from 0 to 180
    }
   
  }
 
  else if ((input == 'R' || input == 'r')&& right==false) { 
    right=true;
    left=false;

    // Sweep from 180 to 0 degrees
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("blue");   // Print "blue" when moving from 180 to 0
    }
   
 }

}