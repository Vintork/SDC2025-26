









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
bool left1 = false, right1 = false;
bool left2 = false, right2 = false;
bool left3 = false, right3 = false; 


//STEPPER VARIABLES

//spin more
// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200;
const int stepsFor40Degrees = 50; // Number of steps for 40 degrees
const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second
int count = 10;


//sensor
int sensor = 13;
int sensor2 = 7;






int ballTracking[10] = {0,0,0,0,0,0,0,0,0,0};


void setup() { 

  //sensor
  pinMode(sensor, INPUT);


  //servo
  myservo1.attach(SERVO1_PIN);  // attaches the servo on pin 31 to servo1
  myservo2.attach(SERVO2_PIN);  // attaches the servo on pin 31 to servo2
  myservo3.attach(SERVO3_PIN);  // attaches the servo on pin 31 to servo3
  myservo2.write(0);
  myservo1.write(0);
  myservo3.write(0);
  
  
  //STEPPER 
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

    
}

void sensores(){

      //read sensor input
      int state = digitalRead(sensor);
      int state2 = digitalRead(sensor2);
      Serial.println("state");
      Serial.println(state);
      Serial.println(state2);
      Serial.println("state2");
      delay(1000);

      //pone input en lista
      ballTracking[(count+1)%10]=state;
      
      ballTracking[count%10]+=state2;
}



//STEPPER FUNCTION
void stepper_code(){

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
    count+=1;
    delay(1000); // Wait one second before the next rotation
}


//servo functions

//steel
void servo_1(String material){
    
      if (material=="steel"){

        for (pos1 = 0; pos1 <= 135; pos1 += 5) { 
            myservo1.write(pos1);  
            delay(30);
            Serial.println("Servo1: Left");  
        }
        delay(200);
        for (pos1 = 135; pos1 >= originalpos1; pos1 -= 5) {

            myservo1.write(pos1);
            delay(30);
            Serial.println("Servo1: OriginalPos");
        }
      }

  
}

//brass
void servo_2(String material){
    if (material=="brass"){
      for (pos2 = 0; pos2 <= 135; pos2 += 5) { 
        
          myservo2.write(pos2);  
          delay(30);
          Serial.println("Servo2: Left");  
      }
      delay(200);
      for (pos2 = 135; pos2 >= originalpos2; pos2 -= 5) {  // Fixed from originalpos1 to originalpos2

          myservo2.write(pos2);  // Fixed from myservo1 to myservo2
          delay(30);
          Serial.println("Servo2: OriginalPos");
      }
    }

}

//plastic
void servo_3(String material){
    if (material=="plastic"){
      for (pos3 = 0; pos3 <= 135; pos3 += 5) { 
          
          myservo3.write(pos3);  
          delay(30);
          Serial.println("Servo3: Left");  
      }
      delay(200);
      for (pos3 = 135; pos3 >= originalpos3; pos3 -= 5) {  // Fixed from originalpos1 to originalpos3
          
          myservo3.write(pos3);  // Fixed from myservo1 to myservo3
          delay(30);
          Serial.println("Servo3: OriginalPos");
      }
    }
}


String get_material(int position){
  if (ballTracking[position]==2){
    return "steel";
  }
  else if(ballTracking[position]==1){
    return "brass";
  }
  else if (ballTracking[position]==0){
    return "plastic";
  }
  else{
    return String(ballTracking[position]);
  }
}


void loop() {

  
  
  sensores();//find sensor input
  String material1 = get_material((count-5)%10), material2 = get_material((count-3)%10),material3 = get_material((count-1)%10);//identify materials
  servo_1(material1),servo_2(material2),servo_3(material3);//run servos 
  stepper_code();//move stepper
  

}

/////////

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
bool left1 = false, right1 = false;
bool left2 = false, right2 = false;
bool left3 = false, right3 = false; 


//STEPPER VARIABLES

//spin more
// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 200;
const int stepsFor40Degrees = 50; // Number of steps for 40 degrees
const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second
int count = 10;


//sensor
int sensor = 13;
int sensor2 = 7;






int ballTracking[10] = {0,0,0,0,0,0,0,0,0,0};


void setup() { 

  //sensor
  pinMode(sensor, INPUT);


  //servo
  myservo1.attach(SERVO1_PIN);  // attaches the servo on pin 31 to servo1
  myservo2.attach(SERVO2_PIN);  // attaches the servo on pin 31 to servo2
  myservo3.attach(SERVO3_PIN);  // attaches the servo on pin 31 to servo3
  myservo2.write(0);
  myservo1.write(0);
  myservo3.write(0);
  
  
  //STEPPER 
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

    
}

void sensores(){

      //read sensor input
      int state = digitalRead(sensor);
      int state2 = digitalRead(sensor2);

      delay(1000);

      //pone input en lista
      ballTracking[(count+1)%10]=state;
      ballTracking[count%10]+=state2;
}



//STEPPER FUNCTION
void stepper_code(){

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
    count+=1;
    delay(1000); // Wait one second before the next rotation
}


//servo functions

//steel
void servo_1(String material){
    
      if (material=="steel"){

        for (pos1 = 0; pos1 <= 135; pos1 += 5) { 
            myservo1.write(pos1);  
            delay(30);
            Serial.println("Servo1: Left");  
        }
        delay(200);
        for (pos1 = 135; pos1 >= originalpos1; pos1 -= 5) {

            myservo1.write(pos1);
            delay(30);
            Serial.println("Servo1: OriginalPos");
        }
      }

  
}

//brass
void servo_2(String material){
    if (material=="brass"){
      for (pos2 = 0; pos2 <= 135; pos2 += 5) { 
        
          myservo2.write(pos2);  
          delay(30);
          Serial.println("Servo2: Left");  
      }
      delay(200);
      for (pos2 = 135; pos2 >= originalpos2; pos2 -= 5) {  // Fixed from originalpos1 to originalpos2

          myservo2.write(pos2);  // Fixed from myservo1 to myservo2
          delay(30);
          Serial.println("Servo2: OriginalPos");
      }
    }

}

//plastic
void servo_3(String material){
    if (material=="plastic"){
      for (pos3 = 0; pos3 <= 135; pos3 += 5) { 
          
          myservo3.write(pos3);  
          delay(30);
          Serial.println("Servo3: Left");  
      }
      delay(200);
      for (pos3 = 135; pos3 >= originalpos3; pos3 -= 5) {  // Fixed from originalpos1 to originalpos3
          
          myservo3.write(pos3);  // Fixed from myservo1 to myservo3
          delay(30);
          Serial.println("Servo3: OriginalPos");
      }
    }
}


String get_material(int position){
  if (ballTracking[position]==2){
    return "steel";
  }
  else if(ballTracking[position]==1){
    return "brass";
  }
  else if (ballTracking[position]==0){
    return "plastic";
  }
  else{
    return String(ballTracking[position]);
  }
}


void loop() {

  
  
  sensores();//find sensor input
  String material1 = get_material((count-5)%10), material2 = get_material((count-3)%10),material3 = get_material((count-1)%10);//identify materials
  servo_1(material1),servo_2(material2),servo_3(material3);//run servos 
  stepper_code();//move stepper
  

}


// //ADD STEPPER INCLUDES:

// #include <Servo.h>
// #include <Arduino.h>
// #include <AccelStepper.h>




// //servo
// Servo myservo1, myservo2, myservo3;  // create servo object to control a servo
// #define SERVO1_PIN 6  // Define the pin to which servo1 is connected
// #define SERVO2_PIN 10  // Define the pin to which servo2 is connected
// #define SERVO3_PIN 11  // Define the pin to which servo3 is connected


// //ADD STEPPER VARIABLES HERE
// //STEPPER VARIABLES

// //spin more
// // Define pin connections & motor's steps per revolution
// const int dirPin = 2;
// const int stepPin = 3;
// const int stepsPerRevolution = 200;
// const int stepsFor40Degrees = 22; // Number of steps for 40 degrees
// const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
// const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second


// //sensor
// int sensor = 13;
// int sensor2 = 9;


// int pos1 = 0, pos2 = 0, pos3 = 0;
// int originalpos1 = 0, originalpos2 = 0, originalpos3 = 0;    // variable to store the servos position

// bool left1 = false, right1 = false;
// bool left2 = false, right2 = false;
// bool left3 = false, right3 = false; 

// void setup() { 
//   //Serial.begin(9600);
//   //sensor
//   pinMode(sensor, INPUT);


//   //servo
//   myservo1.attach(SERVO1_PIN);  // attaches the servo on pin 31 to servo1
//   myservo2.attach(SERVO2_PIN);  // attaches the servo on pin 31 to servo2
//   myservo3.attach(SERVO3_PIN);  // attaches the servo on pin 31 to servo3

//   //ADD STEPPER SETUP HERE:

//     //STEPPER SETUP:

//     // Declare pins as Outputs
//     pinMode(stepPin, OUTPUT);
//     pinMode(dirPin, OUTPUT);
    


// }
// //STEPPER FUNCTION
// void stepper_code(){
//   //while true{}
//   // Set motor direction clockwise
//   digitalWrite(dirPin, HIGH);

//   // Rotate motor by 40 degrees in 1 second
//   for (int x = 0; x < stepsFor40Degrees; x++)
//   {
//       digitalWrite(stepPin, HIGH);
//       delayMicroseconds(1000); // Pulse width for the step
//       digitalWrite(stepPin, LOW);
//       delayMicroseconds(delayPerStep - 1000); // Ensure total time for each step matches delayPerStep
//   }
//   //set_count(get_count()+1);
//   delay(1000); // Wait one second before the next rotation
// }


// //servo functions
// void servo_1(){
//       for (pos1 = 0; pos1 <= 135; pos1 += 5) { 

//           myservo1.write(pos1);  
//           delay(50);
//           Serial.println("Servo1: Left");  
//       }
//       delay(500);
//       for (pos1 = 135; pos1 >= originalpos1; pos1 -= 5) {

//           myservo1.write(pos1);
//           delay(50);
//           Serial.println("Servo1: OriginalPos");
//       }

// }

// void servo_2(){
//       for (pos2 = 0; pos2 <= 135; pos2 += 1) { 
        
//           myservo2.write(pos2);  
//           delay(50);
//           Serial.println("Servo2: Left");  
//       }
//       delay(500);
//       for (pos2 = 135; pos2 >= originalpos2; pos2 -= 1) {  // Fixed from originalpos1 to originalpos2

//           myservo2.write(pos2);  // Fixed from myservo1 to myservo2
//           Serial.println("Servo2: OriginalPos");
//       }

// }

// void servo_3(){
//       for (pos3 = 0; pos3 <= 135; pos3 += 1) { 
          
//           myservo3.write(pos3);  
//           delay(50);
//           Serial.println("Servo3: Left");  
//       }
//       delay(500);
//       for (pos3 = 135; pos3 >= originalpos3; pos3 -= 1) {  // Fixed from originalpos1 to originalpos3
          
//           myservo3.write(pos3);  // Fixed from myservo1 to myservo3

//           Serial.println("Servo3: OriginalPos");
//       }

// }





// void loop() {



//   /////////////////////////////////
//   //sensor


//   int state = digitalRead(sensor);
//   int state2 = digitalRead(sensor2);
//   String material = "none";
//   String material1 = "none";
//   String material2 = "none";
//   Serial.println(state);

//   float volt=analogRead(sensor);
//   // Serial.println(volt);
//   delay(1000);
//   if ((state == HIGH && state2 == LOW)||(state == LOW && state2 == HIGH) ) {
//     Serial.println("state = ");
//     Serial.println(state);

//     Serial.println("state2 = ");
//     Serial.println(state2);

//     material2 = "brass";

//     //Serial.println("brass");
//     Serial.println(material);

//     delay(500); 
//   } 

//   if (state == HIGH && state2 == HIGH ) {
//     Serial.println("state = ");
//     Serial.println(state);

//     Serial.println("state2 = ");
//     Serial.println(state2);


//     material1 = "steel";

//     // Serial.println("steel ");
//     Serial.println(material);

//     delay(500); 
//   } 

//   else if (state2==LOW && state==LOW){
//     Serial.println("state = ");
//     Serial.println(state);

//     Serial.println("state2 = ");
//     Serial.println(state2);

//     material = "plastic";

//     Serial.println(material);

//     delay(500);
//   }


//   /////////////////////////////////////////////////////
//   //SERVOS 


//   //SERVO 1

//   // Sweep from 0 to 180 degrees
//   delay(1000);
//   if (material1 == "steel") {
//       Serial.println(material1);
//       servo_1();
//       material1="none";
//   } 

//   // SERVO 2

//   if (material2 == "brass") {
//       Serial.println(material2);
//       servo_2();
//       material2="none";
//   }

//   // SERVO 3
//   if (material == "plastic") {
//     Serial.println(material);
//     //servo_3(count,count+3)
//     //servo_3(count,goal){
//     //while count!=goal{count = get_count()}}
//     //servo logic
//     servo_3();
//     material = "none";
//   }

//   ///////////////////////////
//   //ADD STEPPER CODE HERE
//   ///////////////////
//       //STEPPER CODE:
//   stepper_code();
//   //count+=1

// }