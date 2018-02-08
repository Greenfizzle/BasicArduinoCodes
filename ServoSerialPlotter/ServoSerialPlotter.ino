#include <Servo.h>    //Calls Servo.h and includes it. You should already have it.

Servo myservo;      //creates servo called myservo

int sensorPin = A0;    // Sensor
 
void setup() {
  
  myservo.attach(9);    //the servo is attached to digital (pwm) 9
  
  Serial.begin(9600);   // begin the serial monitor @ 9600 baud

 
}
 
void loop() {
  int sensorValue = analogRead(sensorPin);    // read the value from the sensor:
  sensorValue = map(sensorValue, 0, 1023, 0, 179); //makes servo 180 degrees
 
  Serial.println(sensorValue);
  Serial.print(" ");
  
  //loop with perameters
  if (sensorValue <=50)
    myservo.write(0);
  if (sensorValue >=50)
    myservo.write(180);
 
  delay(20);


  
}
