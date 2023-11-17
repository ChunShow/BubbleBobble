#include "main.h"

//  constructor
Monster::Monster(MONSTER Type) : type(Type), direction(DOWN), trapped(false), rotation(false), alive(true), rotateAngle(0.0f), trappedBubble(-1) {
	setPosition(0.0f, 0.0f);
	initTextureImage();
}

//  draw mothods
void Monster::drawMonster() 
{
	setTextureID(direction);

	glPushMatrix();
	drawRotate();
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(getPositionX() + 0.0f, getPositionY() + 0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(getPositionX() + 0.2f, getPositionY() + 0.2f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(getPositionX() + 0.2f, getPositionY() + 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(getPositionX() + 0.0f, getPositionY() + 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Monster::drawRotate()
{
	if (isTrapped ()) {
		rotateAngle += 5.0f;
		glTranslatef(getPositionX() + 0.085f, getPositionY() + 0.085f, 1.0f);
		glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
		glScalef(0.65f, 0.65f, 0.65f);
		glTranslatef(-getPositionX() - 0.085f, -getPositionY() - 0.085f, 0.0f);
	}
}

//  texture methods
void Monster::initTextureImage()
{
	switch (type) {
	case(ROBOT):
		leftImage = Texture(_MONSTER, _ROBOT, _LEFT);
		rightImage = Texture(_MONSTER, _ROBOT, _RIGHT);
		break;
	case(CREATURE):
		leftImage = Texture(_MONSTER, _CREATURE, _LEFT);
		rightImage = Texture(_MONSTER, _CREATURE, _RIGHT);
		break;
	case(GHOST):
		leftImage = Texture(_MONSTER, _GHOST, _LEFT);
		rightImage = Texture(_MONSTER, _GHOST, _RIGHT);
		break;
	}

	leftImage.initTexture();
	rightImage.initTexture();
}
void Monster::setTextureID(KEY dir)
{
	if (dir == LEFT) {
		textureID = leftImage.getTextureID();
	}
	else textureID = rightImage.getTextureID();
}

//  reflect monster's collision with a bubble
void Monster::trap(int key) 
{
	trapped = true;
	trappedBubble = key;
}
bool Monster::isTrapped() 
{
	return trapped;
}
bool Monster::isAlive()
{
	return alive;
}
void Monster::kill()
{
	alive = false;
}
void Monster::free()
{
	trapped = false;
	rotateAngle = 0.0f;
	direction = DOWN;
	trappedBubble = -1;
}


void Monster::setDirection(KEY drt)
{
	direction = drt;
}
KEY Monster::getDirection()
{
	return direction;
}
MONSTER Monster::getType()
{
	return type;
}
int Monster::getTrappedBubble()
{
	if (!isTrapped()) {
		cout << "This method should not be called" << endl;
		return -1;
	}
	return trappedBubble;
}
Hitbox Monster::getHitbox() 
{
	float xLeft, xRight, yBottom, yTop;
	switch (type) {
	case(ROBOT):
		xLeft = getPositionX() + 0.03f;
		xRight = getPositionX() + 0.14f;
		yBottom = getPositionY();
		yTop = getPositionY() + 0.14f;
		break;
	case(CREATURE):
		xLeft = getPositionX() + 0.03f;
		xRight = getPositionX() + 0.16f;
		yBottom = getPositionY();
		yTop = getPositionY() + 0.14f;
		break;
	case(GHOST):
		xLeft = getPositionX() + 0.04f;
		xRight = getPositionX() + 0.16f;
		yBottom = getPositionY();
		yTop = getPositionY() + 0.16f;
		break;
	}

	return Hitbox(xLeft, xRight, yBottom, yTop);
}