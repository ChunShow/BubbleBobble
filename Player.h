#pragma once
#include "Bubble.h"
enum KEY { LEFT, RIGHT, UP, DOWN, SPACEBAR };
enum STATE { STAY, JUMP, FALL };

class Player {
public:
	Player();

	void drawPlayer();
	void drawPixel(float x, float y, int n);
	void leftDragon();
	void rightDragon();
	void setPosition(float x, float y);
	Bubble shoot();

	KEY direction;
	STATE state;
	float position[2];
	float height;
	float velocity;
};