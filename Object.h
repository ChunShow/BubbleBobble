#pragma once
#include "GL/freeglut.h"
#include <vector>
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
	
	void setVelocity(float v1, float v2);
	float* getVelocity();
	void setVelocityX(float v1);
	float getVelocityX();
	void setVelocityY(float v2);
	float getVelocityY();

	float* getHitbox();

	bool collisionDetection(Object other);
	float position[2];
	float velocity[2];
};

