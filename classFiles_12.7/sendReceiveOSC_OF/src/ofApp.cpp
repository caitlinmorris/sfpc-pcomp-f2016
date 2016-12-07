#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(40, 100, 40);

	// open an outgoing connection to HOST:PORT
	sender.setup(HOST, OUT_PORT);
	
	//set up a receiver on the localhost input port
	receiver.setup(IN_PORT);

    
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		
		ofxOscMessage m;
		receiver.getNextMessage(m);
		
		// check for incoming message
		if(m.getAddress() == "/test"){
			int incomingX = m.getArgAsInt32(0);
			int incomingY = m.getArgAsInt32(1);
			cout << incomingX << " | " << incomingY << endl;
		}
		else{
			//print out info from unrecognized message
			cout << "Unrecognized message :  " << m.getAddress() << endl;
		}
		
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'a' || key == 'A'){
		ofxOscMessage m;
		m.setAddress("/test");
		m.addIntArg(1);
		m.addFloatArg(3.5f);
		m.addStringArg("hello");
		m.addFloatArg(ofGetElapsedTimef());
		sender.sendMessage(m, false);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	ofxOscMessage m;
	m.setAddress("/mouse");
	m.addIntArg(x);
	m.addIntArg(y);
	sender.sendMessage(m, false);
}


