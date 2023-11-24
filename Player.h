#pragma once
#include "Bubble.h"
#include "Object.h"

class Player: public Object 
{
public:
	//  constructor
	Player();
	Player(int maxLife);

	//  draw mothods
	void drawPixel(float x, float y, int n);
	void drawPlayer();
	void drawHeartPixel(float x, float y, int n, int i);
	void drawLife();

	//  texture methods
	void initTextureImage();
	void initTextureTime();
	void setTextureID(KEY dir, TEXTURE_MOTION motion);
	void setPlayerTexture();

	//  reflect player's collision with a monster
	void giveInvincibility(int frame);
	bool isInvincible();
	bool isBlink();

	/*	change player's x, y coordinates
		when player is out of the window, change the position of player
	*/
	void updatePosition();

	//  draw bubble
	Bubble shoot();

	//  initialize player's position
	void setClearPosition(float x, float y);
	void initializePosition();

	//  gameover and restart methods
	//  determine whether player is alive or not
	bool isAlive();
	//  reset player
	void reset();

	void setDirection(KEY dr);
	KEY getDirection();
	void setState(STATE st);
	STATE getState();
	float getHeight();
	virtual Hitbox getHitbox() override;


	//functions for item effects
	float getSpeedScale();
	void setSpeedScale(float sc);
	bool isDoubleShot();
	void onDoubleShot();
	void offDoubleShot();
	float getDelay();
	float setDelay(float de);
	void increaseLife();

private:
	KEY direction;
	STATE state;
	float height;

	//variables for item effects
	float speedScale = 1.0f;
	float delay = 300.0f;
	bool doubleShot = false;

	//  variables of texture 
	GLuint textureID;
	vector<Texture> leftImage;
	vector<Texture> rightImage;

	//  variables of stage clear 
	bool moveStage;
	float clearPosition[2];

	//  variables of time
	int blinkTime;
	int attackTime;
	int damageTime;
	int fallTime;
	int stayTime;
	float previousX;

	//  the number of left lives of player
	int maxLife;
	int life;
};