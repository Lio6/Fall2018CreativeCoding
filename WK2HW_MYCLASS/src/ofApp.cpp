#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){


    ofSetBackgroundColor(64,85,177);
    fewparticles.resize(200);
    
    for(int i=0; i<fewparticles.size();i++){
      
        
        fewparticles[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){

//    One1.update();

    for (int i = 0; i<fewparticles.size(); i++) {
        fewparticles[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i<fewparticles.size(); i++) {
        fewparticles[i].draw();
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

    for(int i=0; i<fewparticles.size();i++){
        
        
        fewparticles[i].setup();
    }
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
