#pragma once
#include "Bubble.h"
enum KEY { LEFT, RIGHT, UP, DOWN, SPACEBAR };
enum STATE { STAY, JUMP, FALL };

class Player {
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

	//  change player's position (x, y coordinates)
	void setPosition(float x, float y);
	
	Bubble shoot();

	//  check weather player contacts a monster
	void checkhit(float box[2][2]);

	//  draw player's left lives
	void drawHeartPixel(float x, float y, int n, int i);
	void drawLife();

	KEY direction;
	STATE state;
	float position[2];
	float height;
	float velocity;

	/*  player's hit box setting
		hitbox[0][0] : the left side of x coordinate
		hitbox[0][1] : the right side of x coordinate
		hitbox[1][0] : the bottom of y coordinate
		hitbox[1][1] : the top of y coordinate
	*/  
	float hitbox[2][2];

	//  blinkTime means a time for which player is blinking
	int blinkTime;
	//  life means the number of left lives of player
	int life;
};