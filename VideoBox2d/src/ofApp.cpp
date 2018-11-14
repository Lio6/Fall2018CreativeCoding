#include "ofApp.h"
static bool shouldRemove(shared_ptr<ofxBox2dBaseShape>shape) {
    return !ofRectangle(0, -400, ofGetWidth(), ofGetHeight()+400).inside(shape->getPosition());
}

static bool shouldRemovePoly(shared_ptr<ofxBox2dPolygon>shape) {
    return true;
}

//--------------------------------------------------------------
void ofApp::setup(){
    float scale = 1.0;
    bool isShrinking = true;

    
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(320, 240);
    
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    bLearnBakground = true;
    threshold = 127;
    ofBackground(0);
    
    
    // Box2d
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createGround();
    box2d.setFPS(30.0);
    
    bHasShape = false;
    
    myfont.loadFont("castaway.ttf",30);

}


//--------------------------------------------------------------
void ofApp::update(){
    
    bool bNewFrame = false;
    vidGrabber.update();
    
    bNewFrame = vidGrabber.isFrameNew();
    
    if (bNewFrame){
        colorImg.setFromPixels(vidGrabber.getPixels());
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage;        // the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);    // find holes
        
        if(contourFinder.nBlobs > 0){
            if(bHasShape) shape.clear();
            for(int i=contourFinder.blobs[0].pts.size()-1; i>=0; i--) {
                shape.addVertex(contourFinder.blobs[0].pts[i].x*2, contourFinder.blobs[0].pts[i].y*2);
            }
            shape.create(box2d.getWorld());
            bHasShape = true;
        }
        
    }
    
    // add some circles every so often
    if((int)ofRandom(0, 10) == 0) {
        auto circle = std::make_shared<ofxBox2dCircle>();
        
        circle->setPhysics(0.3, 0.5, 0.1);
        circle->setup(box2d.getWorld(), (ofGetWidth()/2)+ofRandom(-20, 20), -20, ofRandom(10, 20));
        circles.push_back(circle);
    }
    
    // remove shapes offscreen
    ofRemove(circles, shouldRemove);
    // ofRemove(polyShapes, shouldRemove);
    
    box2d.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    vidGrabber.draw(0,0,640,480);
    
    ofLogNotice() << contourFinder.nBlobs;
    
//    if(contourFinder.nBlobs > 0){
//        contourFinder.blobs[0].draw(0,0);
//    }
    
    grayBg.draw(0,0,320,240);
    grayDiff.draw(320,0,320,240);
    // some circles :)
    for(int i=0; i<circles.size(); i++) {
        ofNoFill();
        ofSetHexColor(255);
//        circles[i]->draw();
        ofVec2f pos = circles[i]->getPosition();
        
        vector<string> St = ["A", "B" , "C"];
//        ofDrawBitmapString(St,pos.x,pos.y);
        myfont.drawString(St,pos.x,pos.y);
//        ofDrawBitmapString(St,circles[1].getPoint.x,circles[2].get.y);
    }
    
    ofFill();
    ofSetColor(255);
    shape.draw();
    
//    if (contourFinder.nBlobs < 10 && contourFinder.nBlobs >5 ){
//        if(bHasShape) shape.clear();
//        for(int i=contourFinder.blobs[0].pts.size()-1; i>=0; i--) {
//            dropShape.addVertex(contourFinder.blobs[0].pts[i].x*2, contourFinder.blobs[0].pts[i].y*2);
//        }
//        dropShape.create(box2d.getWorld());
////        dropShape.setPhysics(5, 5, 10);
//        bHasShape = true;
//
//        ofSetColor(255,0,0);
//        dropShape.draw();
//
//    }

//    string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
//    ofDrawBitmapString(fpsStr, 100,100);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'b' )bLearnBakground = true;
    else if(key=='+') threshold++;
    else if(key == '-') threshold--;

    ofLog() << threshold;
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
