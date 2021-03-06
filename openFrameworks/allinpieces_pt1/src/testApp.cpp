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
    

void testApp:: exit() {
	printf("exit()\n");
}


//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}
