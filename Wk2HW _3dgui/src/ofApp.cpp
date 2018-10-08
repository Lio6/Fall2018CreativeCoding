#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(242,173,41);
    
//    ofEnableDepthTest();
    ofSetVerticalSync(true);
    cam.setDistance(500);
    
    gui.setup();
    gui.add(BouncingRate.setup("Bouncing Rate",.05,.01,0.5));
    
    gui.add(DepthX.setup("DepthX",.05,.01,1));
    
    gui.add(BallSize.setup("BallSize",10, 5,15));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    cam.begin();
    


//    float sinValue1 = ofMap( sin( ofGetElapsedTimef()) ,-1, 1,0,30);
//    ofLog() << sinValue1;
    
//    ofSetColor(80,42,209);
//    ofDrawBox(0,0,0,sinValue);
//    ofFill();
    

    for(int x=0; x<ofGetWidth()*3;x+=50){
        float cosValue = ofMap( sin( (x*.001)*DepthX) ,-1, 1,-25,50);
        
        for(int y=0;y<ofGetHeight()*3;y+=50){
            float sinValue = ofMap( sin( (y*.005*BouncingRate)*ofGetElapsedTimef()) ,-1, 1,-25,60);
            
            ofSetColor(80, ofGetMouseY(), 209);
            ofFill();
            ofDrawSphere(x*cosValue, cosValue*sinValue, y, BallSize);
            
            
           
            
        }
    }
    
    
    
    cam.end();
    ofDisableDepthTest();
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
