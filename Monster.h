#pragma once
#include "Object.h"

enum MONSTER { ROBOT, CREATURE, GHOST };

class Monster: public Object
{
public:
	//  constructor
	Monster(MONSTER Type);

	//  draw methods
	void drawMonster();
	void drawRotate();

	//  texture methods
	void initTextureImage();
	void setTextureID(KEY dir);

	//  reflect monster's collision with a bubble
	void trap(int key);
	bool isTrapped();
	bool isAlive();
	void kill();
	void free();

	void setDirection(KEY drt);
	KEY getDirection();
	MONSTER getType();
	int getTrappedBubble();
	virtual Hitbox getHitbox() override;

private:
	MONSTER type;
	KEY direction;

	//  variables of texture 
	GLuint textureID;
	Texture leftImage;
	Texture rightImage;

	bool trapped;
	int trappedBubble;
	bool rotation;
	bool alive;
	float rotateAngle;

};