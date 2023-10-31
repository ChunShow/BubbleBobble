#pragma once
#include "Light.h"
#include "Material.h"

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
	void draw();

	float size;
	float pos[2];
	bool capturing;
	DIRECT direction;
	Material mtl;

};

