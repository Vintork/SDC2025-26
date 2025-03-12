
//MARCOS

#include <Servo.h>

//innecesario para arduino ide, essencial para vscode:
#include <Arduino.h>



//STEP 1:declare enableA pin (eg. enA=5)
//STEP 2:declare input 1 pin
//STEP 3:declare input 2 pin
//STEP 4:declare max speed variable & set to a number

void setup() {

    //STEP 5: look up pinMode() function parameters: https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/
	//STEP 6:Declare all three pins as Outputs using pinMode()


    //STEP 7:look up digitalWrite() function parameters : https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalwrite/
	//STEP 8:turn off motors using digitalWrite() in LOW for both inputs

}


//STEP 9:Make function called void directionControl(){}

  //STEP 9a:Set motor direction
    //use digitalWrite() to set one input as HIGH and the other as LOW
    //delay



//STEP 10:Make function called void speedControl(){}

  //STEP 10a: Reverse motor direction
      //use digitalWrite() to set one input as HIGH and the other as LOW. reverse the values used in the direction control function
      


  //STEP 10b: Accelerate from zero to maximum speed with a small delay
    //for loop from i=100 to i=max speed variable
    //look up analogWrite() function parameters : https://docs.arduino.cc/language-reference/en/functions/analog-io/analogWrite/
    //use analogWrite() with enableA pin and i value




void loop() {
    //STEP 11:call direction control function
    //STEP 12:call speed control function
}