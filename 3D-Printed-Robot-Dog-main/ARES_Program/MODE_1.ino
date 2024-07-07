void halt() {
  while (1) {
  }
}

void robotHome (int spd) { //moves the robot to its home position, input spd for all servos

  Robot.setSpeed(spd, spd, spd, //Front Right Leg, Servo #'s (0, 1, 2)
                 spd, spd, spd, //Front Left Leg, Servo #'s (3, 4, 5)
                 spd, spd, spd, //Back Right Leg, Servo #'s (6, 7, 8)
                 spd, spd, spd); //Back Left Leg, Servo #'s (9, 10, 11)

  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)

  Yoffset = 0;
  Yoffset2 = 0;
}

void robotTrot () { //makes the robot trot in place
  int spd = 0;
  int Ystep = 40;
  int t = 50;

  Robot.setSpeed(spd, spd, spd, //Front Right Leg, Servo #'s (0, 1, 2)
                 spd, spd, spd, //Front Left Leg, Servo #'s (3, 4, 5)
                 spd, spd, spd, //Back Right Leg, Servo #'s (6, 7, 8)
                 spd, spd, spd); //Back Left Leg, Servo #'s (9, 10, 11)

  Robot.moveServos(0, Ynorm - Ystep, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm - Ystep, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  robotHome(spd); //moves robot to its home position
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm - Ystep, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm - Ystep, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  robotHome(spd); //moves robot to its home position
  delay(t);
}
