//VICTOR



//LEAN LA LIBRERIA PRIMERO

//LIBRARY
//https://docs.arduino.cc/libraries/stepper/


#include <AccelStepper.h>





//STEP 1: define direction pin connection(eg. dirPin=3)
//STEP 2: define step pin


//IGNORE
const int stepsFor40Degrees = 22; // Number of steps for 40 degrees
const unsigned long timeFor40Degrees = 1000000; // 1 second in microseconds
const unsigned long delayPerStep = timeFor40Degrees / stepsFor40Degrees; // Delay per step to achieve 40 degrees per second



void setup()
{
    //STEP 3: look up pinMode() function parameters: https://docs.arduino.cc/language-reference/en/functions/digital-io/pinMode/
	//STEP 4:Declare both pins as Outputs using pinMode()
   


}

void loop()
{

    //STEP 5:look up digitalWrite() function parameters : https://docs.arduino.cc/language-reference/en/functions/digital-io/digitalwrite/

	//STEP 6:Set motor direction clockwise using digitalWrite() in HIGH

	//STEP 7: Rotate motor by 40 degrees in 1 second
        //for loop from int i=0 to i=22 
        //(22 is the amount of steps a stepper has to make to spin 40 deg)
            //move stepper using digitalWrite(),the step pin and HIGH
            delayMicroseconds(1000);//ignore
            //stop stepper by using digitalWrite(), the step pin and LOW
            delayMicroseconds(delayPerStep - 1000); // ignore

}