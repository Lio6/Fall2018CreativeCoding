//
//  NewOne.cpp
//  WK2HW_MYCLASS
//
//  Created by sumsun on 9/13/18.
//

#include "NewOne.hpp"

NewOne::NewOne(){
    
}


void NewOne::setup(){
    
    
    x = ofRandom(0,ofGetWidth());
    y = ofRandom(0,ofGetHeight());
//    radius1 = ofRandom(ofGetMouseX(),ofGetMouseY());
    
    
//    fewparticles.resize(100);
//    
//    for(int i=0; i<fewparticles.size();i++){
//        
//        
//        fewparticles[i].setup();
//    }
}

void NewOne::update(){
    

    pct = ofRandom(0.01,0.06);
    x = (1-pct)* x + pct * (ofGetMouseX());
    y = (1-pct)* y + pct * (ofGetMouseY());
//    z = (1-pct)* x + pct * (ofGetMouseX())-10;
    
    if (x< ofGetWidth()/2){
        radius1 = ofRandom(1,5);
    }else {
        radius1 = ofRandom(5,10);
    }
    
    
    
    
}

void NewOne::draw(){
    
    ofSetColor(227,197,43);
    ofDrawCircle(x, y, radius1);
}


