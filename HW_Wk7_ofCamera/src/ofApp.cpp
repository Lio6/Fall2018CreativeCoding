#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    light.setPosition(100,100,300);
    dian.set(0,0,0);
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    ofBackground(54, 54, 54);
    
    soundStream.printDeviceList();
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter    = 0;
    drawCounter        = 0;
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
    
    
    ofSoundStreamSettings settings;
    
    auto devices = soundStream.getMatchingDevices("default");
    if(!devices.empty()){
        settings.setInDevice(devices[0]);
    }
    
    settings.setInListener(this);
    settings.sampleRate = 44100;
    settings.numOutputChannels = 0;
    settings.numInputChannels = 2;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);

    for(int i=0; i<200;i++){
        ofPoint p = ofPoint (0,-i*10 +500,0);
        pts.push_back(p);
    }
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);


    
    cam.setPosition(0,100,0);
    folloPos.set(250, 250,250);
//    folloPos.set(0,0,0);


}

//--------------------------------------------------------------
void ofApp::update(){

//    cam.setPosition(200, 100, 100);
//    cam.orbitDeg(ofGetElapsedTimef()*5, ofGetElapsedTimef()*3, 50);

    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    
    mesh.clear();
    float thickness = 0;
    for(int i=0;i<pts.size();i++){
        
        pts[i].x = ofSignedNoise(scaledVol*10, pts[i].y*.1)*10;
//        pts[i].x = ofNoise(scaledVol*10, pts[i].y*.1);
//        pts[i].z = ofNoise(scaledVol*100, pts[i].y*.1, scaledVol*100);
//        pts[i].x = ofNoise(scaledVol, pts[i].y*.1);
        
        
        //get prec and current points
        ofPoint prev = pts[i-1];
        ofPoint curr = pts[i];
        
        ofPoint dir = (curr-prev).normalize();
        
        //get the offset sides of the ribbon
        ofVec3f sideA = dir.getRotated(-90, ofVec3f(0,1,0));
        ofVec3f sideB = dir.getRotated(90,ofVec3f(0,1,0));
        ofVec3f sideC =dir.getRotated(90,ofVec3f(0,0,1));
//        ofVec3f sideD = dir.getRotated(-90, ofVec3f(0,0,1));
        
        //calculate pts offset from to otiginal in perpendicular directions
        ofVec3f ptA = curr + sideA * thickness;
        ofVec3f ptB = curr + sideB * thickness;
        ofVec3f ptC = curr + sideC * thickness;
//        ofVec3f ptD = curr + sideD * thickness;
        
        //add vertices to the mesh
        mesh.addVertex(ptA);
        mesh.addVertex(ptB);
//        mesh.addVertex(ptC);
//        mesh.addVertex(ptD);
        
        thickness += 5;
    }
    
    if(count == true){
        if(pct<1)pct+=0.005;

        float mPct1 = inOutSine(pct);
        float nPct1 = inQuad(pct);

        folloPos = (1-mPct1)*folloPos +mPct1*pts[lookAtMe];
        cam.lookAt(folloPos);

        desPos = pts[lookAtMe]+100;
        camPos = (1-nPct1)*camPos+nPct1*desPos;
        prePos = camPos;
        cam.setPosition(camPos);// 从这里开始，加pct的变化函数。pick random的point在array 里= boxes
    }

    
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    
        light.enable();
    
        //    ofDrawSphere(0, 0,0, scaledVol * 190.0f);
            mesh.draw();
//            cam.lookAt(dian);
    
        light.disable();
    
  
    
    cam.end();
}

void ofApp::audioIn(ofSoundBuffer & input){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (size_t i = 0; i < input.getNumFrames(); i++){
        left[i]        = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
    
    
}

float ofApp::inOutSine(float t){
    return 0.5 * (1+sin(PI*(t-0.5)));
}

float ofApp::inQuad(float t){
    return t * t;
}

void ofApp::cameraMoves(){
    
    
//    color.set(255, 255, 0);
    
    
    pct = 0;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    cameraMoves();
    count = true;
    lookAtMe = ofRandom(200);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

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
