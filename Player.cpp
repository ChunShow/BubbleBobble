#include "main.h"

//  initial setting of player
Player::Player() : direction(KEY::RIGHT), state(STAY), height(0.18f), blinkTime(0), life(5) 
{
	setPosition(-0.95f, -0.95f);
	setFinalPosition();
	for (int i = 0; i < 8; i++) {
		leftImage.push_back(Texture(_PLAYER, _LEFT, (TEXTURE_MOTION)i));
		leftImage[i].initTexture();
	}
	for (int i = 0; i < 8; i++) {
		rightImage.push_back(Texture(_PLAYER, _RIGHT, (TEXTURE_MOTION)i));
		rightImage[i].initTexture();
	}
}

void Player::drawPlayer() 
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	if (blinkTime % 4 == 0 || blinkTime % 4 == 1) {
		//  draw player's left image
		if (direction == LEFT) {
			if (state == JUMP) left_JUMP();
			else if (state == FALL) left_FALL1();
			else left_STAY1();
		}
		//  draw player's right image
		else {
			if (state == JUMP) right_JUMP();
			else if (state == FALL) right_FALL1();
			else right_STAY1();
		}
		if (blinkTime != 0) blinkTime--;
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(getPositionX() + 0.0f, getPositionY() + 0.2f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(getPositionX() + 0.2f, getPositionY() + 0.2f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(getPositionX() + 0.2f, getPositionY() + 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(getPositionX() + 0.0f, getPositionY() + 0.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);

	}
	else blinkTime--;

	drawLife();
}

void Player::drawPixel(float x, float y, int n) 
{
	glBegin(GL_POLYGON);
	glVertex2f(getPositionX() + x, getPositionY() + y);
	glVertex2f(getPositionX() + x, getPositionY() + y + 0.01f);
	glVertex2f(getPositionX() + x + n * 0.01f, getPositionY() + y + 0.01f);
	glVertex2f(getPositionX() + x + n * 0.01f, getPositionY() + y);
	glEnd();
}

void Player::left_ATTACK()
{
	glBindTexture(GL_TEXTURE_2D, leftImage[_ATTACK].getTextureID());
}
void Player::left_DAMAGE()
{
	glBindTexture(GL_TEXTURE_2D, leftImage[_DAMAGE].getTextureID());
}
void Player::left_FALL1()
{
	glBindTexture(GL_TEXTURE_2D, leftImage[_FALL1].getTextureID());
}
void Player::left_FALL2()
{
	glBindTexture(GL_TEXTURE_2D, leftImage[_FALL2].getTextureID());
}
void Player::left_STAY1()
{
	glBindTexture(GL_TEXTURE_2D, leftImage[_STAY1].getTextureID());
}
void Player::left_STAY2()
{
	glBindTexture(GL_TEXTURE_2D, leftImage[_STAY2].getTextureID());
}
void Player::left_JUMP()
{
	glBindTexture(GL_TEXTURE_2D, leftImage[_JUMP].getTextureID());
}

void Player::right_ATTACK() 
{
	glBindTexture(GL_TEXTURE_2D, rightImage[_ATTACK].getTextureID());
}
void Player::right_DAMAGE()
{
	glBindTexture(GL_TEXTURE_2D, rightImage[_DAMAGE].getTextureID());
}
void Player::right_FALL1()
{
	glBindTexture(GL_TEXTURE_2D, rightImage[_FALL1].getTextureID());
}
void Player::right_FALL2()
{
	glBindTexture(GL_TEXTURE_2D, rightImage[_FALL2].getTextureID());
}
void Player::right_STAY1()
{
	glBindTexture(GL_TEXTURE_2D, rightImage[_STAY1].getTextureID());
}
void Player::right_STAY2()
{
	glBindTexture(GL_TEXTURE_2D, rightImage[_STAY2].getTextureID());
}
void Player::right_JUMP()
{
	glBindTexture(GL_TEXTURE_2D, rightImage[_JUMP].getTextureID());
}

void Player::updatePosition()
{
	//  change player's x, y coordinates
	//  when player is out of the window, change the position of player
	//  out of the left side
	if ((direction == KEY::LEFT) && (getPositionX() + 0.01f < -1.2f)) {
		setPositionX(1.05f);
	}
	//  out of the right side
	else if ((direction == KEY::RIGHT) && (getPositionX()  + 0.16f > 1.2f)) {
		setPositionX(-1.18f);
	}

	//  when player is dropped in the bottom hole
	if (getPositionY() < -1.2f) {
		setPositionY(1.0f) ;
	}
}

void Player::decreaseLife()
{
	player.life -= 1;
}

void Player::giveInvincibility(int frame)
{
<<<<<<< HEAD
	right_DAMAGE();
	player.blinkTime = 27;
=======
	player.blinkTime = frame;
>>>>>>> a21887bb3932a2e92e57ba28dc9986cfa3e9f5eb
}

bool Player::isInvincible()
{
	return blinkTime > 0;
}

Bubble Player::shoot()
{
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

void Player::initializePosition()
{
	move = true;
	if ((getPositionX() <= -0.95f) && (getPositionY() <= -0.95f)) {
		move = false;
		setPosition(-0.95f, -0.95f);
	}
	else if (getPositionX() <= -0.95f) {
		setPositionX(-0.95f);
		translate(0.0f, -(finalPosition[1] + 0.95f) / 150);
	}
	else if (getPositionY() <= -0.95f) {
		setPositionY(-0.95f);
		translate(-(finalPosition[0] + 0.95f) / 150, 0.0f);
	}
	else translate(-(finalPosition[0] + 0.95f) / 150, -(finalPosition[1] + 0.95f) / 150);
}

void Player::setDirection(KEY dr)
{
	direction = dr;
}

void Player::setState(STATE st)
{
	state = st;
}

void Player::setFinalPosition()
{
	finalPosition[0] = getPositionX();
	finalPosition[1] = getPositionY();
}

KEY Player::getDirection()
{
	return direction;
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
	float xRight = getPositionX() + 0.16f;
	float yBottom = getPositionY();
	float yTop = getPositionY() + 0.15f;

	return Hitbox(xLeft, xRight, yBottom, yTop);
};

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
