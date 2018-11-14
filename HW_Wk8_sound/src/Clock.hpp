#ifndef _OF_CLOCK
#define _OF_CLOCK

#include "ofMain.h"

class ofClock {
    
public:
    ofClock();
    
    void clockupdate( int, int , int );
    void draw();
    
//private:
//    int radius;
//
//    int top;
//    int left;
//
//    float secondsAngle;
//    float minutesAngle;
//    float hoursAngle;
};

#endif
