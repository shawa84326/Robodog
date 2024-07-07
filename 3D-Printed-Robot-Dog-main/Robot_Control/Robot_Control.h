#ifndef Robot_Control_H
#define Robot_Control_H

//global constants
#define NR  1212//means that the Servo is not running

#include "arduino.h"

class Robot { //single Servo class
  public:
    //class functions
    Robot();
    void calibrate(float Servo0, float Servo1, float Servo2,
                   float Servo3, float Servo4, float Servo5,
                   float Servo6, float Servo7, float Servo8,
                   float Servo9, float Servo10, float Servo11);

    void moveServos(float X0, float Y0, float Z0,
                    float X1, float Y1, float Z1,
                    float X2, float Y2, float Z2,
                    float X3, float Y3, float Z3);

    void setSpeed(float  speed0, float  speed1, float  speed2,
                  float  speed3, float  speed4, float  speed5,
                  float  speed6, float  speed7, float  speed8,
                  float  speed9, float  speed10, float  speed11);
};

#endif
