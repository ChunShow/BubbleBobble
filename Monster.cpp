#include "main.h"

//  initial setting of monster
Monster::Monster(MONSTER Type) : type(Type), direction(LEFT) {
	setPosition(0.0f, 0.0f);
	caught = false;
	rotation = false;
	angle = 0.0f;
}

void Monster::drawMonster() {
	glPushMatrix();
	drawRotate();
	//  draw monster according to the type
	switch (type) {
	case CREATURE:
		//  draw creature facing left
		if (direction == LEFT) leftCreature();
		//  draw creature facing right
		else rightCreature();
		break;
	}
	glPopMatrix();
}
void Monster::drawPixel(float x, float y, int n) {
	float x_pos = getPosition()[0];
	float y_pos = getPosition()[1];
	glBegin(GL_POLYGON);
	glVertex2f(x_pos + x, y_pos + y);
	glVertex2f(x_pos + x, y_pos + y + 0.01f);
	glVertex2f(x_pos + x + n * 0.01f, y_pos + y + 0.01f);
	glVertex2f(x_pos + x + n * 0.01f, y_pos + y);
	glEnd();
}

void Monster::leftCreature() {
	//  black
	glColor3f(0.0f, 0.0f, 0.0f);
	float y = 0.0f;
	drawPixel(0.02f, y, 4);
	drawPixel(0.08f, y, 4);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.06f, y, 2);
	drawPixel(0.12f, y, 5);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.09f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.03f, y, 1);
	drawPixel(0.05f, y, 7);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 8);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 7);
	drawPixel(0.09f, y, 1);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.02f, y, 5);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.03f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.11f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);
	drawPixel(0.09f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 4);

	//  white
	glColor3f(1.0f, 1.0f, 1.0f);
	y = 0.01f;
	drawPixel(0.02f, y, 4);
	drawPixel(0.08f, y, 4);

	y += 0.01f;
	drawPixel(0.03f, y, 14);

	y += 0.01f;
	drawPixel(0.03f, y, 3);
	drawPixel(0.07f, y, 2);
	drawPixel(0.10f, y, 7);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.12f, y, 4);

	y += 0.01f;
	drawPixel(0.10f, y, 2);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 2);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.07f, y, 8);

	y += 0.01f;
	drawPixel(0.01f, y, 2);
	drawPixel(0.04f, y, 2);
	drawPixel(0.07f, y, 2);
	drawPixel(0.12f, y, 3);

	y += 0.01f;
	drawPixel(0.01f, y, 7);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 6);
	drawPixel(0.09f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 6);
	drawPixel(0.09f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 5);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 6);
	drawPixel(0.11f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 8);

	y += 0.01f;
	drawPixel(0.05f, y, 4);

	//  red
	glColor3f(1.0f, 0.0f, 0.0f);
	y = 0.08f;
	drawPixel(0.09f, y, 3);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 3);

	y += 0.01f;
	drawPixel(0.07f, y, 1);
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.07f, y, 1);
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.07f, y, 2);
	drawPixel(0.10f, y, 2);

	y += 0.01f;
	drawPixel(0.08f, y, 3);

	//  orange
	glColor3f(1.0f, 0.5f, 0.3f);
	y = 0.09f;
	drawPixel(0.09f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 1);
}
void Monster::rightCreature() {
	//  black
	glColor3f(0.0f, 0.0f, 0.0f);
	float y = 0.0f;
	drawPixel(0.02f, y, 4);
	drawPixel(0.08f, y, 4);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.06f, y, 2);
	drawPixel(0.12f, y, 5);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.09f, y, 1);
	drawPixel(0.17f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.03f, y, 1);
	drawPixel(0.05f, y, 7);
	drawPixel(0.16f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 8);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 7);
	drawPixel(0.09f, y, 1);
	drawPixel(0.12f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.02f, y, 5);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.03f, y, 1);
	drawPixel(0.06f, y, 1);
	drawPixel(0.15f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.00f, y, 1);
	drawPixel(0.14f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.11f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 2);
	drawPixel(0.09f, y, 2);

	y += 0.01f;
	drawPixel(0.05f, y, 4);

	//  white
	glColor3f(1.0f, 1.0f, 1.0f);
	y = 0.01f;
	drawPixel(0.02f, y, 4);
	drawPixel(0.08f, y, 4);

	y += 0.01f;
	drawPixel(0.03f, y, 14);

	y += 0.01f;
	drawPixel(0.03f, y, 3);
	drawPixel(0.07f, y, 2);
	drawPixel(0.10f, y, 7);

	y += 0.01f;
	drawPixel(0.02f, y, 1);
	drawPixel(0.04f, y, 1);
	drawPixel(0.12f, y, 4);

	y += 0.01f;
	drawPixel(0.10f, y, 2);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 2);
	drawPixel(0.13f, y, 2);

	y += 0.01f;
	drawPixel(0.01f, y, 1);
	drawPixel(0.07f, y, 8);

	y += 0.01f;
	drawPixel(0.01f, y, 2);
	drawPixel(0.04f, y, 2);
	drawPixel(0.07f, y, 2);
	drawPixel(0.12f, y, 3);

	y += 0.01f;
	drawPixel(0.01f, y, 7);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 6);
	drawPixel(0.09f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.01f, y, 6);
	drawPixel(0.09f, y, 1);
	drawPixel(0.13f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 5);
	drawPixel(0.12f, y, 1);

	y += 0.01f;
	drawPixel(0.02f, y, 6);
	drawPixel(0.11f, y, 1);

	y += 0.01f;
	drawPixel(0.03f, y, 8);

	y += 0.01f;
	drawPixel(0.05f, y, 4);

	//  red
	glColor3f(1.0f, 0.0f, 0.0f);
	y = 0.08f;
	drawPixel(0.09f, y, 3);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 3);

	y += 0.01f;
	drawPixel(0.07f, y, 1);
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.07f, y, 1);
	drawPixel(0.11f, y, 2);

	y += 0.01f;
	drawPixel(0.07f, y, 2);
	drawPixel(0.10f, y, 2);

	y += 0.01f;
	drawPixel(0.08f, y, 3);

	//  orange
	glColor3f(1.0f, 0.5f, 0.3f);
	y = 0.09f;
	drawPixel(0.09f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 1);

	y += 0.01f;
	drawPixel(0.08f, y, 1);
	drawPixel(0.10f, y, 1);

	y += 0.01f;
	drawPixel(0.09f, y, 1);
}
void Monster::caughtBubble(float bubblePos[2]) {
	if (getCaught()) {
		setPosition(bubblePos[0] - 0.1f, bubblePos[1] - 0.1f);
	}
}
void Monster::setCaught() {
	caught = true;
	setRotate();
}
bool Monster::getCaught() {
	return caught;
}
void Monster::setRotate() {
	rotation = !rotation;
	if (time == 0.0f) time = 50.0f;
}
bool Monster::getRotate() {
	return rotation;
}
void Monster::drawRotate() {
	if (getRotate()) {
		time -= 1.0f;
		angle += 5.0f;
		glTranslatef(getPosition()[0] + 0.07f, getPosition()[1] + 0.07f, 0.0f);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		glTranslatef(-getPosition()[0] - 0.07f, -getPosition()[1] - 0.07f, 0.0f);
	}
}

float Monster::getTime() {
	return time;
}

float* Monster::getHitbox() {
	float xLeft, xRight, yBottom, yTop;
	float hitbox[4];
	switch (type) {
	case(CREATURE):
		xLeft = getPositionX() + 0.01f;
		xRight = getPositionX() + 0.14f;
		yBottom = getPositionY();
		yTop = getPositionY() + 0.13f;
		break;
	default:
		xLeft = getPositionX();
		xRight = getPositionX() + 0.15f;
		yBottom = getPositionY();
		yTop = getPositionY() + 0.15f;
		break;
	}
	hitbox[0] = xLeft; hitbox[1] = xRight; hitbox[2] = yBottom; hitbox[3] = yTop;
	return hitbox;
}