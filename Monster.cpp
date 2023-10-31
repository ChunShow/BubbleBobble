#include "main.h"

//  initial setting of monster
Monster::Monster(MONSTER Type) : type(Type), direction(LEFT) {
	position[0] = 0.0f;
	position[1] = 0.0f;
	switch (type)
	case CREATURE: {
		hitbox[0][0] = position[0] + 0.01f;
		hitbox[0][1] = position[0] + 0.14f;
		hitbox[1][0] = position[1];
		hitbox[1][1] = position[1] + 0.13f;
		break;
	}
	caught = false;
}

void Monster::drawMonster() {
	//  draw monster according to the type
	switch (type)
	case CREATURE: {
		//  draw creature facing left
		if (direction == LEFT) leftCreature();
		//  draw creature facing right
		else rightCreature();
	}
}
void Monster::drawPixel(float x, float y, int n) {
	glBegin(GL_POLYGON);
	glVertex2f(position[0] + x, position[1] + y);
	glVertex2f(position[0] + x, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y + 0.01f);
	glVertex2f(position[0] + x + n * 0.01f, position[1] + y);
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

void Monster::setPosition(float x, float y) {
	//  change monster's x, y coordinates
	position[0] += x;
	position[1] += y;

	//  change monster's hitbox coordinate
	switch (type)
	case CREATURE: {
		hitbox[0][0] = position[0] + 0.01f;
		hitbox[0][1] = position[0] + 0.14f;
		hitbox[1][0] = position[1];
		hitbox[1][1] = position[1] + 0.13f;
		break;
	}
}