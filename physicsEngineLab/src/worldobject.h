#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

class WorldObject
{
public:
  WorldObject();
    WorldObject(float _size);
    // using const to make it explicit that caller should not intefere with it
    const float getX();
    const float getY();
    const float getDiameter();
    void setPosition(float _x, float _y);

    void move();
    void moveAndBounceOffWalls(float width, float height);
    /** apply the sent impulse force to the object */
    void applyImpulseForce(float _dx, float _dy);
    /** test if the I have collided with the sent object */
    bool hasCollided(WorldObject* otherj);
     /** computes and applies the coliision vector to the two objects. assumes you have already run hasColided and they collided.*/
    void processCollisionImpulse(WorldObject* other);
    /** deals with the collision and collision impulse in one*/
    void computeCollisionAndImpulse(WorldObject* other);

    /** stop moving */
    void stop();
 private:
    float x;
    float y;
    float dx;
    float dy;
    float diameter;
    /** spring is the force applied to colliding objects */
    float spring;
    /** friction is the scalar applied to velocity after hitting a wall */
    float friction;
};
class Ball{
private:
	float red ;
	float green ;
	float blue ;
	float radi;
	float posx;
	float posy;
public:
	Ball(float diameter, float r, float g, float b);
	void draw();
	void setPosition(float x, float y);






}

#endif // WORLDOBJECT_H
