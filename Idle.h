#pragma once
#include <ctime>

class Idle
{
public:
	Idle();

	void operate();
	void idleItemSpawn();
	void idleItem();
	void idlePlayer();
	void idleBubbleAlive();
	void idleMonster();
	void idleBubble();
	void idleExplosion();
	void idleStageClear();
	void idleGameover();

private:
	clock_t endTime;
};
