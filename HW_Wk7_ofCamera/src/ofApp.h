#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void cameraMoves();
    void cameraTurn();
    
        void audioIn(ofSoundBuffer & input);
    
        vector <float> left;
        vector <float> right;
        vector <float> volHistory;
    
        int     bufferCounter;
        int     drawCounter;
    
        float smoothedVol;
        float scaledVol;
    
        ofSoundStream soundStream;
    ofLight light;
//    ofEasyCam cam;
        ofCamera cam;
    ofVec3f dian;
    ofMesh mesh;
    
    vector<ofPoint> pts;
    
    ofVec3f camPos;
    ofVec3f desPos;
    ofVec3f folloPos;
    ofVec3f prePos;
    
    float pct;
    bool count;
    int lookAtMe;
    
    float inOutSine (float t);
    float inQuad (float t);



};
