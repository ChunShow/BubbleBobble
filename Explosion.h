#pragma once
#include "GL/freeglut.h"
#include "Material.h"
#include <ctime>
#include <cmath>

class Explosion
{
public:
	Explosion(float x, float y, bool trapping);
	void increase(float d);
	void draw();
	bool isAlive();

private:
	float center[2];
	float distance;
	bool trapping;
	bool alive;
	clock_t creationTime;
	float radius = 0.01f;
	clock_t lifeTime = 200;
	
	Material mtl;
};

