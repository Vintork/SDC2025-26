// Pin definitions for the color sensor
#include <Arduino.h>
#define S0 40
#define S1 42
#define S2 44
#define S3 46
#define sensorOut 26

// LED pin definitions
#define redLED 33
#define blueLED 35
#define whiteLED 31

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  // Set LED pins as output
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);

  // Set color sensor pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // Read Red color
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);

  // Read Green color
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);

  // Read Blue color
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  // Output the frequency values for debugging
  Serial.print("R= ");
  Serial.print(redFrequency);
  Serial.print(" G= ");
  Serial.print(greenFrequency);
  Serial.print(" B= ");
  Serial.println(blueFrequency);

  // Color detection logic
  // if (redFrequency < blueFrequency && redFrequency < greenFrequency) {
  //   turnOnLED(redLED);
  // } else if (blueFrequency < redFrequency && blueFrequency < greenFrequency) {
  //   turnOnLED(blueLED);
 // } else if (greenFrequency <= redFrequency && greenFrequency <= blueFrequency) {
  //  }  else if(redFrequency <= 35 || greenFrequency <= 35 || blueFrequency <= 35){
   // turnOnLED(whiteLED); // Assuming white is closer to green in terms of frequency
     if (redFrequency >= 90 && greenFrequency >= 45 && blueFrequency >= 30) {

         turnOnLED(blueLED);
    Serial.println("blue");
  } else if (redFrequency >= 30 && greenFrequency >= 100 && blueFrequency >= 70){
  //  turnOnLED(whiteLED);
  //    Serial.println("white");
         Serial.println("red");
    turnOnLED(redLED);

  } else {
    Serial.println("white");
    turnOnLED(whiteLED);
    //turnOffAllLEDs();
  }
   Serial.println(" ");

  delay(200);
}

void turnOnLED(int ledPin) {
  // Turn off all LEDs first
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(whiteLED, LOW);
  
  // Turn on the corresponding LED
  digitalWrite(ledPin, HIGH);
}

void turnOffAllLEDs() {
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(whiteLED, LOW);
}