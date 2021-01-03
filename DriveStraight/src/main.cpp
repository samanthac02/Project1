/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       samantha                                                  */
/*    Created:      Sat Jan 02 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Inertial5            inertial      5               
// ForwardLeft          motor         1               
// ForwardRight         motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

float currentX;
float currentY;

float x;
float y;

float calculateDistance(float targetX, float targetY) {
  float changeInX = fabs(targetX - currentX);
  float changeInY = fabs(targetY - currentY);
  float distance = sqrt((changeInX * changeInX) + (changeInY * changeInY));
  return distance;
}

float calculateAngle(float targetX, float targetY) {
  float changeInX = fabs(targetX - currentX);
  float changeInY = fabs(targetY - currentY);
  float angle = tan(changeInY / changeInX);
  return angle;
}

float getInertial() {
  return Inertial5.rotation(degrees);
}

void resetInertial() {
  Inertial5.setRotation(0, degrees);
}

void drive(int leftSpeed, int rightSpeed, int waitTime = 50) {
  ForwardLeft.spin(forward, leftSpeed, percent);
  ForwardRight.spin(forward, rightSpeed, percent);
  BackLeft.spin(forward, leftSpeed, percent);
  BackRight.spin(forward, rightSpeed, percent);

  wait(waitTime, msec);
}

void turn(float target) {
  float kP = 1;
  float kI;
  float kD = 1;
  float threshold = 5;

  resetInertial();

  float error = target;
  float previousError = error;
  float timeStep = 20;
  float speed;
  float counter = 0;

  while (counter < 10) {
    previousError = error;
    error = target - getInertial();
    speed = (kP * error) + (error - previousError) * timeStep * kD;

    drive(speed, speed, timeStep);

    if (fabs(error) < threshold) {
      counter ++;
    } else {
      counter = 0;
    }
  }
}

void driveStraight(float target) {
  ForwardLeft.setPosition(0, degrees);
  ForwardRight.setPosition(0, degrees);
  BackLeft.setPosition(0, degrees);
  BackRight.setPosition(0, degrees);

  float kP = 1;
  float kI;
  float kD = 1;
  float threshold = 5;

  float error = target;
  float previousError = error;
  float timeStep = 20;
  float speed;
  float counter = 0;
}

void driveToPosition() {
  x = 10;
  y = 10;

  turn(calculateAngle(x, y));
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}
