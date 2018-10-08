

#include "particles.hpp"


Particle::Particle(){
    
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    damp = .9;
    
}

void Particle::setup(ofPoint _pos){
    
    pos= _pos;
    ofSetFrameRate(60);
    
//    pos.set(0,0,0);
//    vel.set(0,0,0);
  
    vel.set(ofRandom(-1,1), ofRandom(-1,1));
    
    rectangle.load("rectangle.png");
    triangle.load("triangle.png");
    eightangles.load("8angles.png");

}


void Particle::update(){
    
    
    
    vel += acc;
    vel *= damp;//decrease velocity over time with "forece"
    pos += vel;
    acc *= 0.0;

    angle =  atan2(pos.x - ofGetMouseX(), pos.y - ofGetMouseY()/2);
//    angle = atan2(ofGetMouseY()-ofGetHeight()/2, ofGetMouseX()-ofGetWidth()/2);
  

    

}

void Particle::noiseMove(){
    
    pos.x= ofMap(ofNoise(ofRandom(5),ofGetFrameNum()+1* 0.001), 0, 1, pos.x-25, pos.x+25);
    pos.y= ofMap(ofNoise(ofRandom(5),ofGetFrameNum()+1* 0.001), 0, 1, pos.y-25, pos.y+25);
    
}

void Particle::draw(){
    
    
    ofDrawCircle(pos, 5);
    
    
    
}

//void Particle::drawCircles(int _alph){
//
//
//
//    ofSetColor(255, 255, 255, _alph);
//
//    ofDrawCircle(pos,60);
//    ofSetColor(0);
//    ofDrawCircle(pos,59);
//
//}

void Particle::drawRects(int _alph){
    
    ofSetRectMode(OF_RECTMODE_CENTER);

    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-90);
    

    ofSetColor(255, 255, 255, _alph);
//    ofDrawRectangle(pos, 44, 44);
//    ofSetColor(0);
//    ofDrawRectangle(pos+2, 40,40);
//    rectangle.draw(-rectangle.getWidth()/2.0, -rectangle.getHeight()/2.0, 40, 40);
    rectangle.draw(0,0,40,40);
     ofPopMatrix();
}

void Particle::drawTriangle(int _alph){
   
    ofSetRectMode(OF_RECTMODE_CENTER);

    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-90);
//    ofRotateZRad(angle);


    ofSetColor(255, 255, 255, _alph);
//    triangle.draw(-triangle.getWidth()/2.0, -triangle.getHeight()/2.0, 40, 40);
    triangle.draw(0, 0, 40,40);
    
        ofPopMatrix();
}

void Particle::draweightangles(int _alph){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-90);
    ofSetColor(255, 255, 255, _alph);
//    eightangles.draw(-eightangles.getWidth()/2.0, -eightangles.getHeight()/2.0, 40, 40);
    eightangles.draw(0,0,40,40);
//    ofSetColor(255,0,0);
//    ofDrawLine(0,0,10,10);
    ofPopMatrix();

    
}


void Particle::addForce(ofPoint force){
    acc += force;
}

void Particle::addAttractionForce(ofPoint _pos, float _rad, float scale){
    
    ofPoint diff = _pos - pos;
    
    if(diff.length()<_rad){
        ofLog() << "ATTRACT";
        
        diff *= 1.0 -(diff.length() / _rad);
        addForce(-diff*scale);
//        diff *= (diff.length() / _rad) - 1.0;
//        addForce(diff*scale);
        
    }
    
}


