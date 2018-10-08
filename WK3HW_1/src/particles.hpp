
#include "ofMain.h"


class Particle{
 
    
public:
    
    Particle(); //constructor
    void setup(ofPoint _pos);
    void update();
    void draw();
    void addForce(ofPoint force);
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;

    float damp;

     void addAttractionForce(ofPoint _pos, float _rad, float scale);
    
    void noiseMove();
    void drawCircles(int _alph);
    void drawRects(int _alph);
    void drawTriangle(int _alph);
    void draweightangles(int _alph);
    
    ofImage triangle;
    ofImage rectangle;
    ofImage eightangles;
    
    float angle;
};

