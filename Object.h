#pragma once
#include "GL/freeglut.h"
#include <vector>
#include <iostream>

using namespace std;

class Object
{
	Object();
	void setPosition(float x, float y);
	void setVelocity(float v1, float v2);
	bool collisionDetection(Object obj1, Object obj2);

	float* getHitbox();

	float position[2];
	float velocity[2];
};

