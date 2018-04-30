#pragma once

#include "ofMain.h"
#include "ofxTwitter.h"
#include "ofxTextWriter.h"
#include "ofxOsc.h"

//The host should be changed in different internet environment
#define HOST "192.168.x.xxx"

#define PORT 8000


class testApp : public ofBaseApp{

	public:
    
    	ofxTextWriter tr;
        ofxOscSender sender;
    
		void setup();
		void update();
		void draw();
    	void exit();
        void printTweetResults(string query);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxTwitter twitterClient;
        ofxTwitterTweet tweet;
        int actualTweet;
        bool reloadTweet;
        int tweetSum;
        string text;

private:
        set <string> knownResults;
        int searchInterval; // 2 seconds
        bool first;
        int lastRun;
    
    
};
