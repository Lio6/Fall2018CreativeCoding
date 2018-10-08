#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetBackgroundColor(0);
    for(int i=0; i<200;i++){
        Particle p;
//        p.setup(ofPoint(
//                    ofRandom(ofGetWidth()/2,ofGetHeight()/2),
//                        ofRandom(ofGetWidth()/2,ofGetHeight()/2)
//                             ));
        p.setup(ofPoint(
                                   ofRandom(ofGetWidth()),
                                   ofRandom(ofGetHeight())
                                   ));

        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    ofPoint mouse = ofPoint (mouseX, mouseY);
    
    for(int i=0; i<particles.size(); i++){
//        particles[i].addForce(ofPoint(0,.1));
        particles[i].update();
    
    
//    particles[i].addAttractionForce(mouse,100,.01);
        particles[i].addRepulsionForce(mouse, 100, .01);
    }
    for(int i=0; i<particles.size(); i++){
    
        for(int j=0; j<i;j++){
            particles[i].addRepulsionForce(particles[j].pos, 35, .1);
            particles[j].addRepulsionForce(particles[i].pos, 35, .1);
        }
    
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//
//    for(int i=0; i<particles.size(); i++){
//       particles[i].draw();
//    }
    
    ofDrawCircle(mouseX, mouseY, 100);
    ofNoFill();
    
    float maxDist = 100;
    for(int i=0; i<particles.size(); i++){
        
        for(int j=0; j<i;j++){
            // find distance between particles
            float dist = (particles[i].pos - particles[j].pos).length();
            // if distance less than our max dist, daw a line
            if (dist<maxDist){
                
            //mao the dist to an alpha value
                float alpha = ofMap(dist,0, maxDist, 255, 0);
                ofSetColor(255, alpha);
                ofDrawLine(particles[i].pos, particles[j].pos);
            }
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    for(int i=0;i<particles.size();i++){
        particles[i].addForce(ofPoint(
                              ofRandom(-4,4), ofRandom(-4,4)));
    }
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
