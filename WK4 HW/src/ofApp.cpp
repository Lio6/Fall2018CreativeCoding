#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofEnableAlphaBlending();
//    ofSetBackgroundColor(0);
//    counter = 0;
//    fbo.allocate(ofGetWidth(),ofGetHeight());
//    for(int i=0; i<100;i++){
////        ofNoise(counter, 0.5)* ofGetWidth()
//        Particle p;
//
//        p.setup(ofPoint(
//                        ofNoise((counter, 200)* ofGetMouseX()),
//                        ofNoise((counter,200)* ofGetMouseY())
////                        ofRandom(ofGetWidth()),
////                        ofRandom(ofGetHeight())
//                        ));
//
//        particles.push_back(p);
//    }
    ofBackground(238,140,169);
    fbo.allocate(ofGetWidth(),ofGetHeight());
    Rcolor = 0;
    Gcolor = 75;
}

//--------------------------------------------------------------
void ofApp::update(){

//    counter += 10;
//    for(int i=0; i<particles.size(); i++){
//        //        particles[i].addForce(ofPoint(0,.1));
//        particles[i].update();
//    }
    for (auto &vert : line.getVertices()){
        vert.x += ofRandom(-0.9,0.9);
        vert.y += ofRandom(-0.8,0.8);
    }
    
    Rcolor = ofGetElapsedTimeMicros()*Rcolor* .01;
    if (Rcolor>255){
        Rcolor = 33;
    }

    Gcolor = ofGetElapsedTimeMicros()*Gcolor* .01;
    if (Gcolor>255){
        Gcolor = 33;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();//fbo是一个canvas， 把东西画在canvas里，只有canvas里的才有trail
    ofSetColor(238,140,169,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(Rcolor,Gcolor,110);

    line.draw();

    
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
  
    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line.clear();

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
