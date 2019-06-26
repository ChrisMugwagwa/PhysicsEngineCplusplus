#include <iostream>
#include <string>
#include <math.h>

// here is a new keyword: namespace.
// this allows us to place the test functions
// into their own namespace, so we call
// test::runTests instead of just runTests

namespace test{

  void printError(std::string testName, std::string msg){
    std::cout << "TEST FAILED: " << testName << ": " << msg << std::endl;
  }
  void printSuccess(std::string testName){
    std::cout << "TESTS PASSED: " << testName << std::endl;
  }

  bool test_req1_world_getElapsedFrames(){
    int errors = 0;
    World world(500, 500);
    world.update();
    if (world.getElapsedFrames() != 1){
      printError("test_req1_world_getElapsedFrames", "elapsedframes is not 1 after 1 update");
      errors ++;
    }
    world.update();
    if (world.getElapsedFrames() != 2){
      printError("test_req1_world_getElapsedFrames", "elapsedframes is not 2 after 2 updates");
      errors ++;
    }
    if (errors == 0){
      printSuccess("test_req1_world_getElapsedFrames");
      return true;
    }
    else {
      return false;
    }
  }
  
  bool test_req2_world_addWorldObject(){
    int errors = 0;
    World world(500, 500);
    world.addWorldObject(new WorldObject());
    if (world.getWorldObjects().size() != 1){
      printError("test_req2_world_addWorldObject", "worldobjects vec does not contain 1 object after add");
      errors ++;
    }
    if (errors == 0){
      printSuccess("test_req2_world_addWorldObject");
      return true;
    }
    else {
      return false;
    }
  }

  bool test_req3_worldobject_applyForces(){
    int errors = 0;

    WorldObject obj;
    // should start at a stand still - verify that!
    float y = obj.getY();
    obj.move();
    if (y != obj.getY()){
      printError("test_req3_worldobject_applyForces", "object moved when it has no velocity");
      errors ++;
    }
    // apply a y force and see if it moves
    obj.applyImpulseForce(0, 1.5);
    // now it should have some velocity in the y direction
    obj.move();
    if (obj.getY() != y + 1.5){// y should go up by 1.5 now
      printError("test_req3_worldobject_applyForces", "force incorrectly affected velocity");
      errors ++;
    }
    
    if (errors == 0){
      printSuccess("test_req3_worldobject_applyForces");
      return true;
    }
    else {
      return false;
    }
    
  }

  
  bool test_req4_world_gravity(){
    int errors = 0;
    // create a world, add an object to it
    // call update twice and verify that the object moves more in
    // the second update that the first (acceleration)
    World world(500, 500);
    WorldObject* obj = new WorldObject(5);
    obj->setPosition(25, 25);
    world.addWorldObject(obj);
    // check the position moves under gravity
    float y = obj->getY();
    world.update();
    float diff = obj->getY() - y;
    if (diff <= 0){
      printError("test_req4_world_gravity", "objects do not get moved positively on y by gravity");
      errors ++;
    }
    y= obj->getY() -y;
    // check the position moves more in the second frame due to acceleration
    world.update();
    float diff2 = obj->getY() - y;
    if (diff2 <= diff){
      printError("test_req4_world_gravity", "gravity does not accelerate objects");      
      errors ++;
    }
    delete obj;
    if (errors == 0){
      printSuccess("test_req4_world_gravity");
      return true;
    }
    else {
      return false;
    }
  }

  bool test_req5_worldobject_hasCollided(){
    int errors = 0;

    // create two objects, place them in the same place
    WorldObject* obj1 = new WorldObject(10);
    WorldObject* obj2 = new WorldObject(10);
    obj1->setPosition(40, 40);
    obj2->setPosition(40, 40);

    if (obj1->hasCollided(obj2) == false){
      printError("test_req5_worldobject_hasCollided", "objects in same position have not collided");      
      errors ++;
    }

    // move them just in range, noting that the diameter of each is 5
    obj1->setPosition(40, 40);
    obj2->setPosition(45, 45);

    if (obj1->hasCollided(obj2) == false){
      printError("test_req5_worldobject_hasCollided", "objects overlapping by diameter ");      
      errors ++;
    }

    // move them just in range, noting that the diameter of each is 5
    obj1->setPosition(40, 40);
    obj2->setPosition(47, 47);

    if (obj1->hasCollided(obj2) == false){
      printError("test_req5_worldobject_hasCollided", "objects overlapping at edge ");      
      errors ++;
    }
    // quite far away
    obj1->setPosition(0, 0);
    obj2->setPosition(100, 100);

    if (obj1->hasCollided(obj2) == true){
      printError("test_req5_worldobject_hasCollided", "objects in different position have collided");      
      errors ++;
    }

    if (errors == 0){
      printSuccess("test_req5_worldobject_hasCollided");
      return true;
    }
    else {
      return false;
    }
  }
  
  bool test_req7_worldobject_getCollisionImpulse(){
    int errors = 0;
    
    if (errors == 0){
      printSuccess("test_req7_worldobject_getCollisionImpulse");
      return true;
    }
    else {
      return false;
    }

  }

  bool test_world_two_obj(){
    int errors = 0;

    // create two objects in the world
    // that are heading towards each other and verify that they collide
    // and change direction at some point
    
    World* world = new World(500, 500);
    WorldObject* ball = new WorldObject(10);
    WorldObject* ball2 = new WorldObject(10);

    world->addWorldObject(ball);
    world->addWorldObject(ball2);
    
    ball->setPosition(200, 200);
    ball2->setPosition(200, 400);

    // now keep calling update
    for (int i=0; i<100; i++){
      world->update();
    }
    
    
    if (errors == 0){
      printSuccess("test_world_two_obj");
      return true;
    }
    else {
      return false;
    }
    
  }
  
  void runTests(){
    std::cout << "Running tests! " << std::endl;
    test_req1_world_getElapsedFrames();
    test_req2_world_addWorldObject();    
    test_req3_worldobject_applyForces();
    test_req4_world_gravity();
    test_req5_worldobject_hasCollided();

    test_world_two_obj();
  }

}
