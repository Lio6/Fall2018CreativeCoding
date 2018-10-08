#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(0);
    counter = 0;
    fbo.allocate(ofGetWidth(),ofGetHeight());
    fbo.begin();
    ofClear(0,0,0,0);
    fbo.end();

    
//    ofSetBackgroundAuto(false);//所有的东西都有trail
    
}

//--------------------------------------------------------------
void ofApp::update(){

    counter += .01;
}

//--------------------------------------------------------------
void ofApp::draw(){
 
    fbo.begin();//fbo是一个canvas， 把东西画在canvas里，只有canvas里的才有trail
    ofSetColor(0, 0, 0,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255);
    for(int i=0; i<100; i++){
    float x = ofNoise(counter, i* .005) * ofGetWidth();
    float y = ofNoise(i* .005, counter) * ofGetHeight();
    ofDrawCircle(x, y, 4);
    }
    
    fbo.end();
    
    fbo.draw(0,0);
    
    
    
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
