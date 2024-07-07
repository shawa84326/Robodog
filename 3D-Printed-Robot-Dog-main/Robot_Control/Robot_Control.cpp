/* Before using this, go to the Serial Settings
  tab in the Maestro Control Center and apply these settings:

   Serial mode: UART, fixed baud rate
   Baud rate: 9600
   CRC disabled

  Set these for all Servos

   Minimum position in ms: 992
   Maximum position in ms: 2000
   Neutral position in ms: 1500

  Be sure to click "Apply Settings" after making any changes.
*/


#include "PololuMaestro.h"
#include <SoftwareSerial.h>
#include "Robot_Control.h"

#define maestroSerial SERIAL_PORT_HARDWARE_OPEN

MiniMaestro maestro(maestroSerial); //if using the Maestro mini controller

//**GLOBAL VARIABLES************************************************************************
int servo[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //Servo servo channels on maestro
float posnorm[12]; //normal position
String dir[12] = {"-", "+", "+", "+", "-", "-", "+", "+", "+", "-", "-", "-"}; //ms direction when angle increases ("+" means that when the angle increases the ms value goes up)
float target[12]; //relative target value
float speed[12]; //speed
float K = 850 / 90; //ms per degree constant value (differs by servo)

float a = 110; //length of both links (in mm)
float X[4]; //X coordinate
float Y[4]; //Y coordinate
float Z[4]; //Z coordinate

float theta1[4]; //theta 1
float theta2[4]; //theta 2
float theta3[4]; //theta 3


//**FUNCTIONS***************************************************************************************

void moveTo(float target0, float target1, float target2, float target3, float target4, float target5,
            float target6, float target7, float target8, float target9, float target10, float target11) {

  //transfers the "target" variable to the "target" array
  target[0] = target0, target[1] = target1, target[2] = target2, target[3] = target3;
  target[4] = target4, target[5] = target5, target[6] = target6, target[7] = target7;
  target[8] = target8, target[9] = target9, target[10] = target10, target[11] = target11;

  for (int i = 0; i < 12; i++) { //for loop that runs 12 times
    if (target[i] != NR) { //if target is not NR "not running" then compute absolute target and run
      //converts degree target to ms target

      if (dir[i] == "+") { //if direction is +
        target[i] = posnorm[i] + K * (target[i] - 90); //converts angle target to ms target
      }
      else if (dir[i] == "-") { //if direction is -
        target[i] = posnorm[i] - K * (target[i] - 90); //converts angle target to ms target
      }
      maestro.setTarget(servo[i], target[i]); //moves Servo to that target
    }
  }
}

float toDeg(float rad) { //converts radians to degrees
  return (rad * 180) / PI;
}

float getTheta1(float X, float Y, float Z) { //returns theta 1
  return 90 - atan(-X / sqrt(pow(Y, 2) + pow(Z, 2))) * (180 / PI) - acos(sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2)) / (2 * a)) * (180 / PI);
}

float getTheta2(float X, float Y, float Z) { //returns theta 2
  return 90 - acos(1 - ((pow(X, 2) + pow(Y, 2) + pow(Z, 2)) / (2 * pow(a, 2)))) * (180 / PI) + getTheta1(X, Y, Z);
}

float getTheta3(float X, float Y, float Z) { //returns theta 3
  return 90 + asin(Z / sqrt(pow(Z, 2) + pow(Y, 2))) * (180 / PI);
}


//**LIBRARY CONTENT***************************************************************************************
Robot::Robot() {
}

void Robot::calibrate(float Servo0, float Servo1, float Servo2, float Servo3, float Servo4, float Servo5,
                      float Servo6, float Servo7, float Servo8, float Servo9, float Servo10, float Servo11) { //sets ms A position

  maestroSerial.begin(9600); //starts maestro

  //sets ms position at 90 degrees position
  posnorm[0] = Servo0, posnorm[1] = Servo1, posnorm[2] = Servo2, posnorm[3] = Servo3;
  posnorm[4] = Servo4, posnorm[5] = Servo5, posnorm[6] = Servo6, posnorm[7] = Servo7;
  posnorm[8] = Servo8, posnorm[9] = Servo9, posnorm[10] = Servo10, posnorm[11] = Servo11;
}

void Robot::moveServos(float X0, float Y0, float Z0, float X1, float Y1, float Z1, float X2, float Y2, float Z2, float X3, float Y3, float Z3) {
  X[0] = X0, Y[0] = Y0, Z[0] = Z0;
  X[1] = X1, Y[1] = Y1, Z[1] = Z1;
  X[2] = X2, Y[2] = Y2, Z[2] = Z2;
  X[3] = X3, Y[3] = Y3, Z[3] = Z3;

  for (int i = 0; i < 4; i++) { //runs loop 4 times

    if (X[i] == NR && Y[i] == NR && Z[i] == NR) { //if X, Y, and Z are NR then all angles are NR
      theta1[i] = NR, theta2[i] = NR, theta3[i] = NR;
    }
    else {
      theta1[i] = getTheta1(X[i], Y[i], Z[i]);
      theta2[i] = getTheta2(X[i], Y[i], Z[i]);
      theta3[i] = getTheta3(X[i], Y[i], Z[i]);
    }

  }

  moveTo(theta3[0], theta1[0], theta2[0],
         theta3[1], theta1[1], theta2[1],
         theta3[2], theta1[2], theta2[2],
         theta3[3], theta1[3], theta2[3]);
}

void Robot::setSpeed(float  speed0, float  speed1, float  speed2, float  speed3, float  speed4, float  speed5,
                     float  speed6, float  speed7, float  speed8, float  speed9, float  speed10, float  speed11) {

  //transfers the "speed" variable to the "speed" array
  speed[0] = speed0, speed[1] = speed1, speed2 = speed2, speed[3] = speed3;
  speed[4] = speed4, speed[5] = speed5, speed[6] = speed6, speed[7] = speed7;
  speed[8] = speed8, speed[9] = speed9, speed[10] = speed10, speed[11] = speed11;

  for (int i = 0; i < 12; i++) { //for loop that runs 12 times
    maestro.setSpeed(servo[i], speed[i]); //sets speed
  }
}
