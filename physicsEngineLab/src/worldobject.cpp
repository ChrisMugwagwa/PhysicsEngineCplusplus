#include "worldobject.h"
#include "ofApp.h"
#include <iostream>
#include <cmath>        // std::abs

WorldObject::WorldObject()
{
  dx = 0;
  dy = 0;
  y = 0; // top of the screnn.
  x = 0; // left of the screen.
  diameter = 10; // assuming a naive shape for now...
  spring = 0.05;
  friction = -0.9;
}

WorldObject::WorldObject(float _diameter)
{
  dx = 0;
  dy = 0;
  y = 0; // top of the screnn.
  x = 0; // left of the screen.
  diameter = _diameter; // assuming a naive shape for now...
  spring = 0.05;
  friction = -0.9;
}

const float WorldObject::getY(){
  return y;
}
const float WorldObject::getX(){
  return x;
}
const float WorldObject::getDiameter(){
    return diameter;
}
void WorldObject::setPosition(float _x, float _y){
  x = _x;
  y = _y;
}

void WorldObject::move(){
    x += dx;
    y += dy;
}
void WorldObject::moveAndBounceOffWalls(float width, float height){
     x += dx;
     y += dy;
     if (x + diameter/2 > width) {
       x = width - diameter/2;
       dx *= friction;
     }
     else if (x - diameter/2 < 0) {
       x = diameter/2;
       dx *= friction;
     }
     if (y + diameter/2 > height) {
       y = height - diameter/2;
       dy *= friction;
     }
     else if (y - diameter/2 < 0) {
       y = diameter/2;
       dy *= friction;
     }
}

void WorldObject::applyImpulseForce(float _dx, float _dy){
  dx += _dx;
  dy += _dy;
}

bool WorldObject::hasCollided(WorldObject* other){
    float dist_x = other->x - x;
    float dist_y = other->y - y;
    float distance = sqrt(dist_x*dist_x + dist_y*dist_y);
    float minDist = other->diameter/2 + diameter/2;
    if (distance < minDist) {
        return true;
    }
    else{
        return false;
    }
}

void WorldObject::processCollisionImpulse(WorldObject* other){
    float dist_x = other->x - x;
    float dist_y = other->y - y;
    //float distance = sqrt(dist_x*dist_x + dist_y*dist_y);
    float minDist = other->diameter/2 + diameter/2;
    //if (distance < minDist) {
    float angle = atan2(dist_y, dist_x);
    float targetX = x + cos(angle) * minDist;
    float targetY = y + sin(angle) * minDist;
    float ax = (targetX - other->x) * spring;
    float ay = (targetY - other->y) * spring;
    dx -= ax;
    dy -= ay;
    other->dx += ax;
    other->dy += ay;
}

void WorldObject::computeCollisionAndImpulse(WorldObject* other){
    float dist_x = other->x - x;
    float dist_y = other->y - y;
    float distance = sqrt(dist_x*dist_x + dist_y*dist_y);
    float minDist = other->diameter/2 + diameter/2;
    if (distance < minDist) {
        float angle = atan2(dist_y, dist_x);
        float targetX = x + cos(angle) * minDist;
        float targetY = y + sin(angle) * minDist;
        float ax = (targetX - other->x) * spring;
        float ay = (targetY - other->y) * spring;
        dx -= ax;
        dy -= ay;
        other->dx += ax;
        other->dy += ay;
    }

}

void WorldObject::stop(){
    dx = 0;
    dy = 0;
}

Ball::Ball(float diameter, float r, float g, float b)
{
}

void Ball::draw()
{
	ofSetColor(red, green, blue);
	ofDrawCircle(posx, posy, radi);

}

void Ball::setPosition(float x,float y)
{
	posx = x;
	posy = y;
}
