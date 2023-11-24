#pragma once
#include "Object.h"
#include <ctime>

enum ITEM_TYPE {SPEED, HEART, SCORE, DOUBLE, RAPID};

class Item : public Object
{
public:
	Item(ITEM_TYPE item_type, float x, float y);
	void draw();

	ITEM_TYPE getType();
	bool visible();
	bool isDisappeared();
	bool isEffective();
	bool isEffectFinished();
	void makeAchived();
	bool isDisposable();
	void release();


	virtual Hitbox getHitbox() override;
	float getSize();

private:
	ITEM_TYPE type;
	bool achived;
	clock_t itemEffectDuration;
	clock_t itemExistenceDuration;
	clock_t creationTime;
	clock_t achivedTime;

	bool disposable;

	float size = 0.05f;
};

