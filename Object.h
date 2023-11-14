#pragma once
#include "GL/freeglut.h"
#include "Hitbox.h"
#include <iostream>

using namespace std;

enum KEY { LEFT, RIGHT, UP, DOWN, SPACEBAR, RESTART };
enum STATE { STAY, JUMP, FALL };

class Object
{
public:
	Object();

	//  setter
	//  set position of object
	void setPosition(float x, float y);
	void setPositionX(float x);
	void setPositionY(float y);
	//  set velocity of object
	void setVelocity(float v1, float v2);
	void setVelocityX(float v1);
	void setVelocityY(float v2);

	//  getter
	//  get position of object
	float* getPosition();
	float getPositionX();
	float getPositionY();
	//  get velocity of object
	float* getVelocity();
	float getVelocityX();
	float getVelocityY();
	//  get hitbox of object
	virtual Hitbox getHitbox();

	void translate(float x, float y);
	bool collisionDetection(Object& other);

private:
	float position[2];
	float velocity[2];
};
