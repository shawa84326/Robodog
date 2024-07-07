void robotStep (int dir) { //moves the robot forward or backwards (input 1 for forwards, input -1 for backwards)
  int spd = 0;
  int Ystep = 40;
  int Xstep = 50 * dir;
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
  Robot.moveServos(Xstep, Ynorm - Ystep, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   Xstep, Ynorm - Ystep, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(Xstep, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   Xstep, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm - Ystep, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm - Ystep, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   Xstep, Ynorm - Ystep, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   Xstep, Ynorm - Ystep, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   Xstep, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   Xstep, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
}

void robotSlide (int dir) { //moves the robot left or right (input 1 for right, input -1 for left)
  int spd = 0;
  int Ystep = 40;
  int Zstep = 30 * dir;
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
  Robot.moveServos(0, Ynorm - Ystep, Zstep, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm - Ystep, -Zstep); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, Zstep, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, -Zstep); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm - Ystep, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm - Ystep, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm - Ystep, -Zstep, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm - Ystep, Zstep, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, -Zstep, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, Zstep, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);

}


void robotTurn (int dir) { //moves the robot forward or backwards (input 1 for forwards, input -1 for backwards)
  int spd = 0;
  int Ystep = 40;
  int Xstep = 50 * dir;
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
  Robot.moveServos(-Xstep, Ynorm - Ystep, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   Xstep, Ynorm - Ystep, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(-Xstep, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   Xstep, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm - Ystep, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm - Ystep, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   Xstep, Ynorm - Ystep, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   -Xstep, Ynorm - Ystep, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
  Robot.moveServos(0, Ynorm, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   Xstep, Ynorm, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   -Xstep, Ynorm, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm, 0); //Back Left Leg, Servo #'s (9, 10, 11)
  delay(t);
}
