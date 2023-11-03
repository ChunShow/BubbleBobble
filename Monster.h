#pragma once

enum MONSTER { ROBOT, CREATURE, GHOST };

class Monster {
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
	void setPosition(float x, float y);
	void setHitbox();
	void caughtBubble(float bubblePos[2]);
	void setCaught();
	bool getCaught();
	void setRotate();
	bool getRotate();
	float getTime();

	MONSTER type;
	KEY direction;
	float position[2];

	/*  monster's hit box setting
		hitbox[0][0] : the left side of x coordinate
		hitbox[0][1] : the right side of x coordinate
		hitbox[1][0] : the bottom of y coordinate
		hitbox[1][1] : the top of y coordinate
	*/
	float hitbox[2][2];

	bool caught;
	bool rotation;
	float angle;
	float time;
};