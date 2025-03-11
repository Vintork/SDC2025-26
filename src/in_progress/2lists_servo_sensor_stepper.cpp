
//THIS FILE CONTAINS SERVOS IN ORDER: BRASS->STEEL->PLASTIC
//PLASTIC ALWAYS MOVES NO MATTER WHAT 
//TWO LISTS 



//NO SERIAL MONITER
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
int sensorTracking[10] = {0,0,0,0,0,0,0,0,0,0};
int sensorTracking_2[10] = {0,0,0,0,0,0,0,0,0,0};


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
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);   
}

void sensores(){
    delay(500);

    //read sensor input
    int state = digitalRead(sensor);
    int state2 = digitalRead(sensor2);

    //insert sensor input into lists
    sensorTracking[(count+1)%10]=state;
    sensorTracking_2[count%10]=state2;

    delay(1000);
}



//STEPPER FUNCTION
void stepper_code(){
    
    // Set motor direction clockwise
    digitalWrite(dirPin, HIGH);

    // Rotate motor by 40 degrees in 1 second
    for (int x =stepsFor40Degrees; x > 0; x--)
    {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000); // Pulse width for the step
        digitalWrite(stepPin, LOW);
        delayMicroseconds(delayPerStep - 1000); // Ensure total time for each step matches delayPerStep
    }
    count+=1;
}


//servo functions

//plastic
void servo_1(){
    
        //move clockwise
        for (pos1 = 0; pos1 <= 135; pos1 += 5) { 
            myservo1.write(pos1);  
            delay(30); 
        }

        delay(200);

        //move back 
        for (pos1 = 135; pos1 >= originalpos1; pos1 -= 5) {
            myservo1.write(pos1);
            delay(30);
        }


  
}

//steel
void servo_2(String material){

    if (material=="steel"){

      for (pos2 = 0; pos2 <= 135; pos2 += 5) { 
          myservo2.write(pos2);  
          delay(30);  
      }

      delay(200);

      for (pos2 = 135; pos2 >= originalpos2; pos2 -= 5) {  // Fixed from originalpos1 to originalpos2
          myservo2.write(pos2);  // Fixed from myservo1 to myservo2
          delay(30);
      }
    }

}

//brass
void servo_3(String material){

    if (material=="brass"){

      for (pos3 = 0; pos3 <= 135; pos3 += 5) { 
          myservo3.write(pos3);  
          delay(30); 
      }

      delay(200);

      for (pos3 = 135; pos3 >= originalpos3; pos3 -= 5) {  // Fixed from originalpos1 to originalpos3
          myservo3.write(pos3);  // Fixed from myservo1 to myservo3
          delay(30);
      }
    }
}


String get_material(int position){
  if (sensorTracking[position]==1 && sensorTracking_2[position]==1){

    return "steel";

  }else if(sensorTracking[position]==1 || sensorTracking_2[position]==1){

    return "brass";

  }else{

    return "plastic";

  }
}


void loop() {

  sensores();//find sensor input
  String material_steel2 = get_material((count-3)%10),material_brass3 = get_material((count-1)%10);//identify materials
  servo_1(),servo_2(material_steel2),servo_3(material_brass3);//run servos 
  stepper_code();//move stepper
  delay(1000);
  

}































//WITH SERIAL MONITER


// //twp lists
// #include <Servo.h>
// #include <Arduino.h>
// #include <AccelStepper.h>


// //1. VERIFICA QUE UN VALOR DE LA LISTA PUEDA llegar a 2
// //2. verifica que este añadiendo y cogiendo de donde es en la lista

// //servo
// Servo myservo1, myservo2, myservo3;  // create servo object to control a servo
// #define SERVO1_PIN 9  // Define the pin to which servo1 is connected
// #define SERVO2_PIN 10  // Define the pin to which servo2 is connected
// #define SERVO3_PIN 11  // Define the pin to which servo3 is connected
// int pos1 = 0, pos2 = 0, pos3 = 0;
// int originalpos1 = 0, originalpos2 = 0, originalpos3 = 0;    // variable to store the servos position
// bool left1 = false, right1 = false;
// bool left2 = false, right2 = false;
// bool left3 = false, right3 = false; 


// //STEPPER VARIABLES

// //spin more
// // Define pin connections & motor's steps per revolution
// const int dirPin = 2;
// const int stepPin = 3;
// const int stepsPerRevolution = 200;
// const int stepsFor40Degrees = 50; // Number of steps for 40 degrees
// const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
// const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second
// int count = 10;


// //sensor
// int sensor = 13;
// int sensor2 = 7;






// int sensorTracking[10] = {0,0,0,0,0,0,0,0,0,0};
// int sensorTracking_2[10] = {0,0,0,0,0,0,0,0,0,0};

// void setup() { 

//   //sensor
//   pinMode(sensor, INPUT);


//   //servo
//   myservo1.attach(SERVO1_PIN);  // attaches the servo on pin 31 to servo1
//   myservo2.attach(SERVO2_PIN);  // attaches the servo on pin 31 to servo2
//   myservo3.attach(SERVO3_PIN);  // attaches the servo on pin 31 to servo3
//   myservo2.write(0);
//   myservo1.write(0);
//   myservo3.write(0);
  
  
//   //STEPPER 
//   // Declare pins as Outputs
//   pinMode(stepPin, OUTPUT);
//   pinMode(dirPin, OUTPUT);

    
// }

// void sensores(){

//       //read sensor input
//       int state = digitalRead(sensor);
//       int state2 = digitalRead(sensor2);
//       // Serial.println("state");
//       // Serial.println(state);
//       // Serial.println("state2");
//       // Serial.println(state2);

      

//       //pon input en lista
//       // int reference[10]=sensorTracking;
//       // int reference2[10]=sensorTracking_2;
//       Serial.println("before:");
//       Serial.print("list1: ");
//       for(int i = 0; i < 10; i++)
//       {
//         Serial.print(sensorTracking[i]);
//       }
//       Serial.println(" ");
//       Serial.print("list2: ");
//       for(int i = 0; i < 10; i++)
//       {
//         Serial.print(sensorTracking_2[i]);
//       }
//       Serial.println(" ");
    
//       // Serial.println((count+1)%10);
//       // Serial.println(sensorTracking[(count+1)%10]);
//       // Serial.println(count%10);
//       // Serial.println(sensorTracking_2[count%10]);

//       sensorTracking[(count+1)%10]=state;
//       sensorTracking_2[count%10]=state2;

//       // Serial.println("after:");
//       // Serial.println((count+1)%10);
//       // Serial.println(sensorTracking[(count+1)%10]);
//       // Serial.println(count%10);
//       // Serial.println(sensorTracking_2[count%10]);
//       Serial.println("after");
//       Serial.print("list1: ");
//       for(int i = 0; i < 10; i++)
//       {
//         Serial.print(sensorTracking[i]);
//       }
//       Serial.println(" ");
//       Serial.print("list2: ");
//       for(int i = 0; i < 10; i++)
//       {
//         Serial.print(sensorTracking_2[i]);
//       }
//       Serial.println(" ");

//       // Serial.println("difference");
//       // Serial.println(sensorTracking-reference);
//       // Serial.println(sensorTracking_2-reference2);
//       delay(1000);
// }



// //STEPPER FUNCTION
// void stepper_code(){
    
//     // Set motor direction clockwise
//     digitalWrite(dirPin, HIGH);

//     // Rotate motor by 40 degrees in 1 second
//     for (int x = 0; x < stepsFor40Degrees; x++)
//     {
//         digitalWrite(stepPin, HIGH);
//         delayMicroseconds(1000); // Pulse width for the step
//         digitalWrite(stepPin, LOW);
//         delayMicroseconds(delayPerStep - 1000); // Ensure total time for each step matches delayPerStep
//     }
//     count+=1;
//     //delay(1000); // Wait one second before the next rotation
// }


// //servo functions

// //steel
// void servo_1(){
    
  
//         Serial.println("Servo1: Left-> plastic"); 
//         for (pos1 = 0; pos1 <= 135; pos1 += 5) { 
//             myservo1.write(pos1);  
//             delay(30);
//             // Serial.println("Servo1: Left");  
//         }
//         delay(200);
//         Serial.println("Servo1: OriginalPos->plastic");
//         for (pos1 = 135; pos1 >= originalpos1; pos1 -= 5) {

//             myservo1.write(pos1);
//             delay(30);
//             // Serial.println("Servo1: OriginalPos");
//         }


  
// }

// //brass
// void servo_2(String material){
//     if (material=="steel"){
//       Serial.println("Servo2: Left->steel");  
//       for (pos2 = 0; pos2 <= 135; pos2 += 5) { 
        
//           myservo2.write(pos2);  
//           delay(30);
//           // Serial.println("Servo2: Left");  
//       }
//       delay(200);
//       Serial.println("Servo2: OriginalPos->steel");
//       for (pos2 = 135; pos2 >= originalpos2; pos2 -= 5) {  // Fixed from originalpos1 to originalpos2

//           myservo2.write(pos2);  // Fixed from myservo1 to myservo2
//           delay(30);
//           // Serial.println("Servo2: OriginalPos");
//       }
//     }else{
//     Serial.print("steel servo didnt move. material= "); 
//     Serial.println(material);      
//     }


// }

// //plastic
// void servo_3(String material){
//     if (material=="brass"){
//       Serial.println("Servo3: Left->brass"); 
//       for (pos3 = 0; pos3 <= 135; pos3 += 5) { 
          
//           myservo3.write(pos3);  
//           delay(30);
//           // Serial.println("Servo3: Left");  
//       }
//       delay(200);
//       Serial.println("Servo3: OriginalPos->brass");
//       for (pos3 = 135; pos3 >= originalpos3; pos3 -= 5) {  // Fixed from originalpos1 to originalpos3
          
//           myservo3.write(pos3);  // Fixed from myservo1 to myservo3
//           delay(30);
//           // Serial.println("Servo3: OriginalPos");
//       }
//     }else{
//       Serial.print("brass servo didnt move. material= "); 
//       Serial.println(material);
//     }
// }


// String get_material(int position){
//   if (sensorTracking[position]==1 && sensorTracking_2[position]==1){
//     // Serial.println("getmaterial returned STEEL");
//     return "steel";
//   }
//   else if(sensorTracking[position]==1 || sensorTracking_2[position]==1){
//     // Serial.println("getmaterial returned BRASS");
//     return "brass";
//   }
//   else if (sensorTracking[position]==0 && sensorTracking_2[position]==0){
//     // Serial.println("getmaterial returned PLASTIC");
//     return "plastic";
//   }
//   else{
//     // Serial.println("getmaterial returned SOMETHING ELSE");
//     return String(sensorTracking[position]);
//   }
// }


// void loop() {

  
//   Serial.println("count");
//   Serial.println(count);
//   sensores();//find sensor input
//   String material_s1 = get_material((count-5)%10), material_b2 = get_material((count-3)%10),material_p3 = get_material((count-1)%10);//identify materials
//   Serial.print("indexes: ");
//   Serial.print((count-5)%10);
//   Serial.print(" ");
//   Serial.print((count-3)%10);
//   Serial.print(" ");
//   Serial.println((count-1)%10);

//   Serial.print("material_p1: ");
//   Serial.println(material_s1);
//   Serial.print("material_s2: ");
//   Serial.println(material_b2);
//   Serial.print("material_b3: ");
//   Serial.println(material_p3);


//   servo_1(),servo_2(material_b2),servo_3(material_p3);//run servos 
//   stepper_code();//move stepper
//   Serial.println(" ");
//   Serial.println(" ");
//   delay(1000);
  

// }