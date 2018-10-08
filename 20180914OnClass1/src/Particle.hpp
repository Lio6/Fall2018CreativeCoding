//
//  Particle.hpp
//  20180914OnClass1
//
//  Created by sumsun on 9/14/18.
//

#pragma once

#include <ofMain.h>


class Particle{
    
public:
    Particle(); //constructor
    
    void setup(ofPoint _pos);
    void update();
    void draw();
    void addForce(ofPoint force);
    
    //variables
    
    void addAttractionForce(ofPoint _pos, float _rad, float scale);
    // _pos: attractor position
    //_pos: distacne from attractoe to apply force
    // scale: how much force to apply
    
    void addRepulsionForce(ofPoint _pos, float _rad, float scale);
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float damp;
    float alpha;
    ofPoint noiseRandomAllSet;

};
