//
//  Particle.cpp
//  20180914OnClass1
//
//  Created by sumsun on 9/14/18.
//

#include "Particle.hpp"

Particle::Particle(){
    
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    damp = .9;
    
}

void Particle::setup( ofPoint _pos){
    
    pos = _pos; //innitial radome place in the screen
    vel.set(ofRandom(-1,1), ofRandom(-1,1));
    noiseRandomAllSet.set(ofRandom(10),ofRandom(10),ofRandom(10));
    
//    pos.set(ofRandom(ofGetWidth(),ofRandom(ofGetWidth())));
    
    
}

void Particle::update(){
    
    vel += acc;
    vel *= damp;//decrease velocity over time with "forece"
    pos += vel;
    acc *= 0.0;
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
        
    }
    
}

void Particle::addRepulsionForce(ofPoint _pos, float _rad, float scale){
    
    ofPoint diff = _pos - pos;
    
    if(diff.length()<_rad){
        
        diff *= (diff.length() / _rad) - 1.0;
        addForce(diff*scale);
    }
    
}

void Particle::draw(){
    ofDrawCircle(pos.x,pos.y,10);
}
