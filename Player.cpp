#include "main.h"

//  constructor
Player::Player(){}
Player::Player(int maxLife) : direction(RIGHT), state(STAY), height(0.16f), moveStage(false), maxLife(maxLife), life(maxLife)
{
	setPosition(-0.95f, -0.95f);
	setClearPosition(1.0f, 1.0f);
	initTextureImage();
	initTextureTime();
}

//  draw mothods
void Player::drawPixel(float x, float y, int n)
{
	glBegin(GL_POLYGON);
	glVertex2f(getPositionX() + x, getPositionY() + y);
	glVertex2f(getPositionX() + x, getPositionY() + y + 0.01f);
	glVertex2f(getPositionX() + x + n * 0.01f, getPositionY() + y + 0.01f);
	glVertex2f(getPositionX() + x + n * 0.01f, getPositionY() + y);
	glEnd();
}
void Player::drawPlayer()
{
	float length = 0.2f;
	if (moveStage) length = 0.3f;

	setPlayerTexture();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(getPositionX() + 0.0f, getPositionY() + length);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(getPositionX() + length, getPositionY() + length);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(getPositionX() + length, getPositionY() + 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(getPositionX() + 0.0f, getPositionY() + 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void Player::drawHeartPixel(float x, float y, int n, int i) {
	glBegin(GL_POLYGON);
	glVertex2f(-0.99f + i * 0.08f + x, -0.995f + y);
	glVertex2f(-0.99f + i * 0.08f + x, -0.995f + y + 0.01f);
	glVertex2f(-0.99f + i * 0.08f + x + n * 0.01f, -0.995f + y + 0.01f);
	glVertex2f(-0.99f + i * 0.08f + x + n * 0.01f, -0.995f + y);;
	glEnd();
}
void Player::drawLife()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < life; i++) {
		drawHeartPixel(0.02f, 0.00f, 1, i);
		drawHeartPixel(0.01f, 0.01f, 3, i);
		drawHeartPixel(0.00f, 0.02f, 5, i);
		drawHeartPixel(0.01f, 0.03f, 1, i);
		drawHeartPixel(0.03f, 0.03f, 1, i);
	}
}

//  texture methods
void Player::initTextureImage()
{
	for (int i = 0; i < 8; i++) {
		leftImage.push_back(Texture(_PLAYER, _LEFT, (TEXTURE_MOTION)i));
		leftImage[i].initTexture();
		rightImage.push_back(Texture(_PLAYER, _RIGHT, (TEXTURE_MOTION)i));
		rightImage[i].initTexture();
	}
}
void Player::initTextureTime()
{
	blinkTime = 0;
	attackTime = 0;
	damageTime = 0;
	fallTime = 0;
	stayTime = 0;
	previousX = getPositionX();
}
void Player::setTextureID(KEY dir, TEXTURE_MOTION motion)
{
	if (dir == LEFT) {
		textureID = leftImage[motion].getTextureID();
	}
	else textureID = rightImage[motion].getTextureID();
}
void Player::setPlayerTexture()
{
	if (moveStage) {
		setTextureID(direction, _CLEAR);
		return;
	}

	if (attackTime > 0 && damageTime > 0) {
		if (attackTime-- > damageTime--) setTextureID(direction, _ATTACK);
		else setTextureID(direction, _DAMAGE);
		return;
	}
	else if (attackTime-- > 0) {
		setTextureID(direction, _ATTACK);
		return;
	}
	else if (damageTime-- > 0) {
		setTextureID(direction, _DAMAGE);
		return;
	}

	switch (state) {
	case JUMP:
		setTextureID(direction, _JUMP);
		break;
	case FALL:
		if ((fallTime++ % 40) < 20) setTextureID(direction, _FALL1);
		else setTextureID(direction, _FALL2);
		break;
	case STAY:
		if ((stayTime++ % 16) < 8) setTextureID(direction, _STAY1);
		else setTextureID(direction, _STAY2);
		if (previousX == getPositionX()) stayTime--;
		previousX = getPositionX();
		break;
	}
}

//  reflect player's collision with a monster
void Player::giveInvincibility(int frame)
{
	life -= 1;
	blinkTime = frame;
	damageTime = 8;
}
bool Player::isInvincible()
{
	return blinkTime > 0;
}
bool Player::isBlink()
{
	if (blinkTime != 0) {
		blinkTime--;
		if (blinkTime % 4 == 0 || blinkTime % 4 == 1) {
			return false;
		}
		return true;
	}
	return false;
}

/*	change player's x, y coordinates
	when player is out of the window, change the position of player
*/
void Player::updatePosition()
{
	//  out of the left side
	if ((direction == KEY::LEFT) && (getPositionX() + 0.01f < -1.2f)) {
		setPositionX(1.05f);
	}
	//  out of the right side
	else if ((direction == KEY::RIGHT) && (getPositionX() + 0.16f > 1.2f)) {
		setPositionX(-1.18f);
	}

	//  out of the bottom side
	if (getPositionY() < -1.2f) {
		setPositionY(1.0f);
	}
}

//  draw bubble
Bubble Player::shoot()
{
	attackTime = 8;

	Bubble bubble;
	bubble.initialize();
	float x = getPositionX(); float y = getPositionY();

	bubble.setSize(0.1f);
	if (direction == KEY::LEFT) {
		bubble.setPosition(x, y + 0.1f);
		bubble.setDirection(DIRECT::D_LEFT);
	}
	else {
		bubble.setPosition(x + 0.1f, y + 0.1f);
		bubble.setDirection(DIRECT::D_RIGHT);
	}
	bubble.createdTime = clock();
	bubble.draw();
	return bubble;
}

//  initialize player's position
void Player::setClearPosition(float x, float y)
{
	clearPosition[0] = x;
	clearPosition[1] = y;
}
void Player::initializePosition()
{
	if (clearPosition[0] == 1.0f && clearPosition[1] == 1.0f) setClearPosition(getPositionX(), getPositionY());

	moveStage = true;
	if ((getPositionX() <= -0.95f) && (getPositionY() <= -0.95f)) {
		moveStage = false;
		direction = RIGHT;
		setPosition(-0.95f, -0.95f);
		setClearPosition(1.0f, 1.0f);
	}
	else if (getPositionX() <= -0.95f) {
		setPositionX(-0.95f);
		translate(0.0f, -(clearPosition[1] + 0.95f) / 150);
	}
	else if (getPositionY() <= -0.95f) {
		setPositionY(-0.95f);
		translate(-(clearPosition[0] + 0.95f) / 150, 0.0f);
	}
	else translate(-(clearPosition[0] + 0.95f) / 150, -(clearPosition[1] + 0.95f) / 150);
}

//  gameover and restart methods
bool Player::isAlive()
{
	return (life >= 1);
}
void Player::reset()
{
	direction = KEY::RIGHT;
	setPosition(-0.95f, -0.95f);
	life = maxLife;
	initTextureTime();
}

void Player::setDirection(KEY dr)
{
	direction = dr;
}
KEY Player::getDirection()
{
	return direction;
}
void Player::setState(STATE st)
{
	state = st;
}
STATE Player::getState()
{
	return state;
}
float Player::getHeight()
{
	return height;
}
Hitbox Player::getHitbox()
{
	float xLeft = getPositionX() + 0.03f;
	float xRight = getPositionX() + 0.14f;
	float yBottom = getPositionY();
	float yTop = getPositionY() + 0.13f;

	return Hitbox(xLeft, xRight, yBottom, yTop);
};
