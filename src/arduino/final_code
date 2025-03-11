//steppper counterclockwise



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
const int stepsFor40Degrees = 55; // Number of steps for 40 degrees
const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second
int count = 10;


//sensor
int sensor = 13;
int sensor2 = 7;
int sensorTracking[10] = {0,0,0,0,0,0,0,0,0,0};
int sensorTracking_2[10]={0,0,0,0,0,0,0,0,0,0};


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
  count=10;
}

void sensores(){
    delay(500);



    //read sensor input
    int state = digitalRead(sensor);
    // int state=Serial.read();
    int state2 = digitalRead(sensor2);

      Serial.println("state");
      Serial.println(state);
      Serial.println("state2");
      Serial.println(state2);

      

      //pon input en lista
      Serial.println("before:");
      Serial.print("list1: ");
      for(int i = 0; i < 10; i++)
      {
        Serial.print(sensorTracking[i]);
      }
      Serial.println(" ");
      Serial.print("list2: ");
      for(int i = 0; i < 10; i++)
      {
        Serial.print(sensorTracking_2[i]);
      }
      Serial.println(" ");
    


    //insert sensor input into lists
    sensorTracking[(count+1)%10]=state;
    sensorTracking_2[count%10]=state2;
      Serial.println("after:");

      Serial.print("list1: ");
      for(int i = 0; i < 10; i++)
      {
        Serial.print(sensorTracking[i]);
      }
      Serial.println(" ");
      Serial.print("list2: ");
      for(int i = 0; i < 10; i++)
      {
        Serial.print(sensorTracking_2[i]);
      }
      Serial.println(" ");



    delay(1000);
}



//STEPPER FUNCTION
void stepper_code(){
    
    // Set motor direction clockwise
    digitalWrite(dirPin, LOW);

    // Rotate motor by 40 degrees in 1 second
    // for (int x =stepsFor40Degrees; x > 0; x--)
    // {
    //     digitalWrite(stepPin, HIGH);
    //     delayMicroseconds(1000); // Pulse width for the step
    //     digitalWrite(stepPin, LOW);
    //     delayMicroseconds(delayPerStep - 1000); // Ensure total time for each step matches delayPerStep
    // }
    // for (int x =0; x < stepsFor40Degrees; x++)
    // {
    //     digitalWrite(stepPin, HIGH);
    //     delayMicroseconds(1000); // Pulse width for the step
    //     digitalWrite(stepPin, LOW);
    //     delayMicroseconds(delayPerStep - 1000); // Ensure total time for each step matches delayPerStep
    // }
    for (int x = 0; x < stepsFor40Degrees; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(delayPerStep - 1000);
      delay(20);
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
  Serial.print("count: ");
  Serial.println(count);

    sensores();//find sensor input
    String material_steel2 = get_material((count-3)%10),material_brass3 = get_material((count-1)%10);//identify materials

  Serial.print("indexes: ");
  Serial.print((count-5)%10);
  Serial.print(" ");
  Serial.print((count)%10);
  Serial.print(" ");
  Serial.println((count)%10);

  Serial.print("material_steel2: ");
  Serial.println(material_steel2);
  Serial.print("material_brass3: ");
  Serial.println(material_brass3);



  
  servo_1(),servo_2(material_steel2),servo_3(material_brass3);//run servos 
  stepper_code();//move stepper
  delay(1000);

  Serial.println(" ");
  Serial.println(" ");

  

}
