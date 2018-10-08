#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    light.setPosition(200,300,1000);
    check = -0.8;

    ofSetVerticalSync(true);
    ofSetWindowShape(ofGetWidth(), ofGetHeight());
    ofSetWindowTitle("Alberto");
    ofSetFrameRate(60);
    ofSetCylinderResolution(50, 4);
    ofSetConeResolution(50, 4);
    Alberto1.load("Alberto.png");
    Alberto2.load("Alberto.png");
    
    offset.x = -Alberto2.getWidth()/2;
//    offset.y = (ofGetHeight() - Alberto2.getHeight()/2);
    offset.y = 0;
    offset.z = 0;
    size = 20;
    
    fbo.allocate(ofGetWidth(),ofGetHeight());
    fbo.begin();
    ofClear(0,0,0,0);
    fbo.end();

    ofSetSphereResolution(10);
//    cam.setDistance(1000);
//    cam.setRotationSensitivity(0, 0, 0);
//    cam.setAutoDistance(true);

    appear = 255;
    fadeImage = false;
 
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    counter+=0.01;
    for(int i =0; i<particles.size(); i++){
        
        particles[i].update(mouse);
//        particles[i].followmouse(mouse);
    }

    if(fadeImage && appear >0){
        appear-=10;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    
    
    
    ofEnableDepthTest();
    fbo.begin();
    
    
    
    ofSetColor(0,0,0,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
   
   
    
    ofPushMatrix();
    
   
    
    ofTranslate(ofGetWidth()/2, 0, -300);
    
    

    if(check > 0){
    ofRotateDeg(check*ofGetElapsedTimef(),0,  -Alberto2.getWidth()/2, 0);
        
    }
    for(int i=0; i <particles.size();i++){
        particles[i].draw();
    }
   
 
    
    ofPopMatrix();
    
    ofDisableDepthTest();
    
    fbo.end();
    fbo.draw(0,0);

    
    
    ofEnableAlphaBlending();
    
    ofSetColor(255, 255, 255, appear);
    Alberto1.draw(ofGetWidth()/2-Alberto2.getWidth()/2,0, Alberto2.getWidth(), Alberto2.getHeight());
    
    ofDisableAlphaBlending();
    
    // ADD: 写particle有fbo的效果
  
//    ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
//    ofTranslate(ofGetWidth()/2-Alberto2.getWidth()/2,0);//让它显示在中间
//    cam.end();
    
    
    


} //要做的效果：1.原图显示☑️ 2.trigger粒子动起来 3. 鼠标drag拖动粒子


//--------------------------------------------------------------



void ofApp::keyPressed(int key){

    

    if(key=='a' && size<26){
        size++;
        for(int i=0; i <particles.size();i++){
            particles[i].size = size;
        }
    }else if(key=='m' && size>16){
        size--;
        for(int i=0; i <particles.size();i++){
            particles[i].size = size;
        }
    }

    if(particles.size()==0 && key=='o') {

//        appear--;
        fadeImage = true;
        check += 5;

        
        
        
        for(int x=0; x<Alberto2.getWidth(); x+=size) {
            for(int y=0; y<Alberto2.getHeight(); y+=size) {
                for(int z=0; z<300; z+=size){

                ofPoint pos;
                pos.set(x, y, z);
                pos += offset;
                    

                PixelParticle v;
                v.setup(pos, Alberto2.getColor(x, y), size);  //////???????
                particles.push_back(v);

                }

            }
        }
        
        
    }

    if(key=='c') {

        particles.clear();
        

        
    }
    
    if(key==' '){
        
   

        light.enable();

        
        for(int i=0; i <particles.size();i++){

            particles[i].addForce(ofPoint(ofRandom(8,-8),ofRandom(8,-8),ofRandom(8,-8)));
        }
        
       
    }
    
    
    else if(key == 's'){
        for(int i=0; i <particles.size();i++){
            particles[i].goBackToStart = true;
        }
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

//    mouse.x = x;
//    mouse.y = y;

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
