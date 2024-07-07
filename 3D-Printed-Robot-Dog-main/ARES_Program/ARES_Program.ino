#include <Robot_Control.h>
#include <RC_Reciever.h>

Robot Robot;
RC_Reciever reciever(5, 6, 7, 8, 9, 10, 11, 12); //define pwm pins for each channel

int Ynorm = 150; //normal Y position for each leg when the robot is in its home stance
float Yoffset;
float Yoffset2;

void setup() {
  //Start the serial monitor
  Serial.begin(115200); //baud rate
  reciever.begin(0, 180); //sets rc reciever min and max analog values

  //Servo positioning calibration
  Robot.calibrate(1500, 2000, 1930, //Front Right Leg, Servo #'s (0, 1, 2)
                  1476, 1031, 1050, //Front Left Leg, Servo #'s (3, 4, 5)
                  1423, 1897, 1870, //Back Right Leg, Servo #'s (6, 7, 8)
                  1437, 1100, 1300); //Back Left Leg, Servo #'s (9, 10, 11)

  robotHome(20); //moves robot to its home position
  delay(2000); //wait 2 seconds
}

void loop() {
  //MODE #1: TRANSLATION
  while (reciever.getChannel(5) == 0 ) { //when channel 5 is in the neutral position
    while (reciever.getChannel(2) > 140) { //if right analog stick is pushed up, move the robot forwards
      robotStep(1);
    }
    while (reciever.getChannel(2) < 40) {  //if right analog stick is pulled down, move the robot backwards
      robotStep(-1);
    }
    while (reciever.getChannel(1) > 140) { //if right analog stick is pushed right, move the robot right
      robotSlide(1);
    }
    while (reciever.getChannel(1) < 40) {  //if right analog stick is pushed left, move the robot left
      robotSlide(-1);
    }
    while (reciever.getChannel(4) > 140) { //if left analog stick is pushed right, turn the robot right
      robotTurn(1);
    }
    while (reciever.getChannel(4) < 40) {  //if left analog stick is pushed left, turn the robot left
      robotTurn(-1);
    }

    robotHome(0); //moves robot to its home position
  }

  //MODE #2: TROT
  while (reciever.getChannel(5) == 1) { //when channel 5 is flipped forward, make the robot trot
    robotTrot();
  }

  robotHome(0); //moves robot to its home position

  //MODE #3: INVERSE KINEMATICS
  while (reciever.getChannel(5) == -1 ) { //when channel 5 is flipped back
  float inc = 10;
  int Ylim = 60;
  int Ylim2 = 30;
  Robot.setSpeed(0, 0, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                 0, 0, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                 0, 0, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                 0, 0, 0); //Back Left Leg, Servo #'s (9, 10, 11)

  if (reciever.getChannel(2) > 140) { //if right analog stick is pushed up, tilt the robot forwards
    Yoffset = Yoffset + inc;
    Yoffset = min(Yoffset, Ylim);
  }
  if (reciever.getChannel(2) < 40) {  //if right analog stick is pulled down, tilt the robot backwards
    Yoffset = Yoffset - inc;
    Yoffset = max(Yoffset, -Ylim);
  }

   if (reciever.getChannel(1) > 140) { //if right analog stick is pushed right, tilt the robot right
    Yoffset2 = Yoffset2 + inc;
    Yoffset2 = min(Yoffset2, Ylim2);
  }
  if (reciever.getChannel(1) < 40) {  //if right analog stick is pushed left, tilt the robot left
    Yoffset2 = Yoffset2 - inc;
    Yoffset2 = max(Yoffset2, -Ylim2);
  }

  if (reciever.getChannel(6) == 1) {
    robotHome(0); //moves robot to its home position
  }

  robotTilt();
}

}
