//
//  NewOne.hpp
//  WK2HW_MYCLASS
//
//  Created by sumsun on 9/13/18.
//

#ifndef NewOne_hpp
#define NewOne_hpp

#include <stdio.h>
#include <ofMain.h>

class NewOne{

              public:
              void setup();
    void update();
    void draw();
              
              float vel;
              float drag;
    float x;
    float y;
    float z;
    float radius1;
    float pct;
    NewOne();
    ofColor color;
    
    vector <NewOne> fewparticles;
    
private:

    };

#endif /* NewOne_hpp */
