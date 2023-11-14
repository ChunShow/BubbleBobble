#pragma once
#include "Bubble.h"
#include "Object.h"

class Player: public Object 
{
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
	void drawBubble();
	
	//  reflect player's contact with other monsters
	void decreaseLife();
	void giveInvincibility(int frame);
	bool isInvincible();

	//  draw bubble
	Bubble shoot();


	//  initialize player's position
	void initializePosition();
	
	//  setter
	void setDirection(KEY dr);
	void setState(STATE st);
	void setFinalPosition();

	//  getter
	KEY getDirection();
	STATE getState();
	float getHeight();
	virtual Hitbox getHitbox() override;

	//  draw player's left lives
	void drawHeartPixel(float x, float y, int n, int i);
	void drawLife();

private:
	KEY direction;
	STATE state;
	float height;
	float finalPosition[2];

	//  blinkTime means a time for which player is blinking
	int blinkTime;

	//  life means the number of left lives of player
	int life;

	bool move;
};