
#include <Arduino.h> 



// int sensor = 12;

// void setup() { 
//   Serial.begin(9600);
//   pinMode(sensor, INPUT);
// }

// void loop() {
//   int state = digitalRead(sensor);
//   Serial.println(state);
//   float volt=analogRead(sensor);//*(5.0/1023.0);
//   Serial.println(volt);
//   if (state == HIGH) {
//     Serial.println("metal");
//     delay(500);
    
//   } 
//   else if (state == LOW) {
//     Serial.println("No Metal");
//     delay(500);
//   }
//   else{
//     Serial.println("Matate");
//     delay(500);
//   }
//}
int sensor = 13;
int sensor2 = 9;

void setup() { 
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop() {
  int state = digitalRead(sensor);
  int state2 = digitalRead(sensor2);
  Serial.println(state);

  float volt=analogRead(sensor);
  Serial.println(volt);

  if (state == HIGH && state2 == HIGH) {
    Serial.println("Steel is detected");

    delay(500); 
  } 
  else if (state == HIGH && state2 == LOW) {
    Serial.println("Brass is detected");
    delay(500);
    }
  else{
    Serial.println("Plastic");
    delay(500);
  }
}