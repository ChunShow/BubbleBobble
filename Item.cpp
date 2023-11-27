#include "Item.h"

Item::Item(ITEM_TYPE item_type, float x, float y)
{
	type = item_type;
	achived = false;
	achivedTime = -LONG_MAX;
	creationTime = clock();
	setPosition(x, y);
	itemExistenceDuration = 10000;

	for (int i = 0; i < 13; i++) {
		textures.push_back(Texture(_MAP, (TEXTURE_BLOCK)i));
		textures[i].initTexture();
	}

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

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	switch (type) {
	case SPEED:
		glBindTexture(GL_TEXTURE_2D, textures[_SPEED].getTextureID());
		break;
	case HEART:
		glBindTexture(GL_TEXTURE_2D, textures[_HEART].getTextureID());
		break;
	case SCORE:
		glBindTexture(GL_TEXTURE_2D, textures[_APPLE].getTextureID());
		break;
	case DOUBLE:
		glBindTexture(GL_TEXTURE_2D, textures[_DOUBLE].getTextureID());
		break;
	case RAPID:
		glBindTexture(GL_TEXTURE_2D, textures[_BUBBLE].getTextureID());
		break;
	}

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(position[0] - size, position[1] - size);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(position[0] + size, position[1] - size);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(position[0] + size, position[1] + size);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(position[0] - size, position[1] + size);
	glEnd();
	glDisable(GL_TEXTURE_2D);	
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

