#pragma once
#include "GL/freeglut.h"
class Light
{
public:
	Light();
	void setLightID(int LID);
	void setPosition(float x, float y, float z, float w);
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void draw() const;

	int lightID;
	float pos[4];
	float ambient[4];
	float diffuse[4];
	float specular[4];
};