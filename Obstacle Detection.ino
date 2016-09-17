/**************************************************************
* OBSTACLE DETECTION
*
***************************************************************/
#include <Servo.h>

Servo servoRadar;
int angle=0; 

//Define pins for ultrasonic
int const trigPin = 11;
int const echoPin = 12;

//Define pin for led
int const ledPin=7;

void setup() {
  
  servoRadar.attach(10); //The digital pin where the servo is attached
  Serial.begin(9600); //Initialize serie port

  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width

  pinMode(ledPin, OUTPUT); 
}

void loop() {

/***************************************************************
*ULTRA SONIC ROUTINE
****************************************************************/
int duration, distance;
// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;

/***************************************************************
*END ULTRA SONIC ROUTINE
****************************************************************/

Serial.print("Distance:");
Serial.println(distance);

moveRadar(); 

if (distance<=20 && distance >0){
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(ledPin,LOW); 
}

  
  }
 
void moveRadar(){
for (angle = 0; angle <= 180; angle += 1) { // goes from 0 degrees to 180 degree
    servoRadar.write(angle);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 10ms for the servo to reach the position
  }
  
  
for (angle = 180; angle >= 0; angle -= 1)  { // goes from 180 degrees to 0 degrees
    servoRadar.write(angle);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 10ms for the servo to reach the position
    
    }
}
