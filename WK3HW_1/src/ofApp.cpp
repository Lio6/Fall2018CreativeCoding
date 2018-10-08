#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    

    ofSetBackgroundColor(255, 255, 255);
    for(int i=0;i<500;i++){
        
        Particle p;
        
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
    for(int i=0;i<particles.size();i++){
       
        particles[i].update();
        particles[i].addAttractionForce(mouse,120,.016);
        
  
    }
    for(int i=0; i<particles.size(); i++){
        
        
        //加rotate效果 鼠标推动时
        
        for(int j=0; j<i;j++){
            particles[i].addAttractionForce(particles[j].pos, 50, .1);
            particles[j].addAttractionForce(particles[i].pos, 50, .1);
        }
        
    }
    

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float maxDist = 38;
     int alph1=100;
   

    for(int i=0;i<particles.size();i++){
        
        
        for(int j=0; j<i;j++){
            // find distance between particles
            float dist = (particles[i].pos - particles[j].pos).length();
            // if distance less than our max dist, daw a line
            if (dist<maxDist){
                
                //mao the dist to an alpha value
                float alpha = ofMap(dist,0, maxDist, 0, 255);
                ofSetColor(0, alpha);
                ofDrawLine(particles[i].pos, particles[j].pos);
                alph1= alph1-100;
                
            }
            
            
        }
    }
    
    for(int i=0;i<80;i++){
        
        
        particles[i].drawRects(alph1);
    }
    
    for(int i=200;i<258;i++){
        
        particles[i].drawTriangle(alph1);
    }
   
    for(int i=400;i<480;i++){
        
        particles[i].draweightangles(alph1);
    }
    
    //加旋转效果 然后把方框的push做好看 明显点
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    
    
//    for(int i=0;i<particles.size();i++){
//
//        particles[i].update();
//
//
//    }
    
//        float targetAngle = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
//        ofSetRectMode(OF_RECTMODE_CENTER);
//    for(int i=0;i<particles.size();i++){
//
//            ofPushMatrix();
//            ofTranslate(ofGetWidth(), ofGetHeight());
//            ofRotateZRad(targetAngle);
//
//            ofDrawRectangle(0, 0, 50, 50);
//
//            ofPopMatrix();
//
//
//    }
    //加rotate效果 鼠标推动时
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    
    for(int i=0;i<particles.size();i++){
        particles[i].noiseMove();
        
        
    }
    
//    for(int i=0;i<particles.size()/12;i++){
//
//        particles[i].drawCircles(0);
//    }
    
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
