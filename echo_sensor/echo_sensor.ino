// defines pins numbers
const int trigPin = 8;
const int echoPin = 7;
#include <Servo.h>

// defines variables
long duration;
int distance;

Servo myservo;
//Servo myservo2;

void setup() 
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
myservo.attach(9);
//myservo2.attach(5);
}

void loop() 
{

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

myservo.write(90);
//myservo2.write(0);

delay(2);

if (distance<=15)
{
  myservo.write(0);
  //myservo2.write(70);
}

}
