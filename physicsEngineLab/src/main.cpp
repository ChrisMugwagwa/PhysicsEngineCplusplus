#include "world.h"
#include "worldobject.h"
#include "tests.h"
#include "ofMain.h"
#include "ofApp.h"


int main(){
  //  World* world = new World();
  //  CircularObject* obj = new CircularObject();

  //  Ball* ball = new Ball(10);
  //  ball->moveToPosition(100, 100);
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context

													// this kicks off the running of my app
													// can be OF_WINDOW or OF_FULLSCREEN
													// pass in width and height too:
	ofRunApp(new ofApp());
  test::runTests();

}



