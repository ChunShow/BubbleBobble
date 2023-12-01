#pragma once
#include "Object.h"
#include <string>
#include <fstream>
#include <ctime>
#include <io.h>
#include <map>

class Scoreboard : public Object
{
public:
	Scoreboard();
	int getScore();
	void addScore(int score);
	void setLastClearTime();

	void draw(bool isMapMoving);
	void displayLeaderboard();

	int getLeftTime(clock_t lastClearTime);
	void changeLeftTimeToScore(clock_t lastClearTime);
	void addScoreByTime();

	void reset();

	void loadLeaderboard();
	void writeLeaderboard();
	void addMyrecord(string name);

private:
	int score;
	int scoreByTime;
	map<int, string> leaderboard;
};

