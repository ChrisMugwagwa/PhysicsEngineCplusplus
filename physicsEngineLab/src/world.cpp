#include "world.h"
#include <iostream>

World::World(float _width, float _height)
{
  frames = 0;
  gravity = 0.01; // y value added to objects each update.
  width = _width;
  height = _height;
}

void World::update(){
  for (int i=0; i<worldObjects.size(); i++){
    // apply gravity
    worldObjects[i]->applyImpulseForce(0, gravity*4);
    // check for collisions
    for (int j=i+1;j<worldObjects.size();j++){
      if (worldObjects[i]->hasCollided(worldObjects[j])){
        //  std::cout << "collide!" << std::endl;
          worldObjects[i]->processCollisionImpulse(worldObjects[j]);
      }
    }
    // call update
    worldObjects[i]->moveAndBounceOffWalls(width, height);
  }
  frames++;
}

const int World::getElapsedFrames(){
  return frames;
}

void World::addWorldObject(WorldObject* obj){
    std::cout << "world::addWorldObject" << std::endl;
  worldObjects.push_back(obj);
  std::cout << "world::addWorldObject added!" << std::endl;

}

std::vector<WorldObject*> World::getWorldObjects(){
  return worldObjects;
}
