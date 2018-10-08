//
//  rectangular.cpp
//  PracticeReading0903
//
//  Created by sumsun on 9/6/18.
//

#include "rectangular.hpp"

void rectangle::interpolateByPct(float myPct){
    pos.x = (1-pct) * posa.x + (pct) * posb.x;
    pos.y = (1-pct) * posa.y + (pct) * posb.y;
}


void rectangle::update(){
    
    pct += 0.01f;        // increase by a certain amount
    if (pct > 1) {
        pct = 0;    // just between 0 and 1 (0% and 100%)
    }
    myRectangle.interpolateByPct(pct);    // go between pta and ptb
    
}
