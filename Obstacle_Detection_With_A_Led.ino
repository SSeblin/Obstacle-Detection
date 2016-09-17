/**************************************************************************************
 * OBSTACLE DETECTION WITH A LED
 **************************************************************************************/

#include <Servo.h>. 
// Defines Trig and Echo pins of the Ultrasonic Sensor
const int trigPin = 11;
const int echoPin = 12;
// Variables for the duration and the distance
long duration;
int distance;
// Variable for the LED output
int const ledPin=7;


Servo servoRadar; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT); 

  servoRadar.attach(10); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 0 to 170 degrees
  for(int i=0;i<=170;i++){  
  servoRadar.write(i);
  delay(10);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
if (distance<20){
    digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(ledPin,LOW); 
}
  
  }
  // Repeats the previous lines from 170 to 0 degrees
  for(int i=170;i>0;i--){  
  servoRadar.write(i);
  delay(10);
  distance = calculateDistance();

  if (distance<20){
    digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(ledPin,LOW); 
}
  
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
