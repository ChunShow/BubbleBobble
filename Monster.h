#pragma once
#include "Object.h"

enum MONSTER { ROBOT, CREATURE, GHOST };

class Monster: public Object
{
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

	void trap(int key);
	bool isTrapped();
	bool isAlive();
	void free();
	void kill();

	//  sette
	void setDirection(KEY drt);

	//  getter
	KEY getDirection();
	float getTime();
	int getTrappedBubble();
	virtual Hitbox getHitbox() override;

private:
	MONSTER type;
	KEY direction;

	bool trapped;
	bool rotation;
	bool alive;
	float angle;
	float time;

	int trappedBubble;
};