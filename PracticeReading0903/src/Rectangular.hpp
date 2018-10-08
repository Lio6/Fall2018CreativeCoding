//
//  rectangular.hpp
//  PracticeReading0903
//
//  Created by sumsun on 9/6/18.
//

#ifndef rectangular_hpp
#define rectangular_hpp

#include <stdio.h>

#endif /* rectangular_hpp */

#include "ofMain.h"

class rectangle {
    
public:
    
    rectangle();
    void draw();
    void interpolateByPct(float myPct);
    
    void setup();
    void update();
    void draw();
    
    
    ofPoint pos;
    ofPoint posa;
    ofPoint    posb;
    float pct;    // what pct are we between "a" and "b"
};
