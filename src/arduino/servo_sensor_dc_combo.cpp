#include <Servo.h>
#include <Arduino.h>

Servo myservo1, myservo2, myservo3;  // create servo object to control a servo
#define SERVO1_PIN 7  // Define the pin to which servo1 is connected
#define SERVO2_PIN 8  // Define the pin to which servo2 is connected
#define SERVO3_PIN 12  // Define the pin to which servo3 is connected
int sensor = 13;
int sensor2 = 9;


int pos1 = 0, pos2 = 0, pos3 = 0;
int originalpos1 = 0, originalpos2 = 0, originalpos3 = 0;    // variable to store the servos position

bool left1 = false, right1 = false;
bool left2 = false, right2 = false;
bool left3 = false, right3 = false; 

void setup() { 
  //Serial.begin(9600);
  pinMode(sensor, INPUT);

  myservo1.attach(SERVO1_PIN);  // attaches the servo on pin 31 to servo1
  myservo2.attach(SERVO2_PIN);  // attaches the servo on pin 31 to servo2
  myservo3.attach(SERVO3_PIN);  // attaches the servo on pin 31 to servo3

  Serial.begin(9600);         // Initialize serial communication
}



//servo functions
void servo_1(){
    for (pos1 = 0; pos1 <= 135; pos1 += 5) { 
        myservo1.write(pos1);  
        delay(5);
        Serial.println("Servo1: Left");  
    }
    delay(500);
    for (pos1 = 135; pos1 >= originalpos1; pos1 -= 5) {
        myservo1.write(pos1);
        delay(5);
        Serial.println("Servo1: OriginalPos");
    }

}

void servo_2(){
    for (pos2 = 0; pos2 <= 135; pos2 += 1) { 
        myservo2.write(pos2);  
        delay(5);
        Serial.println("Servo2: Left");  
    }
    delay(500);
    for (pos2 = 135; pos2 >= originalpos2; pos2 -= 1) {  // Fixed from originalpos1 to originalpos2
        myservo2.write(pos2);  // Fixed from myservo1 to myservo2
        delay(5);
        Serial.println("Servo2: OriginalPos");
    }

}

void servo_3(){
    for (pos3 = 0; pos3 <= 135; pos3 += 1) { 

        myservo3.write(pos3);  
        delay(5);
        Serial.println("Servo3: Left");  
    }
    delay(500);
    for (pos3 = 135; pos3 >= originalpos3; pos3 -= 1) {  // Fixed from originalpos1 to originalpos3

        myservo3.write(pos3);  // Fixed from myservo1 to myservo3
        delay(5);
        Serial.println("Servo3: OriginalPos");
    }

}
void loop() {
  /////////////////////////////////
  //sensor


  int state = digitalRead(sensor);
  int state2 = digitalRead(sensor2);
  String material = "none";
  Serial.println(state);

  float volt=analogRead(sensor);
  // Serial.println(volt);

  if ((state == HIGH && state2 == LOW)||(state == LOW && state2 == HIGH) ) {
    Serial.println("state = ");
    Serial.println(state);
    Serial.println("state2 = ");
    Serial.println(state2);

    material = "brass";

    Serial.println("material: ");
    Serial.println(material);

    delay(500); 
  } 

  if (state == HIGH && state2 == HIGH ) {
    Serial.println("state = ");
    Serial.print(state);
    Serial.println("state2 = ");
    Serial.print(state2);

    material = "steel";

    Serial.println("material: ");
    Serial.println(material);

    delay(500); 
  } 

  else if (state2==LOW && state==LOW){
    Serial.println("state = ");
    Serial.println(state);
    Serial.println("state2 = ");
    Serial.println(state2);

    material = "plastic";

    Serial.println("material: ");
    Serial.println(material);

    delay(500);
  }




  /////////////////////////////////////////////////////
  //SERVOS 


  //SERVO 1

  // Sweep from 0 to 180 degrees
  if (material == "steel") {
    servo_1();
  }


  //SERVO 2

  // Sweep from 0 to 180 degrees
  if (material == "brass") {
    servo_2();
    
  }

  //SERVO 3

  // Sweep from 0 to 180 degrees
  if (material == "plastic") {
    servo_3();
    
  }

}


// #include <Servo.h>
// #include <Arduino.h>

// Servo myservo1, myservo2, myservo3;  // create servo object to control a servo
// #define SERVO1_PIN 7  // Define the pin to which servo1 is connected
// #define SERVO2_PIN 8  // Define the pin to which servo2 is connected
// #define SERVO3_PIN 12  // Define the pin to which servo3 is connected
// int sensor = 13;
// int sensor2 = 9;


// int pos1 = 0, pos2 = 0, pos3 = 0;
// int originalpos1 = 0, originalpos2 = 0, originalpos3 = 0;    // variable to store the servos position
// char input;
// bool left1 = false, right1 = false;
// bool left2 = false, right2 = false;
// bool left3 = false, right3 = false; 

// void setup() { 
//   //Serial.begin(9600);
//   pinMode(sensor, INPUT);

//   myservo1.attach(SERVO1_PIN);  // attaches the servo on pin 31 to servo1
//   myservo2.attach(SERVO2_PIN);  // attaches the servo on pin 31 to servo2
//   myservo3.attach(SERVO3_PIN);  // attaches the servo on pin 31 to servo3

//   Serial.begin(9600);         // Initialize serial communication
// }




// void loop() {
//   /////////////////////////////////
//   //sensor


//   int state = digitalRead(sensor);
//   int state2 = digitalRead(sensor2);
//   char material = 'none';
//   Serial.println(state);

//   float volt=analogRead(sensor);
//   // Serial.println(volt);

//   if ((state == HIGH && state2 == LOW)||(state == LOW && state2 == HIGH) ) {
//     Serial.println("state = ");
//     Serial.print(state);
//     Serial.println("state2 = ");
//     Serial.print(state2);

//     material = 'brass';

//     Serial.println("material: ");
//     Serial.print(material);

//     delay(500); 
//   } 

//   if (state == HIGH && state2 == HIGH ) {
//     Serial.println("state = ");
//     Serial.print(state);
//     Serial.println("state2 = ");
//     Serial.print(state2);

//     material = 'steel';

//     Serial.println("material: ");
//     Serial.print(material);

//     delay(500); 
//   } 

//   else if (state2==LOW && state==LOW){
//     Serial.println("state = ");
//     Serial.print(state);
//     Serial.println("state2 = ");
//     Serial.print(state2);

//     material = 'plastic';

//     Serial.println("material: ");
//     Serial.print(material);

//     delay(500);
//   }




//   /////////////////////////////////////////////////////
//   //SERVOS 


//   //SERVO 1

//   // Sweep from 0 to 180 degrees
//   if (material == 'steel') {

//   for (pos1 = 0; pos1 <= 135; pos1+=5) { 
//       myservo1.write(pos1);       // tell servo to go to position in variable 'pos'
//       delay(5);                // waits 15ms for the servo to reach the position
//       Serial.println("Servo1: Left");    // Print "Left" when moving from 0 to 180
//     }
//     delay(500);
//     for(pos1 = 135; pos1 >= originalpos1; pos1-=5){
//       myservo1.write(pos1);
//       delay(5);
//       Serial.println("Servo1: OriginalPos");
//     }
    
//   }


//   //SERVO 2

//   // Sweep from 0 to 180 degrees
//   if (material == 'brass') {

//     for (pos2 = 0; pos2 <= 135; pos2 += 1) { 
//       myservo2.write(pos2);       // tell servo to go to position in variable 'pos'
//       delay(5);                // waits 15ms for the servo to reach the position
//       Serial.println("Servo2: Left");    // Print "red" when moving from 0 to 180
//     }
//     delay(500);
//     for(pos2 = 135; pos2 >= originalpos1; pos2-=1){
//       myservo1.write(pos2);
//       delay(5);
//       Serial.println("Servo1: OriginalPos");
//     }
    
//   }

//   //SERVO 3

//   // Sweep from 0 to 180 degrees
//   if (material == 'plastic') {
  

//     for (pos3 = 0; pos3 <= 135; pos3 += 1) { 
//       myservo3.write(pos3);       // tell servo to go to position in variable 'pos'
//       delay(5);                // waits 15ms for the servo to reach the position
//       Serial.println("Servo3: Left");    // Print "red" when moving from 0 to 180
//     }
//     delay(500);
//     for(pos3 = 135; pos3 >= originalpos3; pos3-=1){
//       myservo1.write(pos1);
//       delay(5);
//       Serial.println("Servo1: OriginalPos");
//     }
    
//   }

// }