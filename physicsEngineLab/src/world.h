#include <vector>
#include "worldobject.h"

#ifndef WORLD_H
#define WORLD_H


class World
{
public:
    World(float _width, float _height);
    void addWorldObject(WorldObject* obj);
    std::vector <WorldObject*> getWorldObjects();
    void update();
    const int getElapsedFrames();
 private:

    void applyGravity();
    
    std::vector <WorldObject*> worldObjects;
    int frames;
    float gravity;
    float width;
    float height;
};

#endif // WORLD_H
