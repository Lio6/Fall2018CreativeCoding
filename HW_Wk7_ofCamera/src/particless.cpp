//
//  particless.cpp
//  HW_Wk7_ofCamera
//
//  Created by sumsun on 10/15/18.
//

#include "particless.hpp"

void Particles::setup( ofPoint _pos){
    
    homePos = _pos;
  
    force = ofPoint(0,0,0);
    
    startPos = _pos;
}

void Particles::update(){
    
}

void Particles::draw(){
    
}


void Particles::addForce(ofPoint force){
    acc += force;
}


