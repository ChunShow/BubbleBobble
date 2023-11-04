#pragma once
#include "GL/freeglut.h"
#include "Hitbox.h"
#include <iostream>

using namespace std;

class Object
{
public:
	Object();
	void setPosition(float x, float y);
	float* getPosition();
	void setPositionX(float x);
	float getPositionX();
	void setPositionY(float y);
	float getPositionY();

	void translate(float x, float y);
	
	void setVelocity(float v1, float v2);
	float* getVelocity();
	void setVelocityX(float v1);
	float getVelocityX();
	void setVelocityY(float v2);
	float getVelocityY();

	virtual Hitbox getHitbox();

	bool collisionDetection(Object& other);

private:
	float position[2];
	float velocity[2];
};

