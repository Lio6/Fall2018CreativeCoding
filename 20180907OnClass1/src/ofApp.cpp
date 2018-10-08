#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofEnableDepthTest();
//    ofSetVerticalSync(true);
//    cam.setDistance(166);
    
    gui.setup();
    gui.add(freqSlider.setup("Sin Freq",1,.25,10));
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

//    cam.begin();
    
    float targetAngle = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
    ofSetRectMode(OF_RECTMODE_CENTER);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZRad(targetAngle);
    
    ofDrawRectangle(0, 0, 50, 50);
    
    ofPopMatrix();
    
    

//    for(int i= 0; i<360;i+=30){
//        float angle = ofDegToRad(i);
//        float x = ofGetWidth()/2 + (i*.5)*cos(angle);
//        float y = ofGetHeight()/2 + (i*.5)*sin(angle);
//        ofDrawCircle(x, y, 5);
//    }

    
//    float sinValue = ofMap( sin( ofGetElapsedTimef()) ,-1, 1,0,20);
//    ofLog() << sinValue;
//
////    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, sinValue);
//    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2, sinValue,sinValue);
//
//    for(int x=0; x<ofGetWidth();x+=50){
//        float cosValue = ofMap( sin( (x*.01)*ofGetElapsedTimef()) ,-1, 1,0,20);
//
//        for(int y=0;y<ofGetHeight();y+=50){
//             float sinValue = ofMap( sin( (y*.01*freqSlider)*ofGetElapsedTimef()) ,-1, 1,0,20);
//            ofDrawRectangle(x, y, sinValue, cosValue);
//        }
//    }

    
//    cam.end();
    gui.draw();
}

//--------------------------------------------------------------
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
