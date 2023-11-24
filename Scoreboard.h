#pragma once
#include "Object.h"
#include <string>
#include <ctime>

class Scoreboard : public Object
{
public:
	Scoreboard();
	int getScore();
	void addScore(int score);
	void setLastClearTime();

	void draw(bool isMapMoving);
	int getLeftTime(clock_t lastClearTime);
	void changeLeftTimeToScore(clock_t lastClearTime);
	void addScoreByTime();

	void reset();

private:
	int score;
	int scoreByTime;
};

