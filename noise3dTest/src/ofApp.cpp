#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    model.loadModel("dodeca.obj");
    light.setPosition(200,300,500);
    
    baseNoise.set(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    baseNoise += ofPoint(.01,.02,.015);
    //same as the counter

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofEnableDepthTest();
    //access the mesh inside the model.
    ofMesh mesh = model.getMesh(0);
    
    
    ofPoint center = mesh.getCentroid();
    //update all the vertices
    auto & verts = mesh.getVertices();
    for(int i = 0; i < verts.size(); i++){
        ofPoint  diff = center - verts[i];
        
        diff = diff.normalize(); //get normalize value from direction
//        verts[i].x += 20;
        
        
        //expand with sin
//        verts[i].x += 1 * diff.x * sin(ofGetElapsedTimef());
//        verts[i].y += 1 * diff.x * sin(ofGetElapsedTimef());
//        verts[i].z += 1* diff.z * sin(ofGetElapsedTimef());

        
        verts[i].x += diff.x * 2 * ofSignedNoise(verts[i].x + baseNoise.x/15, verts[i].y+baseNoise.y/15);
        verts[i].y += diff.y * 2 * ofSignedNoise(verts[i].y + baseNoise.x/15, verts[i].z+baseNoise.y/15);

        verts[i].z += diff.x * 2 * ofSignedNoise(verts[i].z + baseNoise.z/15, verts[i].y+baseNoise.y/15);

        //instead use the noise
    }
    //draw the mesh
    
    light.enable();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
    ofScale(model.getNormalizedScale());//model.getNormalizedScale());
    ofTranslate(0,-15,0);
    mesh.drawFaces();
//    model.drawFaces();
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
