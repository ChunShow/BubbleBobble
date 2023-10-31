#pragma once

enum MONSTER { ROBOT, CREATURE, GHOST };

class Monster {
public:
	//  constructor
	Monster(MONSTER Type);

	//  draw monster's pixel image according to the type
	void drawMonster();

	//  monster pixel image setting
	void drawPixel(float x, float y, int n);
	void leftCreature();
	void rightCreature();

	//  change monster's position (x, y coordinates)
	void setPosition(float x, float y);

	MONSTER type;
	KEY direction;
	float position[2];

	/*  monster's heat box setting
		heatbox[0][0] : the left side of x coordinate
		heatbox[0][1] : the right side of x coordinate
		heatbox[1][0] : the bottom of y coordinate
		heatbox[1][1] : the top of y coordinate
	*/
	float heatbox[2][2];
};