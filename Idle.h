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
	void idleClear();

private:
	clock_t endTime;
};
