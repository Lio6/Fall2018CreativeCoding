#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //Make everything looking nice and smooth.
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    //Set size & position of our clock
    if( ofGetHeight() < ofGetWidth() )
        radius = (ofGetHeight()/2)-20;
    else
        radius = (ofGetWidth()/2)-20;
    
    top = (ofGetHeight()/2);
    left = (ofGetWidth()/2);
    
    sound1.load("shake.mp3");
    sound1.setMultiPlay(true);
//    sound1.play();
    

    
}

//--------------------------------------------------------------
void ofApp::update(){

    sec = ofGetSeconds();
    min = ofGetMinutes();
    hour = ofGetHours();
    secondsAngle = 6 * sec;
    minutesAngle = 6 * min;
    hoursAngle = 30 * hour + (min / 2);
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    //Set the coortinatesystem to the center of the clock.
    ofPoint circle_center = ofPoint( left, top );
    ofTranslate(circle_center);
    ofRotateZ(-90);
    
    //Draw background of the clock
    ofSetHexColor(0x6AC4AA);
    ofFill();
    ofCircle( ofPoint(0,0), radius );
    
    //Draw Outline of the clock
    ofSetLineWidth( (radius/100)*4 );
    ofNoFill();
    ofSetHexColor(0xFEB3B0);
    ofCircle( ofPoint(0,0), radius );
    
    //Draw the clock face
    ofSetLineWidth(1);
//
    for(int i=0;i<12;i++){
        ofRotateZ( 30 );
        
        ofFill();
        ofRect( ofPoint( (radius/10)*8, -((radius/100)*2) ), (radius/100)*20, (radius/100)*4 );
        ofNoFill();
        ofRect( ofPoint( (radius/10)*8, -((radius/100)*2) ), (radius/100)*20, (radius/100)*4 );
    }
    
    //Draw the hour hand
    ofPushMatrix();
    
    ofSetHexColor(0xFF0000);
    ofRotateZ( hoursAngle );
    
    ofFill();
    ofRect( 0,-((radius/100)*5),(radius/10)*6, (radius/100)*10 );
    ofNoFill();
    ofRect( 0,-((radius/100)*5),(radius/10)*6, (radius/100)*10 );
    
    ofPopMatrix();
    
    //Draw the minute hand
    ofPushMatrix();
    
    ofSetHexColor(0xED3150);
    ofRotateZ( minutesAngle );
    
    ofFill();
    ofRect( 0,-((radius/100)*4),(radius/10)*7, (radius/100)*8 );
    ofNoFill();
    ofRect( 0,-((radius/100)*4),(radius/10)*7, (radius/100)*8 );
    
    ofPopMatrix();
    
    //Draw the second hand
    ofPushMatrix();
    
    ofSetHexColor(0xEAE1B3);
    ofRotateZ( secondsAngle );
    
    ofFill();
    ofRect( -((radius/100)*2),-((radius/100)*2),(radius/10)*9, (radius/100)*4 );
    ofNoFill();
    ofRect( -((radius/100)*2),-((radius/100)*2),(radius/10)*9, (radius/100)*4 );
    
    ofPopMatrix();
    
    ofFill();
    ofSetHexColor(0xFF9999);
    ofCircle( ofPoint(0,0), (radius/100)*6 );
    
    if ( secondsAngle<60 && secondsAngle>1){
        if( sound1.isPlaying() ){
        ofLog()<< secondsAngle;
        }else{
            sound1.play();
        }
    
//    ofLog()<< secondsAngle;

    }else{
        if( sound1.isPlaying() ){
           //add 倒计时
    }
    

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
