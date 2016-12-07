#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define OUT_PORT 12345
#define IN_PORT 12000

//--------------------------------------------------------
class ofApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
	
		ofxOscSender sender;
		ofxOscReceiver receiver;

};

