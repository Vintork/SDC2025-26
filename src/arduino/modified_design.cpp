#include <Servo.h>
#include <Arduino.h>
#include <AccelStepper.h>

//servo
Servo myservo1, myservo2, myservo3;  // create servo object to control a servo
#define SERVO1_PIN 9  // Define the pin to which servo1 is connected
#define SERVO2_PIN 10  // Define the pin to which servo2 is connected
#define SERVO3_PIN 11  // Define the pin to which servo3 is connected
int pos1 = 0, pos2 = 0, pos3 = 0;
int originalpos1 = 0, originalpos2 = 0, originalpos3 = 0;    // variable to store the servos position

//STEPPER VARIABLES
const int dirPin = 2;
const int stepPin = 3;
const int stepsFor40Degrees = 55; // Number of steps for 40 degrees
const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second
int count = 10;

//sensor
int sensor = 13;
int sensor2 = 7;

void setup() { 
  //sensor
  pinMode(sensor, INPUT);
  pinMode(sensor2, INPUT);

  //servo
  myservo1.attach(SERVO1_PIN);  
  myservo2.attach(SERVO2_PIN);  
  myservo3.attach(SERVO3_PIN);  
  myservo2.write(0);
  myservo1.write(0);
  myservo3.write(0);
  
  //STEPPER 
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);   
}

int sensores(){
    //read sensor input
    int state1 = digitalRead(sensor);
    int state2 = digitalRead(sensor2);
    return state1, state2;
}

//servo functions
//wheel
void servo_1(){
    //move clockwise
    for (pos1 = 0; pos1 <= 180; pos1 += 5) { 
        myservo1.write(pos1);  
        delay(30); 
    }
    delay(200);
    //move back 
    for (pos1 = 180; pos1 >= originalpos1; pos1 -= 5) {
        myservo1.write(pos1);
        delay(30);
    }
}

//gate 
void servo_2(){
    //move clockwise
    for (pos2 = 0; pos2 <= 180; pos2 += 5) { 
        myservo2.write(pos2);  
        delay(30); 
    }
    delay(200);
    //move back 
    for (pos2 = 180; pos2 >= originalpos2; pos2 -= 5) {
        myservo2.write(pos2);
        delay(30);
    }
}

//caminos
void servo_3(String material){
    if (material == "brass"){
        // Move 30 degrees counterclockwise
        for (pos3 = originalpos3; pos3 >= originalpos3 - 30; pos3 -= 5) {
            myservo3.write(pos3);
            delay(30);
        }
        
        servo_2();
        delay(200);
        // Return to original position
        for (pos3 = originalpos3 - 30; pos3 <= originalpos3; pos3 += 5) {
            myservo3.write(pos3);
            delay(30);
        }
    }
    else if (material == "steel"){
        // Move 30 degrees clockwise
        for (pos3 = originalpos3; pos3 <= originalpos3 + 30; pos3 += 5) {
            myservo3.write(pos3);
            delay(30);
        }
        
        servo_2();
        delay(200);
        // Return to original position
        for (pos3 = originalpos3 + 30; pos3 >= originalpos3; pos3 -= 5) {
            myservo3.write(pos3);
            delay(30);
        }
    }
}

void loop() {
  servo_1();
  int sensor1, sensor2;
  sensor1, sensor2 = sensores(); //find sensor input
  
  if (sensor1 && sensor2){
      servo_3("steel");
  }
  else if(sensor1 && !sensor2){
      servo_3("brass");
  }
  else{
    servo_2();
  }
}
