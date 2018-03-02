#include <Stepper.h> // Include the header file

// change this to the number of steps on your motor
#define STEPS 32

// create an instance of the stepper class using the steps and pins
Stepper stepper1(STEPS, 8, 10, 9, 11);
Stepper stepper2(STEPS, 3, 5, 4, 6);

int Pval1 = 0;
int joyVal1 = 0;
int Pva2 = 0;
int joyVal2 = 0;

void setup() {
  Serial.begin(9600);
  stepper1.setSpeed(500);
  stepper2.setSpeed(500);
}

void loop() {

joyVal1 = (analogRead(A0));
joyVal2 = (analogRead(A1));

if (joyVal1>515)
  stepper1.step(5);
if (joyVal1<505)
  stepper1.step(-5);

if (joyVal2>525)
  stepper2.step(5);
if (joyVal2<520)
  stepper2.step(-5);


Serial.println(Pval1); //for debugging
}
