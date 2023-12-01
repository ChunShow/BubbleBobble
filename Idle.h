#pragma once
#include <ctime>

class Idle
{
public:
	Idle();

	void operate();
	void idleBoard();
	void idleItem();
	void idlePlayer();
	void idleBubbleAlive();
	void idleMonster();
	void idleBubble();
	void idleExplosion();
	void idleStageClear();
	void idleGameover();
	void idleGamestart();
	void idleGameWin();

private:
	clock_t endTime;
};
