#include "main.h"

//  initial setting of player
Player::Player() : direction(KEY::RIGHT), state(STAY), height(0.18f), blinkTime(0), life(5) {
	setPosition(-0.90f, -0.95f);
}

void Player::drawPlayer() {
	if (blinkTime % 4 == 0 || blinkTime % 4 == 1) {
		//  draw dragon facing left
		if (direction == LEFT) {
			if (state == JUMP) leftDragonJUMP();
			else if (state == FALL) leftDragonFALL();
			leftDragon();
		}
		//  draw dragon facing right
		else {
			if (state == JUMP) rightDragonJUMP();
			else if (state == FALL) rightDragonFALL();
			rightDragon();
		}
		if (blinkTime != 0) blinkTime--;
	}
	else blinkTime--;

	drawLife();
}

void Player::drawPixel(float x, float y, int n) {
	glBegin(GL_POLYGON);
	glVertex2f(getPositionX() + x, getPositionY() + y);
	glVertex2f(getPositionX() + x, getPositionY() + y + 0.01f);
	glVertex2f(getPositionX() + x + n * 0.01f, getPositionY() + y + 0.01f);
	glVertex2f(getPositionX() + x + n * 0.01f, getPositionY() + y);
	glEnd();
}
void Player::leftDragon() {
	// black
	glColor3f(0.0f, 0.0f, 0.0f);
	float y = 0.0f;
	drawPixel(0.01f, y, 15);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 2);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 2);
	drawPixel(0.14f, y, 2);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.14f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 3);
	drawPixel(0.06f, y, 3);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.12f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.05f, y, 2);
	drawPixel(0.10f, y, 4);

	y += 0.01f;
	drawPixel(0.07f, y, 1);
	drawPixel(0.09f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 1);

	// green pixel
	glColor3f(0.4f, 1.0f, 0.15f);
	y = 0.0f;;
	y += 0.01f;
	drawPixel(0.11f, y, 4);

	y += 0.01f;
	drawPixel(0.10f, y, 6);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 2);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 7);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 2);
	drawPixel(0.05f, y, 1);
	drawPixel(0.08f, y, 5);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 4);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 4);

	y += 0.01f;
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 4);

	y += 0.01f;
	drawPixel(0.05f, y, 1);
	drawPixel(0.09f, y, 3);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.08f, y, 4);

	y += 0.01f;
	drawPixel(0.04f, y, 7);

	y += 0.01f;
	drawPixel(0.05f, y, 5);

	// white pixel
	glColor3f(1.0f, 1.0f, 1.0f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.04f, y, 3);

	y += 0.01f;
	drawPixel(0.03f, y, 5);

	y += 0.01f;
	drawPixel(0.03f, y, 6);

	y += 0.01f;
	drawPixel(0.04f, y, 4);

	y += 0.02f;
	drawPixel(0.05f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 2);

	// orange pixel
	glColor3f(1.0f, 0.4f, 0.2f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.01f, y, 3);
	drawPixel(0.07f, y, 4);

	y += 0.01f;
	drawPixel(0.08f, y, 2);

	y += 0.01f;
	drawPixel(0.11f, y, 2);
	drawPixel(0.14f, y, 2);

	y += 0.01f;
	drawPixel(0.10f, y, 3);

	y += 0.01f;
	drawPixel(0.10f, y, 3);

	y += 0.01f;
	drawPixel(0.11f, y, 1);

	y += 0.01f;
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.13f, y, 2);

	y += 0.02f;
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.12f, y, 3);

	y += 0.02f;
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.10f, y, 4);

	y += 0.01f;
	drawPixel(0.07f, y, 3);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
}
void Player::rightDragon() {
	// black pixel
	glColor3f(0.0f, 0.0f, 0.0f);
	float y = 0.0f;
	drawPixel(0.02f, y, 15);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.15f, y, 2);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.02f, y, 2);
	drawPixel(0.14f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.03f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);
	drawPixel(0.09f, y, 3);
	drawPixel(0.13f, y, 3);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.05f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 4);
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.1f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 1);

	// green pixel
	glColor3f(0.4f, 1.0f, 0.15f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.03f, y, 4);

	y += 0.01f;
	drawPixel(0.02f, y, 6);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.08f, y, 2);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.08f, y, 7);

	y += 0.01f;
	drawPixel(0.05f, y, 1);
	drawPixel(0.07f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 5);
	drawPixel(0.12f, y, 1);
	drawPixel(0.14f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 4);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.05f, y, 4);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.05f, y, 4);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.06f, y, 3);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.06f, y, 4);
	drawPixel(0.12f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.07f, y, 7);

	y += 0.01f;
	drawPixel(0.08f, y, 5);

	// white pixel
	glColor3f(1.0f, 1.0f, 1.0f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.11f, y, 3);

	y += 0.01f;
	drawPixel(0.1f, y, 5);

	y += 0.01f;
	drawPixel(0.09f, y, 6);

	y += 0.01f;
	drawPixel(0.1f, y, 4);

	y += 0.02f;
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.1f, y, 2);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 2);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.1f, y, 2);
	drawPixel(0.13f, y, 1);

	// orange pixel
	glColor3f(1.0f, 0.4f, 0.2f);
	y = 0.0f;
	y += 0.01f;
	drawPixel(0.07f, y, 4);
	drawPixel(0.14f, y, 3);

	y += 0.01f;
	drawPixel(0.08f, y, 2);

	y += 0.01f;
	drawPixel(0.02f, y, 2);
	drawPixel(0.05f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 3);

	y += 0.01f;
	drawPixel(0.05f, y, 3);

	y += 0.01f;
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);

	y += 0.02f;
	drawPixel(0.04f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 3);

	y += 0.02f;
	drawPixel(0.05f, y, 2);

	y += 0.01f;
	drawPixel(0.04f, y, 4);

	y += 0.01f;
	drawPixel(0.08f, y, 3);

	y += 0.01f;
	drawPixel(0.09f, y, 1);
}
void Player::leftDragonJUMP() {
	float y = 0.073f;
	glColor3f(1.0f, 1.0f, 1.0f);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	glColor3f(0.0f, 0.0f, 0.0f);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
}
void Player::rightDragonJUMP() {
	float y =  0.073f;
	glColor3f(1.0f, 1.0f, 1.0f);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	glColor3f(0.0f, 0.0f, 0.0f);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
}
void Player::leftDragonFALL() {
	float y = 0.074f;
	glColor3f(0.0f, 0.0f, 0.0f);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	glColor3f(1.0f, 1.0f, 1.0f);
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);

	y += 0.01f;
	drawPixel(0.04f, y, 1);
	drawPixel(0.06f, y, 1);
}
void Player::rightDragonFALL() {
	float y = 0.074f;
	glColor3f(0.0f, 0.0f, 0.0f);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	glColor3f(1.0f, 1.0f, 1.0f);
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.11f, y, 1);
	drawPixel(0.13f, y, 1);
}

void Player::updatePosition() {
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

void Player::giveInvincibility()
{
	player.blinkTime = 27;
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

void Player::drawHeartPixel(float x, float y, int n, int i) {
	glBegin(GL_POLYGON);
	glVertex2f(-0.99f + i * 0.08f + x, -0.995f + y);
	glVertex2f(-0.99f + i * 0.08f + x, -0.995f + y + 0.01f);
	glVertex2f(-0.99f + i * 0.08f + x + n * 0.01f, -0.995f + y + 0.01f);
	glVertex2f(-0.99f + i * 0.08f + x + n * 0.01f, -0.995f + y);;
	glEnd();
}

void Player::drawLife() {
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < life; i++) {
		drawHeartPixel(0.02f, 0.00f, 1, i);
		drawHeartPixel(0.01f, 0.01f, 3, i);
		drawHeartPixel(0.00f, 0.02f, 5, i);
		drawHeartPixel(0.01f, 0.03f, 1, i);
		drawHeartPixel(0.03f, 0.03f, 1, i);
	}
}

float* Player::getHitbox() {
	float xLeft = getPositionX() + 0.03f;
	float xRight = getPositionX() + 0.16f;
	float yBottom = getPositionY();
	float yTop = getPositionY() + 0.15f;

	float hitbox[4]  = {xLeft, xRight, yBottom, yTop};
	return hitbox;
}
