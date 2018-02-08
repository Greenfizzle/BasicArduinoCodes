#include <Stepper.h> // Include the header file

// change this to the number of steps on your motor
#define STEPS 32

// create an instance of the stepper class using the steps and pins
Stepper stepper1(STEPS, 34, 36, 35, 37); // connected to digital pins 34, 36, ,35, 37
Stepper stepper2(STEPS, 30, 32, 31, 33); // connected to digital pins 30, 32, 31,33

// create x and y direction instances for joystick
int joyVal1 = 0;
int joyVal2 = 0;

void setup() 
{
  Serial.begin(9600);
  stepper1.setSpeed(500);
  stepper2.setSpeed(500);
}

void loop() 
{
 joyVal1 = (analogRead(A0)); //reads the value of the joystick (one direction)
 joyVal2 = (analogRead(A1)); //reads the value of the joystick (one direction)

 if (joyVal1>600)   //if the value of the joystick is greater than 600 
  stepper1.step(5);   //move the motor 5 steps
 if (joyVal1<400)   // if the value of the joystick os less than 400 
  stepper1.step(-5);    //move that motor 5 steps in the opposite direction

 if (joyVal2>600)   //if the value of the joystick is greater than 600 
  stepper2.step(5);   //move the motor 5 steps
 if (joyVal2<400)   //if the value of the joystick os less than 400
  stepper2.step(-5);    //move that motor 5 steps in the opposite direction
}
