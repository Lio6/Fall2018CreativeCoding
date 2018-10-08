#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     //initial condition and set initial value
    ofSetBackgroundColor(ofColor::hotPink);
    
    xpos = 0.0;
    pct = 0;
    
//    mPos = ofPoint
    
    // adding some values to the vector
    for(int i=0;i<10;i++){
        manyPoints.push_back(ofPoint(i*20,i*20));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(pct<1) pct +=  .025;
    
    for (int i=0; i< manyPoints.size(); i++){
        float mPct = .01*(i+1);
        manyPoints[i].x = (1-mPct) * manyPoints[i].x + mPct * ofGetMouseX();
        manyPoints[i].y = (1-mPct) * manyPoints[i].y + mPct * ofGetMouseY();


    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    xpos +=  .25;
    
    ofSetCircleResolution(50);
    ofSetColor(0);
    ofDrawCircle(xpos, 100, 40,40);
 
    
    float startPos = 0;
    float endPos = ofGetWidth();
    
    float nPct = pow(pct,2);
    float currentPos = (1-nPct) * startPos + nPct * endPos;
    ofDrawCircle(currentPos, 200, 40);
   
    
    float linearPos = (1-pct) * startPos + pct * endPos;
    ofDrawCircle(linearPos, 300, 40);
    
    float sPct = inOutsine(pct);
    float sPos = (1-sPct) * startPos + sPct * endPos;
    ofDrawCircle(sPos, 400, 40);
    
    
    float xPos = (1-sPct)*startX + sPct * ofGetMouseX();
    float yPos = (1-sPct)*startY + sPct * ofGetMouseY();
    ofDrawCircle(xPos, yPos, 40);
    
    
    for(int i = 0; i< manyPoints.size();i++){
        ofDrawRectangle(manyPoints[i], 20, 20);

    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    pct = 0;

}

float ofApp::inOutsine(float t){
    return 0.5 * (1+ sin(PI *( t - 0.5)));
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
