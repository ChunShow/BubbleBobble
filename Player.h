#pragma once
#include "Bubble.h"
#include "Object.h"

enum KEY { LEFT, RIGHT, UP, DOWN, SPACEBAR };
enum STATE { STAY, JUMP, FALL };

class Player: public Object {
public:
	//  constructor
	Player();

	//  draw player's dragon pixel image
	void drawPlayer();

	//  dragon pixel image setting
	void drawPixel(float x, float y, int n);
	void leftDragon();
	void rightDragon();
	void leftDragonJUMP();
	void rightDragonJUMP();
	void leftDragonFALL();
	void rightDragonFALL();
	void updatePosition();

	void decreaseLife();
	void giveInvincibility();
	bool isInvincible();

	Bubble shoot();

	//  draw player's left lives
	void drawHeartPixel(float x, float y, int n, int i);
	void drawLife();

	void translate(float x, float y);

	KEY direction;
	STATE state;
	float height;

	//  blinkTime means a time for which player is blinking
	int blinkTime;

	//  life means the number of left lives of player
	int life;
};