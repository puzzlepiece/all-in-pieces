#pragma once

#include "ofMain.h"
#include "ofxTwitter.h"
#include "ofxTextWriter.h"
#include "ofxOsc.h"

//The host should be changed in different internet environment
//#define HOST "149.31.121.51"//"149.31.121.129"
#define HOST "192.168.0.205"//"192.168.1.140"//"149.31.121.246"//
//"149.31.121.100"//"149.31.121.44"//"192.168.1.136"//"149.31.121.102"

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
//    ofSoundPlayer sound, sound2, sound3, sound4, sound5, sound6, sound7, sound8;
//    vector <ofSoundPlayer> soundCollection;
    
//        ofImage userImage;
    
    
};
