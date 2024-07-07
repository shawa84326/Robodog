



void robotTilt() {
  Robot.moveServos(0, Ynorm - Yoffset-Yoffset2, 0, //Front Right Leg, Servo #'s (0, 1, 2)
                   0, Ynorm - Yoffset+Yoffset2, 0, //Front Left Leg, Servo #'s (3, 4, 5)
                   0, Ynorm + Yoffset-Yoffset2, 0, //Back Right Leg, Servo #'s (6, 7, 8)
                   0, Ynorm + Yoffset+Yoffset2, 0); //Back Left Leg, Servo #'s (9, 10, 11)
}
