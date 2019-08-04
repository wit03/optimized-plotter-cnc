#include <Servo.h>
#include <AFMotor.h>

#define LINE_BUFFER_LENGTH 512

char STEP = INTERLEAVE ;

const int stepsPerRevolution = 20; 

//set your servo pin (Z axis)
const int penServoPin = 10;

Servo penServo;

// Initialize steppers for X- and Y-axis using this Arduino pins for the L293D H-bridge
AF_Stepper myStepperY(stepsPerRevolution,1);            
AF_Stepper myStepperX(stepsPerRevolution,2);  

/*
Calibration Code will helps you to calibrate your CNC just follow this step:
  1. Set your servo pin.
  2. Upload the code and it will draw a box.
  3. Try to run this code and look and your X and Y axis 
  4. If it's runs to the end of axis just leave it there, If it's not increase the step below (usually by 20) untill to goes to the end. 
  5. Measure the width and height of the box and divide the number of steps with it
  6. you will get the steps per mil value, Just put in in the main code.
*/

void setup() {
  Serial.begin( 9600 );
  penServo.attach(penServoPin);
  penServo.write(75);
  delay(100);
  myStepperX.setSpeed(50);
  myStepperY.setSpeed(50); 
  myStepperX.step(560, FORWARD, STEP);
  myStepperY.step(560, FORWARD, STEP);
  myStepperX.step(560, BACKWARD, STEP);
  myStepperY.step(560, BACKWARD, STEP);  
  penServo.write(115);
  myStepperX.release();
  myStepperY.release();
}

void loop() 
{
  
  
}
