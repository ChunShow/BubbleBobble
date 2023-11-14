#pragma once
#include "Bubble.h"
#include "Object.h"
#include "Texture.h"
#include <vector>

class Player: public Object 
{
public:
	//  constructor
	Player();

	//  draw player's dragon pixel image
	void drawPlayer();

	//  dragon pixel image setting
	void drawPixel(float x, float y, int n);

	void left_ATTACK();
	void left_DAMAGE();
	void left_FALL1();
	void left_FALL2();
	void left_STAY1();
	void left_STAY2();
	void left_JUMP();

	void right_ATTACK();
	void right_DAMAGE();
	void right_FALL1();
	void right_FALL2();
	void right_STAY1();
	void right_STAY2();
	void right_JUMP();

	void updatePosition();
	
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

	// determine whether player is alive or not;
	bool isAlive();

	// reset player
	void reset();

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
	vector<Texture> leftImage;
	vector<Texture> rightImage;
};