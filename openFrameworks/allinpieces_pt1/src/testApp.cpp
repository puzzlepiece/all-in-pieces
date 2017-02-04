#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    sender.setup(HOST, PORT);
    ofBackground(255);
    ofSetFrameRate(30);
    
  //  sound.setMultiPlay( false );
    
    twitterClient.setDiskCache(true);
    twitterClient.setAutoLoadImages(true, false); // Loads images into memory as ofImage;
    
    string const CONSUMER_KEY = "zVsUulyeU789hzg9v3zjqtE17";
    string const CONSUMER_SECRET = "0yhKzRSCYU22I6AnoWYXIFADFIVbgub7uMYup9K6Ftw6CAlGoC";
    //string const ACCESS_TOKEN = "";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET);

    actualTweet = 0;
    
    first = true;
    searchInterval = 30;
    lastRun = ofGetElapsedTimef();
    cout<<"setup time: "<<lastRun<<endl;


    
}

//--------------------------------------------------------------
void testApp::update(){


    
}

//--------------------------------------------------------------
void testApp::draw(){
    cout<< "system start time: "<<lastRun<<endl;
    cout<< "timeElapsed: " << ofGetElapsedTimef()- lastRun << endl;
    cout<< "first? "<<first <<endl;
    
    if (first) {
        cout << "Assert one: This is the first time we call draw() after setup()." << endl;
    }
    
    if (ofGetElapsedTimef() - lastRun > searchInterval || first) {
        if (first) {
            cout << "Assert two: This line should only be printed once; and come along with 'Assert one'." << endl;
        }
        
        printTweetResults("cat");
        lastRun = ofGetElapsedTimef();
        first = false;

    }
    
    for(std::set<string>::iterator it=knownResults.begin(); it!=knownResults.end(); ++it){
    for(int j=0; j< text.length(); j++){
        ofSetColor(0);
        tr.setTimeToRender(20);
        tr.setTextToRender(text);
        
        ofDrawBitmapString(tr.whatToRender(), 10, 10);
        
        ofxOscMessage m;
        
        m.addStringArg(text.substr(j,1));
        cout<<text.substr(j,1)<<endl;
        sender.sendMessage(m);
        
    }
}
    
}

            

/*
        ofSetColor(255, 255, 255, 125);
        if(tweet.isBannerImageLoaded()) {
            tweet.user.profile_banner.draw(0, 0, ofGetWidth(), ofGetHeight());
        }

        ofDrawBitmapString("User:", ofPoint(120,150));
        ofDrawBitmapStringHighlight(tweet.user.screen_name, ofPoint(220,150));
        
        ofDrawBitmapString("Location:", ofPoint(120,180));
        ofDrawBitmapStringHighlight(tweet.user.location, ofPoint(220,180));
        
        ofDrawBitmapString("Descript.:", ofPoint(120,210));
        string desc = tweet.user.description;
        for(int i=0;i<(desc.length()/maxLineSize)+1;i++) {
            ofDrawBitmapStringHighlight(desc.substr(i*maxLineSize,maxLineSize), ofPoint(220,210+(30*i)));
        }

        
        ofDrawBitmapString("Text:", ofPoint(120,300));
        string text = tweet.text;
 
        for(int i=0;i<(text.length()/maxLineSize)+1;i++) {
            ofDrawBitmapStringHighlight(text.substr(i*maxLineSize,maxLineSize), ofPoint(220,300+(30*i)));

        }
*/
            
//            if(text[i]=='c'){
//        ofPushStyle();
//        ofSetColor(255,0,0);
//        ofEllipse(220,100+(10*i), 50, 50);
//        ofPopStyle();
//        cout<< i <<endl;
//        }
//    }
//        ofSetColor(255, 255, 255);
//        if(tweet.isProfileImageLoaded()) {
//            tweet.user.profile_image.draw(40, 150);
//        }
//        
//        ofSetColor(0);
//        string nav = "Now showing tweet: " + ofToString(actualTweet+1) + " of "+ofToString(twitterClient.getTotalLoadedTweets());
//        ofDrawBitmapString(nav, ofPoint(220,420));
//        
//    }
//    ofSetColor(0);
//    string info;
//    info += "ofxTwitter query example:";
//    info += "\nPress 'q' to get tweets containing 'cat'";
//    info += "\nPress 's' to get tweets containing 'cat' with more advanced options";
//    info += "\nPress 'l' to load previous query from disk if avilable";
//    info += "\nPress UP/DOWN to navigate tweets";
//    ofDrawBitmapString(info, ofPoint(20,20));
//
//}

void testApp::printTweetResults(string query) {
    // Initialize search parameters
    ofxTwitterSearch search;
    search.query = query;
    search.lang = "es";
    
    // Run search
    twitterClient.startSearch(search);
    tweetSum = twitterClient.getTotalLoadedTweets();
    
    if(tweetSum > 0) {
        cout<<"Tweet loaded: "<<tweetSum <<endl;
        
        // Read all tweets, and print it to the console/screen only when we haven't seen this tweets before.
        
        for (int i = 0; i < tweetSum; i++) {
            tweet = twitterClient.getTweetByIndex(i);
            text = tweet.text;
           //  vector <ofxTwitterTweet> allTweets;
            
            // If we didn't find
            if (knownResults.find(tweet.text) == knownResults.end()) {
                cout << tweet.text << endl;
                knownResults.insert(tweet.text);
            }
                twitterClient.printDebugInfo();
        }
    }
}

     
        
//
      
//    }

    
    

    
   

void testApp:: exit() {
	printf("exit()\n");
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
//    
//    if(key == 'q') {
//        // Simple Query. You can find tweets containing that word.
//        ofxTwitterSearch search;
//        search.query = "cat";
//        twitterClient.startSearch(search);
//    }
//    
//    if(key == 's') {
//        // Complex search. You can specify more params.
//        ofxTwitterSearch search;
//        search.query = "cat";
//        search.count = 10;
//        search.geocode = ofVec2f(41.3850640,2.1734030);
//        search.geocode_radius = 2;
//        search.bUseMiles = false;
//        search.lang = "es";
//        twitterClient.startSearch(search);
//    }
//    
//    if(key == 'l') {
//        twitterClient.loadCacheFile();
//    }
//    
//    if(key == OF_KEY_UP) {
//        if(actualTweet < twitterClient.getTotalLoadedTweets()-1) actualTweet += 1;
//    }
//    
//    if(key == OF_KEY_DOWN) {
//        if(actualTweet > 0) actualTweet -= 1;
//    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
