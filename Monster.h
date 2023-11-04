#pragma once
#include "Object.h"

enum MONSTER { ROBOT, CREATURE, GHOST };

class Monster: public Object {
public:
	//  constructor
	Monster(MONSTER Type);

	//  draw monster's pixel image according to the type
	void drawMonster();
	void drawRotate();

	//  monster pixel image setting
	void drawPixel(float x, float y, int n);
	void leftCreature();
	void rightCreature();

	//  change monster's position (x, y coordinates)
	void caughtBubble(float bubblePos[2]);
	void setCaught();
	bool getCaught();
	void setRotate();
	bool isRotating();
	float getTime();

	virtual Hitbox getHitbox() override;

	MONSTER type;
	KEY direction;

	bool caught;
	bool rotation;
	float angle;
	float time;
};