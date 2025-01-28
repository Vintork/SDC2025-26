#include <Servo.h>

//innecesario para arduino ide, essencial para vscode:
#include <Arduino.h> 


//DC MOTOR A
int DC_enA = 1;
int DC_in1 = 2; 
int DC_in2 = 3;

//inductive sensor
int sensor = 4;
int state;

//servo
Servo myservo1, myservo2, myservo3;  // create servo object to control a servo
#define SERVO1_PIN 5  // Define the pin to which servo1 is connected
#define SERVO2_PIN 6  // Define the pin to which servo2 is connected
#define SERVO3_PIN 7  // Define the pin to which servo3 is connected
int pos1 = 0, pos2 = 0, pos3 = 0;    // variable to store the servos position
char input;
bool left1 = false, right1 = false;
bool left2 = false, right2 = false;
bool left3 = false, right3 = false; 




////////////////////////////////////////////////////////////////
//DC MOTORS CODE
////////////////////////////////////////////////////////////////
void setup() {
	// Set all the motor control pins to outputs
	pinMode(DC_enA, OUTPUT);
	pinMode(DC_in1, OUTPUT);
	pinMode(DC_in2, OUTPUT);

}

void loop() {
	speedControl();
	delay(1000);
}

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(DC_enA, 255);

	// Turn on motor A & B
	digitalWrite(DC_in1, HIGH);
	digitalWrite(DC_in2, LOW);

	delay(2000);
	

}

// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors
	digitalWrite(DC_in1, LOW);
	digitalWrite(DC_in2, HIGH);

	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(DC_enA, i);

	}

}




/////////////////////////////////////////////////////////
//inductive sensor
/////////////////////////////////////////////////////////
void setup() { 
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() {
  state = digitalRead(sensor);
  Serial.println(state);
  float volt=analogRead(sensor);//*(5.0/1023.0);
  Serial.println(volt);
  if (state == HIGH) {
    Serial.println("metal");
    delay(500);
    
  } 
  else if (state == LOW) {
    Serial.println("No Metal");
    delay(500);
  }
  else{
    Serial.println("Matate");
    delay(500);
  }
}









/////////////////////////////////////////////////////////
//servos
/////////////////////////////////////////////////////////



void setup() {
  myservo1.attach(SERVO1_PIN);  // attaches the servo on pin 31 to servo1
  myservo2.attach(SERVO2_PIN);  // attaches the servo on pin 31 to servo2
  myservo3.attach(SERVO3_PIN);  // attaches the servo on pin 31 to servo3

  Serial.begin(9600);         // Initialize serial communication
}

void loop() {
    if (Serial.available() > 0) {
      input = Serial.read();  // Read the incoming byte
      
    }

  //SERVO 1

  // Sweep from 0 to 180 degrees
  //if metal detected
  if ((state == HIGH || input == 'q') && left1 == false) {
    left1 = true;
    right1 = false;

    for (pos1 = 0; pos1 <= 180; pos1 += 1) { 
      myservo1.write(pos1);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("Servo1: Left");    // Print "Left" when moving from 0 to 180
    }
  }
  else if ((state == LOW || input == 'w')&& right1 == false) { 
    right1 = true;
    left1 = false;
    // Sweep from 180 to 0 degrees
    for (pos1 = 180; pos1 >= 0; pos1 -= 1) {
      myservo1.write(pos1);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("Servo1 = Right");   // Print "Rigth" when moving from 180 to 0
    }
 }

  //SERVO 2

  // Sweep from 0 to 180 degrees
  if ((input == 'A' || input == 'a') && left2 == false) {
    left2 = true;
    right2 = false;

    for (pos2 = 0; pos2 <= 180; pos2 += 1) { 
      myservo2.write(pos2);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("Servo2: Left");    // Print "red" when moving from 0 to 180
    }
  }
  else if ((input == 'S' || input == 's')&& right2 == false) { 
    right2 = true;
    left2 = false;
    // Sweep from 180 to 0 degrees
    for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
      myservo2.write(pos2);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("Servo2 = Right");   // Print "blue" when moving from 180 to 0
    }
 }

  //SERVO 3

  // Sweep from 0 to 180 degrees
  if ((input == 'Z' || input == 'z') && left3 == false) {
    left3 = true;
    right3 = false;

    for (pos3 = 0; pos3 <= 180; pos3 += 1) { 
      myservo3.write(pos3);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("Servo3: Left");    // Print "red" when moving from 0 to 180
    }
  }
  else if ((input == 'X' || input == 'x')&& right3 == false) { 
    right3 = true;
    left3 = false;
    // Sweep from 180 to 0 degrees
    for (pos3 = 180; pos3 >= 0; pos3 -= 1) {
      myservo3.write(pos3);       // tell servo to go to position in variable 'pos'
      delay(5);                // waits 15ms for the servo to reach the position
      Serial.println("Servo3 = Right");   // Print "blue" when moving from 180 to 0
    }
 }

}
