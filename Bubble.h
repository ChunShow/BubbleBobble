#pragma once
#include "Light.h"
#include "Material.h"
#include <vector>
#include <ctime>
#include "Object.h"

using namespace std;
enum DIRECT { D_LEFT, D_RIGHT, D_UP };

class Bubble: public Object
{
public:
	Bubble();
	void setMaterial(Material m);
	void setSize(float s);
	void setDirection(DIRECT d);
	void initialize();
	void grow();
	
	bool checkVerticalBoundary();
	bool checkUpperBoundary();
	
	bool isGrown();
	bool isTrapping();
	bool isAlive();

	void kill();
	bool mapCollision(vector<vector<float>> borderHard);

	float getRadius();
	virtual Hitbox getHitbox() override;
	clock_t getCreatedTime();
	void draw();

	float size;
	bool trapping;
	bool alive;
	clock_t createdTime;
	DIRECT direction;
	Material mtl;

	float horizontal_speed = 0.09f;
	float max_radius = 0.08f;
	
};

