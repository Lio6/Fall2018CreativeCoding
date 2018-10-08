#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255, 255, 255);
    pct=0.0;
    pct1=0.0;
    
    myFont.load("JosefinSans-Regular.ttf",200);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct +=0.005;
    if (pct>1){
        pct=1;
        pct1 +=0.009;
        if (pct1>1){
            pct1=0.93;
            
        }
        
        
    }
    
//    if (linearX = 0.255){
//        pct1=0.0;
//    }
    
    
   
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    float linearMove = linear(pct);
    float inQuadMove = inQuad(pct);
//    float outQuadMove = outQuad(pct);
//    float inOutQuadMove = inOutQuad(pct);
//    float inCubicMove = inCubic(pct);
//    float outCubicMove = outCubic(pct);
//    float inOutCubicMove = inOutCubic(pct);
   
    
    float startPos1 = 255;
    float endPos1 = 0;
    
    float inQuadX = (1-inQuadMove)*startPos1+ inQuadMove*endPos1;
    
    
    ofSetColor(inQuadX);
    myFont.drawString("L",200,500);
    myFont.drawString("i",450,500);
//    myFont.drawString("o", 600, 500);
   
    float outBounceMove = outBounce(pct1);
    
    
    float startPos2 = 0;
    float endPos2 = 500;
    
    float outBounceX = (1-outBounceMove)*startPos2 + outBounceMove*endPos2;
    
    ofSetColor(0);
    myFont.drawString("o", 630, outBounceX);
    
    
    
}


//--------------------------------------------------------------

float ofApp::inQuad(float t){
    return t * t;
}


float ofApp::outBounce(float t){
    if ((t /= 1) < (1 / 2.75)) {
        return (7.5625 * t * t);
    } else if (t < (2 / 2.75)) {
        return (7.5625 * (t -= (1.5 / 2.75)) * t + .75);
    } else if (t < (2.5 / 2.75)) {
        return (7.5625 * (t -= (2.25 / 2.75)) * t + .9375);
    } else {
        return (7.5625 * (t -= (2.625 / 2.75)) * t + .984375);
    }
    
}

void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
