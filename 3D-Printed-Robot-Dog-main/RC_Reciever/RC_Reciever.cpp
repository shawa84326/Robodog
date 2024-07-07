#include "RC_Reciever.h"

//**GLOBAL VARIABLES*******************************************************************************************

int chn_pin[8];; //channel pins for rc reciever
int chn[8]; //channel values
int lower; //lower bound for channels 1-4 analog values
int upper; //upper bound for channels 1-4 analog values

//**GLOBAL FUNCTIONS*********************************************************************************************


//**LIBRARY CONTENT**********************************************************************************************

RC_Reciever::RC_Reciever(int _chn1, int _chn2, int _chn3, int _chn4, int _chn5, int _chn6, int _chn7, int _chn8) {
  //assign channel numbers to global variables
  chn_pin[0] = _chn1;
  chn_pin[1] = _chn2;
  chn_pin[2] = _chn3;
  chn_pin[3] = _chn4;
  chn_pin[4] = _chn5;
  chn_pin[5] = _chn6;
  chn_pin[6] = _chn7;
  chn_pin[7] = _chn8;
}

void RC_Reciever::begin(int A, int B) {
  for (int i = 0; i < 8; i++) { //runs loop 8 times
    pinMode(chn_pin[i], INPUT); //sets pin as input
  }

  lower = A;
  upper = B;
}

int RC_Reciever::getChannel(int num) {
  num = num - 1; //converts num to use for array
  chn[num] = pulseIn(chn_pin[num], HIGH, 20000);

  if (num == 0 || num == 2 || num == 3) { //channels 1,3, and 4
    chn[num] = map(chn[num], 1000, 2000, lower, upper);
  }

  if (num == 1) { //channel 2
    chn[num] = map(chn[num], 2000, 1000, lower, upper);
  }

  if (num == 4 || num == 6) { //channels 5 and 7
    if (chn[num] < 1600 && chn[num] > 1400) {
      chn[num] = 0;
    }

    else if (chn[num] < 1400) {
      chn[num] = 1;
    }
    else {
      chn[num] = -1;
    }
  }

  if (num == 5) { //channel 6
    if (chn[num] < 1500) {
      chn[num] = 0;
    }

    else {
      chn[num] = 1;
    }
  }

  if (num == 7) { //channel 8
    chn[num] = map(chn[num], 1000, 2000, 0, 100);
  }

  return chn[num]; //returns channel value
}
