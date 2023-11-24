#include "Item.h"

Item::Item(ITEM_TYPE item_type, float x, float y)
{
	type = item_type;
	achived = false;
	achivedTime = -LONG_MAX;
	creationTime = clock();
	setPosition(x, y);
	itemExistenceDuration = 10000;

	switch (type) {
	case SPEED:
		itemEffectDuration = 10000;
		disposable = false;
		break;
	case HEART:
		itemEffectDuration = LONG_MAX;
		disposable = true;
		break;
	case SCORE:
		itemEffectDuration = LONG_MAX;
		disposable = true;
		break;
	case DOUBLE:
		itemEffectDuration = 10000;
		disposable = false;
		break;
	case RAPID:
		itemEffectDuration = 10000;
		disposable = false;
		break;
	}
}

void Item::draw()
{
	switch (type) {
	case SPEED:
		glColor3f(0.0f, 1.0f, 1.0f);
		break;
	case HEART:
		glColor3f(1.0f, 0.0f, 1.0f);
		break;
	case SCORE:
		glColor3f(0.0f, 0.0f, 0.0f);
		break;
	case DOUBLE:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case RAPID:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	}
	
	glBegin(GL_QUADS);
	glVertex2f(position[0] - size, position[1] - size);
	glVertex2f(position[0] + size, position[1] - size);
	glVertex2f(position[0] + size, position[1] + size);
	glVertex2f(position[0] - size, position[1] + size);
	glEnd();
}

ITEM_TYPE Item::getType()
{
	return type;
}

bool Item::visible()
{
	return (clock() - creationTime < itemExistenceDuration) && !achived;
}

bool Item::isDisappeared()
{
	return !achived && (clock() - creationTime > itemExistenceDuration);
}

bool Item::isEffective()
{
	return achived && (clock() - achivedTime < itemEffectDuration);
}

bool Item::isEffectFinished()
{
	return achived && (clock() - achivedTime > itemEffectDuration);
}

void Item::makeAchived()
{
	achived = true;
	achivedTime = clock();
}

bool Item::isDisposable()
{
	return disposable;
}

void Item::release()
{
	achived = false;
	itemEffectDuration = 0.0f;
	itemExistenceDuration = 0.0f;
}

Hitbox Item::getHitbox()
{
	return Hitbox(position[0] - size, position[0] + size, position[1] - size, position[1] + size);
}

float Item::getSize()
{
	return size;
}

