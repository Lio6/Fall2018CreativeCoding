#include "Clock.hpp"

ofClock::ofClock()
{
//    //Make everything looking nice and smooth.
//    ofSetCircleResolution(100);
//    ofEnableSmoothing();
//    
//    //Set size & position of our clock
//    if( ofGetHeight() < ofGetWidth() )
//        radius = (ofGetHeight()/2)-20;
//    else
//        radius = (ofGetWidth()/2)-20;
//    
//    top = (ofGetHeight()/2);
//    left = (ofGetWidth()/2);
}

void ofClock::clockupdate( int sec, int min, int hour ){
    
//    secondsAngle = 6 * sec;
//    minutesAngle = 6 * min;
//    hoursAngle = 30 * hour + (min / 2);
}

void ofClock::draw(){
    
//    //Set the coortinatesystem to the center of the clock.
//    ofPoint circle_center = ofPoint( left, top );
//    ofTranslate(circle_center);
//    ofRotateZ(-90);
//    
//    //Draw background of the clock
//    ofSetHexColor(0xbbbbbb);
//    ofFill();
//    ofCircle( ofPoint(0,0), radius );
//    
//    //Draw Outline of the clock
//    ofSetLineWidth( (radius/100)*4 );
//    ofNoFill();
//    ofSetHexColor(0x888888);
//    ofCircle( ofPoint(0,0), radius );
//    
//    //Draw the clock face
//    ofSetLineWidth(1);
//    
//    for(int i=0;i<12;i++){
//        ofRotateZ( 30 );
//        
//        ofFill();
//        ofRect( ofPoint( (radius/10)*8, -((radius/100)*2) ), (radius/100)*20, (radius/100)*4 );
//        ofNoFill();
//        ofRect( ofPoint( (radius/10)*8, -((radius/100)*2) ), (radius/100)*20, (radius/100)*4 );
//    }
//    
//    //Draw the hour hand
//    ofPushMatrix();
//    
//    ofSetHexColor(0xFF0000);
//    ofRotateZ( hoursAngle );
//    
//    ofFill();
//    ofRect( 0,-((radius/100)*5),(radius/10)*6, (radius/100)*10 );
//    ofNoFill();
//    ofRect( 0,-((radius/100)*5),(radius/10)*6, (radius/100)*10 );
//    
//    ofPopMatrix();
//    
//    //Draw the minute hand
//    ofPushMatrix();
//    
//    ofSetHexColor(0xFF6666);
//    ofRotateZ( minutesAngle );
//    
//    ofFill();
//    ofRect( 0,-((radius/100)*4),(radius/10)*7, (radius/100)*8 );
//    ofNoFill();
//    ofRect( 0,-((radius/100)*4),(radius/10)*7, (radius/100)*8 );
//    
//    ofPopMatrix();
//    
//    //Draw the second hand
//    ofPushMatrix();
//    
//    ofSetHexColor(0xFF9999);
//    ofRotateZ( secondsAngle );
//    
//    ofFill();
//    ofRect( -((radius/100)*2),-((radius/100)*2),(radius/10)*9, (radius/100)*4 );
//    ofNoFill();
//    ofRect( -((radius/100)*2),-((radius/100)*2),(radius/10)*9, (radius/100)*4 );
//    
//    ofPopMatrix();
//    
//    ofFill();
//    ofSetHexColor(0xFF9999);
//    ofCircle( ofPoint(0,0), (radius/100)*6 );
}
