#ifndef RC_Reciever_H
#define RC_Reciever_H
#include "arduino.h"

class RC_Reciever { //class 1 for actuator pin assignment
  public:
    //pin functions
    RC_Reciever(int _chn1, int _chn2, int _chn3, int _chn4, int _chn5, int _chn6, int _chn7, int _chn8);

    int getChannel(int num);
    void begin(int A, int B);
};

#endif
