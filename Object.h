#pragma once
#include "GL/freeglut.h"
#include "Hitbox.h"
#include "Texture.h"
#include <iostream>
#include <vector>

using namespace std;

enum KEY { LEFT, RIGHT, UP, DOWN, SPACEBAR, RESTART };
enum STATE { STAY, JUMP, FALL };

class Object
{
public:
	//  constructor
	Object();

	//  position methods
	void setPosition(float x, float y);
	float* getPosition();
	void setPositionX(float x);
	float getPositionX();
	void setPositionY(float y);
	float getPositionY();

	//  velocity methods
	void setVelocity(float v1, float v2);
	float* getVelocity();
	void setVelocityX(float v1);
	float getVelocityX();
	void setVelocityY(float v2);
	float getVelocityY();
	
	virtual Hitbox getHitbox();

	void translate(float x, float y);
	bool collisionDetection(Object& other);

private:
	float position[2];
	float velocity[2];
};
