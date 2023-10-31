#pragma once
#include "Light.h"
#include "Material.h"
#include <vector>
#include <ctime>

using namespace std;
enum DIRECT { D_LEFT, D_RIGHT, D_UP };

class Bubble
{
public:
	Bubble();
	void setPos(float x, float y);
	void setMaterial(Material m);
	void setSize(float s);
	void setDirection(DIRECT d);
	void initialize();
	bool checkVerticalBoundary();
	bool checkUpperBoundary();
	bool isGrown();
	bool isCapturing();
	bool characterCollisionCheck(float hitbox[2][2]);
	bool mapCollision(vector<vector<float>> borderHard);
	float getRadius();
	clock_t getCreatedTime();
	void draw();

	float size;
	float speed;
	float pos[2];
	bool capturing;
	bool alive;
	clock_t createdTime;
	DIRECT direction;
	Material mtl;

};

