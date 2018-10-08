#include "ofApp.h"

//--------------------------------------------------------------
//void ofApp::setup(){
//    xPos = 5;  // horizontal start position
//    ofBackground(ofColor::black);  // black background
//}



//--------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
    pos.x = (1-pct) * posa.x + (pct) * posb.x;
    pos.y = (1-pct) * posa.y + (pct) * posb.y;
}


void rectangle::draw(){

    
    pct += 0.01f;        // increase by a certain amount
    if (pct > 1) {
        pct = 0;    // just between 0 and 1 (0% and 100%)
    }
    
//    myRectangle.interpolateByPct(pct);    // go between pta and ptb
    ofDrawRectangle(pos.x, pos.y, 50, 50);
}


//--------------------------------------------------------------


//--------------------------------------------------------------


