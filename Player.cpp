#include "main.h"

//  initial setting of player
Player::Player() : direction(KEY::RIGHT), state(STAY), height(0.18f), blinkTime(0), life(5) {
	position[0] = -0.9f; position[1] = -0.95f;
	hitbox[0][0] = position[0] + 0.03f;
	hitbox[0][1] = position[0] + 0.16f;
	hitbox[1][0] = position[1];
	hitbox[1][1] = position[1] + 0.15f;
	angle = 0.0f;
}

void Player::drawPlayer() {
	glPushMatrix();
	glTranslatef(position[0] + 0.07f, position[1] + 0.07f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(-position[0] - 0.07f, -position[1] - 0.07f, 0.0f);

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
	glPopMatrix();

	drawLife();
}
void Player::drawPixel(float x, float y, int n) {
	glBegin(GL_POLYGON);
	glVertex2f(position[0] + x, position[1] + y);
	glVertex2f(position[0] + x, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y);
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

void Player::setPosition(float x, float y) {
	//  change player's x, y coordinates
	position[0] += x;
	position[1] += y;

	//  when player is out of the window, change the position of player
	//  out of the left side
	if ((direction == KEY::LEFT) && (position[0] + 0.01f < -1.2f)) {
		player.position[0] = 1.05f;
	}
	//  out of the right side
	else if ((direction == KEY::RIGHT) && (position[0] + 0.16f > 1.2f)) {
		player.position[0] = -1.18f;
	}

	//  when player is dropped in the bottom hole
	if (player.position[1] < -1.2f) {
		player.position[1] = 1.0f;
	}

	//  change player's hitbox coordinate
	if (direction == RIGHT) {
		hitbox[0][0] = position[0] + 0.03f;
		hitbox[0][1] = position[0] + 0.16f;
	}
	else {
		hitbox[0][0] = position[0] + 0.01f;
		hitbox[0][1] = position[0] + 0.14f;
	}
	hitbox[1][0] = position[1];
	hitbox[1][1] = position[1] + 0.15f;

}

Bubble Player::shoot()
{
	Bubble bubble;
	bubble.initialize();
	float x = player.position[0];
	float y = player.position[1];

	bubble.setSize(0.1f);
	if (direction == KEY::LEFT) {
		bubble.setPos(x, y + 0.1);
		bubble.setDirection(DIRECT::D_LEFT);
	}
	else {
		bubble.setPos(x + 0.1, y + 0.1);
		bubble.setDirection(DIRECT::D_RIGHT);
	}
	bubble.createdTime = clock();
	bubble.draw();
	return bubble;
}

void Player::checkHit(float box[2][2]) {
	//  float box[2][2] means a Monster's hit box
	//  only check when blinkTime is 0 
	if (blinkTime == 0) {
		//  check whether player's hit box contacts Monster's hit box
		if ((box[0][0] <= player.hitbox[0][0] && player.hitbox[0][0] <= box[0][1]) ||
			(box[0][0] <= player.hitbox[0][1] && player.hitbox[0][1] <= box[0][1])) {
			if ((box[1][0] <= player.hitbox[1][0] && player.hitbox[1][0] <= box[1][1]) ||
				(box[1][0] <= player.hitbox[1][1] && player.hitbox[1][1] <= box[1][1])) {
				//  if player's hit box contacts Monster's hit box, decrease the number of life and generate blinkTime
				life--;
				blinkTime = 27;
			}
		}
	}
}

bool Player::checkHitBubble(vector<vector<float>> box) {
	if ((box[0][0] <= player.hitbox[0][0] && player.hitbox[0][0] <= box[0][1]) ||
		(box[0][0] <= player.hitbox[0][1] && player.hitbox[0][1] <= box[0][1])) {
		if ((box[1][0] <= player.hitbox[1][0] && player.hitbox[1][0] <= box[1][1]) ||
			(box[1][0] <= player.hitbox[1][1] && player.hitbox[1][1] <= box[1][1])) {
			return true;
		}
	}
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
