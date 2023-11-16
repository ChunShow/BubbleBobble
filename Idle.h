#pragma once
#include <ctime>

class Idle
{
public:
	Idle();

	void operate();
	void idlePlayer();
	void idleBubbleAlive();
	void idleMonster();
	void idleBubble();
	void idleStageClear();
	void idleGameover();

private:
	clock_t endTime;
};
