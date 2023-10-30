#pragma once
#include "Light.h"
#include "Material.h"

enum DIRECT { D_LEFT, D_RIGHT, D_UP };

class Bubble
{
public:
	void setPos(float x, float y);
	void setMaterial(Material m);
	void setSize(float s);
	void setDirection(DIRECT d);
	void initialize();
	void draw();

	float size;
	float pos[2];
	DIRECT direction;
	Material mtl;

};

