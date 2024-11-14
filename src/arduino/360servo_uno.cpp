#include <Servo.h>

//innecesario para arduino ide, essencial para vscode:
#include <Arduino.h>


Servo myServo;  // Create a servo object



void setup()
{
  myServo.attach(9);  // Attach the servo to pin 9
}

void loop()
{
  // Rotate the servo continuously clockwise
  //-=counterclockwise
  //+=clockwise
  myServo.writeMicroseconds(-1300);  // Send a signal to rotate clockwise
  delay(100);  // Delay to let it run (adjust as needed)
}
