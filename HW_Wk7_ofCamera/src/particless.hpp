#pragma once
#include "ofMain.h"

class Particles{
public:
    
    void setup(ofPoint _pos);
    void update();
    void draw();
    void addForce(ofPoint force);

    
    ofPoint homePos;
    ofPoint startPos;
    ofPoint vel;
    ofPoint acc;
    ofPoint force;
    
    
    
    
};
