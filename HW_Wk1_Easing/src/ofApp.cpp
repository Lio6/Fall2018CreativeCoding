#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255, 255, 255);
    pct=0.0;


}

//--------------------------------------------------------------
void ofApp::update(){
    pct +=0.005;
    if (pct>1){
        pct=0;
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){

    float startPos = 20;
    float endPos = 900;
    
    float linearMove = linear(pct);
    float inQuadMove = inQuad(pct);
    float outQuadMove = outQuad(pct);
    float inOutQuadMove = inOutQuad(pct);
    float inCubicMove = inCubic(pct);
    float outCubicMove = outCubic(pct);
    float inOutCubicMove = inOutCubic(pct);
    float outBounceMove = outBounce(pct);
    
    float linearX = (1-linearMove)*startPos + linearMove*endPos;
    ofSetColor(100,25,233);
    ofDrawCircle(linearX, 100, 20);
    
    float inQuadX = (1-inQuadMove)*startPos + inQuadMove*endPos;
    ofSetColor(51,50,233);
    ofDrawCircle(inQuadX, 150, 20);
    
    float outQuadX = (1-outQuadMove)*startPos + outQuadMove*endPos;
    ofSetColor(51,25,233);
    ofDrawCircle(outQuadX, 200, 20);
    
    float inOutQuadX = (1-inOutQuadMove)*startPos + inOutQuadMove*endPos;
    ofSetColor(66, 66, 100);
    ofDrawCircle(inOutQuadX, 250, 20);
    
    float inCubicX = (1-inCubicMove)*startPos + inCubicMove*endPos;
    ofSetColor(120, 40, 166);
    ofDrawCircle(inCubicX, 300, 20);
    
    float outCubicX = (1-outCubicMove)*startPos + outCubicMove*endPos;
    ofSetColor(200, 56, 255);
    ofDrawCircle(outCubicX, 350, 20);
    
    float inOutCubicX = (1-inOutCubicMove)*startPos + inOutCubicMove*endPos;
    ofSetColor(233, 34, 200);
    ofDrawCircle(inOutCubicX, 400, 20);

    float outBounceX = (1-outBounceMove)*startPos + outBounceMove*endPos;
    ofSetColor(10, 100, 233);
    ofDrawCircle(outBounceX, 450, 20);
}

//--------------------------------------------------------------

float ofApp::linear(float t){
    return t;
}

float ofApp::inQuad(float t){
    return t * t;
}

float ofApp:: outQuad(float t){
    return t*(2-t);
}

float ofApp::inOutQuad(float t){
    return t < .5 ? 2 * t * t : -1 + (4 - 2 * t) * t;
}

float ofApp::inCubic(float t){
    return t * t * t;
}

float ofApp::outCubic(float t){
    return (--t) * t * t + 1;
}

float ofApp::inOutCubic(float t){
    return t < .5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
    
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
